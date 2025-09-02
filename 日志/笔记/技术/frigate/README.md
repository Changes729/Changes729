> 参考资料：
>
> - [Getting started](https://docs.frigate.video/guides/getting_started)
> - [Frigate Dockerfile](https://github.com/blakeblackshear/frigate/blob/dev/docker/main/Dockerfile)

# Frigate

```ini
mqtt:
  enabled: false

go2rtc:
  streams:
    camera1:
      - rtsp://admin:1q2w3e4r@192.168.3.107:554/Streaming/Channels/101
#     - isapi://admin:1q2w3e4r@192.168.3.107:80/

cameras:
  camera1: # <------ Name the camera
    enabled: true
    ffmpeg:
      inputs:
        - path: rtsp://127.0.0.1:8554/camera1 # <----- The stream you want to use for detection
          roles:
            - detect
    detect:
      enabled: false # <---- disable detection until you have a working camera feed
      width: 640
      height: 360
version: 0.15-1
```

