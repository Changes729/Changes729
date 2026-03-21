> 参考资料：[unifiedjs](https://github.com/unifiedjs)/[unified](https://github.com/unifiedjs/unified)

# UnifiedJS

## Overview

> `unified` is an interface for processing content with syntax trees. Syntax trees are a representation of content understandable to programs. Those programs, called *[plugins](https://github.com/unifiedjs/unified#plugin)*, take these trees and inspect and modify them. To get to the syntax tree from text, there is a *[parser](https://github.com/unifiedjs/unified#parser)*. To get from that back to text, there is a *[compiler](https://github.com/unifiedjs/unified#compiler)*. This is the *[process](https://github.com/unifiedjs/unified#processorprocessfile-done)* of a *processor*.

`unified` 是一个使用 语法树（Syntax trees）处理内容的界面。语法树是一种程序可以理解的内容呈现。这些程序，被称为 *插件（[plugins](https://github.com/unifiedjs/unified#plugin)）*，对这颗树进行读取和修改。从文本中获取 语法树的过程，称之为 *拷贝器（[parser](https://github.com/unifiedjs/unified#parser)）*，而将其重新回归文本的过程，称之为 *编译器（[compiler](https://github.com/unifiedjs/unified#compiler)）*，下面是这个处理器（Processor）的[流程](https://github.com/unifiedjs/unified#processorprocessfile-done):

```
| ........................ process ........................... |
| .......... parse ... | ... run ... | ... stringify ..........|

          +--------+                     +----------+
Input ->- | Parser | ->- Syntax Tree ->- | Compiler | ->- Output
          +--------+          |          +----------+
                              X
                              |
                       +--------------+
                       | Transformers |
                       +--------------+
```



**01 处理器（Processors）**

```tsx
const processor = unified()
  .use(remarkParse)
  .use(remarkRehype)
  .use(rehypeDocument, {title: '👋🌍'})
  .use(rehypeFormat)
  .use(rehypeStringify)
```



**02 文件**

> When processing a document, metadata is gathered about that document. [`vfile`](https://github.com/vfile/vfile) is the file format that stores data, metadata, and messages about files for unified and plugins.
>
> There are several [utilities](https://github.com/vfile/vfile#list-of-utilities) for working with these files.

当我们处理一篇文档，会搜集关于该文档的元数据。[`vfile`](https://github.com/vfile/vfile) 是存储数据、元数据以及有关 Unified 和插件文件信息的文件格式。

有几个 [工具](https://github.com/vfile/vfile#list-of-utilities) 可用于处理这些文件。



**03 语法树（Syntax tree）**

> The syntax trees used in unified are [unist](https://github.com/syntax-tree/unist) nodes. A tree represents a whole document and each [node](https://github.com/syntax-tree/unist#node) is a plain JavaScript object with a `type` field. The semantics of nodes and the format of syntax trees is defined by other projects:
>
> - [esast](https://github.com/syntax-tree/esast) — JavaScript
> - [hast](https://github.com/syntax-tree/hast) — HTML
> - [mdast](https://github.com/syntax-tree/mdast) — markdown
> - [nlcst](https://github.com/syntax-tree/nlcst) — natural language
> - [xast](https://github.com/syntax-tree/xast) — XML
>
> There are many utilities for working with trees listed in each aforementioned project and maintained in the [`syntax-tree`](https://github.com/syntax-tree) organization. These utilities are a level lower than unified itself and are building blocks that can be used to make plugins.

Unified 使用的语法树是 [unist](https://github.com/syntax-tree/unist) 结点。树表示整个文档，每个结点（[node](https://github.com/syntax-tree/unist#node)）都是带有 `type` 字段的普通 JS 对象。结点的语法和语法树的格式由其他项目定义。

- [esast](https://github.com/syntax-tree/esast) — JavaScript
- [hast](https://github.com/syntax-tree/hast) — HTML
- [mdast](https://github.com/syntax-tree/mdast) — markdown
- [nlcst](https://github.com/syntax-tree/nlcst) — natural language
- [xast](https://github.com/syntax-tree/xast) — XML

有许多可以使用的工具，已经列举在上面了。这些工具会在 [`syntax-tree`](https://github.com/syntax-tree) 中进行维护。



**04 生态系统**

> Around each syntax tree is an ecosystem that focusses on that particular kind of content. At their core, they parse text to a tree and compile that tree back to text. They also provide plugins that work with the syntax tree, without requiring that the end user has knowledge about that tree.
>
> - [rehype](https://github.com/rehypejs/rehype) (hast) — HTML
> - [remark](https://github.com/remarkjs/remark) (mdast) — markdown
> - [retext](https://github.com/retextjs/retext) (nlcst) — natural language

每个语法树都有一个专注于特定内容的生态系统。他们的核心都是实现文本的解析和生成。他们还提供了使用语法树的插件，而不需要用户了解他们的具体实现。

- [rehype](https://github.com/rehypejs/rehype) (hast) — HTML
- [remark](https://github.com/remarkjs/remark) (mdast) — markdown
- [retext](https://github.com/retextjs/retext) (nlcst) — natural language



**05 插件**

> Each aforementioned ecosystem comes with a large set of plugins that you can pick and choose from to do all kinds of things.
>
> - [List of remark plugins](https://github.com/remarkjs/remark/blob/main/doc/plugins.md#list-of-plugins)·[`remarkjs/awesome-remark`](https://github.com/remarkjs/awesome-remark)·[`remark-plugin` topic](https://github.com/topics/remark-plugin)
> - [List of rehype plugins](https://github.com/rehypejs/rehype/blob/main/doc/plugins.md#list-of-plugins)·[`rehypejs/awesome-rehype`](https://github.com/rehypejs/awesome-rehype)·[`rehype-plugin` topic](https://github.com/topics/rehype-plugin)
> - [List of retext plugins](https://github.com/retextjs/retext/blob/main/doc/plugins.md#list-of-plugins)·[`retextjs/awesome-retext`](https://github.com/retextjs/awesome-retext)·[`retext-plugin` topic](https://github.com/topics/retext-plugin)
>
> There are also a few plugins that work in any ecosystem:
>
> - [`unified-diff`](https://github.com/unifiedjs/unified-diff) — ignore unrelated messages in GitHub Actions and Travis
> - [`unified-infer-git-meta`](https://github.com/unifiedjs/unified-infer-git-meta) — infer metadata of a document from Git
> - [`unified-message-control`](https://github.com/unifiedjs/unified-message-control) — enable, disable, and ignore messages from content

上述的每个生态系统都带有一个大型插件集合，你可以从中挑选并选择做各种事情。

- [List of remark plugins](https://github.com/remarkjs/remark/blob/main/doc/plugins.md#list-of-plugins)·[`remarkjs/awesome-remark`](https://github.com/remarkjs/awesome-remark)·[`remark-plugin` topic](https://github.com/topics/remark-plugin)
- [List of rehype plugins](https://github.com/rehypejs/rehype/blob/main/doc/plugins.md#list-of-plugins)·[`rehypejs/awesome-rehype`](https://github.com/rehypejs/awesome-rehype)·[`rehype-plugin` topic](https://github.com/topics/rehype-plugin)
- [List of retext plugins](https://github.com/retextjs/retext/blob/main/doc/plugins.md#list-of-plugins)·[`retextjs/awesome-retext`](https://github.com/retextjs/awesome-retext)·[`retext-plugin` topic](https://github.com/topics/retext-plugin)

还有一些插件可以在任何生态系统中工作：

- [`unified-diff`](https://github.com/unifiedjs/unified-diff) — 忽略 Github Actions 和 Travis 中不相关的信息
- [`unified-infer-git-meta`](https://github.com/unifiedjs/unified-infer-git-meta) — 从 Git 中推断文档的元数据
- [`unified-message-control`](https://github.com/unifiedjs/unified-message-control) — 启用、禁用和忽略来自内容的信息



**06 集成**

> unified can integrate with the file system through [`unified-engine`](https://github.com/unifiedjs/unified-engine). CLI apps can be created with [`unified-args`](https://github.com/unifiedjs/unified-args), Gulp plugins with [`unified-engine-gulp`](https://github.com/unifiedjs/unified-engine-gulp), and language servers with [`unified-language-server`](https://github.com/unifiedjs/unified-language-server). A streaming interface can be created with [`unified-stream`](https://github.com/unifiedjs/unified-stream).

united可以通过[`unified-engine`](https://github.com/unifiedjs/unified-engine)与文件系统集成。CLI应用程序可以使用[`unified-args`创建](https://github.com/unifiedjs/unified-args)，Gulp插件可以使用[`unified-engine-gulp`创建](https://github.com/unifiedjs/unified-engine-gulp)，语言服务器可以使用[`unified-language-server`](https://github.com/unifiedjs/unified-language-server)创建。可以使用[`unified-stream`](https://github.com/unifiedjs/unified-stream)创建流媒体接口。