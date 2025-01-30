> 参考资料：
>
> - [大学物理3：电磁学 ](https://www.icourse163.org/course/TONGJI-44006?from=searchPage#/info)
> - [怎样直观推导电磁波？](https://mp.weixin.qq.com/s/ZIME0wGm9jp4LFZR-53keg)
>
> 名词参考：
>
> - AAT（antenna tracking，天线跟踪）

# 电磁学

- 物体的总电荷量 $$q = ne$$，其中，单位电荷 $$e \approx 1.60.2 \times 10^{-19} C$$

- [库仑定律](https://zh.wikipedia.org/zh-hans/%E5%BA%93%E4%BB%91%E5%AE%9A%E5%BE%8B)：真空中两个点电荷受到的相互作用力为：$$\vec{F} = \frac{1}{4\pi\varepsilon_0}\frac{q_1q_2}{r^2}\vec{e_r}$$，其中，$$\varepsilon_0$$ 是真空电容率

- 点电荷电场强度：$$\vec{E} = \frac{q}{4\pi\varepsilon_0r^2}\vec{e_r}$$

- [电偶极子](https://zh.wikipedia.org/wiki/%E5%81%B6%E6%A5%B5%E5%AD%90)场强：

  - 延长线上的场强：$$E_A \approx \frac{2ql}{4\pi\varepsilon_0r^3}$$，其中 $$ql$$ 是电偶极矩
  - 中垂线上的场强：$$E_A \approx \frac{ql}{4\pi\varepsilon_0r^3}$$

  延长线上的场强要比中垂线上的场强要强，约2倍。

- 无限长带电直线场强公式：$$E = E_y = \frac{\lambda}{2\pi\varepsilon_0a}$$，其中 $$\lambda$$ 是电荷线密度。 $$a$$ 是点电荷离直线的距离。

- 电通量：$$\phi_e = \vec{E}\vec{S}$$，其中 $$E$$ 是场强，而 $$S$$ 是平面面积。必要时采用积分的方式计算。

  - 闭合球面的电通量：$$\phi_e = \frac{q}{\varepsilon_0}$$，可以看到与半径无关。

- 电流：$$I = \frac{\mathrm{d}{q}}{\mathrm{d}{t}}$$

- 电压：$$\vec{V_{ab}} = -\int_{x_a}^{x_b} \vec{E} \mathrm{d}l$$， 电压表现为两点之间的电势差。电势是此处电场的场强沿路径积分。

- 磁感应强度：$$B = \frac{F}{q_0v}$$，单位 特斯拉（T），高斯（G） $$1T = 10^4 G$$

- 载流直导线产生的磁场：$$B = \frac{\mu_0I}{4\pi a}(\cos\theta_1 - \cos\theta_2 )$$

  - 无限长载流直导线：$$B = \frac{\mu_0I}{2\pi a}$$
  - 半无限长载流直导线：$$B = \frac{\mu_0I}{4\pi a}$$
  - 导线延长线：$$B = 0$$

- 载流圆线圈磁感应强度：

  ![img](../../../../../../Changes729_image/raw/main/ln/README/6b6ebe29jw1exlucdyn3hj209u082q2z.jpg)

  载流元：$$\mathrm{d}{B} = \frac{\mu_0}{4\pi} \frac{I\mathrm{d}{l} \sin{\theta}}{r^2}$$

  x方向分量：$$B_x = \int\mathrm{d}{B}\cos{a} = \int\frac{\mu_0}{4\pi}\frac{I\mathrm{l}\sin{90}\cos{a}}{r^2}$$

  最终解得出：$$B = \frac{\mu_0IR}{2(R^2 + x^2)^{3/2}}$$

  - 圆心时：$$B_0 = \frac{\mu_0 I}{2R}$$
  - 弧线：$$B_0 = \frac{\theta}{2\pi} \frac{\mu_0 I}{2R}$$
  - P远离圆电流时：$$B_0 \approx \frac{\mu_0 I R^2}{2x^3} = \frac{\mu_0 I S}{2\pi x^3}$$，其中，S是圆电流的面积。

- 圆电流磁矩：$$\vec{m} = IS\vec{e}_n$$
- 磁通量：$$\phi_m = \vec{B}\vec{S}$$
- 电磁感应：$$\varepsilon_i = - \frac{\mathrm{d}{\phi}}{\mathrm{d}{t}}$$，磁通量的变化会产生电势。（变化的磁场产生电场）
- 自感现象：线圈通电时，由于电场变化导致磁场变化，磁场的变化反过来影响电流，这就是自感。
- 自感电动势：$$\varepsilon_L = -L\frac{\mathrm{d}I}{\mathrm{d}t}$$
- 自感系数：$$L = \mu n^2 V$$，其中 $$\mu$$ 是磁导率，n 是线圈砸数。
- 互感现象：一个线圈发生电流变化引起的磁场变化，导致另一个线圈的磁场变化，进而导致另一个线圈产生电流。
- 麦克斯韦方程组：电磁波





