> 文章来源：https://mp.weixin.qq.com/s/eqAazg5YyYcH3LssT8Z5rw

# 边缘设备、系统及计算杂谈(19)——Ubuntu Server了解一下

**01 分区**

`/var`  分区存储日志

`/home` 分区存数据



**02 用户和权限管理**

- [**可插拔认证模块 (Pluggable authentication module， PAM)**](https://wiki.archlinux.org/title/PAM_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))



**03 日志系统**

都发生在 `/var/log` 中。

由 [rsyslogd](https://www.rsyslog.com/) 完成实际日志文件生成。程序使用 [syslog、opensyslog](https://www.ibm.com/docs/en/aix/7.2?topic=s-syslog-openlog-closelog-setlogmask-subroutine) 等API往 rsyslogd 输出日志。

- `kern.log`：内核日志
- `bootstrap.log` ：启动日志
- `lastlog`
- `btmp`：记录linux登陆失败的用户、时间以及远程IP地址
- `syslog`：只记录警告新信息
- `wtmp`：记录每个用户登陆、注销及系统的启动、停机事件，使用 `last` 命令查看
- `auth.log`：可插拔认证模块（PAM）的日志。



**04 进程管理**

- `&` ：后台运行
- `ctrl + z`：前台程序后台运行
- `jobs`：返回所有在后台的 `pid`
- `fd [pid]`：将进程拉回前台
- `cron && crontab` ：https://tool.lu/crontab



**05 安全**

- 那些端口在监听：`ss -tulpn`
- 加密磁盘：LUKS、`cryptsetup`
- 监控关键文件：`auditctl`
- 杀毒软件：`clamav`