```sh
#!/bin/sh
#
# Grandstream HZ Git-Gerrit configure.
#
# Public values ######################################################
# Include script #####################################################
CURRENT_PATH=$(dirname $(readlink -f "$0"))

# Used functions #####################################################

# Start from this ####################################################
git config alias.rh "push origin HEAD:refs/for/master%r=rzhang@grandstream.cn,r=zhchhe@grandstream.cn,r=lmdu@grandstream.cn"
scp -p -P 29418 hqfu@192.168.120.246:hooks/commit-msg .git/hooks/

cat >.gitCommitTemplate.txt <<"EOF"
[[Bug/Trac XXXX] Bug Description]/[INTERNAL]/[NBF]
Cause: None
Solution: None
Fixed Version: None
Branch: None
EOF
git config commit.template .gitCommitTemplate.txt
```

### gerrit问题
1. Gerrit用ssh拉取代码报出问题
    * [Unable to negotiate with 10.216.90.129 port 29418: no matching key exchange method Their offer: diffie-hellman-group1-sha1](https://www.jianshu.com/p/41337dfbfcdb) 问题缘由当前系统的ssh默认不再支持gerrit的SHA-1加密方式。