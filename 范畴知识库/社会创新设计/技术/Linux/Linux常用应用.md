> 参考资料
>
> - [pacman/提示和技巧](https://wiki.archlinuxcn.org/zh-hans/Pacman/%E6%8F%90%E7%A4%BA%E5%92%8C%E6%8A%80%E5%B7%A7)
> - https://discussion.fedoraproject.org/t/non-interactive-shutdown-from-ssh/77986：非交互式关机

# Linux常用应用

**[Supervisor](http://supervisord.org/)**：Python开发的一个client/server服务，是Linux/Unix系统下的一个进程管理工具，通常用它来管理守护进程。

[nice](https://www.youtube.com/watch?v=II2M3rqgCQA)：Linux用户用来修改程序优先级的方式。



## 常用命令

- zip 打包命令：`zip -q -r html.zip /home/html`

  递归压缩符号链接：`zip -y -r foo.zip foo/`

- 基于Github的版本同步：`wget -N $(wget -qO- https://api.github.com/repos/[Changes729/MediaWallTest]/releases/latest | grep browser_download_url | cut -d'"' -f4)`

- 代理：`export https="http://127.0.0.1:8118"` 让https走http代理。不清楚具体什么意思，但是这样设置 TLS 可以通过

- [Linux 下制作 Windows 系统盘](https://superuser.com/questions/1290568/create-windows-10-usb-installation-drive-with-linux-only)：`woeusb  --target-filesystem NTFS --device path/to/windows.iso /dev/sdX`

- 查看某目录大小：`du -h --max-depth=1 [PATH]`

- 查看磁盘格式：`df -hT`

- tar 压缩文件夹：`tar -zcvf [xahot].tar.gz [xahot]`

- sed
  - 替换某一行的信息：`sed -i '/^lang=JAVA*/c\lang=RUST' hello.txt`，查找以 `lang=JAVA` 开头的行，然后`c\` 替换为 `lang=RUST`
  - 把1.jpg ..... 9.jpg 变换为001.jpg .... 009.jpg `rename 's/^/00/' [0-9].jpg`
  - 把10.jpg ..... 99.jpg 变换为010.jpg ..... 090.jpg `rename 's/^/0/' [0-9][0-9].jpg` 
  - 把 old- 开头的文件替换为 new- 开头的文件`rename 's/old-/new-/' old-*`
  
- `export TMPDIR=./tmpdir` 当下载目录过小的时候，可以用这个方式拓展临时文件夹

- `>`重定向，主要是用作文件输入的。

- `|`管道将一个程序的结果作为另一个程序的输入。如果管道被关闭，那么 `read` 会直接返回，并且读取到的返回值为 0。

- 查看安装包：`pacman -Qqe`

- 递归删除孤立软件包及其配置文件：`pacman -Qtdq | pacman -Rns -`

- 列出软件包拥有的文件并带大小：`pacman -Qlq package | grep -v '/$' | xargs -r du -h | sort -h`

- 挂载ISO：`mount -o loop /path/to/image.iso /media/mountpoint`

- 烧录 ISO：`dd [iso] [sdb] status=progress`

- [硬盘坏块测试](https://wiki.archlinux.org/title/Badblocks)（[e2fsprogs](https://archlinux.org/packages/?name=e2fsprogs)）：`badblocks -wsv /dev/device`

- unzip 特定编码：`unzip -O <encoding> <filename> -d <target_dir>`

- [ls 的值内容](https://blog.csdn.net/weixin_37998647/article/details/79217027)

  - 如果是文件，值为硬连接数
  - 如果是目录，值为目录个数
  
- [创建软链接](https://man7.org/linux/man-pages/man1/ln.1.html)：`ls -sr [source] [target]` 创建一个目标 指向 source 相对路径的软连接。

  `s` 是软连接，`r` 配合 `s` 使用，表示使用相对路径。

- [find 操作](https://www.man7.org/linux/man-pages/man1/find.1.html):

  - 默认后跟 Path：`find ~/Downloads/file` 可以找到具体文件。
  - `-path`：`find -path file` 会根据当前路径的相对路径进行查找。
  - `-name`：会查找完全匹配名字的内容
  - `-inum`：会查找 inode 一样的文件
  - `-regex`：正则表达式查找，`find -regex '.*.txt'`
  
- [wget 代理](https://www.cnblogs.com/frankyou/p/6693256.html)：`wget -e "http_proxy=http://127.0.0.1:8087" [url]`

