> 参考资料：
>
> - [pulsectl](https://pypi.org/project/pulsectl/)
>   - [C Demo](https://gist.github.com/dailongquan/fc0aa1aa09f6dcaf4ad107837fde3d27)
>   - [pavucontrol](https://github.com/pulseaudio/pavucontrol)

# Pulse Audio 控制

Pulse Audio 中存在几个变量，我们可以在 python 里面先创建一个 pulse 对象：

`pulse = pulsectl.Pulse()` ，然后可以看到许多方法。说几个重要的：

- **client_list**：播放音频的客户端。
- **sink_input_list**：播放的音频源。
  - **client**：对应 client_list。
- **sink_list**：输出设备

可以通过重定向 sink_input 到 sink，从而实现音频通道的切换。