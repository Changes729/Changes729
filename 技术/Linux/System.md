# System

```sh
# /etc/systemd/system
[Unit]
Wants=network-online.target
After=network-online.target

[Service]
WorkingDirectory=/usr/local
ExecStart=python /home/pi/dist/src/main.py

[Install]
WantedBy=default.target
```

