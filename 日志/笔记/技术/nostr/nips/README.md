[NIP-01](./NIP-01.md)：客户端、服务端基本通信
[NIP-02](./NIP-02.md)：联系人
[NIP-03](./NIP-03.md)：OpenTimestamps Attestations for Events OpenTimestamps 事件证明
[NIP-04](./NIP-04.md)：Encrypted Direct Message加密直接消息
[NIP-05](./NIP-05.md)：Mapping Nostr keys to DNS-based internet identifiers 将Nostr密钥映射到基于DNS的Internet标识符
[NIP-06](./NIP-06.md)：Basic key derivation from mnemonic seed phrase从助记种子短语导出基本密钥
[NIP-07](./NIP-07.md)：`window.nostr` capability for web browsers Web浏览器的能力
[NIP-08](./NIP-08.md)：Handling Mentions 处理提及
[NIP-09](./NIP-09.md)：Event Deletion 事件删除
[NIP-10](./NIP-10.md)：On "e" and "p" tags in Text Events (kind 1).在文本事件中的“e”和“p”标签上（类型1）。
[NIP-11](./NIP-11.md)：Relay Information Document 继电器信息文档
[NIP-12](./NIP-12.md)：Generic Tag Queries 通用标记查询
[NIP-13](./NIP-13.md)：Proof of Work 工作量证明
[NIP-14](./NIP-14.md)
[NIP-15](./NIP-15.md)
[NIP-16](./NIP-16.md)：Event Treatment 事件处理
[NIP-17](./NIP-17.md)
[NIP-18](./NIP-18.md)
[NIP-19](./NIP-19.md)
[NIP-20](./NIP-20.md)
[NIP-21](./NIP-21.md)
[NIP-22](./NIP-22.md)：Event 活动 `created_at` Limits 限制
[NIP-23](./NIP-23.md)：Long-form Content长格式内容
[NIP-24](./NIP-24.md)
[NIP-25](./NIP-25.md)
[NIP-26](./NIP-26.md)
[NIP-27](./NIP-27.md)
[NIP-28](./NIP-28.md)：Public Chat公共聊天
[NIP-29](./NIP-29.md)
[NIP-30](./NIP-30.md)：Custom Emoji自定义表情符号
[NIP-31](./NIP-31.md)
[NIP-32](./NIP-32.md)：Labeling标签
[NIP-33](./NIP-33.md)
[NIP-34](./NIP-34.md)
[NIP-35](./NIP-35.md)
[NIP-36](./NIP-36.md)
[NIP-37](./NIP-37.md)
[NIP-38](./NIP-38.md)
[NIP-39](./NIP-39.md)
[NIP-40](./NIP-40.md)
[NIP-41](./NIP-41.md)
[NIP-42](./NIP-42.md)
[NIP-43](./NIP-43.md)
[NIP-44](./NIP-44.md)
[NIP-45](./NIP-45.md)
[NIP-46](./NIP-46.md)
[NIP-47](./NIP-47.md)
[NIP-48](./NIP-48.md)
[NIP-49](./NIP-49.md)
[NIP-50](./NIP-50.md)
[NIP-94](./NIP-94.md)：File Metadata 文件元数据
[NIP-98](./NIP-98.md)：HTTP 身份认证





## Event Kinds

| kind    | description                | NIP         |
| ------- | -------------------------- | ----------- |
| `0`     | Metadata                   | [1](01.md)  |
| `1`     | Short Text Note            | [1](01.md)  |
| `2`     | Recommend Relay            | [1](01.md)  |
| `3`     | Contacts                   | [2](02.md)  |
| `4`     | Encrypted Direct Messages  | [4](04.md)  |
| `5`     | Event Deletion             | [9](09.md)  |
| `6`     | Repost                     | [18](18.md) |
| `7`     | Reaction                   | [25](25.md) |
| `8`     | Badge Award                | [58](58.md) |
| `16`    | Generic Repost             | [18](18.md) |
| `40`    | Channel Creation           | [28](28.md) |
| `41`    | Channel Metadata           | [28](28.md) |
| `42`    | Channel Message            | [28](28.md) |
| `43`    | Channel Hide Message       | [28](28.md) |
| `44`    | Channel Mute User          | [28](28.md) |
| `1063`  | File Metadata              | [94](94.md) |
| `1984`  | Reporting                  | [56](56.md) |
| `1985`  | Label                      | [32](32.md) |
| `9734`  | Zap Request                | [57](57.md) |
| `9735`  | Zap                        | [57](57.md) |
| `10000` | Mute List                  | [51](51.md) |
| `10001` | Pin List                   | [51](51.md) |
| `10002` | Relay List Metadata        | [65](65.md) |
| `13194` | Wallet Info                | [47](47.md) |
| `22242` | Client Authentication      | [42](42.md) |
| `23194` | Wallet Request             | [47](47.md) |
| `23195` | Wallet Response            | [47](47.md) |
| `24133` | Nostr Connect              | [46](46.md) |
| `27235` | HTTP Auth                  | [98](98.md) |
| `30000` | Categorized People List    | [51](51.md) |
| `30001` | Categorized Bookmark List  | [51](51.md) |
| `30008` | Profile Badges             | [58](58.md) |
| `30009` | Badge Definition           | [58](58.md) |
| `30017` | Create or update a stall   | [15](15.md) |
| `30018` | Create or update a product | [15](15.md) |
| `30023` | Long-form Content          | [23](23.md) |
| `30078` | Application-specific Data  | [78](78.md) |
| `31989` | Handler recommendation     | [89](89.md) |
| `31990` | Handler information        | [89](89.md) |