> 参考资料：
>
> - [[Archlinux] MariaDB](https://wiki.archlinux.org/title/MariaDB)
> - [mysql 数据库迁移与备份](https://blog.csdn.net/qq_45872037/article/details/136565263)
> - [A MariaDB Primer](https://mariadb.com/kb/en/a-mariadb-primer/)

# MariaDB(MySQL)

## 操作

- 显示所有数据库：`show databases;`

  - 系统数据库：[mariadb_schema](https://mariadb.com/docs/server/reference/system-tables/mariadb_schema) 、[Information Schema](https://mariadb.com/docs/server/reference/system-tables/information-schema)、[Performance Schema](https://mariadb.com/docs/server/reference/system-tables/performance-schema)、[Sys Schema](https://mariadb.com/docs/server/reference/system-tables/sys-schema)、[The mysql Database Tables](https://mariadb.com/docs/server/reference/system-tables/the-mysql-database-tables)
  - 选择数据库：`use [databases];`

- 显示所有表：`show tables;`

  - 简单描述表结构：`desc [tabl_name];`
  - 查看数据：`select * from [table]`

- 修改用户密码：

  > ```sql
  > SET PASSWORD FOR 'jeffrey'@'localhost' = PASSWORD('cleartext password');
  > 
  > FLUSH PRIVILEGES;
  > ```

- 删除用户：`DROP USER [IF EXISTS] 'username'@'hostname';`



## 软件库

1. [mariadb-connector-nodejs](https://github.com/mariadb-corporation/mariadb-connector-nodejs)
2. [go-sql-driver](https://github.com/go-sql-driver)/[mysql](https://github.com/go-sql-driver/mysql)
3. [mariadb-corporation](https://github.com/mariadb-corporation)/[mariadb-connector-cpp](https://github.com/mariadb-corporation/mariadb-connector-cpp)

连接信息：

- 网络信息（IP、Port）
- 用户信息（User、Password）
- 数据库（database）



## 基本操作

- 基本连接
  - 命令行：`mariadb -u root -p`
- 建库建表
- 增删改查



## 配置信息

- 配置文件：
- 用户名密码：
- 数据位置：