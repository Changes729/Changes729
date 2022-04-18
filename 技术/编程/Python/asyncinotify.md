> *参考资料*
>
> - [asyncinotify](https://asyncinotify.readthedocs.io/en/latest/#)
>   - [Linux inotify man page](https://man7.org/linux/man-pages/man7/inotify.7.html)

# asyncinotify

**01 搭建虚拟 Python 环境**

````shell
python -m venv [asyncinotify_env]
source ./[asyncinotify_env]/bin/activate
````

**02 安装 asyncinotify**

```shell
pip install asyncinotify
```

**03 编写代码**

```python
#!/bin/python

from pathlib import Path
from asyncinotify import Inotify, Mask
import asyncio

async def main():
    # Context manager to close the inotify handle after use
    with Inotify() as inotify:
        # Adding the watch can also be done outside of the context manager.
        # __enter__ doesn't actually do anything except return self.
        # This returns an asyncinotify.inotify.Watch instance
        inotify.add_watch('/tmp', Mask.ACCESS | Mask.MODIFY | Mask.OPEN | Mask.CREATE | Mask.DELETE | Mask.ATTRIB | Mask.CLOSE | Mask.MOVE | Mask.ONLYDIR)
        # Iterate events forever, yielding them one at a time
        async for event in inotify:
            # Events have a helpful __repr__.  They also have a reference to
            # their Watch instance.
            print(event)

            # the contained path may or may not be valid UTF-8.  See the note
            # below
            print(repr(event.path))

loop = asyncio.get_event_loop()
try:
    loop.run_until_complete(main())
except KeyboardInterrupt:
    print('shutting down')
finally:
    loop.run_until_complete(loop.shutdown_asyncgens())
    loop.close()
```



## 事件整理

**移动事件（MOVED_FROM & MOVED_TO）**

```txt
eventName:       123
eventMask:       0x40    Mask.MOVED_FROM
eventCookie:     48793
eventPath:       tmp/234/123
====
eventName:       123
eventMask:       0x80    Mask.MOVED_TO
eventCookie:     48793
eventPath:       tmp/asd/123
```



**目录重命名事件（MOVED_FROM & MOVED_TO）**

```python
eventName:       234
eventMask:       0x40000040      Mask.ISDIR|MOVED_FROM
eventCookie:     48822
eventPath:       tmp/234
====
eventName:       123
eventMask:       0x40000080      Mask.ISDIR|MOVED_TO
eventCookie:     48822
eventPath:       tmp/123
```

虽然目录确实更新了，但是其下面的文件路径却是错误的

```python
eventName:       123
eventMask:       0x40    Mask.MOVED_FROM
eventCookie:     48834
eventPath:       tmp/234/123
====
eventName:       234
eventMask:       0x80    Mask.MOVED_TO
eventCookie:     48834
eventPath:       tmp/234/234
```



**目录/文件移出（Mask.ISDIR|MOVED_FROM）**

```python
eventName:       asd
eventMask:       0x40000040      Mask.ISDIR|MOVED_FROM
eventCookie:     48874
eventPath:       tmp/asd
```



**目录/文件删除（Mask.DELETE）**

```txt
eventName:       asd
eventMask:       0x200   Mask.DELETE
eventCookie:     0
eventPath:       tmp/345/asd
```



**文件修改（Mask.MODIFY）**

```txt
eventName:       asd
eventMask:       0x2     Mask.MODIFY
eventCookie:     0
eventPath:       tmp/345/asd
```

