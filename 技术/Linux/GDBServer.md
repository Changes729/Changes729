> 参考资料：
>
> - [GDB cross-compilation for arm](https://superuser.com/questions/1426875/gdb-cross-compilation-for-arm)：获取交叉编译目标设备的名称
> - [Building GDB and GDBserver for cross debugging](https://sourceware.org/gdb/wiki/BuildingCrossGDBandGDBserver)：如何交叉编译 gdb 与 gdbserver
> - [ftp](https://ftp.gnu.org/gnu/gdb/)：下载 gdb

# GDB Server

- 编译 GDB server：

​	`../configure --host=x86_64-w64-mingw32 --target=x86_64-w64-mingw32`

​	`make LDFLAGS="-static" all-gdbserver -j8`





- `build.sh`

  ```sh
  #!/bin/bash
  
  SCRIPT_DIR=$(dirname $(readlink -f "$0"))
  MAIN_DIR=$SCRIPT_DIR/..
  
  if [ -z $BUILD_DIR ]; then
    BUILD_DIR=$MAIN_DIR/build
  fi
  
  if [ ! -n $TARGET_DEVICE ]; then
    echo "set default target as local device"
    _GCC_VERSION=$(gcc -v 2>&1)
    _GCC_VERSION=${GCC_VERSION#*Target:}
    TARGET_DEVICE=${GCC_VERSION%%Configured*}
  else
    echo "set remote target: "
    echo $TARGET_DEVICE
  fi
  
  BUILD_DIR=$BUILD_DIR/$TARGET_DEVICE
  
  ## Functions defines. ###################################
  function usage() {
    local help="Usage: $0"
  
    echo "$help"
  }
  
  function build() {
    if [ ! -d $BUILD_DIR ]; then
      mkdir -p $BUILD_DIR
    fi
  
    cd $BUILD_DIR
    build_gdb
    build_gdbserver
  }
  
  function build_gdb() {
    mkdir build_gdb
    cd build_gdb
  
    $MAIN_DIR/configure --target=$TARGET_DEVICE --prefix=$BUILD_DIR/install
    make all-gdb -j8
    make install-gdb
    cd ..
  }
  
  function build_gdbserver(){
    mkdir build_gdbserver
    cd build_gdbserver
  
    $MAIN_DIR/configure --host=$TARGET_DEVICE --target=$TARGET_DEVICE --prefix=$BUILD_DIR/install
    make LDFLAGS="-static" all-gdbserver -j8
    make install-gdbserver
    cd ..
  }
  
  function print_dir(){
    pwd $BUILD_DIR/install/bin
    ls -l $BUILD_DIR/install/bin
  }
  
  ## Start from here. #####################################
  input=$1
  
  case "$input" in
  "-h" | "--help")
    usage
    exit 1
    ;;
  
  "-p" | "--install-dir")
    print_dir
    ;;
  
  *)
    build ${@:1}
    print_dir
    ;;
  esac
  ```

- `task.settings`

  ```json
  {
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
      {
        "label": "[build] Windows gdb",
        "type": "shell",
        "command": "./script/build.sh -j8",
        "group": {
          "kind": "build",
          "isDefault": true
        },
        "options": {
          "env": {
            "TARGET_DEVICE": "x86_64-w64-mingw32"
          }
        }
      }
    ]
  }
  ```

  