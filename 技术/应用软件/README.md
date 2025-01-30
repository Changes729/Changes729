# 其他应用软件

- [Marvelous Designer](https://www.marvelousdesigner.com/)：专业服装设计软件
- [Wireshark](https://www.wireshark.org/)
  - Linux 下免 sudo：`sudo usermod -a -G wireshark $USER`
  - Mac 下 软件会自动提示安装某应用程序。实现免 sudo。
- [jadx](https://github.com/skylot/jadx)：Java 反汇编工具
- minicom：
  
  - [发送换行](https://blog.csdn.net/qlexcel/article/details/111663373)：`ctrl+J (\n)`、`ctrl+M（\r）`
  
  - ```
    minicom -D /dev/ttyACM0 -b 115200
    ```
- FreeCAD
  - [A2plus](https://github.com/kbwbe/A2plus)：装配组件
  - https://github.com/FreeCAD/FreeCAD/issues/10846：openCAD插件会影响DXF、DWG导出
- AutoSCAD
- Unity
- [fusion360](https://www.autodesk.com/products/fusion-360/overview?term=1-YEAR&tab=subscription)：机械机构设计。
- **[lyrebird](https://github.com/lyrebird-voice-changer/lyrebird)**：变音软件
- AVAHI：零配置mDNS/DNS工具
- QGIS：GIS软件
  
  - [全国地理信息资源目录服务系统](https://www.webmap.cn/main.do?method=index)
- strings：UNIX 环境可以查看应用程序的字符串。通过这个可以做逆向工程，一定程度上可以看到程序的BUG
- [ida-free](https://aur.archlinux.org/pkgbase/ida-free)：逆向工程反汇编程序
- [pwnat](https://github.com/samyk/pwnat)：NAT工具

