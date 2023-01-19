> *参考资料：*
>
> [[Arch Wiki] Installation guide](https://wiki.archlinux.org/title/Installation_guide)
>
> [[Arch Wiki] Font](https://wiki.archlinux.org/title/Fonts)
>
> [[Arch Wiki] NVIDIA](https://wiki.archlinux.org/title/NVIDIA)
>
> - [[SOLVED] Linux-zen kernel and Nvidia](https://bbs.archlinux.org/viewtopic.php?id=251515)
> [[Arch Wiki] NetworkManager](https://wiki.archlinux.org/title/NetworkManager_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

# Archlinux电脑私用配置

本文记录了从安装完毕一个ArchLinux后的一系列操作，从而实现将一个ArchLinux变成私人电脑的过程。想要了解如何安装Archlinux，请查看[这篇文章](./Archlinux安装.md)。

## 关键步骤

1. 联网，设置时区、地区，键盘映射

   - 网线连接或`wifi-menu`，使用 networkManager 时，连接无线网使用`nmcli`

   - `ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime` 之后 `hwclock --systohc`

   - 修改`/etc/locale.gen`，运行`locale-gen`。修改`/etc/locale.conf`至`LANG=en_GB.UTF-8`、`en_SG.UTF-8`或`en_US.UTF-8`

   - 修改`/etc/vconsole.conf`至`KEYMAP=us`

   - 修改`/etc/hostname`

     ```
     127.0.0.1	localhost
     ::1		localhost
     127.0.1.1	myhostname.localdomain	myhostname # 主机名.本地域名 主机名
     ```

   - 不要忘记修改root密码`passwd`

2. 添加新用户

   - `useradd -m [yourname]`然后`passwd [yourname]`

   - [可选] 为新用户提供sudo权限，`visudo`，需要安装`sudo`

   - [可选] 为新用户提供自动登陆`/etc/systemd/system/getty@tty1.service.d/autologin.conf`

     ```
     [Service]
     ExecStart=
     ExecStart=-/sbin/agetty -o '-p -f -- \\u' --noclear --autologin [username] - $TERM
     ```

3. 调整`pacman`源并更新：https://mirrors.tuna.tsinghua.edu.cn/help/archlinuxarm/

   - 修改`/etc/pacman.d/mirrorlist`
   - 更新升级`pacman -Syyu`

4. 安装`zsh`，将其作为默认shell程序，并选用一个适合的风格

   - `pacman -S zsh`
   - `chsh -s [shell path]`

5. 安装图形化环境X11

   - `pacman -S xorg-server xorg-xinit`

   - 修改登陆用户的图形化设置`cp /etc/X11/xinit/xinitrc ~/.xinitrc`

   - 配置为自动启动图形化服务，修改`~/.zprofile`

     ```
     if [[ ! $DISPLAY && $XDG_VTNR -le 3 ]]; then  # le 3 可以支持多显示器
         case $(ps -o comm= -p $PPID) in
             sshd | */sshd) echo "Welcome ssh." ;; # 判断终端是否是ssh登陆的
     	    *) exec startx;;					  # 只允许电脑启动xserver
         esac
     fi
     ```

6. 安装窗口管理器i3，并设置自动启动

   - se

   - 修改`~/.xinitrc`

     ```
     ...

     # Here Xfce is kept as default
     session=$1

     case $session in
         i3|i3wm           ) exec i3;;
         bspwm             ) exec bspwm;;
         dwm               ) exec dwm;;
         # No known session, try to run it as command
         *                 ) exec "There is nothing todo";;
     esac
     ```

     修改`~/.zprofile`

     ```
     if [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
       exec startx ~/.xinitrc i3
     fi
     ```

     > 也许，可以选择安装[bspwm](https://wiki.archlinux.org/title/Bspwm_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))或者[dwm](https://wiki.archlinux.org/title/Dwm_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)),外网对这两款windows manager都有偏好。

   - 自动登陆

     - 创建文件`/etc/systemd/system/getty@tty1.service.d/autologin.conf`并写入，中括号不带：

       ```txt
       [Service]
       ExecStart=
       ExecStart=-/usr/bin/agetty --autologin [username] --noclear %I $TERM
       ```

     - 或执行`systemctl edit getty@tty1`输入上述内容。

7. 安装字体和浏览器

   - 数学符号和表情：`pacman -S texlive-core texlive-fontsextra`
   - 思源字体：`pacman -S adobe-source-han-sans-otc-fonts adobe-source-han-serif-otc-fonts`
   - 编程字体：`pacman -S adobe-source-code-pro-fonts`
   - 安装浏览器：`pacman -S chromium`或从AUR下载`google-chrome`
   - 安装终端：`pacman -S terminator`, 在图形界面下，使用`i3-config-wizard`自动配置。

8. 安装[picom](https://wiki.archlinux.org/title/Picom)

   - `pacman -S picom`
   - 修改`.xinitrc`，添加`exec picom -b -i 1 -e 1 --config ~/.config/picom/picom.conf &`

9. 安装`feh`，并设置桌面背景

   - `pacman -S feh`

   - [可选] 添加背景图片，修改`.xinitrc`

     ```
     feh --bg-center [pathto]/feh-background.jpg
     ```

10. 安装`pikaur`

       - `sudo pacman -S git base-devel`

       - `git clone https://aur.archlinux.org/pikaur.git`

       - `cd pikaur`

       - `makepkg -fsri`


11. 安装`polybar`(需要AUR，可能需要科学上网)

       - `pikaur -S polybar`

       - 修改`.config/i3/config`

         ```sh
         ...
         
         # polybar support
         exec_always --no-startup-id polybar
         ```


12. 安装输入法

    - `pacman -S fcitx5-im`

    - 配置输入法` fcitx5-configtool`

    - 设置开机启动`cp /usr/share/applications/org.fcitx.Fcitx5.desktop ~/.config/autostart/`，或在`.confiig/i3/config` 中添加`exec --no-startup-id fcitx5 -d`

    - 设置环境环境变量`~/.pam_environment`

      ```
      GTK_IM_MODULE DEFAULT=fcitx
      QT_IM_MODULE  DEFAULT=fcitx
      XMODIFIERS    DEFAULT=\@im=fcitx
      INPUT_METHOD  DEFAULT=fcitx
      SDL_IM_MODULE DEFAULT=fcitx
      GLFW_IM_MODULE DEFAULT=ibus
      ```

    - 安装中文输入法`rime`：`pacman -S fcitx5-rime` 或者 `pacman -S fcitx5-chinese-addon`

13. 安装截图软件，配置截图快捷键

    - `pacman -S scrot`

    - 修改`.confiig/i3/config`添加

      ```
      # Screen Capture
      bindsym --release Shift+Print exec "scrot -l mode=edge -s -e 'mv $f [Your Dir]'"
      bindsym --release Print exec "scrot -e 'mv $f [Your Dir]'"
      ```

14. 安装`rofi`

       - `pacman -S rofi`

       - 修改`.confiig/i3/config`添加

         ```sh
         # run rofi
         bindsym $mod+n exec rofi -show run
         ```

         > 注意，`rofi`只能在`LANG=en_US.UTF-8`下运行。

## 其他内容

### 高分辨率

高分辨率屏幕需要手动设置DPI。可以参考设置[X resource](https://wiki.archlinux.org/title/X_resources)

QEMU Archlinux 虚拟机，xrandr 缺少一些特殊的分辨率，可以用[新建分辨率](https://wiki.archlinuxcn.org/wiki/Xrandr)的方式来。



### 用sway（wayland）+ alacritty 取缔 X11 和 i3

QEMU中使用 wayland，还需要安装 `phodav`。[Linux UTM Documentation](https://docs.getutm.app/guest-support/linux/#spice-webdav)



### chromium crash on raspberry PI

[[SOLVED] Aw, Snap! SIGSEGV](https://archlinuxarm.org/forum/viewtopic.php?f=15&t=14453)

### Nvidia

不同内核安装的Nvidia不同。Nvidia包需要对应内核的header。

安装英伟达理论上不需要其他操作， [[Solved] Failed to initialize the NVIDIA kernel module](https://bbs.archlinux.org/viewtopic.php?id=175253)

### SSH


**外部设备自动挂载**

- 安装 `udisks`：`pacman -S udisks`