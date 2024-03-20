有些非常细小的东西，必须要记下来，但是又没有比较变成一片文章。

`Github Gist`是一个解决方案。这里是另一个解决方案。

# Github

关于 [Github Workflow](https://github.com/marketplace/actions/run-cmake).

# VSCode 相关

## VSCode-Server

- Q: Ipad 打开 VScode 白屏，在服务端查看日志显示握手失败。`error vscode handshake timed out code-server`
- A: 查看[Issue](https://github.com/cdr/code-server/issues/3027),上面说**重新安装**或者**重新编译**即可。重新安装不说了，重新编译的话需要知道咱们的`code-server`被安装到哪儿了，比如我`Archlinux`下是`/lib/code-server`.

## VSCode PlatformIO

如果遇到 build 失败的情况，可以看[这篇文章](https://community.platformio.org/t/pio-vsc-cant-build-no-tasks-found/10488/35)解决。

## VSCode GDB 调试发送 SIGNAL 信号

1. 使用 GDB 暂停程序.
2. 在`DEBUG CONSOLE`中输入`-exec signal SIGINT`

# DBus

DBus XML 描述中， **Value 部分**的`type`意义可以看[这篇文章](https://pythonhosted.org/txdbus/dbus_overview.html)和[这篇文章](https://dbus.freedesktop.org/doc/dbus-specification.html#Summary%20of%20types).

要注意的是，接收方对于**DICT_ENTRY**类型在迭代器中需要使用`DBUS_TYPE_DICT_ENTRY`进行接收。而编写**DICT_ENTRY**类型时，需要使用`DBUS_DICT_ENTRY_BEGIN_CHAR`和`DBUS_DICT_ENTRY_END_CHAR`进行覆盖。

我自己有整理部分示例代码, 可以去[Github](https://github.com/Changes729/c_cpp_project_template/tree/gists/spike/src)上查看.

# BiDi

**[w3](https://www.w3.org/International/articles/inline-bidi-markup/)**: LVGL 库参考的网页资料.
**[Firefox](https://developer.mozilla.org/en-US/docs/Archive/B2G_OS/Firefox_OS_apps/Firefox_OS_in_Arabic)**: 浏览器布局示意
**[Unicode.org](https://www.unicode.org/reports/tr9/)**: Unicode RTL 说明与算法

# Standard

**[Country & Region code](https://en.wikipedia.org/wiki/ISO_3166-1)**: 标准国家/地区码.
**[Geographical names](https://unstats.un.org/sdgs/indicators/database/)**: 联合国地理信息.

# Algorithm

## 离散对数 (Discrete logarithm)

- [百科的算法说明](https://baike.baidu.com/item/%E7%A6%BB%E6%95%A3%E5%AF%B9%E6%95%B0/4538780?fr=aladdin)
- [CSDN 算法说明](https://blog.csdn.net/qmickecs/article/details/76585303#t4)
- [椭圆曲线离散对数问题的研究进展](), 田松. 李宝. 王鲲鹏, 密码学报 ISSN 2095-7025 CN 10-1195/TN

# VCPkg 相关

- Q: VCPkg 的 Opencv 不支持 GUI 显示?
- A: 查看 [这个 Issue](https://github.com/microsoft/vcpkg/issues/12621) 修改 CMake 重新安装即可.

# Archlinux 相关

- 输入法简正切换：[Ctrl+.](https://blog.csdn.net/cuma2369/article/details/107666139)

# VirtualBox相关

- VirtualBox Windows分辨率无法自由调节：[参考1](https://qianqianjun.blog.csdn.net/article/details/86677196?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.pc_relevant_default&utm_relevant_index=5)、[参考2](https://blog.csdn.net/Lyq3413/article/details/83658621)

  简单说，你需要安装VirtualBox Windows增强功能，这样Windows画面大小会跟着UI变。

# Git 相关

- [Git删除子模块](https://www.jianshu.com/p/9000cd49822c)

```sh
# shell
git rm --cached assets
rm -rf assets
```

```sh
# .gitmodules delete this.
[submodule "assets"]
  path = assets
  url = https://github.com/maonx/vimwiki-assets.git
```

```sh
# .git/config delete this.
[submodule "assets"]
  url = https://github.com/maonx/vimwiki-assets.git
```

```sh
# delete path.
rm -rf .git/modules/assets`
```

# Navigation

- [List of graph visualization libraries](https://elise-deux.medium.com/the-list-of-graph-visualization-libraries-7a7b89aab6a6)
- [Two Minute Papers(兩分鍾論文)](https://www.youtube.com/user/keeroyz)

## Python

[[CSDN] - Python3虚拟环境 venv搭建轻量级虚拟环境](https://blog.csdn.net/qq_22022063/article/details/78979367?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164272903516780366581002%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164272903516780366581002&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-78979367.pc_search_insert_es_download&utm_term=python+-m+venv&spm=1018.2226.3001.4187)

[[CSDN] - python 项目自动生成requirements.txt文件](https://blog.csdn.net/Irving_zhang/article/details/79087569)

[[QT] Qt for Python](https://doc.qt.io/qtforpython/)

[[CSDN] - python从任意文件夹下导入模块](https://blog.csdn.net/Strive_For_Future/article/details/106716745):`sys.path.append("/Path")`

[[博客园] - Python判断文件是否存在](https://www.cnblogs.com/jhao/p/7243043.html):`os.path.exists(test_file.txt)`

[[Coder] - Python线程非阻塞读取文件](https://www.coder.work/article/1252764)

[PyScreeze](https://pypi.org/project/PyScreeze/)：基础的Python屏幕处理软件，包括截图、定位

[Python CSV](https://docs.python.org/3/library/csv.html)

[[StackOverflow] python signal handler](https://stackoverflow.com/questions/1112343/how-do-i-capture-sigint-in-python)

## python - Xlib

**[active_window_xlib_demo.py](https://gist.github.com/mgalgs/8c1dd50fe3c19a1719fb2ecd012c4edd)**：包括了获取当前活动应用、获取应用的窗口大小功能

## 代理与镜像

### yarn

`https_proxy="http://127.0.0.1:8118" yarn install`

```
npm install --global yarn
```

`yarn config set registry https://registry.npmmirror.com`

#### [docker](https://docs.docker.com/network/proxy/)

`ENV HTTP_PROXY="http://192.168.0.2:8118"`

### [pip](https://mirrors.tuna.tsinghua.edu.cn/help/pypi/)

`pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple`