> 参考资料
>
> - [什么是NAT？](https://info.support.huawei.com/info-finder/encyclopedia/zh/NAT.html)
> - [Network address translation](https://en.wikipedia.org/wiki/Network_address_translation)
> - [P2P 打洞原理](https://webrtc.mthli.com/basic/p2p-hole-punching/)：[《WebRTC学习指南》](https://webrtc.mthli.com/)
>   - [Peer-to-Peer Communication Across Network Address Translators](https://bford.info/pub/net/p2pnat/)

# NAT

## 类型

### SNAT（源NAT）

源NAT在NAT转换时，仅对报文中的源地址进行转换，主要应用于私网用户访问公网的场景。当私网用户主机访问Internet时，私网用户主机发送的报文到达NAT设备后，设备通过源NAT技术将报文中的私网IPv4地址转换成公网IPv4地址，从而使私网用户可以正常访问Internet。

根据转换时是否同时转换源端口号，源NAT可以细分为如下几种类型，详见下图。

| 类别        | 描述                                                       | 使用场景 |
| ----------- | ---------------------------------------------------------- | -------- |
| NAT No-PAT  | 只转换地址，不转换端口的NAT。                              |          |
| NAPT（PAT） | 同时转换地址和端口的NAT                                    |          |
| Easy IP     | 一种特殊的 NAPT，使用出接口的公网 IP 作为 NAT 转换后的地址 |          |



### DNAT（目的NAT）

目的NAT在NAT转换时，仅对报文中的目的地址和目的端口号进行转换，主要应用于公网用户访问私网服务的场景。当公网用户主机发送的报文到达NAT设备后，设备通过目的NAT技术将报文中的公网IPv4地址转换成私网IPv4地址，从而使公网用户可以使用公网地址访问私网服务。

根据转换前后的地址是否存在一种固定的映射关系，目的NAT可以细分为如下几种类型，详见下图。

| 类别        | 描述                                                         | 使用场景                                                     |
| ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 静态目的NAT | 静态目的NAT是一种转换报文目的的IP地址的方式，转换前后的地址存在一种固定的映射关系 | 出于安全考虑，不允许外部网络主动访问内部网络。但是在某些情况下，还是希望能够为外部网络访问内部网络提供一种途径。 |
| 动态目的NAT | 不存在一种固定的映射关系                                     |                                                              |
| NAT Server  | 特殊目的静态NAT                                              |                                                              |



### 双向NAT

双向NAT指的是在转换过程中同时转换报文的源信息和目的信息。双向NAT不是一个单独的功能，而是源NAT和目的NAT的组合。双向NAT是针对同一条流，在其经过设备时同时转换报文的源地址和目的地址。双向NAT主要应用在同时有外网用户访问内部服务器和私网用户访问内部服务器的场景。

#### STUN中定义的NAT类型

在[STUN](https://info.support.huawei.com/info-finder/encyclopedia/zh/STUN.html)标准中，根据私网IP地址和端口到NAT出口的公网IP地址和端口的映射方式，把NAT分为如下四种类型，详见下图。

![STUN中定义的NAT类型](https://download.huawei.com/mdl/image/download?uuid=83613a4712404ea2ac65b69de73c5d35)

**01 Full Cone NAT（完全锥型NAT）**

所有从同一个私网IP地址和端口（IP1:Port1）发送过来的请求都会被映射成同一个公网IP地址和端口（IP:Port）。并且，任何外部主机通过向映射的公网IP地址和端口发送报文，都可以实现和内部主机进行通信。

这是一种比较宽松的策略，只要建立了私网IP地址和端口与公网IP地址和端口的映射关系，所有的Internet上的主机都可以访问该NAT之后的主机。



**02 Restricted Cone NAT（限制锥型NAT）**

所有从同一个私网IP地址和端口（IP1:Port1）发送过来的请求都会被映射成同一个公网IP和端口号（IP:Port）。与完全锥型NAT不同的是，当且仅当内部主机之前已经向公网主机发送过报文，此时公网主机才能向私网主机发送报文。



**03 Port Restricted Cone NAT（端口限制锥型NAT）**

与限制锥型NAT很相似，只不过它包括端口号。也就是说，一台公网主机（IP2:Port2）想给私网主机发送报文，必须是这台私网主机先前已经给这个IP地址和端口发送过报文。



**04 Symmetric NAT（对称NAT）**

所有从同一个私网IP地址和端口发送到一个特定的目的IP地址和端口的请求，都会被映射到同一个IP地址和端口。如果同一台主机使用相同的源地址和端口号发送报文，但是发往不同的目的地，NAT将会使用不同的映射。此外，只有收到数据的公网主机才可以反过来向私网主机发送报文。

这和端口限制锥型NAT不同，端口限制锥型NAT是所有请求映射到相同的公网IP地址和端口，而对称NAT是不同的请求有不同的映射。



## NAT是如何工作的？

### NAPT工作原理

当Host访问Web Server时，设备的处理过程如下：

1. 设备收到Host发送的报文后查找NAT策略，发现需要对报文进行地址转换。
2. 设备根据源IP Hash算法从NAT地址池中选择一个公网IP地址，替换报文的源IP地址，同时使用新的端口号替换报文的源端口号，并建立会话表，然后将报文发送至Internet。
3. 设备收到Web Server响应Host的报文后，通过查找会话表匹配到步骤2中建立的表项，将报文的目的地址替换为Host的IP地址，将报文的目的端口号替换为原始的端口号，然后将报文发送至Intranet。

> 就是路由器



### NAT Server工作原理

内部Server的私网IPv4地址为192.168.1.2/24，对外的公网IPv4地址为1.1.1.10，端口号都为80，它们之间的映射关系在设备上已提前配置好。当Host访问Server时，设备的处理过程如下：

1. 设备收到Internet上用户访问1.1.1.10的报文的首包后，查找并匹配到Server-Map表项，将报文的目的IP地址转换为192.168.1.2。
2. 设备建立会话表，然后将报文发送至Intranet。
3. 设备收到Server响应Host的报文后，通过查找会话表匹配到步骤2中建立的表项，将报文的源地址替换为1.1.1.10，然后将报文发送至Internet。
4. 后续Host继续发送给Server的报文，设备都会直接根据会话表项的记录对其进行转换，而不会再去查找Server-map表项。



## 打洞流程

假设存在两台设备 A 和 B，它们分别位于各自的 NAT_A 和 NAT_B 之后。此时 A 第一次尝试和 B 建立点对点连接，向 NAT_B 发送数据包；然而 NAT_B 经过查表发现，之前并没有 A 和 B 的映射（即 A 的请求无法被转发到 B），于是来自 A 的数据包就会被丢弃。

为了能绕过 NAT 的限制，我们需要借助一台公网上的服务器 S 做地址转发。

![img](https://webrtc.mthli.com/35b5a637552539f54e7ec3f8afba3f8c/hole-punching.png)

1. A 与 S 建立连接（Session A-S），向 S 注册自己的内网地址 `10.0.0.1:4321` ；S 会同时记录 A 在公网的地址 `155.99.25.11:62000` 。B 与 S 建立连接（Session B-S），向 S 注册自己的内网地址 `10.1.1.3:4321` ；S 会同时记录 B 在公网的地址 `138.76.29.7:31000` 。
2. A 向 S 发送请求，获取 B 的地址（Request Connection to B）；**S 会同时把 A 的地址转发给 B（Forward A’s Endpoints to B）**。然后 A 和 B 都开始尝试相互向对方发送数据包。
3. 当 A 向 B 第一次发送数据包时（Send to B at）会在 NAT_A 中产生映射 `(10.0.0.1:4321, 138.76.29.7:31000)` ；此时 NAT_B 并没有 A 和 B 的映射记录，数据包仍然会被丢弃。
4. 当 B 向 A 第一次发送数据包时（Send to A at）会在 NAT_B 中产生映射 `(10.1.1.3:4321, 155.99.25.11:62000)` ；因为之前 NAT_A 已经创建了 A 和 B 的映射，所以 B 请求成功。
5. 当 A 向 B 第二次发送数据包时，因为 NAT_B 也有了 A 和 B 的映射记录，所以 A 也请求成功。于是打洞完成，A 和 B 可以直接建立点对点连接（Session A-B）。



## 其他技术

- [Interactive Connectivity Establishment](https://en.wikipedia.org/wiki/Interactive_Connectivity_Establishment) (ICE) is a complete protocol for using STUN and/or TURN to do NAT traversal while picking the best network route available. It fills in some of the missing pieces and deficiencies that were not mentioned by STUN specification.

- [Session Traversal Utilities for NAT](https://en.wikipedia.org/wiki/STUN) (STUN) is a standardized set of methods and a network protocol for NAT hole punching. It was designed for UDP but was also extended to TCP.

- [Traversal Using Relays around NAT](https://en.wikipedia.org/wiki/Traversal_Using_Relays_around_NAT) (TURN) is a relay protocol designed specifically for NAT traversal.

- NAT hole punching

  is a general technique that exploits how NATs handle some protocols (for example, UDP, TCP, or ICMP) to allow previously blocked packets through the NAT.

  - [UDP hole punching](https://en.wikipedia.org/wiki/UDP_hole_punching)
  - [TCP hole punching](https://en.wikipedia.org/wiki/TCP_hole_punching)
  - [ICMP hole punching](https://en.wikipedia.org/wiki/ICMP_hole_punching)

- [Socket Secure](https://en.wikipedia.org/wiki/SOCKS) (SOCKS) is a technology created in the early 1990s that uses proxy servers to relay traffic between networks or systems.