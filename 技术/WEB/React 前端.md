> 参考资料
>
> - [raphamorim](https://github.com/raphamorim)/[awesome-canvas](https://github.com/raphamorim/awesome-canvas)：A curated list of awesome HTML5 Canvas with examples, related articles and posts.
> - [Start a New React Project](https://react.dev/learn/start-a-new-react-project)
> - [Getting Started with React](https://nextjs.org/learn/react-foundations/getting-started-with-react)：这里介绍了如何在原生 HTML 中添加 React，一共三个库
> - [Building UI with Components](https://nextjs.org/learn/react-foundations/building-ui-with-components)：很简单的阐释了 React UI，需要注意的是 React Properties 只能由父级传递到子级。

# React 前端

## 框架

| Frameworks                                        | Static HTTP | APP  | Other |
| ------------------------------------------------- | ----------- | ---- | ----- |
| [Next.js](https://nextjs.org/learn/dashboard-app) |             |      |       |
| [Expo](https://expo.dev/)                         |             |      |       |



## 变量使用

```tsx
`Cool ${title}`
{title}
```



## State

```tsx
function HomePage() {
  // ...
  const [likes, setLikes] = React.useState(0);
 
  function handleClick() {
    setLikes(likes + 1);
  }
 
  return (
    <div>
      {/* ... */}
      <button onClick={handleClick}>Likes ({likes})</button>
    </div>
  );
}
```





## CSS

- [伪类](https://developer.mozilla.org/en-US/docs/Web/CSS/::before)： `::before`、`::after`

