> 参考资料：
>
> - [MySQL](https://www.mysql.com/)：[MySQL Docs](https://docs.cloud.oracle.com/en-us/iaas/mysql-database/doc/getting-started.html)、[MySQL Documentation](https://docs.oracle.com/cd/E17952_01/index.html)
>   - [MySQL Community Server](https://dev.mysql.com/downloads/mysql/)：[Getting Started With MySQL Database Service](https://docs.oracle.com/en-us/iaas/mysql-database/doc/getting-started-mysql-database-service.html#GUID-3C1DA346-CDA2-442E-9D22-A7C244B9DF04)
>   - [Chapter 3 MySQL Port Reference Tables](https://dev.mysql.com/doc/mysql-port-reference/en/mysql-ports-reference-tables.html)：一些端口

# MySQL

现在都用 `Mariadb ` 替代MySQL了。

## 访问 MySQL

- 使用命令行工具：
  - MacOS：`/usr/local/mysql/bin/mysql`



## 数据库

- [修改密码](http://c.biancheng.net/view/7152.html)：`mysqladmin -u [用户名] -p [旧密码] password [新密码]`
- 查看数据库：`show databases;`
  - 选择数据库：`use [test];`
  - 查看数据库表：`show tables;`
  - 查看表字段：`describe [table];`
