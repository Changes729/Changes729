> 参考资料
>
> - [CUBEMX](https://www.st.com/zh/development-tools/stm32cubemx.html)
> - [platformIO上传程序到stm32失败](https://blog.csdn.net/nick_young_qu/article/details/108217987)：解决方案修改工程配置文件，在工程配置文件`platformio.ini`中`[env...]`下添加`upload_flags = -c set CPUTAPID 0x2ba01477`
> - [stm32duino](https://github.com/stm32duino)/**[wiki](https://github.com/stm32duino/wiki)**
> - [stm32duino](https://github.com/stm32duino)/**[Arduino_Core_STM32](https://github.com/stm32duino/Arduino_Core_STM32)**

# STM32

STM32 使用 HID 需要在 Platform.ini 中 配置 `PIO_FRAMEWORK_ARDUINO_ENABLE_HID`

