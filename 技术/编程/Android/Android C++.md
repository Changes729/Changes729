> 参考资料：
>
> - [[简书] kotlin 调用C/C++](https://www.jianshu.com/p/cfb0076a4245)
> - [[Android Developers] 向您的项目添加 C 和 C++ 代码](https://developer.android.com/studio/projects/add-native-code)

# Android C++

根据官方文档要求，需要安装 `lldb`、`CMake` 以及 `NDK`。

- `CMake` 一般做 `C/C++` 开发都会有，如果没有，可以用 Linux 包管理器下载
  - `pacman -S cmake`
- `NDK` 一般不会自动安装，根据[官方文档](https://developer.android.com/studio/projects/install-ndk)，需要在 `Tools > SDK Manager > SDK Tools > NDK` 选中。
- `LLDB`我这边没有显示出来，查阅了一些资料，网上说是网络代理出问题了。我这边先不管了，官方文档说，LLDB 会在安装 Android Studio 时顺便一同安装了。



## 向已有项目添加 C/C++ 源代码文件

### 确定 C/C++ 文件的位置

- 先将 Android 工程选择为 Project 窗口视图。
- 依次转到 `src > main`，在 main 目录下右键选择 `New > Directory`
- 输入 cpp 作为目录名称。
- 然后就可以放入自己的文件了。
- 放入文件后，需要自己 [配置 CMake](https://developer.android.com/studio/projects/configure-cmake)



### 配置 CMake

- 在项目 `app` 目录新建 `CMakeLists.txt` 

- 下面是 `CMakeLists.txt` 模板文件

  ```cmake
  # Sets the minimum version of CMake required to build your native library.
  # This ensures that a certain set of CMake features is available to
  # your build.
  
  cmake_minimum_required(VERSION 3.4.1)
  
  # Specifies a library name, specifies whether the library is STATIC or
  # SHARED, and provides relative paths to the source code. You can
  # define multiple libraries by adding multiple add_library() commands,
  # and CMake builds them for you. When you build your app, Gradle
  # automatically packages shared libraries with your APK.
  
  add_library( # Specifies the name of the library.
               native-lib
  
               # Sets the library as a shared library.
               SHARED
  
               # Provides a relative path to your source file(s).
               src/main/cpp/native-lib.cpp )
  
  # Specifies a path to native header files.
  include_directories(src/main/cpp/include/)
  
  find_library( # Defines the name of the path variable that stores the
                # location of the NDK library.
                log-lib
  
                # Specifies the name of the NDK library that
                # CMake needs to locate.
                log )
  
  # Links your native library against one or more other native libraries.
  target_link_libraries( # Specifies the target library.
                         native-lib
  
                         # Links the log library to the target library.
                         ${log-lib} )
  
  add_library( app-glue
               STATIC
               ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c )
  
  # You need to link static libraries against your shared native library.
  target_link_libraries( native-lib app-glue ${log-lib} )
  ```

  

### [配置 Gradle](https://developer.android.com/studio/projects/gradle-external-native-builds)

- 对 `app` 模块使用右键 `Add C++ to Module` 会比较方便。



### **Hello World**

Android 调用 C++ 程序实质上是库引用，并且 Java 虚拟机的名字空间等问题，会导致 Kotelin 内调用的方法与实际 C++ 方法不一致。

这里推荐使用 Android Studio 直接智能生成。

