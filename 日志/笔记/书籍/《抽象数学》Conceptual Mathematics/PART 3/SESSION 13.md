# Monoids

# 幺半群

## 关键词

- 幺半群（monoid）：A category with exactly one object is called a monoid.

  仅有一个对象的范畴称为幺半群。

- 函子（functor）：Such a ‘structure-preserving’ interpretation of one  category into another is called a functor (from the first category to the second).

  这种将一个类别解释为另一个类别的“结构保留”解释称为函子（从第一个类别到第二个类别）。

- dynamical systems



## 摘记

**01 对于范畴的界定**

> In general, in order to specify a category completely I must specify what are the  objects, what are the maps, which object is the domain of each map, which object is  the codomain of each map, which map is the identity of each object, and which map is  the composite of any two ‘composable’ maps - six things to be specified. Of course, this cannot be done in any arbitrary way. Recall these laws that must be satisfied:
>
> 一般来说，为了完全指定一个类别，我必须指定什么是对象，什么是映射，哪个对象是每个映射的域，哪个对象是每个映射的共域，哪个映射是每个对象的标识，以及哪个映射是任意两个“可组合”映射的组合 - 需要指定六个内容。当然，这不能以任意方式完成。回想一下必须满足的这些法律：



**02 幺半群和乘法范畴**

> Here is a special case. Suppose we have only one object, which we call V. This  means that all the maps in the category are endomaps (of this unique object).
>
> 这是一个特殊情况。假设我们只有一个对象，我们将其称为 *。这意味着该类别中的所有映射都是（该唯一对象的）内映射。
> $$
> \xymatrix{
> * \ar[r]^0 & *
> },
> \xymatrix{
> * \ar[r]^1 & *
> },
> \xymatrix{
> * \ar[r]^2 & *
> },
> \xymatrix{
> * \ar[r]^3 & *
> }, etc.
> $$
> Let’s call the category we defined above $m$ for multiplication. An interpretation will be denoted this way:
>
> 我们将上面定义的乘法范畴称为 $m$。解释将这样表示：
> $$
> m \to S
> $$
> 一种解释是，将对象 * 看作自然数 $\N$，那么就有
> $$
> \xymatrix{
> \N \ar[r]^{f_n} & \N 
> } 
> $$
>
> $$
> f_n(x) = n \times x
> $$
>
> 



**03 逆元**

> Such a functor also sheds light on the sense in which we can use the symbol of  raising to minus one as a vast generalization of ‘inverse.’ If we change the example slightly, taking rational numbers instead of natural numbers as the maps in $m$, we’ll  find that $(f_3)^{-1} = f_{3^{-1}}$ The inverse map of a map in the list of interpretations is also an example of the maps in the list, so if a ‘named’ map is invertible, the inverse can  also be named. In the example above, $f_3$ is invertible and its inverse is named by the  inverse of 3.
>
> 这样的函子还揭示了我们可以使用求减一的符号作为“逆”的广泛推广的意义。如果我们稍微改变一下例子，用有理数而不是自然数作为 7K 中的映射，我们会发现 $(f_3)^{-1} = f_{3^{-1}}$ 解释列表中映射的逆映射也是列表中映射的一个示例，因此如果“命名”映射是可逆的，则逆也可以在上面的例子中，$f_3$ 是可逆的，它的逆元被命名为3的逆元。



**04 幺半群和加法范畴**

> Let’s now introduce another category which we can call 71. This is also a monoid, so that it will only have one object, denoted again *. The maps will be again num¬  bers, but now the composition will be addition instead of multiplication.
>
> 现在让我们介绍另一个类别，我们可以称之为 71。这也是一个幺半群，因此它只有一个对象，再次表示为 *。地图将再次是数字，但现在的组合将是加法而不是乘法。
> $$
> g_n(x) = n + x
> $$
> All the above suggests the standard example’ of interpretation of a monoid in sets,  in which the object of the monoid is interpreted as the set of maps of the monoid  itself. In this way we get a standard functor from any monoid to the category of sets.
>
> 上述所有内容都表明了集合中幺半群的解释的标准示例，其中幺半群的对象被解释为幺半群本身的映射集。这样我们就得到了从任何幺半群到集合范畴的标准函子。



**05 加法范畴到任意 endomap 范畴**

> There are many functors from 71 to sets other than the standard one. Suppose I  take a set X together with an endomap a, and I interpret * as X and send each map n  °f* (a natural number) to the composite of a with itself n times, i.e. a", and in order to preserve identities, I send the number 0 to the identity map on X. In this way we get a functor from 7t to sets, h : 7t —> S which can be summarized this way:
>
> 除了标准函子之外，还有从 71 到集合的许多函子。假设我将集合 X 与内图 a 一起，将 * 解释为 X，并将每个映射 n°f*（自然数）发送到 a 与其自身 n 次的复合，即 a"，并且为了保留恒等性，我将数字 0 发送到 X 上的恒等映射。这样，我们就得到了从 7t 到集合 h : 7t —> S 的函子，可以这样总结：
>
> 1. $h(*) = X$,
> 2. $h(n) = \alpha^n$, and
> 3. $h(0) = 1_X$

这个部分很好的引出的**函子（functor）**

> In this way, whenever we specify a set-with-endomap X°a we obtain a functorial interpretation of 7t in sets. This suggests that another reasonable name for Sp would be S'* to suggest that an object is a functor from 7t to S. This was the  category of **dynamical systems** (more appropriately called ‘discrete-time dynamical  systems ). A discrete-time dynamical system is just a functor from this monoid 71 to the category of sets. What would be a ‘continuous-time dynamical system’?
>
> 通过这种方式，每当我们指定一个包含内图 X°a 的集合时，我们都会获得集合中 7t 的函数解释。这表明 Sp 的另一个合理名称是 S'*，表明对象是从 7t 到 S 的函子。这是动力系统的类别（更恰当地称为“离散时间动力系统”）。离散时间动力系统只是从幺半群 71 到集合范畴的函子。什么是“连续时间动力系统”？



## 思路

**01 关于函子和结构保持**

文章中是使用了仅有一个元素的对象作为叙述开始的。

所以，如果我们不把自然数看作一个整体先，而把其中每一个数字看作一个整体，1是一个范畴、2是一个范畴。

我们先假设，1范畴和2范畴是两个不同的范畴。



需要注意的，书中是指出了，我们要认识一个范畴，我们需要定义的内容包括：

1. 对象（object）
2. 映射（map）
3. 域（domain）和值域（codomain）
4. 标识（identity）
5. 可组合性（composable）



这里的例子，先定义了对象——单个元素。

然后定义了映射——普通乘法

域和值域——都是**单元素范畴**



都是单元素范畴非常重要，因为SESSION 12 中，文章已经开始让我们意识到，有个大范畴，大范畴下有个属于他的小范畴这样的叙事方式。



**01.1 不可逆**

有一个0的存在。