> 代码来源：[ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
>
> 参考资料：
>
> - [The WebSocket API (WebSockets)](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API)
> - [Server-sent events](https://developer.mozilla.org/en-US/docs/Web/API/Server-sent_events)

# ESP Async Web Server 实现扫描

## 工程框架

```sh
ESPAsyncTCP/
|-- ESPAsyncTCP.h 
		|-- class AsyncServer  	# 负责绑定IP地址，监听客户端的TCP连接
		|-- class AsyncClient		# 由 AsyncServer 创建; 核心数据结构是 `tcp_pcb`

ESPAsyncWebServer/
|-- ESPAsyncWebServer.h       				# 头文件
		|-- class AsyncWebServer  				# 包含一个 AsyncServer 和 AsyncCallbackWebHandler
		|-- class AsyncWebHandler					# Web接口处理模版
				|-- class AsyncCallbackWebHandler # 用于处理 请求、上传等
				|-- class AsyncWebSocket			
		|-- class AsyncWebServerRequest		# 只要有客户端连接，就会由 AsyncWebServer 创建一个请求
		|-- class AsyncWebServerResponse
		|-- class AsyncWebHandler 
		
|-- WebRequest.cpp					  # WebServer TCP 请求单元，用于接收数据，并上发请求
|-- AsyncWebSocket.h
		|-- class AsyncWebSocketClient
|-- AsyncEventSource.h
		|-- class AsyncEventSource
```



## AsyncWebSocketBasicMessage

