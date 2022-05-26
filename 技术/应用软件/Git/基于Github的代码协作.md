# 基于 Github 的代码协作

## 需要准备的事情

- 安装 ssh（安装 git 的都会有这个工具）
- 命令行生成 ssh-key：`ssh-keygen`，然后不断回车即可。
  - Linux：`~/.ssh/`
  - Windows：`C:\Users\Administrator\.ssh`
- 有一个 `github` 的账户
- 点击 github 头像下拉菜单中的 `settings`
- 左边导航栏中找到`SSH and GPG keys`
- 将 ssh 目录下的 `id_rsa.pub` 内容复制，添加到 Github 中。
  - 这个 `.pub` 是公钥，你电脑中没有这个结尾的是私钥。保护好你的私钥！



## 配置远端仓库：`git remote add`

- 本地已经有一个项目
  - `git remote add origin git@xxx.git` 



## 同步远端仓库：`git remote update`

本地仓库事实上有一个远端仓库的缓存。如果远端仓库有变动，需要现在本地做处理进行同步。

这个操作往往会在提交前执行。如果本地分支与远端分支不同步的话，远端分支会拒绝。



## 变基：`git rebase -i [branch]`

本地与远端代码不同步，会被远端拒绝，这是因为远端的某个文件已经做出了更新，但由于本地代码还是老代码，所以贸然合入就会产生冲突。

此时需要先将本地将合入的代码，与远端代码进行变基，用于解决一些冲突。一般的操作是`git rebase -i origin/main`

如果没有冲突，变基完后会重新整理提交内容。但是如果有冲突，就要进行冲突处理。



## 变基冲突处理：`git rebase --continue`

冲突后，代码中会出现两个冲突的文本区，而且会用特殊的符号分割开来。

我们要做的就是选择我们要的，删除我们不要的。

这个步骤最好在带有 Git 工具的集成开发环境中执行。

解决全部冲突后，必须要再执行一次 `git rebase --continue`



## 提交到远程：`git push [remote] [local[:remote]]`

远程分支一般叫 `origin`，本地分支一般叫`main`，所以，一般提交到远程就是 `git push origin main`

可以参看[这里](https://www.runoob.com/git/git-push.html)。



## 拉取到本地 Review：`git fetch origin pull/PRId/head:LocalBranchName`

其中，`PRId`就是 `pull request` 的 `id`。