> 参考资料：
>
> - [RAID](https://wiki.archlinux.org/title/RAID)

# RAID

## 配置RAID5

**01 安装 mdadm**

**02 重新配置 mkinitcpio**

```
/etc/mkinitcpio.conf
...
HOOKS=(base udev autodetect microcode modconf kms keyboard keymap consolefont block mdadm_udev filesystems fsck)
...
```

```
# mkinitcpio -p linux
```



**03 创建阵列**

```
# mdadm --create --verbose --level=5 --metadata=1.2 --chunk=256 --raid-devices=4 /dev/md/MyRAID5Array /dev/sdb1 /dev/sdc1 /dev/sdd1 /dev/sde1 --spare-devices=1 /dev/sdf1
```

如果有阵列存在则需要删除

```
mdadm --stop /dev/md###
```



**04 更新配置文件**

```
# mdadm --detail --scan >> /etc/mdadm.conf
```

```
/etc/mdadm.conf
...
DEVICE partitions
...
ARRAY /dev/md/MyRAID1Array metadata=1.2 name=pine:MyRAID1Array UUID=27664f0d:111e493d:4d810213:9f291abe
```



**05 组装阵列**

```
mdadm --assemble --scan
```



**06 格式化RAID文件系统**

```
mkfs.ext4
```



**07 挂载系统**

```
id -g username # get gid
mount -o gid=[gid] /dev/md0 [dest]
```

必要时可选

```
sudo chown -R user:user [dir]
```



**08 更新fstab**

```
genfstab / >> /mnt/etc/fstab
```

