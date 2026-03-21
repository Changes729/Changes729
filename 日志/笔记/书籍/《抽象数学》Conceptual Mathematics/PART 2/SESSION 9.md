# Retracts and idempotents

# 回缩和幂等

## 关键词

- 同构（isomorphism）：$A \cong B$
- 回缩（retract）与大小比较：我们说 $A$ 是 $B$ 的一个回缩（a retract of），当 存在映射关系：$ A \to^{s} B \to^{r} A; rs = 1_A$，此时我们也说 $A \le_R B$，A 至少和B一样大。
- 不动点（fixed points）：对于任意幂等映射 $e: B \to B$，由 幂等映射 分离出的对象 A,存在两个映射 $s: A \to B; r: B \to A$，使得 $rs = 1_A; sr = e$. 不动点唯一。
- 康托-伯恩斯坦定理（Cantor-Bernstein Theorem）



## 摘记

**01 三类回缩问题**

> Museum director’s problem: Given B -U A, choose A -U B satisfying rs = 1A. Mental picture: View r as sorting B into A sorts:
>
> Bird-watcher’s problem: Given A —> B, choose B —> A satisfying rs — 1aMental picture: View s as a sampling of B by A:
>
> Child’s problem: Given B, choose a map B B satisfying ee = e. Having  watched children for years, I remain as puzzled as ever about the selection of the  idempotent endomap e associating to each animal the most familiar animal it resembles. After that’s done, though, the rest of the job (splitting the idempotent) is easy:

我觉得这个点也很妙。之前我们从一个范畴的恒等映射给出了不动点。然后这次我们从一个大映射中找到自身的小映射。



**02 无限集的比较**

> His striking discoveries have  barely been introduced here; and we have also neglected Galileo’s earlier discovery of a characteristic feature of infinite sets: a set can be isomorphic to a proper part of itself, as the isomorphism
>
> 这里几乎没有介绍他的惊人发现；我们还忽略了伽利略早期发现的无限集合的一个特征：一个集合可以同构于它自身的一个真部分，就像同构一样



## 思路

**01 不动点**

这里用一个例子介绍了不动点。我觉得还挺有价值的。

这里我觉得是一个非常好的补充。因为之前我们了解同构，但是没有仔细去理解非同构。或者说没有理解从恒等映射 **无中生有** 出另一个范畴。然后这个生成的范畴，可以比原范畴更大。

不动点相关的概念还有计算机科学中的字符串。

但是文章关于这方面的内容并没有解释的很明白。