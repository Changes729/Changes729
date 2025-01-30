> 参考资料
>
> - https://www.rust-lang.org/learn/get-started
> - https://doc.rust-lang.org/reference/
> - [Rust for C++ programmers](https://github.com/nrc/r4cppp)
> - [Rust by Example](https://doc.rust-lang.org/rust-by-example/#rust-by-example)
> - [The Rust Programming Language](https://doc.rust-lang.org/book/title-page.html#the-rust-programming-language)：有很多案例

# RUST

## 语法

` unreachable!(...)`：不可达，类似C++中的断言，简短表示为 `panic!()`

`match`：枚举选择语句，感觉可以完全替代 `if-else`，非常常用

循环：

- `for i in 0..nums.len()`



## 类型

`option<>`：会返回一个枚举类型，包括 `Some<>` 和 `None`，一般写法为：

```rust
match hash_map.get(&key) {
  Some(index) => {},
  None => {}
}
```



## 标准库

哈希存储：[HashSet](https://doc.rust-lang.org/std/collections/struct.HashSet.html)、[HashMap](https://doc.rust-lang.org/std/collections/struct.HashMap.html#)