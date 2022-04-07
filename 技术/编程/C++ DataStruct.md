# C++ DataStruct

- [优先队列（priority_queue）](https://zh.cppreference.com/w/cpp/container/priority_queue)

  - 构造函数：

    ```c++
    template<
      class T,
      class Container = std::vector<T>,
      class Compare = std::less<typename Container::value_type>
    > class priority_queue;
    ```

  - [emplace](https://zh.cppreference.com/w/cpp/container/priority_queue/emplace)：原位构造元素并排序底层容器

    **复杂度**：<u>对数次比较</u>加上 `Container::emplace_back` 的复杂度。

    - [std::vector<T,Allocator>::emplace_back](https://zh.cppreference.com/w/cpp/container/vector/emplace_back)：添加新元素到容器尾。

      **复杂度**：均摊常数。

- [集合（set）](https://zh.cppreference.com/w/cpp/container/set)：`std::set` 是关联容器，含有 `Key` 类型对象的**已排序集**。每个对象唯一。

  - [lower_bound](https://zh.cppreference.com/w/cpp/container/set/lower_bound)：返回指向首个*不小于*给定键的元素的迭代器，若找不到这种元素，则返回**尾后迭代器**。

    复杂度：与容器大小成对数。

  - [insert](https://zh.cppreference.com/w/cpp/container/set/insert)：插入元素或结点 (C++17 起)

    复杂度：与容器大小成对数， `O(log(size()))` 。
  
- [向量（vector）](https://en.cppreference.com/w/cpp/container/vector)：是一个动态数组。

  - [emplace_back](https://zh.cppreference.com/w/cpp/container/vector/emplace_back)：在容器末尾就地构造元素。

    **复杂度**：均摊常数。

  - [push_back](https://zh.cppreference.com/w/cpp/container/vector/push_back)：拷贝或**移动**value到容器末尾。

    **复杂度**：均摊常数。




