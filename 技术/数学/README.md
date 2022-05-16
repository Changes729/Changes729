> 参考资料：
> - [LATEX Mathematical Symbols](https://www.caam.rice.edu/~heinken/latex/symbols.pdf)

# 数学

线性代数

> 参考资料：
>
> - [[CDC] 理解变换矩阵](https://mp.weixin.qq.com/s/vtM80l4GcaNV4se7090-GA)

- 向量积：$$\vec{a}\times\vec{b} = \left|\vec{a}\right|\left|\vec{b}\right|\sin{\theta}$$

  - 向量积表现为两个向量围成的四边形面积。从前半部分看，坐标向量积 $$x_a*y_b - x_b*y_a$$ 意义是将向量经过平移后的大面积减去小面积，从而计算出平行四边形的面积。从后半部分看，两个线段围的长度乘以 $$\sin{\theta}$$ 就是平行四边形的底乘高计算公式。

    再补充一下，$$x_a*y_b - x_b*y_a = \left[ \begin{matrix} x_a & x_b \\ y_a & y_b \end{matrix} \right]$$，这个叫 **行列式的值**。

- 点积：$$\vec{a}\cdot\vec{b} = \left|\vec{a}\right|\left|\vec{b}\right|\cos{\theta}$$

  - 向量点积表现为两者同方向上相乘后的长度。从前半部分看，点积是一个向量的投影与另一个向量的乘积。从后半部分看也一样。

    再补充一下，$$x_a*x_b + y_a*y_b = \left[\begin{matrix} x_a & y_a \end{matrix}\right] * \left[\begin{matrix} x_b \\ y_b \end{matrix}\right]$$，这个叫 **向量点积**