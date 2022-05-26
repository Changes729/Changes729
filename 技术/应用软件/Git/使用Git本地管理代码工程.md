# 使用 Git 本地管理工程

## 需要准备的事情

- [安装 Git](https://git-scm.com/)
- 设置 git 信息
  - `git config --global user.name "xxx"`
  - `git config --global user.email "xxx"`
- **本地已有项目，使用 Git 管理**
  - 初始化 git：`git init`
- 云上有项目，使用 Git 下载
  - HTTPS：`git clone https://xxx.git`
  - Git：`git clone git@xxx:xxx.git`

到此为止你已经有一个使用 git  管理的工程了。接下来我们将开始使用 Git 管理我们的工程。



## 使用 Git

### 暂存代码：`git add` & `git reset` & `git checkout -- [file]`

我们很多时候会想要在代码里做一些 “**尝试**” ，比如重新写一个算法，又或者添加几个 `printf` 几个打印日志的东西帮助我们理解代码。

但是前者可能会**写错**，可能会**返工**。后者可能根本不需要，但是**要删除的部分又非常多、非常零碎**。

此时，我们就可以使用 `git add` 、 `git reset` 、 `git checkout -- [file]`这一套工具来帮助我们对代码进行管理。

我们首先要了解我们的 Git 工程有三种状态：文件**修改状态**、文件**暂存状态** 以及 **提交入库**状态。

- **修改状态**：我们任意增删改一个文件，就会让这个文件进入修改状态。
- **暂存状态**：我们使用 `git add`，就会让这个文件的变化**暂存**。
- **提交入库**：我们使用 `git commit`，就会让这个变化永远记录下来。

基于此，我们可以很简单的理解暂存代码的三个命令：

- `git add`：暂存代码更新的内容。
- `git reset`：取消暂存。
- `git checkout -- [file]`：取消修改。



## 版本更新：`git commit` & `git reset`

开发者应该有一个明确的开发计划。有时候我们以及做了足够多的大量的更改，上面的暂存已经几乎不够用了。

此时我们可以使用 `git commit`，提交一个 “**应该永远不会变动的内容**”（虽然未来往往会再进行修改）。这有个好处就是，团队内分配模块进行开发，每个人只需要写好自己模块的内容，提交即可。

当然，如果提交出错了，可以使用 `git reset HEAD^ [file]`，将某个文件更新到之前的版本。或者`git reset --soft HEAD^`，可以将上一个提交取消。



这里要注意的是版本提交的信息是有规范的，规范化的好处是未来追溯会比较方便，易于处理。这里给一个开源 commit 模板：

```txt
[BUG] something...

Mode: ...
Cause: ...
Solution: ...
```

这个模板，将修改的 Bug 用头标记出来，同时在后续部分提供 Mode、Cause、Solution 三个部分分别对应：模块、修改原因和修改方法。

提交内容虽然是规范，但小规模开发并不需要严格遵守上述模板内容，为未来的内容追溯，为代码出错提供良好的回退能力，才是commit的核心。



## 版本切换：`git log` & `git checkout`

有时候我们想回到过去看看。

此时我们可以用 `git log` 去找过去的提交，当我们找到后，提交上有一个 `Commit-ID`

```txt
commit 3ad50e0c29afa33377cf4f02525799231b39d4a5 (HEAD)
```

然后我们就可以使用`git checkout 3ad50e0c29afa33377cf4f02525799231b39d4a5`回到这个版本。



## 版本管理：`git branch`

有时候我们会在原版本基础上，分化出一些特殊的应用场景。

此时我们可以使用`git branch [branch_name]`，在当前进度上新建一个分支。然后使用 `git checkout [branch_name]` 切换过去。这样我们就可以实现一份代码，对多份项目工程了。

可以使用 `git branch -d` 将某个分支删除。但这是个危险行为！一旦删除后可能再也找不回来了。



## 忽略文件

在项目根目录下，新建文件 `.gitignore`。



## 其他内容

命令行操作 git 有时候会比较麻烦，可以使用第三方工具帮助操作：

- [Source Tree](https://www.sourcetreeapp.com/)

更多工具可以看[这篇文章](https://segmentfault.com/a/1190000022736553)。

