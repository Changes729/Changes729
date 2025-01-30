> 参考资料：
>
> - [[CSDN] PlatformIO 开发 Arduino](https://blog.csdn.net/qq_39080978/article/details/114879766?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165059170516780269871180%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165059170516780269871180&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-114879766.142^v9^control,157^v4^control&utm_term=platformIO+arduino&spm=1018.2226.3001.4187)
> - [[CSDN] 在vscode 中用PlatformIO开发Arduino](https://blog.csdn.net/acktomas/article/details/115393834?ops_request_misc=&request_id=&biz_id=102&utm_term=vscode%20%E5%AE%89%E8%A3%85%20platformIO&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-8-115393834.nonecase&spm=1018.2226.3001.4187)

# PlatformIO

本教程的目的在于成功部署基于 [VScode](https://code.visualstudio.com/) 的 [PlatformIO 开发环境](https://platformio.org/)。并且成功运行第一个 Arduino Hello World 程序。

**01 什么是 PlatformIO**

PlatformIO 是一个针对开源软硬件开发的一款开源的集成开发环境（IDE）。对于传统 Arduino IDE 而言，其有着非常多的优势。

| 对比项       | Arduino IDE      | PlatformIO    |
| ------------ | ---------------- | ------------- |
| 项目文件数   | === 1 单文件项目 | >> 1 工程项目 |
| 模块化       | 不支持           | 支持          |
| 串口工具     | 支持             | 支持          |
| 调试工具     | 不支持           | 支持          |
| 第三方库使用 | 支持             | 支持          |
| 第三方库安装 | 手动             | 自动+手动     |
| 第三方库查找 | 不支持           | 支持          |
| 代码格式化   | 不支持           | 支持          |

可以看到，Arduino IDE 支持的，PlatformIO 都支持。唯一的问题就是，Platform IO 不是单文件的项目，所以对于一些只会使用 Arduino IDE 的人而言，具有一定的门槛。工程化既是优势，也是劣势。但总体而言，凡是要做的功能越多越复杂，项目化的优势就会越多。

**02 如何安装 PlatformIO**

推荐查看 [参考资料2](https://blog.csdn.net/acktomas/article/details/115393834?ops_request_misc=&request_id=&biz_id=102&utm_term=vscode%20%E5%AE%89%E8%A3%85%20platformIO&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-8-115393834.nonecase&spm=1018.2226.3001.4187)。

其大致步骤为以下内容：
1. 安装 [VSCode](https://code.visualstudio.com/)
2. 在 VSCode 插件（拓展）中搜索并安装 [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
3. 打开 PlatformIO IDE Home Page，选择新建项目，编写项目名称、开发板以及代码框架。默认开发板可以选择 `Arduino UNO`，代码框架可以选择 `Arduino Framework`。
4. 在 `main.cpp` 中输入代码

```cpp
#include <Arduino.h>

#define SERIAL_BAUDRATE 115200

void setup()
{
  Serial.begin(SERIAL_BAUDRATE);
}

void loop()
{
  Serial.println("Hello World!");
  delay(1000);
}
```

**03 如何从 main.cpp 变成一个可以执行的 Arduino**

不同操作系统快捷键不一样。但从代码到成功烧写代码需要两个步骤：
1. 编译（Build）：一般快捷键为 `Ctrl+Shift+B`。或者底部栏有一个 打勾 的 Icon 是构建功能。
2. 烧写（Upload）：一般快捷键为 `Ctrl+Alt+U`。或者底部栏有一个 右箭头 的 Icon 是烧写功能。

然后，为了查看效果，我们需要打开串口，如果串口中有返回的内容，那么就算成功了。

- 打开串口，默认快捷键为 `Ctrl+Alt+S`。或者底部栏有一个 电插头 的 Icon 是串口功能。

## 其他

### 调整串口波特率

先打开串口，然后在串口中按快捷键 `Ctrl+T Ctrl+H` 会出现以下界面：

```txt
--- Port settings (Ctrl+T followed by the following):
---    p          change port
---    7 8        set data bits
---    N E O S M  change parity (None, Even, Odd, Space, Mark)
---    1 2 3      set stop bits (1, 2, 1.5)
---    b          change baud rate
---    x X        disable/enable software flow control
---    r R        disable/enable hardware flow control
```

输入 `b` 修改波特率，我们的是 `115200`。

### 卸载 Platform IO

首先在 VSCode 拓展/插件中卸载 Platform IO。

- Windows：
    - 在 `C:\Users\[你用户的名字]\` 目录下删除 `.platformIO` 文件夹。（如果存在的话）
    - 在 `C:\Users\[你用户的名字]\Documents\` 目录下删除 `PlatformIO` 文件夹。（如果存在的话）



## 网络情况

如果遇到按照包特别慢的时候，可以在VSCode打开PIO终端，然后在终端设置代理，然后运行 `pio run --target upload` 重新配置