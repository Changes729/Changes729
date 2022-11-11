> 参考资料：
>
> - [Device Class Definition for Human Interface Devices](https://www.usb.org/sites/default/files/hid1_11.pdf)
> - [HID Usage Tables](https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf)

# USB

## HID

USB HID设备会和USB 控制器（PC电脑）之间建立两条数据通道：控制通道 (Control Pipe) 和中断通道 (Interrupt Pipe)。



Arduino 的 USB 库是在 Arduino.h 中引用的 `USBCore.h`。

而 STM32 则有自己的 HAL USB 库。 



- CDC（communications device class）：设备通信类
- CDC_ECM（USB CDC-ECM Class for Ethernet over USB）
- DFU（Device Firmware Upgrade）
- MSC（mass storage device）
  - [STM32F103 MSC](https://forum.arduino.cc/t/blue-pill-stm32f103c8t6-usb-mass-storage-flash-w28q64-like-a-sd-card-reader/612147)：需要配置 `board_build.core = maple`，需要安装 `arpruss/USBComposite for STM32F` 和 `adafruit/Adafruit SPIFlash`
  - [STM32 USB MSC](https://controllerstech.com/stm32-usb-msc/)：USE RAM
