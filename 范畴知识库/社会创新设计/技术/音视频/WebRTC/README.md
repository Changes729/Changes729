参考资料： 

> - [Streaming audio with ffmpeg rtp](https://www.youtube.com/watch?v=DmPlSqt_3Ww)：ffmpeg command line rtc audio stream C/S
> - [WebRTC 使用入门](https://webrtc.org/getting-started/overview?hl=zh-cn)：WebRTC 指南
> - [WebRTC samples](https://webrtc.github.io/samples/)：本地WebRTC
> - [j0r1](https://github.com/j0r1)/[JRTPLIB](https://github.com/j0r1/JRTPLIB)：开源RTPLib
> - [resiprocate](https://github.com/resiprocate)/[resiprocate](https://github.com/resiprocate/resiprocate)：开源 SIP服务器
> - [coturn](https://github.com/coturn)/[coturn](https://github.com/coturn/coturn)：开源 TURN 服务器
> - [meetecho](https://github.com/meetecho)/[janus-gateway](https://github.com/meetecho/janus-gateway)：Janus WebRTC Server
> - **[WebRTC-Example](https://github.com/shanet/WebRTC-Example)**
> - [Icecast](https://wiki.archlinux.org/title/Icecast)：stream media
>   - [kairess](https://github.com/kairess)/[music-streaming-server](https://github.com/kairess/music-streaming-server)：网络电台
> - [WebRTC Tutorial: Simple video chat](https://www.scaledrone.com/blog/webrtc-tutorial-simple-video-chat/)：视频聊天 Demo，可以作为学习案例

# WebRTC

## 关键词

- RTC（real-time communication）
- ICE（Interactive Connectivity Establishment，交互式连接建立）
- TURN（Traversal using Relay NAT）
  - NAT（Network address translation）
- STUN（Session Traversal Utilities for NAT）
- SDP（Session Description Protocol）



**01 Signaling（信令）**

The discovery and negotiation process of WebRTC peers is called signaling. For two devices in different networks to find each other they need to use a central service called a **signaling server**. Using the signaling server two devices can discover each other and exchange negotiation messages. WebRTC does not specify signaling; different technologies such as Websockets can be employed for it.

WebRTC节点的发现和协商过程称为信令。对于不同网络中的两个设备，它们需要使用称为信令服务器的中央服务来找到对方。使用信令服务器，两个设备可以发现彼此并交换协商消息。**WebRTC没有指定信令;可以使用不同的技术，如Websockets。**



**02 ICE Candidates（ICE 候选）（Interactive Connectivity Establishment，交互式连接建立）**

Two peers exchange ICE candidates until they find a method of communication that they both support. After the connection has been established ICE candidates can be traded again to upgrade to a better and faster communication method.

两个对等体交换 ICE 候选，直到他们找到一种他们都支持的通信方法。连接建立后，ICE 候选可以再次**协商**，以升级到更好更快的通信方法。



**03 STUN Server（Session Traversal Utilities for NAT）**

STUN servers are used to get an external network address and to pass firewalls.

STUN服务器用于获取外部网络地址并翻越防火墙。



## 连接建立过程

*以下内容并不正确，请参考 [信令与视频通话](https://developer.mozilla.org/zh-CN/docs/Web/API/WebRTC_API/Signaling_and_video_calling)*

```sequence
Title: WebRTC 通信建立流程
对象A->信令服务器:建立连接
Note Left of 对象A:创建 configuration，iceServers（stun server）信息
Note Left of 对象A:创建 RTCPeerConnection
Note Left of 对象A:打开本地媒体，跟踪流
Note Left of 对象A:当本地 RTCPeer 建立完毕时
对象A->信令服务器: 发送自身的 candidate 信息

对象B->信令服务器:建立连接
Note Right of 对象B:创建 configuration，iceServers（stun server）信息
Note Right of 对象B:创建 RTCPeerConnection
Note Right of 对象B:打开本地媒体，跟踪流
Note Right of 对象B:当本地 RTCPeer 建立完毕时
对象B->信令服务器: 发送自身的 candidate 信息
对象B->信令服务器: 发送自身 sdp 协商信息

信令服务器->对象B: 发送对象A candidate 信息
Note Right of 对象B: 添加对象A 的 candidate 信息

信令服务器->对象A: 发送对象B candidate 信息
Note Left of 对象A: 添加对象B 的 candidate 信息
信令服务器->对象A: 发送对象B sdp 信息
对象A->信令服务器: 创建本地 sdp 信息并应答
```



