> 参考资料：
>
> - [重写、覆盖、多态的差异](https://www.cnblogs.com/txwsh1/archive/2008/06/28/1231751.html)
> - [形参包](https://zh.cppreference.com/w/cpp/language/parameter_pack)：`...` 语法
> - [C++ 异常原理：以一个小程序为例](https://mp.weixin.qq.com/s/GRtWF9m65-D5iMLXHrKcRw)：标准库实现向上寻栈，明明都空指针异常了，程序为何还能继续执行呢？
>   - [C++异常机制的实现方式和开销分析](https://baiy.cn/doc/cpp/inside_exception.htm)：还是这篇文章写的比较好

# C++

## 小技巧

- 向量排序：

  ```cpp
  #include <functional>
  
  void function(vector<int> v)
  {
      // same as less<>
      sort(v.begin(), v.end(), greater<int>());
  }   
  ```



## 数组定义

```c
/** main.c */
#include <stdint.h>
#include <stdio.h>

uint8_t           uint8_arr[]   = {0, 1, 2};
uint16_t          uint16_arr[]  = {0, 1, 2};
const char* const index_arr_0[] = {[0] = "0", [1] = "1"};
const char* const index_arr_1[] = {[0] = "0", [3] = "3"};

void value_of_array(const char* const arr[], unsigned size);

int main()
{
  printf("index array 0 size: %lu\n", sizeof(index_arr_0) / sizeof(const char*));
  value_of_array(index_arr_0, sizeof(index_arr_0) / sizeof(const char*));
  printf("index array 1 size: %lu\n", sizeof(index_arr_1) / sizeof(const char*));
  value_of_array(index_arr_1, sizeof(index_arr_1) / sizeof(const char*));

  return 0;
}

void value_of_array(const char* const arr[], unsigned size)
{
  for(int i = 0; i < size; ++i) {
    printf("\tvalue %i: %s\n", i, arr[i]);
  }
}
```

```sh
index array 0 size: 2
        value 0: 0
        value 1: 1
index array 1 size: 4
        value 0: 0
        value 1: (null)
        value 2: (null)
        value 3: 3
```

