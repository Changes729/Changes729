> 参考资料
>
> - [golang出现cannot convert res (variable of type interface{}) to type []byte: need type assertion错误](https://blog.csdn.net/weixin_61080257/article/details/140122503)：类型处理

# InfluxDB

## 写入——[Get started writing data](https://docs.influxdata.com/influxdb/v2/get-started/write/)

InfluxDB 数据格式，官方的说明非常好：https://docs.influxdata.com/influxdb/v2/get-started/write/#line-protocol-element-parsing

- measurement（测量值）：标识存储数据的[度量](https://docs.influxdata.com/influxdb/v2/get-started/write/)的字符串。
- tag set（标签集合）：逗号分隔的键值对列表，每个键值对代表一个标签。标记键和值是不带引号的字符串。空格、逗号和等号必须转义。
- field set（字段集合）：逗号分隔的列表键值对，每个键值代表一个字段。字段键是不带引号的字符串。空格和逗号必须转义。字段值可以是[字符串](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#string)（带引号）、[浮点](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#float)数、[整数](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#integer)、[无符号整数](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#uinteger)或[布尔值](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#boolean)。
- timestamp（时间戳）：与数据相关[的Unix时间戳](https://docs.influxdata.com/influxdb/v2/reference/syntax/line-protocol/#unix-timestamp)。

基本元素构成：

```tx
[myMeasurement,tag1=val1,tag2=val2] [field1="v1",field2=2i] [timestamp]
```



## 读取——[Get started querying data](https://docs.influxdata.com/influxdb/v2/get-started/query/?t=influx+CLI)

这里使用 go 语言读取数据。

golang 有几个数据函数：

- `Record().Time()`
- `Record().Measurement()`
- `Record().Field()`
- `Record().Value()`
- `Record().Values()`：可以看到所有的键值对。

> - [range() function](https://docs.influxdata.com/flux/v0/stdlib/universe/range/#Copyright)
