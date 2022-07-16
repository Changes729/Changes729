> 参考资料：
>
> - **[pyshark](https://github.com/KimiNewt/pyshark)**
> - [Building your own Network Monitor with PyShark](https://linuxhint.com/building-your-own-network-monitor-with-pyshark/)
> - [Capture Filters](https://wiki.wireshark.org/CaptureFilters)

# Pyshark

```python
import pyshark

capture = pyshark.LiveCapture(interface='enp34s0', bpf_filter='tcp ip.addr=192.168.3.2')
for packet in capture.sniff_continuously(packet_count=5):
    print(packet)
```

