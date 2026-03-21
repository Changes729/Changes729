> 参考资料
>
> - [How to set a systemd timer to run monthly but at a certain time](https://askubuntu.com/questions/1252314/how-to-set-a-systemd-timer-to-run-monthly-but-at-a-certain-time)
> - [systemd/Timers](https://wiki.archlinux.org/title/Systemd/Timers)
>   - [systemd.time - Time and date specifications](https://man.archlinux.org/man/systemd.time.7.en)：可以看到一些具体的时间描述

# System

用户位置：`~/.local/share/systemd/user/`

管理员位置：`/etc/systemd/system/`

```sh
# /etc/systemd/system
[Unit]
Wants=network-online.target
After=network-online.target

[Service]
WorkingDirectory=/usr/local
ExecStart=python /home/pi/dist/src/main.py

[Timer]
OnCalendar=*-*-01 02:00:00
Persistent=true

[Install]
WantedBy=default.target
```



## system/timers

`systemctl list-timers`

```sh
# daily-sync.timer
[Unit]
Description=Daily Sync

[Timer]
# OnBootSec=15min
# OnUnitActiveSec=1w
OnCalendar=*-*-* 02:00:00 
Persistent=true

[Install]
WantedBy=timers.target
```

```sh
# daily-sync.service
[Service]
WorkingDirectory=/usr/local
ExecStart=rsync -aH --delete --quiet -e ssh /path/to/backup remoteuser@remotehost:/location/of/backup
```

