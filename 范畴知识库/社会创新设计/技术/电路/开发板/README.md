> 参考资料：
>
> - [STM32国产替代，候选和比较](https://zhuanlan.zhihu.com/p/376895827)
> - [立创·ESP32S3R8N8开发板](https://oshwhub.com/li-chuang-kai-fa-ban/li-chuang-esp32s3r8n8-kai-fa-ban)
> - [List of common microcontrollers](https://en.wikipedia.org/wiki/List_of_common_microcontrollers)
> - [List of Wi-Fi microcontrollers](https://en.wikipedia.org/wiki/List_of_Wi-Fi_microcontrollers)

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



⚠️注意：USB低成本开发默认选用沁恒微的CH32F103；通用开发板请选择ESP32-S2



## 沁恒微系列

> - [E8051 USB系列](https://www.wch.cn/products/productsCenter/mcuInterface?categoryId=72)

| 系列                                                      | 主频  | FLASH | RAM    | DataFlash | TIMER | UART | SPI  | IIC  | I/O  | 其他    | 价格                                                         | 渠道                                                         |
| --------------------------------------------------------- | ----- | ----- | ------ | --------- | ----- | ---- | ---- | ---- | ---- | ------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| CH552                                                     | 24MHz | 16K   | 1K+256 | 128       | 3*16b | 2    | 1    | -    | 17   | USB     | 1.65                                                         | [1688-1](https://detail.1688.com/offer/730950770195.html?spm=a26352.13672862.offerlist.30.3d847bf0DOOcAr) |
| [CH32V003F4U6](https://www.wch.cn/products/CH32V003.html) | 48MHz | 16K   | 1K     |           |       | 1    | 1    | 1    | 6~18 | NO-USB  | [QFN20-0.68](https://item.taobao.com/item.htm?abbucket=19&id=702260750651&ns=1&pisk=fzUqhJOKuV2WLFQ65juZay9wca0xlqXCuPMss5ViGxDmh5ci7821MxNGHRzZE5EfMc6v_IUzLFTfHiFM7VgGd9_CRSdxWVXByENMmIhs6dcDCAVlrmARNa_CRSFyGjfQZw1t3UttThYgImDuZfMoiAmms_ooOf0MocYDqLD-EA0inxxorfGMjKmin_Jo6fGMjVYDr7cETj0iSRVo1nwgH_ktm6So_s7G8UitKSD0GSUl1mtYGYktCzc4aMFjUbG7zjoqK0SUdt4UtS4K_PCHbAP_m-G8QwWrrry4o0uN7U3bTu2q4oWwz0Eu9Pmz29-L9S24xD4cz_eaEWEKorX9lxEgZPD7o1TZKkNKzbU1eEDaql4jDVpc3bz4TPrN4OvtZG48WoJMbmc-av1PakOgP6y8f0neXhnP2bkCsFxMjdaB5nzZRhKt4scrd1YG.&priceTId=2147812317261089775084717e0c2d&spm=a21n57.1.item.2.6b39523cbjXKDG&utparam=%7B%22aplus_abtest%22:%22c2ffab76b6b1c9b590951582b9fd0c77%22%7D)<br />[QFN20-1.58~0.84](https://item.szlcsc.com/6049934.html?fromZone=l_c__%2522catalog%2522) |                                                              |
| CH32F103C8T6                                              | 72MHz | 32K   | 10K    |           |       | 3    | 2    | 2    | 37   | USB/CAN | [3.79](https://item.taobao.com/item.htm?abbucket=19&id=680708878129&ns=1&pisk=fParKOAtz22bieQBRbuEgPMo5ug-k4X1zyMItWVnNYDoFWcn8-2CwYNheJzEnWE5wD6JTQU4QeT5egFH82ghCO_157d-J2X1Dt1gZQhI9HxHdYvDn0AAGZ_157F2Nbf_iN1KUtMs9HY3K0mcoXDDKb03KqDmwxYotUcHnskxt2cH-0YcofcnZv2ntIVmsXvHKUYnomcSnv0n-UG_K8Cqp0fNmmGnhOgo4AVVXeYElFioIbDD-O4qaOHgZx8H-YbFMLN3K98ISle48c218E37_o0mao5HmYmaq8GYLN8oErPurYalhUMuySq_R-fH-vr0jcZgZttqgoV7umaGQeo8m8EtYy6fW4Z_1yngraJthchUQ4qVnUyG4tvKiM4YJuJHY0cxgA1VglO3l1yYAmnwvHnVDjk1texHxpa6R3zE5HKK0_cqC6Yh.&priceTId=2147801817261104955013109e6d2a&skuId=5052752843020&spm=a21n57.1.item.2.561f523cW5OvTy&utparam=%7B%22aplus_abtest%22:%22bea83603e7c6927a3dc7c2c1ec942563%22%7D)<br />[3.3](https://detail.1688.com/offer/757608886762.html?spm=a26352.13672862.offerlist.1.c7f01e62ESM9Ds)<br />[9.3-7.2](https://so.szlcsc.com/global.html?k=CH32F103C8T6) | [开发板](https://item.taobao.com/item.htm?abbucket=19&id=644529403934&ns=1&pisk=fpwZKJt-Qx4Q3C6XhckqY8OmHRDtQAb5Q-gjmoqmfV0i5omm3y4fXVZcWryq-oF1Xj_90heUzK91W1ED3xMcPa65FlKtHxbWXhLrIhnj4FxMlqX3xfxdA965FlEefcj7xTsx7M9-DIv0ofchKm0Hodvgov0nf2vimdmD-MuKmxxioqvhK0momK4mmDmnVmtMnx0GK2m--qDmnUw4oPIEkfjPtbC0-s3o_4qFwKvqZLGirquHna2Eba3uj2JDnVXVvFZ0oZJjE7UU3b453pH_4WDnbWSDtVczsPiLuTJiSJrgIVwGRdggBkV7hyjDnqP3ZbNujwOEYWq_LXwlzKlTtPF-g-_CeAN7V-huIO8-Rbn4zAVF-dzl4hYxxs2LH58DgfmKY4sFY7t0dgzLGXhyMIhF9Du5mKADiEwWhCyqFIdxTGmEPivc.&priceTId=2147826417261109129828066e5289&skuId=4806792146137&spm=a21n57.1.item.3.f8b2523cpDxAtS&utparam=%7B%22aplus_abtest%22:%22de4bd638f8a20dcf58150a67c27280d3%22%7D) |

CH552 中断只支持低电平和下降沿。



## GD系列

| 系列                                                         | 主频   | FLASH | RAM  | DataFlash | TIMER | UART | SPI  | IIC  | I/O  | 其他    | 价格                                                         |
| ------------------------------------------------------------ | ------ | ----- | ---- | --------- | ----- | ---- | ---- | ---- | ---- | ------- | ------------------------------------------------------------ |
| [GD32F350 CBT6](https://www.gigadevice.com.cn/product/mcu/entry-level-mcus/gd32f3x0-series) | 108MHz | 128K  | 16K  |           |       |      |      |      |      | USB,IIS | [2.95](https://item.taobao.com/item.htm?abbucket=19&id=675059179113&ns=1&priceTId=2100c80817276882990617577e0bb4&spm=a21n57.1.item.1.f526523cXqTiwy&utparam=%7B%22aplus_abtest%22%3A%2236c7aa67a2212c7727466963a4b39ca8%22%7D&xxc=taobaoSearch) |
| [GD32F103 C8T6](https://www.gigadevice.com.cn/product/mcu/mcus-product-selector/gd32f103c8t6) | 108MHz | 3M    | 96K  |           |       | 3    | 2    | 2    |      | USB,CAN | [4.7](https://item.taobao.com/item.htm?id=564707040509&pisk=f6Nm3qOVG0tIK0tmRTcfIoaEmRXRGnGszldtXfnNU0oWkm3v612i2kcTHiitQlqumSHZXtZiIlESQShYkumgXyyYDjHO_70t5nJ2gA5zzV0KQlnTkEw7vyRYMtG9sjGs_MId96LblfGNI4VkssMr5quN6xlwzzlheykc96UbrDFY45fLMITXvv3Z_xoqU0oS-n84bx-rz0gs7nlZ0a4yS6O9MkRYwIcsxnFLDkVBrBnLu0A3R70VhD1I4CPTwqk0_UiJ_4FooxmUuSuTIc0gLWDbYgpx0Jm_x2EAaIq3uo2ELS-Pqfa8Kl03gwJnjoazMYPVWpgS1-yEg5jH0zM3aShbEMAKY8aasYzfxpg8QyFYIg5DUp73pCgPW7J6CxuSrDnPLgtzYzol_abkpPMqPVyL6avohHOwslblrpIj34gap&spm=a1z10.5-c-s.w4002-24706531925.59.373d2ec7GzrMQ1) |



## ESP系列

> - [[官方] ESP 选型](https://products.espressif.com/#/product-selector?language=en&names=)
> - [[安信可] ESP8266系列](https://docs.ai-thinker.com/esp8266)
> - [[安信可] ESP32 系列模组专题](https://docs.ai-thinker.com/esp32-s)
> - [芯片](https://www.espressif.com.cn/zh-hans/products/socs)
> - [**深圳市杰瑞发科技有限公司**](https://shop2ww89w9h1i903.1688.com/page/offerlist_167653743.htm?spm=a261y.25179003.13772573013170.40.2cf03dc26VUyGc&sortType=wangpu_score)

| SOC                                                          | MODULE                                                       | 主频(MHz) | FLASH  | RAM     | DataFlash | UART | SPI  | IIC  | I/O  | WiFi | BLE  | 其他        | 价格                                                         | 渠道                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------- | ------ | ------- | --------- | ---- | ---- | ---- | ---- | ---- | ---- | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ~~ESP8266EX~~                                                |                                                              | 160       | 0      | 160k    | 0         | 2    | 2    | 1    | 17   | O    | X    | I2S         | 4                                                            | [1688-1](https://detail.1688.com/offer/736387716446.html?spm=a26352.13672862.offerlist.6.7e0c2cf6IMyKoV) |
| ~~ESP8266EX~~                                                | ESP-12F                                                      | 160       | 32M    | 160k    | (32M)     | 2    | 2    | 1    | 9    | O    | X    | I2S         | 5.28                                                         | [1688-1](https://detail.1688.com/offer/521867761713.html?spm=a26352.13672862.offerlist.6.64eeec4fXEQGs6) |
| ESP32（ESP32-D0WD-V3）                                       |                                                              | 240       | 0      | 520k    | 0         | 3    | 4    | 2    | 34   | O    | O    | I2S         | 7.9                                                          | [1688-1](https://detail.1688.com/offer/732047774207.html?spm=a26352.13672862.offerlist.1.1a186e1fiLSUBK) |
| ESP32                                                        | ESP32-S                                                      | 240       | 32M    | 520k    | (32M)     | 3    | 4    | 2    | 34   | O    | O    | I2S         | 9.5                                                          | [1688-1](https://detail.1688.com/offer/596934152703.html?spm=a26352.13672862.offerlist.1.742633caA9Rq8o) |
| ESP32-D0WDQ6                                                 | ~~WROOM-32~~（OutOfDate）                                    | 240       | 4M     | 520k    | (4M)      | 3    | 4    | 2    | 32   | O    | O    | I2S         | 21                                                           | [优信电子](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.6da22e8dCVLMnR&id=724748055478&_u=42d3uchq823c) |
| ESP32-S3                                                     | ESP32-S3(N16R8)                                              | 240       | 16M+8M | 512k    | (16M+8M)  | 3    | 4    | 2    | 36   | O    | O    | USB-OTG/I2S | 22.8<br />[10.6](https://detail.1688.com/offer/696254803943.html?spm=a26352.13672862.offerlist.1.290016ecIhSbjf) | [1688-1](https://detail.1688.com/offer/587736633187.html?spm=a26352.13672862.offerlist.45.3502302dtFm6n4) |
| [ESP32-S2F](https://www.espressif.com/sites/default/files/documentation/esp32-s2_datasheet_cn.pdf) | [S2 Mini V1](https://item.taobao.com/item.htm?abbucket=19&id=681794131086&ns=1&spm=a21n57.1.0.0.1274523cHkaRAL&skuId=5103865706888) | 240       | 4      | 128+320 | 2         |      |      |      |      |      |      |             | [5.5](https://detail.1688.com/offer/776793422030.html?spm=a26352.13672862.offerlist.17.5f5a35765V83mM) |                                                              |
| **ESP32-S3(FN8)**                                            |                                                              |           |        |         |           |      |      |      |      |      |      |             | [8.5-6.5](https://detail.1688.com/offer/776785210662.html?_t=1719909194522&spm=a2615.7691456.co_1_0_wangpu_score_0_0_0_0_0_0_0000_1.0)<br />[11.5](https://detail.1688.com/offer/696027154029.html?_t=1719909462034&spm=a2615.7691456.co_0_0_wangpu_score_0_0_0_0_1_0_0000_0.0) |                                                              |
| **ESP32-S3FH4R2**                                            |                                                              |           |        |         |           |      |      |      |      |      |      |             | [7.91-7.57](https://detail.1688.com/offer/776619534162.html?_t=1719909168990&spm=a2615.7691456.co_1_0_wangpu_score_0_0_0_0_0_0_0000_0.0)<br />[10.6](https://detail.1688.com/offer/696254803943.html?spm=a26352.13672862.offerlist.1.290016ecIhSbjf)<br />[13.15](https://item.taobao.com/item.htm?spm=a21n57.1.item.2.1757523c043RAq&priceTId=214781e717199096724862742eb326&utparam=%7B%22aplus_abtest%22:%2221bc41bcfdfb93a4a46ec0267346a88e%22%7D&id=713738674117&ns=1&abbucket=19&skuId=5260274029787) |                                                              |
| ESP32-S3R8                                                   |                                                              |           |        |         |           |      |      |      |      |      |      |             | [12](https://detail.1688.com/offer/734207473748.html?spm=a26352.13672862.offerlist.1.65324c41E79I2H) |                                                              |
| **ESP32-S2FH4**                                              |                                                              |           |        |         |           |      |      |      |      |      |      |             | [8.19-7.05](https://detail.1688.com/offer/776782666965.html?_t=1719909188634&spm=a2615.7691456.co_1_0_wangpu_score_0_0_0_0_0_0_0000_1.0)<br />[8.74](https://item.taobao.com/item.htm?spm=a21n57.1.item.46.1757523c043RAq&priceTId=214781e717199098481132557eb326&utparam=%7B%22aplus_abtest%22:%22613e4f9ecb2bc4203dcd52bc9bfbd2f0%22%7D&id=674290370662&ns=1&abbucket=19&skuId=5150752566747)<br />[8.35](https://detail.1688.com/offer/734326006071.html?_t=1721119111113&spm=a2615.7691456.co_0_0_wangpu_score_0_0_0_0_1_0_0000_0.0) |                                                              |
| **ESP32-S2FH2**                                              |                                                              |           |        |         |           |      |      |      |      |      |      |             | [5.5-3.5](https://detail.1688.com/offer/776826373278.html?_t=1719909174941&spm=a2615.7691456.co_1_0_wangpu_score_0_0_0_0_0_0_0000_0.0) |                                                              |
| [ESP32-C3FH4](https://www.espressif.com.cn/sites/default/files/documentation/esp32-c3_datasheet_en.pdf) |                                                              |           |        |         |           |      |      |      |      |      |      |             | [6.6](https://detail.tmall.com/item.htm?id=699044301863&ns=1&pisk=gTiShPjZFXnq0MbrWHp45J5lpCrIVXtNN9wKIvIPpuE89qMiO7JHruubOjhbwgJkryFIZuUnzWPzOkMn1KRwbhkoEkqJ_C-wRgt59ue8eyFpp-e3QC-W0EJ-EkqpOtSp7hMo6lVvgWeLHKwUKWIK9aFxHS2Cy6hLwrCYCRqL9XhLk-e3CJQ8JaExHS2NeTEL9-FYKJ1dJ7hKHKwHrBCbL_wqFKvwdRTvW7H8GMIK23471q_FAMG7eziKeSMq3mw7P5UX5fR-fAH-jJiHBwNIL4hznXt6GonSN0UbAHs04AgxNrgWOiamkAmLlqA1SAD-NVUt2n9mOjHiSunJtgPoJxnLg0pFA53ZIowmYIj8Oq3K4zqhwQwjVAiIRgzAb5aKFw6bSMwb_K9f-wxWjvNfiUD1Gze0ehJXhsohsMIMuDJfoQU8n8h2hK1qx&priceTId=213b804917285570529843093e1645&skuId=5076339592482&spm=a21n57.1.item.1.4713523c7Ndpnm&utparam=%7B%22aplus_abtest%22%3A%22a6924f300e2c9ef7759aebceed09d15f%22%7D&xxc=ad_ztc) |                                                              |



## 博通系列

| SOC                                                          | 主频 | FLASH | RAM  | 价格 |
| ------------------------------------------------------------ | ---- | ----- | ---- | ---- |
| BK7231N                                                      | 120M | 4M    | 256k |      |
| [BK7238](https://www.bekencorp.com/index/goods/detail/cid/42.html) | 160M | 2M    | 288k |      |



## Arduino系列（ATmega32系列）

| SOC        | MODULE | 主频(MHz) | FLASH | RAM         | DataFlash   | UART | SPI  | IIC  | I/O  | 其他 | 价格 | 渠道                                                         |
| ---------- | ------ | --------- | ----- | ----------- | ----------- | ---- | ---- | ---- | ---- | ---- | ---- | ------------------------------------------------------------ |
| ATmega32u4 |        | 48        | 32k   | 2560(Bytes) | 1024(bytes) | 1    | 2    | 1    |      | USB  | 18   | [优信电子](https://item.taobao.com/item.htm?abbucket=19&id=673016420638&ns=1&spm=a21n57.1.0.0.3d63523cY982At) |



## STM32 系列

| SOC                                                          | 主频         | FLASH | RAM     | DataFlash | 其他   | 价格                                                         | 渠道                                                         |
| ------------------------------------------------------------ | ------------ | ----- | ------- | --------- | ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| stm32f103c8t6                                                | 72MHz（MAX） | 64k   | 20k     |           |        | 5.5                                                          | [1688-1](https://detail.1688.com/offer/44298483616.html?spm=a26352.13672862.offerlist.20.37511e62QiXBhU) |
| stm32f031K6U6                                                | 48MHz        | 32k   | 4KBytes |           |        | 2.39                                                         | [深圳市义胜电子网](https://item.taobao.com/item.htm?id=674309147831&skuId=4851113585535&spm=a1z10.3-c-s.w4002-21047669632.17.708f27e556W3yu) |
| [stm32f030](file:///Users/fuhuaqian/Downloads/stm32f030f4.pdf) | 48MHz        | 16k   | 4k      |           | NO-USB | [3.72~2.26](https://item.szlcsc.com/90220.html?fromZone=l_c__%2522catalog%2522) |                                                              |



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



## NRF系列

| SOC      | BOARD | 主频   | FLASH | RAM   | DataFlash | 价格  | 渠道                                                         | 其他 |
| -------- | ----- | ------ | ----- | ----- | --------- | ----- | ------------------------------------------------------------ | ---- |
| NRF52810 |       | 64 MHz | 192k  | 24K   |           | 2.49  | [淘宝](https://item.taobao.com/item.htm?abbucket=19&id=661903965920&ns=1&priceTId=2150418117168866079921002eb0c0&spm=a21n57.1.item.47.3e2e523ciraGIb&skuId=4944997766993) |      |
| nRF52840 |       | 64 MHz | 1M    | 256KB |           | 5～18 | [淘宝](https://item.taobao.com/item.htm?id=661903965920&skuId=4944997766999&spm=a1z10.3-c-s.w4002-21047669632.9.4aea27e5MQice1)<br />[1688](https://shop583v9w383o857.1688.com/page/offerlist_185921609.htm?spm=a261y.25179003.13772573013170.2.30d76f844ZvDw5&sortType=wangpu_score) | NFC  |

