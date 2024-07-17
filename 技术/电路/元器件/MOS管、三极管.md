# MOS管

**01 如何确定 MOS 管沟道？**

![](https://electronicsarea.com/wp-content/uploads/symbols-nmos-pmos-transistor.png)

如图，箭头指向一定是从P指向N，因此，若箭头指向沟道，则为N沟道，反之则为P沟道。



**02 如何确定 增强型MOS 工作电压？**

如图，n沟道的槽为P基底，需要正电压形成场导通。p沟道槽为N基底，因此需要负电压形成场导通。这个方向和箭头指向是一致的。



03 三极管参数

**hFE = Ic/Ib**



## [双向导通逻辑转换器（Bi-directional logic level shifter）](http://www.penguintutor.com/electronics/mosfet-levelshift)

![](http://www.penguintutor.com/electronics/images/bidirect-mosfet.png)

| LV   | HV   | MOS                    |
| ---- | ---- | ---------------------- |
| -    | -    | OFF                    |
| HIGH | -    | OFF                    |
| HIGH | HIGH | OFF                    |
| LOW  | -    | ON                     |
| LOW  | HIGH | ON*                    |
| -    | LOW  | ON（结型场效应管导通） |
| HIGH | LOW  | OFF                    |
| LOW  | LOW  | ON                     |



## 器件整理

| 型号                                                | 类型 | hFE                             | Ic/Id | 备注 | 价格 |
| --------------------------------------------------- | ---- | ------------------------------- | ----- | ----- | ----- |
| [MMBT3904-1AM](https://item.szlcsc.com/338622.html) | NPN  | 30 ~ 300                        | 200mA |  |  |
| [SS8050](https://item.szlcsc.com/2507.html)         | NPN  | 100mA：120 ~ 400<br />800mA：40 | 1.5A  |   |   |
| [S9013](https://item.szlcsc.com/16748.html)         | NPN  | 60uA - 10mA<br />120uA - 20mA<br />180uA - 33mA<br />240uA - 44mA<br />300uA - 55mA<br />360uA - 66mA<br />hFE: 64 - 260 | 500mA | 大电流会发热 |  |
| AP30H50Q | NMOS | - | 40A |  | [0.37](https://item.szlcsc.com/3049185.html?fromZone=s) |

