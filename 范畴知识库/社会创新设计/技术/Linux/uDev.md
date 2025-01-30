> 参考资料：
>
> - [libudev and Sysfs Tutorial](http://cholla.mmto.org/computers/usb/OLD/tutorial_usbloger.html)：uDev 参考代码
> - [udev](https://wiki.archlinux.org/title/Udev)

# uDEV（User Device）

`uDev` 可以实现设备热插拔、用户设备检测等功能。对于不熟悉的设备类型，您可以使用`sudo udevadm info --root  --name=/dev/sdX`来检测设备类型：

```txt
Udevadm info starts with the device specified by the devpath and then walks up the chain of parent devices.
It prints for every device found, all possible attributes in the udev rules key format.
A rule to match, can be composed by the attributes of the device and the attributes from one single parent device.

looking at device '/devices/pci0000:00/0000:00:04.1/usb3/3-2/3-2:1.0/video4linux/video2':
  KERNEL=="video2"
  SUBSYSTEM=="video4linux"
   ...
looking at parent device '/devices/pci0000:00/0000:00:04.1/usb3/3-2/3-2:1.0':
  KERNELS=="3-2:1.0"
  SUBSYSTEMS=="usb"
  ...
looking at parent device '/devices/pci0000:00/0000:00:04.1/usb3/3-2':
  KERNELS=="3-2"
  SUBSYSTEMS=="usb"
  ATTRS{idVendor}=="05a9"
  ATTRS{manufacturer}=="OmniVision Technologies, Inc."
  ATTRS{removable}=="unknown"
  ATTRS{idProduct}=="4519"
  ATTRS{bDeviceClass}=="00"
  ATTRS{product}=="USB Camera"
  ...
```



