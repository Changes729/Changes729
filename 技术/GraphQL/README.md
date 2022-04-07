> 参考资料：
>
> - https://graphql.org/
> - [graphene-django](https://docs.graphene-python.org/projects/django/en/latest/installation/#)
>   - [Mutations](https://docs.graphene-python.org/en/latest/types/mutations/)

# GraphQL

GraphQL是一个通过类似JSON的方式获取对应JSON数据的工具。

## Python使用

**安装**：`pip install graphene`

**使用**：

```python
import graphene

class Query(graphene.ObjectType):
  hello = graphene.String(name=graphene.String(default_value="World"))

  def resolve_hello(self, info, name): # 外部解析hello这个字段时，会使用这种方式进行解析。
    return 'Hello ' + name

schema = graphene.Schema(query=Query)
result = schema.execute('{ hello }') # 这个就是GraphQL请求的字符串，result是一个Json
print(result.data['hello']) # 从result这个JSON中解析出hello对应的值，会显示'Hello World'
```



## DJango Project

**安装**：`pip install graphene-django`

**配置**：

- 将`graphene_django`添加到`settings.py`文件的`INSTALLED_APPS`内：

  ```python
  INSTALLED_APPS = [
      ...
      "django.contrib.staticfiles", # Required for GraphiQL
      "graphene_django"
  ]
  ```

- 在`url.py`内添加`graphql`路径：

  ```python
  from django.urls import path
  from graphene_django.views import GraphQLView
  
  urlpatterns = [
      # ...
      path("graphql", GraphQLView.as_view(graphiql=True)),
  ]
  ```

  如果你不想在网页端使用GraphiQL API的话，修改`graphiql=False`。

  - CSRF支持： https://docs.djangoproject.com/en/3.0/ref/csrf/#ajax

  - 临时关闭CSRF：使用`csrf_exempt`修饰器。

    ```python
    # urls.py
    
    from django.urls import path
    from django.views.decorators.csrf import csrf_exempt
    
    from graphene_django.views import GraphQLView
    
    urlpatterns = [
        # ...
        path("graphql", csrf_exempt(GraphQLView.as_view(graphiql=True))),
    ]
    ```

- 最后，在`settings.py`中定义你的**Graphql Schema**位置：

  ```python
  GRAPHENE = {
      "SCHEMA": "django_root.schema.schema"
  }
  ```

  - 如果不想在`settings.py`中设置schema的话，可以像下面一样**手动传入**：

    ```python
    # cookbook/urls.py
    
    from django.contrib import admin
    from django.urls import path
    from django.views.decorators.csrf import csrf_exempt
    
    from graphene_django.views import GraphQLView
    
    from cookbook.schema import schema
    
    urlpatterns = [
        path("admin/", admin.site.urls),
        path("graphql", csrf_exempt(GraphQLView.as_view(graphiql=True, schema=schema))),
    ]
    ```

  最简单的schema文件如下所示：

  ```python
  import graphene
  
  class Query(graphene.ObjectType):
      hello = graphene.String(default_value="Hi!")
  
  schema = graphene.Schema(query=Query)
  ```



## Schema：[Core graphene docs](https://docs.graphene-python.org/en/latest/types/schema/)

`graphene.Schema`类描述了你的数据模型，并且提供了一个与之相关的用来获取你欲知数据方法的GraphQL服务。最简单的schema像下面一样：

```python
import graphene

class Query(graphene.ObjectType):
    pass

class Mutation(graphene.ObjectType):
    pass

schema = graphene.Schema(query=Query, mutation=Mutation)
```

如果你自己有定义`Query`和`Mutation`，你可以注册它们如下所示：

```python
import graphene

import my_app.schema.Query
import my_app.schema.Mutation

class Query(
    my_app.schema.Query, # Add your Query objects here
    graphene.ObjectType
):
    pass

class Mutation(
    my_app.schema.Mutation, # Add your Mutation objects here
    graphene.ObjectType
):
    pass

schema = graphene.Schema(query=Query, mutation=Mutation)
```

### Query

每个query都有字段（field）以及解析方法（resolver method）。如下是一个query：

```python
from graphene import ObjectType, String

class Person(ObjectType):
    first_name = String()
    last_name = String()
    full_name = String()

    def resolve_full_name(parent, info):
        return f"{parent.first_name} {parent.last_name}"
```

除了`full_name`有一个自定义的解析器`resolve_full_name`以外，其他字段都是默认解析器。

### Mutation

Mutation 是一个特殊的类型，它还**定义了入参**。下面是一个Mutation的例子：

```python
import graphene

class CreatePerson(graphene.Mutation):
    class Arguments:
        name = graphene.String()

    ok = graphene.Boolean()
    person = graphene.Field(lambda: Person)

    def mutate(root, info, name):
        person = Person(name=name)
        ok = True
        return CreatePerson(person=person, ok=ok)
```

外部可见的字段是`person`和`ok`。`Arguments`属性是这个Mutation中`CreatePerson`需要解析的参数，这个例子中，`name`是唯一的参数。

`mutate`是一个当mutation被调用时会运行的函数。这个方法只是一个特殊的解析器，我们可以用它来改变数据。

我们完善一下我们的schema：

```python
# ... the Mutation Class

class Person(graphene.ObjectType):
    name = graphene.String()
    age = graphene.Int()

class MyMutations(graphene.ObjectType):
    create_person = CreatePerson.Field()

# We must define a query for our schema
class Query(graphene.ObjectType):
    person = graphene.Field(Person)

schema = graphene.Schema(query=Query, mutation=MyMutations)
```

当我们用下面字段进行查询的时候：

```txt
mutation myFirstMutation {
    createPerson(name:"Peter") {
        person {
            name
        }
        ok
    }
}
```

会得到下面的反馈：

```json
{
    "createPerson": {
        "person" : {
            "name": "Peter"
        },
        "ok": true
    }
}
```

