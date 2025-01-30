> 参考资料
>
> - [libcurl - small example snippets](https://curl.se/libcurl/c/example.html)
> - [Timing With Curl](https://susam.net/timing-with-curl.html)

# CURL

```
curl -d "@data.txt" -X POST http://localhost:3000/data
```

```
curl -v -F key1=value1 -F upload=@localfilename URL
```

```
curl -L -w "time_namelookup: %{time_namelookup}
time_connect: %{time_connect}
time_appconnect: %{time_appconnect}
time_pretransfer: %{time_pretransfer}
time_redirect: %{time_redirect}
time_starttransfer: %{time_starttransfer}
time_total: %{time_total}
" https://example.com/
```

- *`time_namelookup`:* 域名解析所用的时间
- *`time_connect`:* 从开始到完成到远程主机（或代理）的TCP连接所用的时间（秒）。
- *`time_appconnect`:* 从启动到完成到远程主机的SSL/SSH/etc连接/握手所用的时间（秒）(Added in 7.19.0)
- *`time_pretransfer`:* 从文件传输开始到开始所用的时间（以秒为单位）。 这包括特定于所涉及的特定协议的所有预传输命令和协商。
- *`time_redirect`:* 时间重定向：所有重定向步骤所用的时间（以秒为单位），包括名称查找、连接、预传输和在最终事务开始之前的传输。time_redirect显示多个重定向的完整执行时间。(Added in 7.12.3)
- *`time_starttransfer`:* 从开始到第一个字节即将被传输所用的时间，以秒为单位。这包括time_pretransfer以及服务器计算结果所需的时间。


- *`time_total`:* 完整操作持续的总时间（以秒为单位）。 