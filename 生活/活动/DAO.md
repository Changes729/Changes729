> 参考资料：
>
> - The DAO
>   - [blockchainsllc](https://github.com/blockchainsllc)/**[DAO](https://github.com/blockchainsllc/DAO)**
>   - [**The Story of the DAO — Its History and Consequences**](https://medium.com/swlh/the-story-of-the-dao-its-history-and-consequences-71e6a8a551ee)

# DAO

## The DAO 的故事

> In essence, the platform would allow anyone with a project to pitch their idea to the community and potentially receive funding from The DAO. Anyone with DAO tokens could vote on plans, and would then receive rewards if the projects turned a profit. With the financing in place, things were looking up.
>
> 从本质上讲，该平台将允许任何有项目的人向社区宣传他们的想法，并有可能从The DAO获得资金。任何拥有DAO代币的人都可以对计划进行投票，如果项目盈利，他们将获得奖励。随着资金到位，情况有所好转。

DAO 可以认为是一个基于区块链的众筹平台。

> In this exploit, the attacker was able to “ask” the smart contract (DAO) to give the Ether back multiple times before the smart contract could update its balance. Two main issues made this possible: the fact that when the DAO smart contract was created the coders did not take into account the possibility of a recursive call and the fact that the smart contract first sent the ETH funds and then updated the internal token balance.
>
> 在这个漏洞中，攻击者能够“要求”智能合约（DAO）在智能合约更新其余额之前多次给予以太币。有两个主要问题使之成为可能：事实上，当创建DAO智能合约时，编码器没有考虑到递归调用的可能性，以及智能合约首先发送ETH资金，然后更新内部代币余额的事实。

这是对以太坊上代码错误所导致的问题。程序应该是不可重入的。

这个事件最终导致以太坊硬分叉，变成如今的以太坊和经典以太坊。



## 专业名词

- Hard fork（硬分叉）：硬分叉是对区块链协议的更改，该协议不向后兼容，并要求所有用户升级其软件以继续参与网络。
- Soft fork（软分叉）：软分叉是对区块链协议的向后兼容更改，允许引入新规则，而无需所有用户升级其软件。

