# Linux常用应用

**[Supervisor](http://supervisord.org/)**：Python开发的一个client/server服务，是Linux/Unix系统下的一个进程管理工具，通常用它来管理守护进程。

[nice](https://www.youtube.com/watch?v=II2M3rqgCQA)：Linux用户用来修改程序优先级的方式。



## 常用命令

- zip 打包命令：`zip -q -r html.zip /home/html`
- 基于Github的版本同步：`wget -N $(wget -qO- https://api.github.com/repos/[Changes729/MediaWallTest]/releases/latest | grep browser_download_url | cut -d'"' -f4)`