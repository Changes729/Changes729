> 参考资料：
>
> - [How To Write Platform Checks](https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks)：非常有用的 cmake 多平台配置方式

# CMake

- [GLOB](./GLOB.md)

## CMake 常用操作

### Windows

- 设置包安装目录：`cmake .. -DCMAKE_INSTALL_PREFIX=abs_path`
- 编译并安装：`cmake --build . --target INSTALL --config Release -j8`
- [使用 CMake 编译时，设置MT/MD](https://stackoverflow.com/questions/14172856/compile-with-mt-instead-of-md-using-cmake)：`set(CMAKE_CXX_FLAGS_RELEASE "/MT")`

### find_package

当 find_package 找不到路径时，可以添加 `PATHS` 帮助找到对应的 `XXconfig.cmake` 文件

