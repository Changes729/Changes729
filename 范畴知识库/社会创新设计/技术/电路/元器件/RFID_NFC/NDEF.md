> 参考资料：
>
> - [深入理解Android：Wi-Fi、NFC和GPS卷](https://static.kancloud.cn/alex_wsc/android-wifi-nfc-gps/)：介绍了 NDEF 数据结构
> - [don](https://github.com/don)/[**NDEF**](https://github.com/don/NDEF)：基于 PN532 的 NDEF 库

# NDEF

NDEF（NFC Data Exchange Format，NFC 数据交换格式）。

接触 Android 的 NFC 时，会有许多疑惑。因为 Android 对 NFC Intent 进行关注时需要定义不同的 NFC Intent 类型，包括三种：

- ACTION_NDEF_DISCOVERED
- ACTION_TECH_DISCOVERED
- ACTION_TAG_DISCOVERED



其中，NDEF 就是无论你是什么卡，只要你符合 NDEF 的数据格式，就可以按照这个来处理，这样就完全隐藏底层 —— 无论你是 Mifare 1k、4k 还是 ICode 卡等等。

但是，NDEF 格式是 NFC Forum 定制的格式，现在 NFC Forum 的文档你不是官方会员你拿不到，所以学生们用的时候就会有许多非标的用法，那那时候存储在 RFID 内的数据就肯定不是 NDEF 格式的了。

为了解决这个问题，Android 设计了 TECH 格式。TECH 格式就是将各个卡的类型做了规定，比如都是 NfcA 的卡、或者都是 NfcB 的卡等等。

其实 NfcA 卡就是 TypeA 卡，也叫 Mifare 卡。Nfc B 是 Type B 卡。两者都是 ISO 14443 协议规范，但是在防冲突算法和交互细节上有所区别。

NfcF 是日本的 RFID 卡。不熟。

NfcV 卡是 ISO 15693 卡。不熟。

还有其他类型，贼多。



那最后，假如没有应用程序对 TECH 卡关心，那么 Android 就会发一个 `ACTION_TAG_DISCOVERED` 给到应用程序，让应用程序自己去判断是什么卡，这个步骤就是自由度最高，写法也最多，开发最耗时间的技术类型了。