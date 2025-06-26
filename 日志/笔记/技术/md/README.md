> 代码来源：[md](https://github.com/doocs/md)

# MD 技術解析

在 `src/components/CodemirrorEditor/EditorHeader/index.vue` 文件中，有关键函数 `copy`

```js
function copy() {
  // 如果是 Markdown 源码，直接复制并返回
  if (copyMode.value === `md`) {
    const mdContent = editor.value?.getValue() || ``
    copyPlain(mdContent)
    toast.success(`已复制 Markdown 源码到剪贴板。`)
    editorRefresh()
    return
  }

  // 以下处理非 Markdown 的复制流程
  emit(`startCopy`)

  setTimeout(() => {
    // 如果是深色模式，复制之前需要先切换到白天模式
    const isBeforeDark = isDark.value
    if (isBeforeDark) {
      toggleDark()
    }

    nextTick(async () => {
      processClipboardContent(primaryColor.value)
      const clipboardDiv = document.getElementById(`output`)!
      clipboardDiv.focus()
      window.getSelection()!.removeAllRanges()
      const temp = clipboardDiv.innerHTML

      if (copyMode.value === `txt`) {
        const range = document.createRange()
        range.setStartBefore(clipboardDiv.firstChild!)
        range.setEndAfter(clipboardDiv.lastChild!)
        window.getSelection()!.addRange(range)
        document.execCommand(`copy`)
        window.getSelection()!.removeAllRanges()
      }

      clipboardDiv.innerHTML = output.value

      if (isBeforeDark) {
        nextTick(() => toggleDark())
      }

      if (copyMode.value === `html`) {
        await copyContent(temp)
      }

      // 输出提示
      toast.success(
        copyMode.value === `html`
          ? `已复制 HTML 源码，请进行下一步操作。`
          : `已复制渲染后的内容到剪贴板，可直接到公众号后台粘贴。`,
      )
      window.dispatchEvent(new CustomEvent(`copyToMp`, {
        detail: {
          content: output.value,
        },
      }))
      editorRefresh()
      emit(`endCopy`)
    })
  }, 350)
}
```

本质上就是拷贝 HTML 元素。不过要求 style 都要内嵌。如果 style 不内嵌，或者有一些微信不支持的元素，格式就会错误。