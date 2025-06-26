> 文章来源：https://holdtherobot.com/blog/2025/05/11/linux-on-android-with-ar-glasses/

# Coding Without a Laptop - Two Weeks with AR Glasses and Linux on Android

## 关键词

- [Xreal Air 2 Pros](https://amzn.to/4dtA4HA)：AR 眼镜
- [Pixel 8 Pro](https://amzn.to/3F02fRD)：手机
- [ChrootOnAndroid](https://wiki.debian.org/ChrootOnAndroid)：Debian 官方 chroot on android



## 摘记

**01 Linux 系统**

> After way too much time spent experimenting, I landed on the chroot approach. I really didn't want to root the phone, but nothing else did what I needed. The virtual machine was way too slow and clunky, as was proot. Sticking to what can be run inside Termux got me surpisingly far, but Android's C implementation is Bionic and most programs won't run unless they're compiled with that in mind. That, plus other differences in the environment mean you're pretty limited. Chroot has no performance penalty as far as I can tell, and (for the most part), anything that can be compiled for arm64 seemed to work.
>
> 在花了太多时间进行实验之后，我选择了chroot方法。我真的不想root手机，但没有别的做我需要的。虚拟机太慢，太笨重，就像root一样。坚持什么可以在Termux内运行让我感到惊讶，但Android的C实现是仿生的，大多数程序都不会运行，除非它们在编译时考虑到这一点。再加上环境的其他差异，意味着你的能力相当有限。据我所知，Chroot没有性能损失，而且（在大多数情况下），任何可以为arm64编译的东西似乎都可以工作。

> So ultimately, the aarch64 glibc rootfs tarball of Void Linux fit the bill, and it's been running beautifully.
>
> 因此，最终，Void Linux的aarch64 glibc rootfs tarball符合要求，并且运行得很好。



## 思路

