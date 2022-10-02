> 参考资料：
>
> - [Arduino Leonardo Schematics](https://docs.arduino.cc/static/05f737fc664415f0e33201f8c2078672/schematics.pdf)
> - [Arduino Uno Schematics](https://content.arduino.cc/assets/UNO-TH_Rev3e_sch.pdf)

# Arduino

## 调试

参考 [官方文档](https://docs.platformio.org/en/latest/boards/atmelavr/uno.html#debugging).

```ini
[env:myenv]
platform = ...
board = ...
debug_tool = simavr
```