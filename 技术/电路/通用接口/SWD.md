> 参考资料：
>
> - [Serial Wire Debug (SWD)](https://community.silabs.com/s/article/serial-wire-debug-swd-x?language=en_US)
> - [SWD DEBUG Communication STM32H7 ISSUE](https://community.st.com/s/question/0D53W00001COOf3SAH/swd-debug-communication-stm32h7-issue)：这篇文章说无法正常进行 SWD 烧录，从反馈来看，有人说是 pin 口坏了，有人说是初始化（使用）了SWD pin 口。
> - [STM32 & ST-LINK - Cannot connect to MCU after successful programming](https://electronics.stackexchange.com/questions/204996/stm32-st-link-cannot-connect-to-mcu-after-successful-programming)：这个回答也是，就说SWD pin 口被占用了。

# SWD(Serial Wire Debug)

SWD 是一种双线可选的 JTAG 接口。其顶层依旧是 JATG 协议。

SWD使用双线通信与内部的 Debug Port（DP）进行通信，而内部的 DP 又和 Memory Access Port（MEM-AP）进行通信，而且可以是多信道的。AP 监听内部的 AHB/APB 总线从而实现内存读取等功能。

典型 SWD 电路如图所示：

![](https://documentation-service.arm.com/static/5f2a6a573951795e690a8f18?token=)