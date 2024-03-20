> 参考资料：
>
> - [ESP32 default.csv](https://github.com/espressif/arduino-esp32/blob/master/tools/partitions/default.csv)

# 分区和LittleFS

## platformIO

```ini
; platformio.ini

board_build.partitions = default_partitions.csv
; important.
board_build.filesystem = littlefs 
```

```sh
/
|-- data/ # file save here.
|-- src/
|-- lib/
|-- platformio.ini
|-- default_partitions.csv # partition.csv
```

1. Platform Upload Filesystem Image
2. Platform Upload

