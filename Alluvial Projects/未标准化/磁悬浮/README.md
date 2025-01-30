> 参考资料
>
> 下拉式磁悬浮
>
> - [x] [【电子制作】低压低功耗纯硬件磁悬浮](https://www.szlcsc.com/info/1262.html)：低功耗磁悬浮技术方案
>
> 上推式磁悬浮
>
> - [ ] [**上拉式磁悬浮试验成功**](https://www.amobbs.com/thread-4552606-1-1.html)
> - [ ] [Magnetic Levitation – The Easy Way](https://www.hackster.io/PeterN/magnetic-levitation-the-easy-way-d0bc1c)
> - [ ] [DIY上拉式磁悬浮](https://blog.csdn.net/nicekwell/article/details/9368369)
> - [ ] [Arduino上拉磁悬浮](https://arduino.ncnynl.com/archives/201603/374.html)
> - [ ] [上拉式磁悬浮制作经历与踩坑~（基于stm32f103, Arduino 和51没试过，不过应该类似)](https://blog.csdn.net/weixin_44221517/article/details/119981844)

# 磁悬浮

## 外部分析

**01 市场价格**

下拉式磁悬浮模块市场价40～55元

上拉式磁悬浮展示产品价格在100～250元之间



## 方案细节

### 黑果开源方案

**01 总体方案**

有三个霍尔元器件，分别检测xyz三轴磁场。通过霍尔反馈直接控制线圈驱动电路。

霍尔元器件采用 HW101A，这是一个防反接霍尔传感器，其内阻受温度变化，最小值为240欧姆，以为其最大输入电流在20mA，所以外加电压不能大于4.8V。在恒压或恒流状态下，霍尔传感器的输出和磁场成正比。恒定磁场条件下，输出电压和输入电压呈正比，但是不和输入电流成正比。

也是因为我们希望输出电压同磁场成正比，为了保持电压文档，电路中使用了一个 TL431 稳压二极管做2.5v的稳压。以保护霍尔元器件的同时保证输出正常。

XY轴的两个线圈驱动从稳压管取中值电压作为参考电压，然后判断经过运放后的霍尔传感器比较输出，来控制线圈的通断，从而调整磁场。

运放这边，输入的参考地通过反向放大器和霍尔元件的输出进行比较。然后再通过反向放大器，将电平放大至 $8.5V_{ref}-7.5V_h$。

默认状态下，Z霍尔感应的应该是0。Z轴出现变化后，X和Y轴默认应该是输出正电压的。



- 霍尔元器件：[HW101A](https://www.akm.com/content/dam/documents/products/magnetic-sensor/hall-element/in-sb-ultra-high-sensitivity/hw101a/hw101a-en-datasheet.pdf)，1、3引脚为输入，2，4引脚为输出，不区分正反，所以可以翻转180度使用。最大额定工作电流20mA，输入阻抗240~550$\Omega$（受温度变化）。

  $V_H = cfV_CB$，计算得当 $V_C = 2.5v$ 时，$V_H = 13.75B$，当 $V_C = 1v$ 时，$V_H = 5.5B$

- 稳压二极管：TL431，反向电压最大36v。稳压 2.5v。



**02 磁场**

> 参考文章：
>
> - [什么是霍尔(HALL)？霍尔传感器工作原理、设计及选型指南](http://www.jupwill.com/news/285.html)

磁场单位为特斯拉（T），我们常用毫特（mT）为单位。其中从N级发出的磁场方向为正方向，一般霍尔元件只感应S极。像HW101A的芯片向上是N极，所以吸引S极。



**03 遗留问题**

1. 当前方案磁铁磁场转化为电压的具体范围



### 立创低功耗方案

上述方案的功耗主要是由三极管短路带来的。这套方案有两处改动

1. 将HW101A霍尔元件更换为 [GH49FEUA](https://item.szlcsc.com/93525.html)，线性霍尔。
2. 将三极管H桥改为 [RZ7889](https://item.szlcsc.com/84833.html) 电机驱动芯片。

