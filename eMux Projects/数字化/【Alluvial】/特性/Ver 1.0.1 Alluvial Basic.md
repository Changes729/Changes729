> 参考资料：**[CommonMark spec](http://spec.commonmark.org/)**

# Ver 1.0.1 Alluvial Basic

我们之前已经实现了基于 milkdown（Prosemirror + unified remark）实现的 markdown 编辑器，并且支持了 Header、List item、block 等 WYSIWYG 元素。证明了这条技术路线的可行性。

现在的目标，是进一步将此技术转化到现实生产之中。此处，我们要面临的是技术的工程化，要因对各种不同的用户媒介进行广泛性设计。

我们当前的数据内容仍然以文本为主。通过使用 Markdown 赋予的超链接能力，增强纯文本（Plain Text）的拓展性。

## 用户终端

可以认识到的，当前的用户终端主要有以下硬件设备：智能手机、私人电脑。

其中，私人电脑的界面，类似 Typora，用于编辑文本，实现自我觉察。而手机端，则类似于 Wechat，用于记录块信息。

### 产品标签框架

```
01 /Alluvial/tools/									alluvial-fs
01 /Alluvial/tools/manager/							alluvial-fs

02 /Alluvial/tools/inputer/editor/					alluvial-editor
02 /Alluvial/tools/inputer/HID/PC/					alluvial-typora
02 /Alluvial/tools/inputer/HID/Android/				alluvial-wechat
```

### 编辑器新增支持

**01 超链接支持**

* [x] 可以通过 `[content](href)` 的方式构建超链接

* [x] 可以点击超链接：通过设置 `style` 并添加全局 `onclick` 处理解决。

* [x] 可以修改超链接的内容和标题：通过 [ex. tooltip-plugin](https://milkdown.dev/docs/plugin/example-tooltip-plugin) 了解到有 [link-tooltip](https://github.com/Milkdown/milkdown/tree/main/packages/components/src/link-tooltip)

**02 图片支持**：

* [ ] ~~可以通过纯文本方式输入图片~~：暂时不考虑

![1.00](https://upload.wikimedia.org/wikipedia/commons/thumb/4/48/Markdown-mark.svg/208px-Markdown-mark.svg.png?20190322184628 "File:Markdown-mark.svg")

* [x] 可以直接复制图片

**03 HTML支持**：

* [ ] ~~支持 HTML 块编辑~~：暂时不考虑

**04 其他 Bug 修复**：

* ~~inlinecode~~： 后面再修

  * [ ] `inlinecode`前后无法选中

  * [ ] 仅支持英文输入

* [x] 文件读取和保存保留空行：暂时不支持空行读取。空行读取可能可以通过将两个 `\n\n` 转译为一个换行。

* [x] 不将空行保存为 `<br/>`：空行出现的行为是在 `pm-view` 中的 `addTextblockHacks` 实现的。

  现在要做的是自己 fock 一个，并尝试用自己的库替代 milkdown 旧有库

  成功使用 `pnpm patch` 功能取消空行的 HTML 保存， 但是 remark 会忽略空行读取。通过将两个连续的 `\n\n` 加载为 `<br/>\n` 成功实现。

* [x] `codeblock` tab size 问题：Style 解决

## 技术底层

**01 虚拟文件**

不考虑铆钉固定的文件系统。

考虑使用抽象的时间文件系统（YYYY-MM-DD）
