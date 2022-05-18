> 参考资料：
>
> - [HiDPI on Linux](https://www.youtube.com/watch?v=6N5zUS9Qv9E)
> - [[Archlinux] HiDPI](https://wiki.archlinux.org/title/HiDPI_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

# Unity

## HiDPI

高DPI的问题，Windows下可以解决。Linux下需要设置 `GDK_SCALE = 2`。

```shell
#!/bin/sh
script_dir=$(cd $(dirname $0);pwd)

GDK_SCALE=2 GDK_DPI_SCALE=0.5 $script_dir/_Unity $*
```

