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

