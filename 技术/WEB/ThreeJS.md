> 相关链接
>
> - [Fundamentals](https://threejs.org/manual/#en/fundamentals)：ThreeJS 初学者简介
>   - [图元](https://threejs.org/manual/zh/primitives.html)
>   - [材质](https://threejs.org/manual/zh/materials.html)
>   - [纹理](https://threejs.org/manual/zh/textures.html)

# ThreeJS

## 关键词

- 渲染器(Renderer)
- 场景(Scene)
  - 网格(Mesh)
    - 几何体(Geometry)
    - 材质(Material)
    - 纹理(Texture)：过滤（filter）
  - 光源(Light)
    - 环境光（AmbientLight）
    - 半球光（HemisphereLight）
    - 方向光（DirectionalLight）
    - 点光源（PointLight）
    - 聚光灯（SpotLight）
- 摄像机(Camera)
  - 正摄相机（OrthographicCamera）
  - 

- **fov** (视野范围，field of view)：垂直方向
- aspect，画布宽高比
- near：近平面
- far：远平面



## 材质

- 物理渲染（*Physically Based Rendering*，PBR）的材质
  - 金属度
  - 粗糙度
  - 光泽度和反光度



## 纹理

*一般来说*，纹理会占用 `宽度 * 高度 * 4 * 1.33` 字节的内存。

那张图片只有157k，所以下载起来会比较快，但实际上它的大小是3024×3761像素.。按照上面的公式。在three.js中，这张图片会占用**60兆（meg）的内存！**。



## 阴影

> [43_阴影贴图2_阴影贴图原理](https://www.bilibili.com/video/BV1zG4y167i6/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：光源摄像头；深度图；反向贴图

Three.js 默认使用*shadow maps（阴影贴图）*，**阴影贴图的工作方式就是具有投射阴影的光能对所有能被投射阴影的物体从光源渲染阴影**。请再读一遍，试着去理解并记住

如果你有 20 个物体对象、5 个灯光，并且所有的物体都能被投射阴影，所有的光都能投射阴影，那么这个场景这个场景将会绘制 6 次。第一个灯光将会为所有的物体投影阴影，绘制场景。然后是第二个灯光绘制场景，然后是第三个灯光，以此类推。最后一次（即第六次）将通过前五个灯光渲染的数据，渲染出最终的实际场景。

糟糕的是，如果你有一个能投射阴影点光源在这个场景中，那个这个场景将会为这个点光源再绘制 6 次。

由于这些原因，除了寻找其他根本上的解决方案去解决一堆光源都能投射阴影的性能问题。一般还有常见的解决方案，就是允许多个光源，但只让一个光源能投射阴影。

另一个解决方案就是使用光照贴图或者环境光贴图，预先计算离线照明的效果。这将导致静态光照，但是至少该方案渲染得非常快。在另一篇文章中将涵盖这两个解决方案。

`.bias`：这里非常微小的调整（大约0.0001）可能有助于减少阴影中的**伪影**。

