> 参考资料：
>
> - [What is OpenOCD?](https://openocd.org/doc-release/html/About.html#What-is-OpenOCD_003f)
> - [OpenOCD Developer Resources](https://openocd.org/doc-release/html/Developers.html#Developers)

## 什么是 OpenOCD

开放片上调试器（Open On-Chip Debugger）目标是为嵌入式设备提供调试（debugging）、烧录再编程（in-system programming）以及边界扫描（boundary-scan）功能。

实现这些功能，往往需要一个调试适配器（debug adapter），它是一个向目标设备发送调试电子信号的一个小硬件。由于调试主机（debug host）往往不具有一些对信号的原生支持，所以需要连接器（connector）帮忙连上设备。

这些调试适配器往往会支持一个或多个不同的信号。因此这些适配器也多种多样。有些适配器是分离的，他们被称为硬件加密狗，也有些适配器是集成在开发版上的，便于开发者们使用USB等通用接口进行开发、调试。

举个例子，JTAG 适配器支持了 JTAG 信号，它和主板上的 JTAG (IEEE 1149.1) 协议相兼容。一个 *TAP* 意思是测试访问端口（Test Access Port）。同样的还有 SWD（Serial Wire Debug，串行调试） 协议用在一些新的 ARM 开发版上。SWD 也支持调试，但是 JTAG 还支持边界扫描。



### 调试器（Dongles，电子狗）

OpenOCD 支持多种调试器，包括基于USB接口的，基于并行端口（parallel port-based）的，或其他可以跑OpenOCD接口的独立设备。详情可以看这篇文章：[Debug Adapter Hardware](https://openocd.org/doc-release/html/Debug-Adapter-Hardware.html)



### GDB 调试器

允许 ARM7、ARM9、XScale、Cortex-M3 以及 Intel Quark内核通过 GDB 协议进行调试。

