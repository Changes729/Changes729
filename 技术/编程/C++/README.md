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

  