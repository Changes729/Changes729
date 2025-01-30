> 文章来源：https://mp.weixin.qq.com/s/EohQySoEAyGtzxRcqAolwQ

# 一篇不是很枯燥的ChatGPT闲谈

## 关键词

- RNN（Recurrent Neural Networks，循环神经网络）：[[Paper]](https://www.pnas.org/doi/pdf/10.1073/pnas.79.8.2554)



## 摘记

> 在很久很久以前（1982年那么久），深度学习模型中有一个非常经典的模型叫做RNN，即Recurrent Neural Networks（循环神经网络）[1]。RNN的出现是为了更好地处理序列信息，RNN隐藏层的值不仅受到当前输入的影响，还取决于上一次隐藏层的值。

> 最早在计算机视觉里应用的Attention机制被拿来用在了自然语言处理。该机制的思想就是把注意力集中在重要的信息上，而忽视不重要的信息（可见Attention图解[2]）。2017年，Google的研究人员发表了《Attention Is All You Need》[3]，这篇文章中的Transformer模型是GPT的基石，整个网络结构是由Attention机制组成[4]，并且将序列中的任意两个位置之间的距离缩小为一个常量，其次Transformer具有好的并行性，符合现有的GPU框架。这里必须要提一下：Transformer设置了一种“位置编码”（position encoding）机制，用来向序列数据添加位置信息，进而让模型学到“顺序”。做法简单巧妙：用正弦、余弦函数生成沿时间轴变化的波形，然后把这种波形叠加到Transformer的输入中。

> 这样的生成式模型可以给他输入N个单词（也称为Token）的序列，输出是最有可能在输入序列末尾放置的单词的预测。举个例子：
>
> 过了一会儿，大灰狼来了，他想闯进小兔子的→家
>
> 当我们想得到一个以上的多个单词时，就将得到的下一个单词添加到输入序列中，就可以得到下一个单词。
>
> ![图片](https://mmbiz.qpic.cn/mmbiz_png/DKcPurxib9LyhCxmk7KLnIZTsV8lIlAP4flpf3x4bLLOsGrn0KPNKd40U8uYJppo9n8wFULzkmDExHSz6wAW6Kw/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

