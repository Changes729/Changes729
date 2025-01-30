> 参考资料：
>
> - [Installation guide](https://wiki.archlinux.org/title/Installation_guide)
> - [Windows10/archlinux双系统安装记录](https://zhuanlan.zhihu.com/p/126725824)

# Archlinux 安装

## 步骤总览

Archlinux操作系统需要你手动操作进行分区、软件包安装、启动引导器设置、软件包下载、用户设置等一系列操作。可以说，使用Archlinux，你的电脑才是真正意义上的"你的电脑"——它将足够干净，而且你也足够了解它。

安装Archlinux也是需要一个PC环境的。这个PC环境我们称为"引导系统"。如果你已经有了一台Linux，那么这台Linux就可以是引导系统。但是对于一台没有任何操作系统的笔记本电脑而言，你往往需要一个U盘作为引导系统。

有了U盘引导系统后，你需要进入BIOS，设置启动顺序，使系统从U盘启动，然后使用U盘内的引导系统，为电脑的硬盘分区、下载操作系统等操作。

## 构建引导系统

略，可以直接dd。

## 修改BIOS

略。百度。

## 安装系统

- 设置键盘：`loadkeys de-latin1`
- 验证启动方式：`ls /sys/firmware/efi/efivars`
- 联网：`dhcpcd` 或 `wifi-menu`
- 更新系统时间：`timedatectl  set-ntp true`
- 分区：`gdisk`
    - `p`：查看分区情况
    - `n`：新建分区
    - `wq`
    - 分区方案：
        - EFI启动：512M
        - ~~交换分区：4G~~ ：请考虑使用 [zram](https://wiki.archlinux.org/title/Zram#Usage_as_swap)
        - 根目录：100G+
        - home目录：剩余（和根目录配合好）
- 分区格式化：
    - ext: `mkfs.ext4`
    - swap: `mkswap`、`swapon`
    - efi：`mkfs.fat -F 32 /dev/sdxY`
- 安装包
    - 更新 `key-ring`: `pacman -Syy archlinux-keyring`
    - 向系统安装包：`pacstrap /mnt base linux linux-firmware`（需要先挂载/boot分区）
    - 网络包：`pacstrap /mnt dhcpcd netctl`, 提供 `dhcpcd` 和 `wifi-menu`
- 记录挂载表：`genfstab -U /mnt >> /mnt/etc/fstab`
- 切换运行环境：`arch-chroot /mnt`
- 修改时区：
    - `ln -sf /usr/share/zoneinfo/Region/City /etc/localtime`
    - `hwclock --systohc`
- 本地化：
    - `vim /etc/locale.gen`
    - `locale-gen`
    - `vim /etc/locale.conf`, 写入 `LANG=en_US.UTF-8`
    - `vim /etc/vconsole.conf`, 写入 `KEYMAP=de-latin1`
- 网络设置：
    - hostname文件：`/etc/hostname`: `127.0.0.1 localhost`、`::1  localhost`
    - resolv.conf：`nameserver [0.0.0.0]`
- `mkinitcpio -P`
- 安装启动引导器 Grub，注意，双系统安装os-prober已经够了。但是grub需要修改内容，有一个prober开关没有关闭。
``` sh
pacman -S grub efibootmgr os-prober 
grub-install --target=x86_64-efi --efi-directory=/boot --bootloader-id=archlinux
grub-mkconfig -o /boot/grub/grub.cfg
```

- 修改root密码

完工。



## 扩展空间

有图形化界面的，可以使用 gparted，直接拉就行，很方便。

