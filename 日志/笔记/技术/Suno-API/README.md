> 参考代码：
>
> - [gcui-art](https://github.com/gcui-art)/[suno-api](https://github.com/gcui-art/suno-api)：Next 实现的 Suno-API
> - [SunoAI-API](https://github.com/SunoAI-API)/[Suno-API](https://github.com/SunoAI-API/Suno-API)：Python 实现的 Suno-API

# Suno-API

## Suno API 保活原理

```python
def update_token(suno_cookie: SunoCookie):
    headers = {"cookie": suno_cookie.get_cookie()}
    headers.update(COMMON_HEADERS)
    session_id = suno_cookie.get_session_id()

    resp = requests.post(
        url=f"https://clerk.suno.com/v1/client/sessions/{session_id}/tokens?_clerk_js_version=4.72.0-snapshot.vc141245",
        headers=headers,
    )

    resp_headers = dict(resp.headers)
    set_cookie = resp_headers.get("Set-Cookie")
    suno_cookie.load_cookie(set_cookie)
    token = resp.json().get("jwt")
    suno_cookie.set_token(token)
    
def keep_alive(suno_cookie: SunoCookie):
    while True:
        try:
            update_token(suno_cookie)
        except Exception as e:
            print(e)
        finally:
            time.sleep(5)
```

原理上，是使用 session 获取 cookie 和 token。



## Suno Generate Full Song 流程

1. 首先需要 generate 一首歌（略）

2. 在生成的歌曲基础上，使用 extend 再生成。返回内容如下：

   生成的音乐在 `clips` 中，两首歌。

   ```json
   {
       "id": "fe604237-3aa8-41f8-8901-a6f4e70ccec9",
       "clips": [
           {
               "id": "c4581fd8-e1cd-42f5-94cb-e1f3fd6505b4",
               "video_url": "",
               "audio_url": "",
               "image_url": null,
               "image_large_url": null,
               "is_video_pending": false,
               "major_model_version": "v3",
               "model_name": "chirp-v3",
               "metadata": {
                   "tags": "soulful pop-rock melancholic, nu metal, female vocals, rock",
                   "prompt": "",
                   "gpt_description_prompt": null,
                   "audio_prompt_id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
                   "history": [
                       {
                           "id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
                           "continue_at": 25.0,
                           "type": "concat",
                           "source": "web",
                           "infill": false
                       }
                   ],
                   "concat_history": [
                       {
                           "id": "efbf3f56-5c11-43b5-ab44-af4000d10656",
                           "continue_at": 106.0,
                           "type": "gen",
                           "source": "web",
                           "infill": false
                       },
                       {
                           "id": "77037a26-b99b-4776-a8e6-cadd573e02c9",
                           "continue_at": null
                       }
                   ],
                   "type": "gen",
                   "duration": null,
                   "refund_credits": null,
                   "stream": true,
                   "infill": false,
                   "has_vocal": null,
                   "is_audio_upload_tos_accepted": null,
                   "error_type": null,
                   "error_message": null
               },
               "is_liked": false,
               "user_id": "72a33730-ad60-43ce-9b49-edf859af86a4",
               "display_name": "ThrivingHypeMan254",
               "handle": "thrivinghypeman254",
               "is_handle_updated": false,
               "avatar_image_url": "https://cdn1.suno.ai/defaultPink.jpg",
               "is_trashed": false,
               "reaction": null,
               "created_at": "2024-07-07T13:21:04.725Z",
               "status": "submitted",
               "title": "",
               "play_count": 0,
               "upvote_count": 0,
               "is_public": false
           },
           {
               "id": "600ee6ac-f44e-47bf-ab44-3ee509df1080",
               "video_url": "",
               "audio_url": "",
               "image_url": null,
               "image_large_url": null,
               "is_video_pending": false,
               "major_model_version": "v3",
               "model_name": "chirp-v3",
               "metadata": {
                   "tags": "soulful pop-rock melancholic, nu metal, female vocals, rock",
                   "prompt": "",
                   "gpt_description_prompt": null,
                   "audio_prompt_id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
                   "history": [
                       {
                           "id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
                           "continue_at": 25.0,
                           "type": "concat",
                           "source": "web",
                           "infill": false
                       }
                   ],
                   "concat_history": [
                       {
                           "id": "efbf3f56-5c11-43b5-ab44-af4000d10656",
                           "continue_at": 106.0,
                           "type": "gen",
                           "source": "web",
                           "infill": false
                       },
                       {
                           "id": "77037a26-b99b-4776-a8e6-cadd573e02c9",
                           "continue_at": null
                       }
                   ],
                   "type": "gen",
                   "duration": null,
                   "refund_credits": null,
                   "stream": true,
                   "infill": false,
                   "has_vocal": null,
                   "is_audio_upload_tos_accepted": null,
                   "error_type": null,
                   "error_message": null
               },
               "is_liked": false,
               "user_id": "72a33730-ad60-43ce-9b49-edf859af86a4",
               "display_name": "ThrivingHypeMan254",
               "handle": "thrivinghypeman254",
               "is_handle_updated": false,
               "avatar_image_url": "https://cdn1.suno.ai/defaultPink.jpg",
               "is_trashed": false,
               "reaction": null,
               "created_at": "2024-07-07T13:21:04.725Z",
               "status": "submitted",
               "title": "",
               "play_count": 0,
               "upvote_count": 0,
               "is_public": false
           }
       ],
       "metadata": {
           "tags": "soulful pop-rock melancholic, nu metal, female vocals, rock",
           "prompt": "",
           "gpt_description_prompt": null,
           "audio_prompt_id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
           "history": [
               {
                   "id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
                   "continue_at": 25.0,
                   "type": "concat",
                   "source": "web",
                   "infill": false
               }
           ],
           "concat_history": [
               {
                   "id": "efbf3f56-5c11-43b5-ab44-af4000d10656",
                   "continue_at": 106.0,
                   "type": "gen",
                   "source": "web",
                   "infill": false
               },
               {
                   "id": "77037a26-b99b-4776-a8e6-cadd573e02c9",
                   "continue_at": null
               }
           ],
           "type": "gen",
           "duration": null,
           "refund_credits": null,
           "stream": true,
           "infill": false,
           "has_vocal": null,
           "is_audio_upload_tos_accepted": null,
           "error_type": null,
           "error_message": null
       },
       "major_model_version": "v3",
       "status": "complete",
       "created_at": "2024-07-07T13:21:04.716Z",
       "batch_size": 1
   }
   ```

3. extend 的音乐生成完毕后，可以试听。但是音频长度有限，并且不一定完整（因为是在原来基础上拓展的）

4. 使用 contact 合并为完整的音乐，收到如下反馈：

   第一个ID就是新歌曲ID

   ```json
   
   {
     "id": "8af396bb-37ed-4f53-8815-b9e38af9829a",
     "video_url": "",
     "audio_url": "",
     "image_url": "https://cdn1.suno.ai/image_77037a26-b99b-4776-a8e6-cadd573e02c9.png",
     "image_large_url": "https://cdn1.suno.ai/image_large_77037a26-b99b-4776-a8e6-cadd573e02c9.png",
     "is_video_pending": false,
     "major_model_version": "v3.5",
     "model_name": "chirp-v3.5",
     "metadata": {
       "tags": "soulful pop-rock melancholic",
       "prompt": "[Verse]\nWoke up in the rain today\nSky is gray and full of pain\nEvery step is heavy now\n\n[Verse 2]\nEmpty streets they scream your name\nEchoes haunt me I can't hide\nFeel the weight it's crushing down\n\n[Chorus]\nThis is not a happy day\nShadows chase the light away\nLost my smile it's gone astray\nThis is not a happy day\n\n[Verse 3]\nBroken dreams they hold me tight\nTangled in the webs we weave\nCan't escape the endless night\n\n[Bridge]\nTears fall down like shattered glass\nMemories of love long past\nTime is cruel it moves too fast\n\n[Chorus]\nThis is not a happy day\nShadows chase the light away\nLost my smile it's gone astray\nThis is not a happy day\n\n[lrc]Silent battlegrounds, no birds' song\nShadows of war, where we don't belong\nMay flowers of peace bloom in this place\nLet's guard this precious dream with grace\n[endlrc]",
       "gpt_description_prompt": null,
       "audio_prompt_id": null,
       "history": null,
       "concat_history": [
         {
           "id": "efbf3f56-5c11-43b5-ab44-af4000d10656",
           "continue_at": 106,
           "type": "gen",
           "source": "web",
           "infill": false
         },
         {
           "id": "77037a26-b99b-4776-a8e6-cadd573e02c9",
           "continue_at": null
         }
       ],
       "type": "concat",
       "duration": null,
       "refund_credits": null,
       "stream": null,
       "infill": null,
       "has_vocal": null,
       "is_audio_upload_tos_accepted": null,
       "error_type": null,
       "error_message": null
     },
     "is_liked": false,
     "user_id": "72a33730-ad60-43ce-9b49-edf859af86a4",
     "display_name": "ThrivingHypeMan254",
     "handle": "thrivinghypeman254",
     "is_handle_updated": false,
     "avatar_image_url": "https://cdn1.suno.ai/defaultPink.jpg",
     "is_trashed": false,
     "reaction": null,
     "created_at": "2024-07-07T13:18:13.097Z",
     "status": "queued",
     "title": "This is Not a Happy Day",
     "play_count": 0,
     "upvote_count": 0,
     "is_public": false
   }
   ```

   

