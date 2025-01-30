> 视频来源：[手把手教你做个WiFi/蓝牙网关](https://www.bilibili.com/video/BV1xt4y1j7vK/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)
>
> 参考资料：
>
> - [[立创开源硬件] **ESP32 WiFi/蓝牙网关 ESP32 GetWay**](https://oshwhub.com/yanqisui/esp32-getway)
>   - [[增强版] **Home Assistant蓝牙网关**](https://oshwhub.com/jdbwlj/Home-Assistantlan-ya-wang-guan)
> - [蓝牙Mesh模组软件规范](https://help.aliyun.com/document_detail/173310.html?userCode=okjhlpr5)
> - [EMQ](https://www.emqx.com/zh)：面向物联网的 现代数据基础设施？

# 【立创开源】手把手教你做个WiFi/蓝牙网关

整体方案基于 乐鑫ESP32-GetWay 开源方案。

- 烧录：ESP32 Download tool（Windows）
  - 固件：提供的 .bin 固件
  - 烧录接口：SPI
- 接口：网口、USB-C、BLE、WiFi
- 组网设备：PB（**provisioning bearer**，能力中继，本意是 provisioning 作为供应，bearer 作为携带者，应该是指蓝牙能力携带）
- 蓝牙服务端协议：MQTT（Message Queuing Telemetry Transport，**消息队列遥测传输**）
  - 平台：[EMQ](https://www.emqx.com/zh)