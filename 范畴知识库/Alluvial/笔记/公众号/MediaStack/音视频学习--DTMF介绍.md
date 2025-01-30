> 文章来源：https://mp.weixin.qq.com/s/rFHxy1KQQWdHeAd_v9f9BA

# 音视频学习--DTMF介绍

**01 什么是 DTMF？它为何产生，而如今又走向何处？**

双音多频 (DTMF) 是一种<u>电信信令系统</u>，在电话设备与其他通信设备和交换中心之间使用电话线上的语音频带。<u>DTMF 是一种用于拨打电话号码或向交换系统发出命令的方法</u>。

每个 DTMF 数字由两个频率表示，一高一低。选择的频率应使人耳和电话设备能够轻松区分。数字 0 到 9 的频率如下表所示：

![图片](https://mmbiz.qpic.cn/mmbiz_png/CmsibKlb9EkhDvMH1q8S8jnTeLV6hic4NuLHzAv2nO7zyibt8HWOIP4JkCtSXG4GPWWbg3N4vkRRwzvMcM7cKgy7Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

为什么需要DTMF？首先，早起的电话系统，从贝尔实验室发明以来，一直是需要拉电话线从而进行有线通讯，因为通讯线路资源匮乏，所以，一些信道复用技术开始出现。 Inband 信令系统，意味着你可以在建立了通讯线路打电话的同时，还可以通过发送DTMF信令以实现一些特殊功能。

> 这些命令通常用于拨打电话号码进行呼叫，但也可用于发送电话控制命令或控制远程设备，因为控制音与语音信号在同一通道上播放。它是一个<u>Inband信令系统</u>；



在DTMF出现之前，电话系统主要是用[脉冲拨号](https://zh.wikipedia.org/wiki/%E8%84%89%E5%86%B2%E6%8B%A8%E5%8F%B7)来发送号码。

![undefined](https://upload.wikimedia.org/wikipedia/commons/2/21/Model500Telephone1951.jpg)

然而，旋转拨号技术的拨号过程缓慢，而且由于是电信号，因此拨号的传输距离也有限制（太长的传输线无法有效传输信号）。以至于后续技术被 MF（multi frequency）技术替代，最后由贝尔实验室旗下的 Touch-Tone 公司设计 DMTF标准：

> DTMF 由 Bell System 开发，于 1963 年 11 月 18 日推出供公众使用。它以 Touch-Tone 商标而闻名，并很快被接受为标准并在全球范围内采用。

随着进入互联网时代，DTMF也逐渐被替代，在VoIP领域，DTMF通常仅用于拨号提示的反馈系统而存在，当然在信令系统中也有很多定义，并开始拓展信令的作用范围。