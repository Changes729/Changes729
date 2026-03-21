> 相关链接：
>
> - [Youtube](https://www.youtube.com/watch?v=I8LbkfSSR58&list=PLbgaMIhjbmEnaH_LTkxLI7FMa2HsnawM_&index=1)
> - [Table of Contents](https://bartoszmilewski.com/2014/10/28/category-theory-for-programmers-the-preface/)
> - [milewski-ctfp-pdf-zh-cn-translation](https://github.com/Wang-Ji20/milewski-ctfp-pdf-zh-cn-translation)：中文翻译

# 范畴学（[milewski-ctfp-pdf](https://github.com/hmemcpy/milewski-ctfp-pdf)）

## 关键词

- 符号：箭头（`->`）、类型（`A`，`B`）、组合（`g∘f`）

- 概念：集合（`Set`、`Void`、`Bool`、`Int`）、函子的集合（`Hom-set`）、纯函数（Pure Functions）、荒谬函数（absurd）、自函数（id）、单元构造（unit）

- 关系：顺序（Orders）

- 范畴：Kleisli范畴、monoid（幺半群）

- 算法|组合：Product（笛卡尔积）、coproduct（余积）

- 组合|类型：组合类型（Product、Struct）、和类型（Sum Types、enum）、加法、代数类型（`List a = Nil | Cons a (List a)`）

  | Numbers   | Types                             |
  | --------- | --------------------------------- |
  | 0         | `Void`                            |
  | 1         | `()`                              |
  | a + b     | `Either a b = Left a | Right b`   |
  | a * b     | `(a, b) `or `Pair a b = Pair a b` |
  | 2 = 1 + 1 | `data Bool = True | False`        |
  | 1 + a     | `data Maybe = Nothing | Just a`   |

- 函子、函数类型、函数对象的指数

- 自然变换





## 摘记

**00 其他摘记**

范畴学是关于组合（Composition）和唯一性（Identity）的学科。

集合悖论：一个不包含自己的集合



范畴（Category）由对象（Objects）构成。

Morphisms（态射）是指对象的关系：`a->b`，`->` 就是 态射。

对象是抽象对象，它没有内部属性。

> 非线性写作？突然想到这个词
>
> 群论（幺半群是一个范畴）



类型（Type）是一种集合（Set）

$A^{id} = A$



同构（isomorphism）

- injective（单射，monomorphism，one to one）：an arrow *f* : *X* → *Y* such that for all objects *Z* and all morphisms *g*1, *g*2: *Z* → *X*, $\displaystyle f\circ g_{1}=f\circ g_{2}\implies g_{1}=g_{2}.$ 
- surjective（[满射](https://zh.wikipedia.org/wiki/%E6%BB%A1%E5%B0%84)，epimorphism）



`absurd（荒谬的）`：范畴论中以 `Void` 为参数的函数。不能以 Void 作为参数，因为 Void 没有 `id`。



`hom-set`：$C（a,b）$ 表示一个范畴中，所有关系的集合。

在 `thick category` 的定义中，一个 `thick category` 的 `hom-set` 必须是空集，或者是单例。`Partially ordered`偏序关系，有向无环图。



monoid（幺半群）：对幺半群的所有内部关系，指向的对象都是幺半群本身。



Kleisli Categories



terminal Object（终端对象）



积：

$$p' = p∘m $$

$$q' = q∘m $$



余积：

$$i' = m∘i $$

$$j' = m∘j $$

$l(a) = 1 + a*l(a) = \frac{1}{1-a} = \sum_{n=0}^{\infty} a^n$

> 这里不对。但是课程是想借用这个来说明这是一个数列。



**01 关于函子和态射**

函子是范畴与范畴之间的关系，态射是范畴内的关系。



## 思路

