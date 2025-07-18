> Ver 2.18

# python 库更新办法

代码仓库：https://gitee.com/nanomics/luomi-g1-shaker-and-magnetic/tree/dev/

选择 dev 分支。右边有个下载按钮，下载压缩包。



然后把下载下来的 luomi-g1-shaker-and-magnetic-dev.zip 放到工作站上。

unzip 解压文件夹

然后命令行打开文件夹 `cd luomi-g1-shaker-and-magnetic`

编译包：`python3 -m build`

安装编译包：`python3 -m pip install --force-reinstall dist/nanomics_modules-0.2.2-py3-none-any.whl`

