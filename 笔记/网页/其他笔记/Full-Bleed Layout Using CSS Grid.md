> 文章来源：https://www.joshwcomeau.com/css/full-bleed/

# Full-Bleed Layout Using CSS Grid

## 关键词

- **Holy Grail layout**：圣杯形布局
  - [Holy Grail Layout with CSS Grid](https://www.geeksforgeeks.org/holy-grail-layout-with-css-grid/)



## 摘记

[研究表明](https://readings.design/PDF/the_elements_of_typographic_style.pdf)，理想的行长度约为65个字符。在罗马字母的背景下，45到85之间的任何地方都是可以接受的。

```css
.wrapper {
  display: grid;
  grid-template-columns:
    1fr
    min(65ch, 100%)
    1fr;
}
.wrapper > * {
  grid-column: 2; 
}
.full-bleed {
  width: 100%;
  grid-column: 1 / 4;
}
```

- `grid-template-columns`：根据下方具体数值，设置3列网格。

  - `1fr` 是灵活单位

- `.wrapper > *`：选中所有的元素；这里的作用就是把所有的元素设置为第二列

- `grid-column: 1 / 4;`：元素填充第一列到第四列。（全出血）

  - 也可以选择：

    ```css
    .full-bleed {
      grid-column: 1 / -1;
    }
    ```

    