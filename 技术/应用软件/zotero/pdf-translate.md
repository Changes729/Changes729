# Zotero 翻译插件实现扫描

最近在做一个提高自己看视频效率的工具。虽然 whisper 可以支持语言转文本，然而，还是不能顺便做到翻译的。

现在语音转文本都很方便，有了文本后文本再转语言也很方便。感谢技术。

本文呢是 [zotero-pdf-translate](https://github.com/windingwind/zotero-pdf-translate) 工程的技术扫描，同时呢也会尝试整理所有的API。以方便后续其他工程上使用。



## 实现路径扫描

虽然没有了解过 zotero 的插件开发，但是一看 `zotero-pdf-translate` 是 `typescript` 写的，笔者也简单看了一下 zotero 的工程实现，也是JS工程。再想想 VSCode，都可以通过前端技术实现插件功能。所以前端做APP好用是有道理的。

入口文件简单看，就是 `src/index.ts`，文件不用看太多，只需要注意两行：

```ts
/** src/index.ts */
import Addon from "./addon";
...

if (!basicTool.getGlobal("Zotero")[config.addonInstance]) {
	...
  _globalThis.addon = new Addon();
  defineGlobal("ztoolkit", () => {
    return _globalThis.addon.data.ztoolkit;
  });
  Zotero[config.addonInstance] = addon;
  // Trigger addon hook for initialization
  addon.hooks.onStartup();
}

...
```

因为其他内容其实都是插件语法和配置文件，所以不用在意，我们的目标是找到翻译的具体实现路径。

从顶至下考虑，想要实现文本翻译，基本上只需要实现一个函数：

```cpp
string translate(string){...}
```

而且我们已经知道了 zotero 的交互方式，只需要用户使用鼠标选取文本，插件便可以自动翻译。那么找到绑定交互行为的事件函数即可找到其调用的翻译函数了。

```ts
/** src/addon.ts */
import api from "./api";
import hooks from "./hooks";
import { TranslateTask } from "./utils/task";
import { TranslationServices } from "./modules/services";
import { createZToolkit } from "./utils/ztoolkit";

class Addon {...}
```

ok，其实这里已经看到所有的内容了。`hooks` 就是插件的事件钩子，`TranslateTask` 估计就是具体执行翻译的抽象任务，`TranslationServices` 应该就是我们要找的各个翻译服务器了。

多看一点，先看 `hooks`：

```ts
/** src/hooks.ts */
...

function onReaderPopupShow(
  event: _ZoteroTypes.Reader.EventParams<"renderTextSelectionPopup">,
) {
  const selection = addon.data.translate.selectedText;
  const task = getLastTranslateTask();
  if (task?.raw === selection) {
    buildReaderPopup(event);
    addon.hooks.onReaderPopupRefresh();
    return;
  }
  addTranslateTask(selection, event.reader.itemID);
  buildReaderPopup(event);
  addon.hooks.onReaderPopupRefresh();
  if (getPref("enableAuto")) {
    addon.hooks.onTranslate();
  }
}

...

export default {
  onStartup,
  onMainWindowLoad,
  onMainWindowUnload,
  onShutdown,
  onNotify,
  onPrefsLoad,
  onShortcuts,
  onTranslate,
  onTranslateInBatch,
  onReaderPopupShow,
  onReaderPopupRefresh,
  onReaderTabPanelRefresh,
};
```

OK，从 `onReaderPopupShow` 中可以看到，如果开启了 `enableAuto`，那么就会自动执行 `addon.hooks.onTranslate();`

```ts
/** src/hooks.ts */
async function onTranslate(...data: any) {
  let task = undefined;
  let options = {};
  if (data.length === 1) {
    if (data[0].raw) {
      task = data[0];
    } else {
      options = data[0];
    }
  } else if (data.length === 2) {
    task = data[0];
    options = data[1];
  }
  await addon.data.translate.services.runTranslationTask(task, options);
}
```

看见了吗，最后调用的是 `translate.services.runTranslationTask`，点进去看：

```ts

export class TranslationServices {
  [key: string]: TranslateTaskRunner | unknown;
  constructor() {
    import("./aliyun").then(
      (e) => (this.aliyun = new TranslateTaskRunner(e.default)),
    );
    import("./baidu").then(
      (e) => (this.baidu = new TranslateTaskRunner(e.default)),
    );
    ...
  }
```

这样就找到了各个不同翻译平台的具体注册函数了。它们是通过文字索引找到的对应的翻译任务执行器的。



## 翻译工具整理

因为知网、Google 以及 DeepLx 的翻译都是免费的，所以这里也先只记录这些API调用办法。

### Google 翻译

这个工程的 Google 翻译实现有点复杂，很大程度上是由抄录的JS导致的，导致我们不知道那段代码实现了什么（但其实只是文本翻译而已）

这里找了一个 Golang 实现的Google翻译调用工程 [googletranslate](https://github.com/spywiree/googletranslate)

```go
/** googletranslate/endpoint_1.go */
func TranslateE1(text string, source, target languagecodes.LanguageCode) (string, error) {
	...
	url := "https://translate.googleapis.com/translate_a/single?client=gtx&dt=t"
	url += "&sl=" + string(source)
	url += "&tl=" + string(target)
	url += "&q=" + u.QueryEscape(text)

	r, err := http.Get(url)
  ...
}
```

可以看到非常清楚的三个参数。那我们就可以模仿这个格式去获取翻译的结果：

`https://translate.googleapis.com/translate_a/single?client=gtx&dt=t&sl=en&tl=zh&q=helloworld`

结果会回一个Json TxT文件：

`[[["你好世界","helloworld",null,null,10]],null,"en",null,null,null,null,[]]`



### 知网翻译

知网翻译有点麻烦，首先得去知网拿到 Token：

```sh
curl https://dict.cnki.net/fyzs-front-api/getToken
# {"msg":"","code":200,"data":"f6f6b8e4-330a-4a08-95e8-68716d8bb611"}
```

然后再编织 POST 内容，其中，`words` 字段需要先加密，再变成 Base64 进行传输（没有成功）：

```sh
curl -X POST -H "Token:f6f6b8e4-330a-4a08-95e8-68716d8bb611" -H "Content-Type:application/json;charset=UTF-8" --data "words:aes_with_base64&translateType: null" https://dict.cnki.net/fyzs-front-api/translate/literaltranslation
```



