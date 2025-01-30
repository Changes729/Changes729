> 参考资料：
>
> - [Golang创建最简单的HTTP和HTTPS服务](https://studygolang.com/articles/14947)

# HTTPS 服务器

### 生成证书

```sh
openssl genrsa -out key.pem 2048
openssl req -new -x509 -key key.pem -out cert.pem -days 3650
```

将生成的key.pem、cert.pem和以下代码放在同一目录下

### 对外监听

```go
package main

import (
    "log"
    "net/http"
)

func handler(w http.ResponseWriter, req *http.Request) {
    w.Header().Set("Content-Type", "text/plain")
    w.Write([]byte("This is an example server.\n"))
}

func main() {
    http.HandleFunc("/", handler)
    log.Printf("About to listen on 10443. Go to https://127.0.0.1:10443/")
    // One can use generate_cert.go in crypto/tls to generate cert.pem and key.pem.
    // ListenAndServeTLS always returns a non-nil error.
    err := http.ListenAndServeTLS(":10443", "cert.pem", "key.pem", nil)
    log.Fatal(err)
}
```