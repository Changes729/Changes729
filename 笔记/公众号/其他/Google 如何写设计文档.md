> 文章来源：https://mp.weixin.qq.com/s/NJdPVNcrJ9OuyKSPKpmfWA

# Google 如何写设计文档

## 关键词

用设计文档来定义软件设计、



## 摘要

> 作为软件工程师，我们的工作并不是生产代码本身，而是解决问题。
>
> 设计文档可能更简明、更容易被理解，相比代码能在更高的层面沟通问题及解决方案。
>
> 除了用作软件设计的原始文档记录，设计文档还在软件研发生命周期中实现了下述功能：
>
> - 在修改成本还比较低的时候，尽早地**识别设计缺陷**。
> - 在组织中围绕设计**达成共识**。
> - 确保**横切关注点（Cross-cutting concern）**得到充分考虑。
> - 在组织中**传播资深工程师的知识**。
> - 就设计决策形成**组织记忆基础**。
> - 成为软件设计者技术资产中的一个**摘要性制品**。

横切关注点，指的是一些具有横越多个模块的行为，通常是有多模块复用的中层。

> **设计文档的构成**
>
> 1. **上下文和范围（Context and scope）**
>
> 2. **目标和非目标（Goals and non-goals）**
>
> 3. **实际设计（The actual design）**
>
>    **系统上下文图（System-context-diagram）**
>
>    **APIs**
>
>    **数据存储（Data storage）**
>
>    **代码和伪代码（Code and pseudo-code）**
>
>    **约束条件（Degree of constraint）**
>
> 4. **候选设计（Alternatives considered）**：在给定的项目目标和所有可选方案下，为什么选择了最终方案，在给定目标下权衡的判断是如何做出的，而这正是文档的读者所关注的核心。
>
> 5. **横切关注点（Cross-cutting Concerns）**：在这里组织可以确保一些横切关注点如安全，隐私，可观测性，总是被考虑到。
>
> 6. **设计文档的长度（The length of a design doc）**：设计文档应该具备充分的细节，但同时足够简短以能够被忙碌的人阅读。对于一个大型项目来说，最佳的长度似乎是 10 到 20 页。
>
> **设计文档的生命周期（The design doc lifecycle）**
>
> 1. 创建和快速迭代
> 2. 审查（可能有多轮）
> 3. 实现和迭代
> 4. 维护和学习

