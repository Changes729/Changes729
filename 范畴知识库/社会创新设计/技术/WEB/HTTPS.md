> 参考资料：
>
> - [~~Wireshark Tutorial: Decrypting HTTPS Traffic~~](https://unit42.paloaltonetworks.com/wireshark-tutorial-decrypting-https-traffic/)
> - [TLS](https://wiki.wireshark.org/TLS)
>   - [HowTo: Set an Environment Variable in Mac OS X - /etc/launchd.conf](https://www.dowdandassociates.com/blog/content/howto-set-an-environment-variable-in-mac-os-x-slash-etc-slash-launchd-dot-conf/)
>   - [Setting environment variables on OS X](https://stackoverflow.com/questions/135688/setting-environment-variables-on-os-x)
> - [HTTPS proxy tunnel](https://github.com/axios/axios/issues/925#issuecomment-359982190)：HTTPS-over-HTTP tunnel
>   - [Node.js Axios behind corporate proxies](https://janmolak.com/node-js-axios-behind-corporate-proxies-8b17a6f31f9d)
>   - [How to do proxy and TLS in golang](https://stackoverflow.com/questions/61401128/how-to-do-proxy-and-tls-in-golang)：介绍了如何使用 openssl 测试 TLS 连接。也有一些关于代理的知识
> - [一步步生成一张 TLS 证书](https://0x00.cl/blog/2024/exploring-tls-certs/)

# HTTPS

### HTTPS-over-HTTP tunnel

在使用 Suno-API 的时候，用 axios 时会报一个 `The plain HTTP request was sent to HTTPS port.` 的错。即使开代理也不行，但是Web是可以的。后来查资料，了解到有很多不同的代理方式，有一些是正向代理，由服务器去重新建立请求的。

另一种就是隧道，通过在代理之间建立一个隧道，实际上的访问还是本机。



### openssl 连接测试

`openssl s_client -connect [URL] -proxy [address:port]`