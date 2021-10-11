_[官方文档](https://www.arduino.cc/reference/en/language/functions/communication/serial/)_

# 串口通讯

## 串口初始化

```C++
void setup()
{
  Serial.begin(9600);
}
```

## 串口输入

```c
void loop()
{
  int byte = Serial.read();
  String str = Serial.readString();
}
```
