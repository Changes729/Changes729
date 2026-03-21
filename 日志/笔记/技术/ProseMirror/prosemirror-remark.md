> 参考资料：[prosemirror-unified](https://github.com/marekdedic/prosemirror-unified)

# ProseMirror-remark

> ## Creating your own extensions
>
> prosemirror-unified provides several utilities for creating your own extension to support custom unified syntax. Please note that `prosemirror-unified` doesn't aim to extend unified itself, so you either need to take an existing unified plugin (such as remark for GitHub or rehype for HTML) or create your own. prosemirror-unified provides the tools to translate between the unified syntax (called unist) and the ProseMirror syntax.
>
> Documents in unist are represented by an abstract syntax tree (AST) of nodes, starting with a root node representing the whole document. In ProseMirror, things work mostly the same way, with one important difference - ProseMirror has a concept of *marks* that can be applied to a node in the AST. These represent things such as bold text, which in ProseMirror is just a text node with a mark to make it bold. In unist, there are no marks and bold text is represented by a bold node, which contains a text node.
>
> To make up for this difference, prosemirror-unified provides two basic types of extensions:
>
> - A `NodeExtension` is used when translating between a unist node and a ProseMirror node - for example a paragraph. The extension provides functions to translate both ways.
> - A `MarkExtension` is used to translate between a unist node and a ProseMirror mark - for example bold text. This type of extension also provides fnctions to translate both ways.

## 创建你自己的拓展方案

prosemirror-unified 提供许多工具，帮助您创建自己的扩展以支持自定义 unified 语法。请注意，`prosemirror-unified` 并不打算扩展 unified 本身，所以你要么需要使用现有的 unified 插件（例如GitHub的remark或HTML的rectype），要么创建自己的插件。prosemirror-unified 提供了在统一语法（称为 unist 结点）和 ProseMirror 语法之间进行转换的工具。

unist 中的文档由节点的抽象语法树（abstract syntax tree，AST）表示，从表示整个文档的根节点开始。在 ProseMirror 中，事物的工作方式基本相同，只有一个重要的区别 —— ProseMirror 有标记（Mark）的概念，可以应用于 AST 中的节点。这些表示诸如粗体文本之类的内容，在ProseMirror中，粗体文本只是一个带有标记的文本节点。在 unist 中，没有标记，粗体文本由包含文本节点的粗体节点表示。

为了弥补这一差异， prosemirror-unified 提供了两种基本类型的扩展：

- 在 unist 节点和 ProseMirror 节点之间转换时使用 `NodeExtension` 例如段落。该扩展提供了两种方式的翻译功能。
- `MarkExtension` 用于在 unist 节点和 ProseMirror 标记之间转换，例如粗体文本。这种类型的扩展还提供了转换两种方式的功能。



> ### Translating from unist to ProseMirror
>
> prosemirror-unified traverses an existing unist AST and creates a matching ProseMirror AST from the leaf nodes to the root. For each node, all extensions are checked to find one that can translate this type of node. Once an applicable extension is found, all the children of the node are translated first. Only after that is the actual node translated, so that it can use the already-prepared children and incorporate them in the ProseMirror tree. This process works the same for `NodeExtension`s and `MarkExtension`s as the extension can decide what the output node will look like and what marks it will have.
>
> As some extensions need to add information after the whole document is parsed, there is a global context that any extension can modify when translating a node. Additionally, a post-translation hook can be added to any extension.

### 从 unist 到 ProseMirror

prosemirror-unified 遍历现有的 unist AST，并创建从叶节点到根节点的匹配 ProseMirror AST。对于每个节点，检查所有扩展以找到可以转换此类型节点的扩展。一旦找到一个适用的扩展，节点的所有子节点将首先被转换。只有在此之后，才转换实际的节点，以便它可以使用已经准备好的子节点并将它们合并到 ProseMirror 树中。这个过程对 `NodeExtension` 和 `MarkExtension` 的工作原理相同，因为扩展可以决定输出节点的外观以及它将具有什么标记。

由于某些扩展需要在解析整个文档后添加信息，因此在翻译节点时，任何扩展都可以修改全局上下文。此外，翻译后钩子可以添加到任何扩展。



> ### Translating from ProseMirror to unist
>
> prosemirror-unified traverses the existing unist AST and creates a matching unist AST from the leaf nodes to the root. For each node, all extensions are searched to find a `NodeExtension` that can translate this node. Once an applicable `NodeExtension` is found, all the children of the node are translated first. Only after that is the actual node translated, so that it can use the already-prepared children and incorporate then in the unist tree. If the original ProseMirror node had any marks, then for each mark a matching `MarkExtension` is found and that extension can post-process the already-translated unist node. For multiple marks, the order in which they are processes will is not guaranteed.

### 从ProseMirror到Unist

prosemirror-unified 遍历现有的unist AST，并创建从叶子节点到根节点的匹配的unist AST。对于每个节点，搜索所有扩展以找到可以翻译该节点的`NodeExtension`。一旦找到适用的`NodeExtension`，则首先转换节点的所有子节点。只有在此之后，才转换实际的节点，以便它可以使用已经准备好的子节点并将其合并到unist树中。如果原始的ProseMirror节点有任何标记，那么对于每个标记，都会找到匹配的`MarkExtension`，并且该扩展可以后处理已经翻译的unist节点。对于多个标记，不保证它们的处理顺序。

> #### Example
>
> Bold text is represented by a Text node with a Bold mark in ProseMirror. As such, when translating to unist, first a hypothetical `TextExtension` (which is a `NodeExtension`) is called, which translates the node into a unist Text node. This unist node is then post-processed by a `BoldExtension` (which is a `MarkExtension`) and changed into a unist Bold node (which contains the original unist Text node).

### 案例

粗体文本由ProseMirror中带有粗体标记的Text节点表示。因此，当转换为unist时，首先调用假设的`TextExtension`（它是`NodeExtension`），它将节点转换为unist Text节点。然后，这个unist节点由`BoldExtension`（即`MarkExtension`）进行后处理，并更改为unist Bold节点（包含原始的unist Text节点）。
