> 视频来源：https://www.bilibili.com/video/BV1AT411K7sh/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab
>
> 其他资料：
>
> - [Desmos](https://www.desmos.com/?lang=zh-CN)：我们致力于帮助每一位学生学习数学并爱上数学。一个数学绘制网页。
> - [ECC椭圆曲线密码学的原理、公式推导、例子、Python实现和应用](https://zhuanlan.zhihu.com/p/42629724)：有一些非常基础的概念解释
> - [离散对数和椭圆曲线加密原理](https://blog.csdn.net/qmickecs/article/details/76585303)：有一个图解

# matter协议椭圆曲线密码学(ECC)原理详解

## 关键词

ECC非对称加解密算法(Elliptic Curve Cryptography)

secp256k1：比特币中采用的椭圆曲线 —— $$y^2 = x^3 + ax + b; a = 0, b = 7$$



## 公私钥定义

在曲线上任意取一点 $$G$$，将其和整数$$k$$做的点相乘得到曲线上另外一点 $$P$$，的到$P = k*G$其中，$$k$$是私钥，$$P$$是公钥。

其中计算$P = k*G$的速度非常快，但是计算$k = P/G$非常慢。这个特性是非对称加密的基础。

```python
# n is the order of thr curve (the number of all its points)
# h is the curve cofactor, the number of non-overlapping subgroups of points
# r is the order of the subgroups (the number of points in each subgroup, 
# 	including the infinity point for each subgroup) [1...r]
# n = h * r
# g: Elliptic curve subgroups usually have many generator points,
#		but cryptographers carefully select one of them,
#		which generates the entire group (or subgroup) and is suitable
#		for performance optimizations in the computations.
#		This is the generator known as "G".
from tinyec.ec import SubGroup, Curve

field = SubGroup(p = 17, g=(15, 13), n = 18, h = 1)
curve = Curve(a = 0, b = 7, field = field, name = 'p1707')
print('curve:', curve)
for k in range(0, 25):
  p = k * curve.g
  print(f"{k} * G = ({p.x}, {p.y})")
```

```python
from tinyec.ec import SubGroup, Curve

# Domain parameters for the `secp256r1` curve
# (as defined in http://www.secg.org/sec2-v2.pdf)
name = 'secp256r1'
p = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
n = 0xFFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551
a = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC
b = 0x5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B
G = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 
     0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5)
h = 1

curve = Curve(a, v, SubGroup(p, g, n, h), name)
print('curve:', curve)

privKey = int('0x51897b64e85c3f714bba707e867914295a1377a7463a9dae8ea6a8b914246319', 16)
print('privKey:', hex(privKey)[2:])

pubKey = curve.g * privKey
# The public key is compressed and encoded in the standard format
# (encode the y coordinate as prefix 02 or 03).
pubKeyCompressed = '0' + str(2 + pubKey.y % 2) + str(hex(pubKey.x)[2:])
print('pubKey:', pubKeyCompressed) 
```



非对称加密传输是通过 ECDH 实现的。

## ECC 加解密过程

选择一个随机数 $r$，信息为 $M$，生成一个点 $C = (rG， M+rP)$

$$P = kG$$

解密过程：$(M + rP) - k(rG) = M + rkG - rkG = M$



## ECDH 密钥协商过程

小红私钥 $x$，计算 $xG$ 作为公钥。

小明私钥 $y$，计算 $yG$ 作为公钥。

双方共同的密钥$xyG$。

公网上传输信息，如果想要伪造小明往小红发消息，则需要知道小明私钥；反方向同理。