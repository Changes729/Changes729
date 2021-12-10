## 变量与数据类型

根据[Arduino Reference](https://www.arduino.cc/reference/en/)，Arduino具有一些常量、强制转换器（Conversion）、类型变量、变量修饰符以及工具函数。

需要注意的是，Arduino是32位机，所以`int`是两个字节。`byte`等于无符号字节，`char`是有符号字节。arduino里，`bool`和`boolean`都可以。

注意几个常量：`HIGH`、`LOW`；`INPUT`、`OUTPUT`、`INPUT_PULLUP`。注意，使用`digital_write()`在`INPUT`时会变为启用上拉或关闭上拉电阻模式。

## 程序结构控制（略）

## 函数（略）

## 库的使用

- EEPROM - `<EEPROM.h>` - reading and writing to "permanent" storage
- Ethernet - `<Ethernet.h>` - for connecting to the internet using the Arduino Ethernet Shield, Arduino Ethernet - - Shield 2 and Arduino Leonardo ETH
- Firmata - `<Firmata.h>` - for communicating with applications on the computer using a standard serial protocol.
- GSM - `<GSM.h>` - for connecting to a GSM/GRPS network with the GSM shield.
- LiquidCrystal - `<LiquidCrystal.h>` - for controlling liquid crystal displays (LCDs)
- SD - `<SD.h>` - for reading and writing SD cards
- Servo - `<Servo.h>` for controlling servo motors
- SPI - `<SPI.h>` for communicating with devices using the Serial Peripheral Interface (SPI) Bus
- SoftwareSerial - `<SoftwareSerial.h>` - for serial communication on any digital pins. Version 1.0 and later of Arduino - incorporate Mikal Hart's NewSoftSerial library as SoftwareSerial.
- Stepper - `<Stepper.h>` - for controlling stepper motors
- TFT - `<TFT.h>` - for drawing text , images, and shapes on the Arduino TFT screen
- WiFi - `<WiFi.h>` - for connecting to the internet using the Arduino WiFi shield
- Wire - `<Wire.h>` - Two Wire Interface (TWI/I2C) for sending and receiving data over a net of devices or sensors.

## 电流（略）

## 常用电子元器件

**Arduino配套元器件**

- 电阻(Registors)
- 排插(Male Pins Strips)
- 二极管(Diodes)
- 电容(Capacitors)
- 功率放大器、三极管
- [光耦合器(optocoupler)](https://www.arduino.cc/documents/datasheets/Optocouplers.pdf?_gl=1*16pf0b1*_ga*MTk2MTE1MTE3NS4xNjM1OTk0ODQ5*_ga_SELSHHP7SG*MTYzNTk5NzE3Ni4xLjEuMTYzNTk5NzI4My4w)
- H桥电机驱动芯片
- 小伺服电机（小舵机）(Servo)
- 直流电机(Motor)
- LED
- 数码管
- [倾斜开关(Lift Sensor)](https://www.arduino.cc/documents/datasheets/TiltSensor.PDF?_gl=1*1myz3wa*_ga*MTk2MTE1MTE3NS4xNjM1OTk0ODQ5*_ga_SELSHHP7SG*MTYzNTk5NzE3Ni4xLjEuMTYzNTk5NzI4My4w)
- 温度传感器
- 轻触开关
- 光敏电阻
- 可变电阻

**书中提及的传感器**
- 动作传感器，被动红外（PIR）传感器

**其他元器件**
- 蓝牙
- 编码器
- 触摸屏

## 示意图和电路图（略）

## 万用表（略）

## 面包板

注意面包板的导通方向，其余略。

## 串口通信

```cpp
#include <Serial.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.read();
    Serial.write("xxx");
}
```

```cpp
// Returns true if the specified serial port is available. This will only return false if querying the Leonardo’s USB CDC serial connection before it is ready. 
if(Serial)

begin()
end()

available() // ForRead()
availableForWrite()

// Waits for the transmission of outgoing serial data to complete. 
flush()

parseFloat()
parseInt()

// Returns the next byte (character) of incoming serial data without removing it from the internal serial buffer. That is, successive calls to peek() will return the same character, as will the next call to read().
peek()

print()
println()
write()

/** 
 * @find: reads data from the serial buffer until the target is found. 
 *        The function returns true if target is found, false if it times out.
 * @findUntial: reads data from the serial buffer until a target string of given length or terminator string is found.
 * The function returns true if the target string is found, false if it times out.
 */
find()
findUntil()
read()
readBytes()
readBytesUntil()
readString()
readStringUntil()

setTimeout()

serialEvent()

```

软串口的使用除了需要定义TX、RX以外，使用方式与Serial一致。

## 简单数字和模拟输入

```cpp
// Digital I/O
// 需要pinMode设置类型
digitalRead() 
digitalWrite() 
pinMode() 

// Analog I/O
// 不需要设置引脚类型
analogRead() 
analogReference() // https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/
// 需要设置为 OUTPUT
analogWrite() 

// Zero, Due & MKR Family
analogReadResolution() 
analogWriteResolution() 
```

回顾：
- 如何不使用外部电阻实现按键检测？- `digitalWrite(pin, HIGH)`;
- 软件消抖逻辑？ - 读到按下后，延迟1ms，继续检测。
- 按键按下计时？ - millis()记录开机时间。毫秒，unsigned long
- 模拟值数值映射？ - map()
- 如何读取超过6路的模拟输入？ - 数字选择器多路复用
- 如何测量超过5v的电压？ - 电路分压

## 获取传感器输入

- 如何检测动作？- 倾斜传感器（开关）
- 如何检测光？- 光敏电阻LDR
- 什么是被动红外探测器？
    - PIR能做到哪些功能？
- 如何测距？ - 超声波传感器
    - 如何计算距离？ - `microseconds * 340 / 1000 / 2`
- 红外传感器精确测量距离如何实现？
- 压电传感器有什么用？- 本质上根据微弱的压电元器件形变产生电压，这就是压电效应，后来可以用来检测传感器是否受到震动。
- 声音检测 - 驻极体话筒
- 温度测量 - 温度传感器（温度与电压成正比）
- RFID标签 - 协议，起始位、终止位、10位标签。
- 旋转动作检测 - 编码器

**中断与编码器**
```cpp
// FALLING, RISING, CHANGE
attachInterrupt(Interrupt0, doEncoder, FALLING);
```

## 可视输出、物理输出、声音输出

**可视输出**
- LED灯（略）
- PWM，注意使用analogWrite，其余略
- Charlieplexing控制灯法
- 数码管控制

**物理输出**
- 舵机与占空比
- H桥控制电路
- 双极步进电机`Stepper.h`
```cpp
Stepper stepper(STEPS, 2, 3, 4, 5);

void setup()
{
    // 设置电机速度到30RPM
    stepper.setSpeed(30);
}

void loop()
{
    stepper.step(steps);
}
```

**音频播放**

- 蜂鸣器模拟音调
- WAV播放（X）
- MIDI播放（X）

## 无线通讯和网络

```cpp
#include <VirtualWire.h>

void setup()
{
    vw_setup(2000);
    // vw_rx_start(); // 开始接受
}

void loop()
{
    // if(vw_get_message(message_buffer, &msg_size))
    vw_send(const char* msg, size_t size);
    vw_wait_tx();
}
```

- ZIGBEE（mesh network）
- XBEE
- RFM12B

```cpp
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {};
byte ip[] = {};
byte server[] = {};
```

