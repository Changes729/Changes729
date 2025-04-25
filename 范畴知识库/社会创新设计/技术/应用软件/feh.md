# feh

## 技巧

- `s`：保存图片（会重命名）
- `< >`：左右旋转图片
- `F`：全屏幕

```sh
#!/bin/sh

files=`ls`

for file in $files
do
    if [[ "$file" == feh* ]]; then
        echo "Processing file: $file"
        echo ${file: -23}
        mv $file ${file: -23}
    fi
done
```

