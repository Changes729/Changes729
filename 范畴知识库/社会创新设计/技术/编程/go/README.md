> 参考资料：
>
> - [Golang](https://go.dev/learn/)
>   - [Go Web Examples](https://gowebexamples.com/)
> - [A Tour of Go](https://go.dev/tour/concurrency/1)：涉及到轻量级线程

# Golang

## A Tour of Go

- 名字首字母大写和导出有关

- golang 可以具名返回

  ```golang
  func split(sum int) (x, y int) {
  	x = sum * 4 / 9
  	y = sum - x
  	return
  }
  ```

- 变量也是需要声明和初始化的。声明通过 `var`，在函数内可以通过 `:=`

- 常量 `const`



- `defer`：`defer` 会先将后续语句压入栈，然后在函数析构时调用栈。这里有一个案例需要注意：

  ```go
  func c() (i int) {
      defer func() { i++ }()
      return 1
  }
  ```

  此时返回的是2，而不是1



- `*` ：指针，比较无用。没有指针运算。

- `type [name] struct`：结构体

  - 初始化：

    ```go
    type Vertex struct {
    	X, Y int
    }
    
    var (
    	v1 = Vertex{1, 2}  // 创建一个 Vertex 类型的结构体
    	v2 = Vertex{X: 1}  // Y:0 被隐式地赋予
    	v3 = Vertex{}      // X:0 Y:0
    	p  = &Vertex{1, 2} // 创建一个 *Vertex 类型的结构体（指针）
    )
    ```

- `var a [10]int`：数组，数组不能改变容量大小，`make` 用来创建动态数组

  - `a[low : high]`：切片，切片是数组的引用
  - `len(s)`：长度
  - `cap(s)`：容量
  - `nil` 切片的长度和容量为 0 且没有底层数组。
  - 可以用 `append` 给 **切片** 添加元素
  - 遍历用 `range`

- `var m map[key]val`：映射定义

  - 增：`m[key] = elem`
  - 删：`delete(m, key)`
  - 查：`elem, ok = m[key]`

- 函数闭包

  ```go
  func adder() func(int) int {
  	sum := 0
  	return func(x int) int {
  		sum += x
  		return sum
  	}
  }
  ```

- 接口：接口也是值

  ```go
  type I interface {
  	M()
  }
  ```

  - 类型断言：`t, ok := i.(T)`，获取接口对应的类型



- `go`：轻量级线程调研
- `chan`：数据通道 `<-`，一定要进一个出一个
- `select`：多通道阻塞，信号量唤醒，多个可调用时只会调用一个；`default` 不会阻塞



## 构建工程

- `go mod init [name]`：初始化一个项目
- `go get [url]`：获取第三方库
- `go mod tidy`：下载库



## 代理

- `export GOPROXY=https://mirrors.aliyun.com/goproxy/,direct`



## 三方库

- [github.com/gorilla/mux](https://github.com/gorilla/mux)：路由库
- [github.com/go-sql-driver/mysql](https://github.com/go-sql-driver/mysql)：MySQL 数据库驱动库



## 其他纪要

type 类型 初始化描述：`omitempty`。有些类型比如Json、XML，其中的字符串可能会空。使用这个初始化时，如果没有定义，则序列化时不会显示错。