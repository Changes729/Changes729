> 文章来源：https://github.com/nostr-protocol/nips/blob/master/01.md

# NIP-01

## 事件基本类型（Event）

```json
{
  "id": <32字节 sha256 16进制小写编码 的序列化数据>,
  "pubkey": <32字节 16进制小写编码 的事件发送者公钥>,
  "created_at": <unix 时间戳（s）>,
  "kind": <一个整数>,
  "tags": [
    ["e", <32字节 16进制表示 其他事件的 ID>, <recommended relay URL>],
    ["p", <32字节 16进制表示 的一个公钥>, <recommended relay URL>],
    ... // 以后可能会包含其他类型的标签
  ],
  "content": <任意字符串>,
  "sig": <64字节 sha256 16进制表示 的此事件序列化数据的信息摘要，这个字段和 “id” 字段是相同的>
}
```

- Q1：kind有什么用？

- Q2：发送者公钥用来做什么？

- Q3：e有什么用？p有什么用？

  A3：详见 NIP-10

- Q4：如果sig和id一样，那么为什么要设置一个 sig 字段？



## 客户端和中继器之间的数据通信

**客户端行为**：

- `["EVENT", <event JSON as defined above>]`，用于发布事件。
- `["REQ", <subscription_id>, <filters JSON>...]`，用于请求事件和订阅新的更新。
- `["CLOSE", <subscription_id>]`，用于停止以前的订阅。

**相关参数**：

- `<subscription_id>`是一个任意的非空字符串，最大长度为64个字符，应该用来表示订阅。

- `<filters>`是一个JSON对象，它确定在该订阅中将发送哪些事件，它可以具有以下属性：

  ```json
  {
    "ids": <一个事件id或前缀的列表>,
    "authors": <公开密钥或前缀的列表，事件的公开密钥必须是其中之一>,
    "kinds": <一个 kind 列表>,
    "#e": <一个被 “e” 标签引用的事件列表>,
    "#p": <一个被 “p” 标签引用的公钥列表>,
    "since": <一个 unix 时间戳, 事件必须比这个时间戳要新>,
    "until": <一个 unix 时间戳, 事件必须比这个时间戳要旧>,
    "limit": <在返回列表中能返回的最大事件数>
  }
  ```

> Upon receiving a `REQ` message, the relay SHOULD query its internal database and return events that match the filter, then store that filter and send again all future events it receives to that same websocket until the websocket is closed. The `CLOSE` event is received with the same `<subscription_id>` or a new `REQ` is sent using the same `<subscription_id>`, in which case it should overwrite the previous subscription.
>
> Filter attributes containing lists (such as `ids`, `kinds`, or `#e`) are JSON arrays with one or more values. At least one of the array's values must match the relevant field in an event for the condition itself to be considered a match. For scalar event attributes such as `kind`, the attribute from the event must be contained in the filter list. For tag attributes such as `#e`, where an event may have multiple values, the event and filter condition values must have at least one item in common.
>
> The `ids` and `authors` lists contain lowercase hexadecimal strings, which may either be an exact 64-character match, or a prefix of the event value. A prefix match is when the filter string is an exact string prefix of the event value. The use of prefixes allows for more compact filters where a large number of values are queried, and can provide some privacy for clients that may not want to disclose the exact authors or events they are searching for.
>
> All conditions of a filter that are specified must match for an event for it to pass the filter, i.e., multiple conditions are interpreted as `&&` conditions.
>
> A `REQ` message may contain multiple filters. In this case, events that match any of the filters are to be returned, i.e., multiple filters are to be interpreted as `||` conditions.

Q5：然而，id和authors都是摘要算法出来的，为什么能有固定的前缀呢？

**服务器行为**：

- `["EVENT", <subscription_id>, <event JSON as defined above>]`，用于发送客户端请求的事件。
- `["EOSE", <subscription_id>]`，用于指示实时存储的事件的结束和新接收的事件的开始。
- `["NOTICE", <message>]`，用于向客户端发送人类可读的错误消息或其他内容。

> `EVENT` messages MUST be sent only with a subscription ID related to a subscription previously initiated by the client (using the `REQ` message above).



## kinds 事件类型

- `0`：`set_metadata`：`content`被设置为字符串化的JSON对象`{name: <username>, about: <string>, picture: <url, string>}`，描述创建事件的用户。中继可以删除过去的`set_metadata`事件，一旦它获得相同pubkey的新事件。
- `1`：`text_note`：`content`设置为笔记的明文内容（用户想说的任何内容）。不应使用必须解析的内容，例如Markdown和HTML。客户端也不应该将内容解析为那些。
- `2`：`recommend_server`：`content`被设置为URL（例如，`wss://somerelay.com`）的事件创建者想要推荐给其追随者的中继。

