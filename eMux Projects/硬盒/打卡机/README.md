# 打卡机

## 主要更新方向

- 打卡机需求：尺度问题（大的屏幕/小的屏幕）；供电问题；丰富度；
- 打卡机和外部展项结合



## 模块构成

- 电源
- 主控
  - GUI
  - 网络
  - 数据
  - 接口
- 屏幕
- RFID
- 音频





## 更新计划

**01 产品设计**

硬盒两个版本：

- 方形：POE 拓展板+当前方形屏幕；整体外形是方形的。
- 长条：POE 紧凑拓展板+长条DSI屏幕



1. 完善当前设计
   - 系统稳定性测试
   
     - 温度检测：`vcgencmd measure_temp`
   
       【2025-3-23】通过命令测试，不到10分钟，温度70摄氏度；一个小时到80度；参考文章：
   
       - [Raspberry Pi 能否在70 摄氏度下工作](https://groups.google.com/g/ustc_lug/c/KZkr3OlKkOM)
       - [树莓派的工作温度测试](https://shumeipai.nxez.com/2019/04/02/what-is-the-ideal-raspberry-pi-cpu-temperature-range.html)
       - [簡單玩樹莓派-(1) 監測樹莓派](https://www.gss.com.tw/blog/rpi-monitor)
   
2. 降本拓展

   - [RK3566](https://wiki.lckfb.com/zh-hans/tspi-rk3566/sdk-compilation/android-sdk-compilation.html)：支持 Android、Linux、OpenHarmony
   - [K230 RISC-V](https://wiki.lckfb.com/zh-hans/lushan-pi-k230/)：只有 OpenMV 固件
   - [
     device_arpi_rpi4](https://github.com/android-rpi/device_arpi_rpi4)