# Ascending to categories of richer structures

# 提升到更丰富结构的类别

## 关键词

- 自同态范畴集 $S^{\circlearrowright \alpha} \sub X^{\circlearrowright \alpha}$ ：
  $$
  \xymatrix{
  \bullet \ar@(ul,dl)[] & \bullet \ar[l] & \bullet \ar[l] \\
  					  & \bullet \ar[u]					\\
  \bullet \ar[dr] 	  & \bullet \ar[l] & \bullet \ar[l] \\
  					  & \bullet \ar[u] & \bullet \ar[l]
  }
  $$

- 恒等映射范畴集 $S^e$ ：如果 $X^{\circlearrowright \alpha}$ 是恒等映射范畴集的一个对象，那么必须满足 $\alpha \circ \alpha = \alpha$

- 可逆范畴集 $S^{invert}$：如果 $X^{\circlearrowright \alpha}$ 是恒等映射范畴集的一个对象，那么必须满足 $\alpha$ 可逆，且$\alpha \circ \beta = \beta \circ \alpha = 1_X$

- 图（graphs）：$S^{\underset{\cdot}{\dot{\downdownarrows}}} $
  $$
  \xymatrix{
  X \ar@<1ex>[d]^t \ar@<-1ex>[d]_s \\
  Y 
  }
  $$
  



## 摘记

**01 A category of richer structures: Endomaps of sets**

>$X^{\circlearrowright \alpha}$ 
>$$
>\xymatrix{
>\bullet \ar@(ul,dl)[] & \bullet \ar[l] & \bullet \ar[l] \\
>					  & \bullet \ar[u]					\\
>\bullet \ar[dr] 	  & \bullet \ar[l] & \bullet \ar[l] \\
>					  & \bullet \ar[u] & \bullet \ar[l]
>}
>$$
>

$X^{\circlearrowright \alpha}$ ：这是一个范畴。并且是具有自同态（endomap）的范畴。其中的自同态映射为 $\alpha$。

定义：如果说 $f: X^{\circlearrowright \alpha} \to Y^{\circlearrowright \beta}$ 属于 $S^{\circlearrowright }$ ，就意味着 $f: X \to Y$ 属于 $S$，并且 $f \circ \alpha = \beta \circ f$

书中给到的例子：

> $$
> \xymatrix{
> \circ \ar@(ul,dl)[] \ar @/^1pc/[r] &
> \bullet \ar@(ul,dl)[] & \bullet \ar[l] & \bullet \ar[l] \\
> 					  & \bullet \ar[u]
> }
> $$

两个不同的点表示在不同的（子）范畴内。



**02 恒等映射范畴集**

> $$
> \xymatrix{
> \bullet \ar[dr] & \bullet \ar[d] & \bullet \ar[dl]& \bullet \ar@(dl,dr)[] \\
> 				& \bullet \ar@(dl,dr)[]
> }
> $$
>
> 
>
> Every point is either a fixed point or reaches a fixed point in one step. (In particular there are no cycles of length two or more.) An isomorphism in Se means ‘correspondence between fixed points and correspondence between branches at corresponding fixed points.’
>
> 每个点要么是一个固定点，要么一步到达一个固定点。 （特别是不存在长度为 2 或更多的循环。）Se 中的同构意味着“固定点之间的对应性以及对应固定点处的分支之间的对应性”。



**03 可逆映射范畴集**

> $$
> \xymatrix{
> \bullet \ar[dr] & \bullet \ar[l] & \bullet \ar[l]& \bullet \ar@(dl,dr)[] \\
> 				& \bullet \ar[ru]
> }
> $$
>
> Recall that an invertible endomap, i.e. an endomap which is also an isomorphism, is called an automorphism. An automorphism of a finite set is also known as a permutation of the set.
>
> 回想一下，可逆内图，即内图也是同构，称为自同构。有限集合的自同构也称为集合的排列。



**04 非自反有向多重图（irreflexive directed multigraphs）**

> $$
> \xymatrix{
> \bullet	& \bullet \ar[d] & \bullet \ar@(dl,dr)[]_z & \bullet \ar[d] \\
> 		& \bullet        & 		   				 & \bullet \ar@/^/[r] & \bullet \ar@/^/[l]
> }
> $$
>
> where the dots are the elements of Y and the arrows are the elements of X. If X has  an element z such that sz = tz then we draw z as a loop. For any object in we can draw such a picture and each picture of this kind represents a pair of maps with the  same domain and same codomain.
>
> 其中点是 Y 的元素，箭头是 X 的元素。如果 X 具有元素 z 且 sz = tz，则我们将 z 绘制为循环。对于 中的任何对象，我们都可以绘制这样的图，并且这种图的每张图都代表一对具有相同域和相同辅域的映射。



**04.1 图的映射**

> 定义，一个映射在图范畴 $S^{\underset{\cdot}{\dot{\downdownarrows}}}$ 中，从
> $$
> from \xymatrix{
> X \ar@<1ex>[d]^t \ar@<-1ex>[d]_s \\
> Y 
> } to \xymatrix{
> X' \ar@<1ex>[d]^{t'} \ar@<-1ex>[d]_{s'} \\
> Y' 
> }
> $$
> 存在映射：$f_A: X \to X'; f_D: Y \to Y'$ 使交换图成立
> $$
> \xymatrix{
> X \ar[r]^{f_A} \ar@<1ex>[d]^t \ar@<-1ex>[d]_s	& X' \ar@<1ex>[d]^{t'} \ar@<-1ex>[d]_{s'} \\
> Y \ar[r]^{f_D}	& Y'
> }
> $$
> Two graphs are isomorphic if we can exactly match arrows of one to arrows of the  other and dots of one to dots of the other, taking care that if two arrows are matched  then so are their source-dots and so are their target-dots. The exercises below illus¬  trate this. This category has many applications, e.g. in electrical engineering, trans¬  port problems, and even in linguistics, since graphs appear in all these subjects, be it  as electric circuits, road systems between towns, or as nouns and verbs relating the  nouns.
>
> 如果我们可以将一个图的箭头与另一个图的箭头以及一个图的点与另一个图的点精确匹配，则两个图是同构的，注意如果两个箭头匹配，那么它们的源点也匹配，它们的目标点也匹配。下面的练习说明了这一点。这个类别有很多应用，例如在电气工程、交通问题、甚至语言学中，因为图表出现在所有这些学科中，无论是电路、城镇之间的道路系统，还是与名词相关的名词和动词。



## 思路

**01 范畴、子集、元素**

第一个问题就是关于范畴、子集和元素的。

在最开始讲映射到时候，我们会把元素归在某个子集之中。然后那个时候还谈到了映射的数量。

但是这里，就会谈到范畴，和子集之间的映射。



可以理解，这里的视角其实是将子集看作一个元素。

而不同的点在于，之前我们是分立的看待元素和映射，但是这里，我们开始将映射也看作子集的一部分。



然后在这些概念的基础上，最终给出了所谓的范畴类型。

—— 某些范畴是存在特征的，是包含关系，转化关系在的。

但是具体的关系是什么，目前还不清楚，现在只是在介绍各种范畴类型。
