> 原文链接：
>
> - [Ubuntu下搭建STC单片机开发环境](https://zhou-yuxin.github.io/articles/2019/Ubuntu%E4%B8%8B%E6%90%AD%E5%BB%BASTC%E5%8D%95%E7%89%87%E6%9C%BA%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83/index.html)

# Ubuntu下搭建STC单片机开发环境

8051 架构

编译器：sdcc

```cpp
#include <8051.h>

void delay(unsigned long loop) {
    while (loop) {
        loop--;
    }
}

void main() {
    while (1) {
        delay(100000);
        P1_7 = 0;
        delay(100000);
        P1_7 = 1;
    }
}
```

编译：`sdcc main.c`

hex文件生成：`packihx main.ihx > main.hex`

烧录：

`sudo stcgal -o clock_source=internal main.hex`