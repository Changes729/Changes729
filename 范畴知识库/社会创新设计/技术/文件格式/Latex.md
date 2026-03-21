> 参考资料：
>
> - [LaTeX画交换图](https://zhuanlan.zhihu.com/p/675400799)
> - [LaTeX中怎么画出范畴论中的交换图(包括3-cell这种复杂的图)?](https://www.zhihu.com/question/377324420)：第二个答案成功了
> - [LaTeX系列笔记(11)-画交换图](https://zhuanlan.zhihu.com/p/146546207)：仅支持 xy-pic
>   - https://texdoc.org/serve/xyguide.pdf/0

# Latex Block

$$
A @>a>> B \\
@VbVV @AAcA \\
   C @= D
$$

$$
\xymatrix{
 U \ar@/_/[ddr]_y \ar[dr] \ar@/^/[drr]^x \\
  & X \times_Z Y \ar[d]^q \ar[r]_p  & X \ar[d]_f            \\
  & Y \ar[r]^g & Z                       }
$$

$$
\xymatrix{ A \\
B & C \ar@<1ex>[ul]
\ar@<1ex>[ul];[] }
$$

