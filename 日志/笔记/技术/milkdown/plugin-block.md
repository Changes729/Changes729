> 参考资料：
>
> - https://milkdown.dev/docs/api/plugin-block：Block 基础
> - https://milkdown.dev/docs/plugin/example-block-plugin：Block 案例（会崩溃）

# Plugin block

## 入口内容

从 编辑器 配置中看一下。`block` 是一个典型的 插件列表：

```ts
      .use(block)
      .config((ctx: Ctx) => {
        ctx.set(block.key, {
          view: createBlockPluginView(ctx),
        });
      })
```

```ts
// @milkdown/plugin-block
export const block = [
  blockSpec,
  blockConfig,
  blockService,
  blockServiceInstance,
  blockPlugin,
] as BlockPlugin
```

其中，`blockSpec` 是 插件基本内容，是一个 `PluginSpec`，而且只设置了 `view` 字段。要注意的是，prosemirror 中的 view 字段，更像是一个注册函数，提供 `EditorView` 的同时，也需要回传，告知如何 `update` 和 `destroy`。



`blockConfig` 配置了一个过滤器 ：

```ts
export const defaultNodeFilter: FilterNodes = (pos) => {
  const table = findParent((node) => node.type.name === 'table')(pos)
  if (table) return false

  return true
}
```

`blockService` 定义了服务生成器，而 `blockServiceInstance` 定义了具体的服务实例。

`blockPlugin` 构成了具体的 `MilkdownPlugin`，在其中注册信号并负责转发给服务。



服务实例最重要的是信号注册，也就是 notify 机制：

```ts
  #notify?: BlockServiceMessage

  /// @internal
  #hide = () => {
    this.#notify?.({ type: 'hide' })
    this.#active = null
  }

  /// @internal
  #show = (active: ActiveNode) => {
    this.#active = active
    this.#notify?.({ type: 'show', active })
  }
```

比如在鼠标移动的时候就有相应：

```ts

  #mousemoveCallback = throttle((view: EditorView, event: MouseEvent) => {
    if (!view.editable) return

    const rect = view.dom.getBoundingClientRect()
    const x = rect.left + rect.width / 2
    const dom = view.root.elementFromPoint(x, event.clientY)
    if (!(dom instanceof Element)) {
      this.#hide()
      return
    }

    const filterNodes = this.#filterNodes
    if (!filterNodes) return

    const result = selectRootNodeByDom(
      view,
      { x, y: event.clientY },
      filterNodes
    )

    if (!result) {
      this.#hide()
      return
    }
    this.#show(result)
  }, 200)
```

这个 `notify` 会由 `BlockProvider` 在初始化的时候注册，并绑定，随后构成相应。

```ts
  #init() {
    const view = this.#ctx.get(editorViewCtx)
    const root = this.#root ?? view.dom.parentElement ?? document.body
    root.appendChild(this.#element)

    const service = this.#ctx.get(blockServiceInstance.key)
    service.bind(this.#ctx, (message) => {
      if (message.type === 'hide') {
        this.hide()
        this.#activeNode = null
      } else if (message.type === 'show') {
        this.show(message.active)
        this.#activeNode = message.active
      }
    })

    this.#service = service
    this.#service.addEvent(this.#element)
    this.#element.draggable = true
  }
```



