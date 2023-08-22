> 参考资料：
>
> - [重写、覆盖、多态的差异](https://www.cnblogs.com/txwsh1/archive/2008/06/28/1231751.html)
> - [形参包](https://zh.cppreference.com/w/cpp/language/parameter_pack)：`...` 语法

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

  