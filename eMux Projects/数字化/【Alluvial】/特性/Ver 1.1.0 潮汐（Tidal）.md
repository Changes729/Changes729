# 潮汐（Tidal）

Tidal 是一款日常生活的记录模式。它通过「过去」「昨天」「今日」「明天」和「未来」，构成了一个人的历史脉络，通过一朝一夕的潮汐，冲刷形成新的自己。



「潮汐」会支持 CRM 等系统的开发。



## 逻辑块

```txt
tidal
|-- vision
|-- future(tomorrow、the day after tomorrow)
|-- today
|-- past(yesterday、the day before yesterday)
```

**Alluvial 管理方式**

```txt
[tidal]
|-- README.md（vision）
|-- YYYY
	|-- YYYY-MM-DD.md
```



## milkdown 逻辑块整理

* `blockquote`：引用块

* `bullet_list`：无序列表

* `code_block`：代码块

* `doc`：根结点

* `footnote_definition`：脚注内容

* `footnote_reference`：脚注引用

* `hardbreak`：Markdown AST 中的强制换行结点。

* `heading`：标题

* `hr`：水平分割线

* `html`：HTML 块

* `image`：图片内容块

* `list_item`：列表项

* `ordered_list`：有序列表

* `paragraph`：段落

* `table`：表格块

* `table_cell`：单元格

* `table_header`：表头行

* `table_header_row`：表头块

* `table_row`：表格内容

* `text`：文本

以下为 `marks`

* `emphasis`：弱强调（斜体）

* `inlineCode`：内联代码

* `link`：超链接文本

* `strike_through`：删除线

* `strong`：强强调（粗体）



### 内容块

「潮汐」是内容驱动的。基本内容包括：文本、图片、视频、音频和其他文件。其中，特殊的，文本中还包含了 超文本链接，从而可以访问到来自互联网任何地方的信息。

**01 内容文本**

内容文本（Normal Content），包括了 [超链接]()，`内联代码块` ，**粗体显示**，*斜体显示*。基本上所有的 「内联」 模式都支持。`![智能链接](...)` 也属于内容文本的范畴。



`text`：内容的修饰包括了：`emphasis`、`inlineCode`、`link`、`strike_through`、`strong`，修饰不影响段落的阅读。仅保护文本内容的有：

* `paragraph`：段落是由文本构成的，是行文的基础单位。

* `code_block`：代码块全部由纯文本构成。

* `heading`：标题也是由文本构成的。不过其构成逻辑和 段落 是一致的。



**02 内容定义**

内容是不可拆分的，要么存在，要么删除。内容可以转化，可以修饰，但是无论如何转化和修饰，内容还是以单元存在。内容可以组合成一个新的整体，但是彼此之间不存在关系：不存在内容与内容的等价，也不存在内容和内容的包含。

* 超链接：超链接由两个内容组合而成，标签和链接。

固定格式的内容，由修饰文本和内容构成。修饰后的内容依旧是内容。



### 标签块

标签块是一种逻辑块，和内容不一样，标签只有依赖内容而生，无法脱离内容而存在。「潮汐」中，每一个内容的产生，都会存在自然标签与之匹配，包括内容属性（文本、多媒体等），以及时间。

标签是内容文本的关系构成。文本的关系大体包括以下内容：

* 平等构成关系（没关系）：平等的内容构成了一则普通的文章。

* 修饰关系：在普通的内容上进行修饰，比如超链接、粗体、斜体等。

* 等价关系：对某种概念的进一步说明。通常用 `：` 表示一种内容的展开。

* 包含关系（树状）：使用一种树形结构构成多层次的关系。

`paragraph`

* `table_cell`

  * `table_row`

* `table_header`

  * `table_header_row`

    * `table`

* `list_item`

  * `ordered_list`

  * `bullet_list`



`doc`：包含有

* `paragraph`

* `image`

* `blockquote`



### 拆分逻辑

**01 基本时间**

输入的内容，都会有一个基本时间作为记录，时间精细到小时。最新内容会根据最终输入时间决定。如果修改了内容，并且不是最新内容，则不会修改标签时间，系统会视作修改历史记录。

历史记录在交互上只能修改昨天一天的内容，再久远的内容修改需要通过其他方式。

除了日程时间（YY-DD），其余时间并不会直接显示。标签会存在在内容的右边。



日志系统是不存在标签的。所有的标签内容需要二次打标，以及使用超链接或智能链接。

日志系统的主标签是时间系统，并采用 `DateTime` 时间记录。基本构成为

```txt
Date
|-- README				# 内容文件
|-- named-file			# 一些具名的文件，往往是文件中被引用的数据
```





**02 文件系统**

```
	::	# File title						->		File_title.md   < file content.
	::	file content.
	::	another file content.				->		File_title.1.md < another file content.
	^___ file operation part.
```

先前的实现，所有内容通过一个文件保存，并通过 Markdown 的语法实现分离。

当下，我们希望 Title 自然作为标签系统的一环，自动将各个字内容填充进入子文件。这种行文逻辑类似于写书。
