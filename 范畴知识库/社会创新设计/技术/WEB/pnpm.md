> 参考资料：
>
> - https://pnpm.io/
> - [`patch-packet`](https://www.npmjs.com/package/patch-package)
>   - [How To Replace npm Library With Your Own Implementation?](https://yumasoft.pl/how-to-replace-npm-library-with-your-own-implementation-pl/)
> - [How to fix vscode warning module not installed when using pnpm](https://stackoverflow.com/questions/71686054/how-to-fix-vscode-warning-module-not-installed-when-using-pnpm)

# pnpm

起因是这样的，我需要修改一些依赖库，以实现一些功能，但是我又不想自己建立一个 新的库，所以就找到了 [`patch-packet`](https://www.npmjs.com/package/patch-package)，但是这个库需要 `package-lock.json` ，然后我基本上都使用 `cnpm` 的，这玩意儿又无法产生文件，而 `npm` 又经常出问题，这个时候找到 `pnpm` 自然支持这些功能。



## 安装

可以 `npm -g pnpm` ，我使用 `archlinux pnpm` 



## VSCode

还有一点是，VSCode 在使用 pnpm 之后需要更新包管理，才能正常识别。