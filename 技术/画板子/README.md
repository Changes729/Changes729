> 参考资料：
>
> - [PCB打板之前必须要知道的FR-4](https://mp.weixin.qq.com/s/IWvLdXUPJT8QjBvCYMyu2g)
> - [我是如何在家里小批量生产电路板的](https://www.bilibili.com/video/BV1AB4y1e7Qa?spm_id_from=333.999.0.0&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：介绍了电热台回流焊、介绍了嘉立创 SMT。
> - [一个实验搞明白PCB走线应该画多宽](https://www.bilibili.com/video/BV1G34y1n7Eq)：电路线要画多宽？
> - [轻松搞定人生的第一块柔性线路板 FPCB](https://www.bilibili.com/video/BV1yP411Q7CM/?spm_id_from=333.1245.0.0&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：有介绍一些FPCB基本参数以及加强层等内容介绍

# 画板子

## 工具

- [Altium Designer](https://www.altium.com.cn/altium-designer/)
- [KiCAD](./KiCAD/)
- [立创EDA](./%E7%AB%8B%E5%88%9BEDA.md)

## 小技巧

> - 0欧姆电阻设计，0欧姆电阻可以断开电阻后接入分析仪器，调试方便。
> - 考虑元器件封装时，也要考虑其功率电流等。
> - Arduino等集成电路使用的时候，需要考虑其正反方向，确定是正方向。不然有可能板子会画到反面去。
> - 走线宽度，2.54mm太细了。可以尝试5mm
>   - 电源：20mil，5.08mm
>   - 信号线：2.54mm，10mil



## 电源线宽度

| 电流   | 最小线宽       | 推荐线宽 | 开窗     |
| ------ | -------------- | -------- | -------- |
| < 0.1A | -              | < 10mil  | x        |
| 1A     | 10mil(0.254mm) | 15mil    | x        |
| 2A     | 30mil          | 50mil    | x        |
| 3A     | 60mil          | 100mil   | 可选     |
| > 3A   | -              | -        | 敷铜开窗 |



## 特殊走线

| 线宽 | 用处     |
| ---- | -------- |
| 0.28 | 差分线   |
| 0.5  | 普通走线 |
| 1    | 电源线   |





## 板材

参数

- 玻璃化转变温度（Tg）：Tg越高材料可靠性也越高。
- 热膨胀系数（CTE）
- 吸水率