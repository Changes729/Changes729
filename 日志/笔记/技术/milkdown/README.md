> 参考资料：
>
> 

# Milkdown

在 `editor-state.ts` 中，所有内容被最终加载后，`milkdown`会有一个通过 `optionsOverride` 的方式，重新更新内容。

```ts

  return async () => {
    await ctx.waitTimers(editorStateTimerCtx)

    const schema = ctx.get(schemaCtx)
    const parser = ctx.get(parserCtx)
    const rules = ctx.get(inputRulesCtx)
    const optionsOverride = ctx.get(editorStateOptionsCtx)
    const prosePlugins = ctx.get(prosePluginsCtx)
    const defaultValue = ctx.get(defaultValueCtx)
    const doc = getDoc(defaultValue, parser, schema)
    const km = ctx.get(keymapCtx)
    const disposeBaseKeymap = km.addBaseKeymap()

    const plugins = [
      ...prosePlugins,
      new Plugin({
        key,
        state: {
          init: () => {
            // do nothing
          },
          apply: (_tr, _value, _oldState, newState) => {
            ctx.set(editorStateCtx, newState)
          },
        },
      }),
      createInputRules({ rules }),
      createKeymap(km.build()),
    ]

    ctx.set(prosePluginsCtx, plugins)

    const options = optionsOverride({
      schema,
      doc,
      plugins,
    })

    const state = EditorState.create(options)
    ctx.set(editorStateCtx, state)
    ctx.done(EditorStateReady)

    return () => {
      disposeBaseKeymap()
      ctx
        .remove(defaultValueCtx)
        .remove(editorStateCtx)
        .remove(editorStateOptionsCtx)
        .remove(editorStateTimerCtx)
        .clearTimer(EditorStateReady)
    }
  }
```



## 重要文件

- [milkdown](https://github.com/Milkdown/milkdown/tree/f56ff7ab21cdb85016185c688de38c7ce61c3dea)/[packages](https://github.com/Milkdown/milkdown/tree/f56ff7ab21cdb85016185c688de38c7ce61c3dea/packages)/[core](https://github.com/Milkdown/milkdown/tree/f56ff7ab21cdb85016185c688de38c7ce61c3dea/packages/core)/[src](https://github.com/Milkdown/milkdown/tree/f56ff7ab21cdb85016185c688de38c7ce61c3dea/packages/core/src)/[internal-plugin](https://github.com/Milkdown/milkdown/tree/f56ff7ab21cdb85016185c688de38c7ce61c3dea/packages/core/src/internal-plugin)/editor-state.ts：editorState有很多细节信息。
