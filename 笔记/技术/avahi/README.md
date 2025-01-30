> 参考资料：[avahi](https://github.com/avahi)/[avahi](https://github.com/avahi/avahi)

# avahi

## mDNS 实现方式

```cpp
int avahi_mdns_mcast_join_ipv4(int fd, const AvahiIPv4Address *a, int idx, int join) {
#ifdef HAVE_STRUCT_IP_MREQN
    struct ip_mreqn mreq;
#else
    struct ip_mreq mreq;
#endif
    struct sockaddr_in sa;

    assert(fd >= 0);
    assert(idx >= 0);
    assert(a);

    memset(&mreq, 0, sizeof(mreq));
#ifdef HAVE_STRUCT_IP_MREQN
    mreq.imr_ifindex = idx;
    mreq.imr_address.s_addr = a->address;
#else
    mreq.imr_interface.s_addr = a->address;
#endif
    mdns_mcast_group_ipv4(&sa);
    mreq.imr_multiaddr = sa.sin_addr;

    /* Some network drivers have issues with dropping membership of
     * mcast groups when the iface is down, but don't allow rejoining
     * when it comes back up. This is an ugly workaround */
    if (join)
        setsockopt(fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));

    if (setsockopt(fd, IPPROTO_IP, join ? IP_ADD_MEMBERSHIP : IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        avahi_log_warn("%s failed: %s", join ? "IP_ADD_MEMBERSHIP" : "IP_DROP_MEMBERSHIP", strerror(errno));
        return -1;
    }

    return 0;
}
```

其中，`mdns_mcast_group_ipv4` 构造了一个组播地址。具体的操作是先 `IP_DROP_MEMBERSHIP`，再 `IP_ADD_MEMBERSHIP`。

> 这样子的话，mDNS首先是在各个地方注册了一个解析服务器，这一步应该就是做这个的。然后很多 domain 其实是通过 mDNS 进行解析的。
>
> 需要了解 *recvfrom*，avahi 服务端如何接受数据并返回的；以及mDNS是如何被请求的。

从 Wireshark 抓包可以看到，最开始是网络中的其他设备访问 `224.0.0.251`，询问地址，而后是本地回给对端一个具体的地址。

```txt
262	14.402409458	192.168.3.109	224.0.0.251	MDNS	75	Standard query 0x4d00 A emptiness.local, "QM" question`
263	14.402594866	192.168.3.103	192.168.3.109	MDNS	91	Standard query response 0x4d00 A emptiness.local, "QM" question A 192.168.3.103`
```



