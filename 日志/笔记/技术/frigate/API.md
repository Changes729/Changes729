## 生成 Clip

```sh
curl -L 'http://localhost:5000/api/export/CAMERA116/start/1760786400/end/1760786420' \
-H 'Content-Type: application/json' \
-H 'Accept: application/json' \
-d '{
  "playback": "realtime",
  "source": "recordings",
  "name": "test",
  "image_path": "string"
}'

> {"success":true,"message":"Starting export of recording.","export_id":"CAMERA116_kqo4v5"}%  
```



## 获取 ID

```sh
curl  http://localhost:5000/api/exports/CAMERA116_kqo4v5  

>{"id":"CAMERA116_kqo4v5","camera":"CAMERA116","name":"test","date":1760786400,"video_path":"/media/frigate/exports/CAMERA116_20251018_112000-20251018_112020_kqo4v5.mp4","thumb_path":"/media/frigate/clips/export/CAMERA116_kqo4v5.webp","in_progress":false}
```



## 下载文件

```sh
curl http://localhost:5000/exports/CAMERA116_20251018_112000-20251018_112020_kqo4v5.mp4 --output file
```

