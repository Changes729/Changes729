> 参考资料：
>
> - [【MOS管】防反接电路](https://www.bilibili.com/video/BV1tY4y1P7Kp)：二极管防反接、P沟道MOS管防反接、N沟道MOS管防反接（NCE4060K）
> - [安规电容（X/Y电容）](https://zhuanlan.zhihu.com/p/350438523)
> - 氮化镓方案
> - [555芯片 - 自制无线充电 收发电路](https://www.bilibili.com/video/BV1qR4y1E7jn/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：介绍了直流电变交流电LC协振方案，以及整流桥的交流电转直流电方案。

# 电源

## 电池

- [聚合物锂电池](https://en.wikipedia.org/wiki/Lithium-ion_battery#Safety)：[爆炸实验](https://www.youtube.com/watch?v=eZxDC-whz14)
  
  > 供应商：
  >
  > - [裕辉达玩具电池配件商](https://shop505073405.taobao.com/)
  > - [洛其新能源](https://item.taobao.com/item.htm?spm=a230r.1.14.39.52fb5825d22anJ&id=528453120288&ns=1&abbucket=7#detail)
  > - [广州市莱悦电子科技](https://shop126557863.taobao.com/)
  
  聚合物锂电池的内阻低，质量轻，深受航模、小型电子产品所喜爱。然而，其因穿刺、弯折、过充放电会导致电池鼓包，严重的会导致燃烧。
  
  安全工作电压范围在 3.3v ~ 4.2v 之间。充电会充到 3.8v 进行保存。
  
  标准充电方法：0.5C CC（恒流）充电至4.25V，再CV（恒压4.2V）充电直至充电电流≤0.05C
  



## 无线充电

- [XKT-412/XKT-335/XKT-001](https://cb-electronics.com/products/xkt-335/)



## 智能插座（可控电源）

### 公牛

### gosund（小米供应链）

### 华为（正泰代工）

### 向日葵



## 器件整理

芯片供应商：

- [矽力杰](https://www.silergy.com/list/174)
- [TI（德州仪器）](https://www.ti.com.cn/zh-cn/power-management/dcdc-power-modules/products.html)
  - [AC/DC 和 DC/DC 转换器（集成 FET）](https://www.ti.com.cn/zh-cn/power-management/acdc-dcdc-converters/products.html#451max=3.2%3B40&238max=10%3B450&sort=1130;asc&)
  - [Webench power designer](https://webench.ti.com/power-designer/)

| 芯片                                                         | 推荐                                                         | 输入      | 输出          | 电流           | 工作温度 | 结温                   | 工作效率 | 体积 | 价格                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------- | ------------- | -------------- | -------- | ---------------------- | -------- | ---- | ------------------------------------------------------------ |
| TPS63070                                                     |                                                              | 2～16V    | 2.5～9V       | 2A             |          |                        |          |      | [4~2.1](https://item.szlcsc.com/110543.html?fromZone=s_s__%2522TPS63070%2522) |
| ZXDN16S1205                                                  |                                                              | 8～40V    |               |                |          |                        |          |      |                                                              |
| [NAE12S17-B](https://www.bilibili.com/video/BV1qw411m7Qw/?spm_id_from=333.999.0.0&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab) | *                                                            | 3～14V    | 0.6～5.5V     | 17A            |          |                        |          |      |                                                              |
| [SY8368AQQC](https://wmsc.lcsc.com/wmsc/upload/file/pdf/v2/lcsc/2302161530_Silergy-Corp-SY8368AQQC_C207642.pdf) |                                                              | 4~28V     |               | 8A（16A Peak） | -40~125  | 30°C/W                 | 90%      |      | [1.69](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.7a4c2e8d3XagKN&id=714347899055&_u=t2d3uchq401d) |
| [TLVM13610](https://www.ti.com.cn/cn/lit/ds/symlink/tlvm13610.pdf?ts=1716503317726&ref_url=https%253A%252F%252Fwww.ti.com.cn%252Fzh-cn%252Fpower-management%252Fdcdc-power-modules%252Fproducts.html) |                                                              | 3～36V    | 1～10v        | 8A             | -40~125  | 18.2°C/W               | 90%      |      |                                                              |
| [TPSM8683x](https://www.ti.com.cn/cn/lit/ds/symlink/tpsm86837.pdf?ts=1716521363506) |                                                              | 4.5~28V   | 0.6~5.5V      | 8A             | -40~150  |                        | 90%      |      |                                                              |
| [TPSM63610](https://www.ti.com.cn/cn/lit/ds/symlink/tpsm63610.pdf?ts=1716521368397) |                                                              | 3~36V     | 1~20V         | 8A             | -40~105  | 18.2°C/W               | 90%      |      |                                                              |
| [LMZ13608](https://www.ti.com.cn/cn/lit/ds/symlink/lmz13608.pdf?ts=1716521371234) |                                                              | 6~36V     | 0.8~6V        | 8A             | -40~125  |                        | 80%      |      |                                                              |
| [**LM2596S**](https://item.szlcsc.com/324081.html?kw=LM2596&fromZone=s) |                                                              | ~40V      | 1.2~37V       | 3A             |          |                        | 80%      |      |                                                              |
| [TPS51397ARJER](https://item.szlcsc.com/1609551.html?kw=TPS51397A&fromZone=s) |                                                              | 4.5V~24V  | 5V            | 10A            | -40~150  | ?                      | 90%      |      |                                                              |
| [TLVM13640](https://www.ti.com.cn/product/cn/TLVM13640)      |                                                              | 3～36V    | 1~6V          | 4A             | -40~125  | 12.3°C/W               | 93%      |      |                                                              |
| [TLVM13630](https://www.ti.com.cn/cn/lit/ds/symlink/tlvm13630.pdf?ts=1716902256903&ref_url=https%253A%252F%252Fwww.ti.com.cn%252Fzh-cn%252Fpower-management%252Fdcdc-power-modules%252Fproducts.html) |                                                              | 3～36V    | 1~6V          | 3A             | -40~125  | 21.5°C/W               | 90%      |      |                                                              |
| [TPS5430DDAR](https://item.szlcsc.com/10396.html)            |                                                              | 5.5V~36V  | 1.221V~32.04V | 3A             | -40~125  | TOP: 46                | 90%      |      | [1.5](https://item.szlcsc.com/10396.html?fromZone=s)         |
| [TPS54360B](https://www.ti.com/product/TPS54360B)            |                                                              | 4.5V~60V  | 800mV~58.8V   | 3.5A           | -40~150  | TOP: 45                | 80%      |      |                                                              |
| [RT7272BGSP](https://item.szlcsc.com/139149.html?fromZone=s) |                                                              | 4.5V~36V  | 800mV~30V     | 3A             | −40~125  | TOP: 49                | 80%      |      |                                                              |
| [**LM60440AQRPKRQ1**](https://item.szlcsc.com/3749923.html?fromZone=s) | [PDF](https://www.ti.com/lit/ds/symlink/lm60440-q1.pdf?ts=1716971819221&ref_url=https%253A%252F%252Fwww.google.com%252F) | 3.8V~36V  | 1V~24V        | 4A             | -40~150  | TOP：37.8              | 90%      | 3*2  | [7.5](https://detail.1688.com/offer/770149082150.html?spm=a26352.13672862.offerlist.6.4a61ea97F0p9hl)<br />25 |
| [AOZ1284PI](https://item.szlcsc.com/49067.html?fromZone=s)   |                                                              | 3V~36V    | 800mV~30.6V   | 4A             | -40~85   | 50                     | 85%      |      |                                                              |
| [LMR33640DDDAR](https://item.szlcsc.com/1942967.html?fromZone=s) |                                                              | 3.8V~36V  | 1V~24V        | 4A             | -40~125  | TOP：54                | 90%      |      | 5.5                                                          |
| [BTT3050EJXUMA1](https://item.szlcsc.com/18378931.html?fromZone=s) |                                                              | 6V~36V    |               | 4A             | -40~150  |                        |          |      |                                                              |
| [CN3903](http://www.dcx-ic.com/public/static/uploads/file/20231010/20231010110029_3509.pdf) |                                                              | 4.5~36V   |               | 3A             | -40~125  | TOP: 52                |          |      | [0.6](https://item.taobao.com/item.htm?abbucket=19&id=749595907741&ns=1&priceTId=214782e917169765028664471e1983&spm=a21n57.1.item.4.16d4523cRc2COy) |
| [TPS54531](https://www.ti.com.cn/product/cn/TPS54531)        | *                                                            | 3.5~28V   | 0.8~26V       | 5A             | -40~150  | TOP：63                | 87%      |      | [1.3](https://item.szlcsc.com/51615.html?fromZone=s)         |
| [TPS56637](https://www.ti.com.cn/cn/lit/ds/symlink/tps56637.pdf?ts=1717129130618&ref_url=https%253A%252F%252Fwww.ti.com.cn%252Fzh-cn%252Fpower-management%252Facdc-dcdc-converters%252Fproducts.html) | *                                                            | 4.5~28V   | 0.6~13V       | 6A             | -40~150  | TOP：28.8<br />MAX：49 | 90%      |      | [4.4](https://item.szlcsc.com/899225.html?fromZone=s)        |
| [LMR51440](https://www.ti.com.cn/cn/lit/ds/symlink/lmr51450.pdf?ts=1717129140999&ref_url=https%253A%252F%252Fwww.ti.com.cn%252Fzh-cn%252Fpower-management%252Facdc-dcdc-converters%252Fproducts.html) |                                                              | 4~36V     |               | 4A             | -40~150  | TOP: 44                | 90%      |      | [15](https://item.szlcsc.com/7233594.html?fromZone=s)        |
| [TPS62740DSSR](https://www.ti.com/lit/ds/slvsb02b/slvsb02b.pdf) |                                                              | 2.2~5.5V  | 1.8~3.3V      | 300mA          |          |                        |          |      | [2](https://item.szlcsc.com/139891.html)                     |
| [TPS62840DLCR](https://www.ti.com/lit/ds/symlink/tps62840.pdf?ts=1716969262186&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252Fde-de%252FTPS62840%252Fpart-details%252FTPS62840YBGR) |                                                              | 1.8~6.5V  | 1.8~3.3V      | 750mA          |          |                        |          |      | [5](https://item.szlcsc.com/2163442.html)                    |
| TPS62743YFPR                                                 |                                                              | 2.15~5.5V | 1.2~3.3V      | 300mA          |          |                        |          |      | [1.5](https://item.szlcsc.com/346259.html)                   |
| TPS62840YBGR                                                 |                                                              | 1.8~6.5V  | 1.8~3.3V      | 750mA          |          |                        |          |      | 5                                                            |
| TLV70433DBVR                                                 |                                                              | 24V       | 3.3V          | 150mA          |          |                        |          |      | [0.5](https://item.szlcsc.com/96117.html?fromZone=s)         |
| [TPS7A05](https://www.ti.com/lit/ds/symlink/tps7a05.pdf?ts=1717041613188&ref_url=https%253A%252F%252Fwww.ti.com%252Fpower-management%252Flinear-regulators-ldo%252Fproducts.html) |                                                              | 1.4~5.5V  | 0.8~3.3V      | 200mA          |          |                        |          |      | [2](https://item.szlcsc.com/3073247.html?fromZone=s)<br />[1](https://item.szlcsc.com/3086533.html?fromZone=s) |
| [TPS7A20](https://www.ti.com/product/TPS7A20)                | *                                                            | 1.6~6V    | 0.8~5.5V      | 300mA          |          |                        |          |      | [1.1](https://item.szlcsc.com/3076318.html?fromZone=s)       |
| SPX3819M5-L-3-3/TR                                           | *                                                            | 16V       | 3.3V          | 500mA          |          |                        |          |      | [1~0.6](https://item.szlcsc.com/9575.html?fromZone=l_c__%2522catalog%2522) |

### 热功耗计算方式

导通损耗：$$P_{con} = I_{out}^2 \times R_{ds}(on) \times V_{OUT}/V_{IN}$$

开关损耗：$$P_{sw} = V_{IN}\times I_{out} \times f_{SW} \times t_{rise}$$

静态电流损耗：$$P_{q} =  V_{IN} * I_{Q}$$

总损耗：$$P_{tot} = P_{con} + P_{sw} + P_{q} $$

```sh
# TPS5430DDAR 
假设输出电流 3A，5V，输入24V，效率90%，电流0.7A。
导通损耗：3*3*0.15*5/24 = 0.28W
开关损耗：24 * 3 * 0.01 = 0.72W
静态电流损耗：0.7*0.01 = 0.007W
总损耗：1.0007W，

# SY8368A（MAX）
输出 5V*8A = 40W，效率85%计算，损耗：7W

# SY8368A（NORMAL）
3W损耗，90%效率计算，输出27W，5V，5.4A

# TPS54531
Pcon = 4*4*0.12*5/24 = 0.4W
Psw = 0.5*10e-9*24*24*4*570*10e3 = 0.656W
Pgc = 22.8*10e-9*570*10e3 = 0.013W
Pq = 0.11 * 10e-3 * 24 = 0.0026W
P = 1.071W
T = 40 + 1 * 63 = 103

# TPS56637
Pcon = 6*6*0.038*5/24 = 0.285
Psw = 
```



## 电池芯片

> [充电电流 1C 的含义](https://blog.csdn.net/Fwuyi/article/details/123893272)：某只电池标称容量1200mAh，0.2C放电电流为240mA（充电时间5h），1C表示1200mA（充电时间1h）。

| TYPE                                                         | Vin  | PDF                                            | 充电电流 | S    | 价格                                                         |
| ------------------------------------------------------------ | ---- | ---------------------------------------------- | -------- | ---- | ------------------------------------------------------------ |
| [BQ25100YFPR](https://www.ti.com/lit/ds/symlink/bq25100a.pdf?ts=1716970743104&ref_url=https%253A%252F%252Fwww.google.com%252F)\BQ25101YFPR | 30V  | [bq2510x](https://www.ti.com/lit/gpn/BQ25100A) | 250mA    | 1    | [6.7](https://item.szlcsc.com/545868.html?fromZone=s)<br />[2.5](https://detail.1688.com/offer/735921047556.html?spm=a26352.13672862.offerlist.1.2db31e62Ksy808) |

