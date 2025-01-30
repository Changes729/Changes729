> 参考资料
>
> - [how to use libavcodec/ffmpeg to find duration of video file](https://stackoverflow.com/questions/6451814/how-to-use-libavcodec-ffmpeg-to-find-duration-of-video-file)

# FFMEPG

```cpp
#include <libavformat/avformat.h>
...
av_register_all();
AVFormatContext* pFormatCtx = avformat_alloc_context();
avformat_open_input(&pFormatCtx, filename, NULL, NULL);
avformat_find_stream_info(pFormatCtx,NULL)
int64_t duration = pFormatCtx->duration;
// etc
avformat_close_input(&pFormatCtx);
avformat_free_context(pFormatCtx);
```

> The duration is in uSeconds, divide by AV_TIME_BASE to get seconds.