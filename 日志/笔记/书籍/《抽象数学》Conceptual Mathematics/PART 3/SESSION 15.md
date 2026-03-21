# Objectification ofproperties in dynamical systems

# 动态系统属性的客观化

## 关键词





## 摘记

**01 结构保留的映射**

> $$
> X^{\circlearrowright \alpha} = \xymatrix @ur{
> 3 \ar[r] & 0 \ar[d] \\
> 2 \ar[u] & 1 \ar[l]
> }
> 
> Y^{\circlearrowright \beta} = \xymatrix @ur{
>  		 	  & y \ar@/^/[ld] \\
> z \ar@/^/[ru] & w \ar[l]
> }
> $$
>
> We want to find a map $f$ from $X^{\circlearrowright \alpha}$ to $Y^{\circlearrowright \beta}$ in $S^{\circlearrowright}$ that sends 0 to y.
> $$
> \xymatrix @ur{
> 3 \ar@{-->}[r] \ar[ddr] 	& 0 \ar@{-->}[d] \ar[dr] 					\\
> 2 \ar@{-->}[u] \ar@/^/[rr]	& 1 \ar@{-->}[l] \ar[d]	& y \ar@<1ex>@{-->}[ld] 	\\
> 		 					& z \ar@<1ex>@{-->}[ru] 		& w \ar@{-->}[l]
> }
> $$

这个映射图很有意思。因为如果不同范畴之间的态射存在，并且假定 $f: 0 \to y$，那么
$$
f(1) = f(\alpha(0)) = \beta(f(0))  = \beta(y) = z \\
f\alpha0 = f1 = z	\\ 
f\alpha1 = f2 = y	\\ 
f\alpha2 = f3 = z	\\
f\alpha3 = f0 = y	\\
$$

> In fact, there are exactly two structure-preserving maps  from X^a to Y333 one which sends 0 to y, and one which sends 0 to z, but none  which sends 0 to w. Do you see why?
>
> 事实上，从 X^a 到 Y333 正好有两个结构保留映射，一个将 0 发送到 y，一个将 0 发送到 z，但没有一个将 0 发送到 w。你明白为什么吗？
>
> These maps also illustrate that structure-preserving maps do not preserve negative  properties
>
> 这些映射还表明，保留结构的图不会保留负属性



**02 通过映射命名具有确定周期的元素**

> $$
> C_n = \xymatrix{
> \bullet^0 \ar[r] & \bullet^1 \ar[r] & \bullet^2 \ar[r] & \bullet... \ar[r] & \bullet^{n-1} \ar@/^/[llll]
> }
> $$
>
> $C_n \to Y^{\circlearrowright \beta}$ means elements y in $Y^{\circlearrowright \beta}$ having period n

> Exericise 1: Show that an element which has both period 5 and period 7 must be a fixed point.
>
> 证明同时具有周期 5 和周期 7 的元素一定是不动点。



**03 继任者地图（successor map）**

上面的内容，介绍了循环元素，并且对于其他任意范畴，只要存在循环结构，就可以存在一种通用的函子。

但是，循环之外的元素应该如何映射？这里就给出了加法映射。



**04** 

> In Session 6 we emphasized the notion that in studying a large objective category  X — S, the category of all abstract sets and maps, a bare minimum which is  adequate is the category with eight maps whose two objects are a one-point set 1 and a two-point set 2; this is because:
>
> 在第 6 节中，我们强调了这样一个概念：在研究一个大的客观范畴 $X = S$（所有抽象集合和映射的范畴）时，最低限度是具有 8 个映射的范畴，其中两个对象是单点集 1 和两点集 2；这是因为：
>
> 1. the maps $1 \to X$ are the points of  $X$;  
> 2. the maps $2 \to X$ are the pairs of points of $X$;  
> 3. the maps $X \to 2$ are sufficient to express all the yes/no properties of points of $X$;  
> 4. precomposing with a map $2\to 2$ exchanges the roles of two points in a pair;  
> 5. following by a map$2\to 2$ effects negating a property; and 
> 6. composing $1 \to X \to 2$ records in $e$ whether a particular point has a particular property.

> $$
> \Omega = \xymatrix{
> \bullet^0 \ar@(ul, dl)[] & \bullet^1 \ar[l] & \bullet^2 \ar[l] & \bullet^3 \ar[l] & ...\bullet^{\infty} \ar[l] \ar@(ur, dr)[]
> }
> $$



**05 动态系统的表示**

> $$
> \xymatrix @ur{
> && \bullet \ar[dl] & \bullet \ar[l] \\
> &\bullet \ar[d] & \bullet \ar[l] & &\bullet \ar@/^/[dl] \\
> \bullet \ar[ur] & \bullet\ar[l] & \bullet \ar[l] &\bullet \ar@/^/[ur]\\
> }
> $$
>
> 1. 寻找端点，或寻找循环中的任意一点：
>
> $$
> \xymatrix @ur{
> && \bullet \ar[dl] & \bullet^a \ar[l] \\
> &\bullet \ar[d] & \bullet^b \ar[l] & &\bullet \ar@/^/[dl] \\
> \bullet \ar[ur] & \bullet\ar[l] & \bullet^c \ar[l] &\bullet^d \ar@/^/[ur]\\
> }
> $$
>
> 2. 选择一个合理的排序，如 $a,b,c,d$
>
> 3. 寻找不同的映射路径，比如从 $a$ 开始，$a, \alpha a, \alpha^2 a, \alpha^3 a, \alpha^4 a$都是不同的，但是我们会到这一步因为：
>
>    $\alpha^5 a = \alpha^2 a$
>
> 4. 然后进行到下一个元素：
>
>    $\alpha b = \alpha^2 a$
>
> 5. 重复第四步直到结束。
>
> 这样你可以得到一系列标签 和一些关系：
>
> $L: a, \alpha a, \alpha^2 a, \alpha^3 a, \alpha^4 a, b, c, d, ad$
>
> $R：\alpha^5 a = \alpha^2 a \\\alpha b = \alpha^2 a \\\alpha c = \alpha^3 a \\\alpha^2 d = d$
>
> 然后，当存在一个 $Y^{\circlearrowright \beta}$
> $$
> \xymatrix{
> \bullet^q \ar[r]  & \bullet^r \ar[d] & \bullet^q \ar[l] & & \bullet^m \ar@/^/[d] \\
> &\bullet^t \ar[r] & \bullet^v \ar[dl] & & \bullet^l \ar@/^/[u] \\
> \bullet^s \ar[ur] & \bullet^u \ar[l] & & & \bullet^x \ar[d] \\
> &&&\bullet^w \ar[ur]& \bullet^y \ar[l]& \bullet^z \ar[l]
> }
> $$
>
> 1. 寻找 $f(a)$ 所有的可能点，并且还需要满足 $ \beta^5(\bar{a}) = \beta^2(\bar{a})$
>
>    只有 $w,x,y,z$ 满足要求。
>
> 2. 对于所有在 1 中满足要求的选择，寻找 $\bar{b}$ 元素，满足 $\beta^2 \bar{a} = y$
>
>    如果 $w$ 是 $\bar{a}$，那么只有 $x,z$ 满足要求
>
> 3. 然后继续寻找 $\bar{c}$，以此类推。



## 思路

