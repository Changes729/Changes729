> 参考资料：
>
> - [rsync - ArchWiki](https://wiki.archlinux.org/title/Rsync)
>   - [As a backup utility](https://wiki.archlinux.org/title/Rsync#As_a_backup_utility)
> - [**rsync**(1) manpage](https://download.samba.org/pub/rsync/rsync.1)

# rsync

## 基本用法

```txt
Local:
    rsync [OPTION...] SRC... [DEST]

Access via remote shell:
    Pull:
        rsync [OPTION...] [USER@]HOST:SRC... [DEST]
    Push:
        rsync [OPTION...] SRC... [USER@]HOST:DEST

Access via rsync daemon:
    Pull:
        rsync [OPTION...] [USER@]HOST::SRC... [DEST]
        rsync [OPTION...] rsync://[USER@]HOST[:PORT]/SRC... [DEST]
    Push:
        rsync [OPTION...] SRC... [USER@]HOST::DEST
        rsync [OPTION...] SRC... rsync://[USER@]HOST[:PORT]/DEST)
```

**01 SSH backup**

```
rsync -a --delete --quiet -e ssh /path/to/backup remoteuser@remotehost:/location/of/backup
```



## 其他用法

**01 排除文件**

**02 频率更新**

脚本是在`/etc/cron.daily`目录中创建的，如果安装并正确配置了 cron [守护进程，](https://wiki.archlinux.org/title/Daemon)它将每天运行。配置和使用[cron](https://wiki.archlinux.org/title/Cron)超出了本文的范围。

```
/etc/cron.daily/backup
#!/bin/sh
rsync -a --delete --quiet /path/to/backup /location/of/backup
```

`-a`：表示文件应该被存档，这意味着它们的大部分特征都被保留（但**不包括**URL、硬链接或扩展属性，如功能）

`--delete`：意味着在源上删除的文件也将在备份中删除



**03 文件检测**