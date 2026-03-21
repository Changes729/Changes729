# Pi-Media

基于树莓派（ARM-Linux）的媒体智能硬件。



基本架构：HTTP 后端、Chrome 前端。



## 硬盒

- Golang HTTPS 后端，启动本地 http 网页，跳转。
- Golang 链接 串口，Websocket 传输信息。



## 游乐能-圳能量

- [x] 上电开机
- [ ] 定时关机
  - [ ] 支持前端配置，定时关机
- [ ] GPIO 检测
- [ ] 混合媒体随机播放器