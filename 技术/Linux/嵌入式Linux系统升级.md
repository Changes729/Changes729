> 参考资料
>
> - [[elinux] Device Tree Usage](https://elinux.org/Device_Tree_Usage)：比较详细的介绍了 dts 文件的设计
> - https://www.kernel.org/doc/Documentation/devicetree/bindings/sound/：有比较详细的 dts 说明文档，在linux kernel 文档里面也有
> - [OrangePi zero 最小软件系统构建过程记录](https://whycan.com/t_3253.html)：里面有一些非常值得学习的操作。

# 嵌入式Linux

## 内核相关

- `spi-nor`：这个是spi对应的nor-flash的驱动设备。



## 驱动相关

### GPIO

> 参考资料：
>
> - [[SUNXI] GPIO](https://linux-sunxi.org/GPIO)：SUNXI 的 GPIO教程，里面说明了 PC0 这种GPIO口如何计算成 gpiochip0 的ID

现在GPIO口都是用 libgpiod 来控制了。



### SPI 用户设备驱动

> 参考资料：
>
> - [How to use SPI from Linux userland with spidev](https://wiki.stmicroelectronics.cn/stm32mpu/wiki/How_to_use_SPI_from_Linux_userland_with_spidev)：stm SPI 配置，同时有 spidev_test 使用方式。注意我们测试的时候需要短接 MOSI 和 MISO
>
>   Enable spidev by adding a compatible *spidev*.
>
> - [[SUNXI] SPIdev](https://linux-sunxi.org/SPIdev)：关于如何配置 SUNXI Kernel SPI 的文件说明，当然也有内核态和用户态的代码
>
> - [No SPIDEV device on Allwinner H3](https://archlinuxarm.org/forum/viewtopic.php?f=60&t=15395&sid=ff7396aa907dc08d33a1dc8ad0efe37d)：教了一些方式来看设备配置
>
> - [Linux设备树（Device Tree）](https://blog.csdn.net/qq_41596356/article/details/125312933?ops_request_misc=&request_id=&biz_id=102&utm_term=linux%20%E8%AE%BE%E5%A4%87%E6%A0%91&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-2-125312933.142^v88^insert_down38v5,239^v2^insert_chatgpt&spm=1018.2226.3001.4187)：简单介绍了 Device Tree
>
> - [Accessing SPI Devices in Linux](https://www.emcraft.com/som/stm32f7-240/accessing-spi-devices-in-linux)：这里也有一些关于如何查看SPI设备的说明，值得参考
>
> - [Orange Pi One](http://www.orangepi.cn/html/hardWare/computerAndMicrocontrollers/service-and-support/Orange-pi-One.html)：他里面的使用文档比较需要，特别是如何开启硬件和如何使用的
>
> - [rohm,dh2228fv](https://www.rohm.com/products/data-converter/d-a-converters/8bit-d-a/bh2228fv-product)：这个应该就是 SPI 配置的设备，是一个 DAC

在Linux内核中，有一个叫 `spidev.c`的驱动文件。这边使用 `orangepi-one`，buildroot 默认的 `sun8i-h3-orangepi-one.dts` 内部默认并没有支持 spi。

我在dts中添加了如下内容后可以成功注册 `spidev.c`。（当然要开启其他SPI配置）

```c
&spi0 {
  status = "okay";
  pinctrl-names = "default";
  pinctrl-0 = <&spi0_pins>;
  
  spidev@0 {
    compatible = "linux,spidev","rohm,dh2228fv";
    reg = <0>;
    spi-max-frequency = <50000000>;
  };
};
```

这里的 `rohm,dh2228fv` 是无意义的，可以看第一篇文章（STM32那一篇），只是为了符合规定让 spidev 设备能出来。



## Sound

> 参考资料：
>
> - 驱动例子：
>   - [Linux声卡驱动添加虚拟codec](https://stackdump.cn/linux%E5%A3%B0%E5%8D%A1%E9%A9%B1%E5%8A%A8%E6%B7%BB%E5%8A%A0%E8%99%9A%E6%8B%9Fcodec/)：虚拟声卡，从I2S重定向。
>   - [Simple-Card](https://www.kernel.org/doc/Documentation/devicetree/bindings/sound/simple-card.txt)：Linux 声卡配置说明。
> - [f1c100s linux 5.2 USB已完美驱动，host+device完美运行](https://whycan.com/t_3087.html)：USB驱动参考，未看。
> - [请问有没有大神搞定了f1c100s的主线kernel4.19下的声卡驱动？](https://whycan.com/t_2041.html)：sunxi 声卡驱动，但是内核好像已经有了。
> - [H3 I2S0 DT overlay](https://forum.armbian.com/topic/5643-h3-i2s0-dt-overlay/)：I2S 虚拟声卡已经验证成功。



## 问题记录

Q1：Linux是如何挂载根文件目录的？

Q2：如何修改树莓派的rootfs？

