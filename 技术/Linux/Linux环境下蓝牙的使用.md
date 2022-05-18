# Linux环境下蓝牙的使用

> 本文目的,是成功在Linux环境下使用bluetoothctl连接蓝牙,并播放音频.

## 相关软件及说明

**bluetoothctl:** 蓝牙客户端, 我们通过它执行搜索蓝牙,连接蓝牙和断开蓝牙的操作. 它使用DBus和**bluetoothd**进行交互.

**bluetoothd:** 蓝牙服务端, 负责管理蓝牙设备, 提供DBus功能接口.

**pavucontrol:** Linux混音功能GUI应用软件, 我们在PC上测试蓝牙时最终会根据此控制蓝牙音频.

**d-feet:** 一个好用的dbus嗅探器, 可以用它来发送一些dbus消息.

## Linux 下支持蓝牙, 以Ubuntu为例

> 正常情况下, Ubuntu应该已经安装了蓝牙相关的应用软件,并启动了后台服务, 这时可以使用`bluetoothctl`命令或者`systemctl status bluetoothd` 查看系统蓝牙情况.

- 安装pulseaudio

  `apt install pulseaudio pulseaudio-module-bluetooth`

  *pulseaudio*是linux **高级音频管理模块(Advanced Linux Sound Architecture, ALSA)** 的控制应用程序, ALSA主要文件体现在`/dev/snd/pcmCxDx`.

- 安装bluez

  `apt install bluez bluez-btsco`

  *bluez*是Linux下使用最广的蓝牙模块, 其包括了**bluetoothd守护进程**, 蓝牙内核模块, 以及客户端**bluetoothctl**. 当然, bluetooth内还支持安卓的客户端, 但是好像有文章说bluez的蓝牙不好用, 所以安卓自己做了一个, 具体是什么忘了.

- 为pulseaudio添加蓝牙支持

  在`/etc/pulse/system.pa`文件的末尾添加两个模块

  ```conf
  load-module module-bluetooth-policy
  load-module module-bluetooth-discover
  ```

  > 为什么是`system.pa`而不是`default.pa`, 因为我们的`bluetoothd`是由系统启动的守护进程.

  > 一般来说添加这两个module应该就足够了, 如果还是失败了, 就需要处理错误了. 这时候比较麻烦, 需要拿到bluez日志然后去google. 可以使用`journalctl -n 20`去找蓝牙的错误日志. 

  > 从这里添加pulseaudio模块也可以看出, 蓝牙和音频是两个不同的模块, 作为Linux后台应用程序, 它们的职责往往是为系统提供方便易用的拓展功能. 两者应用程序使用Dbus作为进程间通讯的主要手段. 每一个应用程序有自己的职责,这种单一职责原则真是深入了Linux应用开发思维中.

- 重启pulseaudio和bluetoothd

  ```sh
  # 先重启pulseaudio
  pulseaudio -k # 关闭 pulseaudio
  pulseaudio --start # 开启 pulseaudio
  
  # 再重启bluetoothd
  # systemctl restart bluetooth.service
  systemctl start bluetooth.service
  ```

- 使用bluetoothctl连接蓝牙

  ```sh
  # 进入bluetoothctl控制台
  bluetoothctl
  
  # 查看操作
  help
  
  power on 
  agent on 					# 开启蓝牙适配器
  scan on  					# 扫描蓝牙
  pair 11:22:33:44:55:66 		# 配对蓝牙
  connect 11:22:33:44:55:66 	# 连接蓝牙(服务)
  trust 11:22:33:44:55:66 	# 信认蓝牙, 下次蓝牙开机时自动连接
  
  disconnect <11:22:33:44:55:66> # 断开蓝牙
  remove 11:22:33:44:55:66 	# 移除蓝牙设备
  
  device 						# 查看当前系统记忆的设备
  ```

  > bluetoothctl是可以使用tab补全的.

- 播放音频

- 查看/调整音频

  使用`pavucontrol`查看当前系统的**音频输入(Playback)**, 不出意外应该有一个输入源, 如果是网页版的音乐播放器, 那么会有一个网页的Playback. 查看系统的**输出源(Output Devices)**, 这里应该有一个蓝牙设备.

至此, Linux应该可以成功连接你的蓝牙耳机并且播放音乐了.

## 使用 d-feet

`sudo apt install d-feet`

`d-feet`可以看到`bluetoothd`所提供的所有DBus功能. 这里不详细说明了. 直接在`System DBus`里搜索Bluez就可以.

## 关于HSP/HFP

HSP和HFP是电话相关的蓝牙协议, 后面会提到. 如果想要在Linux上支持这两个协议, 可以考虑安装`ofono`, 但是, 我在Ubuntu下是失败了.

## Refer

- [Archlinux - Bluetooth Headset](https://wiki.archlinux.org/title/Bluetooth_headset_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

