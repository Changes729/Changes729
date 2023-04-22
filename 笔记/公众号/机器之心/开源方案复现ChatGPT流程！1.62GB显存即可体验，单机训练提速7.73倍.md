> 文章来源：https://mp.weixin.qq.com/s/j8gvD_4ViRE4WQaQlcnmrQ
>
> 开源地址：https://github.com/hpcaitech/ColossalAI

# 开源方案复现ChatGPT流程！1.62GB显存即可体验，单机训练提速7.73倍

## 关键词

人类反馈强化学习（RLHF，Reinforcement Learning from human preferences）

> ChatGPT 的惊人效果，重要特征是在训练过程引入人类反馈强化学习（RLHF），使得模型表现更符合人类价值观。

大语言模型、训练奖励模型（RM）、强化学习算法、近端策略优化算法（PPO）

> ChatGPT 的训练流程主要分为三个阶段：
>
> 1. 从 Prompt 库中采样，收集其人工回答，利用这些数据来**微调预训练大语言模型**。
>
> 2. 从 Prompt 库中采样，使用大语言模型生成多个回答，人工对这些回答进行排序后，**训练奖励模型（RM）**，来拟合人类的价值判断。
>
> 3. 基于阶段 1 的监督微调模型和阶段 2 的奖励模型，利用**强化学习算法**对大语言模型进一步训练。
>
> 其中阶段 3 是 RLHF 训练的核心部分，OpenAI 采用了强化学习中的**近端策略优化算法（PPO）**，借此引入奖励信号，使得语言模型生成内容更加符合人类评判标准。

![](https://mmbiz.qpic.cn/mmbiz_png/KmXPKA19gWib6zMyQx2Kiauvl3BNYBIHT2dZvqZN1icfU7pg1Cqia0t2icTEwuRvzDzicJwL7L2qmgtjpicnXuqfLXl4g/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

Actor-Critic（AC）结构、PPO 算法

> ChatGPT 模型的复杂性在于强化学习的引入会带来更多模型的调用。例如，使用基于 Actor-Critic（AC）结构的 PPO 算法，需要在训练时进行 Actor、Critic 两个模型的前向推理和反向传播，以及监督微调模型、奖励模型的多次前向推理。

ZeRO、Gemini、Chunk-based 内存管理

> 同时，Colossal-AI 通过 ZeRO，Gemini,  Chunk-based 内存管理等技术，极大地降低 ChatGPT 训练的显存开销

GPT-L

> 由于 ChatGPT 的复杂性和内存碎片，PyTorch 最大仅能启动基于 GPT-L（774M）这样的小模型的 ChatGPT。

低秩矩阵微调（LoRA）

> Colossal-AI 支持使用低秩矩阵微调（LoRA）方法进行高效微调。LoRA 方法认为大语言模型是过参数化的，其在微调中的参数改变量是·一个低秩的矩阵，可以将其分解为两个更小的的矩阵的乘积。

无冗余优化器 (ZeRO) 

> Colossal-AI 支持使用无冗余优化器 (ZeRO) 来优化内存使用，这种方法可以有效减少内存冗余，并且相比传统的数据并行策略，不会牺牲计算粒度和通信效率，同时可以大幅提高内存使用效率。