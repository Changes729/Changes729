> *参考资料*
>
> - [Python Dictionary Comprehension](https://www.programiz.com/python-programming/dictionary)：一种通过 for 循环构造字典的方式
> - [Synchronization Primitives](https://docs.python.org/3/library/asyncio-sync.html)
>   - [yield from](http://simeonvisser.com/posts/python-3-using-yield-from-in-generators-part-1.html)
>   - [Queue](https://docs.python.org/3/library/queue.html)
>   - [threading](https://docs.python.org/3/library/threading.html#module-threading)
>   - [Async timer](https://stackoverflow.com/questions/45419723/python-timer-with-asyncio-coroutine)
> - [Python 二进制，十进制，十六进制转换](https://blog.csdn.net/u012063703/article/details/42609833)
> - [python 路径](https://note.nkmk.me/en/python-script-file-path/)

# Python

## 基本语法

- 枚举：`Color = Enum('Color', ['RED', 'GREEN', 'BLUE'])`



## 面向对象

- 私有变量：`_` 下划线表示私有



## 设计模式

- [单例修饰器](https://stackoverflow.com/questions/6760685/creating-a-singleton-in-python)

  ```python
  def singleton(class_):
      instances = {}
      def getinstance(*args, **kwargs):
          if class_ not in instances:
              instances[class_] = class_(*args, **kwargs)
          return instances[class_]
      return getinstance
  
  @singleton
  class MyClass(BaseClass):
      pass
  ```

  



## Python库

- [asyncinotify](./asyncinotify.md)：异步文件监听库。类似 Linux 下的 epoll。
- [Getopt module in Python](https://www.geeksforgeeks.org/getopt-module-in-python/)
- [pyshark](https://github.com/KimiNewt/pyshark)：Python 抓包库
- math
  - `log10`：等于数学中的 `log`
  - `log`：等于数学中的 `ln`




## 小技巧

- 获取 Python 运行文件路径：`os.path.dirname(os.path.abspath(__file__))`
- Python 搭建临时 HTTP 服务器：`python3 -m http.server 5678`
- 导出 requirements 文件：`pip freeze > requirements.txt`



