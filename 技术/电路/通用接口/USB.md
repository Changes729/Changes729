> 参考资料：
>
> - [USB Document Library](https://www.usb.org/documents)
>
> - [Device Class Definition for Human Interface Devices](https://www.usb.org/sites/default/files/hid1_11.pdf)
> - [HID Usage Tables](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)
> - [STM32 "USB Device" vs. "USB OTG HS" - what is the difference?](https://electronics.stackexchange.com/questions/234516/stm32-usb-device-vs-usb-otg-hs-what-is-the-difference)：Device 只能作为设备，而 OTG HS 就能作为主设备了。然后文章还说了一句：STM32 HS片上不支持HS，还需要外挂。
> - [USB 之一 USB2.0 规范详解 第一部分](https://blog.csdn.net/ZCShouCSDN/article/details/79957404)
> - [STM32 之三 标准外设版USB驱动库详解（架构+文件+函数+使用说明+示例程序）](https://blog.csdn.net/ZCShouCSDN/article/details/78936456)：这文章写的蛮好的
> - [WCH选型说明](https://special.wch.cn/zh_cn/USBChips/#/)
> - [[USB] VBUS](https://blog.csdn.net/muojie/article/details/7205275?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166910582416800213014551%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166910582416800213014551&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-7205275-null-null.142^v66^wechat,201^v3^control,213^v2^t3_control2&utm_term=usb%20vbus&spm=1018.2226.3001.4187)：说明了 VBUS 取电规范

# USB

## HID

USB HID设备会和USB 控制器（PC电脑）之间建立两条数据通道：控制通道 (Control Pipe) 和中断通道 (Interrupt Pipe)。



Arduino 的 USB 库是在 Arduino.h 中引用的 `USBCore.h`。

而 STM32 则有自己的 HAL USB 库。 



- CDC（communications device class）：设备通信类
  - POTS Models
  - ISDN Models
  - Networking Models

- CDC_ECM（USB CDC-ECM Class for Ethernet over USB）
- DFU（Device Firmware Upgrade）
- MSC（mass storage device）
  - [STM32F103 MSC](https://forum.arduino.cc/t/blue-pill-stm32f103c8t6-usb-mass-storage-flash-w28q64-like-a-sd-card-reader/612147)：需要配置 `board_build.core = maple`，需要安装 `arpruss/USBComposite for STM32F` 和 `adafruit/Adafruit SPIFlash`
  - [STM32 USB MSC](https://controllerstech.com/stm32-usb-msc/)：USE RAM



## USB传输类型

- 控制传输
- 中断传输
- 批量传输
- 等时传输



