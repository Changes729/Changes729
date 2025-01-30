> 参考资料
>
> - [CUBEMX](https://www.st.com/zh/development-tools/stm32cubemx.html)
> - [platformIO上传程序到stm32失败](https://blog.csdn.net/nick_young_qu/article/details/108217987)：解决方案修改工程配置文件，在工程配置文件`platformio.ini`中`[env...]`下添加`upload_flags = -c set CPUTAPID 0x2ba01477`
> - [stm32duino](https://github.com/stm32duino)/**[wiki](https://github.com/stm32duino/wiki)**
> - [stm32duino](https://github.com/stm32duino)/**[Arduino_Core_STM32](https://github.com/stm32duino/Arduino_Core_STM32)**
> - [dfu-util - Device Firmware Upgrade Utilities](https://dfu-util.sourceforge.net/)：STM32 USB Download
>   - [lupyuen](https://github.com/lupyuen)/[bluepill-bootloader](https://github.com/lupyuen/bluepill-bootloader)
> - https://stm32-base.org/assets/pdf/boards/original-schematic-STM32F103C8T6-Blue_Pill.pdf

# STM32

STM32 使用 HID 需要在 Platform.ini 中 配置 `PIO_FRAMEWORK_ARDUINO_ENABLE_HID`



## 硬件相关

STM32尽量[不要使用硬件IIC](https://blog.csdn.net/weixin_41101205/article/details/88723007?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPaidSort-1-88723007-blog-139848940.235%5Ev43%5Epc_blog_bottom_relevance_base7&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPaidSort-1-88723007-blog-139848940.235%5Ev43%5Epc_blog_bottom_relevance_base7&utm_relevant_index=1)；使用软件IIC的时候出现了IIC-BUSY锁死的情况。



## BOOT 方式

| BOOT0 | BOOT1 | 启动方式      |
| ----- | ----- | ------------- |
| LOW   | -     | FLASH         |
| HIGH  | LOW   | System Memory |
| HIGH  | HIGH  | embedded SRAM |

FLASH 就是正常程序烧写的启动模式。

Embedded SRAM [文章中](https://blog.csdn.net/weixin_51087836/article/details/111937931?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166909962716782425675521%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166909962716782425675521&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-111937931-null-null.142^v66^wechat,201^v3^control,213^v2^t3_control2&utm_term=boot&spm=1018.2226.3001.4187) 说是为了方便**程序调试**。

而 System Memory 则是 ISP（In System Program） 启动方式，它通过检测USB、CAN 以及 USART 等方式来更新 FLASH，所以这种方式也被用来从串口下载程序用。



## OSC 和 OSC 32

OSC 是外部高速时钟，一般为 8M，文档里要求 4M~16MHz

OSC 32 是外部低速时钟，一般为 32.768 KHz



## 供应商

- [STM32F401RET6](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.13.df106a4bx0gSFz&id=602727308211) 0.206/个 84MHz/512KB/96KB RAM
- [STM32F401CEU6](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.9.df106a4bx0gSFz&id=585800874556) 0.303/个 84MHz/512KB/96KB RAM
- [STM32F401RCT6](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.11.df106a4bx0gSFz&id=585949747279) 0.078/个 84MHz/256KB/64KB RAM
- [STM32F103RCT6](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.28.23696a4bsCNKHx&id=523892305756) 0.111/个 72MHz/256KB/48KB RAM

