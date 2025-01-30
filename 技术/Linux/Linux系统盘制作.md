> 
>
> 参考资料：*
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
>
> [[Arch ARM Wiki] Raspberry Pi 4](https://archlinuxarm.org/platforms/armv8/broadcom/raspberry-pi-4)
>
> [[Bilibili] 【韦东山】嵌入式Linux教程_韦东山手把手教你嵌入式Linux快速入门到精通](https://www.bilibili.com/video/BV1w4411B7a4?p=7&spm_id_from=pageDriver)
>
> [[Bilibili] 【韦东山】bootloader简述](https://www.bilibili.com/video/BV17P4y1P78K?share_source=copy_web)
>
> [[Bilibili] 【韦东山】Linus Linux Kernel简述](https://www.bilibili.com/video/BV19b4y1j77Y?spm_id_from=333.999.0.0)
>
> [[Arch ARM Wiki] Is there any tool to build custom ISO ?](https://archlinuxarm.org/forum/viewtopic.php?f=7&t=10827&sid=d2d541e5d54abae9a1a0ebc631c322cb)、[Where I can found script/tool used to generated root tarbals](https://archlinuxarm.org/forum/viewtopic.php?f=7&t=11119)
>
> [[ArchLinux Wiki] Arch boot process (简体中文)](https://wiki.archlinux.org/title/Arch_boot_process_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)#%E5%BC%95%E5%AF%BC%E5%8A%A0%E8%BD%BD%E7%A8%8B%E5%BA%8F)
>
> [自己动手编译交叉编译链](https://blog.csdn.net/qq_34818535/article/details/81349524?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166789556016782414960525%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166789556016782414960525&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-6-81349524-null-null.142^v63^opensearch_v2,201^v3^control,213^v1^t3_esquery_v2&utm_term=%E7%BC%96%E8%AF%91%E4%BA%A4%E5%8F%89%E7%BC%96%E8%AF%91%E5%B7%A5%E5%85%B7%E9%93%BE&spm=1018.2226.3001.4187)： 使用crosstool-ng编译交叉编译工具链。
>
> [peng-zhihui](https://github.com/peng-zhihui)/**[Planck-Pi](https://github.com/peng-zhihui/Planck-Pi)**



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



# 嵌入式Linux系统盘（ARM）

ArchLinux提供的嵌入式Linux系统，是以`.tar.gz`为后缀名的`rootfs tarball`——压缩包文件。其制作方式与X86-64架构的ISO不同，也和`image`不同，它只是系统包。

根据韦东山的嵌入式教学视频，我们可以知道，一个嵌入式ARM操作系统包括**bootloader**、**Linux内核**、**rootfs**以及**应用二进制程序**。

## Boot Loader

单片机有着少量的内存，我们写过单片机的人都知道，单片机的Rom比较小，一般写单片机都需要进行烧写，烧写的东西就是整个系统的**Boot Loader**。

**Boot Loader**需要了解的内容，除了协议，命令、脚本支持外，由于**Boot Loader**需要加载操作系统，所以它必须指明，支持那些`Flash`设备的查找、读取（如ESP、UEFI、MBR、Hard didsk、USB、LAN等），也需要表明对应设备文件类型的支持，如果不支持文件系统，则无法正确读取操作系统内核文件（如FAT、ext、NILFS等）。

## 内核（操作系统）

内核可以简单理解为操作系统，但实际上，Linux内核包含了诸多内容，以后可以介绍。操作系统的功能无非包括**进程管理**、**内存管理**、**文件和输入输出**。

### 构建嵌入式内核步骤

1. 获取嵌入式板子配套的交叉编译工具链
2. 下载Linux Kernel源码
   - 可以从git主分支下载
   - 推荐从芯片原厂获取
3. 本地配置交叉编译与嵌入式开发环境
4. 指定编译板子配置文件
   - `make  [BOARDNAME]_defconfig`
5. 编译
   - 编译内核镜像：`make -j[N]`
   - 编译设备树：`make dtbs`
   - 编译安装模块驱动：`make modules`

在编译的时候，可以直接用`make all`编译所有内容。由于编译的时候需要通过网络下载所需的文件，如果遇到无法下载的情况（比如我这里就是无法从github下载内容），那么需要手动设置代理：`export https_proxy="https://127.0.0.1:[PORT]"`



## rootfs（根文件系统）

Boot Loader会加载内核，内核最开始会将内嵌的`initramfs`（初始RAM文件系统）解压为最初的rootfs，而后，再通过外部的`initramfs`加载正真的rootfs。



# Linux 硬件系统

