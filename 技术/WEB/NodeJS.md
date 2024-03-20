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



### 中国源

```text
yarn config set registry https://registry.npmmirror.com
```

