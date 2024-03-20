> 文章来源：https://mp.weixin.qq.com/s/Fkhn4UdV4A7kAPTI6ZfMVg

# Go 语言体系下的微服务框架选型: Dubbo-go

## 关键词

- **[Dubbo-go](https://github.com/apache/dubbo-go)**：Apache Dubbo 是一款易用、高性能的 WEB 和 RPC 框架，同时为构建企业级微服务提供服务发现、流量治理、可观测、认证鉴权等能力、工具与最佳实践。Dubbo3 从设计上不绑定编程语言，社区目前提供了 Java、Go、Rust、Node.js 等多语言实现。
- 通信协议：HTTP、TCP外，这里还关注 RPC（Remote procedure call）；包括了JSONRPC、gRPC；
- 服务注册：Client-based 服务发现机制？支持注册中心适配如 Nacos、Consul、Zookeeper；
- 配置中心：配置变更的实时感知，也有 ZooKeeper；
- 负载均衡：负载均衡策略，随机负载均衡策略、一致性哈希负载、基于权重的轮询、最小活跃度优先、自适应负载均衡 P2C
- 流量控制：超时时间调整、开启访问日志、金丝雀发布、参数路由、同区域优先、按比例流量分发
- 分布式事务：Seata-golang 分布式事务框架。实现了 AT 模式和 TCC 模式分布式事务的调用。
- 链路追踪：Jaeger
- 指标可视化：Prometheus



## 遗留问题

- RPC 的功能设计包括哪些？远程调用中，对任务生命周期的管理是如何？

  - [gRPC](https://grpc.io/docs/what-is-grpc/introduction/)：就是远程调用。基本上，gRPC就是期望做到底层隐藏。基本原理是序列化和接口描述解耦。

- 什么是Client-based [服务发现机制](https://www.bilibili.com/video/BV1Zs4y1h7ku/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)？

  - 简单的服务，就是写死配置。但是由于后端微服务的动态更新迭代，IP地址的变动等等运营上的问题，因此需要有一种动态的机制让前端服务可以动态了解后台大规模的微服物部署情况。这里就涉及到了微服务的同步机制，还有包括负载均衡等等问题。

- [Zookeeper](https://zhuanlan.zhihu.com/p/45728390)是什么？

  - ZooKeeper 是一个分布式的，开放源码的分布式应用程序协调服务，它是一个为**分布式应用提供一致性服务**的软件，提供的功能包括：配置维护、域名服务、分布式同步、组服务等。服务注册和配置中心。

    > 关于“ZooKeeper”这个项目的名字，其实也有一段趣闻。在立项初期，考虑到之前内部很多项目都是使用动物的名字来命名的（例如著名的Pig项目),雅虎的工程师希望给这个项目也取一个动物的名字。时任研究院的首席科学家 RaghuRamakrishnan 开玩笑地说：“在这样下去，我们这儿就变成动物园了！”此话一出，大家纷纷表示就叫动物园管理员吧一一一因为各个以动物命名的分布式组件放在一起，雅虎的整个分布式系统看上去就像一个大型的动物园了，而 Zookeeper 正好要用来进行分布式环境的协调一一于是，Zookeeper 的名字也就由此诞生了。

- 什么是分布式 AT 模式和 TCC 模式？

  - [分布式事务 Seata 及其三种模式详解 | Meetup#3 回顾](https://seata.io/zh-cn/blog/seata-at-tcc-saga.html)：AT 模式（Automatic Transaction）一阶段，二阶段提交或回滚，比较类似 Git 代码管理，Stash，Commit和Revert。TCC 模式（Try、Confirm、Cancel）在支付场景下，Try 实际上是对分布式数据的锁。放冲突用的。

- 什么是 Jaeger 链路追踪？

  - [全链路追踪](https://jckling.github.io/2021/04/02/Jaeger/%E5%85%A8%E9%93%BE%E8%B7%AF%E8%BF%BD%E8%B8%AA%E4%B8%8E%20Jaeger%20%E5%85%A5%E9%97%A8/index.html)：就是本地程序运行的时候，其实除了问题，看看日志就行。但是在分布式业务下，无论是本地的日志（Logging），还是最终看的度量（Metrics），都不能很好的查看业务流程。因此，需要通过分布式追踪（Tracing）追踪具体的业务流程。