> 参考资料：
>
> - [[Wiki] 射频识别](https://zh.wikipedia.org/wiki/%E5%B0%84%E9%A2%91%E8%AF%86%E5%88%AB)：[En](https://en.wikipedia.org/wiki/Radio-frequency_identification)
> - [RFID Technology: A Complete Overview](https://www.electronicsforu.com/technology-trends/rfid-technology-complete-overview)
> - [NXP NFC](https://www.nxp.com.cn/products/rfid-nfc:RFID-NFC)
> - [HFSS、CST、FEKO、ADS，微波仿真软件用哪个？](https://www.bilibili.com/read/cv11820471)
>   - [天线仿真软件哪个好？例如HFSS？](https://www.zhihu.com/question/29506002)
>   - [天线HFSS、CST仿真设计为什么不靠谱？](http://www.360doc.com/content/19/1117/18/36367108_873757028.shtml)
> - [[PDF] MFRC522](https://www.nxp.com.cn/docs/en/data-sheet/MFRC522.pdf)
> - [RAIN RFID and NFC Tag Design](https://voyantic.com/rfid-tag-design/)
> - [[Wiki] NFC](https://en.wikipedia.org/wiki/Near-field_communication)
> - [miguelbalboa](https://github.com/miguelbalboa)/**[rfid](https://github.com/miguelbalboa/rfid)**
> - [爱采购](https://b2b.baidu.com/s?q=MFRC522&from=search&fid=67174400%2C1651636003010&pi=b2b.s.search...273966187815426)、[淘宝网](https://item.taobao.com/item.htm?spm=a230r.1.14.219.40f637a7fru8m4&id=658178661866&ns=1&abbucket=14#detail)
> - [don](https://github.com/don)/[**NDEF**](https://github.com/don/NDEF)
> - [Android/NFC](https://developer.android.com/guide/topics/connectivity/nfc)：看 ST 文档，Android 是同时支持ISO 14443 和 ISO 15693 的。
> - [cbm80amiga](https://github.com/cbm80amiga)/[RFID_Scanner_OLED](https://github.com/cbm80amiga/RFID_Scanner_OLED)
> - [NFC Forum](http://www.nfc-forum.org/)
> - [稚晖君 NFC Card](https://github.com/peng-zhihui/L-ink_Card)
> - [【IoT】加密与安全：NFC 读写 IC 卡以及密码安全验证](https://blog.51cto.com/u_15284384/3050927)
> - [How to design an antenna for dynamic NFC tags](https://www.st.com/resource/en/application_note/cd00232630-how-to-design-an-antenna-for-dynamic-nfc-tags-stmicroelectronics.pdf)
> - [微雪 NFC PN532](https://item.jd.com/65256486831.html)
>   - [Yinke7](https://github.com/Yinke7)/[PN532](https://github.com/Yinke7/PN532)
> - [UID 芯片](https://item.taobao.com/item.htm?spm=a230r.1.14.46.bd1f3907pObgDv&id=612544062808&ns=1&abbucket=11#detail)
> - [NFC读卡器](https://www.nxp.com.cn/products/rfid-nfc/nfc-hf/nfc-readers:NFC-READER)
> - [ST NFC/RFID product presentation](https://www.st.com/content/ccc/resource/sales_and_marketing/presentation/product_presentation/group1/a9/5d/77/96/be/9a/48/7e/ST25_NFC_RFID_product_overview/files/ST25_product_overview.pdf/jcr:content/translations/en.ST25_product_overview.pdf)
>   - [ST25 product overview](https://www.st.com/content/ccc/resource/sales_and_marketing/presentation/product_presentation/group0/fd/7f/ea/d5/2b/b2/4b/d6/ST25R95_product_presentation_jan2019/files/ST25R95product_presentation-Jan2019.pdf/jcr:content/translations/en.ST25R95product_presentation-Jan2019.pdf)：ST25R95 文档里说是支持 ISO 15693 模拟的。但是产品描述中又说只支持 ISO14443 TypeA 的模拟。
> - [What Is the Difference Between ISO 15693 and ISO 14443A Tags?](https://www.rfidjournal.com/question/what-is-the-difference-between-iso-15693-and-iso-14443a-tags)：ISO 14443 是被设计在金融行业的，传输距离短，速度快。而 ISO 15693 是被设计用来做访问控制的，其标签读取距离很长，但速度慢。
> - [RfidResearchGroup](https://github.com/RfidResearchGroup)/**[proxmark3](https://github.com/RfidResearchGroup/proxmark3)**
> - [[知乎] 详谈Mifare Classic 1K卡](https://zhuanlan.zhihu.com/p/67532665)：介绍了 Mifare 卡，其作用和破解原理。
> - [[PDF] Mifare Standard Card IC](https://d1.amobbs.com/bbs_upload782111/files_45/ourdev_672290CL1VWC.pdf)

# RFID/NFC

## RFID 是怎么工作的？（原理讲解）

### [电磁感应](https://zh.wikipedia.org/wiki/%E7%94%B5%E7%A3%81%E6%84%9F%E5%BA%94) - 互感现象 - 信号与系统 - [电磁场与电磁波]([电磁场与电磁波](https://www.icourse163.org/course/NJTU-1002535019?tid=1465164447)) - [微波技术与天线](https://www.icourse163.org/learn/XDU-1206399806?tid=1466861470#/learn/announce)

![img](../../../../../../../Changes729_image/raw/main/ln/README/2022-04-24-153333_1293x440_scrot.png)

![img](../../../../../../../Changes729_image/raw/main/ln/README/Induction_experiment.png)

电磁波本身带有能量，射频发射器能与射频接收器产生互感，从而在射频接收器产生互感电动势，形成电源供给能量。根据文章描述，有多种技术可以实现RFID，有分**电感耦合**和**电磁反馈耦合**。其中，电感耦合基于的是电磁感应（电磁学），而电磁反馈耦合基于的是雷达原理（光学），雷达发射的电磁波会被遮挡或者吸收，所以根据反馈波的物理特性的不同，可以了解到前方物质的特征。

根据麦克斯韦方程组，电磁感应定律，变化的电场产生磁场，变化的磁场产生电场。使得我们的通信可以在空中传播。首先，RFID双方通信，在数据上存有协议。其次，由于RFID通信方式的特殊性，需要考虑一些低功耗的编码方式以降低通信过程中的能量损耗，所以会重新进行编码。然后重新编码的数据配合射频前端完成震荡。震荡的电路携带着数字信号，依靠天线以电磁波的形式发射到空气中。然后RFID标签天线收取到电磁波，电磁波重新变成电形式的交流电。交流电配合滤波电路、整流电路过滤杂波，取出数字信号，经过解码，还原出原先的数据。然后，再通过同样的路径将信号发送回去。

然后，电磁波是半双工的。典型的半双工协议包括了CSMA/CA。

**RFID 工作频段**

- LF（Low-Frequence）：低频(LF: 125–134.2 kHz and 140–148.5 kHz)
- HF（High-Frequence）：高频 (HF: 13.56 MHz) 标签可以不需要许可证而广泛使用。
- UHF（Ultra-high-frequency）：超高频标签不能被全球性使用，因为国家地区之间的标准不一。


**RFID 标准**
- 小于 135 kHz：
  - ISO/IEC 11784/11785
  - ISO/IEC 18000-2
- 6.78 MHz/13.56 MHz
  - [ISO/IEC 14443](https://www.iso.org/search.html?q=ISO%2FIEC%2014443&hPP=10&idx=all_en&p=0&hFR%5Bcategory%5D%5B0%5D=standard)
  - [ISO/IEC 15693](https://en.wikipedia.org/wiki/ISO/IEC_15693)：
  - ISO/IEC 18000

**RFID 卡类型**
NXP
- [NFC Mifare](https://www.nxp.com.cn/products/rfid-nfc/mifare-hf:MC_53422)：包括 Mifare、Mifare DESFire、Mifare Plus、Mifare Ultralight、Mifare SAM、Mifare 2GO
- [NFC UCODE](https://www.nxp.com.cn/products/rfid-nfc/ucode-rain-rfid-uhf:MC_50483)
- [NFC HITAG](https://www.nxp.com.cn/products/rfid-nfc/hitag-lf:MC_42027)
- [NTAG](https://www.nxp.com.cn/products/rfid-nfc/nfc-hf/ntag-for-tags-labels:NTAG-TAGS-AND-LABELS)
- [ICODE](https://www.nxp.com.cn/products/rfid-nfc/nfc-hf/icode:MC_42024)

复旦微

- [FM系列](http://fmsh.com/7e67a741-a1ed-718d-15e3-83bdb6ecf4fa/)

SONY

- [FeliCa系列](https://www.sony.net/Products/felica/)

其他

- B 型卡：Type B？可能是ISO/IEC 14443 标准的TypeB卡
- 二代证：可能是二代身份证



## 天线仿真

- [HFSS](https://www.ansys.com/products/electronics/ansys-hfss)
- [CST](https://www.3ds.com/zh//)
- [FEKO](https://www.altair.com/)

### 电路板天线设计

- [ST antenna design tool](https://www.st.com/content/st_com/zh/support/resources/edesign.html)

## NFC Chip

- [[ST] ST25DV](https://pdf1.alldatasheet.com/datasheet-pdf/view/1009237/STMICROELECTRONICS/ST25DV.html)


## TODO

- [ ] Android 读取卡片
- [ ] 自建电路 读取卡片
- [ ] Android 模拟卡片
- [ ] 自建 IC 电路卡片
- [ ] Android 与 自建电路通信
- [ ] 自建电路 模拟卡片