> 参考资料：[The Buildroot user manual](https://buildroot.org/downloads/manual/manual.html#_how_buildroot_works)
>
> [Buildroot — part 2. Creating a configuration of your board; application of external tree, rootfs-overlay, post-build scripts](https://boozlachu.medium.com/buildroot-part-2-bffac4b0b86a)
>
> [Manual build howto](https://linux-sunxi.org/Manual_build_howto)：全志技术支持，里面有介绍 [XunLong Orange Pi Zero2](https://linux-sunxi.org/Xunlong_Orange_Pi_Zero2) 的一些资料；

# Buildroot

## Xunlong Orange Pi Zero2

在 Linux dts 中选择 [sun50i-h616-orangepi-zero2.dts](https://github.com/torvalds/linux/blob/master/arch/arm64/boot/dts/allwinner/sun50i-h616-orangepi-zero2.dts)

在 Uboot 中选择 orangepi_zero2_defconfig



## 一些操作

- `make savedefconfig`：用于保存默认配置

