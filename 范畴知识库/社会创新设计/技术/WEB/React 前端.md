> 参考资料
>
> - [raphamorim](https://github.com/raphamorim)/[awesome-canvas](https://github.com/raphamorim/awesome-canvas)：A curated list of awesome HTML5 Canvas with examples, related articles and posts.
> - [Start a New React Project](https://react.dev/learn/start-a-new-react-project)
> - [Getting Started with React](https://nextjs.org/learn/react-foundations/getting-started-with-react)：这里介绍了如何在原生 HTML 中添加 React，一共三个库
> - [Building UI with Components](https://nextjs.org/learn/react-foundations/building-ui-with-components)：很简单的阐释了 React UI，需要注意的是 React Properties 只能由父级传递到子级。
> - [使用 Promise](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Using_promises)：一种很好的事务管理办法
> - [React Router](https://reactrouter.com/)：客户端路由，防止过度请求服务器
>   - [一种 hash router 混合使用的办法](https://codesandbox.io/p/sandbox/suspicious-feather-09ijf?file=%2Fsrc%2Findex.js%3A4%2C1)
> - [Implementing CSV Data Export in React Without External Libraries](https://dev.to/graciesharma/implementing-csv-data-export-in-react-without-external-libraries-3030)
> - [How can I go to the implementation of something instead of its TypeScript declaration?](https://stackoverflow.com/questions/46893661/how-can-i-go-to-the-implementation-of-something-instead-of-its-typescript-declar)：F12 不会跳转到 源代码的问题，除非源代码库支持了一个文件，但是很多开源代码并没有。

# React 前端

## 框架

| Frameworks                                        | Static HTTP | APP  | Other |
| ------------------------------------------------- | ----------- | ---- | ----- |
| [Next.js](https://nextjs.org/learn/dashboard-app) |             |      |       |
| [Expo](https://expo.dev/)                         |             |      |       |
| Vue                                               |             |      |       |



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
- [`list-style-type`](https://developer.mozilla.org/en-US/docs/Web/CSS/Reference/Properties/list-style-type)：列表的现实，可以设置为 `none`



## 特性说明

**01 defaultProps**

```js
    const MyFunctionalComponent = (props) => {
      return <div>Hello, {props.name}!</div>;
    };

    MyFunctionalComponent.defaultProps = {
      name: 'Stranger'
    };
```

应该变更为：

```js
    const MyFunctionalComponent = ({ name = 'Stranger' }) => {
      return <div>Hello, {name}!</div>;
    };
```



**02 PropTypes**

`PropTypes` 可以通过 npm 下载，其用于 React JS 开发中的类型判定。

```sh
   npm install prop-types
```

```js
import PropTypes from 'prop-types';

function Gallery({ photos, onClick, margin = 8, onLoad }) {
    ......
}
    
Gallery.propTypes = {
  photos: PropTypes.array,
  margin: PropTypes.number,
  onClick: PropTypes.func,
  onLoad: PropTypes.func,
};
```

转用 TypeScript 会不用依赖：

```tsx
import React from 'react';

interface MyComponentProps {
  name: string;
}

function MyComponent(props: MyComponentProps) {
  return <div>Hello, {props.name}!</div>;
}

export default MyComponent;
```



**03 [memo](https://zh-hans.react.dev/reference/react/memo)**

`memo` 允许你的组件在 props 没有改变的情况下跳过重新渲染。

使用 `memo` 将组件包装起来，以获得该组件的一个 **记忆化** 版本。通常情况下，只要该组件的 props 没有改变，这个记忆化版本就不会在其父组件重新渲染时重新渲染。但 React 仍可能会重新渲染它：记忆化是一种性能优化，而非保证。

> [跳过组件的重新渲染](https://zh-hans.react.dev/reference/react/useMemo#skipping-re-rendering-of-components)：这个部分充分说明了 usememo 的价值。
>
> 类似的还有 [useCallback](https://zh-hans.react.dev/reference/react/useCallback#usage)，如果说 memo 是值对象，那么 callback 就是函数对象了。



**04 [ref 操作 DOM](https://zh-hans.react.dev/learn/manipulating-the-dom-with-refs)**

有时你可能需要访问由 React 管理的 DOM 元素 —— 例如，让一个节点获得焦点、滚动到它或测量它的尺寸和位置。在 React 中没有内置的方法来做这些事情，所以你需要一个指向 DOM 节点的 **ref** 来实现。

```js
import { useRef } from 'react';

export default function Form() {
  const inputRef = useRef(null);

  function handleClick() {
    inputRef.current.focus();
  }

  return (
    <>
      <input ref={inputRef} />
      <button onClick={handleClick}>
        聚焦输入框
      </button>
    </>
  );
}
```



**05 [useEffect](https://zh-hans.react.dev/learn/synchronizing-with-effects)**

useEffect 是一个在 React 渲染完毕之后调用的函数。比如某个元素在渲染时还没有加载完毕，我们就不能去控制它，但是又希望能在其每次渲染完毕时，去重新设置它的状态。

这个时候就需要 useEffect，它一方面会在每次 React 对象渲染完毕后调用，同时，也可以设置过滤器。

最后要注意 useEffect 可能会造成死循环。

> `useLayoutEffect` 是 [`useEffect`](https://zh-hans.react.dev/reference/react/useEffect) 的一个版本，在浏览器重新绘制屏幕之前触发。
>
> 比如需要重新计算对象的大小。



**06 customElements.define**

自定义类型，名称必须要有横线，这是为了[防止和系统类型冲突](https://dom.spec.whatwg.org/#valid-element-local-name)。

另外，类型在 construct 中并没有加载完全，要等到 `connectedCallback` 才有 `attribute` 。所以，像一些 style 的初始化，不能放在 `construct` 中。
