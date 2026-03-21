> 参考资料：
>
> - [ProseMirror Guide](https://prosemirror.net/docs/guide/)
> - [Noteworthy](https://noteworthy.ink/)：一个支持 Latex 的编辑器，但是很难看。基于 [KaTeX](https://katex.org/docs/supported.html) and [`prosemirror-math`](https://github.com/benrbray/prosemirror-math)

# ProseMirror

基本模块包括：

- [`prosemirror-model`](https://prosemirror.net/docs/ref/#model)：定义文档类型，描述编辑器内容的数据结构
- [`prosemirror-state`](https://prosemirror.net/docs/ref/#state)：提供了描述编辑器的整个状态的数据结构
- [`prosemirror-view`](https://prosemirror.net/docs/ref/#view)：实现了一个用户界面组件
- [`prosemirror-transform`](https://prosemirror.net/docs/ref/#transform)：包含以可记录和重放的方式修改文档的功能，这是`state`模块中事务的基础，并且使撤消历史和协作编辑成为可能。



以 `prosemirror-markdown` 为例子。在 `schema` 中定义了抽象 DOM 类型，其中，`content` 定义了归属关系，是一种抽象描述。而 `parseDOM` 是从 DOM 转 抽象内容，而 `toDOM` 则是从抽象内容转 DOM。



在 `prosemirror-markdown` 中定义了一个 `ParseSpec`，因为 工程中是使用 `markdown-it` 作为解析器，同时 `markdown-it` 也会解析成一个数据类型。因此，`ParseSpec` 作为连接层， 可以将 `markdown-it` 的输出格式很好的和 `scheme` 的格式做对应，最终就可以实现双向转化。



## Scheme-Node-NodeType

在声明中我们可以看到一个精简版本的 `scheme`：

```tsx
declare const schema: Schema<"blockquote" | "image" | "text" | "doc" | "paragraph" | "horizontal_rule" | "heading" | "code_block" | "hard_break", "link" | "code" | "em" | "strong">;
```

而在源代码会更多内容，特别包含了 `toDOM` 和 `parseDOM`。 暂时不谈这些，源代码中，会通过 `nodes` 描述符和 `marks` 描述符构建一个 `Schema` 并且会直接转换为内部的 `NodeType` 和 `MarkType` 对象。

`Scheme` 基于内容，可以生成 `node`、`text` 和 `mark`，不过 `node` 和 `text` 都是一样的结点。

`toDOM` 的返回值会被 后面用于自动生成 `HTMLElement`，其类型为：

```tsx
type DOMOutputSpec = string | DOMNode | {
    dom: DOMNode;
    contentDOM?: HTMLElement;
} | readonly [string, ...any[]];
```

而具体解析方式在 `DOMSerializer.renderSpec` 中。



## View

首先阅读了 `prosemirror-view` 的内容，其中主要包括了

- `EditorView`：主要的编辑器对象
- `DirectEditorProps`：实际使用的资产对象
  - `EditorProps`：继承了这个。

从一个代码示例可以了解到 `DirectEditorProps` 是需要一个 `EditorState` 的：

```tsx

        this._view = new EditorView(this._placeHolder.current, {
          state: EditorState.create({
            doc: DOMParser.fromSchema(schema).parse(div),
            plugins: [
              history(),
              keymap({ "Mod-z": undo, "Mod-y": redo }),
              keymap(baseKeymap),
              new Plugin({
                props: {
                  handleKeyDown(view, event) {
                    console.log("A key was pressed!");
                    return false; // We did not handle this
                  },
                },
              }),
            ],
          }),
          editable: this.editable,
          dispatchTransaction: this.dispatchTransaction,
        });

```

除了 `EditorState` , `EditorProps` 中还涵盖了 自定义的 `nodeViews` 和 `markViews`。



在 `viewdesc.ts` 文件中，`docViewDesc` 函数在 `EditorView` 初始化的时候就已经把基础 `dom` 设置好了。其中还有多个视图描述对象：

- `ViewDesc`：基础视图描述对象
  - `WidgetViewDesc`
  - `CompositionViewDesc`
  - `MarkViewDesc`
  - `NodeViewDesc`
    - `TextViewDesc`
    - `CustomNodeViewDesc`

最后还包含一个工具类 `ViewTreeUpdater`

生成的内容描述符最终会通过 `updateChildren` 进行渲染。



### 重要模块

- [prosemirror-commands](https://github.com/ProseMirror/prosemirror-commands/tree/master)/[src](https://github.com/ProseMirror/prosemirror-commands/tree/master/src)/commands.ts：一些官方的命令
- [prosemirror-model](https://github.com/ProseMirror/prosemirror-model/tree/be84a1e44df11a1475831f49fc393a6f5038abe0)/[src](https://github.com/ProseMirror/prosemirror-model/tree/be84a1e44df11a1475831f49fc393a6f5038abe0/src)/to_dom.ts：有很重要的 `renderSpec` 函数