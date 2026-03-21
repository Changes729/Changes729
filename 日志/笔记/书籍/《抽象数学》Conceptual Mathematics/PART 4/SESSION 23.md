# More on universal mapping properties

# 有关通用映射属性的更多信息

## 关键词

- 初始对象
- 积的定义





## 摘记

**01 映射对的类别（A category of pairs of maps）**

> It might occur to you that to study pairs of maps into two given objects Bx and B2 in  we could invent a new category, which we will call (?b.b2- An object of this category is an object of $e$ equipped with a pair of maps to B1 and B2 respectively, i.e. a diagram of the type
>
> 您可能会想到，要研究两个给定对象 Bx 和 B2 的映射对，我们可以发明一个新类别，我们将其称为 $e_{B_1B_2}$ 该类别的对象是 $e$ 的对象，分别配备有一对到 $B_1$ 和 $B_2$ 的映射，即类型的图
> $$
> \xymatrix @ur{
> X \ar[r]^{\phi_1} \ar[d]_{\phi_2} & B_1 \\ B_2
> }
> $$
> in e, while a map between two objects in this category, for example a map
>
> 在 e 中，而此类别中两个对象之间的映射，例如映射：
> $$
> from \xymatrix @ur{
> X \ar[r]^{\phi_1} \ar[d]_{\phi_2} & B_1 \\ B_2
> } to 
> \xymatrix @ur{
> Y \ar[r]^{\psi_1} \ar[d]_{\psi_2} & B_1 \\ B_2
> }
> $$
> is simply a map X —Y in *2 which ‘preserves the structure,’ meaning that it satisfies the two obvious equations saying that this diagram commutes:
>
> 只是 e 中的映射 $f: X \to Y$，它“保留了结构”，这意味着它满足两个明显的方程，说明该图是可通的：
> $$
> \xymatrix @ur{
> X \ar@/^/[rdr]^{\phi_1} \ar@/_/[ddr]_{\phi_2} \ar[dr]^f \\ & Y \ar[r]^{\psi_1} \ar[d]_{\psi_2} & B_1 \\ & B_2
> }
> \\
> \psi_1f = \phi_1; \psi_2f = \phi_2;
> $$
> Our main question about this category gBlB, is: What is its terminal object? The answer must depend only on B\ and B2 since these are the only ingredients used to  construct this category. By the definition of terminal object we must find an object
>
> 我们关于这个类别 gBlB 的主要问题是：它的终端对象是什么？答案必须仅取决于 B\ 和 B2，因为它们是用于构建此类别的唯一成分。根据终端对象的定义，我们必须找到一个对象
>
> 这个对象就是 $B_1$ 和 $B_2$ 的乘积。
>
> Why do we bother to invent a category in which a terminal object is the same as a product of Bi and B2 in This construction, ‘reducing’ products in one category to  terminal objects in another, in particular makes the uniqueness theorem for products  a consequence of the corresponding theorem for terminal objects. Of course, it would  seem to need a lot of effort to define the category &bxb2 if our only purpose were to deduce that any two products of B\ and B2 are uniquely isomorphic from the  uniqueness theorem for terminal objects. By the time we prove that &bxb1 is actually a category we could have finished the direct proof of uniqueness of the product.  However, after gaining some experience it becomes obvious that anything con¬  structed as &B\B2 was, is automatically a category; and there are many instances in which it is very helpful to think of a product of two objects as a terminal object in the  appropriate category. The fact that this is always possible helps us to understand better the concept of product.
>
> 为什么我们要费心发明一个范畴，其中终端对象与 Bi 和 B2 的乘积相同。这种构造，将一个范畴中的乘积“还原”为另一个范畴中的终端对象，特别是使乘积的唯一性定理成为终端对象相应定理的结果。当然，如果我们的唯一目的是根据终端对象的唯一性定理推导出 B\ 和 B2 的任意两个乘积唯一同构，那么定义类别 $e_{B_1B_2}$ 似乎需要花费大量精力。当我们证明 $e_{B_1B_2}$ 实际上是一个类别时，我们就可以完成积的独特性的直接证明。  然而，在获得一些经验之后，很明显，任何被构造为 $e_{B_1B_2}$ 的东西，都会自动成为一个范畴；在很多情况下，将两个对象的乘积视为适当范畴中的终端对象是非常有帮助的。事实上，这总是可能的，有助于我们更好地理解产品的概念。

需要注意，这里的 $f$ 是函子。是两个范畴成立的函子。



**02 How to calculate products**

> $$
> \xymatrix{
> D \ar[d]_s \ar[dr]^x \\
> A \ar[r]^p & X
> }
> $$
>
> the source os $p$ is $x$, or $ps = x$
> $$
> \frac{D \to A^2}{D \to A, D \to A}
> $$
> This tells us that the dots of A are the pairs of dots of A. Since A has two dots, there are four pairs and therefore A2 has four dots. The arrows of A2 are
>
> 这告诉我们，A 的点是 A 的点对。由于 A 有两个点，所以有四对，因此 A2 有四个点。 A2的箭头是
> $$
> \frac{A \to A^2}{A \to A, A \to A}
> $$
> the pairs of arrows of A. But A has only one arrow, thus we can form only one pair  and therefore A2 has only one arrow. At this point A2 has been determined to be
>
> A 的箭头对。但是 A 只有一个箭头，因此我们只能形成一对，因此 A2 只有一个箭头。此时A2已确定为（一个箭头）
>
> $A^2 = A + 2D$




## 思路

