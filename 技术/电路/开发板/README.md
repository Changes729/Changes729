> 参考资料：
>
> - [STM32国产替代，候选和比较](https://zhuanlan.zhihu.com/p/376895827)
> - [立创·ESP32S3R8N8开发板](https://oshwhub.com/li-chuang-kai-fa-ban/li-chuang-esp32s3r8n8-kai-fa-ban)

# 开发板

- [ESP8266](./ESP8266.md)
- [北京兆易创新 - GD32系列](https://www.gigadevice.com.cn/product/mcu)：号称做到了与STM32相同型号的全兼容
- 上海灵动微电子
- [沁恒微电子](https://www.wch.cn/)：专做USB通信的
- [宏晶 STC](http://www.stcmcudata.com/)
- [和泰（Holtek）/盛群](https://www.holtek.com.cn/)：有许多单片机，USB/触摸/健康管理等。
- [新唐](https://www.nuvoton.com/?__locale=zh)：也有许多单片机
- [华大]():
  - [**HC32D391FEUA-TFN32TR**](https://item.szlcsc.com/3349886.html)



## 沁恒微系列

> - [E8051 USB系列](https://www.wch.cn/products/productsCenter/mcuInterface?categoryId=72)

| 系列  | 主频  | FLASH | RAM    | DataFlash | TIMER | UART | SPI  | IIC  | I/O  | 其他 | 价格 | 渠道                                                         |
| ----- | ----- | ----- | ------ | --------- | ----- | ---- | ---- | ---- | ---- | ---- | ---- | ------------------------------------------------------------ |
| CH552 | 24MHz | 16K   | 1K+256 | 128       | 3*16b | 2    | 1    | -    | 17   |      | 1.65 | [1688-1](https://detail.1688.com/offer/730950770195.html?spm=a26352.13672862.offerlist.30.3d847bf0DOOcAr) |

CH552 中断只支持低电平和下降沿。

## ESP系列

> - [[官方] ESP 选型](https://products.espressif.com/#/product-selector?language=en&names=)
> - [[安信可] ESP8266系列](https://docs.ai-thinker.com/esp8266)
> - [[安信可] ESP32 系列模组专题](https://docs.ai-thinker.com/esp32-s)
> - [芯片](https://www.espressif.com.cn/zh-hans/products/socs)

| SOC                                                          | MODULE                                                       | 主频(MHz) | FLASH  | RAM     | DataFlash | UART | SPI  | IIC  | I/O  | WiFi | BLE  | 其他        | 价格 | 渠道                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------- | ------ | ------- | --------- | ---- | ---- | ---- | ---- | ---- | ---- | ----------- | ---- | ------------------------------------------------------------ |
| ESP8266EX                                                    |                                                              | 160       | 0      | 160k    | 0         | 2    | 2    | 1    | 17   | O    | X    | I2S         | 4    | [1688-1](https://detail.1688.com/offer/736387716446.html?spm=a26352.13672862.offerlist.6.7e0c2cf6IMyKoV) |
| ESP8266EX                                                    | ESP-12F                                                      | 160       | 32M    | 160k    | (32M)     | 2    | 2    | 1    | 9    | O    | X    | I2S         | 5.28 | [1688-1](https://detail.1688.com/offer/521867761713.html?spm=a26352.13672862.offerlist.6.64eeec4fXEQGs6) |
| ESP32（ESP32-D0WD-V3）                                       |                                                              | 240       | 0      | 520k    | 0         | 3    | 4    | 2    | 34   | O    | O    | I2S         | 7.9  | [1688-1](https://detail.1688.com/offer/732047774207.html?spm=a26352.13672862.offerlist.1.1a186e1fiLSUBK) |
| ESP32                                                        | ESP32-S                                                      | 240       | 32M    | 520k    | (32M)     | 3    | 4    | 2    | 34   | O    | O    | I2S         | 9.5  | [1688-1](https://detail.1688.com/offer/596934152703.html?spm=a26352.13672862.offerlist.1.742633caA9Rq8o) |
| ESP32-D0WDQ6                                                 | ~~WROOM-32~~（OutOfDate）                                    | 240       | 4M     | 520k    | (4M)      | 3    | 4    | 2    | 32   | O    | O    | I2S         | 21   | [优信电子](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.6da22e8dCVLMnR&id=724748055478&_u=42d3uchq823c) |
| ESP32-S3                                                     | ESP32-S3(N16R8)                                              | 240       | 16M+8M | 512k    | (16M+8M)  | 3    | 4    | 2    | 36   | O    | O    | USB-OTG/I2S | 22.8 | [1688-1](https://detail.1688.com/offer/587736633187.html?spm=a26352.13672862.offerlist.45.3502302dtFm6n4) |
| [ESP32-S2F](https://www.espressif.com/sites/default/files/documentation/esp32-s2_datasheet_cn.pdf) | [S2 Mini V1](https://item.taobao.com/item.htm?abbucket=19&id=681794131086&ns=1&spm=a21n57.1.0.0.1274523cHkaRAL&skuId=5103865706888) | 240       | 4      | 128+320 | 2         |      |      |      |      |      |      |             |      |                                                              |



## Arduino系列（ATmega32系列）

| SOC        | MODULE | 主频(MHz) | FLASH | RAM         | DataFlash   | UART | SPI  | IIC  | I/O  | 其他 | 价格 | 渠道                                                         |
| ---------- | ------ | --------- | ----- | ----------- | ----------- | ---- | ---- | ---- | ---- | ---- | ---- | ------------------------------------------------------------ |
| ATmega32u4 |        | 48        | 32k   | 2560(Bytes) | 1024(bytes) | 1    | 2    | 1    |      | USB  | 18   | [优信电子](https://item.taobao.com/item.htm?abbucket=19&id=673016420638&ns=1&spm=a21n57.1.0.0.3d63523cY982At) |



## STM32 系列

| SOC           | 主频         | FLASH | RAM     | DataFlash | 其他 | 价格 | 渠道                                                         |
| ------------- | ------------ | ----- | ------- | --------- | ---- | ---- | ------------------------------------------------------------ |
| stm32f103c8t6 | 72MHz（MAX） | 64k   | 20k     |           |      | 5.5  | [1688-1](https://detail.1688.com/offer/44298483616.html?spm=a26352.13672862.offerlist.20.37511e62QiXBhU) |
| stm32f031K6U6 | 48MHz        | 32k   | 4KBytes |           |      | 2.39 | [深圳市义胜电子网](https://item.taobao.com/item.htm?id=674309147831&skuId=4851113585535&spm=a1z10.3-c-s.w4002-21047669632.17.708f27e556W3yu) |



## AT32系列

| SOC          | 主频   | FLASH | RAM  | DataFlash | 其他 | 价格 | 渠道                                                         |
| ------------ | ------ | ----- | ---- | --------- | ---- | ---- | ------------------------------------------------------------ |
| AT32F415K8U7 | 150MHz | 64k   | 32k  |           |      | 5    | [1688-1](https://detail.1688.com/offer/715331135020.html?spm=a26352.13672862.offerlist.15.72eb83d42eaJl8) |



## HC32系列

| SOC                 | 主频   | FLASH | RAM  | DataFlash | 其他    | 价格 | 渠道 |
| ------------------- | ------ | ----- | ---- | --------- | ------- | ---- | ---- |
| HC32F460JETA-LQFP48 | 200MHz | 512K  | 32k  | 4K        | USB支持 | 3.9  |      |



## 全志系列

| SOC                    | BOARD         | 主频   | RAM   | 视频                               | 价格 | 渠道                                                         |
| ---------------------- | ------------- | ------ | ----- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| H3 Quad-core Cortex-A7 | Orange Pi One | 1.2GHz | 512MB | H.265/HEVC 4K@30fps video decoding | 150  | [淘宝](https://item.taobao.com/item.htm?_u=42d3uchqfdd0&id=658556522882&spm=a1z09.2.0.0.5d562e8dm9sgLx) |

