> 参考资料
>
> - [内核模块](https://wiki.archlinuxcn.org/wiki/%E5%86%85%E6%A0%B8%E6%A8%A1%E5%9D%97)
> - [How to create a Systemd service in Linux](https://www.shubhamdipt.com/blog/how-to-create-a-systemd-service-in-linux/)：有很多 service 编写的example

# 初始化进程

## 内核模块加载

内核模块的自动加载只需要在 `/etc/modules-load.d/[program].conf`  添加模块即可。

```txt
# /etc/modules-load.d/virtio-net.conf
# Load virtio_net.ko at boot
virtio_net
```

