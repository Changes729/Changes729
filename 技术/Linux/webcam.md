> 参考资料：
>
> - [Webcam setup](https://wiki.archlinux.org/title/Webcam_setup)
> - [Capture/Webcam - FFmpeg Wiki](https://trac.ffmpeg.org/wiki/Capture/Webcam)

# Webcam

首先，需要安装 [v4l-utils](https://archlinux.org/packages/?name=v4l-utils) 来查看当前视频设备列表。

```
v4l2-ctl --list-devices
```

然后，安装 [v4l2loopback-dkms](https://archlinux.org/packages/?name=v4l2loopback-dkms) 来对视频录播进行支持

```
# modprobe v4l2loopback exclusive_caps=1
$ ffmpeg -i http://192.168.1.xxx:8080/video -vf format=yuv420p -f v4l2 /dev/video0
```



用 ffmpeg 录制：

`ffmpeg -f v4l2 -framerate 25 -video_size 640x480 -i /dev/video0 output.mkv`



如果用 IP camera：`ffmpeg -i http://192.168.1.191:8080/video -vf format=yuv420p -f v4l2 /dev/video0`



直接使用 ffplay：`ffplay -i /dev/video0`