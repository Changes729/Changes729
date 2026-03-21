# 数据关系与数据管理

思考一下以下的日志系统。

```txt
日志
|-- YYYY-MM-DD
	|-- Readme.md
	|-- image.img
	|-- xxx.md
```

这个是一般日志系统的组织形式。所有文件都包含在一个日期目录下。 `Tidal` 最开始实现的功能也是如此。

我们将这样的基本日志组织形式称为 `Diary Only`  的形式。



## Diary Only 

`Diary Only` 的组织形式，优点是，在`文件系统`中还是在`网站`中，都可以通过 `PATH/URL` 的形式进行 **数据访问**，同时，**数据备份**也比较简单，只需要文件夹拷贝即可。

然而，这种组织形式 数据备份的优势，也恰好是其劣势。对文件夹进行拷贝复制，就意味着冗余和标签缺失。

- 冗余：同样的 图片可能会被多个文件引用，但是数据备份的时候是单独文件夹备份的。
- 标签缺失：标签仅局限于文件夹内，一旦文件夹关系破坏，数据之间的关系就会缺失。



一般来说，我们希望一些大数据可以被集中管理和优化。比如，我想引用 `markdown` 的 ICON，最好的办法就是通过 markdown `URL` 进行引用。除非对个体特别重要的数据，确实需要备份，那么才会下载下来。



我们对这种需要备份管理的数据中心称为——「个人中心化大数据管理」。

- 以个人为中心：只记录个体认为重要的数据。
- 个人中心化大数据：以个人关注的大数据数据只有一个抽象的大数据数据中心。
- 个人大数据管理：对数据进行个人友好的高效检索。



## Flexible Relation —— 灵活的大数据关系

对 `Diary Only` 的升级，就是基于一个 「个人中心化大数据管理」的 `Flexible Relation` 。

其组织关系如下：

```txt
Flexible Relation（Manager/Backup）
|-- Diary					O
	|-- YYYY				| => Flexible Relation
		|-- YYYY-MM-DD.md	O
|-- Image					O
	|-- YYYY-MM-DD			|
		|-- xxx.img			|		
|--	Video					|
	|-- YYYY-MM-DD			| => User Centralized BigData Manager
		|-- xxx.mov			|
|-- Audio					|
	|-- YYYY-MM-DD			|
		|-- xxx.wav			|
|-- ...						O
|-- xxx						O => Abstract Project
```



比如，我们打开了某个日志 —— `2025-12-30.md`，其中有一个图片 `![](./someImage.png)`，这种引用形式和 `Diary Only` 是一致的，但是可以通过 `Web`的方式进行拓展，通过检测 `.png` 类型，定位到 `Image`大类，然后再重定向到 `./Image/2025-12-30/someImage.png`。就可以获取到图片了。



我们希望 `Diary` 象征的，对数据的灵活关系，就像 `Alluvial` 一样，冲积平原生成的过程尽可能的自然。而其生成的结果，才是真正的生活记录之美。