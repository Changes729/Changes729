> _参考资料_
>
> - [[Bilibili] Nginx教程](https://b23.tv/KZgBAPr)
> - [一文理清 nginx 中的 location 配置（系列一）](https://segmentfault.com/a/1190000022315733)

# Nginx

Nginx是一个开源的Web服务器，你安装了Nginx，你就约等于有了一个服务器。



## Nginx location配置

- 匹配 URI 类型，有四种参数可选，当然也可以不带参数。：`location [ = | ~ | ~* | ^~ ] /URI { … }`
  - 空：标准 URI
  - =：用于标准 URI 前，要求请求字符串与其精准匹配，成功则立即处理，nginx停止搜索其他匹配。
  - ^~：用于标准 URI 前，并要求一旦匹配到就会立即处理，不再去匹配其他的那些个正则 URI，一般用来匹配目录
  - ~：用于正则 URI 前，表示 URI 包含正则表达式， 区分大小写
  - ~*：用于正则 URI 前， 表示 URI 包含正则表达式， 不区分大小写
  - @：定义一个命名的 location，@ 定义的locaiton名字一般用在内部定向，例如error_page, try_files命令中。它的功能类似于编程中的goto。
- 命名location，用@来标识，类似于定义goto语句块。：`location @/name/ { … }`



如以下配置，可以实现操作和UI请求分流：

```nginx
location ~ ^/(admin|graphql|thumbnailer|static-collected) {
	proxy_pass        http://localhost:8000;
}

location / {
	proxy_pass        http://localhost:3000;
}
```



