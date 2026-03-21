# Categories of structured sets

# 结构集的范畴

## 关键词

- 自同构范畴：$S^{\circlearrowright}$
  $$
  \xymatrix{
  m \ar[dr]_{shadow} \ar[rr]^{sharper image} &  & S^t \ar[dl] \\
   								   & C
  }
  $$
  两个子范畴：

  - $S^e$：范畴内的对象全部都是幂等（idempotent）的
  - [打不出来的标记]：所有元素都是可交换的（invertible）；可以说是集合的自同构，或者排列（permutations）

- 子集关系：

  $e \sub e^\theta \sub e^{invert} \sub e^{\circlearrowright}$

  $e \sub e^e \sub e^{\circlearrowright}$

  意思是：

  恒等态射/单位元（endomaps） $\sub$ 对合映射/自反映射（Involution）$\sub$ 同构自映射/自同构（Isomorphic Endomaps/Automorphism）$\sub$ 自映射（Endomap）

  恒等态射/单位元（endomaps） $\sub$ 幂等映射（Identity）$\sub$ 自映射（Endomap）

- 对合映射（Involution）：$\theta \circ \theta = 1_A$，是自同构，有逆元。

  唯一的幂等自同构是恒等映射

- 非自反图（Irreflexive graphs）：$S^{\darr\darr}$，次类别的任意对象，都有一对平行映射。

  $s: X\to P; t: X \to P$，其中，$X$ 称为箭头集，$P$ 称为图形的点集。如果 $x$ 是一个箭头，那么 $s(x)$ 就是箭头的源头，$t(x)$ 就是箭头的目标。

$$
\xymatrix{
&&& S^e
\\
\txt{Reflexive\\ graphs} \ar[r]_U 
	& S^{\underset{\cdot}{\dot{\downdownarrows}}} \ar[d] _{\supset}
	& S^{\circlearrowright} \ar@{_{(}->}[l] \ar[ur]_{\supset} \ar[r]_{\supset}  \ar[dl]_J \ar[d]_V
	& S^{\circlearrowright\circlearrowleft} 
\\	& S^{\underset{\cdot}{\dot{\downarrow}}} 
	& S
}
$$





## 摘记

> We use maps to express extra ‘structure’ on sets, leading to  graphs, dynamical systems, and other examples of ‘types of  structure.’ We then investigate ‘structure-preserving’ maps.
>
> 我们使用映射来表达集合上的额外“结构”，从而产生图形、动力系统和其他“结构类型”的示例。然后我们研究“结构保持”映射。



**01 从离散到连续**

> It is critical that the category which we were discussing is not the category of abstract sets and arbitrary functions; it must rather be some  category of ‘cohesive’ objects and ‘continuous’ maps



**02 要讨论的范畴**

> where m denotes an imprecise but real category, T denotes a specific chosen notion of structure, and ST denotes the category of structures of kind T which can be built  in S; the arrows denote the appropriate kind of maps between categories, known as functors, which we will discuss later.
>
> 其中m表示不精确但真实的类别，T表示特定选择的结构概念，ST表示可以在S中构建的T类结构的类别；箭头表示类别之间适当的映射类型，称为函子，我们将在稍后讨论。

这是一个很重要的概念。PDF 中有很好的图片说明。

$更清晰的图像（sharper image）: m \to S^T$

$投射（shadow）: m \to S$

其中，$m$ 表示原像，在书中表示为，模糊但是具体的类别。

$S$ 表示一个抽象的一切范畴，

而 $T$ 是一个拟定的结构（或者说已知的，预设的类别）。

$S^T$ 表示可以在 $S$ 中构建 $T$ 的类别。然后箭头是 函子（functor）。这里还是引出了许多新概念的。



> Now we return to the category in which an object is an endomap of a set. A  suggestive notation for it is S object of S is any set X equipped with an  endomap a. But the most important thing about a category is its maps and how they  compose - what are the maps of S They are maps which ‘respect the given structure,’ i.e. a map
>
> 现在我们回到一个对象是集合的内图的范畴。一个暗示性的符号是 A 的一个对象是任何配备有内图 a 的集合 X。但关于一个类别最重要的是它的映射以及它们如何组成 - S 的映射是什么 它们是“尊重给定结构”的映射，即映射
>
> $f: X^{\circlearrowright{\alpha}} \to Y^{\circlearrowright{\beta}}$
>
> $f\circ \alpha = \beta \circ f$

文章在这里指出了对象内部的结构，其实是对象内部的态射，也就是说我们过去把集合（Set）看作一个个孤立的点，但其实，集合本身是有结构的，正是因为它存在结构，所以我们说它们是同构的，因为元素的关系以及内涵在集合内了。

这也说明了，我们为什么可以形成两个集合之间的同构关系。

> Objects of $S^{\circlearrowright}$ arise frequently as dynamical systems or automata.

简单来说，这个符号经常被用在系统状态图（自动化领域）

这一章节很有价值，因为它让我们联想到了状态图，以及某个对象的内部关系，并且还可以通过对象内部关系的变化，通过自映射，形成某种动态的关系，文章中提到了两个点：

> Given a state x, is it possible to get into that state, i.e. does there exist a state x' for which a(x') = x?
>
> 给定一个状态 x，是否有可能进入该状态，即是否存在一个状态 x'，其中 a(x') = x？

> Given a state x, is it possible by activating a enough times (or waiting long enough, in the natural system view) to arrive at a state which no longer changes, i.e. for some n, a"+1(x) = aH(x)？
>
> 给定一个状态x，是否有可能通过激活足够的时间（或在自然系统视图中等待足够长的时间）到达不再改变的状态，即对于某些n，$a^{n+1}(x)= a^n(x)$？

可以看到，前者是系统稳态图，后者是极限、收敛问题。



## 思路

**01 Endomaps as special graphs**

这一章节好绝。这个部分很绝。

从点集跳转到了一个更高范畴，非自反集。映射自己就可以表示自己。



在第九部分有一张全景图。很重要。也涉及到了遗忘函子。
