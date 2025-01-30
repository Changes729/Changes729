> 参考资料：
>
> - [关于PCB与设备外壳接地问题](https://blog.csdn.net/andylauren/article/details/52204068)：大致就是说，外壳如果没接地，那么PCB也别和外壳接地。
> - [什么叫做接地？](https://blog.csdn.net/qq_43188920/article/details/90715010?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-90715010-blog-105574106.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-90715010-blog-105574106.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=1)：总之就是要和地做电气或金属性连接。
> - [EMC design guide for STM8, STM32 and legacy MCUs](https://www.st.com/resource/en/application_note/an1709-emc-design-guide-for-stm8-stm32-and-legacy-mcus-stmicroelectronics.pdf)

# EMC电磁干扰

## 高速信号线 EMC 设计考虑

- **耦合干扰**（Coupling/crosstalk）：当一个信号耦合干扰到另一条线时，将会被识别为一个数据，并且存在时间偏移。
- **信号反射**（Signal reflection）：由于阻抗失配（impedance mismatching），容易受到影响的高速信号波形会产生变化。
- **时钟抖动**（Clock jitter）：一个外部干扰或者噪声会造成时钟边缘的偏差（deviation），这将导致时域宽容度的降低，甚至是通信失败。
- **潜在的天线**（Potential antennas）：靠近PCB边缘或者间隙间（gaps）的走线，将会成为一个天线。
- **认证失败**（Certification fails）：即使没有功能性问题，产品依然无法通过认证而需要重新设计。
- **多层板**（Stack-up）：
  - 一种最常见的对于改善 EMI 的考虑就是使用四层板（或者更多），它包括上下两层信号板，还有内部的地平面和电源平面。
  - 如果确实有明确的干扰信号存在，那么多层板的源地平面会减少干扰的发射，但是那可能需要八层板或更多的板层。
  - 避免在板子上加沟槽，沟槽会成为一个天线。
- **布线（Routing）技巧和推荐**：
  - 如果一个高速信号需要过孔（不推荐，这会导致高速信号阻抗适配），那么需要考虑将它的回流路径（return path）控制在最小回路。
  - 不要在间隙间布线，以避免它成为间隙间的电容。
  - 避免与噪声信号线的长距离平行走线，以避免耦合问题。
  - 对于一个非常长的走线（>30cm）并且有一个高速信号（>50MHz）时，可以添加一个终端电阻（termination resistance）以减少信号反射，电阻范围在 $$30 \ohm$$ ~ $$50 \ohm$$ 之间。