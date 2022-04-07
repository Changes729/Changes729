> *参考资料*
>
> - [Creating a React App… From Scratch.](https://medium.com/@JedaiSaboteur/creating-a-react-app-from-scratch-f3c693b84658)：从头开始打造工具链
> - **using ES6 Module syntax**：
>   - [Getting Unexpected Token Export](https://stackoverflow.com/questions/38296667/getting-unexpected-token-export)：`export`无法解析
>   - [Solve - __dirname is not defined in ES module scope](https://bobbyhadz.com/blog/javascript-dirname-is-not-defined-in-es-module-scope)
>   - [记录 Webpack 从版本 4 更新至 5 所遇到的问题](https://quickapp.lovejade.cn/record-issues-encountered-with-webpack-update-from-version-4-to-5/)
>
> 实践时常约：<u>3小时</u>（包括查阅资料，和解决意外问题）

# React

**初始化前端项目**：`npm init`或者`yarn init`。

**创建工程文件**：`mkdir public src`

- *public：index.html*

  ```html
  <!-- sourced from https://raw.githubusercontent.com/reactjs/reactjs.org/master/static/html/single-file-example.html -->
  <!DOCTYPE html>
  <html>

  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>React Starter</title>
  </head>
  <!-- NOTICE！ 这是React会"勾住"（hook into）的源（root） -->
  <body>
    <div id="root"></div>
    <!-- NOTICE！ 这是我们将构建React App的地方 -->
    <noscript>
      You need to enable JavaScript to run this app.
    </noscript>
    <script src="../dist/bundle.js"></script>
  </body>

  </html>
  ```

- *src*：安装完React后修改。

**安装React**：`npm install react@16.5.2 react-dom@16.5.2`

- **react**：React主包。

- **react-dom**：React DOM表解析器。

- *src*：

  ```js
  import React from "react";
  import ReactDOM from "react-dom";
  import App from "./App.js";
  
  // 在HTML中寻找 id == root的位置并加载 <App />
  ReactDOM.render(<App />, document.getElementById("root"));
  ```

  - *App.js*：

    ```js
    import React, { Component } from "react";
    import "./App.css";

    class App extends Component {
      render() {
        return (
          <div className="App">
            <h1>hello, world!</h1>
          </div>
        );
      }
    }

    export default App;
    ```

  - *App.css*：

    ```css
    .App {
      margin: 1rem;
      font-family: Arial, Helvetica, sans-serif;
    }
    ```

**安装Babel语言翻译器**：`npm install --save-dev @babel/core@7.1.0 @babel/cli@7.1.0 @babel/preset-env@7.1.0 @babel/preset-react@7.0.0`。@n.n.n是版本号，如果我们没有**特殊需求**，**请最好选择一个稳定的版本号进行开发**。

- **@babel/core**：这是最主要的babel软件包，我们需要它来翻译（transformations）我们的代码。

- **@babel/cli**：它提供了`babel-cli`工具，使得我们可以通过命令行编译文件（compile files）。

- **@babel/preset-env & @babel/preset-react**：在本教程中，他们都是用来翻译（transform）不同风格（specific flavors）代码的预设（preset）。

  - **preset-env**：它允许我们将新的ES6语法（ES6+）转化为传统的JS写法
  - **preset-react**：它允许我们将JSX语法转化为传统JS写法

- *.babelrc*：用来告诉babel使用哪些预设（presets）

  ```json
  {
    // @babel/env: support ES6+ to traditional JS.
    // @babel/preset-react: support react JSX to traditional JS.
    "presets": ["@babel/env", "@babel/preset-react"]
  }
  ```

**安装Webpack打包器**：`npm install --save-dev webpack@4.19.1 webpack-cli@3.1.1 webpack-dev-server@3.1.8 style-loader@0.23.0 css-loader@1.0.0 babel-loader@8.0.2`。

- **webpack & webpack-cli**：webpack主包，以及其命令行工具。

- **webpack-dev-server**：webpack开发服务器，我们用它来验证我们的开发服务器，同时使用热加载（Hot Module Replacement, HMR）来方便我们修改后看到效果。

- **style-loader & css-loader**：CSS（Cascading Style Sheets，层叠样式表）加载器。

- *webpack.config.js*：

  ```js
  const path = require('path');
  const webpack = require("webpack");

  module.exports = {
    entry: "./src/index.js",                              // 从 `./src/index.js` 开始打包。`./src/index.js` 是主界面入口。
    mode: "development",                                  // mode: working in development mode. This saves us from having to add a mode flag when we run the development server.
    module: {
      rules: [
        // transforming our ES6 and JSX syntax.
        {
          test: /\.(js|jsx)$/,                            // include all .js and .jsx.
          exclude: /(node_modules | bower_components)/,   // exclude all node_modules or bower_components directories.
          loader: "babel-loader",                         // include babel, use babel in webpack.
          options: { presets: ["@babel/env"] },           // include env.
        },
        // processing CSS.
        {
          test: /\.css$/,
          use: ["style-loader", "css-loader"],            // css-loader 需要 style-loader 才能工作.
        },
      ],
    },
    resolve: { extensions: ["*", ".js", ".jsx"] },        // specify which extensions Webpack will resolve
    output: {
      path: path.resolve(__dirname, "dist/"),
      publicPath: "/dist/",
      filename: "bundle.js",
    },
    devServer: {
      contentBase: path.join(__dirname, "public/"),
      port: 3000,
      publicPath: "http://localhost:3000/dist/",
      hotOnly: true,
    },
    plugins: [new webpack.HotModuleReplacementPlugin()],
  };

  ```

- 在`package.json`中的`script`段添加`start`操作：

  ```js
  "scripts": {
    "start": "webpack-dev-server --mode development"
  }
  ```

  运行`npm run start`或者`yarn start`.

**支持HMR**：`npm install react-hot-loader`

- 修改App.js：

  ```jsx
  import React, { Component} from "react";
  import {hot} from "react-hot-loader";
  import "./App.css";
  
  class App extends Component{
    render(){
      return(
        <div className="App">
          <h1> Hello, World! </h1>
        </div>
      );
    }
  }
  
  export default hot(module)(App);
  ```
