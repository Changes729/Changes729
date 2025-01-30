# Pulse Audio 简介

> 蓝牙开发, 特别是蓝牙音频开发时, 若对音频一点概念都没有, 那在看代码的过程中一定会有特别多的疑问. 

> 文本的目的是介绍Linux下的音频开发, 铺上一层简单的概念, 方便后续遇到问题知道应该google哪些关键词.

## 音频文件简介

### PCM(脉冲编码调制, Pulse Code Modulation)

首先要明确, PCM是**无压缩的纯音频数据**, 是经过**采样/保持/量化/编码**后的纯AD数据. 其编码有**均匀量化**和**非均匀量化**两种方式.

<img src="https://pic2.zhimg.com/80/v2-72cb76a04d27528ce7f55099ccd6a841_720w.jpg" alt="img" style="zoom:50%;" />

其中,均匀量化就是**相同时间间隔**, 对音频模拟信号在伏值内, 使用多少**比特位进行均匀量化**.

从`ffmpeg -codecs`里面可以看到各种不同的PCM格式音频, 主要就提及了三个信息 - `基本数据类型`, `比特位`以及 `大小端存储`.  例如`s16be`, 就是指**signed 16-bit big-endian**.

> Linux下都是小端存储数据的, 而网络传输的数据都是大端存储的. Linux上可以用
>
> `echo -n I | od -to2 | head -n1 | cut -f2 -d" " | cut -c6 ` 
>
> 来判断系统是否是小端存储. *[来源](https://qastack.cn/server/163487/how-to-tell-if-a-linux-system-is-big-endian-or-little-endian)*

由于音频数据的时间属性, 音频数据除了采样编码方式外, 还有时间, 也就是**采样率**, 在`ffmpeg`中, 采样率用`-ar` *(audio sampling rate)* 指定. 从数据上看, 采样率乘以编码方式就是1s内音频数据大小了.

至于双声道就没有什么特别的好说了, 还不是人有两只耳朵. 在`ffmpeg`中, 声道使用`-ac` *(audio channels)* 指定.

> 这里提一嘴, 双声道(stereo)音频虽然在数据样本上大了一倍, 但是从音频效果上好了不仅一倍. 所以音频都建议听双声道的. 有兴趣可以看这个[评测视频](https://www.bilibili.com/video/BV1db411t7t5).

> 看到这里其实大伙儿可以拿一个纯PCM文件来玩了, 网上有很多MP3转PCM的工具, 我就下了一首流行歌然后转PCM, 然后用ffmpeg播放, 最后就用这个PCM文件用C代码放声音给蓝牙.

PCM非均匀量化, 有`PCM A律编码`和`PCM μ律编码`. [μ律](https://baike.baidu.com/item/%CE%BC%E5%BE%8B) 和 [A律](https://baike.baidu.com/item/A%E5%BE%8B)都是为了解决均匀量化产生较大的信噪比问题而出现的. 因为均匀量化是**周期性** *(等时间隔)*, 和**平均量化**的. 这样在量化中不可避免的会有一个大约`(Δv×Δt)/2`的噪声.  A律和μ律就是使用折线的方式去拟合信号的曲律, 减少噪声.

在`ffmpeg`中, `alaw`和`mulaw`就是A律和μ律的编码方式了.

> 这里提这一点主要是蓝牙音频也是支持A律和μ律的编码方式的, 就了解一下这是啥就行了.

### WAV

<img src="http://images2015.cnblogs.com/blog/708332/201704/708332-20170401230123867-1830898061.png" alt="img" style="zoom: 67%;" />

wav就是在PCM文件前加数据块描述音频数据.

## Sound Play Demo

> 可以看[这个代码](https://github.com/Changes729/c_cpp_project_template/blob/gists/spike/src/alsa-play.c). 可以帮助你理解Pulse Audio.

就关注两点, 一个时域上关注采样率*(sampling rate)*, 音频通道(channels)以及音频时长. 另一个关注**编码方式**, 全部都设置好了之后, 代码就是读文件, 然后写文件.

## ALSA

我们主要以`pavucontrol`来理解`Pulse Audio`, 就是说, Linux的`ALSA (Advanced Linux Sound Architecture, 高级Linux音频架构) `对硬件提供驱动和数据块, 对外提供文件设备.

而`Pulse Audio`就是应用程序和ALSA之间的桥梁, 它关于**混音**, **应用音频通道管理**等功能. 放音的应用程序称为`Playback`, 录音的是`Record`, 两者其实都不需要实际的音频设备, 因为即使没有音频设备, 你依旧可以录下某个应用软件的音频.

可以外放声音的设备是`Output Device`, 可以录音的设备是`Input Device`, 可以把输出设备看作`Record`, 同理也可以把输入设备看作`Playback`.

> 所以可以用ALSA去录一些下不了的歌...

## Bluetooth的音频

Linux上, BT的音频实际上是`bluetoothd`发送dbus, 在在`pulseaudio-bluetooth`中调用`bluetooth-alsa`模块建立蓝牙输入输出音频设备.

但是像我们260x话机不支持整个`bluez`架构,我们没有bluez,也没有pulseaudio, 这个时候就要在C代码内手动的从虚拟声卡里读音频/写音频, 再通过蓝牙发送了. 不过幸好, 我们260x有一个`SCO over PCM`的功能, 可以把它想象成`DMA`,一片数据块可以绕过应用程序的控制直接写入存储区.

> 不过上面这种类似DMA的方式传输数据就不支持重传了, 像A2DP这种高级音频播放协议,就支持重传, 所以这种音频就会有延迟, 当然质量也会好不少.

## Refer

- [Archlinux - PulseAudio](https://wiki.archlinux.org/title/PulseAudio_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
- [SoundPlay Demo](https://github.com/Changes729/c_cpp_project_template/blob/gists/spike/src/alsa-play.c)
- [百度 - 音频格式简介](https://cloud.baidu.com/doc/SPEECH/s/7k38lxpwf)
- [知乎 - 音频格式简介](https://zhuanlan.zhihu.com/p/212318683)
- [CSDN - 音频格式简介](https://blog.csdn.net/xieyi2015/article/details/78408846#t0)
- [通信人 - 信噪比与A律编码](http://www.txrzx.com/i4740.html)