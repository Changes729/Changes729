> 视频来源：https://www.youtube.com/watch?v=FqR5vESuKe0

# Latency Numbers Programmer Should Know: Crash Course System Design

## 摘记

- CPU的时钟周期在ns级 
- L1、L2缓存在1-10ns内；CPU分支错误预测惩罚也在这个时间范围内（20个CPU周期）
- L3缓存在10-100ns内，主存
- 100-1000ns范围内包括了Linux系统调用；或者md5校验算法
- 1-10us，Linux任务切换所需的时间；以及主存到内存的拷贝所需时间
- 10-100us，Nginx 处理HTTP请求所需时间，以及从主存中顺序读取1MB的数据。
- 100-1000us：SSD写入延迟，写入一页需要1ms；云服务局域网内往返速度也在这个区间。
  - 典型的 Memcache 或 redis 获取操作大约只需要 1ms；这里包括上面的网络延迟



## 关键词

