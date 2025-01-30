> 代码来源：[Esp32_oscilloscope](https://github.com/BojanJurca/Esp32_oscilloscope)

# 网页示波器实现扫描

ESP的好处就是可以联网。完全可以当成 Linux 嵌入式的低配平替。最近有个需求就是需要进行远程调试，这放在五六年前，技术方案可能是 `电路设计 -> STM32 下位机 -> QT/MFC 上位机 `，然而，随着ESP的出现，现在这套技术方案可以是：`电路设计 -> ESP32 下位机 + WebServer 上位机`，虽然技术栈可能多了一个 JS/TS，但是，一旦起来那是真的方便。



## 工程概览

原项目是 Arduino 项目；笔者习惯使用 PlatformIO 工程框架，修改后的工程框架如下：

```sh
/
|-- data/var/www/html
		|-- oscilloscope.html 			# 这个就是最终的网页，只有这一个文件是必须的
		|-- *.png									  # 省略其他图片 
|-- src
		|-- Esp32_oscilloscope.ino	# 主程序
		|-- dmesg_functions.h				# 日志
		|-- fileSystem.hpp					# 文件系统
		|-- fsString.h							# 支持文件系统的字符串库
		|-- ftpServer.hpp						# FTP 服务器
		|-- httpServer.hpp					# http 服务器
		|-- network.h								# WiFi 库
		|-- oscilloscope.h					# 示波器功能主文件
		|-- time_functions.h				# 时间库
		|-- userManagement.hpp			# 用户
		|-- version_of_servers.h		# Settings.h
|-- platformio.ini							# PlatformIO 配置文件
```

烧录后，在串口界面看到IP，然后通过网页打开，显示效果和工程Readme中的差不多：

![Screenshot](https://github.com/BojanJurca/Esp32_oscilloscope/raw/master/oscilloscope.png)



## Web示波器实现

直奔主题，系统是如何实现 Web 的示波器显示功能的？通过Google浏览器的开发工具（F12），我们看到了示波器是一个画布（Canvas）：

```html
<canvas id="oscilloscope" width="809" height="512"></canvas>
```

然后去 `oscilloscope.html` 中寻找引用了画布的地方，一共就三处：

第一处是让画布自适应窗口大小的：

```js
function resizeCanvas () {
  if (lastWidth != currentWidth) {
    document.getElementById ('oscilloscope').width = document.getElementById ('vSens').clientWidth;
    lastWidth = currentWidth;
  }
}
```

第二处是示波器窗口绘制主函数：

```js
function drawBackgroundAndCalculateParameters () {
  resizeCanvas ();

  /** 一些参数变量 */
  var x;
  var y;
  var i;
  var j;
  var yGridTick;
  var gridTop;

  restartDrawingSignal = true;  // drawing parameter - for later use
  var canvas = document.getElementById ('oscilloscope');
  var ctx = canvas.getContext ('2d');

  /** 绘制底色 */
  ctx.fillStyle = 'hsl(82, 90%, 10%)';
  ctx.beginPath ();
  ctx.moveTo (0, 0);
  ctx.lineTo (canvas.width - 1, 0);
  ctx.lineTo (canvas.width - 1, canvas.height - 1);
  ctx.lineTo (0, canvas.height - 1);
  ctx.fill ();

  /** 设置线条大小和颜色 */
  ctx.strokeStyle = 'hsl(82, 90%, 40%)';
  ctx.lineWidth = 1;
  ctx.font = '16px Verdana';

  xOffset = 50;

  /** 绘制线框（区分模拟和数字） */
  if (document.getElementById ('analog').checked) {
		...
  } else {
    ...
  }

  /** 根据采样时间设置数轴的数字 */
  switch (document.getElementById ('frequency').value) {
    case '1': screenWidthTime = 10000; // (ms) horizontal frequency = 0,1 Hz, whole width = 10 s, grid tick width = 1 s
      xGridTick = screenWidthTime / 10;
      xScale = (canvas.width - xOffset) / screenWidthTime;
      xLabel = '1 s';
      break;
    case '2': 
      ...
  }

  /** 设置具体数字 */
  for (x = 0; x < screenWidthTime; x += xGridTick) {
    i = xOffset + xScale * x;
    ctx.strokeText (xLabel, i + 25, yOffset + 25);
    ctx.beginPath ();
    ctx.moveTo (i, yOffset + 5);
    ctx.lineTo (i, gridTop);
    ctx.stroke ();
  }
}
```

是的，上面省略了很多，不过基本上是绘制一个白板示波器面板。第三处是具体的波形绘制函数 `drawSignal`：

```js
function drawSignal (myInt16Array, startInd, endInd) {}

ws.onmessage = function (evt) {
  // 错误处理
  if (typeof (evt.data) === 'string' || evt.data instanceof String) {
    alert ('Error message from server: ' + evt.data); // oscilloscope code reporting error (synatx error, ...)
    enableDisableControls (false);
  }
  
  // 解析二进制数据
  if (evt.data instanceof Blob) {
    var myInt16Array = null;
    var myArrayBuffer = null;
    var myFileReader = new FileReader ();
    myFileReader.onload = function (event) {
      myArrayBuffer = event.target.result;
      myInt16Array = new Int16Array (myArrayBuffer);
      drawSignal (myInt16Array, 0, myInt16Array.length - 1); 
    };
    myFileReader.readAsArrayBuffer (evt.data);
  }
};
```

`drawSignal` 函数，只在 `websocket` 的消息处理函数中有调用。而 `websocket` 消息处理也只是接收了数据而已。现在我们不知道数据格式具体是什么，我们得回到 Arduino 去找答案。



## ESP 示波器服务器实现

从Web中找到了 `websocket` 绑定的 URL：

```js
var ws = new WebSocket ('ws://' + self.location.host + '/runOscilloscope');
```

然后我们回到 Arduino 找到了相应 `Websocket` 的函数：

```cpp
void wsRequestHandler (char *wsRequest, WebSocket *webSocket) {
    #define wsRequestStartsWith(X) (strstr(wsRequest,X)==wsRequest)
    if (wsRequestStartsWith ("GET /runOscilloscope")) runOscilloscope (webSocket);
}
```

`runOscilloscope` 函数有一大堆。我们也不用关心，从上面 Web 端的接收函数知道了 Web 接收的是二进制数据，所以我们在 Arduino 代码里找二进制发送的部分，只有一个地方是发送二进制的：

```cpp
void runOscilloscope (WebSocket *webSocket) {
  ...
  oscSender ((void *) &sharedMemory);
  ...
}

void oscSender (void *sharedMemory) {
  unsigned char gpio1 				= (unsigned char) ((oscSharedMemory *) sharedMemory)->gpio1;
  unsigned char gpio2 				= (unsigned char) ((oscSharedMemory *) sharedMemory)->gpio2;
  unsigned char noOfSignals 	= 1; if (gpio2 <= 39) noOfSignals = 2;  // monitor 1 or 2 signals
  oscSamples *sendBuffer 			= &((oscSharedMemory *) sharedMemory)->sendBuffer;
  sendBuffer->samplesAreReady = false;
  bool clientIsBigEndian 			= ((oscSharedMemory *) sharedMemory)->clientIsBigEndian;
  WebSocket *webSocket 				= ((oscSharedMemory *) sharedMemory)->webSocket;

  unsigned long lastMillis = millis ();
  /** 主循环 */
  while (true) {
    delay (1);
    if (sendBuffer->samplesAreReady && sendBuffer->sampleCount) {
      oscSamples sendSamples = *sendBuffer;
      sendBuffer->samplesAreReady = false; 

      /** 计算具体数据大小，并调整字节序 */
      int sendBytes;
      if (noOfSignals == 1)
        if (sendSamples.samplesI2sSignal [0].signal1 < -3)
          sendBytes = sendSamples.sampleCount * sizeof (oscI2sSample);
      else
        sendBytes = sendSamples.sampleCount * sizeof (osc1SignalSample);
      else
        sendBytes = sendSamples.sampleCount * sizeof (osc2SignalsSample);
      int sendWords = sendBytes >> 1;                                 

      if (clientIsBigEndian) {
        uint16_t *w = (uint16_t *) &sendSamples;
        for (size_t i = 0; i < sendWords; i ++) w [i] = htons (w [i]);
      }
      
		  /** 一直发送二进制数据，如果遇到错误如连接断开，就会退出循环 */  
      if (!webSocket->sendBinary ((byte *) &sendSamples,  sendBytes)) return;
    }

    if (webSocket->available () != WebSocket::NOT_AVAILABLE) return; // this also covers ERROR and TIME_OUT
    if (webSocket->getSocket () == -1) return; // if the socket has been closed by oscReader
  }
}
```

从上面代码可以看到，只要 Arduino 收到了 `Websocket`，响应函数 `runOscilloscope` 就会调用 `oscSender` 一直循环，向网页发送数据。其中，发送的数据来自于 `&((oscSharedMemory *) sharedMemory)->sendBuffer;` ，同时发送条件为 `sendBuffer->samplesAreReady`。

那么 `sendBuffer` 中的数据又是在哪里读取的呢？根据搜索， `sendBuffer` 只会在三个函数内进行修改：

```cpp
void oscReader_digital (void *sharedMemory);
void oscReader_millis (void *sharedMemory);
void oscReader_analog (void *sharedMemory);

void runOscilloscope (WebSocket *webSocket) {
	...

  /** 函数指针，用来选择具体的读取函数 */
  void (*oscReader) (void *sharedMemory);
  if (strcmp (sharedMemory.readType, "analog")) {
    oscReader = oscReader_digital;
  } else {
    oscReader = oscReader_analog;
    #ifdef USE_I2S_INTERFACE
    if (sharedMemory.gpio2 > 39)
      oscReader = oscReader_analog_1_signal_i2s;
    #endif
  }
  if (!strcmp (sharedMemory.samplingTimeUnit, "ms")) {
    oscReader = oscReader_millis; 
  }

  sharedMemory.oscReaderState = INITIAL;

  /** RTOS 创建任务 */
  #ifdef OSCILLOSCOPE_READER_CORE
  BaseType_t taskCreated = xTaskCreatePinnedToCore (oscReader, "oscReader", 4 * 1024, (void *) &sharedMemory, OSCILLOSCOPE_READER_PRIORITY, NULL, OSCILLOSCOPE_READER_CORE);
  #else
  BaseType_t taskCreated = xTaskCreate (oscReader, "oscReader", 4 * 1024, (void *) &sharedMemory, OSCILLOSCOPE_READER_PRIORITY, NULL);
  #endif
  
  /** RTOS 任务创建完毕后，由"主进程"发送开始指令启动任务。 */
  if (pdPASS != taskCreated) {
    ...
  } else {
    sharedMemory.oscReaderState = START;
    while (sharedMemory.oscReaderState == START) delay (1);

    oscSender ((void *) &sharedMemory);
    sharedMemory.oscReaderState = STOP;
    while (sharedMemory.oscReaderState != STOPPED) delay (1);
  }

  return;
}
```

RTOS [`xTaskCreate`](https://www.freertos.org/a00125.html) 函数原型如下：

```cpp
typedef void (* TaskFunction_t)( void * );

static inline IRAM_ATTR BaseType_t xTaskCreate(
  TaskFunction_t pvTaskCode, 					// 具体任务函数，只有一个入参
  const char * const pcName,					// 进程名称
  const uint32_t usStackDepth,				// 栈空间
  void * const pvParameters,					// 入参
  UBaseType_t uxPriority,							// 优先级
  TaskHandle_t * const pxCreatedTask  // 任务句柄（handler）
)； åå
```

简单一点，我们只关心 `oscReader_digital` 函数实现，有很多都可以省略，我们只看最基础的部分：

```cpp
void oscReader_digital (void *sharedMemory) {
	
  // 主任务会发启动信号，此任务接收到信号后，向主任务发送 STARTED 信号。
  while (((oscSharedMemory *) sharedMemory)->oscReaderState != START) delay (1);
  ((oscSharedMemory *) sharedMemory)->oscReaderState = STARTED;
  
  ...
  while (((oscSharedMemory *) sharedMemory)->oscReaderState == STARTED) {
    unsigned long screenTime = 0;
    unsigned long deltaTime = 0;
    unsigned long lastSampleMicroseconds = micros ();
    unsigned long newSampleMicroseconds = lastSampleMicroseconds;

    // 特殊处理：这里设置了虚假的数据，用来告诉浏览器有几个数据、从何处刷新
    if (noOfSignals == 1) readBuffer->samples1Signal [0] = {-2, -2};
    else                  readBuffer->samples2Signals [0] = {-3, -3, -3};
    readBuffer->sampleCount = 1;

    ...
    // 开始读取数据
    while (((oscSharedMemory *) sharedMemory)->oscReaderState == STARTED) {
      // 满负载处理：当数据正好可以填充满所有数据时，直接记录所有数据，然后让主进程发送。不然会出现一些比较奇怪的显示问题
      if (screenTime >= screenWidthTime || 
          (noOfSignals == 1 && readBuffer->sampleCount >= OSCILLOSCOPE_1SIGNAL_BUFFER_SIZE) || 
          (noOfSignals == 2 && readBuffer->sampleCount >= OSCILLOSCOPE_2SIGNALS_BUFFER_SIZE)) {
				// 等待主任务（发送任务）发送数据。
        // samplesAreReady 再重新设置为 true
        if (!sendBuffer->samplesAreReady)
          *sendBuffer = *readBuffer; 
        break; 
      }

      // 区分数据，读取并设置
      union {
        osc1SignalSample new1SignalSample;
        osc2SignalsSample new2SignalsSample;
      };

      if (noOfSignals == 1) { new1SignalSample = {(int16_t) digitalRead (gpio1), (int16_t) deltaTime};
                             readBuffer->samples1Signal [readBuffer->sampleCount ++] = new1SignalSample;
                            } else                { new2SignalsSample = {(int16_t) digitalRead (gpio1), (int16_t) digitalRead (gpio2), (int16_t) deltaTime};
                                                   readBuffer->samples2Signals [readBuffer->sampleCount ++] = new2SignalsSample;
                                                  }

      screenTime += deltaTime;

      delayMicrosecondsUntil (&newSampleMicroseconds, samplingTime);
      deltaTime = newSampleMicroseconds - lastSampleMicroseconds;
      lastSampleMicroseconds = newSampleMicroseconds;

    }

    vTaskDelayUntil (&lastScreenRefreshTicks, pdMS_TO_TICKS (screenRefreshMilliseconds));

  } // while sampling

  // wait for the STOP signal
  while (((oscSharedMemory *) sharedMemory)->oscReaderState != STOP) delay (1);
  ((oscSharedMemory *) sharedMemory)->oscReaderState = STOPPED;

  vTaskDelete (NULL);
}
```

这个代码有个地方容易忽略，就是 `*sendBuffer = *readBuffer; ` `sendBuffer` 内的 `samplesAreReady` 也会被设置为 `true`。

除此之外，代码还是很清晰的。定时刷新，并且记录数据。可以看一下单通道、双通道的数据结构：

```cpp
struct osc1SignalSample {                        // one sample
  int16_t signal1;                       // signal value of 1st GPIO read by analogRead or digialRead
  int16_t deltaTime;                     // sample time - offset from previous sample in ms or us
}; // = 4 bytes per sample

struct osc2SignalsSample {                        // one sample
  int16_t signal1;                       // signal value of 1st GPIO read by analogRead or digialRead
  int16_t signal2;                       // signal value of 2nd GPIO if requested
  int16_t deltaTime;                     // sample time - offset from previous sample in ms or us
}; // = 6 bytes per sample
```

还有一点要注意的是，除了 `oscReader_millis` 以外，都是满了才发的。



## 绘制示波器

```js
for (var ind = startInd; ind <= endInd; ind += wordsPerSample) {
  // 明确有多少通道；重新设置时间戳
  if (myInt16Array [ind] < 0) {
    switch (myInt16Array [ind]) {
      case -2:  wordsPerSample = 2;
        continuousSamplingTime = 0;
        break;
      case -3:  wordsPerSample = 3;
        continuousSamplingTime = 0;
        break;
      default:
        wordsPerSample = 1;
        continuousSamplingTime = -myInt16Array [ind];
        screenTimeOffset = -continuousSamplingTime;
    }

    // 重绘页面
    drawSignal (myInt16Array, startInd, ind - wordsPerSample);
    drawBackgroundAndCalculateParameters ();
    drawSignal (myInt16Array, ind + wordsPerSample, endInd);
    return;
  }
}
```

示波器不允许有负值，所以有负值的话，只能是特殊处理。

```js
for (var ind = startInd; ind <= endInd; ind += wordsPerSample) {
  // 计算采样点横轴位置
  if (continuousSamplingTime == 0) {
    screenTimeOffset += myInt16Array [ind + wordsPerSample - 1];
  } else {
    screenTimeOffset += continuousSamplingTime;
  }

  i = xOffset + xScale * screenTimeOffset;
  j1 = yOffset + yScale * myInt16Array [ind];
  j2 = wordsPerSample >= 3 ? yOffset + yScale * myInt16Array [ind + 1] : -1;

  // 绘制具体的线
  if (lines) {
    if (restartDrawingSignal) {
      restartDrawingSignal = false;
    } else {
      if (analog) { // analog
        ...
      } else { // digital
        // signal 2
        if (j2 >= 0) {
          ctx.strokeStyle = '#ff8000';
          ctx.beginPath ();
          ctx.moveTo (lastI, lastJ2);
          ctx.lineTo (i, lastJ2);
          ctx.lineTo (i, j2);
          ctx.stroke ();
        }
        // signal 1
        ctx.strokeStyle = '#ffbf80';
        ctx.beginPath ();
        ctx.moveTo (lastI, lastJ1);
        ctx.lineTo (i, lastJ1);
        ctx.lineTo (i, j1);
        ctx.stroke ();
      }
    }
  }
  
  ...
}
```



## 总评

肉眼可见，工程量规模扩大，像 Arduino 这样的单文件工程就有点力不从心了。

代码中第一个门槛其实是  `*sendBuffer = *readBuffer; `  这边的隐参数赋值。另外还是大量的代码没能很好的封装复用。

不过作为一个开源项目，这个工程确实也有很多值得学习的地方，示波器的一般实现方式，画布的绘制等。而且还有很多内容都没有细看，包括 NTP 时间服务器功能，FileSystem 文件系统，FTP 服务器实现等，好像还能通过 telnet 直接作为 Shell 访问。总之，此项目作为开源项目，还是非常值得学习的。