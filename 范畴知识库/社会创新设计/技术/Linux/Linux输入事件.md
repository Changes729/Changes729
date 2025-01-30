# Linux输入事件

## 键盘事件

C语言Linux输入事件从对应的`/dev/input/eventX`读取。其中，键盘输入的结构体在`#include <linux/input.h>`中。

```c
struct input_event {
#if (__BITS_PER_LONG != 32 || !defined(__USE_TIME_BITS64)) && !defined(__KERNEL__)
	struct timeval time;
#define input_event_sec time.tv_sec
#define input_event_usec time.tv_usec
#else
	__kernel_ulong_t __sec;
#if defined(__sparc__) && defined(__arch64__)
	unsigned int __usec;
	unsigned int __pad;
#else
	__kernel_ulong_t __usec;
#endif
#define input_event_sec  __sec
#define input_event_usec __usec
#endif
	__u16 type;
	__u16 code;
	__s32 value;
};
```

简单来看：

```c
struct input_event {
	struct timeval {
  		__time_t tv_sec;		/* (long) Seconds.  */
  		__suseconds_t tv_usec;	/* (long) Microseconds.  */
    } time;
	__u16 type;
	__u16 code;
	__s32 value;
};
```

用python写，需要用到`struct`模块。[官方文档](https://docs.python.org/zh-cn/3.10/library/struct.html)

```python
import struct

FORMAT = 'llHHI'
EVENT_SIZE = struct.calcsize(FORMAT)

in_file = open("/dev/input/event0", "rb")
event = in_file.read(EVENT_SIZE)
(tv_sec, tv_usec, type, code, value) = struct.unpack(FORMAT, event)
in_file.close()
```

`l - long`、`H - unsigned short`、`I - unsigned int`



## 鼠标事件

鼠标事件分为`案件事件`和`移动事件`。点击行为和键盘一致。

在`python`中，鼠标位置可以直接通过`pyautogui.position()`获取。



### Python线程非阻塞读取

```python
# IO 放在线程里操作
def read_file_cb(fd):
    return fd.read(EVENT_SIZE)

# 线程读完后的回调
def after_read_file_cb(future_file):
    event = future_file.result()
    print(event)
    _RUNNING = False

_RUNNING = True
in_file = open(FPATH, "rb")
executor = ThreadPoolExecutor(1)
future_file = executor.submit(read_file_cb, in_file)
future_file.add_done_callback(after_read_file_cb)

while(_RUNNING):{}

# 主线程可以用 cancel() 取消线程
# future_file.cancel()
executor.shutdown()
in_file.close()
```



## 多点触控协议

- 驱动类型：`#define EV_ABS      0x03`
- 驱动事件
  - **ABS_MT_TOUCH_MAJOR**：触点主轴半径（a）
  - **ABS_MT_TOUCH_MINOR**：触点短轴半径（b）
  - **ABS_MT_WIDTH_MAJOR**：接近域主轴半径（a）
  - **ABS_MT_WIDTH_MINOR**：接近域短轴半径（b）
  - **ABS_MT_PRESSURE**：接触区域压力
  - **ABS_MT_DISTANCE**：接近距离
  - **ABS_MT_ORIENTATION**：（没看懂）好像是触点的方向，但是触点椭圆的方向默认是（touch - width）的向量，那么这个值又能有什么影响呢？而且不是可以用 ABS_MT_POSITION - ABS_MT_TOOL 计算么？
  - **ABS_MT_POSITION_X**/**ABS_MT_POSITION_Y**：触点中心
  - **ABS_MT_TOOL_X**/**ABS_MT_TOOL_Y**：接近中心
  - **ABS_MT_TOOL_TYPE**：触点类型，默认省略（因为屏幕无法识别接触的物体具体是什么）
  - **ABS_MT_BLOB_ID**：触摸A类设备低级匿名分组，将几个数据包合成一个形状打包。忽略。
  - **ABS_MT_TRACKING_ID**：触点生命周期关联，这个是系统判断的ID，递增。
  - ABS_MT_SLOT：触控点位，信号会发送这个数值来做触控点信号切换

> Windows POINTER_TOUCH_INFO
>
> ```c++
> typedef struct tagPOINTER_TOUCH_INFO {
>   POINTER_INFO pointerInfo;
>   TOUCH_FLAGS  touchFlags;
>   TOUCH_MASK   touchMask;
>   RECT         rcContact;
>   RECT         rcContactRaw;
>   UINT32       orientation;
>   UINT32       pressure;
> } POINTER_TOUCH_INFO;
> ```
>
> Windows 使用 矩形 拟合。

多点触控协议还需要使用 `ioctl` 获取触摸点的值域。



## 参考资料

- [Linux-hexdump命令调试event驱动—详解(13)](https://www.cnblogs.com/lifexy/p/7553550.html)
- [python-struct](https://docs.python.org/3/library/struct.html#module-struct)
- [腾讯云 - Linux键盘按键驱动 (详解)](https://cloud.tencent.com/developer/article/1012323)
- [[Coder] - python 非阻塞文件读取](https://www.coder.work/article/1252764)
- [[CSDN] - Linux input子系统之Input event codes](https://blog.csdn.net/weixin_43444989/article/details/122597029)
    - [Input Event Codes](https://www.kernel.org/doc/html/v4.15/input/event-codes.html#event-codes) 
- [Multi-touch (MT) Protocol](https://www.kernel.org/doc/html/v4.18/input/multi-touch-protocol.html)
    - [Wiki 椭圆](https://zh.wikipedia.org/wiki/%E6%A4%AD%E5%9C%86)
- [[Android] 触摸设备](https://source.android.com/docs/core/interaction/input/touch-devices?hl=zh-cn#x-and-y-fields)：里面介绍了Android获取触摸屏原始数据后应该如何处理
    - [Linux input子系统 io控制字段](https://blog.csdn.net/wh_19910525/article/details/11948297)：文章介绍了 Linux 下使用 `ioctl` 获取一些设备数据

