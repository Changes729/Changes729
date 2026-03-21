> 参考资料：
>
> - [[Archlinux] Valkey](https://wiki.archlinux.org/title/Valkey)
> - https://valkey.io/：Valkey 的网页
>   - https://raw.githubusercontent.com/valkey-io/valkey/7.2/valkey.conf：valkey 默认配置文件
> - [Predis guide (PHP)](https://redis.io/docs/latest/develop/clients/php/)：PHP examples
>   - [Redis for VS Code](https://redis.io/docs/latest/develop/tools/redis-for-vscode/)：Redis 插件
>   - [Redis CLI](https://redis.io/docs/latest/develop/tools/cli/)：命令行界面，可以支持大规模输入导出导入

# Valkey (Redis)

## 说明

一些大型应用会使用 valkey 作为应用缓存，因为 valkey 的数据是存在缓存中的。



## 关键信息

- 配置文件位置：`/etc/valkey/valkey.conf`，端口配置 `port 6379`



## 配置文件

- 端口，默认6379
- 用户名和密码，如果设置了 `requirepass` ，其实意味着默认用户名为 `default`
- 数据库名称在配置文件中为： `dbfilename` 字段
- 而路径则为：`dir` 字段



## 示例

```go
package main

import (
	"context"
	"github.com/redis/go-redis/v9"
)

func main() {
	ctx := context.Background()

	rdb := redis.NewClient(&redis.Options{
		Addr:	  "localhost:6379",
		Password: "", // no password set
		DB:		  0,  // use default DB
	})

	err := rdb.Set(ctx, "key", "value", 0).Err()
	if err != nil {
		panic(err)
	}

	val, err := rdb.Get(ctx, "key").Result()
	if err != nil {
		panic(err)
	}
	fmt.Println("key", val)

	val2, err := rdb.Get(ctx, "key2").Result()
	if err == redis.Nil {
		fmt.Println("key2 does not exist")
	} else if err != nil {
		panic(err)
	} else {
		fmt.Println("key2", val2)
	}
	// Output: key value
	// key2 does not exist
}
```

