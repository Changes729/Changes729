> 参考资料：
>
> - [Quickstart for Installing Gerrit on Linux](https://gerrit-documentation.storage.googleapis.com/Documentation/3.6.2/linux-quickstart.html)：安装步骤来即可，注意安装最新版的 Gerrit
> - [Gerrit Code Review - Uploading Changes](https://gerrit-documentation.storage.googleapis.com/Documentation/3.6.2/user-upload.html#ssh)
> - [gerrit-forge](https://gerrit-ci.gerritforge.com/view/Plugins-stable-3.7/)

# Gerrit

## 创建用户

直接登陆网页就可以注册用户

Gerrit一般是内网部署，通过反向代理服务器做用户管理的。



## 创建存储库（Repository ）

我这个版本，在`BROWSE -> Repository`，里面有边有个 CREATE NEW。



## 上传存储库

需要注意的是，这里首先要按照文档说的，添加[Git-Hook](https://gerrit-documentation.storage.googleapis.com/Documentation/3.6.2/user-upload.html#ssh)，因为如果 Commit 没有 Commit-ID的话，Gerrit 是会拒绝提交的。



## Gerrit 存储

Gerrit所有存储都在 `${GERRIT}/git/` 目录下，存的都是 `.git` 目录。



## Plugin

- [Github oauth](https://gerrit-ci.gerritforge.com/view/Plugins-stable-3.7/job/plugin-github-mvn-stable-3.7/)：两个插件，一个是oauth，另一个是plugin
- [SAML](https://gerrit-ci.gerritforge.com/view/Plugins-stable-3.7/job/plugin-saml-bazel-master-stable-3.7/)
