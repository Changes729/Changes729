# 标签描述与移动

—— 什么是标签描述？

如果标签是文件的正形，那么标签描述就是文件结构，是负形。标签描述不包含具体的文件内容，它只是文件存在的环境。文件有自然解析器。但是文件的组合逐渐会形成更大的组合文件，对这样的组合文件进行描述，就是标签描述。

标签描述在具体文件中会形成标签。



## 标签描述

前端 TS，可以通过这样的方式实现标签描述。

```ts
type Describe = {
  topology?: Record<string, Describe>;
};

const frameworkDesc: Describe = {
  topology: {
    api: {},
    web: {},
  },
};

const tsProject: Describe = {
  topology: {
    "tsconfig.json": {},
    "package.json": {},
    "src": frameworkDesc,
  },
};

console.log(JSON.stringify(tsProject, null, 2))
```

文件可以使用 yaml 的模块功能实现标签描述（不支持模块化）：

```yaml
# 1. 定义一个模板 (锚点)
base_config: &base
  api_version: "v1"
  timeout: 30

# 2. 引用并覆盖 (别名)
services:
  web:
    <<: *base
    port: 80
  api:
    <<: *base
    port: 8080
```

golang 使用 Viper 库。



## 标签

标签就是 `类型-内容` 。

TS 中，标签这样定义：

```ts
type token = {
    key: ID,
    value: string
};
```

一般，对外只展示 `value`，程序员可以根据 ID 判断具体是哪个 `desc` 