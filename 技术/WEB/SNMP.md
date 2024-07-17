> 参考资料
>
> - [How SNMP Works - a quick guide](https://www.youtube.com/watch?v=2IXP0TkwNJU)
> - [List of TCP and UDP port numbers](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers)
> - [获取网络设备SNMP OID值](https://www.bilibili.com/video/BV1Bq4y1v74G/?spm_id_from=333.788.recommend_more_video.0&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)

# SNMP

## 关键词

- OID（Object Identifier，设备检测）
- MIB（Management Information Base，管理信息库）
  - MIB 浏览器：需要查看MIB值，以及添加厂商私有的MIB库
- Polling（`161`）
- Notifying（`162`）
- 网络管理平台
  - openmanager
  - solarwinds
  - zabbix



## 摘记

SNMP 通常用来发现网络中的 SNMP 设备，获取信息的同时可以对 SNMP 设备进行配置。多用在网关设备上。