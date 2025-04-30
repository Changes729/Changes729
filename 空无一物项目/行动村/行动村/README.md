# 行动村

## 架构设计

**01 后端框架**：[Laravel](https://laravel.com/)

- 依赖：nginx，php-fpm(7.2.14) —— [mac 配置 nginx 和 php-fpm](https://developer.aliyun.com/article/809046?userCode=okjhlpr5)

**02 前端框架**：Vue，NodeJS(v11.10.0)

**03 数据库**：redis（数据库）：7399 数据库端口

> 现在问题出在 AMap 上
>
> - https://github.com/ElemeFE/vue-amap
> - https://lbs.amap.com/api/webservice/summary



## 关键目录

```txt
/home/www/m-client-xdc/
/home/www/console-xdc/：管理员页面
/home/www/client-xdc/：行动村主页面
/home/www/api-xdc/：PHP后台
\-storage/logs/
/etc/redis.conf
/home/www/
/etc/nginx/conf.d/
\- api.xdc.conf
/etc/php-fpm.d/www.conf
console.actionvillager.com.key
console.actionvillager.com.pem
```



## 关键轮子

```txt
fish
```



## System





## SSL

现在是使用 [acme.sh](https://github.com/acmesh-official/acme.sh) 自动生成了免费的。

> 参考资料：
>
> - [SSL证书文件校验工具](https://www.chinassl.net/ssltools/decoder-ssl.html)
> - [Aliyun domain API](https://github.com/acmesh-official/acme.sh/wiki/dnsapi#11-use-aliyun-domain-api-to-automatically-issue-cert)：未使用
> - [DNS manual mode](https://github.com/acmesh-official/acme.sh/wiki/dns-manual-mode)：最后使用了 DNS 模式，需要登陆阿里云
> - [Server](https://github.com/acmesh-official/acme.sh/wiki/Server)：最后还是zerossl成功了，用DNS的条件下

参考命令：

```sh
/root/.acme.sh/acme.sh --issue  -d console.actionvillager.com --debug 2 --dns --yes-I-know-dns-manual-mode-enough-go-ahead-please
```

```sh
/root/.acme.sh/acme.sh --renew  -d console.actionvillager.com --debug 2  --yes-I-know-dns-manual-mode-enough-go-ahead-please
```

```shell
/root/.acme.sh/acme.sh --install-cert -d console.actionvillager.com --key-file /etc/nginx/cert/console.actionvillager.com.key --fullchain-file /etc/nginx/cert/console.actionvillager.com.pem
```

```sh
/root/.acme.sh/acme.sh --set-default-ca --server letsencrypt_test
```

