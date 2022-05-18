# Socket理解与应用

## socket
Socket通常用于TCP/UDP网络通讯上，所以如果谈到Socket，一般就想到网络编程。

在网络通讯中，如果需要建立一个会话，那么必须知道**通讯协议**，**网络A端IP地址**，**网络A端端口**，**网络B端IP地址**，**网络B端端口**这五个信息。Socket就表征了本地的IP地址加端口号，当然还有通讯协议。关于Socket本质，[这篇文章](https://blog.csdn.net/weixin_34252090/article/details/86037970)可以加深理解。

## 任务说明
编写可以进行网络通讯的服务端和客户端，服务端收到客户端的数据之后，可以对客户端的数据进行响应。

TCP连接：
1. 支持多个客户端接入
2. 由客户端发起断开连接
3. 服务端结束时，断开所有客户端的连接
4. 对客户端的响应可以简单的将数据发回

UDP连接：
1. 支持多个客户端数据接收和响应

## 前言与适合阅读人群QA
希望在阅读完[任务说明](#任务说明)后，读者可以自行动手练习，以达到提升自己，学习技术的目的。文章后面讲述了笔者是如何完成这个项目的方式方法，可供读者参考。

### QA项目匹配度
1. 你是否会使用VSCode、CMake工具，在Linux环境下完成C/C++语言的编译，运行与调式?
2. 你是否熟悉多线程编程？
3. 你是否了解TCP网络通讯基本流程？
4. 你是否了解UDP网络通讯基本流程？

如果你还不会某些问题，你可能要去学。而如果你越想要知道上面问题的答案，那么你就越适合这次练习与本文。

## 涉及内容总汇
### socket描述与本质
单一的socket可以认为是本地的IP和一个端口再加上一个网络通讯协议。所以在C语言中，一个网络socket用以下结构描述：
```c
struct sockaddr_in {
  sa_family_t    sin_family;  /* Address family */
  in_port_t      sin_port;    /* Port number. */
  struct in_addr sin_addr;    /* Internet address. */
}
```
其中，`sa_family_t`表示为 _**SocketAddress family**_，就是socket通讯域，通讯域在`socket.h`头文件中有定义，可以看见一类是**Protocol families**，而**Address families**是对**Protocol families**的映射。我们的网络通讯域是`PF_INET`，也就是`AF_INET`。

Linux环境下，Socket从操作系统上看的本质是文件，通过其进行的网络传输其实也是种特殊的IO。Linux环境下使用设备描述符实现对文件的操作。建立与打开一个Socket文件采用下面的操作：
```c
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
```
函数返回一个socket设备描述符。其中`domain`是通讯域，`type`是通讯类型，`protocol`一般为0以选用默认协议。

| domain 域 | 描述 |
| --- | --- |
| AF_INET | IPv4因特网域 |
| AF_INET6 | IPv6因特网域 |
| AF_UNIX | UNIX域 |
| AF_UNSPEC | 未制定 |

| type 类型 | 描述 |
| --- | --- |
| SOCK_DGRAM | 长度固定的、无连接的不可靠报文传递 |
| SOCK_RAM | IP协议的数据报接口 |
| SOCK_SEQPACKET | 长度固定、有序、可靠的面向连接报文传递 |
| SOCK_STREAM | 有序、可靠、双向的面向连接字节流 |

如果我们想要使用TCP建立连接，那么两个socket创建方式如下：
```c
/*客户端*/
clientSocket = socket(AF_INET, SOCK_STREAM, 0);

/*服务端*/
serverSocket = socket(AF_INET, SOCK_STREAM, 0);
bind(serverSocket, (struct sockaddr *)&servAddr, sizeof(servAddr));
```

这里发现，客户端并没有`bind()`操作。因为客户端可以让系统选用一个默认的端口，而服务端通常要有一个确定的端口方便其他客户端进行连接。
### TCP/UDP通讯流程
```
    服务端                    客户端             TCP流程
      ↓                        ↓
  打开Socket                打开Socket           socket()创建
      ↓                        ↓
绑定本地IP+端口内容    设置远程Socket的Ip加Port     服务器调用bind()
      ↓                        ↓
   允许连接                    ----              服务器调用listen()
      ↓                        ↓
   等待连接     <-------     发起连接             服务器调用accept()，  
      ↓                        ↓                客户端调用connect()
  [发送·读取]   <------->   [发送·读取]           文件读写，read(),write()
      ↓                        ↓
   断开连接                   断开连接            文件关闭,close()
      ↓                        ↓
  关闭Socket               关闭Socket
```

```
    服务端                    客户端             UDP流程
      ↓                        ↓
  打开Socket                打开Socket           socket()创建
      ↓                        ↓
绑定本地IP+端口内容    设置远程Socket的Ip加Port     服务器调用bind()
      ↓                        ↓
  [发送·读取]   <------->   [发送·读取]           文件读写，read(),write()
      ↓                        ↓
  关闭Socket               关闭Socket            文件关闭,close()
```

## 正文
### 设计前言
TCP连接相比与UDP连接要复杂一些。从服务器角度看，我们要实现`Open()`函数，负责建立与配置服务端socket，并且开启一个连接客户端的线程`AcceptFunc()`，然后主线程负责等待用户输入的退出命令，以运行`Close()`函数。

当连接客户端的线程`AcceptFunc()`成功连接一个客户端后，会保存客户端的连接信息，并创建一个消息接收线程`ListenFunc()`。

当客户端另一端关闭时，服务端会关闭消息接收线程，并发送**已经关闭**的消息，再让客户端的socket关闭。服务端的连接关闭后自动释放资源。

客户端来看比较简单，只需要与服务端建立连接后，开启一个发送消息的线程，主线程中一直等待服务器的关闭消息。

服务端设计如下：
```c
typedef struct msg
{
  int socket;
  pthread_t tid;
  struct sockaddr_in sockAddress;
  struct msg *next;
} Item_t;
typedef Item_t *ItemPtr_t;

void Open();
void Close();

void AcceptSocket();
void ReceiveMsg();

void *Accept();
void *Receive();
```
其中自定义类型包含了文件描述符、线程标识符、客户端地址以及下一个元素指针。

### Open()
```c
void Open()
{
  /*开启服务端socket，设置socketAddr并绑定*/
  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  servAddr = (struct sockaddr_in){
      AF_INET,
      htons(SERV_PORT),
      htonl(INADDR_ANY),
      ""};
  bind(listen_fd, (struct sockaddr *)&servAddr, sizeof(servAddr));
  
  /*允许监听连接*/
  listen(listen_fd, 20);
  printf("Accepting connections ..\n");
  cliAddrLenth = sizeof(struct sockaddr_in);

  //FLOW:开启接收连接线程
  pthread_create(&_accept, NULL, Accept, NULL);
}
```

### AcceptSocket()
```c
void AcceptSocket()
{
  ItemPtr_t pNewItem = malloc(sizeof(Item_t));

  /* 设置pthread_cleanup函数 */
  pthread_cleanup_push(_AcceptCleanUp, pNewItem);
  pNewItem->socket = accept(listen_fd, (struct sockaddr *)&pNewItem->sockAddress, &cliAddrLenth);
  pthread_cleanup_pop(0);

  /* 同步互斥区 */
  pthread_mutex_lock(&_itemLock);
  pNewItem->next = _pItem;
  _pItem = pNewItem;
  pthread_mutex_unlock(&_itemLock);

  /* 开启消息接收线程 */
  pthread_create(&pNewItem->tid, NULL, Receive, pNewItem);
  printf("成功链接一个socket\n");
}
```
因为线程是默认设置，所以默认是`PTHREAD_CANCEL_ENABLE`以及`PTHREAD_CANCEL_DEFERRED`的。这样，当其他线程发送一个`pthread_cancel()`消息时，只可能在`accept()`中取消（`accept()`函数在POSIX标准中存在取消点）。我们在`accept()`前后注册一个`_AcceptCleanUp()`函数，可以保证我们`malloc()`的元素被正确释放。

```c
void _AcceptCleanUp(void *arg)
{
  free(arg);
  printf("链接函数退出\n");
}
```

### ReceiveMsg()
```c
void ReceiveMsg(ItemPtr_t socket)
{
  int n = 0;
  pthread_cleanup_push(_ReceiveCleanUp, socket);
  while (buffer[read(socket->socket, buffer, MAXBUFFERLENTH)] = '\0', 1)
  {
    printf("received from %s at PORT %d:%s\n",
           inet_ntop(AF_INET, &socket->sockAddress.sin_addr, str, sizeof(str)),
           ntohs(socket->sockAddress.sin_port), buffer);
    write(socket->socket, buffer, strlen(buffer));
    if(strcmp(buffer, "quit") == 0 || strcmp(buffer, "close") == 0)
    {
      break;
    }
  }
  pthread_cleanup_pop(0);
}
```
读取线程可能阻塞在`read()`函数上，同样的`read()`也存在取消点。我们在`read()`前后注册`_ReceiveCleanUp()`函数，将客户端的socket关闭：

这个函数在接收到客户端信息后，会将客户端的信息发回。这里很好的展示了Linux标准文件读写`read()`和`write()`。
```c
void _ReceiveCleanUp(void *arg)
{
  ItemPtr_t pItem = arg;
  close(pItem->socket);
  pItem->tid = 0;
}
```

### Close()
```c
void Close()
{
  /* 先关闭接收连接的函数 */
  pthread_cancel(_accept);
  pthread_join(_accept, NULL);

  while(NULL != _pItem)
  {
    ItemPtr_t pTmp = _pItem;
    if(pTmp->tid > 0)
    {
      write(pTmp->socket, "quit", strlen("quit"));
      pthread_cancel(pTmp->tid);
      _pItem = _pItem->next;
      pthread_join(pTmp->tid, NULL);
    }    
    free(pTmp);
    printf("清理一个socket\n");
  }
  printf("退出");
}
```

### TCP客户端
客户端需要获取目标服务器的IP，通常使用命令行后跟参数运行。
```c
#include <netdb>

int main(int argc, const char *argv[])
{
  struct hostent *host;

  if ((host = gethostbyname(argv[1])) == NULL)
  {
    herror("gethostbyname error!");
    exit(1);
  }

  if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("socket create error!");
    exit(1);
  }
  else
  {
    socketAddressIn = (struct sockaddr_in){
        AF_INET,
        htons(SERVPORT),
        *((struct in_addr *)host->h_addr_list[0]),
        ""};
  }

  connect(clientSocket, (struct sockaddr *)&socketAddressIn, SIZEOF_SOCKADDR);
}
```
我们通过命令行参数`argv`，并且通过`gethostbyname()`函数校验目标IP地址是否正确。最后配置在`socketAddressIn`参数上。最后`connect()`函数将本地socket同远程IP地址进行绑定。

绑定完成后，数据的发送和读取就和服务端一样啦。

![123](https://raw.githubusercontent.com/Changes729/Diary/master/image/TCP_CLIENT_SERVER.gif)

### UDP接收及发送
UDP模型比TCP而言少了建立连接的步骤。同时在建立socket的时候需要将`type`类型定义为`SOCK_DGRAM`。而数据报形式下，socket数据接收和发送依旧需要目标地址信息。下面两个函数就可以实现没有建立连接的情况下的数据发送：

```c
#include<sys/socket.h>

ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n,
			 int __flags, __SOCKADDR_ARG __addr,
			 socklen_t *__restrict __addr_len);
       
ssize_t sendto (int __fd, const void *__buf, size_t __n,
		       int __flags, __CONST_SOCKADDR_ARG __addr,
		       socklen_t __addr_len);
```