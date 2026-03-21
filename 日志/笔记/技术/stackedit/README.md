> 参考资料：
>
> - [mafgwo](https://github.com/mafgwo)/[stackedit](https://github.com/mafgwo/stackedit)：中文版，可运行。

# StackEdit

## 留存的問題

1. 具体的编辑器是如何实现的？对象是什么？有哪些方法？
   1. 内容是如何注入的？
   2. 当识别到内容变化后，会做什么操作？
   3. 文本变化和 Dom 变化
   4. 如何读取 Raw data？





## 编辑器构成与技术细节

**01 具体的编辑器实现**

**01.1 编辑器结构**

具体的编辑器部分在 `components/Editor.vue`，内容是存储在 `<pre class="editor__inner` 里面的。这个 `dom` 在代码中也会被提取为 `editorElt`



`Editor.vue` 创建  `.editor__inner`

`Layout.vue` 提取 `.editor__inner`并初始化 `editorSvc`

`editorSvc.js` 使用 `cledit`，`cledit` 最终调用 `cleditHighlighter` 的 `highlight`



`workspaceSvc` 会提取并创建具体的文件 `newFile`，然后将新文件存储到 `file/setCurrentId` 中。



**01.2 内容是如何注入的？**

在 `localDbSvc.js` 中，会默认读取一个文件

```js
// If still no ID, create a new file
const newFile = await workspaceSvc.createFile({
  name: 'Welcome file',
  text: welcomeFile,
}, true);
// Set it as the current file
store.commit('file/setCurrentId', newFile.id);
```

而在 `workspaceSvc.createFile` 中，会把 `text` 存入 `content` 中，

```js
const item = {
  id,
  name: utils.sanitizeFilename(name),
  parentId: parentId || null,
};
const content = {
  id: `${id}/content`,
  text: utils.sanitizeText(text || store.getters['data/computedSettings'].newFileContent),
  properties: utils
    .sanitizeText(properties || store.getters['data/computedSettings'].newFileProperties),
  discussions: discussions || {},
  comments: comments || {},
};

...

store.commit('content/setItem', content);
store.commit('file/setItem', item);
```

这个 `content` 是 Vue Store 的一个文件 `content.js`，它通过模板创建

```js
import moduleTemplate from './moduleTemplate';
import empty from '../data/empties/emptyContent';
const module = moduleTemplate(empty);
```

这个模板内自包含了 `setItem`

```js
import { reactive } from 'vue';
import utils from '../services/utils';

export default (empty, simpleHash = false) => {
  // Use Date.now() as a simple hash function, which is ok for not-synced types
  const hashFunc = simpleHash ? Date.now : item => utils.getItemHash(item);

  return {
    namespaced: true,
    state: reactive({
      itemsById: {}
    }),
    getters: {
      items: ({ itemsById }) => Object.values(itemsById),
    },
    mutations: {
      setItem(state, value) {
        const item = Object.assign(empty(value.id), value);
        if (!item.hash || !simpleHash) {
          item.hash = hashFunc(item);
        }
        state.itemsById[item.id] = item;
      },
      patchItem(state, patch) {
        const item = state.itemsById[patch.id];
        if (item) {
          Object.assign(item, patch);
          item.hash = hashFunc(item);
          state.itemsById[item.id] = item;
          return true;
        }
        return false;
      },
      deleteItem(state, id) {
        delete state.itemsById[id];
      },
    },
    actions: {},
  };
};
```

在 `editorSvc.js` 中，会使用 `store.watch` 引用出具体内容 `const content = store.getters['content/current'];` 然后会调用 `editorSvcDiscussions.js` 中的 `this.applyContent();`



在 `editorSvcDiscussions.js` 中，有一个 `clEditor` 的编辑器，这个编辑器是从 `editorSvc.js` 的 `Init` 函数，取了第一个参数 `editorElt` 传入的。

```js
/** editorSvc.js */
init(editorElt, previewElt, tocElt) {
  this.editorElt = editorElt;
  this.previewElt = previewElt;
  this.tocElt = tocElt;

  this.createClEditor(editorElt);
...
}

/** editorSvcDiscussions.js */
createClEditor(editorElt) {
  this.clEditor = cledit(editorElt, editorElt.parentNode, true);
...
}
```



**01.3 内容变化**

在初始化的时候，会检测编辑器的内容变化：

```js
clEditor.on('contentChanged', (text) => {
  const oldContent = store.getters['content/current'];
  const newContent = {
    ...utils.deepCopy(oldContent),
    text: utils.sanitizeText(text),
  };
  syncDiscussionMarkers(newContent, true);
  if (!isChangePatch) {
    previousPatchableText = currentPatchableText;
    currentPatchableText = diffUtils.makePatchableText(newContent, markerKeys, markerIdxMap);
  } else {
    // Take a chance to restore discussion offsets on undo/redo
    newContent.text = currentPatchableText;
    diffUtils.restoreDiscussionOffsets(newContent, markerKeys);
    syncDiscussionMarkers(newContent, false);
  }
  store.dispatch('content/patchCurrent', newContent);
  isChangePatch = false;
});
```

这里会分发 `patchCurrent`，更新内容，具体的，会更新 `hash` ，然后，`editorSvc.js` 检测 `currentChangeTrigger` （包括其中 Hash 变化）

```js
store.watch(
  () => store.getters['content/currentChangeTrigger'],
```

然后再调用 `editorSvcDiscussions` 内部的 `applyContent`：

```js
applyContent() {
  if (clEditor) {
    const content = store.getters['content/current'];
    if (clEditor.setContent(content.text, true).range) {
      // Marker will be recreated on contentChange
      removeDiscussionMarkers();
    } else {
      syncDiscussionMarkers(content, false);
    }
  }
},
```

因为内部数据和外部数据是一样的，所以这里就会去调用 `syncDiscussionMarkers` 



文本内部的颜色变化，推测是使用 `Prism` 在 `markdownConversionSvc.js` 中，在 highlight 中调用的：

```js
highlight(markdown, converter = this.defaultConverter, grammars = this.defaultPrismGrammars) {
  const parsingCtx = this.parseSections(converter, markdown);
  return parsingCtx.sections
    .map(section => Prism.highlight(section.text, grammars[section.data])).join('');
},
```

