> 参考资料
>
> - [How to set a systemd timer to run monthly but at a certain time](https://askubuntu.com/questions/1252314/how-to-set-a-systemd-timer-to-run-monthly-but-at-a-certain-time)
> - [systemd/Timers](https://wiki.archlinux.org/title/Systemd/Timers)

# System

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

