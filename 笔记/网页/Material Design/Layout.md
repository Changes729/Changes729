原文链接: [[Material Design] Layout](https://material.io/design/layout/understanding-layout.html#principles)

# Layout

网格系统，这一章没能那么快理解。就是Layout有三部分构成：`margnis 边缘`、`Gutters 沟道`和`Columns 列`。

每一个部分都由最基本的网格系统构成，有`8dp`，也有`4dp`系统。Icon图标、小图标、按钮都是在这基础上设计的。



这么一来，其实设计工具就显得很重要了：网格辅助设计。

- [Shadows Resources](https://material.io/archive/guidelines/resources/shadows.html#)



![img](../../../../../Changes729_image/raw/main/ln/Layout/Columns.png)

On mobile, at a breakpoint of 360 dp, this layout grid uses 4 columns.

![img](../../../../../Changes729_image/raw/main/ln/Layout/Gutter.png)

On mobile, at a breakpoint of 360 dp, this layout grid uses 16dp gutters.



![img](../../../../../Changes729_image/raw/main/ln/Layout/Dimensions.png)

1. Status bar height: 24dp
2. App bar height: 56dp
3. List item height: 88dp



![img](../../../../../Changes729_image/raw/main/ln/Layout/bottom%20navigation.png)

Elements of the bottom navigation bar align to the 4dp grid. (Total 8 + 24 icon + 12 label + 12 = 56dp)



![img](../../../../../Changes729_image/raw/main/ln/Layout/Touch%20target.png)

Touch target minimum of 48 x 48 dp

1. 40dp element, 48dp touch target
2. 24dp element, 48dp touch target
3. 36dp element, 48dp touch target