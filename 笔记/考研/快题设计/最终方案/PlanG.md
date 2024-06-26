# PlanG - 音韵

哼小曲儿 - JAZZ - 乐器 - 伴奏 - 分享

## 第一章 方案呈现

**01 [主题]：传统民族文化与数字文创**

**02 [引出]**

中国自古以来就是世界公认的礼乐之邦。音乐制作在古时制作非常麻烦


**03 [现状与需求分析]**

我们通过在城市道路上进行用户调研，调研内容分三块："音乐兴趣与相关程度"、"生活中的声音"以及"音乐的本质"三方面进行研究。其中，音乐兴趣与相关程度，从生活、应用场景、音乐生产等方面对被试进行分析；生活中的声音通过多选框和启发式问答，让被试写出符合某场景的音乐名称或声音内容；最后音乐的本质通过开放式问答，从现代音乐和传统古代音乐、现代音乐和人工智能音乐、普通的声音和音乐等角度让被试阐述自己的看法。从而得出了一幅用户画像：

**用户画像**

小王：

- 程序员、业余音乐制作人。
- 不会乐器，想要自己创作音乐。会使用草莓音乐制作软件设计音乐。
- 不会乐理，路上突现灵感时，通过手机记录曲调，在家中对音乐进行MIDI采样比较花费时间。
- 可以说出一些场景下的具体声音，大多数城市的声音比较嘈杂，而乡村的声音比较自然。
- 会尝试将这些声音变成音乐。
- 很喜欢采样音乐。认为自然的声音在叙事时是最好的音源。

**使用场景** 

（渐进式音乐生成器）

酒吧里，人可以对声音进行录音，然后转为钢琴、小号的声音上传，成为酒吧背景的一部分。用户也可以看到背景音乐的所有乐谱，对喜爱的片段进行点赞投票。（OK）

运河边，行人散步，从没声音变成有节奏，从有节奏变成有节律，到有旋律。（任何走路的时候，逛街，文化街、运河边、超市、回家）
文化街，街边叫卖，形成基本节奏。用户可以自己哼节奏，然后试听、上传。
社区公园，散步时。
打铁铺、纺织处、画画画室。（任何制造场景，流水线）

（音乐生成器）

酒吧里有人JAZZ演奏完，可以通过这个软件作风格迁移，用其他乐器继续演奏之前钢琴曲的旋律。（ON）

某人走在路上，哼出了一段节奏，它把它录了下来，通过软件听到了用提琴、钢琴演奏的样子，它听着新曲子，哼了新旋律，软件纪录并转化了新旋律，他通过微调，创建了多个音乐片段，完成了一首曲子。

虎跑那边在下雨，雨落在伞上、亭子上、树叶上、水塘中，软件把它记录了下来，通过声音风格获取了一段风格类似的音乐片段，他将这两个片段结合，谱成了一首曲子。自然中的鸟鸣，有近有远，他把声音记录下来，变成了一个小片段，用户将这个片段节奏重复完成了乐曲，并且使用其他乐器将其演奏出来。

用户录音获取某个乐器声音，他通过软件听到了乐器所模拟的鸟鸣声、瀑布水流声、雨滴声等。

**需求分析**

用户希望能有一款音乐记录与制作软件，方便用户用声音记录生活，让用户从生活中发现音乐、创作音乐、分享音乐。

**现状分析**

用户音乐制作流程

采样 -》（人工）MIDI -》 编曲 -》 混音 -》 演唱

采样 -》（自动）MIDI -》**变成其他乐器演奏，或找其他相似的采样音乐** -》 编曲 -》 混音 

**功能**

- 功能一：采集音频、段落化记录
- 功能二：音频MIDI转化
- 功能三：音频预览
- 功能四：音频并入上传
- 功能五：