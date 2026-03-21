# 距离感应设备

## 需求

- 300平米（20*20米），距离检测
- 亮灯
- 两队，2*5的人次。



## 初次技术调研

四种技术：BLE（Coded PHY）（RSSI）、LoRa（RSSI）、UWB（TOF）、Openthread（RSSI）

### BLE Coded PHY

> 相关资料：
>
> **nRF52840**：**最推荐**。旗舰级芯片，完美支持 Coded PHY。内置功率放大器（PA），最大发射功率 +8 dBm，配合长距离模式可轻松突破 300 米。
>
> **nRF52833**：工业级精简版，支持 Coded PHY 和 AoA/AoD 定位，性价比高。
>
> **nRF5340**：高性能双核芯片，适合需要处理复杂算法（如卡尔曼滤波）的测距场景。
>
> **nRF52811 / nRF52820**：入门级，也支持长距离模式，适合做简单的传感器节点。
>
> - [CODED_PHY function to extend the range of my project and develop in Arduino](https://forum.seeedstudio.com/t/coded-phy-function-to-extend-the-range-of-my-project-and-develop-in-arduino/273290)：有工程，但没有细看
> - [Nano 33 ble nRF52840 - BLE long range/pairing ? Mbed BLE API ? Adafruit Lib?](https://forum.arduino.cc/t/nano-33-ble-nrf52840-ble-long-range-pairing-mbed-ble-api-adafruit-lib/644684)：有直接配置的代码
> - [**Nordic测试 - 蓝牙长距离**](https://www.nordicsemi.cn/news/bluetooth-long-range/)
> - [ProMicro NRF52840开发板](https://item.taobao.com/item.htm?abbucket=13&id=979573157042&mi_id=0000SrjNCdcx8kBc0u99kJpZizhuQOSLmGXHWsOigv163hs&ns=1&priceTId=214781bb17665538651784109e1009&spm=a21n57.1.hoverItem.4&utparam=%7B%22aplus_abtest%22%3A%2263b1797a22265be375382b4614f04a67%22%7D&xxc=taobaoSearch)：16.28
>   - [Promicro NRF52840](https://item.taobao.com/item.htm?abbucket=13&id=760219799103&mi_id=0000ZlRfsJc98V_r44TJj21po7T50mKZOFBSemicpbzxv-o&ns=1&priceTId=214787c617665580915196891e1068&skuId=5412093043170&spm=a21n57.1.hoverItem.6&utparam=%7B%22aplus_abtest%22%3A%22c400ffe9f39f1167bef7c9ff528c8daf%22%7D&xxc=taobaoSearch)：11.64



### LoRa

> 相关资料：
>
> $$RSSI = A - 10n \lg(d)$$
>
> - $d$：待测距离。
> - $A$：距离 1 米时的信号强度（基准值）。
> - $n$：路径损耗指数（环境因子，空旷地带通常为 2，有障碍物可能为 3-4）。
>
>  覆盖范围广（城镇 3-5km，郊区可达 15km）
>
> - [LPWAN （低功耗广域网）](https://zh.digi.com/resources/definitions/lpwan)：说明文档
>   - [[Wiki] LPWAN](https://zh.wikipedia.org/wiki/LPWAN)
> - [思为无线：LoRa无线模块LoRa1280通讯距离测试](https://zhuanlan.zhihu.com/p/610773521)：无遮挡测距
> - [arduino-LoRa](https://github.com/sandeepmistry/arduino-LoRa)：开源项目
>   - 底层是 SX1276/77/78/79
>   - [ESP32 with LoRa using Arduino IDE – Getting Started](https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/)：Demo，使用RFM95
>   - [RFM95](https://item.taobao.com/item.htm?ali_refid=a3_430582_1006%3A1312910175%3AH%3AlWH8FFGjBaRtZj3%2BOPux1A%3D%3D%3A99e6db2c36420d9d31c089bc9b655286&ali_trackid=282_99e6db2c36420d9d31c089bc9b655286&id=583562291762&mi_id=0000FbPK_pGiz27jZAM6OInpBLo95XLVxbsBfbBgzvVBkQs&mm_sceneid=1_0_411970124_0&priceTId=213e023117665512063993868e10d7&skuId=4976073876771&spm=a21n57.1.hoverItem.1&utparam=%7B%22aplus_abtest%22%3A%22ca7ddb4dbcd22c00d576d46d28d4f438%22%7D&xxc=ad_ztc)：23~26
> - [Lora 人员定位技术的测距原理与算法研究浅析](https://blog.csdn.net/LanJingTanWei/article/details/154994789)：AOA 到达角测量
> - [安信可Ra-01（SX1278 LoRa）](https://item.taobao.com/item.htm?abbucket=13&id=582273174874&mi_id=0000sfimGOiVq5cYikazs4o3ONH2gTQ5-hiUjwuzuQc3cQo&ns=1&priceTId=214787c617665584573064192e1068&spm=a21n57.1.hoverItem.3&utparam=%7B%22aplus_abtest%22%3A%228f664bb4882bcc053a10492ee7fe6630%22%7D&xxc=taobaoSearch)：带天线，21
>   - [文档](https://docs.ai-thinker.com/Ra-01/)
> - [LORA sx1278 ra-02 and arduino uno](https://forum.arduino.cc/t/lora-sx1278-ra-02-and-arduino-uno/1347100)：有代码



```cpp
/*********
main.cpp
Modified from the examples of the Arduino LoRa library by nuttyengieer.com
for more information write to nuttyengineeronline@gmail.com or
info@nuttyengineer.com
*********/
#if 0
#include <LoRa.h>
#include <SPI.h>
#define ss 10
#define rst 8
#define dio0 2

int counter = 0;

void setup() {
  // initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("LoRa Sender Tested by SME Dehradun ");

  // setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print("Packet ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(1000);
}

#else
/*********
Modified from the examples of the Arduino LoRa library by nuttyengieer.com
for more information write to nuttyengineeronline@gmail.com or
info@nuttyengineer.com
*********/
#include <LoRa.h>
#include <SPI.h>
#define ss 10
#define rst 8
#define dio0 2

int counter = 0;

void setup() {
  // initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("LoRa Sender Tested by SME Dehradun ");

  // setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed !");
    while (1)
      ;
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK !");
  delay(3000);
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet ");
    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData);
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
#endif
```

```cpp
// LoRa.h
// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LORA_H
#define LORA_H

#include <Arduino.h>
#include <SPI.h>

#ifdef ARDUINO_SAMD_MKRWAN1300
#define LORA_DEFAULT_SPI           SPI1
#define LORA_DEFAULT_SPI_FREQUENCY 250000
#define LORA_DEFAULT_SS_PIN        LORA_IRQ_DUMB
#define LORA_DEFAULT_RESET_PIN     -1
#define LORA_DEFAULT_DIO0_PIN      -1
#else
#define LORA_DEFAULT_SPI           SPI
#define LORA_DEFAULT_SPI_FREQUENCY 8E6 
#define LORA_DEFAULT_SS_PIN        10
#define LORA_DEFAULT_RESET_PIN     9
#define LORA_DEFAULT_DIO0_PIN      2
#endif

#define PA_OUTPUT_RFO_PIN          0
#define PA_OUTPUT_PA_BOOST_PIN     1

class LoRaClass : public Stream {
public:
  LoRaClass();

  int begin(long frequency);
  void end();

  int beginPacket(int implicitHeader = false);
  int endPacket();

  int parsePacket(int size = 0);
  int packetRssi();
  float packetSnr();
  long packetFrequencyError();

  // from Print
  virtual size_t write(uint8_t byte);
  virtual size_t write(const uint8_t *buffer, size_t size);

  // from Stream
  virtual int available();
  virtual int read();
  virtual int peek();
  virtual void flush();

#ifndef ARDUINO_SAMD_MKRWAN1300
  void onReceive(void(*callback)(int));

  void receive(int size = 0);
#endif
  void idle();
  void sleep();

  void setTxPower(int level, int outputPin = PA_OUTPUT_PA_BOOST_PIN);
  void setFrequency(long frequency);
  void setSpreadingFactor(int sf);
  void setSignalBandwidth(long sbw);
  void setCodingRate4(int denominator);
  void setPreambleLength(long length);
  void setSyncWord(int sw);
  void enableCrc();
  void disableCrc();

  // deprecated
  void crc() { enableCrc(); }
  void noCrc() { disableCrc(); }

  byte random();

  void setPins(int ss = LORA_DEFAULT_SS_PIN, int reset = LORA_DEFAULT_RESET_PIN, int dio0 = LORA_DEFAULT_DIO0_PIN);
  void setSPI(SPIClass& spi);
  void setSPIFrequency(uint32_t frequency);

  void dumpRegisters(Stream& out);

private:
  void explicitHeaderMode();
  void implicitHeaderMode();

  void handleDio0Rise();

  int getSpreadingFactor();
  long getSignalBandwidth();

  void setLdoFlag();

  uint8_t readRegister(uint8_t address);
  void writeRegister(uint8_t address, uint8_t value);
  uint8_t singleTransfer(uint8_t address, uint8_t value);

  static void onDio0Rise();

private:
  SPISettings _spiSettings;
  SPIClass* _spi;
  int _ss;
  int _reset;
  int _dio0;
  long _frequency;
  int _packetIndex;
  int _implicitHeaderMode;
  void (*_onReceive)(int);
};

extern LoRaClass LoRa;

#endif

```

```cpp
// LoRa.cpp
// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <LoRa.h>

// registers
#define REG_FIFO                 0x00
#define REG_OP_MODE              0x01
#define REG_FRF_MSB              0x06
#define REG_FRF_MID              0x07
#define REG_FRF_LSB              0x08
#define REG_PA_CONFIG            0x09
#define REG_LNA                  0x0c
#define REG_FIFO_ADDR_PTR        0x0d
#define REG_FIFO_TX_BASE_ADDR    0x0e
#define REG_FIFO_RX_BASE_ADDR    0x0f
#define REG_FIFO_RX_CURRENT_ADDR 0x10
#define REG_IRQ_FLAGS            0x12
#define REG_RX_NB_BYTES          0x13
#define REG_PKT_SNR_VALUE        0x19
#define REG_PKT_RSSI_VALUE       0x1a
#define REG_MODEM_CONFIG_1       0x1d
#define REG_MODEM_CONFIG_2       0x1e
#define REG_PREAMBLE_MSB         0x20
#define REG_PREAMBLE_LSB         0x21
#define REG_PAYLOAD_LENGTH       0x22
#define REG_MODEM_CONFIG_3       0x26
#define REG_FREQ_ERROR_MSB       0x28
#define REG_FREQ_ERROR_MID       0x29
#define REG_FREQ_ERROR_LSB       0x2a
#define REG_RSSI_WIDEBAND        0x2c
#define REG_DETECTION_OPTIMIZE   0x31
#define REG_DETECTION_THRESHOLD  0x37
#define REG_SYNC_WORD            0x39
#define REG_DIO_MAPPING_1        0x40
#define REG_VERSION              0x42

// modes
#define MODE_LONG_RANGE_MODE     0x80
#define MODE_SLEEP               0x00
#define MODE_STDBY               0x01
#define MODE_TX                  0x03
#define MODE_RX_CONTINUOUS       0x05
#define MODE_RX_SINGLE           0x06

// PA config
#define PA_BOOST                 0x80

// IRQ masks
#define IRQ_TX_DONE_MASK           0x08
#define IRQ_PAYLOAD_CRC_ERROR_MASK 0x20
#define IRQ_RX_DONE_MASK           0x40

#define MAX_PKT_LENGTH           255

LoRaClass::LoRaClass() :
  _spiSettings(LORA_DEFAULT_SPI_FREQUENCY, MSBFIRST, SPI_MODE0),
  _spi(&LORA_DEFAULT_SPI),
  _ss(LORA_DEFAULT_SS_PIN), _reset(LORA_DEFAULT_RESET_PIN), _dio0(LORA_DEFAULT_DIO0_PIN),
  _frequency(0),
  _packetIndex(0),
  _implicitHeaderMode(0),
  _onReceive(NULL)
{
  // overide Stream timeout value
  setTimeout(0);
}

int LoRaClass::begin(long frequency)
{
#ifdef ARDUINO_SAMD_MKRWAN1300
  pinMode(LORA_IRQ_DUMB, OUTPUT);
  digitalWrite(LORA_IRQ_DUMB, LOW);

  // Hardware reset
  pinMode(LORA_BOOT0, OUTPUT);
  digitalWrite(LORA_BOOT0, LOW);

  pinMode(LORA_RESET, OUTPUT);
  digitalWrite(LORA_RESET, HIGH);
  delay(200);
  digitalWrite(LORA_RESET, LOW);
  delay(200);
  digitalWrite(LORA_RESET, HIGH);
  delay(50);
#endif

  // setup pins
  pinMode(_ss, OUTPUT);
  // set SS high
  digitalWrite(_ss, HIGH);

  if (_reset != -1) {
    pinMode(_reset, OUTPUT);

    // perform reset
    digitalWrite(_reset, LOW);
    delay(10);
    digitalWrite(_reset, HIGH);
    delay(10);
  }

  // start SPI
  _spi->begin();

  // check version
  uint8_t version = readRegister(REG_VERSION);
  if (version != 0x12) {
    return 0;
  }

  // put in sleep mode
  sleep();

  // set frequency
  setFrequency(frequency);

  // set base addresses
  writeRegister(REG_FIFO_TX_BASE_ADDR, 0);
  writeRegister(REG_FIFO_RX_BASE_ADDR, 0);

  // set LNA boost
  writeRegister(REG_LNA, readRegister(REG_LNA) | 0x03);

  // set auto AGC
  writeRegister(REG_MODEM_CONFIG_3, 0x04);

  // set output power to 17 dBm
  setTxPower(17);

  // put in standby mode
  idle();

  return 1;
}

void LoRaClass::end()
{
  // put in sleep mode
  sleep();

  // stop SPI
  _spi->end();
}

int LoRaClass::beginPacket(int implicitHeader)
{
  // put in standby mode
  idle();

  if (implicitHeader) {
    implicitHeaderMode();
  } else {
    explicitHeaderMode();
  }

  // reset FIFO address and paload length
  writeRegister(REG_FIFO_ADDR_PTR, 0);
  writeRegister(REG_PAYLOAD_LENGTH, 0);

  return 1;
}

int LoRaClass::endPacket()
{
  // put in TX mode
  writeRegister(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_TX);

  // wait for TX done
  while ((readRegister(REG_IRQ_FLAGS) & IRQ_TX_DONE_MASK) == 0) {
    yield();
  }

  // clear IRQ's
  writeRegister(REG_IRQ_FLAGS, IRQ_TX_DONE_MASK);

  return 1;
}

int LoRaClass::parsePacket(int size)
{
  int packetLength = 0;
  int irqFlags = readRegister(REG_IRQ_FLAGS);

  if (size > 0) {
    implicitHeaderMode();

    writeRegister(REG_PAYLOAD_LENGTH, size & 0xff);
  } else {
    explicitHeaderMode();
  }

  // clear IRQ's
  writeRegister(REG_IRQ_FLAGS, irqFlags);

  if ((irqFlags & IRQ_RX_DONE_MASK) && (irqFlags & IRQ_PAYLOAD_CRC_ERROR_MASK) == 0) {
    // received a packet
    _packetIndex = 0;

    // read packet length
    if (_implicitHeaderMode) {
      packetLength = readRegister(REG_PAYLOAD_LENGTH);
    } else {
      packetLength = readRegister(REG_RX_NB_BYTES);
    }

    // set FIFO address to current RX address
    writeRegister(REG_FIFO_ADDR_PTR, readRegister(REG_FIFO_RX_CURRENT_ADDR));

    // put in standby mode
    idle();
  } else if (readRegister(REG_OP_MODE) != (MODE_LONG_RANGE_MODE | MODE_RX_SINGLE)) {
    // not currently in RX mode

    // reset FIFO address
    writeRegister(REG_FIFO_ADDR_PTR, 0);

    // put in single RX mode
    writeRegister(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_RX_SINGLE);
  }

  return packetLength;
}

int LoRaClass::packetRssi()
{
  return (readRegister(REG_PKT_RSSI_VALUE) - (_frequency < 868E6 ? 164 : 157));
}

float LoRaClass::packetSnr()
{
  return ((int8_t)readRegister(REG_PKT_SNR_VALUE)) * 0.25;
}

long LoRaClass::packetFrequencyError()
{
  int32_t freqError = 0;
  freqError = static_cast<int32_t>(readRegister(REG_FREQ_ERROR_MSB) & B111);
  freqError <<= 8L;
  freqError += static_cast<int32_t>(readRegister(REG_FREQ_ERROR_MID));
  freqError <<= 8L;
  freqError += static_cast<int32_t>(readRegister(REG_FREQ_ERROR_LSB));

  if (readRegister(REG_FREQ_ERROR_MSB) & B1000) { // Sign bit is on
     freqError -= 524288; // B1000'0000'0000'0000'0000
  }

  const float fXtal = 32E6; // FXOSC: crystal oscillator (XTAL) frequency (2.5. Chip Specification, p. 14)
  const float fError = ((static_cast<float>(freqError) * (1L << 24)) / fXtal) * (getSignalBandwidth() / 500000.0f); // p. 37

  return static_cast<long>(fError);
}

size_t LoRaClass::write(uint8_t byte)
{
  return write(&byte, sizeof(byte));
}

size_t LoRaClass::write(const uint8_t *buffer, size_t size)
{
  int currentLength = readRegister(REG_PAYLOAD_LENGTH);

  // check size
  if ((currentLength + size) > MAX_PKT_LENGTH) {
    size = MAX_PKT_LENGTH - currentLength;
  }

  // write data
  for (size_t i = 0; i < size; i++) {
    writeRegister(REG_FIFO, buffer[i]);
  }

  // update length
  writeRegister(REG_PAYLOAD_LENGTH, currentLength + size);

  return size;
}

int LoRaClass::available()
{
  return (readRegister(REG_RX_NB_BYTES) - _packetIndex);
}

int LoRaClass::read()
{
  if (!available()) {
    return -1;
  }

  _packetIndex++;

  return readRegister(REG_FIFO);
}

int LoRaClass::peek()
{
  if (!available()) {
    return -1;
  }

  // store current FIFO address
  int currentAddress = readRegister(REG_FIFO_ADDR_PTR);

  // read
  uint8_t b = readRegister(REG_FIFO);

  // restore FIFO address
  writeRegister(REG_FIFO_ADDR_PTR, currentAddress);

  return b;
}

void LoRaClass::flush()
{
}

#ifndef ARDUINO_SAMD_MKRWAN1300
void LoRaClass::onReceive(void(*callback)(int))
{
  _onReceive = callback;

  if (callback) {
    pinMode(_dio0, INPUT);

    writeRegister(REG_DIO_MAPPING_1, 0x00);
#ifdef SPI_HAS_NOTUSINGINTERRUPT
    SPI.usingInterrupt(digitalPinToInterrupt(_dio0));
#endif
    attachInterrupt(digitalPinToInterrupt(_dio0), LoRaClass::onDio0Rise, RISING);
  } else {
    detachInterrupt(digitalPinToInterrupt(_dio0));
#ifdef SPI_HAS_NOTUSINGINTERRUPT
    SPI.notUsingInterrupt(digitalPinToInterrupt(_dio0));
#endif
  }
}

void LoRaClass::receive(int size)
{
  if (size > 0) {
    implicitHeaderMode();

    writeRegister(REG_PAYLOAD_LENGTH, size & 0xff);
  } else {
    explicitHeaderMode();
  }

  writeRegister(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_RX_CONTINUOUS);
}
#endif

void LoRaClass::idle()
{
  writeRegister(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_STDBY);
}

void LoRaClass::sleep()
{
  writeRegister(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_SLEEP);
}

void LoRaClass::setTxPower(int level, int outputPin)
{
  if (PA_OUTPUT_RFO_PIN == outputPin) {
    // RFO
    if (level < 0) {
      level = 0;
    } else if (level > 14) {
      level = 14;
    }

    writeRegister(REG_PA_CONFIG, 0x70 | level);
  } else {
    // PA BOOST
    if (level < 2) {
      level = 2;
    } else if (level > 17) {
      level = 17;
    }

    writeRegister(REG_PA_CONFIG, PA_BOOST | (level - 2));
  }
}

void LoRaClass::setFrequency(long frequency)
{
  _frequency = frequency;

  uint64_t frf = ((uint64_t)frequency << 19) / 32000000;

  writeRegister(REG_FRF_MSB, (uint8_t)(frf >> 16));
  writeRegister(REG_FRF_MID, (uint8_t)(frf >> 8));
  writeRegister(REG_FRF_LSB, (uint8_t)(frf >> 0));
}

int LoRaClass::getSpreadingFactor()
{
  return readRegister(REG_MODEM_CONFIG_2) >> 4;
}

void LoRaClass::setSpreadingFactor(int sf)
{
  if (sf < 6) {
    sf = 6;
  } else if (sf > 12) {
    sf = 12;
  }

  if (sf == 6) {
    writeRegister(REG_DETECTION_OPTIMIZE, 0xc5);
    writeRegister(REG_DETECTION_THRESHOLD, 0x0c);
  } else {
    writeRegister(REG_DETECTION_OPTIMIZE, 0xc3);
    writeRegister(REG_DETECTION_THRESHOLD, 0x0a);
  }

  writeRegister(REG_MODEM_CONFIG_2, (readRegister(REG_MODEM_CONFIG_2) & 0x0f) | ((sf << 4) & 0xf0));
  setLdoFlag();
}

long LoRaClass::getSignalBandwidth()
{
  byte bw = (readRegister(REG_MODEM_CONFIG_1) >> 4);
  switch (bw) {
    case 0: return 7.8E3;
    case 1: return 10.4E3;
    case 2: return 15.6E3;
    case 3: return 20.8E3;
    case 4: return 31.25E3;
    case 5: return 41.7E3;
    case 6: return 62.5E3;
    case 7: return 125E3;
    case 8: return 250E3;
    case 9: return 500E3;
  }

  return -1;
}

void LoRaClass::setSignalBandwidth(long sbw)
{
  int bw;

  if (sbw <= 7.8E3) {
    bw = 0;
  } else if (sbw <= 10.4E3) {
    bw = 1;
  } else if (sbw <= 15.6E3) {
    bw = 2;
  } else if (sbw <= 20.8E3) {
    bw = 3;
  } else if (sbw <= 31.25E3) {
    bw = 4;
  } else if (sbw <= 41.7E3) {
    bw = 5;
  } else if (sbw <= 62.5E3) {
    bw = 6;
  } else if (sbw <= 125E3) {
    bw = 7;
  } else if (sbw <= 250E3) {
    bw = 8;
  } else /*if (sbw <= 250E3)*/ {
    bw = 9;
  }

  writeRegister(REG_MODEM_CONFIG_1, (readRegister(REG_MODEM_CONFIG_1) & 0x0f) | (bw << 4));
  setLdoFlag();
}

void LoRaClass::setLdoFlag()
{
  // Section 4.1.1.5
  long symbolDuration = 1000 / ( getSignalBandwidth() / (1L << getSpreadingFactor()) ) ;

  // Section 4.1.1.6
  boolean ldoOn = symbolDuration > 16;

  uint8_t config3 = readRegister(REG_MODEM_CONFIG_3);
  bitWrite(config3, 3, ldoOn);
  writeRegister(REG_MODEM_CONFIG_3, config3);
}

void LoRaClass::setCodingRate4(int denominator)
{
  if (denominator < 5) {
    denominator = 5;
  } else if (denominator > 8) {
    denominator = 8;
  }

  int cr = denominator - 4;

  writeRegister(REG_MODEM_CONFIG_1, (readRegister(REG_MODEM_CONFIG_1) & 0xf1) | (cr << 1));
}

void LoRaClass::setPreambleLength(long length)
{
  writeRegister(REG_PREAMBLE_MSB, (uint8_t)(length >> 8));
  writeRegister(REG_PREAMBLE_LSB, (uint8_t)(length >> 0));
}

void LoRaClass::setSyncWord(int sw)
{
  writeRegister(REG_SYNC_WORD, sw);
}

void LoRaClass::enableCrc()
{
  writeRegister(REG_MODEM_CONFIG_2, readRegister(REG_MODEM_CONFIG_2) | 0x04);
}

void LoRaClass::disableCrc()
{
  writeRegister(REG_MODEM_CONFIG_2, readRegister(REG_MODEM_CONFIG_2) & 0xfb);
}

byte LoRaClass::random()
{
  return readRegister(REG_RSSI_WIDEBAND);
}

void LoRaClass::setPins(int ss, int reset, int dio0)
{
  _ss = ss;
  _reset = reset;
  _dio0 = dio0;
}

void LoRaClass::setSPI(SPIClass& spi)
{
  _spi = &spi;
}

void LoRaClass::setSPIFrequency(uint32_t frequency)
{
  _spiSettings = SPISettings(frequency, MSBFIRST, SPI_MODE0);
}

void LoRaClass::dumpRegisters(Stream& out)
{
  for (int i = 0; i < 128; i++) {
    out.print("0x");
    out.print(i, HEX);
    out.print(": 0x");
    out.println(readRegister(i), HEX);
  }
}

void LoRaClass::explicitHeaderMode()
{
  _implicitHeaderMode = 0;

  writeRegister(REG_MODEM_CONFIG_1, readRegister(REG_MODEM_CONFIG_1) & 0xfe);
}

void LoRaClass::implicitHeaderMode()
{
  _implicitHeaderMode = 1;

  writeRegister(REG_MODEM_CONFIG_1, readRegister(REG_MODEM_CONFIG_1) | 0x01);
}

void LoRaClass::handleDio0Rise()
{
  int irqFlags = readRegister(REG_IRQ_FLAGS);

  // clear IRQ's
  writeRegister(REG_IRQ_FLAGS, irqFlags);

  if ((irqFlags & IRQ_PAYLOAD_CRC_ERROR_MASK) == 0) {
    // received a packet
    _packetIndex = 0;

    // read packet length
    int packetLength = _implicitHeaderMode ? readRegister(REG_PAYLOAD_LENGTH) : readRegister(REG_RX_NB_BYTES);

    // set FIFO address to current RX address
    writeRegister(REG_FIFO_ADDR_PTR, readRegister(REG_FIFO_RX_CURRENT_ADDR));

    if (_onReceive) {
      _onReceive(packetLength);
    }

    // reset FIFO address
    writeRegister(REG_FIFO_ADDR_PTR, 0);
  }
}

uint8_t LoRaClass::readRegister(uint8_t address)
{
  return singleTransfer(address & 0x7f, 0x00);
//  return singleTransfer(address & 0x7f, 0xEF);
}

void LoRaClass::writeRegister(uint8_t address, uint8_t value)
{
  singleTransfer(address | 0x80, value);
}

uint8_t LoRaClass::singleTransfer(uint8_t address, uint8_t value)
{
  uint8_t response;

  digitalWrite(_ss, LOW);

  _spi->beginTransaction(_spiSettings);
  _spi->transfer(address);
  response = _spi->transfer(value);
  _spi->endTransaction();

  digitalWrite(_ss, HIGH);

  return response;
}

void LoRaClass::onDio0Rise()
{
  LoRa.handleDio0Rise();
}

LoRaClass LoRa;

```





### UWB

> 相关资料：
>
> - [fw-SmartTag](https://github.com/uqomm/fw-SmartTag)：开源工程，用 DW3000 做测距
> - [arduino-dw1000](https://github.com/thotro/arduino-dw1000)：开源代码，好久没有维护了。
> - [安信可模组](https://docs.ai-thinker.com/uwb_1/)：不好用，开发板也是二次开发的，AT指令定好了。除非了解其本身的 DW1000/DW3000 的开发，才能去修改，那还不如直接买 DW1000/DW3000 模块
>   - [测距说明文档](https://fcniufr8ibx1.feishu.cn/wiki/KAq4wXtmTijSv3kPiVOcwxLTnOg)：如何在他们的框架下二次开发，可不看。
> - [QORVO ULTRA-WIDEBAND](https://www.qorvo.com/products/wireless-connectivity/ultra-wideband#ta0116;;;)：官方网站
>   - [DW1000-I-TR13](https://item.taobao.com/item.htm?abbucket=13&id=862575736624&mi_id=00005E6byz_60W96ail3dZuqS5ghnm-q9uBHCY-ZKwNUJaI&ns=1&priceTId=213e09ee17664948689826427e1016&skuId=5680683304109&spm=a21n57.1.hoverItem.14&utparam=%7B%22aplus_abtest%22%3A%22daf6942d9d15f73f21ac82b72032e94a%22%7D&xxc=taobaoSearch)：17.5（芯片）
>   - [DUM1000](https://www.qorvo.com/products/p/DWM1000#documents)：模组的官方文档集合
>     - [Application Notes](https://www.qorvo.com/innovation/ultra-wideband/resources/application-notes)
>
> - [研创物联产品树](https://www.ychiot.com/shop00/?n=n1#High-power)
>   - [研创物联 DWM1000 数据手册 V1.2](https://www.ychiot.com/static/dataSheet/1-UWB%E6%A8%A1%E7%BB%84/CN/cn_UM03_DWM1000%E6%95%B0%E6%8D%AE%E6%89%8B%E5%86%8C_V1.2.pdf)：这个手册写的不错的。
>   - [DWM1000模块](https://item.taobao.com/item.htm?id=535565757547&mi_id=0000sFK9dTGvRceP4z2SGGzGIcLmS61YsCqfxyFs_d_ucCs&skuId=4398406167878&spm=a21xtw.29978518.0.0)：30米，94.5，这家模块有送工程代码。
>   - [开发板](https://item.taobao.com/item.htm?abbucket=13&id=534733415332&mi_id=0000xbTQT7WARgNGv9S2L_sj83nCEkVkI_ygX5CrvMk0TFM&ns=1&priceTId=2100c82c17665612769622724e08e9&skuId=4747748027973&spm=a21n57.1.hoverItem.7&utparam=%7B%22aplus_abtest%22%3A%222a628a39dd0cc2474cb413b890505a0f%22%7D&xxc=taobaoSearch)：262.5
> - [思为无线 UWB3000F00-X1](https://www.nicerf.cn/product/show/id/uwb3000f00-x)
>   - [淘宝](https://item.taobao.com/item.htm?abbucket=13&id=974324602951&mi_id=0000mcBIALEpTLfIOJZl_C_qjobqVAVa42rbRps32bSbpmI&ns=1&priceTId=215048e717665445868506752e0f79&skuId=5926889596715&spm=a21n57.1.hoverItem.1&utparam=%7B%22aplus_abtest%22%3A%227870d39ad99acb2c78a3d4f6feb7fea3%22%7D&xxc=taobaoSearch)：108：这家也说有送工程代码，不过卖的要贵。而且外置天线



### Openthread

> 相关资料:
>
> - [ESP32-H2](https://item.taobao.com/item.htm?abbucket=13&id=845037287438&mi_id=0000hy0T--LX8jBiLecWrpR4GGTS0KibenjQb-qlyTsPSvM&ns=1&priceTId=2147808117665533432657793e11b1&skuId=5791928038535&spm=a21n57.1.hoverItem.2&utparam=%7B%22aplus_abtest%22%3A%227049d477b29f43fc44a598f69c8d35e8%22%7D&xxc=taobaoSearch):16.9
> - [ESP32-H2](https://item.taobao.com/item.htm?abbucket=13&id=988989854868&mi_id=0000YzMTw5tk7J0kOYWnnr7op3uWh6qOiMas1UJElyl33JE&ns=1&priceTId=2150417e17665490067122330e1939&skuId=6122270451086&spm=a21n57.1.hoverItem.1&utparam=%7B%22aplus_abtest%22%3A%22be2ff7dfb2b0c77a19847d3df46d15a0%22%7D&xxc=taobaoSearch): 20.02
>   - [otPlatRadioGetRssi](https://github.com/espressif/esp-idf/blob/1e87d43f1ae1e582771cc0df2f7dffb60a0186fc/components/openthread/src/port/esp_openthread_radio_spinel.cpp#L286)：ESP 获取 RSSI
>   - [原理图](https://ziliao.nologo.tech/%E6%97%A0%E5%90%8D%E7%A7%91%E6%8A%80Nologo%E8%B5%84%E6%96%99/ESP32%E5%BC%80%E5%8F%91%E6%9D%BF/ESP32-H2%20Supermini+HXB%E8%B5%84%E6%96%99/SuperMini-H2%E5%8E%9F%E7%90%86%E5%9B%BE.png)
> - [简化智能家居：了解 Matter、Thread 与 Wi-Fi 如何重塑物联网连接](https://cn.qorvo.com/design-hub/blog/simplifying-smart-homes-learn-how-matter-thread-and-wi-fi-are-revolutionizing-iot-connectivity)：文章写的不错，介绍了 openthread
> - [使用 ESP32H2 和 ESP 线程边界路由器板构建线程网络](https://openthread.io/codelabs/esp-openthread-hardware?hl=zh-cn#1)：官方开发文档。
>   - https://github.com/espressif/esp-idf/tree/master/examples/openthread/ot_cli： 命令行案例
>   - https://github.com/openthread/openthread/blob/main/src/cli/cli.cpp：一些命令的实现
>   - [OpenThread CLI Reference](https://github.com/openthread/openthread/blob/main/src/cli/README.md)

通过 `ot_cli` 成功获取 `PAN`、`MAC`，`CH` 、`dBm`。

```txt
esp32h2> ot scan
| PAN  | MAC Address      | Ch | dBm | LQI |
+------+------------------+----+-----+-----+
| e3af | b67c6d999dd20370 | 14 | -44 |  10 |
Done
```

![What is RSSI? Understanding Your RSSI Level | Virgin Media O2](https://storyblok.cdn.vmo2digital.co.uk/f/253875/1980x1080/bb999cfe80/rssi-signal-strength-comparsion.jpg/m/1200x0/filters:quality(75))

1. 两片测试，最近距离 dBm 为 -10；一米左右 dBm 为 -47（50）。

   假设，空旷地带，10米 dBm 为 `-47 - 10*2*lg(10) = -47 - 20 = -67`，50米dBm为 `81`

2. 根据测试，陶瓷天线存在方向。存在情况，A可以接收到B信号，但是B不可以接收到A信号。

3. 根据公式，空旷地带，10米距离 dBm 降低 20，有遮挡降低 40。100米距离，dBm 降低 40，有遮挡降低 80。

   - 根据 ESP 设计，接收灵敏度在 -98dBm。
   - ESP 发射功率在 -20dBm 到 20dBm 之间

4. 测试使用 命令行，扫描可以通过 `scan` 和 `discover`，`PAN ID` 可以通过 `panid` 获取和设置，范围内多个相同 `PAN` 不会影响什么

5. 可以通过 API 轮训获取 RSSI：

   [otLinkEnergyScan](https://github.com/openthread/openthread/blob/main/src/cli/cli.cpp)，还有一个 otThreadDiscover 能拿到名称。

   ```cpp
   void scanCallback(otActiveScanResult *aResult, void *aContext) {
     if (aResult != NULL) {
       ESP_LOGI(TAG, "PAN: %u; dBm: %d", aResult->mPanId, aResult->mRssi);
     }
   }
   
   void ScanTask(void *) {
     while (true) {
   
       uint32_t scanChannels = 0;
       uint16_t scanDuration = 0;
   
       otLinkActiveScan(esp_openthread_get_instance(), scanChannels, scanDuration,
                        scanCallback, NULL);
       vTaskDelay(pdMS_TO_TICKS(100));
     }
   }
   ```

6. 在 `ActiveScan` 函数中， 扫描间隔默认为 300ms。

7. 后期大体是稳定的，但是会被其他进程干扰，可能要考虑优先级以及关闭其他功能。

8. 板载陶瓷天线型号推测为 C03，根据文档，长条方向为轴，轴两边的信号最强，天线正上方信号不如下方信号。

9. 信号接收和电源质量呈正相关。



当前问题：

1. H2 全向高增益天线