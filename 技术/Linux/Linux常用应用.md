> 参考资料
>
> - [pacman/提示和技巧](https://wiki.archlinuxcn.org/zh-hans/Pacman/%E6%8F%90%E7%A4%BA%E5%92%8C%E6%8A%80%E5%B7%A7)

# Linux常用应用

**[Supervisor](http://supervisord.org/)**：Python开发的一个client/server服务，是Linux/Unix系统下的一个进程管理工具，通常用它来管理守护进程。

[nice](https://www.youtube.com/watch?v=II2M3rqgCQA)：Linux用户用来修改程序优先级的方式。



## 常用命令

- zip 打包命令：`zip -q -r html.zip /home/html`
- 基于Github的版本同步：`wget -N $(wget -qO- https://api.github.com/repos/[Changes729/MediaWallTest]/releases/latest | grep browser_download_url | cut -d'"' -f4)`
- 代理：`export https="http://127.0.0.1:8118"` 让https走http代理。不清楚具体什么意思，但是这样设置 TLS 可以通过
- [Linux 下制作 Windows 系统盘](https://superuser.com/questions/1290568/create-windows-10-usb-installation-drive-with-linux-only)：`woeusb  --target-filesystem NTFS --device path/to/windows.iso /dev/sdX`
- 查看某目录大小：`du -h --max-depth=1 [PATH]`
- 查看磁盘格式：`df -hT`
- tar 压缩文件夹：`tar -zcvf [xahot].tar.gz [xahot]`
- sed
  - 替换某一行的信息：`sed -i '/^lang=JAVA*/c\lang=RUST' hello.txt`，查找以 `lang=JAVA` 开头的行，然后`c\` 替换为 `lang=RUST`
- `export TMPDIR=./tmpdir` 当下载目录过小的时候，可以用这个方式拓展临时文件夹
- `>`重定向，主要是用作文件输入的。
- `|`管道将一个程序的结果作为另一个程序的输入。如果管道被关闭，那么 `read` 会直接返回，并且读取到的返回值为 0。
- 查看安装包：`pacman -Qqe`
- 递归删除孤立软件包及其配置文件：`pacman -Qtdq | pacman -Rns -`
- 列出软件包拥有的文件并带大小：`pacman -Qlq package | grep -v '/$' | xargs -r du -h | sort -h`

