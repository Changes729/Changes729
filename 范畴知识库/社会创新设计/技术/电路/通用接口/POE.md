> 参考资料：
>
> - https://www.inscapedata.com/pdf/IEEE802.3at_Standard.pdf：25.5w
> - [TPS2378-POE受电分离器](https://oshwhub.com/qyxa007/xing-huo-POE-power-system)
> - [树莓派3B+/4B扩展板 迷你POE以太网供电模块 支持802.3af网络标准](https://item.taobao.com/item.htm?abbucket=13&id=687736601706&ns=1&pisk=gs4ZeKOCy3LIf4Htjyg2Y2dNAq3taqW57rMjiSVm1ADiCScmuJ2f6ANcB-zqKSE16m69gCUUUET1BGFDuqgcFT_5P5dskqX5IMIgZdhoaEbjImAnWjiOd69CP5FtHCJcNkbW3AoDVCxmn-0nxbhmofcmIHfEgbkmoAmDKHcoKq0msjVHKjhvsxDgnHAnZbLMmj0m-pcxNqD0nqfUtvhjoxDrX-2OTxnGgshDurfwucDusv8DzQHZjkQ-pEx0-fPEE5qvoE4E_c4x5640-qr0woum81b068MKmDehRFu4tjysd8bk82V_Nugglstx_oV75u2AVH3ail2xYRBpYvZ3WSDmbIY8TJP0wvPFz3ebQlwEYqsvoV0taR3gS99Zu2l-0uieQ9MbVWaiY8XB8-n42SG4QN8iRuwTq0Ed33kuV73F4LvxtWiTklJD0ccKTY1FTDswYvtDryjeDnnFvXk5iExvDc0rTY1F9nKxYlhEF13d.&priceTId=213e037617428694509958186e1c55&spm=a21n57.1.hoverItem.3&utparam=%7B%22aplus_abtest%22%3A%2292940973cab099f41bfda7cf071a33f8%22%7D&xxc=taobaoSearch)
> - [Raspberry PI powered over Ethernet (PoE)](https://di-marco.net/docs/n0d3-b0x_v2/pi_poe/)
> - [PoE供电技术简介](https://blog.csdn.net/weixin_45365488/article/details/132407768)：写的比较详细的

# POE（Power Over Ethernet）

## 方案分析

**01 [树莓派以太网供电迷你扩展板 适用于树莓派3B+/4B，支持802.3af网络标准](https://www.waveshare.net/shop/PoE-HAT-E.htm)**

- [MB10F](https://item.szlcsc.com/226051.html?fromZone=s_s__%22MB10F%22&spm=sc.gb.xh2.zy.n&lcsc_vid=Q1ZbBVRRQ1hWVQVVRwANUAcCTwUKVQBUQABWAgUETlgxVlNSQ1lYV1JRQFFdUzsOAxUeFF5JWBYZEEoVDQ0NFAdIFA4DSA%3D%3D)：推测是整流二极管

- RG：？稳压二极管

- [MP8017](https://www.monolithicpower.cn/cn/documentview/productdocument/index/version/2/document_type/Datasheet/lang/en/sku/MP8017GL/document_id/9827/)

  [REF](https://www.monolithicpower.com/jp/learning/resources/introducing-the-mp8017-an-ultra-small-ieee-802.3af-poe-pd-solution)

- [SBR8U60P5-13](https://item.szlcsc.com/166068.html?fromZone=s_s__%22SBR8U60P5%22&spm=sc.gb.xh1.zy.n&lcsc_vid=Q1ZbBVRRQ1hWVQVVRwANUAcCTwUKVQBUQABWAgUETlgxVlNSQ1lYVlRfQVFbVDsOAxUeFF5JWBYZEEoVDQ0NFAdIFA4DSA%3D%3D)



**02 [PoE HAT (G)](https://www.waveshare.net/shop/PoE-HAT-G.htm)**

- [MP9928](https://www.monolithicpower.com/jp/mp9928.html)
- [4407A](https://item.szlcsc.com/8575679.html?fromZone=s_s__%224407A%22&spm=sc.gb.xh1.zy.n___sc.gb.hd.ss&lcsc_vid=Q1ZbBVRRQ1hWVQVVRwANUAcCTwUKVQBUQABWAgUETlgxVlNSQ1lYVlRfQVFbVDsOAxUeFF5JWBYZEEoVDQ0NFAdIFA4DSA%3D%3D)
- ANUP525
- NH6042S 2412([DMNH6042SPS-13](https://item.szlcsc.com/5954951.html?fromZone=s_s__%22NH6042S%202412%22&spm=sc.gb.xh1.zy.n&lcsc_vid=Q1ZbBVRRQ1hWVQVVRwANUAcCTwUKVQBUQABWAgUETlgxVlNSQ1lYXlFQRlhfUDsOAxUeFF5JWBYZEEoVDQ0NFAdIFA4DSA%3D%3D))



其他产品

- [树莓派5 POE带PD诱导Type C供电模块以太网供电协议802.3af/at Pi5](https://spotpear.cn/shop/Raspberry-Pi-5-Pi5-POE-Power-Over-Ethernet-PD-Trigger-Activation-A/Pi5-POE-PD-A.html)
