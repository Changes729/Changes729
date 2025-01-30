# KiCAD 开源

| Project                                                      | Comment                                                      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [KiCad Footprints](https://gitlab.com/kicad/libraries/kicad-footprints) | Official KiCad Footprint Libraries for KiCad                 |
| [KiCad Footprint Generator](https://gitlab.com/kicad/libraries/kicad-footprint-generator) | creating kicad footprints using python scripts               |
| [KiCad Library utilities](https://gitlab.com/kicad/libraries/kicad-library-utils) | Some scripts for helping with library development            |
| [KiCad Library Convention](https://gitlab.com/kicad/libraries/klc) | [KLC Home](https://klc.kicad.org/)，社区公约                 |
| [kicad-website](https://gitlab.com/kicad/services/kicad-website) | [https://kicad.org](https://kicad.org/), this is the official website source for KiCad |
| [kicad-dev-docs](https://gitlab.com/kicad/services/kicad-dev-docs) | https://dev-docs.kicad.org/ website                          |
| [Forums](https://forum.kicad.info/)                          |                                                              |



## Contribute 

> Source：https://www.kicad.org/libraries/contribute/

**01 KLC (KiCad Library Convention)**

1. 作出贡献之前应该先熟悉 [KLC](https://klc.kicad.org/)
2. 有[工具](https://gitlab.com/kicad/libraries/kicad-library-utils)可以检查提交的内容是否规范



**02 Scripting Tools**

推荐使用脚本工具。

- [kicad-footprint-generator](https://gitlab.com/kicad/libraries/kicad-footprint-generator)
- [kicad-packages3D-generator](https://gitlab.com/kicad/libraries/kicad-packages3D-generator)



## Configuration

| 模块      | MAC 路径                                                     | Linux 路径 | 仓库                                           |
| --------- | ------------------------------------------------------------ | ---------- | ---------------------------------------------- |
| SYMBOL    | /Applications/KiCad/KiCad.app/Contents/SharedSupport/symbols/ |            | https://gitlab.com/Changes729/kicad-symbols    |
| FOOTPRINT | /Applications/KiCad/KiCad.app/Contents/SharedSupport/footprints/ |            | https://gitlab.com/Changes729/kicad-footprints |
| 3DMODEL   | /Applications/KiCad/KiCad.app/Contents/SharedSupport/3dmodels/ |            | https://gitlab.com/Changes729/kicad-packages3D |
| TEMPLATE  | /Users/fuhuaqian/Documents/KiCad/8.0/template/               |            |                                                |



## 私有化配置文档

- `Examples`：仅原理图的 Examples
- `Module`：上面的 `Template`
- `Project`：终端项目