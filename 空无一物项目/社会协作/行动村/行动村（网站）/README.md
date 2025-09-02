> IP: 106.14.148.11
>
> 参考资料：
>
> - [How to Configure PHP-FPM with NGINX for Secure PHP Processing](https://www.digitalocean.com/community/tutorials/php-fpm-nginx)

# 行动村

## 架构设计

**01 后端框架**：[Laravel](https://laravel.com/)

- 依赖：nginx，[php-fpm](https://wiki.archlinux.org/title/Nginx)(7.2.14) —— [mac 配置 nginx 和 php-fpm](https://developer.aliyun.com/article/809046?userCode=okjhlpr5)

**02 前端框架**：Vue，NodeJS(v11.10.0)

**03 数据库**：redis（数据库）：7399 数据库端口

> 现在问题出在 AMap 上
>
> - https://github.com/ElemeFE/vue-amap
> - https://lbs.amap.com/api/webservice/summary

**04 sms 服务**

> [首页-飞鸽云通讯_短信平台_短信群发_短信接口__国际短信_做 ...](https://www.feige.cn/)
>
> 代码文件在 `api-xdc/Core/Services/ShortMessageService.php`



## 主要功能

**01 项目库**

**01.1 项目数据库**

项目数据库包括，流程、文本、图片、成员信息等数据；



**02 项目功能** 

**02.1 项目搜索**

- 按地理位置搜索
- 按标签搜索（小分类、大分类）
- 按项目进度搜索



**02.2 项目创建**

- 项目创建模版信息（文档信息）
- 项目组队（成员信息）
- 地理位置（地理信息）



**02.3 项目更新**

- 项目记录文档（文字&图片）



~~02.4 项目删除~~ 暂时没有项目删除功能



**03 项目反馈**

- 项目关注数
- 项目阅读量
- 虚拟币
- 项目证书



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

> laravel.log



## 关键轮子

```txt
fish
```



## 问题记录

**01 php 部署问题**

**01.1 redis 数据库是什么？**

**01.2 如何读写 redis？（通常 和 PHP）**

**01.3 php REST 请求**

**01.4 php 架构**



## SSL

现在是使用 [acme.sh](https://github.com/acmesh-official/acme.sh) 自动生成了免费的。

> 参考资料：
>
> - [SSL证书文件校验工具](https://www.chinassl.net/ssltools/decoder-ssl.html)
> - [Aliyun domain API](https://github.com/acmesh-official/acme.sh/wiki/dnsapi#11-use-aliyun-domain-api-to-automatically-issue-cert)：未使用
> - [DNS manual mode](https://github.com/acmesh-official/acme.sh/wiki/dns-manual-mode)：最后使用了 DNS 模式，需要登陆阿里云
> - [Server](https://github.com/acmesh-official/acme.sh/wiki/Server)：最后还是zerossl成功了，用DNS的条件下

参考命令：

api.actionvillager.com

```sh
/root/.acme.sh/acme.sh --issue  -d console.actionvillager.com --debug 2 --dns --yes-I-know-dns-manual-mode-enough-go-ahead-please
```

```sh
/root/.acme.sh/acme.sh --renew  -d console.actionvillager.com --debug 2  --yes-I-know-dns-manual-mode-enough-go-ahead-please
```

renew 后需要在阿里云重新设置 域名内容。

```shell
/root/.acme.sh/acme.sh --install-cert -d console.actionvillager.com --key-file /etc/nginx/cert/console.actionvillager.com.key --fullchain-file /etc/nginx/cert/console.actionvillager.com.pem
```

```sh
/root/.acme.sh/acme.sh --set-default-ca --server letsencrypt_test
```

需要重启 Nginx



[使用阿里云域名API自动颁发证书](https://github.com/acmesh-official/acme.sh/wiki/dnsapi#dns_ali)：成功

```sh
/root/.acme.sh/acme.sh --issue  -d console.actionvillager.com --debug 2 --dns dns_ali --yes-I-know-dns-manual-mode-enough-go-ahead-please
```



