> Ver 1.0.0

# WebViewer

## 项目初衷

WebViewer 其目的在支持本地数字资源的定制化浏览。

此版本聚焦于本地 Markdown 文本的网页呈现。未来会考虑富文本、LaTex、AsciiDoc等富文本格式。

## 当前资源

开启此项目之前，笔者一直使用 Typora 进行本地 Markdown 笔记整理；并使用范畴学分类，树状管理本地笔记。

在笔记更新上，依赖 Typora 的 所见即所得（WYSIWYG）编辑器。

在笔记阅读上，依赖 Typora 的 Markdown Style Viewer 进行阅读，也依赖 Typora 支持的本地搜索功能进行检索。

为了提升阅读效率和灵活性，使用 React + React Markdown，加 golang 实现的 Web 后端实现了网页阅读。

在笔记搜索上，Linux环境多会使用 `find` 查找具体文件，使用 `awk` 检索文件内的具体内容。

## 需求要素

此版本的需求，在于将本地的 Markdown 数据库，可以更轻松的支持网页浏览和文本查询。

由于 Typora 软件闭源，且新版本开始收费。因此笔者在使用的旧版本 Typora 会不太稳定，经常出现卡死、输入异常的情况。因此，最起码的要素就是软件要持续更新（LTS）。

另外，Markdown 转 HTML 的视觉效果依旧需要保持 Github Style。

最后的需求就是尽可能小巧、可拓展。

## 积累与效果

### 市场产品（Markdown APP & Library）

截止 2025年1月28日（农历除夕），在市场上扫描到了以下产品：

- [volca](https://github.com/volca)/[markdown-preview](https://github.com/volca/markdown-preview)：提供了浏览器插件，可以直接通过 `File:///` 访问 `.md` 后缀的文件，自动加载为 `Markdown Html`。
- [marktext](https://github.com/marktext)/[marktext](https://github.com/marktext/marktext)：Typora 的开源替代品，不过好像10个月前就不更新了。
  - [marktext](https://github.com/marktext)/[muya](https://github.com/marktext/muya)：现在他们开始转向开发网页版本的了
  - Issue里面也有人说使用 [joplin](https://github.com/laurent22/joplin)，但是它的 UI I dont like.
- [markedjs](https://github.com/markedjs)/[marked](https://github.com/markedjs/marked)：老牌 Markdown 转 HTML 工具。
- [remarkjs](https://github.com/remarkjs)/[react-markdown](https://github.com/remarkjs/react-markdown)：React 支持的 markdown，其底层为 unified 的 remark，支持 unified 生态。
  - [unifiedjs](https://github.com/unifiedjs)/[unified](https://github.com/unifiedjs/unified)
  - [remarkjs/*remark*](https://github.com/remarkjs/remark)
- [honwhy](https://github.com/honwhy)/[md](https://github.com/honwhy/md)：支持 markdown 直转 微信公众号
- https://codemirror.net/: 支持多种编程语言的网页库， marktext 就是 codemirror 的上层应用。

从本阶段的目标而言，`markdown-preview` 可以满足网页浏览的需求；`marktext` 可以完美替代 `typora`，但是还是缺乏网页直接搜索本地数据库的功能。

另外，考虑到未来发展，这里搜索了很多底层库，考虑到未来的一些需求，应该选择哪一种开源库基础上进行开发。

搜索功能暂时没有找到合适的开源库。不过 marktext 软件也实现了。

### 技术路线

**01.1 marktext search 原理**

文件内容搜索的原理是从 atom 中迁移过来的，marktext 的搜索功能文件为[ripgrepSearcher](https://github.com/marktext/marktext/blob/develop/src/renderer/node/ripgrepSearcher.js)，其底层为 `ripgrep`，也可以参考 [VSCode 调用 ripgrep](https://github.com/microsoft/vscode-ripgrep)

**01.2 marktext 文件树功能**

marktext 的文件树功能，UI 标签为 `project-tree`。由于 electron 渲染线程分离，具体的数据被存储在渲染层的 `projectTree` 内。并通过应用层的 IPC 工具发送 `mt::update-object-tree` 同步信息。

也就是说具体的文件树生成是在应用层实现的。底层依赖库 [chokidar](https://github.com/paulmillr/chokidar)。

VSCode 的文件树底层也使用了 chokidar，控件路径位于 **`src/vs/base/browser/ui/tree/`**，业务路径位于 **`src/vs/workbench/contrib/files/browser/views/`**

**01.3 VSCode 文件树功能**

electron 版本的文件树使用 chokidar，然而，网页版本的 VSCode 则使用[文件系统 API](https://developer.mozilla.org/zh-CN/docs/Web/API/File_System_API)。其中，本地文件系统称为 OPFS（Origin Private File System）

**01.4 markdown-preview 架构简析**

没什么架构，markdown-preview 会在HTML加载完毕后，如果URL符合要求，则会自动调用 marked 将文本转化为 HTML。

具体转化文件在 [markdownnify.js](https://github.com/volca/markdown-preview/blob/master/js/markdownify.js) 文件中。需要注意的是这个文件使用了 [Immediately-Invoked Function Expression (IIFE) 写法](https://stackoverflow.com/questions/42489305/what-is-functiondocument-document)。

**02.1 浏览器插件的侧边栏实现**

[chrome.sidePanel](https://developer.chrome.com/docs/extensions/reference/api/sidePanel?hl=zh-cn#examples) 有针对侧边栏的开发说明。

浏览器也可以通过 [源私有文件系统](https://developer.mozilla.org/zh-CN/docs/Web/API/File_System_API/Origin_private_file_system) 直接访问本地文件。

**02.2 OPFS Load and handler**

**02.3 AutoReload Markdown Filetype**
