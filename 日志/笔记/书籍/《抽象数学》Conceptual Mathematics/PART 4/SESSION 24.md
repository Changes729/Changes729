# Uniqueness ofproducts and definition of sum

# 积的唯一性和总和的定义

## 关键词

- 和（sum）；余积（codomain）

  - sum injections：
    $$
    f(x)=\{
    \begin{aligned}
    f_1 \\
    f_2
    \end{aligned}
    $$
    



## 摘记

**01 回顾积（product）的定义**

> We will recall now how a product in a category can be considered as giving rise to  a way of combining two maps into one. Given two objects $B_1$ and $B_2$  in a category $e$ pair of product projections for $B_1$ and $B_2$ is a pair of maps
>
> 我们现在回想一下，一个范畴中的积如何被视为产生了一种将两个映射组合成一个的方式。给定范畴中的两个对象 $B_1$ 和 $B_2$，$B_1$ 和 $B_2$ 的一对乘积是一对映射
> $$
> \xymatrix @ur{
> P \ar[r]^{p_1} \ar[d]_{p_2} & 
> B_1 \\
> B_2
> }
> $$
> satisfying the following universal mapping property: For any two maps
>
> 满足以下通用映射属性：对于任意两个映射
> $$
> \xymatrix @ur{
> X \ar[r]^{f_1} \ar[d]_{f_2} & 
> B_1 \\
> B_2
> }
> $$
> among all the maps $X \to P$ there is exactly one $f: X\to P$ that satisfies both equations
>
> 在所有映射 $X \to P$ 中，恰好有一个$f: X\to P$ 满足两个方程
> $$
> f_1 = p_1f ; f_2 = p_2f
> $$
> As we said in the last session, that unique map $f$ is denoted $\langle f_1, f_2 \rangle$ . This means that a  product P of $B_1$ and $B_2$ permits us to combine two maps into one map.
>
> 正如我们在上一阶段中所说，唯一的映射 $f$ 表示为 $\langle f_1, f_2 \rangle$。这意味着 $B_1$和 $B_2$ 的乘积 P 允许我们组合两个映射变成一个映射
> $$
> \xymatrix {
> X \ar[r]^{\langle f_1, f_2 \rangle} & P
> }
> $$
> The definition of ‘product’ is that this process of combining is inverse to the  process of composing a map X —-> P with the projections. If we are given a map  X P and compose it with the projections p\ and p2, we get two maps p\g)  and g2(— Pig) which are ‘the components of g’ (relative to the product at hand). Indeed, if we now combine g, and g2, the result must necessarily be the original map  g
>
> “积”的定义是，这种组合过程与用投影组成映射 $X \to P$ 的过程相反。如果给定一个映射 $g: X \to P$ 并将其与投影 $p_1$ 和 $p_2$ 组合，我们会得到两个映射 $g_1(=p_1g)$ 和 $g_2(=p_2g)$，它们是 “g 的分量”（相对于已有的乘积）。事实上，如果我们现在将 $g_1$ 和 $g_2$ 组合起来，结果必然是原始映射 g
>
> Summing up: To say that two maps p\, p2 are product projections boils down to saying that this simple process of ‘decomposing’ a map (by composing it with each of  p^ and p2) is invertible. In fact many universal mapping properties just state that a  certain simple process is invertible.
>
> 总结：说两个映射 $p_1, p_2$ 是乘积投影，可以归结为说 “分解” 映射（通过将其与 $p_1$ 和 $p_2$ 中的每个进行组合）的这个简单过程是可逆的。事实上，许多通用映射属性只是表明某个简单过程是可逆的。

这里需要回看上一章节。特别是需要明确对 $\langle f_1, f_2 \rangle$ 的理解。



## 思路

**01 问题**

有个问题是，为什么，我们假定 P 是 B1 B2 的积的时候，就一定存在任意 X 对 P 的映射成立呢？
