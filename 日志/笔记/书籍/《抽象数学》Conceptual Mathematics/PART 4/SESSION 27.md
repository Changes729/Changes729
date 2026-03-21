# Examples of universal constructions

# 通用结构的例子

## 关键词

- 极限（limits）：

  - 终端对象（1）：$1\times A = A$

  - 对象的积

  - 等化字（equalizer）：$p: E\to X$ is an **equalizer** of $f, g$ if $fp = gp$ and for each $x: T\to X$ for which $fx = gx$, there is exactly one $e: T\to E$ for which $x = pe$.

    $p: E\to X$ 是 g 的均衡器当$fp = gp$ 并且对于 $x: T\to X$ 的每个 $fx = gx$，恰好有一个 $e: T\to E$ 使 $x = pe$ 成立。
    $$
    \xymatrix @ur{
    & E \ar[d]^p \\
    T \ar[ur]^e \ar[r]^x & X \ar@<2pt>[dr]^f \ar@<-2pt>[dr]_g \\
    && Y
    }
    $$
    

- 余极限（colimits）：

  - 初始对象（0）：$0 + A = A$
  - 对象的和



## 摘记

**01 关于积**

> These equations look simple because they are familiar from numbers, but here  they have more meaning. The product of two numbers is just a number, but the  product of two objects R and Q is another object P and two ‘projection’ maps  P—>R and P—>Q. Thus when we said A is a product of A and 1, we had to specify the projection maps
>
> 这些方程看起来很简单，因为它们与数字很相似，但在这里它们有更多的意义。两个数字的乘积只是一个数字，但两个对象 R 和 Q 的乘积是另一个对象 P 和两个“投影”映射 P—>R 和 P—>Q。因此，当我们说 A 是 A 和 1 的乘积时，我们必须指定投影图
> $$
> \xymatrix @ur {
> A \ar[r]^{p_1} \ar[d]_{p_2} & A \\
> 1
> }
> $$
> 



**02 关于和**

> There is another way of seeing the same thing, but treating simultaneously the  objects A and B. To say that 0 is a coproduct of A and B means that for any object X, the pairs of maps A —U X * — B are the same as the maps 0 —► X. There is only  one^map from 0 to X (since 0 is initial), therefore there is only one pair of maps  A —-> X <x- B. Thus there is only one map A —* X, and only one map B —>X. This  means that both A and B are initial objects. Now we have a complete answer to our  question: an initial object has a negative, but only initial objects have negatives.
>
> 还有另一种看待同一事物的方法，但同时处理对象 A 和 B。说 0 是 A 和 B 的余积，意味着对于任何对象 X，映射对 A —U X * — B 与映射 0 —► X 相同。从 0 到 X 只有一个^映射（因为 0 是初始值），因此只有一对映射 A —-> X <x- B。因此只有一个映射 A —* X，也只有一个映射 B —>X。这意味着 A 和 B 都是初始对象。现在我们的问题有了完整的答案：初始对象有负数，但只有初始对象才有负数。



## 思路

**01 遗忘函子**

这里首次介绍了两个对象的积，会比其中一个对象还要少。



02 

看不懂，渐渐的都看不懂了。