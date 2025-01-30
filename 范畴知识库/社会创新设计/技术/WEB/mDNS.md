> 参考资料
>
> - **[mdns](https://github.com/hashicorp/mdns)**：golang mdns 实现
> - [libraries/ESPmDNS/src/ESPmDNS.h](https://github.com/espressif/arduino-esp32/blob/master/libraries/ESPmDNS/src/ESPmDNS.h)：ESP 官方库 mDNS 实现
>   - [How to set up mDNS on an ESP32](https://lastminuteengineers.com/esp32-mdns-tutorial/)：Arduino test pass.
> - [*Avahi*](https://wiki.archlinux.org/title/Avahi)：Linux mdns daemon
>   - [How to route all subdomains to a single host using mDNS?](https://stackoverflow.com/questions/775233/how-to-route-all-subdomains-to-a-single-host-using-mdns)
> - [RFC6762 *mDNS* (Multicast DNS)](https://www.rfc-editor.org/rfc/rfc6762.txt)
> - [RFC6763 *DNS-SD* (DNS-based Service Discovery)](https://www.rfc-editor.org/rfc/rfc6763.txt)

# mDNS

- `DNS-SD (DNS Service Discovery)`



## Avahi

配置mdns，在配置文件里面有一个`[host-name].[domain-name]`很简单。