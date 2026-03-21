# 电子骰子

## 基本流程

```sequence
Title: 电子骰子交互流程
Application->dice: 设置骰子初始化
Note right of dice: 骰子等待静止
dice->Application: Ready 信号
dice->Application: Roll 信号
dice->Application: Standby 信号
```





## 初版本

- [9000mAh，5v TypeC](https://item.taobao.com/item.htm?ali_refid=a3_420434_1006%3A1682230219%3AH%3AR%2BkS1ArVtGY%2BPEwmCLn02Q%3D%3D%3A42c65fa88ac81653d580531c6c008f8c&ali_trackid=282_42c65fa88ac81653d580531c6c008f8c&id=733234510026&mi_id=000092zdJy8Q3txiVY6i7NvkkYQoajY26jNyWtTfdRuLLz0&mm_sceneid=1_0_4876029901_0&priceTId=213e0a5417626666206041863e106d&skuId=5075746481517&spm=a21n57.1.hoverItem.3&utparam=%7B%22aplus_abtest%22%3A%22ba258fcd4ff9e30a4b13b9262fd4d022%22%7D&xxc=ad_ztc)：或者 4000mAh 仍选。
- [ICM-42688-P](https://item.taobao.com/item.htm?spm=tbpc.boughtlist.suborder_itemtitle.1.4e812e8dvBLYuh&id=709614700649&mi_id=0000f_0ExcD41F1_Z_AvfXpb0lLL1C19jfLE0Q9Csbme4Qo)：SPI可用，库需要修改符号。
- ESP32-S2



## 技术方案

- mDNS
- UDP