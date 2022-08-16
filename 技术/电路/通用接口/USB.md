> 参考资料：
>
> - [Device Class Definition for Human Interface Devices](https://www.usb.org/sites/default/files/hid1_11.pdf)
> - [HID Usage Tables](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)

# USB

## HID

USB HID设备会和USB 控制器（PC电脑）之间建立两条数据通道：控制通道 (Control Pipe) 和中断通道 (Interrupt Pipe)。



Arduino 的 USB 库是在 Arduino.h 中引用的 `USBCore.h`。

而 STM32 则有自己的 HAL USB 库。 
