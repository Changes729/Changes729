> 参考资料：
>
> - [屏幕如何感应到触摸？ 触控面板的基本认识](https://www.eizo.com.cn/global/library/basics/basic_understanding_of_touch_panel/index.html)
> - [Windows 8和10：具有多个触摸显示器时的触摸屏功能问题](https://www.dell.com/support/kbdoc/zh-cn/000132341/windows-8%E5%92%8C10-%E5%85%B7%E6%9C%89%E5%A4%9A%E4%B8%AA%E8%A7%A6%E6%91%B8%E6%98%BE%E7%A4%BA%E5%99%A8%E6%97%B6%E7%9A%84%E8%A7%A6%E6%91%B8%E5%B1%8F%E5%8A%9F%E8%83%BD%E9%97%AE%E9%A2%98)
> - [微雪触摸屏驱动源代码](https://github.com/waveshare/linux-patch/blob/rpi-6.1.y/drivers/gpu/drm/panel/panel-waveshare-dsi.c)
> - [esp32 lvgl用于TFTLCD屏幕，TFT_eSPI库移植，设置控件边框颜色，图片在屏幕中位置设置，设置字体颜色，屏幕切换函数参数讲解](https://www.cnblogs.com/caiya/p/16013449.html)：LVGL 的嵌入式屏幕驱动驱动，采用 TFT_eSPI 库。库内有驱动。

# 屏幕



## 触摸屏幕类型

- 电阻膜式触控面板

- 电容式触控面板

- 投射电容式触控面板

  - [**深圳市格林兴显示科技有限公司**](https://greentouch.panelook.cn/?ac=ne_product&catid=12870)

    万利 先生 | 销售部 总监：手机：86-13823548639

- 表面声波式（SAW）触控面板

- 光学式触控面板（红外光学成像触控面板）

- 电磁感应式触控面板

- 控制卡：

  - [x] [奕力卡](http://www.wide-et.com/drivers.aspx)：公司当前方案
    - [奕力官网](https://www.ilitek.com.tw/page/about/index.aspx?kind=10)
  - [EETI控制卡](https://www.wiwotouch.com/cn/product/products-6-26)



## 器件整理

> 供应商：
>
> - [汉昇](http://www.hslcm.com/)
> - [Newvision(新智景)](http://www.jxwisevision.com/)

| 屏幕                 | 价格                                                         | 体积 | 分辨率  | 色彩空间 | 接口       |
| -------------------- | ------------------------------------------------------------ | ---- | ------- | -------- | ---------- |
| X050-8848TSWYG02-H14 | [6](https://item.szlcsc.com/19915584.html?kw=catalog&fromZone=l_b) |      |         |          |            |
| HS96F04BF            | [9](https://item.szlcsc.com/5751919.html?kw=catalog&fromZone=l_b) |      |         |          |            |
| ST7796（FT6336）     | [64](https://item.taobao.com/item.htm?id=726092568739&mi_id=0000iy5WnuERg5cVQKp85sFQfw-8sT7MS9GMZ-1oVCbFYJw&spm=tbpc.boughtlist.suborder_itemtitle.1.61e82e8ddM0eqF&skuId=5038781604151) |      | 320*480 |          | SPI（IIC） |



### ST7796（FT6336）

触摸屏幕，有工程文件可下载：[3.5inch IPS SPI Module ST7796](https://www.lcdwiki.com/zh/3.5inch_IPS_SPI_Module_ST7796#%E7%A8%8B%E5%BA%8F%E4%B8%8B%E8%BD%BD)
