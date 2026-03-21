> 参考资料：
>
> - https://vorondesign.com/voron2.4：官网
> - [VoronDesign](https://github.com/VoronDesign)/[Voron-2](https://github.com/VoronDesign/Voron-2)：Voron 2.4 CAD 模型
> - [VoronDesign](https://github.com/VoronDesign)/[Voron-Documentation](https://github.com/VoronDesign/Voron-Documentation)：Voron 文档源码
>   - https://docs.vorondesign.com/：网页
>   - https://docs.vorondesign.com/hardware.html：硬件版本型号
>   - https://vorondesign.com/voron0.2：V0 的 Bom 表。所有 Bom 表都是通过网站生成的。
>     - https://docs.vorondesign.com/materials.html：材料指南
>     - https://pif.voron.dev/：前置打印，网站上没有中国区
>     - [3D打印机配件之紧固件-voron2.4](https://zhuanlan.zhihu.com/p/474112133)：知乎中文版紧固件说明。
>   - https://docs.vorondesign.com/build/：构建指南
> - [VoronDesign](https://github.com/VoronDesign)/[Voron-Hardware](https://github.com/VoronDesign/Voron-Hardware)：硬件电路

# Voron

## 版本型号简记

- [Voron Zero](https://docs.vorondesign.com/hardware.html#voron-zero)：\$400～\$600，前置打印成本在 80USD（约566RMB）
- [Voron 2](https://docs.vorondesign.com/hardware.html#voron-2)：\$1,500 - \$1,900，前置打印成本在 110USD（约779RMB）



## Voron 0 BOM 表翻译

| Bill of Materials（BOM）             | 材料清单                                                     |           |
| ------------------------------------ | ------------------------------------------------------------ | --------- |
| **类别（Category）:**                | **描述（Part Description）:**                                | **数量:** |
| 紧固件（Fasteners）                  | 列举的数量是最低需要，请多购买一些冗余。                     |           |
|                                      | [Makerbeam XL M3 t-nut](https://www.makerbeam.com/t-slot-nuts-for-makerbeamxl-50p.html) [[tb]](https://item.taobao.com/item.htm?abbucket=13&id=703965339772&mi_id=0000WEeMyS1G2MEZDNG_8SH7zjYVmngM54F8tA0BOs_IzAQ&ns=1&priceTId=213e090117646454777657202e18c0&skuId=4951815556057&spm=a21n57.1.hoverItem.36&utparam=%7B%22aplus_abtest%22%3A%2274b81125ed7f230255c4da1776b49b9f%22%7D&xxc=taobaoSearch) | 2         |
|                                      | M3x8 平头螺丝（FHCS）                                        | 5         |
|                                      | M3x8 圆头螺丝（BHCS）                                        | 115       |
|                                      | M3x6 圆头螺丝（BHCS）                                        | 40        |
|                                      | M3x40 圆头螺丝（BHCS）                                       | 10        |
|                                      | M3x35 圆头螺丝（BHCS）                                       | 30        |
|                                      | M3x30 圆头螺丝（BHCS）                                       | 10        |
|                                      | M3x25 圆头螺丝（BHCS）                                       | 10        |
|                                      | M3x16 圆头螺丝（BHCS）                                       | 10        |
|                                      | M3x12 圆头螺丝（BHCS）                                       | 25        |
|                                      | M3x10 圆头螺丝（BHCS）                                       | 50        |
|                                      | M3 螺母（Nut）                                               | 140       |
|                                      | M3 黄铜螺母（Brass heatstake inserts） - short M3x5x4        | 50        |
|                                      | M2x8 圆柱头螺丝（SHCS）                                      | 10        |
|                                      | M2x6 圆柱头螺丝（SHCS）                                      | 70        |
|                                      | M2x6 平头螺丝（FHCS）                                        | 10        |
|                                      | M2x10 自攻螺丝（Self Tapping Screws） for Plastic            | 30        |
|                                      | M2 螺母（Nut）                                               | 55        |
|                                      | 3x6x0.5 垫片垫圈（Shim Washer）                              | 50        |
| 框架结构（Frame）                    |                                                              |           |
|                                      | 铝型材 [Makerbeam XL 15x15 200mm](https://www.makerbeam.com/makerbeamxl/) | 16        |
|                                      | 铝型材 Makerbeam XL 15x15 100mm                              | 3         |
| 顶部框架？（Extrusion Tophat Frame） |                                                              |           |
|                                      | 铝型材 Makerbeam XL 15x15 80-100mm                           | 4         |
|                                      | 铝型材 Makerbeam XL 15x15 200mm                              | 4         |
| 电子元件（Electronics）              |                                                              |           |
|                                      | V0-Display                                                   | 1         |
|                                      | Raspberry Pi 3                                               | 1         |
|                                      | 欧姆龙鼠标按键（Omron Mouse Button - Micro Switch）          | 2         |
|                                      | 步进电机<br />[NEMA17 Stepper Motor w/ integrated lead screw 200mm T8x8](https://www.amazon.com/Nema17-Stepper-28N-CM-17HS3401S-T8-3401S-T8x8-200mm/dp/B0DF4V4KH2?th=1) | 1         |
|                                      | 步进电机<br />NEMA14 Stepper Motor 40Ncm                     | 2         |
|                                      | MicroSD Card                                                 | 1         |
|                                      | 24V电源（[Meanwell LRS-150-24](https://www.meanwell.com/Upload/PDF/LRS-150/LRS-150-SPEC.PDF)） | 1         |
|                                      | 品字插座带开关<br />IEC320 C14 inlet                         | 1         |
|                                      | 热敏电阻<br />Hotend thermistor                              | 1         |
|                                      | <u>Hotend</u>                                                | 1         |
|                                      | 管压配接头<br />[ECAS04 Bowden Fitting](https://infinityflow3d.com/products/bowden-tube-press-fit-fitting-ecas04?srsltid=AfmBOooBBHYkLyF44_-9peJyP6TkCFFS1aM4LfXa9aMBHkEHi2Lrrufj) | 1         |
|                                      | 品子接头对接（延长）线<br />C13 Power Cord                   | 1         |
|                                      | 主控拓展板<br />Bigtreetech SKR Pico                         | 1         |
|                                      | [3M 5952 VHB tape](https://www.3m.com.cn/3M/zh_CN/p/d/b40065688/) | 1         |
|                                      | [3010 鼓风机（blower fans） 24V](https://www.sugoi3d.jp/shop/p/3010-fan-for-new-mini-stealthburner-v02-h4jc9) | 2         |
|                                      | [3010 轴流风扇（axial fan） 24V](https://www.amazon.co.jp/YOUCHLAN-%E5%A3%B2%E5%BA%97-%E3%83%97%E3%83%AA%E3%83%B3%E3%82%BF%E3%83%95%E3%82%A1%E3%83%B3-Hotend-%E3%83%97%E3%83%AA%E3%83%B3%E3%82%BF%E3%82%A2%E3%82%AF%E3%82%BB%E3%82%B5%E3%83%AA%E3%83%BC/dp/B0CYC3ZJQ7?th=1) | 2         |
|                                      | 加热棒<br />24V Heater Cartridge                             | 1         |
| 电缆线（Cables）                     |                                                              |           |
|                                      | 电线 18AWG 3米<br />Wire 18gauge 10ft                        | 1         |
|                                      | 陶瓷热熔断器（Thermal Fuse） 150C                            | 1         |
|                                      | 尼龙扎带（Nylon Cable Ties） (1.8mm wide or smaller)         | 50        |
|                                      | Micro-Fit(MX 3.0) 直角插头 10pin<br />Microfit3 Dual Row (10circuits) Male & Female Plug | 1         |
|                                      | XH 连接件<br />JST connectors (2pin 3pin 4pin)               | ?         |
|                                      | <u>Insulated Crimp Receptical</u>                            | 4         |
|                                      | 22AWG 高挠性电线 30米<br />High Flex Wire 22gauge 100ft      | 1         |
|                                      | 22AWG 高挠性电线 3米<br />High Flex Wire 20gauge 10ft        | 1         |
|                                      | 电缆绳链（锚链）<br />7mm x 7mm cable chain (less than 1/2 meter needed) | 1         |
| 转动机械（Motion）                   |                                                              |           |
|                                      | 防回隙法兰螺母？<br /><u>T8x8 Anti-backlash Flange Nut</u>   | 1         |
|                                      | 线性滑轨<br />MGN7H Linear Rail with Carriage - 150mm        | 5         |
|                                      | 同步带<br />GT2 Open Belt (6mm W) - 3000mm                   | 1         |
|                                      | 同步齿轮<br />GT2 20T (5mm ID 6mm W)                         | 2         |
|                                      | 轴承<br />F623-RS Bearing                                    | 24        |
| 打印底板（Buildplate）               |                                                              |           |
|                                      | 黄色压模压缩弹簧<br />[yellow die springs 8x4x20mm](https://kb-3d.com/store/hardware/254-yellow-die-compression-spring-8x4x20mm-set-of-4-1634424375018.html) | 3         |
|                                      | 柔性构建板 PEI 片<br />[Spring Steel Flex Buildplate 120x120mm](https://www.amazon.com/Spring-Flexible-120x120mm-Printer-Heated/dp/B0D6SGYJG5) (OPTIONAL) | 1         |
|                                      | [Silicone DC 24V Heater](https://www.amazon.co.jp/-/en/Silicone-200x200mm-Accessory-Electronic-Components/dp/B0C1F19P1R) 100x100mm 60W | 1         |
|                                      | [PEI + 3M 468MP](https://www.amazon.co.jp/ULTEM1000-468MP-%E7%B2%98%E7%9D%80%E3%83%86%E3%83%BC%E3%83%97%E3%81%8C%E4%BB%98%E3%81%84%E3%81%A6%E3%81%84%E3%82%8B-%E3%83%97%E3%83%AA%E3%83%B3%E3%82%BF%E3%81%AE%E6%A7%8B%E7%AF%89%E8%A1%A8%E9%9D%A2-%E7%89%B9%E5%BE%B4%E7%9A%84%E3%81%AA/dp/B0CH7TNFGG) (200MP) | 1         |
|                                      | 弹簧钢构造板<br />[Magnetic sheet for spring steel plate](https://www.amazon.co.jp/Magnetic-Flexible-Printing-Adhesive-Compatible/dp/B0F672YG17?th=1) 120x120 (OPTIONAL) | 1         |
|                                      | 铝板？<br /><u>MIC6 1/4" Plate - 120x120mm</u>               | 1         |
| 面板（Panels）                       |                                                              |           |
|                                      | 上后方面板（Upper Rear Panel） 212x63x3mm                    | 1         |
|                                      | 电机面板（Motor Panel） 3mm thick (See DXF)                  | 1         |
|                                      | 中部面板（Mid Panel） 3mm thick (See DXF)                    | 1         |
|                                      | 下后方面板（Lower Rear Panel） 212x185x3mm                   | 1         |
|                                      | 甲板面板（Deck Panel） 3mm thick (See DXF)                   | 1         |
|                                      | 底部面板（Bottom Panel） 3mm thick (See DXF)                 | 1         |
|                                      | 丙烯酸片材（Acrylic Sheet Clear） (sides) - 212x230x3mm      | 2         |
|                                      | 丙烯酸片材（Acrylic Sheet Clear） (door) - 212x239x3mm       | 1         |
| Bowden                               |                                                              |           |
|                                      | 鲍登管（Bowden Tube） 4x2mm - 1m                             | 1         |
|                                      | 鲍登配件（Bowden Fitting）                                   | 2         |
| Misc.                                |                                                              |           |
|                                      | 中等强度锁线器<br />Medium Strength Thread Locker            | 1         |
|                                      | 小橡胶脚<br />Little Rubber Feet                             | 4         |
|                                      | Bowden Tube 4x3mm - 1m                                       | 1         |
|                                      | 圆形钕磁铁<br />6mm x 3mm Round Neodymium Magnets            | 8         |
| Extrusion Tophat Panels              |                                                              |           |
|                                      | Top Panel 212x212mm                                          | 1         |
|                                      | Side Panels 212x(71-91)mm                                    | 4         |
| 挤出机（Extruder）                   |                                                              |           |
|                                      | [NEMA14 36mm pancake Motor with 10 tooth gear](https://sparta3d.ca/products/ldo-nema14-36mm-pancake-stepper-motor) | 1         |
|                                      | [MR85 Bearing](https://jp.misumi-ec.com/vona2/detail/221000528976/?HissuCode=MR85) | 3         |
|                                      | [Bondtech BMG Extruder Kit](https://www.amazon.com/-/zh/dp/B07DGL43SQ/ref=sr_1_2?dib=eyJ2IjoiMSJ9.dxHjHp7zopozaBDjyLpExOXivloB1sruQyIcQvE7KObDt5UgHbVv07xM6U_a4XivSTA_f5WO8BQTzuCOh4VIHxDSBRpfYp3vimgnK03vlWZAwP3sKeXhAEz5CogWLOjcD3r-rOwp177faL8g0tCwlZ-Rz-55yYP80k6MvYzeET4Dh5McUV_jpzXaybPNUakESF6BayALzRq9-GdRA_v28RmsocZSmTA71ooVBhdhHUY._YDz-OIGyRoNA_Y6VBrnPrEbgMmNup8bcdTOy_qzrBA&dib_tag=se&keywords=bondtech+bmg+extruder+kit&qid=1764654250&sr=8-2) | 1         |
