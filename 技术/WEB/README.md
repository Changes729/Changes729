> 参考资料：
>
> - [[MDN] CORS](https://developer.mozilla.org/en-US/docs/Glossary/CORS)
> - [HTML 元素参考](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element)

# 前端基础

## HTML

列表描述：

- `<ol>`：ordered list
- `<ul>`：unordered list
- `<li>`：list



## CORS（**Cross-Origin Resource Sharing**）

当请求域名与网页域名不一致时，并且请求域名没有开放跨域请求权限时，就会产生这个问题。

> 它由一系列传输的 [HTTP 标头](https://developer.mozilla.org/zh-CN/docs/Glossary/HTTP_header)组成，这些 HTTP 标头决定浏览器是否阻止前端 JavaScript 代码获取跨源请求的响应。

跨域请求是一个前端行为，由浏览器对前端行为进行阻止。

解决这个问题可以在被请求网页中添加跨域头：

```go
w.Header().Add("Access-Control-Allow-Origin", "*")
```



## 正向代理和反向代理

所谓正向代理，是指在客户端进行代理。用户在客户端配置正向代理服务器，正向代理服务器向实际资源服务器发送请求，再原路返回。类似 GOPROXY，SOCK_PROXY等。

而反向代理是在服务端，用户往往不知道代理的存在。比较典型的就是NGINX负载均衡，它反向代理的服务器，其实对用户是隐藏的。



## DevOps（Development & Operations）

DevOps 是一组过程、方法与系统的统称，用于促进开发、技术运营和质量保障部门之间的沟通、协作与整合。

其核心思想在于**解决开发者与运维之间曾经不可逾越的鸿沟**，增强开发者与运维者之间的沟通和交流。

> DevOps 的出现是由于软件行业日益清晰地认识到：为了按时交付软件产品和服务，开发和运营工作必须紧密合作。市场瞬息万变，同时机会转瞬即逝。**互联网公司要实现生存，必须拥有快速试错和迭代产品的能力**。那我们有没有办法快速交付价值、灵活响应变化呢？答案就是 DevOps，他是面向业务目标，助力业务成功的最佳实践。
>
> DevOps的目标是缩短开发周期，**增加部署频率，更可靠的发布**。用户可以通过完整的工具链，**深度集成代码仓库、制品仓库、项目管理、自动化测试等类别中的主流工具，实现零成本迁移，快速实践DevOps**。



## 其他

If you set `"private": true` in your package.json, then npm will refuse to publish it.

This is a way to prevent accidental publication of private repositories.