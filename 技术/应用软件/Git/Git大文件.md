> 参考资料：
>
> - [使用 Git 存储大文件](https://cloud.tencent.com/developer/article/1938225?cps_key=1d358d18a7a17b4a6df8d67a62fd3d3d)
> - [git-lfs](https://github.com/git-lfs)/**[git-lfs](https://github.com/git-lfs/git-lfs)**

# Git 大文件

因为 Git 不会将大文件拆分，而会永远存在git仓库中，这会导致git文件巨大。git lfs 在提交时，会将各个分支的大文件统一提交到 `LFS store` 中，当我们拉取分支时，LFS会从存储器中仅下载对应分支的大文件数据。