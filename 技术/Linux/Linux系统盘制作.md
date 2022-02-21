> *参考资料：*
>
> [[HarmonyOS] Linux下制作树莓派系统盘](https://harmonyos.51cto.com/posts/1675)：`dd`方法
>
> [Mac下制作树莓派系统盘](https://www.jianshu.com/p/8528907a9c3d)：文章中解释了一些参数
>
> [[Windy] 从零开始制作一个Linux ISO镜像](https://www.cnblogs.com/aWxvdmVseXc0/p/15553891.html)：教学Linux内核编译。busybox、syslinux（BIOS启动）、system-boot（UEFI启动）
>
> [[Arch Wiki] Archiso](https://wiki.archlinux.org/title/Archiso_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))：教学Archlinux内核制作。教学如何使用archiso构建自定义系统ISO
>
> [[GitLab] ArchISO](https://gitlab.archlinux.org/archlinux/archiso)、[SysLinux](https://wiki.syslinux.org/wiki/index.php?title=Development)、[xorriso](https://www.gnu.org/software/xorriso/)



# Linux系统盘

本文主要解决两个问题：

1. 如何制作Linux操作系统镜像
2. 如何制作Linux系统盘



## 如何制作Linux操作系统镜像

> 从操作上来看，Archlinux 提供的 ArchISO 更加简洁、规范。但是简介和规范意味着有许多程式化的内容被隐藏，这也对使用者的素质有了一定的要求——优质的使用者需要知道背后的运作原理。而当你想要去了解背后的原理时，抛开这个软件从零制作ISO是一条必经之路。
>
> - ArchISO 在背后做了哪些事情？
>   - ArchISO 用户
>   - 自定义软件仓库
> - 如何通过ArchISO制作其他平台的ISO？

### 注意点

1. 目前每次制作系统镜像，都需要先删除`work/`目录。



### 详解

`xorriso`是最终用来制作ISO的工具。

> - xorriso为什么叫这个？
> - ISO 9660是什么？
> - xorriso有哪些功能？



## 如何制作Linux系统盘

### 准备操作系统镜像

首先你需要准备一个[操作系统镜像](https://www.raspberrypi.org/downloads/)。

### 准备SD卡连接电脑

有些电脑没有SD卡读卡器，可以去购买一个`TF卡/SD卡读卡器`

通过`df -h`去找SD卡

### 制作系统盘

```markup
sudo dd bs=4M if=[你的镜像] of=[SD卡位置]
```

> `bs=4m` 指的是同时设置读入/输出的块大小为 4m bytes 个字节，

