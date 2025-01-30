> *参考资料*
>
> [[Archlinux] gitlab](https://wiki.archlinux.org/title/GitLab)
>
> [[Gitlab] troubleshooting](https://docs.gitlab.com/ee/security/reset_user_password.html#troubleshooting)
>
> [离线安装gitlab无法修改初始密码问题](https://jingyan.baidu.com/article/c1465413527ae54afcfc4caa.html)

# Gitlab笔记

安装过程按照Archlinux的笔记来就好，不过gitlab最近有一个安全性更新，就是[修改密码一定要邮箱认证](https://docs.gitlab.com/ee/user/upgrade_email_bypass.html)，所以搞的我安装完，这个密码一直修改不了。

![](../../../../../Changes729_image/raw/main/ln/GitLab/65ba880b312105610841cb5a08aee8d7582a6a75.jpg)

然后要注意的是，文档里说要启动`rails console`，但其实，Archlinux下的gitlab用户不允许终端登陆，默认仅允许ssh登陆。所以gitlab的文档里写的登陆`gitlab-rails console`是不行的，**Archlinux下的打开方式如下**：

```sh
cd /usr/share/webapps/gitlab
sudo -u gitlab $(cat environment | xargs) bundle-2.7 exec rails console
```

然后按照Gitlab的文档去关闭邮箱认证即可。



> 这玩意儿我搞了一个下午！
>
> 不过好像后面还是无法修改密码，所以选用Docker容器去允许gitlab了。

