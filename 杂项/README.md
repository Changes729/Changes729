有些非常细小的东西，必须要记下来，但是又没有比较变成一片文章。

`Github Gist`是一个解决方案。这里是另一个解决方案。

# Github
关于 [Github Workflow](https://github.com/marketplace/actions/run-cmake).

# VSCode 相关
## VSCode-Server
- Q: Ipad打开VScode白屏，在服务端查看日志显示握手失败。`error vscode handshake timed out code-server`
- A: 查看[Issue](https://github.com/cdr/code-server/issues/3027),上面说**重新安装**或者**重新编译**即可。重新安装不说了，重新编译的话需要知道咱们的`code-server`被安装到哪儿了，比如我`Archlinux`下是`/lib/code-server`.

## VSCode PlatformIO
如果遇到build失败的情况，可以看[这篇文章](https://community.platformio.org/t/pio-vsc-cant-build-no-tasks-found/10488/35)解决。

## VSCode GDB调试发送 SIGNAL 信号
1. 使用GDB暂停程序.
2. 在`DEBUG CONSOLE`中输入`-exec signal SIGINT`

# DBus
DBus XML描述中， **Value部分**的`type`意义可以看[这篇文章](https://pythonhosted.org/txdbus/dbus_overview.html)和[这篇文章](https://dbus.freedesktop.org/doc/dbus-specification.html#Summary%20of%20types).

要注意的是，接收方对于**DICT_ENTRY**类型在迭代器中需要使用`DBUS_TYPE_DICT_ENTRY`进行接收。而编写**DICT_ENTRY**类型时，需要使用`DBUS_DICT_ENTRY_BEGIN_CHAR`和`DBUS_DICT_ENTRY_END_CHAR`进行覆盖。

我自己有整理部分示例代码, 可以去[Github](https://github.com/Changes729/c_cpp_project_template/tree/gists/spike/src)上查看.

# BiDi
**[w3](https://www.w3.org/International/articles/inline-bidi-markup/)**: LVGL库参考的网页资料.
**[Firefox](https://developer.mozilla.org/en-US/docs/Archive/B2G_OS/Firefox_OS_apps/Firefox_OS_in_Arabic)**: 浏览器布局示意
**[Unicode.org](https://www.unicode.org/reports/tr9/)**: Unicode RTL说明与算法

# Standard
**[Country & Region code](https://en.wikipedia.org/wiki/ISO_3166-1)**: 标准国家/地区码.
**[Geographical names](https://unstats.un.org/sdgs/indicators/database/)**: 联合国地理信息.

# Algorithm
## 离散对数 (Discrete logarithm)
- [百科的算法说明](https://baike.baidu.com/item/%E7%A6%BB%E6%95%A3%E5%AF%B9%E6%95%B0/4538780?fr=aladdin)
- [CSDN 算法说明](https://blog.csdn.net/qmickecs/article/details/76585303#t4)
- [椭圆曲线离散对数问题的研究进展](), 田松. 李宝. 王鲲鹏, 密码学报 ISSN 2095-7025 CN 10-1195/TN

# VCPkg 相关

- Q: VCPkg 的 Opencv 不支持GUI显示?
- A: 查看 [这个Issue](https://github.com/microsoft/vcpkg/issues/12621) 修改CMake重新安装即可.