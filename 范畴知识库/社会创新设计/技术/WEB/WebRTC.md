> *参考资料*
>
> - [关于WebRTC发展的担忧和思考](https://mp.weixin.qq.com/s/gbO2mbxDYS5NZutLIrnbWA)
> - [WebRTC samples](https://webrtc.github.io/samples/)
> - [李超：WebRTC传输与服务质量](https://mp.weixin.qq.com/s/XV0aZLgOeKEOFJ5cOh79Ww)
> - [如何用 Node.js 实现一个简单的 Websocket 服务？](https://mp.weixin.qq.com/s/jrXsXch-wnlTcS2JEKe32Q)
> - 栗伟 WebRTC技术详解 -> [wistingcn](https://github.com/wistingcn)/**[dove-into-webrtc](https://github.com/wistingcn/dove-into-webrtc)**
# WebRTC

关键词:
- 音频部分
    - OPUS/G.711 PCM编码
    - 回音消除
    - 降噪
- 视频部分
    - VP8/H264编码
    - Jitter Buffer
    - 图像增强
- 媒体传输
    - RTP/SRTP/SCTP
    - TURN/STUN
    - ICE/SDP
    - DTLS/UDP
- 网络拓扑
    - Mesh组网
    - MCU( Multipoint Control Unit )
    - SFU( Selective Forwarding Unit )
    - Simulcast联播:是一种SFU技术优化
- 可伸缩视频编码( Scalable Video Coding, SVC )
    - 空间可伸缩:媒体流包含多个不同分辨率的层
    - 时间可伸缩:媒体流包含多个不同帧率的层
    - 质量可伸缩:媒体流包含多个不同码率的层
- 其他直播技术
    - RTMP( Real Time Messageing Protocol, 实时消息传输协议 )
    - RTSP( Real Time Streaming Protocol, 实时流协议 )
        - RTP/RTCP
    - SRT( Secure Reliable Transport, 安全可靠传输 )
    - QUIC( Quick UDP Internet Connection, 快速UDP互联网连接 )
- 统一计划( Unified Plan ) 与 Plan B

