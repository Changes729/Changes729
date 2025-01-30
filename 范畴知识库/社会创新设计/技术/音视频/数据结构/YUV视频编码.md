> 参考资料：
>
> - https://wiki.videolan.org/YUV：比较详细的介绍了各种YUV编码的视频
> - [4:2:0 Video Pixel Formats](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/4-2-0-video-pixel-formats)：微软视频文档
> - [422，420，10bit，8bit？这些究竟是什么](https://www.bilibili.com/video/BV1ds411T7F4/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)：
>   - 4:4:4，横向4pixel，第一行四个采样点，第二行四个采样点。
>   - 4:2:2，横向4pixel，第一行两个采样点，第二行两个采样点。
>   - 4:2:0，横向4pixel，第一行两个采样点，第二行没有采样点。（4pixel共享一个采样点）

# YUV

## Planar formats（平面格式）

### YUV 4:2:0 (I420/J420/YV12)

`I420` 像素 : `YYYYYYYYUUVV（12bit）`，`f420` Y为浮点数，范围 `16~255`，`YV12`就是 U、V序列反转，也就是`YYYYYYYYVVUU（12bit）`

`IYUV`：交换了 `Cb`、`Cr`平面。`Cb`是色度蓝色平面（Chroma Blue）

