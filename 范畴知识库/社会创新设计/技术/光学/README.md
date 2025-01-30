> 参考资料
>
> - [[MOOC] 应用光学](https://www.icourse163.org/learn/ZJU-1206578811?tid=1472036463#/learn/content?type=detail&id=1257189701)

# 应用光学

- 辐射功率：J

- 可见光：400～760nm

- 朗伯体光源：光强满足余弦分布

- 卡塞格林系统

- 发光强度：[Candela（cd，坎德拉）](https://en.wikipedia.org/wiki/Candela)

  - 格拉斯曼颜色混合定律：**混合**色的总亮度等于组成**混合**色的各种**颜色**光的亮度之和。

- 光角度单位：[Solid angle（sr，立体角）](https://en.wikipedia.org/wiki/Solid_angle)，$$\Omega = A/r^2 (m^2/m^2)$$，$$\Omega = 1sr |_{ A = r^2}$$，$$\Omega = 2\pi(1-\cos \theta)$$，其中 $$\theta$$ 是半角

  半球立体角为 $$2\pi = 6.28$$

  ![undefined](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Angle_solide_coordonnees.svg/1280px-Angle_solide_coordonnees.svg.png)

- 光通量单位：[luminous flux（lm，流明）](https://en.wikipedia.org/wiki/Luminous_flux)，$$1lm = 1cd*1sr$$

  人眼所能感觉到的辐射功率，$$1lm|_{(1/683)W,555nm}$$

- 光照度（lx，lux）：光源发出的光投射到某表面，该表面上的亮、暗程度。单位面积上的光通量。

  - 读书光照度不低于 50lx
  - 工作光照度不低于 100lx
  - $$1lx = 1lm/m^2 = 1.46\times10^-7 W/cm^2 = 1.46 \times 10^-4 mW/cm^2$$

- 光出射度

- 辐射通量（mW）：辐射总功率

- 辐射强度（le，mW/sr）：

- 辐射照度（Ee，mW/cm^2）：

- 辐射半角（Half-angle，$$\Phi$$）：沿着发射中心线测量角度，该角度处辐射强度降至最大值的 50 %



## 定理

- 光在同一介质中传播，忽略散射与吸收时，光束的光通量与亮度不变。
- 光能损失：
  - 反射损失：
    - 光学零件折射面上的反射损失 $$\rho$$
    - 交合面两侧材料差异较大产生的反射损失（可以忽略）
    - 光学零件折射面或反射面上的散射损失
  - 吸收损失：
    - 在空气中吸收（距离较短可忽略）
    - 光学零件中的材料吸收——损失 $$1-\tau｜_{光学透过率}$$
  - 反射面不完全反射损失
    - 镀膜反射面