> 视频来源：https://www.youtube.com/watch?v=YKRK82JeBo8
>
> 参考资料：
>
> - [**Procedural Patterns And Noises**](http://neilblevins.com/art_lessons/procedural_noise/procedural_noise.html)

# Blender 教程 程序节点石材材质

## 关键词

- HDR：polyhaven.com、`Environment Texture`
- 插件：[Node Wrangler](https://docs.blender.org/manual/en/latest/addons/node/node_wrangler.html)
- [Voronoi Texture（沃罗诺伊纹理）](https://zhuanlan.zhihu.com/p/27084187348)[【Blender】](https://docs.blender.org/manual/zh-hans/4.5/compositing/types/texture/voronoi.html)：离散点集，空间划分方法。
  - `Ctrl + T`
  - `Ctrl + Shift`：预览效果
  - 参数
    - F1
    - Distance to Edge（到边缘的距离）
      - Scale（缩放）
- Texture Coordinate（纹理坐标）
- Noise Texture（噪波纹理）
  - Detail（细节）：
  - Roughness（粗糙度）：
- Principled BSDF（原理化 BSDF）：
  - Roughness（粗糙度）：
  - Normal（法线？）：
- Bump（凹凸节点）
- ColorRamp（颜色渐变）：
- `Ctrl + Shift + D`：用来复制
- mix（混合颜色）
  - Darken（变暗）：
    - Fac（系数）



## 摘记

**01 Voronoi Texture（沃罗诺伊纹理）**

**01.1 晶格距离**

我觉得[知乎]()写的内容在理解上已经没什么问题了。但是事实上，Blender的 Voronoi Texture 在参数上还挺多的。

从晶格距离入手，随机点可以理解，然而，一般我们认识 Voronoi Texture 是在 2D 场景下的（如下图），但是 Blender 中存在 1D、3D，甚至是 4D（也是隐藏参数 `w` 的前提）。属实不太好理解。

![undefined](https://upload.wikimedia.org/wikipedia/commons/thumb/5/54/Euclidean_Voronoi_diagram.svg/1280px-Euclidean_Voronoi_diagram.svg.png)



**01.2 平滑度（Smoothness）**

进到 Blender 中的纹理介绍就晕迷糊了。其实，这个平滑度参数只有在选择了 `Smooth F1` 的特性时才奏效。



**01.3 特征**

`F1` 和 `到边缘的距离` 是距离参数的反值，一个是到中心的距离，另一个是到边缘的距离。但是F1存在颜色和位置参数，到边缘的距离则没有。



**02 Texture Coordinate（纹理坐标）**

在这个案例中，使用物体来绑定对应坐标，从而生成纹理。



**03  Noise Texture（噪波纹理）**

这里主要从类型切入。

- 多重分形（Standard multifractal）：

  > [噪波纹理分析（2）：分形函数](https://www.cnblogs.com/wangxydela/p/19046572)
  >
  > AI：在程序噪波里，多重分形通常是在基础分形噪声（如 Perlin、Simplex 噪波）上，叠加一个幅度随位置变化的粗糙度函数
  >
  > 多重分形是相乘的，fBM是相加的

- 脊状多重分形（Ridged multifractal）

  > [Procedural Terrain with ridged fractal noise](https://stackoverflow.com/questions/36796829/procedural-terrain-with-ridged-fractal-noise)
  >
  > 根据这篇文章的内容，脊状多重分形是取了 ABS，而ABS就是山脊高度。

- 分形布朗运动（fractal Brownian Motino，fBM）

  > [Fractal Brownian Motion](https://thebookofshaders.com/13/)：文章里面说 fBM 和多重分形是一样的过程？
  >
  > 目前推测，fBM值域在-1到1，而多重分形在0到1

- 混合多重分形（Hybrid multifractal）：结合相乘和相加的算法。

- 异向地行（Hetero Terrain）：类似混合多重分形，但是可以调整八度的权重和分量。

**03.1 [Perlin（柏林噪声）](https://zhuanlan.zhihu.com/p/206271895) [Wiki](https://zh.wikipedia.org/wiki/Perlin%E5%99%AA%E5%A3%B0)** 与多重分形（Standard multifractal）

柏林噪声是通过一个中间插值函数，通过某个确定的序列进行随机生成，这种生成因为中间插值函数而存在连续性，又因为序列是随机的所以具有随机性。一般将插值函数$$3t^2-2t^3$$和$$6t^5 -15t^4 + 10t^3$$的区别作为区分 Perlin 和 Simplex 噪波的区别。

柏林噪声的算法可以看 Wiki,比较详细

```python
from math import floor

#Perlin 最初提出的数组
SEQ = [
  151,160,137,91,90,15,
  131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
  190,6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
  88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,48,27,166,
  77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
  102,143,54,65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,196,
  135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,
  5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
  223,183,170,213,119,248,152,2,44,154,163,70,221,153,101,155,167,43,172,9,
  129,22,39,253,19,98,108,110,79,113,224,232,178,185,112,104,218,246,97,228,
  251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
  49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,127,4,150,254,
  138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180]

#插值函数
def _blending(t):
    return t*(t*(t*(10+t*(-15+6*t))))              #6t^5 -15t^4 + 10t^3

def noise(pos):
    if pos%1 == 0:                                 #对于整数点，直接从数列中取得数值即可。
        return SEQ[int(pos%256)]
    else:                                          #对于非整数的点，由左右的整数进行插值运算得出数值。
        x0,x1 = floor(pos)%256,floor(pos+1)%256    #取得非整数点旁的两个整数。
        c0,c1 = SEQ[x0],SEQ[x1]                    #从数列中取得两个整数点的数值。
        t = pos%256 - x0                           #计算非整数点离左边整数点的距离。
        return (c0*_blending(1-t)+c1*_blending(t)) #使用插值函数计算非整数点的数值并输出。
```

同时，分形噪声就是在基础的柏林噪声的基础上，通过将输入进行倍频叠加，从而模拟更复杂的噪声。如柏林噪声为 `noise(x)`，那么倍频就是 `noise(2x)` , 将多重噪声进行叠加和归一化就是多重分形。



**04 原理化 BSDF**

BSDF（**Bidirectional Scattering Distribution Function**），“双向散射分布函数”，是描述光线照射到物体表面后如何被反射和散射的数学模型。﻿

- 基础色：这个就是基础颜色
- 粗糙度：镜面反射和漫反射。镜面反射的高光会更清晰。漫反射就几乎看不清了。
- 金属度：塑料到金属过度，金属不反光，而塑料材料会反光。
- IOR（Index of refraction），镜面反射和透射的折射率：透明的情况下物体



**05 Bump（凹凸节点）**

- 强度乘数
- 距离乘数
- 高度纹理
- 法向纹理
