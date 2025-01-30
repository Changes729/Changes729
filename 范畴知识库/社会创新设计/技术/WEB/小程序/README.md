> 参考资料：
>
> - [小程序代码构成](https://developers.weixin.qq.com/miniprogram/dev/framework/quickstart/code.html#JSON-%E9%85%8D%E7%BD%AE)

# 小程序

## 小程序代码构成

**01 JSON 配置**

**02 WXML 模板**

其中 `WXML` 充当的就是类似 `HTML` 的角色。小程序的 `WXML` 用的标签是 `view`, `button`, `text` 等等，这些标签就是小程序给开发者包装好的基本能力，我们还提供了地图、视频、音频等等组件能力。

WX开发是顺应 MVVM 开发模式的。

- [XML - 事件](https://developers.weixin.qq.com/miniprogram/dev/framework/view/wxml/event.html)

**03 WXSS 样式**



## 小程序的宿主环境

整个小程序只有一个 App 实例。

`Page` 是一个页面构造器，这个构造器就生成了一个页面。在生成页面的时候，小程序框架会把 `data` 数据和 `index.wxml` 一起渲染出最终的结构，于是就得到了你看到的小程序的样子。

在渲染完界面之后，页面实例就会收到一个 `onLoad` 的回调，你可以在这个回调处理你的逻辑。

- [小程序的组件](https://developers.weixin.qq.com/miniprogram/dev/component/)
- [小程序的API](https://developers.weixin.qq.com/miniprogram/dev/framework/app-service/api.html)
- [小程序的协同工作与发布](https://developers.weixin.qq.com/miniprogram/dev/framework/quickstart/release.html#%E5%8F%91%E5%B8%83%E4%B8%8A%E7%BA%BF)：介绍了合作流程，发布上线过程和运营数据接入办法。



## 配置小程序

- [小程序全局配置](https://developers.weixin.qq.com/miniprogram/dev/reference/configuration/app.html)：小程序根目录下的 `app.json` 文件用来对微信小程序进行全局配置，决定页面文件的路径、窗口表现、设置网络超时时间、设置多 tab 等
- [小程序页面配置](https://developers.weixin.qq.com/miniprogram/dev/reference/configuration/page.html)：每一个小程序页面也可以使用同名 `.json` 文件来对本页面的窗口表现进行配置



## 小程序框架

- 场景值：场景值用来描述用户进入小程序的路径。（从哪里进来的，比如公众号、APP分享）
- JS部分：
  - app.js：[App 参考文档](https://developers.weixin.qq.com/miniprogram/dev/reference/api/App.html)
  - page.js：[Page 参考文档](https://developers.weixin.qq.com/miniprogram/dev/reference/api/Page.html) 
    - [behaviors](https://developers.weixin.qq.com/miniprogram/dev/framework/custom-component/behaviors.html)：页面可以引用 behaviors 。 behaviors 可以用来让多个页面有相同的数据字段和方法。
    - [`Component` 构造器](https://developers.weixin.qq.com/miniprogram/dev/framework/custom-component/component.html)：对于复杂的页面，可以使用 `Component` 构造器来构造页面。 
  - [生命周期](https://developers.weixin.qq.com/miniprogram/dev/framework/app-service/page-life-cycle.html)
  - [页面路由](https://developers.weixin.qq.com/miniprogram/dev/framework/app-service/route.html)
  - [API](https://developers.weixin.qq.com/miniprogram/dev/framework/app-service/api.html#API)
- View部分：
  - 数据绑定：单个数据、列表数据、条件渲染
  - 模版
  - [事件系统](https://developers.weixin.qq.com/miniprogram/dev/framework/view/wxml/event.html)：冒泡事件、双向绑定
  - [组件文档](https://developers.weixin.qq.com/miniprogram/dev/component/)


