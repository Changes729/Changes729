# Git与Github教程

## Github 是什么

Github是一个用于存放git仓库的互联网开源平台。

程序员不用自己搭建服务器，就可以以最低成本开始一个项目，并远程和团队成员进行协作。——Linux、VSCode



共创一个软件？（YES，AND）共创一个文档——一切皆文档（Linux 哲学）



从开源工具看到开源世界



## Git 教程

**00 安装Git**

> 还需要安装 vscode
>
> Mac 需要安装 homebrew：https://github.com/Homebrew/brew/releases
>
> 也需要安装 Python，安装一些教学需要的包：
>
> - ```py
>   brew install python-tk
>   ```
>
> - 下载 https://introcs.cs.princeton.edu/python/code/stdlib-python.zip
>
> - `pip install pygame`
>



**01 新建工程**



**02 Hello World**

> 使用 Python 编写



**03 Git详解**

- 新建（init）

- 查看（log）

- 暂存（add、stash）

- 分支（branch、checkout）

  ![Git V: An Optimal Git Branching Model | MergeBase](https://mergebase.com/blog/git-v-branching-model/images/git-V.webp)

- 配置Git 用户

  > git config --global user.ema"you@example.com"]
  > git config --global user.name ["Your Name"]

- 提交（commit）

- ~~合并（merge）~~

- 变基（rebase）:`git rebase -i [branch]`

- 恢复（reset）

- 删除



## Github 协作教程

**00 注册 Github**

注册Github并本地配置账号

SSH 注册

```sh
ls ~/.ssh #应该是没有内容的
ssh-keygen
cat ~/.ssh/id_rsa.pub
```



**01 同步工程**

- 获取分支（`git clone`）
- 分支（new、fork）
- 拉取（pull）：分支同步`git remote update`
- 问题（Issue）
- 推送（push）
- 检查（review）
- 添加远端仓库：`git remote add origin git@github.com:michaelliao/learngit.git`
- 删除



## 补充、不足与下一步

与Git、Github配合的软件

- vscode
- gitlens
- ~~github desktop~~
- gitbook

Github共创的不足之处

- 以代码工程为核心
- 异步协作

替代方案

- 以bug为核心：bugzilla
- 以信息交互为核心：discord
- 以数据为核心：分布式数据库与WebUI
