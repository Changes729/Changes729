> 参考资料：
> 
> - [Win10添加Samba共享失败？看完这篇你就能搞定了](https://www.pcoic.com/system/windows/2119.html)
# SAMBA

NAS服务器也是使用SAMBA的。所以有些SAMBA问题会放在这里。

## 常见问题

- [windows需要一个共享才能发布](https://www.pcoic.com/system/windows/2119.html)

  简单来说，添加网络驱动器时 `\\[ip]` 是不行的，需要后续跟一个目录。这是因为 Samba 虽然可以登录，但是网络地址如 `\\192.168.1.200\` 事实上是用户根目录，如果公司的用户是ROOT，那么访问根目录可能是非法的，所以会被屏蔽，要做的就是加上后续的文件目录名称如 `\\192.168.1.200\[share]`

- [Windows Samba 网络凭据没有权限/以其他用户身份登录而无法修改为新用户](https://jingyan.baidu.com/article/546ae185595b175148f28c6c.html)

  需要手动修改用户凭据。

- [Linux 启动smb服务器，windows连接smb 服务器](https://blog.csdn.net/xuetaoxuetao/article/details/78857106)
