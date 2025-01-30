# DBus的理解与应用（笔记）

## 目录
* [DBus是什么](#DBus)
* [练习工程任务说明](#任务说明)
* [前言与适合阅读人群QA](#前言与适合阅读人群QA)
  * [问答](#QA项目匹配度) 
* [项目涉及知识点](#涉及内容总汇)
  * [开发环境](#DBus开发环境)
  * [使用效果](#DBus使用效果)
  * [DBus守护进程](#DBus守护进程)
  * [推荐阅读](#推荐阅读)
* [具体实现](#正文)
  * [DBus连接与命名](#DBus连接与命名)
  * [DBus消息建立](#DBus消息建立)
  * [DBus消息内容与发送](#DBus消息内容与发送)
  * [DBus消息区分与接收](#DBus消息区分与接收)
  * [DBus方法回传与回传接收](#DBus方法回传与回传接收)
  * [其他使用](#其他使用)

## DBus
DBus是由[freedesktop.org]()开源管理的一个IPC(Inter-Process Communication, 进程间通讯)软件工具。freedesktop.org专门为开发者提供桌面窗口系统与桌面环境之间的互操作性和基础技术共享的项目。像他们还有项目类似`opower`，开发者可以用它来显示电池和充电信息。而DBus作为一个IPC工具，它被设计成为一种低开销、低延迟的IPC，并被多种桌面环境（如KDE、GNOME等）所采用。

## 任务说明
本次项目练习，是在Linux环境下，使用C语言，通过DBus，实现两个程序的进程间通讯功能。

要求：
1. 分客户端和服务端应用程序
2. 客户端需要实现向服务端发送signal的功能
3. 客户端还需要实现向服务端调用method的功能，并获取方法调用的返回值。
4. 交叉编译至[相应硬件]()上运行

## 前言与适合阅读人群QA
希望在阅读完[任务说明](#任务说明)后，读者可以自行动手练习，以达到提升自己，学习技术的目的。文章后面讲述了笔者是如何完成这个项目的方式方法，可供读者参考。

### QA项目匹配度
1. 你是否熟悉C语言下DBus进程间通讯流程？

如果你还不会某些问题，你可能要去学。而如果你越想要知道上面问题的答案，那么你就越适合这次练习与本文。

## 涉及内容总汇
### DBus开发环境
DBus被广泛用于Linux系统底层。属于Linux系统支持进程。我们虽然可以从网上获取DBus源码并安装，不过这里还是推荐`apt install libdbus-1-dev`安装，可以看见在`usr/include/`目录下，多了一个`dbus-1.0`的目录，里面存有dbus开发所需要的头文件。这里还需要做的是将`/usr/lib/x86_64-linux-gun/dbus-1.0/include/dbus/dbus-arch-deps.h`文件拷贝到`usr/include/dbus-1.0/dbus/`目录下。

### DBus效果演示
我们先编写了一个客户端和一个服务端进程，服务端主要内容如下图所示：
![服务端行为](https://raw.githubusercontent.com/Changes729/Diary/master/image/DBus_Server_%E8%AF%B4%E6%98%8E.gif)
服务端在主函数中做等待**信号与方法的接收**，图中，前两个断点打着的表示接收进程信号，并通过`printf()`输出。第三个断点是调用方法。而在方法调用中，我们定义好了两个返回值`stat`和`level`都是定值。

![客户端行为](https://raw.githubusercontent.com/Changes729/Diary/master/image/DBus_Client_%E8%AF%B4%E6%98%8E.gif)
客户端非常简单，它将发送一个信号，也发送一个方法调用。

![](https://raw.githubusercontent.com/Changes729/Diary/master/image/DBus%E6%BC%94%E7%A4%BA%E6%95%88%E6%9E%9C.gif)
可以看见，左边返回两个消息，第一个是收到了信号，而第二个是调用了方法。右边则接收到了方法调用的返回值。

### DBus守护进程
DBus通讯使用DBus守护进程作为消息的路由，从而可以将消息转发至其他进程。可以使用`ps -aux | grep dbus`命令查看后台的dbus守护进程。

### 推荐阅读
* [DBus学习系列](https://blog.csdn.net/flowingflying/article/details/4527634)

## 具体实现
### DBus连接与命名
DBus需要同**dbus-deamon**建立连接并由其完成信号的接收与发送。连接是必须的。DBus的命名在我们想要使用`methodCall`，也就是方法调用时，是必须的，这会在[DBus信号发送](#DBus消息建立)中提到。

完成同dbus守护进程的连接非常简单:
```c
#include <dbus/dbus.h>

DBusConnection *pConn = dbus_bus_get(DBUS_BUS_SESSION, &err);
```
`DBUS_BUS_SESSION`表示连接到标准会话。完成对守护进程的连接之后，dbus服务端需要向守护进程申请一个名字，这样可以让客户端方面的dbus寻找到它。
```c
#include <dbus/dbus.h>

int ret = dbus_bus_request_name(*ppConn, busName, DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret)
{
  return RES_FAILED;
}
```
`DBUS_NAME_FLAG_REPLACE_EXISTING`选项将会申请替换当前已申请名字的DBus。有另一个选项`DBUS_NAME_FLAG_ALLOW_REPLACEMENT`将允许其他DBus替换自己申请的DBus名字。成功申请后，应当返回`DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER`，表示当前连接已经获取成为本DBus的名字拥有者了。通常，如果申请失败，会返回值为3的`DBUS_REQUEST_NAME_REPLY_EXISTS`宏。

一个标准的DBus连接与命名函数如下：
```c
#include <dbus/dbus.h>

#define RES_SUCCESS -1
#define RES_FAILED   0
#define DBUS_NAME    "test.method.server"

static DBusConnection *pConn;

int DBus_Init()
{
  int dBusRequest;
  DBusError err;

  dbus_error_init(&err);
  pConn = dbus_bus_get(DBUS_BUS_SESSION, &err);
  if (dbus_error_is_set(&err))
  {
    fprintf(stderr, "Connection Error (%s)\n", err.message);
    dbus_error_free(&err);
    return RES_FAILED;
  }
  dBusRequest = dbus_bus_request_name(pConn, DBUS_NAME, 
                                      DBUS_NAME_FLAG_ALLOW_REPLACEMENT, &err);
  if (dbus_error_is_set(&err))
  {
    fprintf(stderr, "Name Error (%s)\n", err.message);
    dbus_error_free(&err);
    return RES_FAILED;
  }

  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != dBusRequest)
  {
    return RES_FAILED;
  }

  return RES_SUCCESS;
}
```

### DBus消息建立
DBus消息种类分为四种：
1. 信号消息
2. 方法调用消息
3. 结果返回消息
4. 错误消息

其中，方法调用与结果返回通常是合并写在一起的，看起来就很像一个大的上下文。即使DBus有四种消息类型，但是建立和发送的逻辑是一样的。（这里不包含错误消息的发送，错误消息的接收存在问题。）

消息的建立使用函数`dbus_message_new_signal()`以及`dbus_message_new_method_call()`函数分别创建一个signal消息与一个methodCall消息。他俩具体声明如下：
```c
//#include<dbus-message.h>
DBusMessage* dbus_message_new_signal        (const char  *path,
                                             const char  *iface,
                                             const char  *name);

DBusMessage* dbus_message_new_method_call   (const char  *bus_name,
                                             const char  *path,
                                             const char  *iface,
                                             const char  *method);
```
一个signal，需要三个变量创建：`path`、`iface`和`name`。其中，`path`变量在接收端效用不明显，`iface`与`name`都是在具体消息接收时，会进行判断的内容，它们的作用需要和[消息接收](#DBus消息区分与接收)一并看。

`dbus_message_new_method_call()`相比`dbus_message_new_signal()`，多了一个`const char  *bus_name`，这个变量是我们在[命名DBus时](#DBus连接与命名)用的那个名字。

### DBus消息内容与发送
当我们获取到创建好的signal或methodCall时，这个`DBusMessage`还没有内容，我们使用函数`dbus_message_iter_init_append()`初始化`DBusMessageIter`迭代器，并通过`dbus_message_iter_append_basic()`函数往其中添加内容。最后，通过`dbus_connection_send()`函数发送。

下面是一个标准的signal发送例程以及一个methodCall例程：
```c
int DBus_SendSig(char *str[])
{
  DBusError err = DBUS_ERROR_INIT;
  dbus_uint32_t serial;

  msg = dbus_message_new_signal("/test/signal/Object", "test.signal.Type", "Test");
  if (NULL == msg)
  {
    printf("Message Null");
    return RES_FAILED;
  }

  dbus_message_iter_init_append(msg, &iter);
  if (!dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, str))
  {
    fprintf(stderr, "Out of memory\n");
    return RES_FAILED;
  }

  if (!dbus_connection_send(pConn, msg, &serial))
  {
    fprintf(stderr, "Out of memory");
    return RES_FAILED;
  }

  dbus_connection_flush(pConn);
  dbus_message_unref(msg);
}
```
注意我们给`DBusMessage`添加数据的函数，使用`DBUS_TYPE_STRING`描述后续内容是一个字符串，同样的dbus中还有其他类型也需要用这样的方式去描述,下面省略了一些类型：
| 类型 | DBus类型 | 描述 |
|-|-|-|
| | | DBUS_TYPE_BYTE |
| 布尔值| dbus_bool_t | DBUS_TYPE_BOOLEAN |
| 16位整形 | dbus_int16_t | DBUS_TYPE_INT16 |
| 32位整形 | dbus_int32_t | DBUS_TYPE_INT32 |
| 64位整形 | dbus_int64_t | DBUS_TYPE_INT64 |
| 双精度浮点数 | double | DBUS_TYPE_DOUBLE |
| 字符串类型 | char * | DBUS_TYPE_STRING |
| 对象路径？| | DBUS_TYPE_OBJECT_PATH |
| | | DBUS_TYPE_SIGNATURE |
| UNIX文件描述符 | int | DBUS_TYPE_UNIX_FD |

### DBus消息区分与接收
当我们另一个进程发送了消息，我们的其他进程就可以获取消息。只不过DBus的消息是**对进程广播**的，所以进程需要添加一些信息，来告诉DBus**哪些信息是本进程感兴趣的**。我们使用方法`dbus_bus_add_match()`实现对消息内容的响应设置。
```c
  dbus_bus_add_match(conn, "type='signal',"
                           "interface='test.signal.Type',"
                     &err);
  dbus_connection_flush(conn);
```
接下来是获取dbus消息：
```c
while (TRUE)
  {
    // non blocking read of the next available message
    dbus_connection_read_write(conn, 0);
    msg = dbus_connection_pop_message(conn);

    if (NULL == msg)
    {
      sleep(1);
      continue;
    }

    //EXP:接收信号、接收方法调用
    if (dbus_message_is_signal(msg, "test.signal.Type", "Test"))
    {
      if (!dbus_message_iter_init(msg, &iter))
      {
        fprintf(stderr, "dbus_message_iter_init error, msg has no arguments!\n");
      }
      else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&iter))
      {
        fprintf(stderr, "not a uint 32 type !\n");
      }
      else
      {
        char *param = 0;
        dbus_message_iter_get_basic(&iter, &param);
        printf("Got signal with value %s\n", param);
      }
    }
    else if (dbus_message_is_method_call(msg, "test.method.Type", "Method"))
    {
      reply_to_method_call(msg, conn);
    }

    dbus_message_unref(msg);
  }
```
当`dbus_connection_read_write()`函数发现`DBusConnection`可以读取下一个消息时，将会解除阻塞，同时使用`dbus_connection_pop_message()`获取到这个消息。[创建消息](#DBus消息建立)的时候，我们提到过函数有三个值，其中`iface`与`name`就对应了`dbus_message_is_signal()`方法中第二第三个参数。从函数中看，只有当`DBusMessage`内容的`iface`、`name`和定义的一样才可以进行下面的流程。

`DBusMessage`是通过`DBusMessageIter`迭代器获取内容的。我们先使用`dbus_message_iter_init()`初始化迭代器，再根据`dbus_message_iter_get_arg_type()`确认参数类型，最后使用`dbus_message_iter_get_basic()`获取`DBusMessage`中的具体数据。

### DBus方法回传与回传接收
从上面DBus消息接收可以看见，我们仅针对信号消息通过`dbus_bus_add_match()`设置了内容，而方法是不需要设置的。其实是因为方法调用在创建的时候就已经设定了`dbus_name`，dbus就是通过这个变量寻找到相应的dbus，从而向这个dbus对应的进程发送方法调用请求。

方法调用消息，分三步，第一步，客户端创建、配置并发送一个**MethodCall**;第二步，服务端接收消息，获取消息内容，完成一些逻辑后，建立并配置返回消息;第三步，客户端接收到服务端返回的消息。

我们看以下源代码：
```c
//Client.c -1
int DBus_MethodCall(char *str[])
{
  DBusError err = DBUS_ERROR_INIT;
  DBusPendingCall *pending = NULL;
  dbus_uint32_t serial, level;
  dbus_bool_t _bool;
  

  msg = dbus_message_new_method_call(METHODDBUS_NAME, "/test/signal/Object", "test.method.Type", "Method");
  if (NULL == msg)
  {
    printf("Message Null");
    return RES_FAILED;
  }

  dbus_message_iter_init_append(msg, &iter);
  if (!dbus_message_iter_append_basic(&iter, DBUS_TYPE_STRING, str))
  {
    fprintf(stderr, "Out of memory\n");
    return RES_FAILED;
  }

  if (!dbus_connection_send_with_reply(pConn, msg, &pending, DBUS_METHOD_REPLY_TIMEOUT_DEFAULT))
  {
    fprintf(stderr, "Out of memory");
    return RES_FAILED;
  }

  dbus_connection_flush(pConn);
  dbus_message_unref(msg);
```
这是一半的客户端代码，大体上与发送信号消息相同，唯一不同的是发送时使用了`dbus_connection_send_with_reply()`函数，并添加了一个`pending`参数。我们接下来看服务端的函数:
```c
//Server.c
void reply_to_method_call(DBusMessage *msg, DBusConnection *pConn)
{
  DBusMessage *reply;
  DBusMessageIter iter;
  dbus_bool_t stat = TRUE;
  dbus_uint32_t level = 21614;
  dbus_uint32_t serial = 0;
  char *param = "";

  // read the arguments
  if (!dbus_message_iter_init(msg, &iter))
    fprintf(stderr, "Message has no arguments!\n");
  else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&iter))
    fprintf(stderr, "Argument is not string!\n");
  else
    dbus_message_iter_get_basic(&iter, &param);

  printf("Method called with %s\n", param);

  reply = dbus_message_new_method_return(msg);
  dbus_message_iter_init_append(reply, &iter);
  if (!dbus_message_iter_append_basic(&iter, DBUS_TYPE_BOOLEAN, &stat))
  {
    fprintf(stderr, "Out Of Memory!\n");
    exit(1);
  }

  if (!dbus_message_iter_append_basic(&iter, DBUS_TYPE_UINT32, &level))
  {
    fprintf(stderr, "Out Of Memory!\n");
    exit(1);
  }

  if (!dbus_connection_send(pConn, reply, &serial))
  {
    fprintf(stderr, "Out Of Memory!\n");
    exit(1);
  }

  dbus_connection_flush(pConn);
  dbus_message_unref(reply);
}
```
前半部分，读取`DBusMessage`参数部分的代码，同信号消息接收是一样的。只是在后面，调用函数`dbus_message_new_method_return()`从客户端发来的`DBusMessage`中，获取了一个新的`DBusMessage`，并将其作为发向客户端的消息。接下来的过程和信号消息的发送是类似的。服务端这边将数据内容发送给客户端之后，客户端便使用`pending`获取返回值：
```c
//Client.c -2
  dbus_pending_call_block(pending);
  msg = dbus_pending_call_steal_reply(pending);
  if (NULL == msg)
  {
    printf("Message Null");
    return RES_FAILED;
  }
  dbus_pending_call_unref(pending);

  if (!dbus_message_iter_init(msg, &iter))
  {
    fprintf(stderr, "Message has no arguments!\n");
  }
  else if (DBUS_TYPE_BOOLEAN != dbus_message_iter_get_arg_type(&iter))
  {
    fprintf(stderr, "Argument is not boolean!\n");
  }
  else
  {
    dbus_message_iter_get_basic(&iter, &_bool);
  }

  if (!dbus_message_iter_next(&iter))
  {
    fprintf(stderr, "Message has too few arguments!\n");
  }
  else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&iter))
  {
    fprintf(stderr, "Argument is not int!\n");
  }
  else
  {
    dbus_message_iter_get_basic(&iter, &level);
    printf("Get method cal return-- status:%d, level:%d\n", _bool, level);
  }

  dbus_message_unref(msg);
}
```
`dbus_pending_call_block()`函数在没有返回前是一直阻塞的。当服务端发回了消息，这个函数会立即解除阻塞。是用`dbus_pending_call_steal_reply()`方法从`DBusPending`中获取回传的`DBusMessage`，随后的步骤，就和信号消息的接收是一样的了。

### 其他使用
1. 可以使用`DBUS_ERROR_INIT`对`DBusError`进行初始化。效果同`dbus_error_init(&err)`一样。
2. `dbus_bus_add_match()`中，一共存在**五种配置类型**，分别是`type`、`sender`、`path`、`interface`和`member`。祥见代码：
```c
  dbus_bus_add_match(conn, "type='signal',"                 //信号类型
                           "sender='test.method.cliend',"   //发送方DBus名称
                           "path='/test/signal/Object',"    //DBusMessage设置的path
                           "interface='test.signal.Type',"  //DBusMessage设置的iface
                           "member='Test'",                 //DBusMessage设置的name
                     &err);
```
3. `dbus_connection_send_with_reply()`最后一个参数`timeout_milliseconds`如果设置太小，会导致`dbus_pending_call_block()`阻塞快速结束，这将导致服务端那边的数据没能顺利回传。为解决这样的方式，一般给`timeout_milliseconds`参数设置为 _**-1**_。这个结论在函数`dbus_connection_send_with_reply_and_block()`中也同样适用。