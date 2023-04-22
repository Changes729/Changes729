> 参考资料：
>
> - [ffplay Documentation](https://www.ffmpeg.org/ffplay.html)

# FFPlay 

`-loop`：`ffplay -loop 0 input.mp4`，循环播放视频

`-fs`：Start in fullscreen mode. 全屏模式



## C语言重定向获取 FFPlay 的视频播放信息

```cpp
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <exception>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

#define BUFFER_SIZE 256

const char* _fake_strip(const char* str)
{
  const char* ret = str;
  while(*ret != '\0' && !isgraph(*ret)) {
    ret++;
  }
  return ret;
}

int main(void)
{
  char   buffer[BUFFER_SIZE]{};
  size_t buffer_handler = 0;

  cout << "This is C program output string handler." << endl;
  try {
    char ch = '\0';
    char duration[16]{};
    char timestamp[100]{};

    while((ch = getc(stdin)) != EOF) {
      buffer[buffer_handler] = ch;
      buffer_handler         = buffer_handler + 1;
      switch(ch) {
        case '\n':
        case '\r':
        {
          const char* str        = _fake_strip(buffer);
          buffer[buffer_handler] = '\0';
          size_t res = sscanf(str, "Duration: %[0-9.:]s,", duration);
          if(res > 0) {
            printf("\n Duration: %s\n", duration);
          }
          res = sscanf(str, "%[ 0-9.:]s A-V:", timestamp);
          if(res > 0) {
            fprintf(stderr, "\r Timestamp: %s", timestamp);
          }

          buffer_handler = 0;
          buffer[0]      = '\0';
        } break;

        default:
          if(buffer_handler >= BUFFER_SIZE - 1) {
            buffer_handler = 0;
            buffer[0]      = '\0';
          }
          break;
      }
    }

    if(ch == EOF) {
      cout << "Program end with pipe close." << endl;
    }
  } catch(exception e) {
    cout << "[Exception] " << e.what() << endl;
  }

  return 0;
}
```

