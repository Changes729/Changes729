# The algebra of composition

# 组合代数

## 关键词

- 同构（Isomorphisms）  ：一个从 $f: A\to B$ 被称作同构，或者可逆映射（invertible map），那么，就存在一个映射 $g: B\to A$ ，对 $g \circ f = 1_A; f \circ g = 1_B$。如果至少有一个同构，则称两个对象是同构的。
  - 拟映射（inverse map）：此时 $g$ 被称为 $f$ 的拟映射（唯一），记作 $f^{-1}$
  - 自反性（Reflexive）：A 和 A 本身同构
  - 对称性（Symmetric）：如果 A 和B同构，那么 B与A同构。
  - 传递性（Transitive）：如果 A和B同构，B和C同构，那么A与C同构。
  
  如果一个映射的逆映射，同时构成回缩和截面，那么我们说，映射是同构的。
  
- 回缩（Retractions）：一个映射 $f: A \to B$，令 另一个映射$r: B \to A, r \circ f = 1_A$ 成立。

  这同时也是一个判定问题（determination）

- 截面（sections）：一个映射$f: A \to B$，令 另一个映射$r: B \to A, f \circ r = 1_B$ 成立。

  这同时也是一个提升问题（lifting）

- 消去律（cancellation law）

  - 满射（surjective，epimorphism）：对于任意 $y$，存在一个 $x$ 使 $fx = y$ 成立，则称 $f$ 是一个满射。

    对于任意 $t_1: B \to T, t_2: B\to T$，使 $t_1 \circ f = t_2 \circ f; t_1 = t_2$  成立

  - 单射（injective，monomorphism）：对于任意一对映射 $x_1: T\to A; x_2: T\to A$，都存在 $f \circ x_1 = f\circ x_2; x_1 = x_2$，则称 $f$ 是一个单射。

- 幂等（idempotents）

- 自同构（automorphisms）：自己与自己同构。是具有数量的。

  集合范畴中的自同构传统上也称为排列（permutation）。



## 摘记

**01 除法问题**

> 1. The ‘determination’ (or ‘extension’) problem Given f and h as shown, what are all g, if any, for which $h = g \circ f$
> 2. The ‘choice’ (or ‘lifting’) problem Given g and h as shown, what are all /, if any, for which $h = g \circ f$

1. 判定问题（determination）

   如果 $h$ 有任意解 $g$，我们说 $h$ 由 $f$ 决定，或 $h$ 仅取决于 $f$。

2. 选择（提升）问题（choice，lifting）



**02 同构的价值**

> What is the relation of A to B if there is an isomorphism between them? In the  category of finite sets this just says that A and B have the same number of elements. But this enables us to give a usable definition of ‘same number’ without depending on  counting - a definition which is very significant even for infinite sets. That is, we say  that A and B have the same number of elements if they are isomorphic in the  category of sets, where (in any category) A and B are isomorphic means that there  exists an isomorphism from A to B in the category. Categories other than sets usually  involve objects that are more richly structured, and, correspondingly, isomorphic  objects will be alike in much more than just ‘number of elements’ - they will have the  ‘same shape’, ‘same structure’, or whatever the category itself involves.
>
> 如果 A 和 B 之间存在同构，那么它们之间有什么关系？在有限集范畴中，这只是说 **A 和 B 具有相同数量的元素**。但这使我们能够在不依赖计数的情况下给出“相同数字”的可用定义——**即使对于无限集，这个定义也非常重要**。也就是说，如果 A 和 B 在集合范畴中同构，我们就说它们具有相同数量的元素，其中（在任何范畴中）A 和 B 同构意味着该范畴中存在从 A 到 B 的同构。**除集合之外的类别通常涉及结构更丰富的对象，相应地，同构对象的相似之处不仅仅是“元素数量”——它们将具有“相同的形状”、“相同的结构”或类别本身涉及的任何内容。**



**03 同构与自同构**

> In general, if there are any isomorphisms A —>B, then there are the same number  of them as there are automorphisms of A. This fact we can prove without counting  by remembering the definition of‘same number’ given above. If we let Aut(A) stand  for the set of all automorphisms of A and Isom(A,B) stand for the set of all isomorphisms from A to B, the definition says that we need only construct an iso¬  morphism between those two sets. Now Aut(A) is always non-empty since at least  1A is an example of an isomorphism A —>A. If there is an isomorphism A -> B, choose such an f and use it to construct
>
> 一般来说，如果存在任何同构 A —>B，那么它们的数量与 A 的自同构的数量相同。我们可以通过记住上面给出的“相同数量”的定义来证明这一事实，而无需计数。如果我们让 Aut(A) 代表 A 的所有自同构的集合，Isom(A,B) 代表从 A 到 B 的所有同构的集合，则定义表明我们只需要在这两个集合之间构造一个同构。现在 Aut(A) 总是非空的，因为至少 1A 是同构 A —>A 的一个例子。如果存在同构 A -> B，则选择这样的 f 并用它来构造

> $F: Aut(A) \to Isom(A, B)$
>
> 定义 $F(\alpha) = f \circ \alpha$ 对于任意集合A中的自同构 $\alpha$ 。

> An automorphism in the category of sets is also traditionally called a permutation,  suggesting that it shifts the elements of its set around in a specified way. Such a  specified way of shifting is one of the simple, but interesting kinds of structure, so we  can use this idea to describe our second example of a category, the category of  permutations. An object of this category is a set A together with a given automorphism a of A. A map  
>
> from A^a to  
>
> is a map of sets A + B, which ‘respects’ or ‘preserves’ the given automorphisms a  and P in the sense that 
>
>  f ° a = b °f

这一节很精彩。它引出了一些很基础的概念，但我现在还不知道他叫什么。



## 思路

**01 判定问题**

判定问题书中用了两个个很妙的例子。



**02 命名思路**

1. 为什么叫 “截面（sections）”和“收缩（Retractions）”，因为其起源于拓扑学。

   > *Section（截面/剖面）* 这个词源于对某个物体进行“切片”或取“横截面”的想法。
   >
   > 在拓扑学中，想象你有一个“全空间” $E$ 位于一个“基空间” $B$ 之上（例如一个圆柱体位于一个圆圈之上）。投影映射 $p: E \to B$ 将圆柱体压扁到圆圈上。
   >
   > **截面** $s: B \to E$ 则是一种反向操作。它将基空间“抬升”回全空间。之所以叫“截面”，是因为它为 $B$ 中的每个点在 $E$ 中精确地挑选了一个点，就像是在形状中“切出了一个剖面”一样。
   >
   > - **数学定义：** 如果 $p \circ s = 1_B$，则 $s$ 是 $p$ 的一个截面。
   > - **逻辑本质：** 它是一个**右逆（Right Inverse）**。
   >
   > *Retraction（回缩/收买）*这个词源于将一个较大的空间“缩回”或“折叠”到一个较小的子空间的想法。
   >
   > 想象你有一个橡胶圆盘（$X$）及其中心点（$A$）。你可以通过让圆盘上的每个点沿着直线向中心滑动，将整个圆盘“回缩”到那个中心点。在这个过程中，中心点本身是不动的。
   >
   > 在范畴论中，如果你有一个包含映射（将小物体放入大物体的方法）$i: A \to X$，那么**回缩** $r: X \to A$ 就是一种将大物体映射回小物体的方法，且保证原本就在 $A$ 中的元素位置保持不变。
   >
   > - **数学定义：** 如果 $r \circ i = 1_A$，则 $r$ 是 $i$ 的一个回缩。
   > - **逻辑本质：** 它是一个**左逆（Left Inverse）**。