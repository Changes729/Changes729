# Alluvial 技术思考

## 技术思考

**01 数据基础**

如果希望某个输入方式是同一个，那么不同数据类型，应该通过对基础数据的泛化进行更新。

比如设计一个通用 文本 数据，但是发现需要抽象一个 标签 数据：

```
class Doc {
	Time 	lastTime
	Doc[] 	childs
}

class Tag {
	TagRoot origin
	Tag[]	tags
	Doc[]	childs
}
```

两者可以数据合并。可以用 C 语言的 Type 去理解，同样的数据结构，不同的解析方式。



**02 基本数据**

**02.1 自由文本**

```
class Doc {
	Time 	time
	String	content
}
```

自由文本本质是静态数据，但是数据可能会被更新。因此，仅考虑数据内容和数据时间。



**02.2 标签族**

```
class Tag {
	Tag 		affiliationTag
	String 	 	tagName
	Tag[]	 	explicitTags
	Doc[]	 	childs
}
```

标签族涵盖了其中的所有标签，是一种有限的树状标签管理系统。标签作为叶子节点，需要归属与上一个标签，同时也需要有个名称。



**02.3 归属文本**

```
class AffiliateDoc : Doc {
	Tag[]	affiliationTags
}
```

归属文本在基础的自由文本上，需要归属于多个标签族。



**02.4 抽象文本**

考虑到文本的抽象性，我们大胆的将一个自由文本中自包含一些标签

```
class AbstractDoc {
	Time 	time
	Tag[] 	affiliationTags
	String  content
	
	Tag[]	explicitTags
	Tag[]	implicitTags
}
```

最后，把 标签 和 抽象文本数据进行同一化，这就是最基础的数据类似（暂定）：

```
class AbstractDoc {
	Time 			time
	AbstractDoc[] 	affiliationTags
	String  		content
	
	AbstractDoc[]	explicitTags
	AbstractDoc[]	implicitTags
}
```

其中，

- 时间和内容构成了基础的自由文本。
- 父内容和子内容加上本身内容，构成了一个抽象的标签系统。

为了方便拓展，我们用函数式定义一下：

```
class AbstractDoc {
	Time 			time();
	AbstractDoc[] 	affiliationTags();
	String  		content();
	
	AbstractDoc[]	explicitTags();
	AbstractDoc[]	implicitTags();
}
```



**03 操作系统适配**

**03.1 根标签系统**

当前操作系统的文件系统是树状系统：

```
class File {
	Time	time
	File	parents
	string	content
	
	File[]	childs
}
```

为了适配当前的操作系统，设计了一个根标签，可以扫描到所有文件。

```
class OpSystemFile : AbstractDoc {
	Time 			time();
	AbstractDoc 	affiliationTags();	//len == 1
	String  		content();
	
	AbstractDoc[]	explicitTags();	
	AbstractDoc[]	implicitTags() = delete;
}
```

如果存在子文件，则 content 表示目录名（文件名）。如果不存在则为具体 文件内容。



**03.2 冗余数据信息**

上面缺失的信息，包括多个归属标签，以及生成式标签。需要自建数据库。



**03.3 根数据**

有一些数据无法包含子文件的，则被称为根数据。也就是 `explicitTags` 为 `null`

```
class DataFile : AbstractDoc{
	Time 			time();
	AbstractDoc[] 	affiliationTags();
	String  		content();
	
	AbstractDoc[]	explicitTags() = delete;	
	AbstractDoc[]	implicitTags()
}
```

数据文件可以通过硬连接归属于多个标签族。



**03.4 软硬连接**

硬连接是同一个文件，软连接是不同文件。

`ls -li` 命令可以获取文件的 `inode` ，而 `find -inum [inode]` 可以找到目录下的所有文件。

对于软连接目录，可以用 `find -L -inum [inode]` 搜索所有路径。如果有循环会报错。

可以用 `find [.] -type l -lname [path]` 找到所有指向这个路径的软链接。但是要注意，如下所示，`fileA` 和 `fileB` 是两个不同的软链接。

```
13 Oct 10 09:33 fileA -> ../doc1/fileA
32 Oct 10 09:34 fileB -> ~/Downloads/doc1/fileA
```



**04 对象存储**

**04.1 操作系统标签族**

- model：三维结构数据
- audio：音频数据
- books：电子书数据
- image：图片数据
- ISO：镜像文件备份
- video：视频数据



**05 桌面应用**

- [**wails**](https://wails.io/zh-Hans/)

- [webview](https://github.com/webview)/[webview](https://github.com/webview/webview)

  ```go
  package main
  
  import (
          "fmt"
          "log"
          "net/http"
  
          "github.com/webview/webview"
  )
  
  func main() {
          go func() {
                  // Your Go HTTP server
                  http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
                          fmt.Fprintln(w, "<h1>Hello from Go!</h1><script>alert('Hello from JS!')</script>")
                  })
                  log.Fatal(http.ListenAndServe(":8080", nil))
          }()
  
          // Create the webview
          w := webview.New(true) // Set to true for debugging
          defer w.Destroy()
          w.SetTitle("Go Desktop App")
          w.SetSize(800, 600, webview.HintNone)
          w.Navigate("http://localhost:8080") // Your Go backend URL
          w.Run()
  }
  ```

  
