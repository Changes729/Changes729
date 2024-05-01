> 文章来源：https://mp.weixin.qq.com/s/QPTJj1yyZp-_94nWEutscg

# 音频文件格式--MP3 代码走读

## 摘记整理

**01 ID3v1**

ID3v1是 MP3 文件中使用的元数据标记格式。根据文章所说，可以从中读取音乐信息，比如标题、艺术家、专辑和曲目编号。特别的，文章中说，搜索引擎还可以使用元数据来索引 MP3 文件。

```c
/** libavformat/id3v1.c */
#include "id3v1.h"
#include "libavutil/dict.h"

/* See Genre List at http://id3.org/id3v2.3.0 */
const char * const ff_id3v1_genre_str[ID3v1_GENRE_MAX + 1] = {
      [0] = "Blues",
      [1] = "Classic Rock",
      [2] = "Country",
  ...
```

> 头一回见到这种数组定义方式。



**02 ff_mp3_demuxer**

```c
/** libavformat/mp3dev.c */
const FFInputFormat ff_mp3_demuxer = {
    .p.name         = "mp3",
    .p.long_name    = NULL_IF_CONFIG_SMALL("MP2/3 (MPEG audio layer 2/3)"),
    .p.flags        = AVFMT_GENERIC_INDEX,
    .p.extensions   = "mp2,mp3,m2a,mpa", /* XXX: use probe */
    .p.priv_class   = &demuxer_class,
    .read_probe     = mp3_read_probe,
    .read_header    = mp3_read_header,
    .read_packet    = mp3_read_packet,
    .read_seek      = mp3_seek,
    .priv_data_size = sizeof(MP3DecContext),
};
```

FFmpeg 使用 `ff_mp3_demuxer` 结构来解复用 MP3 文件。调用 `read_probe` 函数来确定该文件是否实际上是 MP3 格式。如果文件是MP3格式，FFmpeg会调用`read_header`函数读取文件头。`read_header` 函数将返回指向 `AVFormatContext` 结构的指针，该结构包含有关文件的信息，例如文件中的流数和用于每个流的编解码器。

然后 FFmpeg 将调用 `read_packet` 函数从文件中读取数据包。`read_packet` 函数将返回指向 `AVPacket` 结构的指针，其中包含数据包的数据。然后 FFmpeg 将解码数据包中的数据并播放该文件。

