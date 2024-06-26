# 交互设计

> 交互设计的本质是信息传达？



## 2022-01-14

> 来源：[[Bilibili] Figma UI绘制](https://www.bilibili.com/video/BV1RK4y1a7Xb?share_source=copy_web)
>
> 练习时长：新手约2个半小时

涉及内容：

- 基本内容：
  - 手机UI框架、形状（圆角、组合、合并、减去顶层、对齐）、图层、文字（大小、字体、行间距、下划线）
  - 颜色、渐变
- 视觉内容：厚度、层叠、阴影（层次）、圆柱体、配色方案、高光



**01** 绘制结构

1. 顶部操作栏，井字符号栏内有个`Frame`，在右边详情栏可以调节`Frame`的大小。
2. 顶部操作栏，找**形状**和**文字**，拖拽进行绘制
3. 左边`Layout`，可以查看界面元素。界面内使用`CTRL+G`可以群组，方便操作。可以通过左边的元素详情**选中某群组内元素**，或者双击点入群组元素。
4. 选中不同元素，右边`Design`详情栏会不同。通过选中`Rectangle 矩形`，在右边的`Group`内**调整圆角参数**。矩形够大时也可以鼠标拖动**矩形内的圆角锚点**。
5. 选中形状元素，顶层操作栏会出现**形状按钮**，里面可以对多个形状进行**逻辑处理（合并、减去顶层等）**
6. 在右边`Design`栏给元素上不同的颜色。
7. 添加文字。在右边`Design`栏的`Text`中可以调节字号、字形（粗、细），`Text`栏右下脚有个`...`的按钮，点击后可以给字体加首**字母大写**、**下划线**等功能

![](../../../../../Changes729_image/raw/main/ln/README/2022-01-15-Framework.svg)



**02** 调整色彩

8. 色彩调整也在`Design`详情栏中
9. 调整`Group色彩`和`形状色彩`是不同的。可以自行体会下。
10. 在`Design->Fill`中的右上角`+`可以添加图层，一般用这个添加`高光层`和`阴影层`。
11. 单击色彩弹出的**RGB颜色选框界面**，在左上角可以选择上色类型，**渐变**也在这里。

![](../../../../../Changes729_image/raw/main/ln/README/2022-01-15-Finish.svg)

**03** 视觉总结

1. 高光和阴影用来立体化元素。
2. 深色颜色用来表示阴影，也称之为**后退色**。相反，浅色系用来表示高光，也称之为**前进色**。
3. 颜色前进后退是相对的。比如图中的两个橙色部分，圆部分是用**<u>阴影高光打出球形</u>**；而另一部分是通过**<u>色相向冷移动</u>**实现的。
4. 配色整体中等偏下，属于练习色彩的水平。没有心得。



**04** 问题提出

- 如何在绘制时考虑网格系统？
- 如何在绘制时添加安全区？

