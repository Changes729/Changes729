> 文章来源：https://sspai.com/post/69407
>
> 关键词：
>
> - [内容农场](https://zh.wikipedia.org/wiki/內容農場)（Content farm）：这些网站自己不产出内容，却凭借针对性的 SEO 极力提升在搜索引擎中的权重并从中牟利。

# 清理「内容农场」，还你清爽的 Google 中文搜索体验

## 内容农场是什么梗？让小编来告诉你

这段话就是一种典型的内容农场文风，俗称「小编体」。其特征是通篇复读同一关键词，围绕热点话题，套用固定格式，车轱辘话扯上千字，以浪费读者时间为己任，往往还伴随着剽窃行为。**自媒体平台的营销号们这么做，是为了使文章更容易被搜索，以提高阅读量，榨取更多收入。**

内容农场的文章**通常直接爬取自其它平台，用自动化程序实现从采集到发布的一整套流程**：比较不讲究的，就是聚合下社交网络热门关键词，拼凑生成网页，主动推送至各大搜索引擎，能骗一个是一个；稍微先进点的，会扒下整篇文章，掐头去尾，再加上自己的水印，甚至直接复刻一个李鬼网站；技术力再高一点，可能从 Stack Overflow、GitHub 等外国网站搜刮热门内容，机器翻译后当成自家原创，或者干脆中翻英再翻中，让读者难以找到原文出处。

少数派开张**九年**有余，**几百作者共同创作，迄今只有不到七万篇文章**；



## 惊天内幕！内容农场总在前列的秘诀

还是以每日頭條为例，其绝大部分内容都直接抓取自微信公众平台、今日头条等致力于构建「**生态闭环**」的内地网站，而上述平台对通用搜索引擎极其不友好。因此，如果你发表了一篇公众号独占的原创文章，除搜狗外的搜索引擎只能索引到盗文的内容农场。在极端情况下，若原文被和谐，这些网站甚至可能成为唯一参考来源。

**换句话说，在 Google 等搜索引擎看来，每日頭條的文章均属原创，而且量大管饱，精品频出，不排第一简直对不起作者**。

**关联阅读：**[7000 字告诉初学者 2022 Google SEO 怎么玩](https://sspai.com/post/68905)

更恼火的是，[蜻蜓计划](https://zh.wikipedia.org/zh-hans/蜻蜓計畫) 等重返大陆的方案被搁置后，Google 对中文搜索已经基本进入了放养状态，在桌面端优先展示移动版网页都是常有之事。



眼不见为净，最直接的方式当然是避免搜索结果中出现内容农场。[uBlacklist](https://iorate.github.io/ublacklist/) 这款浏览器扩展就能自动屏蔽 Google 搜索页面中出现的低质量结果，支持 [Chrome](https://chrome.google.com/webstore/detail/ublacklist/pncfbmialoiaghdehhbnbhkkgmjanfhe/)、[Firefox](https://addons.mozilla.org/en/firefox/addon/ublacklist/) 和 [Safari](https://apps.apple.com/cn/app/id1547912640) 等主流平台。

目前更新最及时、社区最活跃的中文项目是 [Google Chinese Results Blocklist](https://github.com/cobaltdisco/Google-Chinese-Results-Blocklist)，自 2016 年不断完善至今，已覆盖数千网址，提供 [精确匹配](https://raw.githubusercontent.com/cobaltdisco/Google-Chinese-Results-Blocklist/master/uBlacklist_subscription.txt) 和 [模糊匹配](https://raw.githubusercontent.com/cobaltdisco/Google-Chinese-Results-Blocklist/master/uBlacklist_match_patterns.txt) 两种规则，复制订阅链接后直接添加即可。[uBlacklist subscription compilation](https://github.com/eallion/uBlacklist-subscription-compilation) 是一个较为激进的项目，整合网络上大部分订阅列表，通过 GitHub Actions 自动更新。如果你经常搜索编程关键词，我推荐尝试针对 [机翻 Stack Overflow](https://github.com/arosh/ublacklist-stackoverflow-translation) 和 [GitHub](https://github.com/arosh/ublacklist-github-translation) 采集站的规则列表。也欢迎你参与上述项目，分享遇到的垃圾站点，让更多人受益。