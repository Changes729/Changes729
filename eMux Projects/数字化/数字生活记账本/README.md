# 数字时代个人生活记账本

现代资本社会主要以**资金**为主要生存手段，对资金进行管控是高质量生活的一种态度与方式。

当下，记账本的主要问题是<u>记账本手动记录太麻烦</u>。我们希望通过某种方式，使我们的经济生活达到一种**收支既记录**的愿景。

## 主要功能

现阶段主要以解决支付、记录之间的鸿沟为目标。

- [ ] 收支记录
    - [ ] 按时间显示精简收支纪录
        - [ ] 交易时间
        - [ ] 交易方
        - [ ] 金额
    - [ ] 查看收支详情
        - [ ] 交易时间
        - [ ] 交易方
        - [ ] 交易状态
        - [ ] 交易金额
        - [ ] 交易商品类型
        - [ ] 支付方式
        - [ ] 交易订单
    - [ ] 折叠收支纪录
        - [ ] 按天、月、年折叠收支纪录
    - [ ] 查找收支纪录
        - [ ] 过滤条件：金额范围、时间范围、交易方（交易地点）、支付类型、支付方式
- [ ] 收支同步
    - [ ] 微信账单同步
    - [ ] 支付宝账单同步
    - [ ] 其他第三方支付账单同步
    - [ ] 银行卡支付同步
    - [ ] 线下支付同步（发票）
    - [ ] 随手记



最重要的是收支同步功能。理想的同步其实不是同步，应该是一种`Pub-Sub`的形式。但是现在因为支付宝、微信不开放接口，所以支付内容无法那么轻松的获取。得想个办法比较好的同步数据。



### 二期内容

- [ ] 收支数据秘书
    - [ ] 收支数据可视化
        - [ ] 支出占比（饼图）
        - [ ] 历史收支（柱状图）



## 原型

```script
# 使用摹客绘制原型
```



## 实现

```script
# 导航至App
```



## 其他链接

- [TODO List](./TODO.md)
- [竞品分析](./竞品分析.md)



- [[Bilibili] Money Manager](https://www.bilibili.com/video/BV1W54y1172R?from=search&seid=3363601211321926301&spm_id_from=333.337.0.0)
- [鲨鱼记账](https://www.shayujizhang.com/)
- [口袋记账](https://www.qeeniao.com/)
- [[Bilibili] 花记](https://www.bilibili.com/video/BV1Z44y1E7ie?from=search&seid=3363601211321926301&spm_id_from=333.337.0.0)：这是某人的毕业设计
- [[Bilibili] 简约记账](https://www.bilibili.com/video/BV1Ey4y1k73N/?spm_id_from=333.788.recommend_more_video.-1)：工程教学
- [网易有钱](https://www.zhihu.com/question/435859588/answer/1639959811)：理想的账单同步软件。如今已经下架。
- [51信用卡风波](https://www.cnbeta.com/articles/tech/901891.htm)
- 微信账单和支付宝账单的提取和合并：[Bilibili](https://www.bilibili.com/video/BV1L64y1B7CG?from=search&seid=9760958450398533635&spm_id_from=333.337.0.0)、[Gitee](https://gitee.com/Python_CaiShu/Bill)
