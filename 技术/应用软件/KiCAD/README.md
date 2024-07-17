> 参考资料：
>
> - [Kicad如何导入封装库、符号库（元件库）以及3D模型文件？](https://jrhar.blog.csdn.net/article/details/123115163?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3-123115163-blog-89856806.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3-123115163-blog-89856806.pc_relevant_default&utm_relevant_index=6)
> - [KiCad 开源元件库收集](http://bbs.eeworld.com.cn/thread-1161523-1-1.html)
>   - [KiCad Libraries](https://kicad.github.io/)
> - [KiCad-9分钟速成系列](https://www.bilibili.com/video/BV12J411z7j7?spm_id_from=333.337.search-card.all.click)
> - [技术指导：下单前技术员必看](https://www.jlc.com/portal/server_guide_112.html)
> - [Kicad6.0中使用立创EDA导出的封装和3D模型](https://zhuanlan.zhihu.com/p/576608333)
> - [KiCad Library Conventions](https://gitlab.com/kicad/libraries/klc)：KLC，Kicad 规范指北
> - [Custom design rule examples](https://docs.kicad.org/8.0/en/pcbnew/pcbnew.html#custom_design_rule_examples)：自定义 DRC

# KiCAD

- [画板子](./画板子.md)
- [插件](./插件.md)
- [编辑符号库](./编辑符号库.md)
- [封装向导](./封装向导.md)
- [射频实战](./射频实战.md)
- [层次图与设计规则](./层次图与设计规则.md)



## 设计规则

### 嘉立创

- 最小间隙

  - 单面和双面板最小线宽线隙：0.10/0.10mm 
  - 四层和六层板最小线宽线隙：0.09/0.09mm

  > 成品厚铜板最小线宽线隙：2OZ：0.16/0.16mm；2.5OZ：0.20/0.20mm；3.5OZ：0.25/0.25mm；4.5OZ：0.30/0.30mm

- 最小布线宽度

- 最小连线宽度

- 最小环形宽度

- 最小过孔外径 & 最小通孔

  - 单面和双面板最小过孔：内径0.3mm/外径0.5mm（单面铝基板最小钻孔1.0mm）
  - 四层及四层以上多层板最小过孔：内径0.15mm/外径0.25mm

- 铜孔间隙：最小焊盘边距离线边:0.10mm

- 铜边缘间隙

- 孔对孔间隙

- 最小微孔外径

- 最小U形导通孔

- 敷铜参数：间隙、最小宽度：0.2（高速线）
- 焊盘：AB（0.25）
- 泪滴：
  - V：90%
  - H：50%
  - 曲线点（10）

