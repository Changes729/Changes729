> 参考资料：[prosemirror-markdown](https://github.com/ProseMirror/prosemirror-markdown)

# ProseMirror-Markdown

首先定义 `schema` ，因为 ProseMirror 依赖这个构建树状关系。

然后，通过 `MarkdownParseState` 生成一个映射表，这个映射表需要将 `scheme` 中的对象，进一步的映射为 `markdown-it` 的对象，其中还包含了加载逻辑。最后，就是调用 `markdown-it` 读取其返回树，然后便利树。

代码使用了一个栈空间，用来管理从属关系。