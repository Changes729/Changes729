> 文章来源：https://mp.weixin.qq.com/s/VC6vtYqwZHh-Y3B-TPa3XQ

# 基于组合优化的3D家居布局生成看千禧七大数学难题之NP问题

## 关键词

- [组合优化问题](https://en.wikipedia.org/wiki/Combinatorial_optimization)

  - [**P（polynomial time，多项式时间）**问题](https://en.wikipedia.org/wiki/P_(complexity))：P 意味着用多项式描述的复杂性类；比如一个算法需要花多少时间解决（时间复杂度）

    > In computational complexity theory, P, also known as PTIME or DTIME(nO(1)), is a fundamental complexity class. It contains all decision problems that can be solved by a deterministic Turing machine using a polynomial amount of computation time, or polynomial time.

  - [**NP（nondeterministic polynomial time，非确定性多项式时间）**](https://en.wikipedia.org/wiki/NP_(complexity))问题：

    > NP is the set of decision problems solvable in polynomial time by a **nondeterministic Turing machine**.
    >
    > NP is the set of decision problems verifiable in polynomial time by a **deterministic Turing machine**.

  - [NP-completeness](https://en.wikipedia.org/wiki/NP-completeness) 问题：（看不懂）

- 运筹学

- **组合优化方法（Combinatorial Optimization Problem，COP）**：是一类在离散状态下求极值的最优化问题。组合优化也叫离散优化, 是运筹优化的重要组成部分, 其中 "组合" 是排列组合的组合。从字面上理解这个名词, 组合优化是要从呈组合数复杂度爆炸式增长的解空间中, 寻找最优的解向量, 即制定最优决策方案。



## 摘记

**从技术角度，这些设计过程都是一种决策过程，而决策过程总是可以被刻画成一个优化问题**，进而可以使用运筹学的方法来解决。运筹学、数学规划（Math Programming）问题的数学表达式，由自变量（Variables）、目标函数（Objective Function）和约束条件（Constraints）组成，所有优化问题本质上都可以化简为由它们组成的数学表达式，然后求解满足约束条件下使得目标函数最大/小的变量的值。