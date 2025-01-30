> 
>
> 参考资料
>
> - [电容充放电时间常数RC计算方法](https://blog.csdn.net/xuhao0258/article/details/116260327)

# 电路相关

- [画板子](./%E7%94%BB%E6%9D%BF%E5%AD%90/)
- [元器件](./%E5%85%83%E5%99%A8%E4%BB%B6/)
- [开发板](./%E5%BC%80%E5%8F%91%E6%9D%BF/)
- [绘制数字信号](https://lgl88911.github.io/2020/05/22/%E6%95%B0%E5%AD%97%E7%94%B5%E8%B7%AF%E6%B3%A2%E5%BD%A2%E5%9B%BE%E7%BB%98%E5%88%B6%E5%B7%A5%E5%85%B7WaveDrom%E7%AE%80%E4%BB%8B/)



## 电工装备

- 示波器
- 电源
- 信号源
- 烙铁



## 一些术语

- DIP (dual in-line package, 双列直插式封装技术)
- SMT (Surface Mounted Technology, 表面贴装技术)
- 品质因素：根据物理学，Q因子等于2π乘以系统储存的总能量，除以单一周期损失的能量，也可以表示为系统储存的总能量和单位弪度损失能量的比值。



## 电路原理

- [电抗](https://zh.wikipedia.org/wiki/%E7%94%B5%E6%8A%97)
- [品质因子](https://zh.wikipedia.org/wiki/%E5%93%81%E8%B3%AA%E5%9B%A0%E5%AD%90)：串联电路 - $$Q = \frac{1}{R}\sqrt{\frac{L}{C}} = \frac{\omega_0L}{R} = \frac{1}{\omega_0RC}$$；并联电路 - $$Q = R\sqrt{\frac{C}{L}} = \frac{R}{\omega_0L} = \omega_0RC$$
- [Basic network theory](https://www.microwaves101.com/encyclopedias/basic-network-theory)
  - [S-parameters](https://www.microwaves101.com/encyclopedias/s-parameters)



## RC电路

$$
V_t = V_0 + (V_u - V_0)[1 - e^{-t/RC}]
$$