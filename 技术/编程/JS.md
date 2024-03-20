> *参考资料*
>
> [MDN Web Docs](https://developer.mozilla.org/zh-CN/)：[Github](https://github.com/mdn/)
>
> - [WebAPI Document](https://developer.mozilla.org/zh-CN/docs/Web/API/Document) 
> - [WebAPI EventTarget](https://developer.mozilla.org/zh-CN/docs/Web/API/EventTarget)
>
> [How do I POST a x-www-form-urlencoded request using Fetch?](https://stackoverflow.com/questions/35325370/how-do-i-post-a-x-www-form-urlencoded-request-using-fetch)

# JS

### POST

```js
var xhr = new XMLHttpRequest();
xhr.open("POST", yourUrl, true);
xhr.setRequestHeader('Content-Type', 'application/json');
xhr.send(JSON.stringify({
    value: value
}));
```

```js
fetch('https://example.com/login', {
    method: 'POST',
    headers:{
      'Content-Type': 'application/x-www-form-urlencoded'
    },    
    body: new URLSearchParams({
        'userName': 'test@gmail.com',
        'password': 'Password!',
        'grant_type': 'password'
    })
});
```

```js
var details = {
    'userName': 'test@gmail.com',
    'password': 'Password!',
    'grant_type': 'password'
};

var formBody = [];
for (var property in details) {
  var encodedKey = encodeURIComponent(property);
  var encodedValue = encodeURIComponent(details[property]);
  formBody.push(encodedKey + "=" + encodedValue);
}
formBody = formBody.join("&");

fetch('https://example.com/login', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
  },
  body: formBody
})
```



## 事件

- [DOMContentLoaded](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/DOMContentLoaded_event)：当初始的 **HTML** 文档被完全加载和解析完成之后，**`DOMContentLoaded`** 事件被触发，而无需等待样式表、图像和子框架的完全加载。



## 其他

- [What is a blob URL and why it is used?](https://stackoverflow.com/questions/30864573/what-is-a-blob-url-and-why-it-is-used)

