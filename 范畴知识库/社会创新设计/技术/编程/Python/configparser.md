> 参考资料：
>
> - [configparser](https://docs.python.org/3/library/configparser.html#module-configparser)：Configuration file parser

# configparser

## 读

```python
>>> another_config = configparser.ConfigParser()
>>> another_config.read('example.ini')
['example.ini']
>>> another_config['topsecret.server.com']['Port']
'50022'
>>> another_config.read_string("[topsecret.server.com]\nPort=48484")
>>> another_config['topsecret.server.com']['Port']
'48484'
>>> another_config.read_dict({"topsecret.server.com": {"Port": 21212}})
>>> another_config['topsecret.server.com']['Port']
'21212'
>>> another_config['topsecret.server.com']['ForwardX11']
'no'
```



## 写

