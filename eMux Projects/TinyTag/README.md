# TinyTag

### 用户调研

**01 商业产品**

网上有很多电子墨水屏的DIY，并且 [汉硕](https://www.hanshow.com/zh-cn) 公司也凭借电子墨水屏标签，成功进行了线下门店的数字化改造。

> 参考资料：
>
> - [汉硕价签HanShow Stellar E31 墨水屏改时钟，无需加硬件实现蓝牙传图，蓝牙OTA](https://www.bilibili.com/video/BV1L14y1K7Eh/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)
> - [CR2450*2焊脚纽扣电池hanshow汉朔stellar电子价签XL3N/M3N专用](https://item.taobao.com/item.htm?abbucket=13&detail_redpacket_pop=true&id=775342994164&ltk2=1749265363047ykinyqo7xypodwolw3u6e&ns=1&priceTId=undefined&query=%E6%B1%89%E7%A1%95%E4%BB%B7%E7%AD%BEHanShow%20Stellar%20E31&spm=a21n57.1.hoverItem.36&utparam=%7B%22aplus_abtest%22%3A%227b94435f08499c0ca1ef30fbd027bdf2%22%7D&xxc=taobaoSearch) 3v 1200mAh

汉硕的价签基本上也服务于各种品牌门店。

然而，如今的商业产品，在成本上并不明细，而且不面向 C 端客户。



**02 真实需求**

**02.1 交互式标签**

为了适应未来的个体，以及更好的和环境进行交互。我们尝试将电子标签作为一个现实的触点。



**02.2 Debug 工具**

有一个类似的相关工具，就是使用 UART 充当外接屏幕。



### 设计方案

**版本 0.1.0**

当前方案，是将其打造成一个独立的屏幕显示单元。并可以与其他嵌入式设备进行通信。



### 实现落地

**01 版本 0.1.0 排期**

- ~2025-06-22（日）：反思推文推送
- ~2025-06-20（五）：收尾验证，技术评估与反思
- ~2025-06-13（五）：明确技术方案，并进行初步技术验证
- 2025-06-07（六）：立项，明确时间、投入资金、预期功能。明确库存可利用的屏幕，明确储备设备。
  - 预计投入资金电路制版：三个版本不包含SMT（300）
  - 预期功能：支持一块屏幕显示文本信息，一个按钮支持信号触发。比如，设备上记录了名字：eMux,则可以打开eMux网页。
  - 可利用的屏幕：
    - [ET011TJ1](https://item.taobao.com/item.htm?id=684142072667&pisk=goQu6CjrdccIxC2vDZT7baxH3mrxyUTC893ppepU0KJbO0n8NHRFt9bd26Jp-9XhKLKUFUQhn11LNwFWzyAFBtYdwLpdnWXRO2e7AU3EKT1aF_pLNwvenTWHA79pLpXdTgFYWPC5NeTEKRUTW--BL56o4LuzTKRHTSdzGgzFbeTUBJmx83aMRT7S1qgE0IJXtBoeL9o4uC92T08FLK-2_CHy89We0xR69bkrzHJ4iCAr8QJeYsk2tCnEU98UisJXTeRPLekkR0J9TLQ4HMJ-fl76XZAkqd50fDnBPVKJQOJq8R7DZd9NaK0E8LCciEfNK806awAl0w-7c8flDgWJG94gne6fY9Rh3yM2GafOX3juEVpBjG1ptT4ozUIVcaTRkRc6q9vDbZt0bjxA3aXHeeEEAFS26195UXnvJafVyI6n_0CyfLYDGwejzpjVYaKWRYy9V6ScnQXYhmAcXT_MuNyj-OSzUmoNVe3BgWQqADtyGIv98CKtp6eMi8F0icCB4IOFXSVmAoxyGIvaiSmT13RXNkC..&spm=tbpc.boughtlist.suborder_itemtitle.1.15602e8d8dLpVY)：电子墨水屏
    - [3.5寸 SPI TFT](https://item.taobao.com/item.htm?_u=72d3uchq950d&id=726092568739&pisk=gAA0_jv4fJ46GxmReQ1jLIjcuwD-ls16_hFOX1IZUgSS5-exlO7wShA9HFSOshxMjiBZcsdMqeTtlC3fgfbwv3f9kiI9qVxv55njCsFajnTEcEItlCjNqn-GCqsObGx97K3-9XLXl11ajDhK9KRRdit0Qt7Z787G-4QqPKlwL11ZvcbZzQfh1nRjNq2aUaS5SNPa_h5P4wbF_N7V_4jPSwwa0h-ZrT7CW-7Nu-7rag_C7R5a3TPP-Zr4g--wz4bh71Swbtukzchu3MQNDQoJQiOmlEPXwZXcYES2keRrLtyXlg2QpQvoCMY2C5PwZZXD1aR0mkfMQe9G__0q_EtdVOWW4bFcsU7MDgKET7fykepdgC3TCZvwJIpefve5iFJ2fTxjV8jJUITNbt4aOUxk7eskrX2BXnvvqTftC55VGwxfgIo8m1flROvdEomRXpLJgTxE27x1IpTOSnc0g_ppcpWBFc2hYpLCZg8zUJJf65_rWQy_Ct75rMCNJ9E9WDboD40upF6VPNJKr42sEt75rMuorJ3C3a_jB&spm=a1z09.2.0.0.64102e8dADwmb8)：带电容触摸
  - 设备：ESP32S2



### 渠道销售