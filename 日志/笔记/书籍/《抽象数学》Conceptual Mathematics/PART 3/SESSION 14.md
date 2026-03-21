#  Maps preserve positive properties

# 映射保留正向属性

## 关键词

- 不动点（fixed point）
  $$
  \xymatrix{
  \bullet \ar@/^/[r] & \bullet \ar@/^/[l]
  }
  $$
  这个内图（endomap）映射就没有不动点，
  $$
  \xymatrix{
  \bullet \ar[r] & \bullet \ar[r] & \bullet \ar@(ur,dr)[]
  }
  $$
  
  这个内图映射就有不动点。
  
- 正向属性与负面属性（Positive properties versus negative properties）



## 摘记

**01 正面属性与负面属性**

正面属性可以被获取（accessibility），负面属性不会被保留，但他们会被反映：

> $$
> \xymatrix{
> \bullet^y \ar[r] & \bullet^x \ar[r] & \bullet^z \ar@(ur,dr)[]
> }
> $$
>
> the elements x and z have this property, but y doesn’t because no element goes to y.  (This is a positive property. We’ll come back to these later.)
>
> 元素 x 和 z 具有此属性，但 y 没有，因为没有元素转到 y。 （这是一个积极的特性。我们稍后会再讨论这些。）
>
> An example of a negative property of x is not being a fixed point, i.e.  $a(x) \neq x$.
>
> x 的负属性的一个例子是不是一个固定点，即 $a(x) \neq x$。
>
> Negative properties tend not to be preserved, but instead they tend to be  reflected.
>
> 负面特性往往不会被保留，而是会被反映。



**01.2 负面特性往往不会被保留**

> Yes. Take, for example, X — Z, and a = adding 2 (i.e. a{n) = 2 + n) and / = parity  (i.e. /(n) = even or odd, depending on what n is). Then we can take for Y the set {even, odd} and for (1 the identity map.
>
> 是的。以 X — Z 为例，a = 加 2（即 a{n）= 2 + n），/ = 奇偶校验（即 /(n) = 偶数或奇数，取决于 n 是什么）。然后我们可以为 Y 取集合 {even, odd}，为 (1 取恒等映射。
> $$
> \xymatrix{
> \Z^{\circlearrowright 2+()}  \ar[rr]^{f=parity} & & \{ even, odd \}^{\circlearrowright id}
> }
> $$
>

这里可以看到，整数范畴不存在固定点，但是奇偶范畴却存在了固定点。



## 思路

