# MOS管

**01 如何确定 MOS 管沟道？**

![](https://electronicsarea.com/wp-content/uploads/symbols-nmos-pmos-transistor.png)

如图，箭头指向一定是从P指向N，因此，若箭头指向沟道，则为N沟道，反之则为P沟道。



**02 如何确定 增强型MOS 工作电压？**

如图，n沟道的槽为P基底，需要正电压形成场导通。p沟道槽为N基底，因此需要负电压形成场导通。这个方向和箭头指向是一致的。



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

