> 参考资料：
>
> - [USB Document Library](https://www.usb.org/documents)
>- [Device Class Definition for Human Interface Devices](https://www.usb.org/sites/default/files/hid1_11.pdf)
> - [HID Usage Tables](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)
> - [STM32 "USB Device" vs. "USB OTG HS" - what is the difference?](https://electronics.stackexchange.com/questions/234516/stm32-usb-device-vs-usb-otg-hs-what-is-the-difference)：Device 只能作为设备，而 OTG HS 就能作为主设备了。然后文章还说了一句：STM32 HS片上不支持HS，还需要外挂。
> - [USB 之一 USB2.0 规范详解 第一部分](https://blog.csdn.net/ZCShouCSDN/article/details/79957404)
> - [STM32 之三 标准外设版USB驱动库详解（架构+文件+函数+使用说明+示例程序）](https://blog.csdn.net/ZCShouCSDN/article/details/78936456)：这文章写的蛮好的
> - [WCH选型说明](https://special.wch.cn/zh_cn/USBChips/#/)
> - [[USB] VBUS](https://blog.csdn.net/muojie/article/details/7205275?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166910582416800213014551%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166910582416800213014551&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-7205275-null-null.142^v66^wechat,201^v3^control,213^v2^t3_control2&utm_term=usb%20vbus&spm=1018.2226.3001.4187)：说明了 VBUS 取电规范
> - [USB Type-C接口PD协议解决方案](https://www.richtek.com/Design%20Support/Technical%20Document/AN056?sc_lang=zh-CN)

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



## USB-C

![Technical Document Image Preview](https://www.richtek.com/Design%20Support/Technical%20Document/~/media/Richtek/Design%20Support/Technical%20Documentation/AN056/CN/Version15/image013.jpg?file=preview.png)

- USB Type-C标准相对于旧标准的另一不同点是它引入了**双角色能力**。每根USB Type-C电缆的两端都是完全等同的，这就意味着**连接起来的两台设备必须相互进行沟通**以确定自己应作为主机还是外设而存在。角色的沟通需针对数据和电源分别进行，此工作在电缆接通之后就要进行。用于数据通讯的**主机端口被称为下行端口 (Downstream Facing Port, DFP)**，**外设端口被称为上行端口 (Upstream Facing Port, UFP)**。而电源方面，供电端被称为源端 (Source)，耗电端被称为吸端 (Sink)。有的设备既可以有数据上的双角色 (Dual Roles of Data, DRD) 能力，又具有电源上的双角色 (Dual Roles of Power, DRP) 能力。CC线在两台设备连接期间能起到定义电源角色的作用。

- USB Type-C系统带来的另一个好处是较高的供电能力。传统的USB电缆只容许提供2.5W功率，USB Type-C电缆则容许提供高达5V/3A即15W的最大功率，如果采用了**电源传输 (Power Deliver, PD) 协议**，电压电流指标就可以提升到20V/5A即100W的最大功率，这就容许通过USB端口为大型设备如监视器等设备供电，也容许对含有大型电池包的笔记本电脑等设备进行充电。新的USB PD 3.0协议还支持可编程电源 (Programmable Power Supply, PPS) 协议，容许对总线电压和电流进行精确调节，而电压则可以低于5V。利用这样的协议，使用可调的总线电压对电池进行直接充电的高效直充系统就成为可能，这时的总线电压可以低达3V。标准的Type-C电缆额定的负载能力是3A，当更高的电流出现时，含有电子标签的电缆就必须被使用了，其中的电子标签可经CC线对电缆的能力进行标识。电子标签需要的电源供应是5V的，可用CC线经由电缆的VCONN向其提供。

![Technical Document Image Preview](https://www.richtek.com/Design%20Support/Technical%20Document/~/media/Richtek/Design%20Support/Technical%20Documentation/AN056/CN/Version15/image014.jpg?file=preview.png)

### 手机快充解决方案

![Technical Document Image Preview](https://www.richtek.com/Design%20Support/Technical%20Document/~/media/Richtek/Design%20Support/Technical%20Documentation/AN056/CN/Version15/image015.jpg?file=preview.png)

