> 原文链接: [[Material Design] Surfaces](https://material.io/design/environment/surfaces.html#material-environment)

# Environment

## Surface 平面

<u>**关键字**：平面（surface）、深度（depth）、阴影（shadows）</u>

**单位**：dp（Density-independent pixel，屏幕像素点密度为 160ppi 时 1px 长度）

Material Design 是模仿现实生活中的材料，而显示在手机屏幕之上的视觉 UI 设计范式。

> ### The physical world
>
> In the physical world, objects can be stacked or attached to one another, but cannot pass through each other. They cast shadows and reflect light.
>
> Material Design reflects these qualities in how surfaces are displayed and move across the Material UI. Surfaces, and how they move in three dimensions, are ommunicated in ways that resemble how they move in the physical world. This spatial model can also be applied consistently across apps.

虽然是取自生活，但是 Material 其实不是液体也不是气体，这是 Material Design 设计的。文中描述了许多 Material 的特性。

它有点像对一个通用 content 进行定义，开发 Web 的可以认为是对一个`dev`进行属性定义。

在`Behavior`一栏中就支出有三种行为：`Rigid 刚性`、`Stretchable 延展性`和`Pannable 拖动性`。

### 总结

整篇文章主要以最基本的`Surface`概念说起，这里提到的`Surface`就是我们手机上面的任意元素、任意平面。文章提到，`Surface`就是一个高度为 1dp 的小平面。由于整个手机显示的是一个 3D 的画面，所以，这个 urface 是有高度的，而这个高度，就通过阴影展现出来。通过这样的方式去设计 UI，既合理又美观。

文中还介绍了`Surface`和其他文本、图片等内容的关系、`Surface`的颜色、透明度、形状、动效以及具体实现效果和场景。

最后介绍了一下滤光网`Scrims`。也就是我们常说的阴影遮罩。

## Elevation 海拔

海拔在`Surface`内也有提过，这里不仅仅提到了`Surface`内的高低，也体现了`Surface`与`Surface`之间的高度，就体现在`Scrims`上。

文章还说明了海拔的变化与交互之间的关系。

最后，给出了一些控件的默认海拔高度。

![img](<../../../../../Changes729_image/raw/main/ln/Environment/Elevation(DPs).png>)

<video autoplay loop muted="true"><source src="file:///home/asuki/Downloads/mio-staging_mio-design_1581631970573_assets_1QJydhs6x1YdaiMy5KgClaESCOMjsJss__elevation-hero.mp4"/></video>

**Component elevation values**

1. Nav drawer: 16dp
2. App bar: 4dp
3. Card: 1dp to 8dp
4. FAB: 6dp
5. Button: 2dp to 8dp
6. Dialog: 24dp



## Light and shadows

![img](../../../../../Changes729_image/raw/main/ln/Environment/Light%20and%20shadows.png)
