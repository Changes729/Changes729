> 参考资料：
>
> - [Network Bridge](https://wiki.archlinux.org/title/Network_bridge)
> - [Software access point](https://wiki.archlinux.org/title/Software_access_point#Wi-Fi_link_layer)
> - [Bridge with netctl](https://wiki.archlinux.org/title/Bridge_with_netctl)

# 无线 AP 与网络桥接

## [配置 DHCP](https://wiki.archlinux.org/title/Dhcpd)

- 安装 DHCP：`pacman -S dhcpd`

- 配置一个网卡 ip，注意这个 ip 要和网关 ip 一致：`ip addr add dev eth0 139.96.30.100/24`

  - 删除 ip 可以用：`ip addr del 139.96.30.100/24 dev eth0`

- 配置 DHCP 文件 `/etc/dhcpd.conf`：

  ```txt
  option domain-name-servers 8.8.8.8, 8.8.4.4;
  option subnet-mask 255.255.255.0;
  option routers 139.96.30.100;
  subnet 139.96.30.0 netmask 255.255.255.0 {
    range 139.96.30.150 139.96.30.250;
  }
  ```

  其中，路由器就是网关

- 拷贝 DHCP 服务：`cp /usr/lib/systemd/system/dhcpd4.service /etc/systemd/system/dhcpd4@eth0.service`

  这个目的是只针对某一个网卡进行 DHCP 服务。手动开启：`dhcpd -4 -cf /etc/dhcpd.conf -pf /run/dhcpd4/dhcpd.pid eth0`



## 配置网桥

[Network Bridge](https://wiki.archlinux.org/title/Network_bridge) 方案失败了，[Bridge with netctl](https://wiki.archlinux.org/title/Bridge_with_netctl) 成功了。

- 配置网桥配置文件，` /etc/netctl/bridge`：

  ```txt
  Description="Example Bridge connection"
  Interface=br0
  Connection=bridge
  BindsToInterfaces=(eth0)
  MACAddress=eth0
  IP=static
  Address='192.168.10.254/24'
  Gateway='192.168.1.1'
  ## Ignore (R)STP and immediately activate the bridge
  SkipForwardingDelay=yes
  ```

  我这里把网桥的网关设置成了 `192.168.1.1` 目的是我的无线网联网后能上公网的网关是这个 ip

- 开启网桥：`netctl start/enable bridge`

- 设置桥接：`ip link set eth0 master bridge_name`



## [无线 AP](https://wiki.archlinux.org/title/Software_access_point#Wi-Fi_link_layer)

- 编写 AP 配置文件 `hostapd.conf`：

  ```txt
  # the interface used by the AP
  interface=wlp4s0
  
  # the channel to use
  channel=1
  bridge=br0
  
  driver=nl80211
  
  # the name of the AP
  ssid=testAP
  ```

  这是一个无密码的 AP，设置了网卡以及桥接。

- 开启 AP：`hostapd hostapd-minimal.conf`