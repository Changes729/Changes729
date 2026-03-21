# Brouwer’s theorems

# 布劳威尔定理

## 关键词

- 布劳威尔不动点定理（Brouwer  fixed point theorems）：

  1. Let I be a line segment, including its endpoints (I for Interval) and suppose that  $f: I \to I$ is a continuous endomap. Then this map must have afixedpoint: a point x  in Ifor which f(x) = x.

     令 $I$ 为一条线段，包括其端点（$I$ 表示 Interval，间隔），并假设 $f: I \to I$ 是连续的自同态。那么这个映射必须有一个不动点：$I$ 中的一个点 x，其中 $f(x) = x$。

  2. Let D be a closed disk (the plane figure consisting of all the points inside  or on a circle), and fa continuous endomap of D. Then f has a fixed point.

     设D为闭圆盘（由圆内或圆上的所有点组成的平面图形），且D为连续内图fa，则f有不动点。

  3. Any continuous endomap of a solid ball has a fixed point.

     任何连续的实心球内同态都有一个固定点。

- 布劳威尔回缩定理（Brouwer retraction theorems）：给定一个没有固定点的连续自同态，我们可以构建连续回缩到其边界的结构。

  1. Consider the inclusion map j : E —> $I$ of the two-point set E as boundary  of the interval I. There is no continuous map which is a retraction for j.

     考虑两点集 E 的包含映射 j : E —> $I$ 作为区间 I 的边界。不存在连续映射是 j 的回缩。

  2. Consider the inclusion map j : C —> D of the circle C as boundary of the  disk D into the disk. There is no continuous map which is a retraction  for j.

     考虑圆 C 的包含图 j : C —> D 作为圆盘 D 进入圆盘的边界。不存在连续的映射，它是 j 的回缩。

  3. Consider the inclusion j : S —> B of the sphere S as boundary of the  ball B into the ball. There is no continuous map which is a retraction  for j.

     考虑球体 S 的包含 j : S —> B 作为球 B 进入球的边界。不存在连续的映射，它是 j 的回缩。



## 摘记

**01 布劳威尔定理**

> If there is no continuous retraction of the disk to its boundary then every continuous map from the disk to itself has a fixed point.
>
> 如果圆盘（D）没有连续回缩到其边界，则从圆盘到其自身的每个连续映射都有一个固定点。
>
> Given a continuous endomap of the disk with no fixed points, one can construct a  continuous retraction of the disk to its boundary.
>
> 给定一个没有固定点的连续自同态，我们可以构建连续回缩到其边界的结构。

这个定理还是不太懂。我觉得这里主要是关于这个 `continuous map（连续映射）`的不理解。

> Roughly, a map $f$ is  continuous if $f(p)$ doesn’t instantaneously jump from one position to a far away  position as we gradually move p. We met this concept in discussing Galileo’s idea of  a continuous motion of a particle, i.e. a continuous map from an interval of time into  space.
>
> 粗略地说，如果当我们逐渐移动 p 时 $f(p)$ 不会立即从一个位置跳到较远的位置，则映射 $f$ 是连续的。我们在讨论伽利略关于粒子连续运动的想法时遇到了这个概念，即从时间间隔到空间的连续映射。

虽然可以理解什么是连续映射。

所以还是应该把上面两条，看作是“公理”。

1. 如果连续自同态没有回缩到边界，那么连续自同态一定有个不动点。
2. 如果连续自同态没有不动点，那么就可以构建连续的回缩到边界。

> In other words, it is not possible to map the interval continuously to its two  endpoints and leave the endpoints in place. Isn’t this reasonable? Isn’t it pretty obvious that one cannot put one part of the interval on one of its endpoints and another part of it on the other without tearing it?
>
> 换句话说，不可能将间隔连续映射到其两个端点并将端点保留在适当的位置。这不合理吗？显然，我们不能将间隔的一部分放在其端点之一上，而将另一部分放在另一端点上而不撕裂它，这不是很明显吗？

理解了，因为边缘的映射对于**原映射不连续**。连续的只能是一个点。



**02 布劳威尔证明**

> We return to Brouwer’s theorems. To prove that the non-existence of a retraction implies that every continuous endomap has a fixed point, all we need to do is to  assume that there is a continuous endomap of the disk which does not have any fixed  point, and to build from it a continuous retraction for the inclusion of the circle into  the disk.
>
> So, let $j: C \to D$ be the inclusion map of the circle into the disk as its boundary,  and let’s assume that we have an endomap of the disk, $f: D \to D$, which does not have any fixed point. This means that for every point x in the disk $D, f(x) \neq x$.
>
> From this we are going to build a retraction for j, i.e. a map $r: D \to C$ such that  $r\circ j$ is the identity on the circle. The key to the construction is the assumed property of $f$, namely that for every point x in the disk, $f(x)$ is different from x. Draw an  arrow with its tail at $f(x)$ and its head at x. This arrow will ‘point to’ some point $r(x)$  on the boundary. When x was already a point on the boundary, $r(x)$ is x itself, so  that r is a retraction for j, i.e. $rj= 1_c$.

不理解。

好像是说，如果D是一个圆形边界，并且定义 D的一个映射是指向边界。那么最终会回缩到边界，因为边界的 $f(x) = x$

但是，如果没有边界，那么会回缩到不动点。



## 思路

**01 关于回缩的不动点和边界**

好像有点明白了。

就是说，如果回缩到一个点，那么必定有（因为定义），然后这个点叫不动点。

但是如果没有回缩到一个点，那么会**摊开**到一个边界上。

这个和之前不动点的定义也可以参考。



**02 布劳威尔证明**

只要从最后一部分去理解，还是可以理解的。

有一个点在于，所谓的「不动点」其实是一个动点，但是它不固定。

就好比，书中提到的例子，一方面说，会回缩到边界，但是这个边界的点是固定的。

另一方面说，如果可以把地图压缩成一团，然后丢到地上，那么一定会有一个点是对应的，这个点就是不动点，但是并没有说这个不动点在任意情况下都是相等的，只能说存在一个不动点。



然后证明过程中有两个公理。第一个公理中，有一个简易的描述，就是从 $\alpha: B \to A$ 的路径，之所以能成立，一方面是假设，就是逻辑上认为如果 $\alpha$  存在，那么后续的推论都是正确的——也就是说，存在一个回缩 $r: B\to S$。

此时，你会知道，回缩到的是一个具体的集合。

从概念上来说，$\alpha$ 之所以能存在，是因为我们假定了说不存在一个不动点使得 $f(x) = x$ 成立。所以，$A$ 和 $B$ 是不同的点，也就存在映射关系。



**03 后续**

虽然还没有完全理解透彻，但起码理论是已经接受了。

其理论总结出了逻辑学中的逆否关系。