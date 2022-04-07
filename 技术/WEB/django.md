> *参考资料*：
>
> - https://www.djangoproject.com/
>   - [URL 的反向解析](https://docs.djangoproject.com/zh-hans/4.0/topics/http/urls/#reverse-resolution-of-urls)
>   - [命名URL模式](https://docs.djangoproject.com/zh-hans/4.0/topics/http/urls/#naming-url-patterns-1)
>   - [migrate](https://docs.djangoproject.com/zh-hans/4.0/ref/django-admin/#django-admin-migrate)：负责应用和撤销迁移。
>     - 你应该将迁移看作是**数据库**架构的版本控制系统。
>
>   - [How to create custom `django-admin` commands](https://docs.djangoproject.com/en/4.0/howto/custom-management-commands/)
>     - [如果有重名的命令会发生什么情况？](https://stackoverflow.com/questions/29320103/if-multiple-django-apps-define-the-same-custom-management-command-which-is-used)：根据优先级，后加载的模块会覆盖前面的命令
>
>
> *相关项目*：
>
> - [photonixapp](https://github.com/photonixapp)/**[photonix](https://github.com/photonixapp/photonix)**：A modern, web-based photo management server.

# django

**安装**：`python -m pip install Django`

**创建新项目**：`django-admin startproject [mysite]`

**创建新界面**：`python manage.py startapp polls`

**启动网站**：`python manage.py runserver [port]`

**关键文件**：

- **manage.py**：一个可以和`django`交互的工具文件。了解更多请参阅 [django-admin and manage.py](https://docs.djangoproject.com/en/4.0/ref/django-admin/).

- **mysite/__init__.py**：一个用来告诉Python这个目录应该被看作一个Python包的空文件. 如果你是一位Python初学者, 在[more about packages](https://docs.python.org/3/tutorial/modules.html#tut-packages) 查阅更多相关信息.

- **mysite/settings.py**：Django项目的配置/设置文件。这个文件[Django settings](https://docs.djangoproject.com/en/4.0/topics/settings/) 将会告诉你它是如何工作的。

- **mysite/urls.py**：这是Django项目的URL声明，一个记录Django赋能的网页表格。你可以在[URL dispatcher](https://docs.djangoproject.com/en/4.0/topics/http/urls/)了解更多.

  - **polls/urls.py**：这是一个子URL，这样的设计可以保证即使Root环境变化，这个URL下的页面与内容不变。

    ```python
    # mysite/urls.py
    from django.contrib import admin
    from django.urls import include, path

    urlpatterns = [
        path('polls/', include('polls.urls')),
        path('admin/', admin.site.urls),
    ]
    ```

    ```python
    # mysite/polls/urls.py
    from django.urls import path

    from . import views

    urlpatterns = [
        path('', views.index, name='index'),
    ]
    ```

  - **polls/views.py**：页面行为，用来处理http请求并返回内容。这个页面需要通过urls.py进行绑定。

    ```python
    # mysite/polls/views.py
    from django.http import HttpResponse


    def index(request):
        return HttpResponse("Hello, world. You're at the polls index.")
    ```

- **mysite/asgi.py**：暂时未知。ASGI（Asynchronous Server Gateway Interface，异步服务器网关接口）

- **mysite/wsgi.py**：暂时未知。WSGI（Web Server Gateway Interface，Web服务器网关接口）



## 一些技巧

