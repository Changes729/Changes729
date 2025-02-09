> 视频来源：https://www.icourse163.org/learn/BUAA-1002534005?tid=1473108463#/learn/content?type=detail&id=1259802858&sm=1
>
> 其他参考资料
>
> - [北京理工大学 射频技术与软件研究所](https://cems.bit.edu.cn/)：[矢量分析](https://cems.bit.edu.cn/docs//2023-03/9edbe65013a8442cb353c1a6c298293d.pdf)
> - 参考书：[微波技术与天线](https://zh.singlelogin.re/book/22985578/254a91/%E5%BE%AE%E6%B3%A2%E6%8A%80%E6%9C%AF%E4%B8%8E%E5%A4%A9%E7%BA%BF.html) *[周希朗](https://zh.singlelogin.re/author/周希朗（编著）)*

# 微波技术

## 相关课程

《电磁场与电磁波》系统学习电磁波的基本理论。



## 书本大纲

01 绪论

02 规则传输系统中导波的基础知识

03 传输线理论

04 微波规则传输系统

05 微波谐振腔

06 微波网络基础

07 微波无源元件

08 天线



## 电磁场与电磁波

**01 无界空间均匀平面波**

平面波是指其等相位面是平面，均匀波是指其等相位面和等幅度面重合。特点：

1. 电场强度和磁场强度之比等于**媒质固有波阻抗 $$\eta$$**；媒质介电常数 $$\dot{\mu}$$ ，媒介磁导率 $$\dot{\epsilon}$$ 都可能为复数

   $$\eta = \sqrt{\frac{\dot{\mu}}{\dot{\epsilon}}} = |\eta|e^{j\phi_\eta}$$

   $$\eta$$ 可以描述媒质中传播的均匀平面波电场强度和磁场强度的大小和相位关系。

2. 向 `+Z` 方向传播的波电磁场复述表示具有 $$e^{-jkz}$$ 形式的传播因子，波的衰减和相移由**媒质固有波数** $$k = \beta - j\alpha $$ 确定。其中  $$\beta $$ 为**相位常数**， $$\alpha $$ 为**衰减常数**。

   $$k = \omega \sqrt{\dot{\mu}\dot{\epsilon}} = \beta - j\alpha$$

3. 相速度 $$v_p$$ 、相波长 $$\lambda_p$$ 由相位常数 $$\beta$$ 和角频率 $$\omega$$ 的关系确定：

   对<u>自由空间</u>，有

   $$v_p = c = \frac{1}{\sqrt{\mu_0 \epsilon_0}}$$ ，自由空间相速度为光速。

   $$\lambda_p = \frac{c}{f} = \lambda_0$$，自由空间相波长，也称为工作波长。

   对<u>理想介质</u>，有

   $$v_p = v = \frac{1}{\sqrt{\mu \epsilon}} = \frac{c}{\sqrt{\mu_r \epsilon_r}}$$

   $$\lambda_p = \lambda = \frac{\lambda_0}{\sqrt{\mu_r \epsilon_r}}$$

   $$\mu_r \epsilon_r$$ 为相对介电常数和相对磁导率

   

   对有限时长的多频窄带信号还可以定义群速度 $$v_g$$，群速度：理想的电磁波是不存在的，实际信号往往是多个信号的叠加。

   在窄带信号中，我们可以定义群速度，也就是一群 $$\omega, \beta$$ 相近的波运动时，可以表现出的波群整体的共同速度。

   $$v_g = \frac{d\omega}{d\beta}$$

   沿传播方向经过单位长度波形整体延迟的时间，称为群延时或群时延

4. 对有损耗材质，波的相速度随频率变化，这种现象称为 **色散**。其本质上由媒质和边界条件决定。



**02 有界空间的平面波**

因为均匀平面波只在理想情况下存在，我们在微波技术中，考虑一种特殊的情况——导行电磁波。



**03 时谐量的复数表示**

$$u(z,t) = A(z)cos[\omega t + \phi(z)]$$

$$E_x(\vec{r},t) = E_x(\vec{r})cos[\omega t + \phi_x(\vec{r})]$$

只考虑时谐量的幅度和初相位，不考虑时间关系。

$$u(t) = Acos[\omega t + \phi]$$

$$u(t) = Re(Ae^{j\phi}e^{j\omega t})$$，取实部 $$\dot{u} = Ae^{j\phi}$$



## 传输线理论

- $$R_0$$：单位长度导体损耗功率
- $$G_0$$：单位长度媒质损耗功率
- $$L_0$$：单位长度存储的磁能
- $$C_0$$：单位长度存储的电能

$$\gamma = \alpha + j\beta$$；$$\gamma$$ 为传播常数

传输线电压通解：$$\dot{U}(z) = A_1 e^{-\gamma z} + A_2 e^{\gamma z}$$

传输线特性阻抗：$$Z_0 = \sqrt\frac{Z}{Y}$$ 

- 传输线特性阻抗与传输线长度无关

单列波与合成波



传输线三种工作状态：行波、驻波、行驻波

- 行波：阻抗匹配
- 驻波：全反射（终端短路、终端开路、终端纯电抗负载）
- 行驻波：阻抗失配



## 波导理论



## 微波网络与微波元件

