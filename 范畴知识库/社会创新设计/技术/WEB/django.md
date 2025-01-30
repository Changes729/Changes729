> *参考资料*：
>
> - https://www.djangoproject.com/
>   - [URL 的反向解析](https://docs.djangoproject.com/zh-hans/4.0/topics/http/urls/#reverse-resolution-of-urls)
>   - [命名URL模式](https://docs.djangoproject.com/zh-hans/4.0/topics/http/urls/#naming-url-patterns-1)
>   - [migrate](https://docs.djangoproject.com/zh-hans/4.0/ref/django-admin/#django-admin-migrate)：负责应用和撤销迁移。
>     - [migrate document](https://docs.djangoproject.com/en/4.0/topics/migrations/#module-django.db.migrations)
>     - 你应该将迁移看作是**数据库**架构的版本控制系统。
>       - [makemigrations](https://docs.djangoproject.com/zh-hans/4.0/ref/django-admin/#django-admin-migrate)：根据检测到的模型变化创建新的迁移。
>     - [How to Create Django Data Migrations](https://simpleisbetterthancomplex.com/tutorial/2017/09/26/how-to-create-django-data-migrations.html)
>     - [Writing a Django Data Migration with Real World Example](https://dev.to/guin/writing-a-django-data-migration-with-real-world-example-40m)
>
>   - [Introduction to models](https://docs.djangoproject.com/en/4.0/topics/db/models/)
>     - [model field reference](https://docs.djangoproject.com/en/4.0/ref/models/fields/#model-field-types)：Model 字段類型
>
>   - [Making queries](https://docs.djangoproject.com/en/4.0/topics/db/queries/)
>     - [QuerySet API reference](https://docs.djangoproject.com/en/4.0/ref/models/querysets/)
>   
>     - [How to write custom lookups](https://docs.djangoproject.com/zh-hans/4.0/howto/custom-lookups/#how-to-write-custom-lookups)
>       - [Lookup API reference](https://docs.djangoproject.com/en/4.0/ref/models/lookups/)：介绍了如何编写一个 Lookup 表达式
>     
>   - [How to create custom `django-admin` commands](https://docs.djangoproject.com/en/4.0/howto/custom-management-commands/)
>     - [如果有重名的命令会发生什么情况？](https://stackoverflow.com/questions/29320103/if-multiple-django-apps-define-the-same-custom-management-command-which-is-used)：根据优先级，后加载的模块会覆盖前面的命令 
>   - [Django中的用户认证](https://docs.djangoproject.com/zh-hans/4.0/topics/auth/)
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

- **mysite/\__init__.py**：一个用来告诉Python这个目录应该被看作一个Python包的空文件. 如果你是一位Python初学者, 在[more about packages](https://docs.python.org/3/tutorial/modules.html#tut-packages) 查阅更多相关信息.

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



## Migrations 迁移

**四个命令**：

- migrate：用来应用（applying）或者撤销（unapplying）迁移。
- makemigrations：基于你对模型（models）的修改，来创建一个新的迁移（migrate）。
- sqlmigrate
- showmigrations

**什么时候需要创建迁移（make migrations）？**：

- 当你对模型修改时（如同添加或删除一个字段），通过 `makemigrations` Django 会创建一个迁移文件。
- 一旦你拥有一个迁移文件之后，你应该使用 `migrate` 应用它以保证它符合期望。

**什么时候需要执行迁移（run migrations）？**：

- 当需要保证模型数据库符合预期时，需要进行数据迁移。包括通过git更新了其他人的迁移文件时。都需要进行同步。



## Models Django 模型

