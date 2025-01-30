> 参考资料
>
> - [PhantomJS not found on PATH](https://github.com/xhlwill/blog/issues/11)：网络问题
> - [npm ,yarn 更换使用国内镜像源，阿里源，清华大学源](https://zhuanlan.zhihu.com/p/623547625)

# NodeJS

## NodeJS 网页前端

```sh
# create a front-end project
npm install -g create-react-app 
create-react-app my-app

# package front-end
npm run build
```

```sh
# use this.
yarn create react-app app
```



## React 打包

默认的话，可以直接 `yarn build`，当然可以先 `yarn eject` 然后再 `yarn build` 打包。

后者开启了 Webpack，可以安装插件 `html-webpack-inline-source-plugin`

```sh
yarn add dev html-webpack-inline-source-plugin@1.0.0-beta.2
```

> 说是这个插件[没有维护](https://markdowner.net/skill/215869806883246080)了，然后[文件配置](https://stackoverflow.com/questions/51949719/is-there-a-way-to-build-a-react-app-in-a-single-html-file)可以看这里。



### 其他打包器

- Webpack（已经过时，请选用 esbuild）
- [esbuild](https://esbuild.github.io/)：[esbuild-loader-examples](https://github.com/privatenumber/esbuild-loader-examples)



### electron 打包

```sh
npm install --save-dev @electron-forge/cli
npx electron-forge import
npm run make
```



## 一些工具

- [nodejs](https://github.com/nodejs)/**[node-gyp](https://github.com/nodejs/node-gyp)**：`npm install -g node-gyp`
- `npm install electron --verbose`
- cnpm：`npm install cnpm -g --registry=https://registry.npmmirror.com`
- pm2
  - 日志位置：`$HOME/.pm2/logs/XXX-err.log`
  - 查看日志：`pm2 logs`
- Puppeteer：配合 chrome headless 自动化测试工具
  - [Headless Chrome](https://www.bilibili.com/video/BV1At41147EQ/?spm_id_from=333.337.search-card.all.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：可以实现截图，jpeg、PDF



### 中国源

```text
yarn config set registry https://registry.npmmirror.com
```



## 一些库

[Swiper](https://swiperjs.com/)：滑动窗口组件

[Bootstrap](https://getbootstrap.com/)：快速构建响应式网站

[Animejs](https://animejs.com/)：网页动画库

**[esbuild-sass-plugin](https://github.com/glromeo/esbuild-sass-plugin)**

[mdx](https://github.com/mdx-js/mdx)：markdown viewer

[sandpack](https://github.com/codesandbox/sandpack)：code editor

[View Transitions API](https://developer.chrome.com/docs/web-platform/view-transitions)：视图转换

[Algolia](https://www.algolia.com/)：搜索

[Feather Icons](https://feathericons.com/)：轮廓图标

[icegl-three-vue-tres](https://github.com/hawk86104/icegl-three-vue-tres)：3d模型显示器

[WebChat](https://github.com/molvqingtai/WebChat)：网页聊天



## 一些问题

- `electron` 在安装的时候出现了 DNS 错误的情况。这是因为 `yarn` 配置内使用了过时的阿里DNS地址。[参考这里](https://blog.csdn.net/q1003675852/article/details/138493725?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522af3b264f3643e4a5d473977afc41e175%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=af3b264f3643e4a5d473977afc41e175&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-138493725-null-null.142^v101^pc_search_result_base8&utm_term=Hostname%2FIP%20does%20not%20match%20certificates%20altnames%3A%20Host%3A%20npm.taobao.org.&spm=1018.2226.3001.4187)
  - `yarn config list`
  - `yarn config delete electron_mirror`