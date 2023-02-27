> 参考资料
>
> - [[微信读书] 刘歧 赵文杰 ffmpeg从入门到精通](https://weread.qq.com/book-detail?type=1&senderVid=13954449&v=587329805e2f7c587db316ekcfc32da010cfcd208495488)
> - [FFmpeg Documentation](https://ffmpeg.org/documentation.html)
>   - `-y`：覆盖输出文件（yes）
>   - `-b`：修改比特率 bitrate，通常后面跟的`:a`这种，`a` 是 Audio，`v`是 Video，`s`是 Subtitle。
>   - `-auto-alt-ref 1`：启用双通道缓冲区编码优化。默认是关闭的。
> - [使用FFmpeg添加、删除、替换和提取视频中的音频](https://mp.weixin.qq.com/s/SFpdHo1IT3XA4xDm_XuA-g)
> - [利用FFmpeg进行音频降噪](https://guohongyi.com/2020/09/28/%E5%88%A9%E7%94%A8FFmpeg%E8%BF%9B%E8%A1%8C%E9%9F%B3%E9%A2%91%E9%A2%84%E5%A4%84%E7%90%86/#%E5%85%B3%E4%BA%8Effmpeg)
> - [如何使用FFmpeg精确剪辑视频](https://juejin.cn/post/6952762128600317966)：讲到了一个视频编码等问题，就是IBP帧的问题。

# FFmpeg

工具构成
- ffmpeg：ffmpeg本体，包含包格式（AVFormat）、编解码（AVCodec）、视频滤镜（AVFilter）、视频图像转换（swscale）以及音频计算（swresample）
- ffprobe：多媒体分析器
- ffplay：多媒体播放器，有许多针对开发者的视频显示功能

常用功能：
- [视频采集](https://trac.ffmpeg.org/wiki/Capture/Desktop)
  - 通过[x11grab](https://ffmpeg.org/ffmpeg-devices.html#x11grab)捕获视频：`ffmpeg -video_size 1024x768 -framerate 25 -f x11grab -i :0.0+100,200 v-out.mp4`
    - select_region：可以用鼠标选择截屏区域`-select_region 1`
    - draw_mouse：可以选择是否录制进鼠标
    - follow_mouse：截屏区域跟随鼠标`-follow_mouse centered` 或 `-follow_mouse 100`(pixels)
    - show_region：显示捕获屏幕的边界`-show_region 1`
    - region_border：设置边界的边框`-region_border 3`
    - window_id：截取固定窗口，此窗口需要通过传入ID实现定位，窗口ID可以通过`xwininfo`的`-tree`或`-root`确定`-window_id 0`
    - video_size：确定屏幕录制的大小
    - grab_x & grab_y：确定可拖动的位置大小
  - 同时录制视频和音频：
    - `ffmpeg -video_size 1024x768 -framerate 25 -f x11grab -i :0.0 -f pulse -ac 2 -i default output.mkv`
  - 通过framebuffer捕获视频：`ffmpeg -framerate 30 -f fbdev -i /dev/fb0 output.mp4`
  
- 音频采集

  - 通过pulse录音：`ffmpeg -f pulse -i default -t 10 /tmp/pulse.wav`
    - sample_rate：设置音频采样率
    - channels：设置音频通道
    - frame_size：设置帧宽度，每一帧音频用多大的数据去量化
  - 通过ALSA录音：*（失败，机子无法读取音频设备）*

- 视频裁剪

  - 使用`-ss`定位视频，通过`-to 00:02:00`确定截取时长，并通过`-c copy -copyts`复制新视频。音频剪辑同理。

    `ffmpeg -ss 00:01:00 -i video.mp4 -to 00:02:00 -c copy -copyts cut.mp4`
    
    ` ffmpeg -ss 00:00:11.04 -accurate_seek -i 造物节.mp4 cut.mp4`，由于视频帧的存在，如果直接剪辑可能导致剪掉了I帧，导致视频错乱，所以需要去掉 `-c copy` 重新编码，这样虽然比较消耗CPU，但是视频是可用的

- 音视频合成

  - 同编码视频合成：`ffmpeg -f concat -safe 0 -i mylist.txt -c copy output.wav`，其中mylist.txt内容如下：

    ```txt
    # this is a comment
    file '/path/to/file1.wav'
    file '/path/to/file2.wav'
    file '/path/to/file3.wav'
    ```

  - 不同编码视频合成：

    ```sh
    ffmpeg -i input1.mp4 -i input2.webm -i input3.mov \
    -filter_complex "[0:v:0][0:a:0][1:v:0][1:a:0][2:v:0][2:a:0]concat=n=3:v=1:a=1[outv][outa]" \
    -map "[outv]" -map "[outa]" output.mkv
    ```

  - 音频定位插入

    ```sh
    ffmpeg -i input1.mp3 -i input2.mp3 -i input2.mp3  -filter_complex "[1]adelay=4000|4000[del1],[2]adelay=6000|6000[del2],[0][del1]amix[out],[out][del2]amix" output.mp3 
    ```

- 字幕添加

  - 字幕添加需要ASS文件
  - ASS嵌入视频流：`ffmpeg -i input.mp4 -vf ass=t1.ass -f mp4 output.mp4`
  - ASS嵌入字幕流：`ffmpeg -i input.mp4 -i t1.ass -acodec copy -vcodec copy -scodec copy output.mkv`
    - 或者`ffmpeg -i input.mp4 -i t1.ass -map 0:0 -map 0:1 -map 1:0 -acodec copy -vcodec copy -scodec copy output.mkv`，这命令将第一个视频的两个流，和第二个视频的第一个流合并写入output.mkv

- 视频特效：[[CSDN] 博客](https://blog.csdn.net/yu540135101/article/details/103025957)

  - 淡入淡出：`ffmpeg -i 1.mp4 -vf fade=in:0:50 out3.mp4`
  
- 视频转码：

  - [mov格式转 vp8 webm](https://www.xuefei.net.cn/index.php/archives/138/)：`ffmpeg -i fg.mov -vcodec libvpx -auto-alt-ref 0 -acodec libvorbis out.webm`
  
- 音频转码：

  - mp3转wav：`ffmpeg -i xx.mp3 xx.wav`
  
- 音频降噪：

  - 频域滤波：通频带为 300 ～ 3400

    `ffmpeg -y -i in.wav -ac 1 -ar 16000 -acodec pcm_s16le -filter "bandpass=frequency=300:width_type=h:width=3100" out.wav`

