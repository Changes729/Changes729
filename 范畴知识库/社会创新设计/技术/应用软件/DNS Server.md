> 参考资料：
>
> - [[Arch Wiki] unbound](https://wiki.archlinux.org/title/Unbound#Using_unbound-control)：详细介绍了 unbound 的安装和启动，但是没有介绍如何设置正反向代理，在配置文件上介绍比较少
> - [Unbound服务的安装与运行管理](https://www.cnblogs.com/rusking/p/7591938.html)：这个是老版本的，里面有些仅参考
> - [将 Unbound 配置为简单的转发 DNS 服务器](https://www.redhat.com/sysadmin/forwarding-dns-2)：就简单展示了 `stub-zone` 和 `forward-zone`
> - [unbound document](https://unbound.docs.nlnetlabs.nl/en/latest/index.html)

# DNS Server（unbound）

unbound 的安装和启动略。

```sh
include: "/etc/unbound/local.d/*.conf"
```

这句话可以从对应目录下导入所有配置文件。

```sh
interface: [ip]
```

这个配置默认是只读取localhost的，所以这里需要将ip设置为局域网ip。其他一些基本配置：

```sh
# 如果需要使用 systemctl 管理，则需要配置
do-daemonize: no

# 允许访问
access-control: [192.168.1.0/24] allow
username: ""

# 对一些不安全的域名不筛查
domain-insecure: "domain.com"
```



最后是转发设置：

```sh
# domain.conf

server:
        local-zone: "box.test." static

        # forward
        local-data: "box.test. 86400 IN SOA dns1.box.test. root.box.test 1 1D 1H 1W 1H"
        local-data: "dns1.box.test. IN A 192.168.2.191"
        local-data: "dns2.box.test. IN A 192.168.2.191"
        local-data: "www.box.test. IN A 192.168.2.191"

        # backward
        local-data-ptr: "192.168.2.191 dns1.box.test"
        local-data-ptr: "192.168.2.191 dns2.box.test"
        local-data-ptr: "192.168.2.191 www.box.test"
```