![图片](https://mmbiz.qpic.cn/mmbiz_png/CmsibKlb9EkgianpFzsf5dBYe1brBdicD2KMOQtUL4vT3ricUwwdj68iarkibHe5BZjTzeL787mDMdiaBoQo9stiatSD3w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



**03 ff_id3v1_read**

```c
/** libavformat/id3v1.c */
void ff_id3v1_read(AVFormatContext *s)
{
    int ret;
    uint8_t buf[ID3v1_TAG_SIZE];
    int64_t filesize, position = avio_tell(s->pb);

    if (s->pb->seekable & AVIO_SEEKABLE_NORMAL) {
        /* XXX: change that */
        filesize = avio_size(s->pb);
        if (filesize > 128) {
            avio_seek(s->pb, filesize - 128, SEEK_SET);
            ret = avio_read(s->pb, buf, ID3v1_TAG_SIZE);
            if (ret == ID3v1_TAG_SIZE) {
                parse_tag(s, buf);
            }
            avio_seek(s->pb, position, SEEK_SET);
        }
    }
}
```

ff_id3v1_read() 函数用于从音频文件中读取 ID3v1 标签。

如果音频文件是可搜索的，则该函数会获取音频文件的大小。该函数然后查找音频文件的末尾并读取 128 字节的数据。128 字节的数据是 ID3v1 标签。



**04 mp3_read_probe**

```c
/** libavformat/mp3dec.c */
static int mp3_read_probe(const AVProbeData *p)
{
    int max_frames, first_frames = 0;
    int whole_used = 0;
    int frames, ret;
    int framesizes, max_framesizes;
    uint32_t header;
    const uint8_t *buf, *buf0, *buf2, *buf3, *end;

    buf0 = p->buf;
    end = p->buf + p->buf_size - sizeof(uint32_t);
    while (buf0 < end && !*buf0)
        buf0++;

    max_frames = 0;
    max_framesizes = 0;
    buf = buf0;

    for (; buf < end; buf = buf2+1) {
        buf2 = buf;
        for (framesizes = frames = 0; buf2 < end; frames++) {
            MPADecodeHeader h;
            int header_emu = 0;
            int available;

            header = AV_RB32(buf2);
            ret = avpriv_mpegaudio_decode_header(&h, header);
            if (ret != 0)
                break;

            available = FFMIN(h.frame_size, end - buf2);
            for (buf3 = buf2 + 4; buf3 < buf2 + available; buf3++) {
                uint32_t next_sync = AV_RB32(buf3);
                header_emu += (next_sync & MP3_MASK) == (header & MP3_MASK);
            }
            if (header_emu > 2)
                break;
            framesizes += h.frame_size;
            if (available < h.frame_size) {
                frames++;
                break;
            }
            buf2 += h.frame_size;
        }
        max_frames = FFMAX(max_frames, frames);
        max_framesizes = FFMAX(max_framesizes, framesizes);
        if (buf == buf0) {
            first_frames= frames;
            if (buf2 == end + sizeof(uint32_t))
                whole_used = 1;
        }
    }
    // keep this in sync with ac3 probe, both need to avoid
    // issues with MPEG-files!
    if   (first_frames>=7) return AVPROBE_SCORE_EXTENSION + 1;
    else if (max_frames>200 && p->buf_size < 2*max_framesizes)return AVPROBE_SCORE_EXTENSION;
    else if (max_frames>=4 && p->buf_size < 2*max_framesizes) return AVPROBE_SCORE_EXTENSION / 2;
    else if (ff_id3v2_match(buf0, ID3v2_DEFAULT_MAGIC) && 2*ff_id3v2_tag_len(buf0) >= p->buf_size)
                           return p->buf_size < PROBE_BUF_MAX ? AVPROBE_SCORE_EXTENSION / 4 : AVPROBE_SCORE_EXTENSION - 2;
    else if (first_frames > 1 && whole_used) return 5;
    else if (max_frames>=1 && p->buf_size < 10*max_framesizes) return 1;
    else                   return 0;
    //mpegps_mp3_unrecognized_format.mpg has max_frames=3
}
```

`mp3_read_probe`函数是一个用于探测文件以查看其是否为 MP3 格式的函数。该函数将指向 `AVProbeData` 结构的指针作为其唯一参数。`AVProbeData` 结构包含有关文件的信息，例如文件的大小和文件的前几个字节。

`mp3_read_probe` 函数首先查找 MPEG-1 第 3 层 (MP3) 标头。MP3 标头是一个 12 字节的标头，位于每个 MP3 文件的开头。如果该函数找到 MP3 标头，就会读取文件接下来的几个字节以查看是否与 MP3 文件一致。如果接下来的几个字节与 MP3 文件一致，则函数返回一个正值。该函数返回的值表示该文件为 MP3 格式的可能性有多大，较高的值表示较高的可能性。

如果函数没有找到 MP3 文件头或者文件接下来的几个字节与 MP3 文件不一致，则函数返回一个负值，一般负值表示文件不是 MP3 格式。



**05 mp3_read_header**

```c
/** libavformat/mp3dec.c */
static int mp3_read_header(AVFormatContext *s)
{
    FFFormatContext *const si = ffformatcontext(s);
    MP3DecContext *mp3 = s->priv_data;
    AVStream *st;
    FFStream *sti;
    int64_t off;
    int ret;
    int i;

    s->metadata = si->id3v2_meta;
    si->id3v2_meta = NULL;

    st = avformat_new_stream(s, NULL);
    if (!st)
        return AVERROR(ENOMEM);
    sti = ffstream(st);

    st->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
    st->codecpar->codec_id = AV_CODEC_ID_MP3;
    sti->need_parsing = AVSTREAM_PARSE_FULL_RAW;
    st->start_time = 0;

    // lcm of all mp3 sample rates
    avpriv_set_pts_info(st, 64, 1, 14112000);

    ffiocontext(s->pb)->maxsize = -1;
    off = avio_tell(s->pb);

    if (!av_dict_count(s->metadata))
        ff_id3v1_read(s);

    if (s->pb->seekable & AVIO_SEEKABLE_NORMAL)
        mp3->filesize = avio_size(s->pb);

    if (mp3_parse_vbr_tags(s, st, off) < 0)
        avio_seek(s->pb, off, SEEK_SET);

    ret = ff_replaygain_export(st, s->metadata);
    if (ret < 0)
        return ret;

    off = avio_tell(s->pb);
    for (i = 0; i < 64 * 1024; i++) {
        uint32_t header, header2;
        int frame_size;
        if (!(i&1023))
            ffio_ensure_seekback(s->pb, i + 1024 + 4);
        frame_size = check(s->pb, off + i, &header);
        if (frame_size > 0) {
            ffio_ensure_seekback(s->pb, i + 1024 + frame_size + 4);
            ret = check(s->pb, off + i + frame_size, &header2);
            if (ret >= 0 &&
                (header & MP3_MASK) == (header2 & MP3_MASK))
            {
                break;
            } else if (ret == CHECK_SEEK_FAILED) {
                av_log(s, AV_LOG_ERROR, "Invalid frame size (%d): Could not seek to %"PRId64".\n", frame_size, off + i + frame_size);
                return AVERROR(EINVAL);
            }
        } else if (frame_size == CHECK_SEEK_FAILED) {
            av_log(s, AV_LOG_ERROR, "Failed to read frame size: Could not seek to %"PRId64".\n", (int64_t) (i + 1024 + frame_size + 4));
            return AVERROR(EINVAL);
        }
    }
    if (i == 64 * 1024) {
        off = avio_seek(s->pb, off, SEEK_SET);
    } else {
        av_log(s, i > 0 ? AV_LOG_INFO : AV_LOG_VERBOSE, "Skipping %d bytes of junk at %"PRId64".\n", i, off);
        off = avio_seek(s->pb, off + i, SEEK_SET);
    }
    if (off < 0)
        return off;

    // the seek index is relative to the end of the xing vbr headers
    for (int i = 0; i < sti->nb_index_entries; i++)
        sti->index_entries[i].pos += off;

    /* the parameters will be extracted from the compressed bitstream */
    return 0;
}
```

`mp3_read_header` 函数是一个用来读取 MP3 文件头的函数。该函数将指向 `AVFormatContext` 结构的指针作为其唯一参数。`AVFormatContext` 结构包含有关文件的信息，例如文件的大小和文件中的流数。

`mp3_read_header`函数首先读取文件的前几个字节。这些字节包含 MP3 标头。如果该函数成功读取 MP3 标头，它将读取文件的其余部分，寻找其他 MP3 标头。如果该函数找到其他 MP3 标头，它会将有关标头的信息存储在 `AVFormatContext` 结构中。

如果该函数未找到任何 MP3 标头，则返回负值。负值表示该文件不是 MP3 文件。



**06 mp3_read_packet**

```c
/** libavformat/mp3dec.c */
#define MP3_PACKET_SIZE 1024

static int mp3_read_packet(AVFormatContext *s, AVPacket *pkt)
{
    MP3DecContext *mp3 = s->priv_data;
    int ret, size;
    int64_t pos;

    size = MP3_PACKET_SIZE;
    pos = avio_tell(s->pb);
    if (mp3->filesize > ID3v1_TAG_SIZE && pos < mp3->filesize)
        size= FFMIN(size, mp3->filesize - pos);

    ret = av_get_packet(s->pb, pkt, size);
    if (ret <= 0) {
        if(ret<0)
            return ret;
        return AVERROR_EOF;
    }

    pkt->flags &= ~AV_PKT_FLAG_CORRUPT;
    pkt->stream_index = 0;

    return ret;
}
```



**07 mp3_seek**

```c
/** libavformat/mp3dec.c */
static int mp3_seek(AVFormatContext *s, int stream_index, int64_t timestamp,
                    int flags)
{
    FFFormatContext *const si = ffformatcontext(s);
    MP3DecContext *mp3 = s->priv_data;
    AVIndexEntry *ie, ie1;
    AVStream *st = s->streams[0];
    FFStream *const sti = ffstream(st);
    int64_t best_pos;
    int fast_seek = s->flags & AVFMT_FLAG_FAST_SEEK;
    int64_t filesize = mp3->header_filesize;

    if (filesize <= 0) {
        int64_t size = avio_size(s->pb);
        if (size > 0 && size > si->data_offset)
            filesize = size - si->data_offset;
    }

  	/* 检查是否具有 Xing TOC，如果存在，则通过时间戳找到最近的 Index */
    if (mp3->xing_toc && (mp3->usetoc || (fast_seek && !mp3->is_cbr))) {
        int64_t ret = av_index_search_timestamp(st, timestamp, flags);

        // NOTE: The MP3 TOC is not a precise lookup table. Accuracy is worse
        // for bigger files.
        av_log(s, AV_LOG_WARNING, "Using MP3 TOC to seek; may be imprecise.\n");

        if (ret < 0)
            return ret;

        ie = &sti->index_entries[ret];
    /* 如果不存在就通过缩放算法估算时间戳的位置 */
    } else if (fast_seek && st->duration > 0 && filesize > 0) {
        if (!mp3->is_cbr)
            av_log(s, AV_LOG_WARNING, "Using scaling to seek VBR MP3; may be imprecise.\n");

        ie = &ie1;
        timestamp = av_clip64(timestamp, 0, st->duration);
        ie->timestamp = timestamp;
        ie->pos       = av_rescale(timestamp, filesize, st->duration) + si->data_offset;
    } else {
        return -1; // generic index code
    }

  	/* 通过 sync 跳转到固定位置，并更新dts */
    best_pos = mp3_sync(s, ie->pos, flags);
    if (best_pos < 0)
        return best_pos;

    if (mp3->is_cbr && ie == &ie1 && mp3->frames) {
        int frame_duration = av_rescale(st->duration, 1, mp3->frames);
        ie1.timestamp = frame_duration * av_rescale(best_pos - si->data_offset, mp3->frames, mp3->header_filesize);
    }

    avpriv_update_cur_dts(s, st, ie->timestamp);
    return 0;
}
```

`mp3_seek` 该函数首先检查 MP3 文件是否有 Xing TOC。 如果是，该函数将使用 TOC 查找时间戳之前最接近的索引条目。 如果 MP3 文件没有 Xing TOC，则该函数使用简单的缩放算法来估计时间戳的位置。

一旦函数找到时间戳的位置，它就会调用 `mp3_sync` 函数以确保位置准确。 如果 `mp3_sync` 函数返回错误，则该函数返回该错误。

最后，该函数更新流的当前 DTS 并返回 0。



**08 mp3_sync**

```c
/** libavformat/mp3dec.c */
static int64_t mp3_sync(AVFormatContext *s, int64_t target_pos, int flags)
{
    int dir = (flags&AVSEEK_FLAG_BACKWARD) ? -1 : 1;
    int64_t best_pos;
    int best_score, i, j;
    int64_t ret;

    avio_seek(s->pb, FFMAX(target_pos - SEEK_WINDOW, 0), SEEK_SET);
    ret = avio_seek(s->pb, target_pos, SEEK_SET);
    if (ret < 0)
        return ret;

#define MIN_VALID 3
    best_pos = target_pos;
    best_score = 999;
    for (i = 0; i < SEEK_WINDOW; i++) {
        int64_t pos = target_pos + (dir > 0 ? i - SEEK_WINDOW/4 : -i);
        int64_t candidate = -1;
        int score = 999;

        if (pos < 0)
            continue;

        for (j = 0; j < MIN_VALID; j++) {
            ret = check(s->pb, pos, NULL);
            if (ret < 0) {
                if (ret == CHECK_WRONG_HEADER) {
                    break;
                } else if (ret == CHECK_SEEK_FAILED) {
                    av_log(s, AV_LOG_ERROR, "Could not seek to %"PRId64".\n", pos);
                    return AVERROR(EINVAL);
                }
            }
            if ((target_pos - pos)*dir <= 0 && FFABS(MIN_VALID/2-j) < score) {
                candidate = pos;
                score = FFABS(MIN_VALID/2-j);
            }
            pos += ret;
        }
        if (best_score > score && j == MIN_VALID) {
            best_pos = candidate;
            best_score = score;
            if(score == 0)
                break;
        }
    }

    return avio_seek(s->pb, best_pos, SEEK_SET);
}
```

mp3_sync()该函数首先寻找目标位置。 如果查找成功，该函数将检查接下来的几帧以查看它们是否是同步帧。 如果是，该函数返回第一个同步帧的位置。 如果不是，该函数将继续向前查找，直到找到同步帧。其中分数是衡量位置与目标位置的接近程度的指标。



**09 check**

check()函数用于检查 MP3 文件中的位置是否是同步帧。

```c
/** libavformat/mp3dec.c */
#define SEEK_WINDOW 4096

static int check(AVIOContext *pb, int64_t pos, uint32_t *ret_header)
{
    int64_t ret = avio_seek(pb, pos, SEEK_SET);
    uint8_t header_buf[4];
    unsigned header;
    MPADecodeHeader sd;
    if (ret < 0)
        return CHECK_SEEK_FAILED;

    ret = avio_read(pb, &header_buf[0], 4);
    /* We should always find four bytes for a valid mpa header. */
    if (ret < 4)
        return CHECK_SEEK_FAILED;

    header = AV_RB32(&header_buf[0]);
    if (ff_mpa_check_header(header) < 0)
        return CHECK_WRONG_HEADER;
    if (avpriv_mpegaudio_decode_header(&sd, header) == 1)
        return CHECK_WRONG_HEADER;

    if (ret_header)
        *ret_header = header;
    return sd.frame_size;
}
```

