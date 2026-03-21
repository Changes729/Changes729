# Sets, maps and composition

# 集合，映射与组合

## 关键词





## 摘记

**01 相等的映射**

> In categories other than the category of sets, ‘a map from A to B’ is typically some  sort of ‘process for getting from A to B,' so that in any category, maps / and g are  not considered the same unless they have at least the properties:  
>
> 1. $f$ and $g$ have the same domain, say A, and 
> 2. $f$ and $g$  have the same codomain, say B.  
>
> Of course, there may be many different maps from A to B, so that these two properties alone do not guarantee that $f$ and $g$ are the same map. If we recall that a point of  a set A is a map from a singleton set 1 to A, we see that there is a simple test for  equality of maps of sets A —> B and A —> B:  
>
> If for each point $1 \to A, f \circ a = g \circ a, then f = g.$



## 思路

**01 映射的数量**

这个还挺关键的。我们虽然之前知道了 “映射” 是从集合 A 到集合 B，并且也知道了映射到恒等关系。但是这一章节中，给出了映射的数量。

$A = \{S, O, A, M \} ;  B = \{E\}$ 

$A\to B$只有一个映射。$B \to A$ 却有四个映射。

但是，如果 $A = \{\}$，$A\to B$ 也有一个映射，书上是这样写的，我不明白。

$B \to A$ 则没有映射。

如果 $B = \{\}$，那么 $A\to B$ 仍然还有一个映射。

这是因为，映射的数量 $A\to B = |B|^{|A|}$。