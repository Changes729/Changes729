> *参考资料*
>
> - [[Stack Overflow] How to collect source files with CMake without globbing?](https://stackoverflow.com/questions/10914607/- how-to-collect-source-files-with-cmake-without-globbing)
> -  [[Stack Overflow] Is it better to specify source files with GLOB or each file individually in CMake?](https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak)
> -  [[Stack Overflow] how to use CMake file (GLOB SRCS *. ) with a build directory](https://stackoverflow.com/questions/34863374/how-to-use-cmake-file-glob-srcs-with-a-build-directory)
> -  [[知乎] cmake 里用 glob 到底好不好？](https://www.zhihu.com/question/373313782)

# CMake GLOB 问题

> 还是没能找出GLOB到底那里不好的问题

## 前景提要

朋友有个项目是[Visual Studio](https://visualstudio.microsoft.com/zh-hans/)上跑的，我对那个项目比较感兴趣，但是我只有Linux系统，所以就打算用[CMake](https://cmake.org/)+[VSCode](https://code.visualstudio.com/)在Linux下编译出来。

在去掉`.vcxproj`，并添加`CMakeLists.txt`后大致文件结构如下

```sh
.
├── 3rdparty # 第三方库
│   ├── glfw
│   ├── glm
│   ├── glslang
│   ├── shaderc
│   ├── SPIRV-Headers
│   └── spirv-tools
├── build # CMake build 目录
├── CMakeLists.txt # 项目层CMake描述
├── README.md
├── script # Linux下一些脚本
│   ├── build.sh
│   └── test.sh
├── src # 项目源文件
│   ├── app
│   ├── CMakeLists.txt # 源文件层CMake描述
│   ├── core
│   └── main.cpp
├── test
└── workdir # 资源目录
```

第一个`CMakeLists.txt`主要用来描述项目和依赖库：

```CMake	
cmake_minimum_required(VERSION 3.0.0)
project(Playground VERSION 0.1.0)

## set CPACK_PROJECT_NAME
if(DEFINED ENV{CMAKE_PROJECT_NAME})
  message("Use environment project name: " $ENV{CMAKE_PROJECT_NAME})
  set(CPACK_PROJECT_NAME $ENV{CMAKE_PROJECT_NAME})
else()
  set(CPACK_PROJECT_NAME ${PROJECT_NAME})
  set(ENV{CMAKE_PROJECT_NAME} ${CPACK_PROJECT_NAME})
endif()

## set CPACK_PROJECT_VERSION
if(DEFINED ENV{CMAKE_PROJECT_VERSION})
  message("Use environment project version: " $ENV{CMAKE_PROJECT_NAME})
  set(CPACK_PROJECT_VERSION $ENV{CMAKE_PROJECT_VERSION})
else()
  set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
  set(ENV{CMAKE_PROJECT_VERSION} ${CPACK_PROJECT_VERSION})
endif()

## set Compiler Flags.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++1z" COMPILER_SUPPORTS_CXX1Z)
if(COMPILER_SUPPORTS_CXX17)
  message("Use std C++17.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX1Z)
  message("Use std C++1z.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
else()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ compiler.")
endif()

## extra compiler warnings
if ("${CMAKE_C_COMPILER_ID}" MATCHES ".*Clang.*")
	SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wunused-variable -Werror")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
	SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wunused-but-set-variable -Wunused-variable -Werror")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "Intel")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/linux_pc)

set(SHADERC_SKIP_TESTS ON CACHE BOOL "Shaderc tests" FORCE)
set(SHADERC_SKIP_EXAMPLES ON CACHE BOOL "" FORCE)
set(SHADERC_SKIP_COPYRIGHT_CHECK ON CACHE BOOL "" FORCE)
set(SPIRV-Headers_SOURCE_DIR "3rdparty" CACHE BOOL "" FORCE)

## support pkg_check_modules
find_package(PkgConfig REQUIRED)

add_subdirectory(3rdparty/glfw)
add_subdirectory(3rdparty/glm)
add_subdirectory(3rdparty/SPIRV-Headers)
add_subdirectory(3rdparty/spirv-tools)
add_subdirectory(3rdparty/glslang)
add_subdirectory(3rdparty/shaderc)

pkg_check_modules(LIBUSB REQUIRED vulkan)
include_directories(${VULKAN_INCLUDE_DIRS})
link_directories(${VULKAN_LIBRARY_DIRS})
link_libraries(${VULKAN_LIBRARIES})

add_subdirectory(src)
```

可以看到有对编译器版本的设置、项目名称、版本号等设置，还有`add_subdirectory`操作来确定整个项目的第三方库依赖关系。

这里也通过`PkgConfig`去搜索一些系统中依赖的库，比如`vulkan`。

最后引入`src`目录开始开发。`src`目录下的`CMakeLists.txt`主要用来描述工程结构：

```CMake
# Include .h ###################################################################
include_directories(.)
include_directories(./app)
include_directories(./core)
include_directories(./core/common)
include_directories(./core/scanline)
include_directories(./core/vg)
include_directories(./core/vk)
include_directories(./core/vulkan)

# find library #################################################################
include_directories("../3rdparty/glm/")

# include .c/.cpp ##############################################################
file(GLOB SOURCE_CPP "./app/*.cpp")
file(GLOB SOURCE_CPP "./core/*.cpp")
file(GLOB SOURCE_CPP "./core/common/*.cpp")
file(GLOB SOURCE_CPP "./core/scanline/*.cpp")
file(GLOB SOURCE_CPP "./core/vg/*.cpp")
file(GLOB SOURCE_CPP "./core/vk/*.cpp")
file(GLOB SOURCE_CPP "./core/vulkan/*.cpp")

# generate exec obj ############################################################
add_executable( ${CPACK_PROJECT_NAME}
  "main.cpp"
  ${SOURCE_CPP}
)

# link librarys ################################################################
target_link_libraries(${CPACK_PROJECT_NAME} glfw)
target_link_libraries(${CPACK_PROJECT_NAME} vulkan)
target_link_libraries(${CPACK_PROJECT_NAME} shaderc)
```

然后编译，最后报出了一大堆无法定位的`undefined reference`问题。

## 问题解决

<u>这是因为`file(GLOB SOURCE_CPP`前后覆盖了</u>。按照下面的写法CMake能正常引入所有Source文件了。

```cmake
file(GLOB SOURCE_CPP
  "./app/*.cpp"
  "./core/*.cpp"
  "./core/common/*.cpp"
  "./core/scanline/*.cpp"
  "./core/vg/*.cpp"
  "./core/vk/*.cpp"
  "./core/vulkan/*.cpp"
)
```

