> 参考资料：
>
> - [What is a reasonable amount of inotify watches with Linux?](https://stackoverflow.com/questions/535768/what-is-a-reasonable-amount-of-inotify-watches-with-linux)：
>   - `/proc/sys/fs/inotify/max_user_instances`：可创建的 inotify 对象数量
>   - `/proc/sys/fs/inotify/max_user_watches`：可监控的文件数量？
> - [inotify/demo_inotify.c](https://man7.org/tlpi/code/online/dist/inotify/demo_inotify.c.html)

# inotify

inotify 可以用来检测一个目录文件的变化。