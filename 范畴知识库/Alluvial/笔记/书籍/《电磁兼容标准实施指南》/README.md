# 电磁兼容标准实施指南

## 专业术语

- 电磁环境（electromagnetic environment）
- 无线电环境（radio environment）
- 电磁辐射（electromagnetic radiation）
- 电磁骚扰（electromagnetic disturbance）
- 电磁干扰（electromagnetic interference）
- 电磁噪声（electromagnetic noise）
- 无用信号（unwanted signal；undesired signal）
- 干扰信号（interfering signal）
- 性能降低（degradation of performance）
- 电磁发射（electromagnetic emission）
- 功率密度（power density）
  - 对于电磁波的功率密度，其定义为：“垂直于波传播方向的单位截面积的发射功率”
  - 对于无线电波传播，功率密度的定义为：“行波的功率密度是波印廷矢量（Poynting Vector）的时间平均值”
- 功率谱密度（power spectrum density）
  - 对一个波的频谱来说，功率谱密度是“单位频率的均方幅度”
  - 均方幅度：幅度平方的平均值
- 基波（分量）（fundamental（component））
- 谐波（harmonic）
- 谐波次数（harmonic number）
- 交调（crossmodulation）
- 互调（intermodulation）
- 抗扰度（immunity）
- 敏感度（susceptibility-EMS）
- 发射裕量（emission margin）
- 抗扰度电平（immunity level）
- 抗扰度限值（immunity limit）
- 抗扰度裕量（immunity margin）



## 电磁干扰分析

书中提到电磁干扰本身就是一件非常复杂的事情，一方面是由于电子元器件信号中本身携带丰富的谐波，另一方面生活中原本就充斥着各种无线电波。

书中提到，干扰包括

- 紧耦合线：靠得非常近的线缆
- 天线源和天线接收器：分电压与电场；电流与磁场的耦合。
- 导线源和导线接收器：分电压与电场；电流与磁场的耦合。
- 公共阻抗耦合

干扰的模型可以用 骚扰源（N），到耦合（T，0<T<1），最后到接收器的信号（S）之间的关系来简单表示。

书本的第 6.5 章有提到一个电磁波的**进场干扰和远场干扰**。就是说，对于$$\mathcal{f} = 10KHz, \lambda = 3\times10^4 m; \mathcal{f} = 1MHz, \lambda = 300 m; \mathcal{f} = 100MHz, \lambda = 3m; \mathcal{f} = 1GHz, \lambda = 0.3 m $$，文章中提出，对于3m测量法，10MHz以下的频率属于近场范围，二对于300MHz以上的频率已经进入远场区，这样就使得我们需要在远近场，综合干扰信号的频率综合判断干扰。



## 电气照明和类似设备的无线电骚扰

书中确实有表明，电气照明类设备存在电磁骚扰，而我查阅部分网页，也表示——电磁骚扰的问题往往不出在灯本身，而是电源。

电气照明灯电磁兼容规范中，有一个「插入损耗」参数，插入损耗越大越好，越大电磁兼容性越好。

文中也提出，对于白炽灯，没有**调光装置或者电子开关**的，是不产生电磁骚扰的。而对于荧光灯灯具、无极灯、微波硫灯等，都需要在完整的工作电路下，都需要进行电磁兼容测试。

书中有几个对电磁兼容的参数要求：

- 电源端子的骚扰电压（与频率有关）
- 负载端子的骚扰电压
- 控制端子的骚扰电压
- 9kHz～30MHz频率范围的**磁场**分量辐射电磁干扰限值
- 30MHz～300MHz频率范围的**电场**分量辐射电磁干扰限值
- 30MHz～300MHz频率范围的**共模端子**分量辐射电磁干扰限值