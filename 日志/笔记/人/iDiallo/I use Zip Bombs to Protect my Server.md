> 原文链接：https://idiallo.com/blog/zipbomb-protection

# I use Zip Bombs to Protect my Server

## 关键词

- bots that scan for security vulnerabilities（扫描安全漏洞的机器人）




## 摘记

**01 网络机器人**

> The majority of the traffic on the web is from bots. For the most part, these bots are used to discover new content. These are RSS Feed readers, search engines crawling your content, or nowadays AI bots crawling content to power LLMs. But then there are the malicious bots. 
>
> 网络上的大部分流量来自机器人。在大多数情况下，这些机器人用于发现新内容。这些是RSS Feed阅读器，搜索引擎抓取您的内容，或者现在的AI机器人抓取内容以支持LLM。但还有恶意的机器人。这些都是来自垃圾邮件发送者，内容抓取器或黑客。



**02 如何创建一个 zip 炸弹（zip bomb）**

> ```default**
> dd if=/dev/zero bs=1G count=10 | gzip -c > 10GB.gz
> ```



**03 黑名单**

> On my server, I've added a middleware that checks if the current request is malicious or not. I have a list of black-listed ips that try to scan the whole website repeatedly. I have other heuristics in place to detect spammers. A lot of spammers attempt to spam a page, then come back to see if the spam has made it to the page. I use this pattern to detect them. It looks something like this:
>
> 在我的服务器上，我添加了一个中间件来检查当前请求是否是恶意的。我有一个黑名单的ip，试图扫描整个网站反复。我有其他的方法来检测垃圾邮件发送者。很多垃圾邮件发送者试图发送垃圾邮件到一个页面，然后回来看看垃圾邮件是否已经到达该页面。我用这种模式来检测它们。它看起来像这样：
>
> ```js
> if (ipIsBlackListed() || isMalicious()) {
>     header("Content-Encoding: gzip");
>     header("Content-Length: "+ filesize(ZIP_BOMB_FILE_10G)); // 10 MB
>     readfile(ZIP_BOMB_FILE_10G);
>     exit;
> }
> ```



## 思路

