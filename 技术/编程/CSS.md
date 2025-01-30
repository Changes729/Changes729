> 参考资料：
>
> - [em, px, pt, cm, in](https://www.w3.org/Style/Examples/007/units.zh_CN.html)
>
> - CSS Animation
>   - https://cssanimation.io/
> - [CSS Loaders](https://css-loaders.com/)：有很多 CSS 案例
> - [CSS 网格区块详解](https://ishadeed.com/article/css-grid-area/#header-layout)

# CSS

`1in = 2.54cm = 25.4mm = 72pt = 6pc`

绝对单位 (`cm`,`mm`, `in`, `pt` and `pc`) 

相对性单位(`em`, `ex`)

`em`仅仅是字体大小。在2英寸的元素中1em就是2英寸。 利用`em`表达大小的话，就代表它们是与字体大小相关。如果使用者有较大的字体(例如在大屏幕上)，或者是较小的字体(例如手持装置)，它的大小会保持比例。 



## 响应式布局

margin-top和padding-top为百分比时是相对于父元素的width计算的；

另一种技巧是将padding应用于**伪元素**而不是box本身。你浮动伪元素，所以里面的内容可以很好地在里面，然后清除浮动。

```scss
.aspect-ratio-box {
  background: white;
}
.aspect-ratio-box::before {
  content: "";
  width: 1px;
  margin-left: -1px;
  float: left;
  height: 0;
  padding-top: 591.44px / 1127.34px * 100%;
}
.aspect-ratio-box::after { /* to clear float */
  content: "";
  display: table;
  clear: both;
}
```

[font-size：Xvw](https://stackoverflow.com/questions/77606758/how-does-viewport-width-work-with-font-size-in-css)：如果您设置font-size：4vw;，这意味着字体大小将是视口宽度的4%

还能实现参数化css布局：

```html
<div style="--aspect-ratio:815/419;">
</div>

<div style="--aspect-ratio:16/9;">
</div>

<!-- even single value -->
<div style="--aspect-ratio:1.4;">
</div>
```

```scss
[style*="--aspect-ratio"] > :first-child {
  width: 100%;
}
[style*="--aspect-ratio"] > img {  
  height: auto;
} 
@supports (--custom:property) {
  [style*="--aspect-ratio"] {
    position: relative;
  }
  [style*="--aspect-ratio"]::before {
    content: "";
    display: block;
    padding-bottom: calc(100% / (var(--aspect-ratio)));
  }  
  [style*="--aspect-ratio"] > :first-child {
    position: absolute;
    top: 0;
    left: 0;
    height: 100%;
  }  
```

- CSS [*attribute**=*value*] Selector, [Attribute selectors](https://developer.mozilla.org/en-US/docs/Web/CSS/Attribute_selectors)
- [CSS selectors](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_selectors)
  - `>` ([Child combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Child_combinator))
- [@supports](https://developer.mozilla.org/en-US/docs/Web/CSS/@supports)
- [Custom properties (--*): CSS variables](https://developer.mozilla.org/en-US/docs/Web/CSS/--*)



现在支持 `aspect-ratio:16/9` 了



## 文本相关

- `text-wrap:balance;` 字体平衡换行