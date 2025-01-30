> 参考资料：[Go Web Examples](https://gowebexamples.com/)

# Go Web Examples

文章主要介绍了一些基本操作。主要包括

- Go Project（Go 项目结构）
- Hello World（Go 项目运行）
- HTTP Server （Go HTTP 基本服务器）
- Routing（Go HTTP 路由方法）
- MySQL Database（Go 数据库）
- Templates（Go 网页模版）
- Assets and Files（Go 静态资源管理）
- Forms（Go 表单处理）
- Middleware Basic&Advanced（Go 中间件实现与应用）
- Sessions（Go Cookies）
- JSON（Go JSON）
- Websockets（Go Websockets）
- Password Hashing（Go 密码加密）



其中，包括了第三方拓展有：

- [go-sql-driver](https://github.com/go-sql-driver)/**[mysql](https://github.com/go-sql-driver/mysql)**
- [gorilla](https://github.com/gorilla)/**[sessions](https://github.com/gorilla/sessions)**
- [gorilla](https://github.com/gorilla)/**[websocket](https://github.com/gorilla/websocket)**
- [gorilla](https://github.com/gorilla)/**[mux](https://github.com/gorilla/mux)**
- [golang.org/x/crypto/**bcrypt**](https://golang.org/x/crypto/bcrypt)



另外，在项目中有引用的包有：

- `"net/http"`：基本 HTTP 请求访问库

  ```go
  http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
    ...
  })
  http.ListenAndServe(":80", nil)
  ```

- `"fmt"`：文本格式化库

  ```go
  // 可以用 os.Stdout 或者 fmt.printf 可以在服务端显示信息
  fmt.Fprintf(w, "Hello, you've requested: %s\n", r.URL.Path)
  ```

- `"database/sql"`：数据库基础库

  ```go
  db, err := sql.Open("mysql", "username:password@(127.0.0.1:3306)/dbname?parseTime=true")
  if _, err := db.Exec(query); err != nil {
    log.Fatal(err)
  }
  ```

- `"html/template"`：网页模版库

  ```go
  tmpl := template.Must(template.ParseFiles("layout.html"))
  func(w http.ResponseWriter, r *http.Request) {
      tmpl.Execute(w, "data goes here")
  }
  ```

- `"log"`：日志库

- `"encoding/json"`：JSON库

  ```go
  json.NewDecoder(r.Body).Decode(&user)
  json.NewEncoder(w).Encode(peter)
  ```

