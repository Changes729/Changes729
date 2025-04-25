> 参考资料：
>
> - [asciinema-player](https://github.com/asciinema/asciinema-player)
>   - [npm package](https://docs.asciinema.org/manual/player/quick-start/)
> - [asciinema recorder](https://docs.asciinema.org/manual/cli/)

# [asciinema](https://github.com/asciinema)

- `asciinema rec [demo.cast]`：录制
- `asciinema play [demo.cast]`：播放



**Node 环境使用**

```js
import * as AsciinemaPlayer from 'asciinema-player';
AsciinemaPlayer.create('/demo.cast', document.getElementById('demo'));
```

