> *参考资料：*
>
> [[ArchWiki] Arch Build System (简体中文)](https://wiki.archlinux.org/title/Arch_Build_System_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

# Arch Build System

Archlinux软件构建方式，分以下步骤：

1. 通过`git`同步[构建文件仓库树](#构建文件仓库树)：`pacman -Syy`
2. 通过`PKGBUILD`，获取**对应架构的软件包和安装脚本**
3. 通过`pacman`对软件包的依赖关系进行管理



## 构建文件仓库树

这个仓库树是存放构建时所需文件的库。

每个包有各自的子目录，其中又有`repos`和`trunk`目录。`repos`又**进一步按仓库名(如*core*)和架构细分**。`repos`里的PKGBUILD和其它文件用来构建官方包。`trunk`里的文件是**给开发者用的**，并最终复制到`repos`中。

例如，`acl`的目录结构是这样的：

```
acl
acl/repos
acl/repos/core-x86_64
acl/repos/core-x86_64/PKGBUILD
acl/trunk
acl/trunk/PKGBUILD
```



# 自定义软件仓库

