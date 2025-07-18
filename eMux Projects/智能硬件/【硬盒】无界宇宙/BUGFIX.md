# 无界宇宙 USB 掉线 BUG

## 问题描述

1. Windows系统下，程序运行，串口存在，但是无相应
2. Windows系统下，程序运行，串口掉了，且无法恢复
3. Linux系统下，使用 Cat 读数据，数据到一半停止
4. Linux系统下，同时使用 Joystick 和 串口通信，必出现 `reset full-speed USB device number 39 using xhci_hcd` 问题。



## 问题定位

ESP32S2 的 USB 硬件问题



## 历史记录

### 2-25

- 裸露测试温度最高42度，环境温度12度



### 2-23

- 四张SD卡全部损坏；SD卡使用温度范围：-25ºC 到 85 ºC的工作温度；不要在 SD 卡读取/写入时突然断电
- 四台树莓派全部正常；三块屏幕一块带过来的时候就已经损坏。
- 拟解决方案：
  1. 不要断电。通宵耗电量不过10度。`3A*5V*30台*12小时 = 10800W`
     - 软件办法，添加关机卡/添加网络关机功能（没有开机功能）
  2. 外壳开孔散热，特别是SD卡周围
  3. SD卡损坏必现的还是需要去现场查看，必现问题一定有固定问题存在。
- 已知BUG：上电启动有概率应用未启动，因为GUI未加载完毕。(已修复，请使用最新的SD卡)



### 2-22

- 反馈一个树莓派插上 SD 卡后 ，SD卡烧毁

- 反馈一个树莓派无法刷卡，有滴的一声反馈，但是树莓派无法打卡

- 反馈旋钮有一个会掉

- 阶段解决办法：

  - [x] 打卡机刷卡异常：刷卡后屏幕无反应，推测服务器无反馈，导致刷卡机等待请求卡死。
    - 解決办法：添加请求超时功能代码，并反馈请求超时错误
    - 同时添加 DEBUG 日志；切换启动方式至 System 系统，自动记录日志内容和时间
  - [x] 旋钮设备掉线问题：三个旋钮连主板，其中一个旋钮会掉。
    - 不确定原因，当前解决办法：从公司替换一个新的旋钮到现场
    - 旋钮设备需要补货，已经无存货

  - 消费点：
    - 由于树莓派检测办法尚未明确，不采购新树莓派；
    - 但是要更新固件，需要采购30个SD卡制作新系统并去现场重新更换SD卡、并重新配置
      - 或者有现场人员配合，远程更新
    - 旋钮问题需要采购/制作新设备，用于替换可能损坏的旋钮并检测问题



### 2-20

- 测试了已经损坏的树莓派，绿灯不亮。推测是 EEPROM 损坏，网上搜索了修复 EEPROM 相关的资料
- 制作 EEPROM 修复 SD 卡，失败。目前定为树莓派失效，同时检测到背板有电容击穿的痕迹



### 2-13

- 从下午4点到晚上10点，三个连HUB的打卡机出现一次全部掉线的问题；电脑还能识别其中的两个，两个重新打开依旧能正常通信
- 转手柄协议的通信一直正常
- `esptool.py -p COM3 write_flash 0x10000 firmware.bin`



### 2-12

- [USB Console](https://docs.espressif.com/projects/esp-idf/en/v4.3/esp32s2/api-guides/usb-console.html)：S2 USB 限制

- 需要一个具体解决方案。了解到Unity是SerialPort，没有Linux如此丰富的串口配置。

  剩余两个方案包括：

  1. 变更为 Arduino
  2. ~~树莓派中继~~

- 明确方案：

  - 旋钮变更为HID发送信息，正在测试
    1. 接在HUB上的 Joystick 会受到速率影响而失效（Reset？）
  - RFID不变，新电路新增 UART 接口



### 2-11

- 在家里，Windows 笔记本，外接6个设备，20分钟，无掉线，但数据无法读取。高概率
- 换树莓派，HUB外接6个设备，20分钟，无掉线，同样数据无法读取，中概率。
- 树莓派，不接HUB，外接4个设备，20分钟，无掉线，数据无法读取，中概率。 
- 换主Linux电脑，HUB外接6个设备，20分钟，无掉线，数据无法读取，低概率。
- Linux电脑开 Joystick，20分钟，高速设备 Reset。必现。

- [What are USB device resets?](https://superuser.com/questions/668911/what-are-usb-device-resets)：说是USB总线质量问题
- [USB device stop working after some time](https://bbs.archlinux.org/viewtopic.php?id=286234)
- [Devices Connected to a USB Hub Resetting Constantly](https://bbs.archlinux.org/viewtopic.php?id=291592)：说这是一个内核问题，但是又介绍说内核修复了这个问题。
- [config_usb_ehci_hcd - kernelconfig.io](https://www.kernelconfig.io/config_usb_ehci_hcd)：介绍了什么是 ehci（Enhanced Host Controller Interface）
- [一台电脑上最多可以连接多少台USB设备？](https://www.usbzh.com/article/detail-867.html)
- 用一个最简单的串口发送功能，依旧卡死。
- 打印错误信息后发现是 `CDC RX Overflow` 问题
- [Native USB CDC hangs up on ESP32-S2 after about 320 characters](https://github.com/espressif/arduino-esp32/issues/6221)：定位到了 ESP 的具体问题