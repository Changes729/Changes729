# C/C++ XML的理解与应用

## XML
像下面这种结构的文本，就可以认为是一种XML
```xml
<note>
  <to>George</to>
  <from>John</from>
  <heading>Reminder</heading>
  <body>Don't forget the meeting!</body>
</note>
```

## 任务说明
本次项目练习，是在Linux环境下，使用C/C++，通过第三方库`Libxml2`,完成对XML文件的解析、修改和保存。功能上需要完成：
1. `PrintList()`: 按顺序打印所有节点的内容 
2. `AddNode(Node node, auto location)`: 任意位置插入节点
3. `DetNode(auto location)`: 任意位置删除节点
4. `Sort()`: 对节点进行名字按字母排序后打印出来

因为是C/C++实现，所以这里不采用C++标准库实现数据存储的功能，采用自建链表，并要求完成以下功能：
1. 最终在程序结束时释放所有资源 （要求不能使用结构体析构方式进行操作）
2. 完成功能，并且保证无crash，无内存泄漏，无编译警告

最后再使用C++ 的`List`容器完成上述内容。数据如下：
| name | number | age | country |
| --- | --- | --- | --- |
| Alfred |  8100 | 34 | USA |
| Gypsy | 8134 | 27 | UK |
| Dats | 708225 | 52 | Mozambique |
| Manhattan | 9047967 | 36 | Sudan |
| Finlay | 124679 | 24 | USA |
| Yedda | 8098 | 31 | Dubai |
| Akashi | 34501 | 41 | Japan |
| Tatum | 9034561 | 29 | UK3 |
| Will | 589620 | 37 | China|

## 前言与适合阅读人群QA
希望在阅读完[任务说明](#任务说明)后，读者可以自行动手练习，以达到提升自己，学习技术的目的。文章后面讲述了笔者是如何完成这个项目的方式方法，可供读者参考。

### QA项目匹配度
1. 你是否会使用VSCode、CMake工具，在Linux环境下完成C/C++语言的编译，运行与调式？->[]()
2. 你是否想要使用其他第三方C/C++开源库，并构建自己的应用代码？
3. 你是否想要了解如何检查自己的程序有无内存泄漏的问题？
4. 你是否想要了解List标准库容器，以及其是如何使用的？

如果你还不会某些问题，你可能要去学。而如果你越想要知道上面问题的答案，那么你就越适合这次练习与本文。

## 正文
### Linux下C/C++库函数链接方式
Linux下想要成功链接第三方库，就需要编译时完成链接。简单来说是需要我们，帮助gcc找到链接库的位置。下图就是C语言编译过程:

![编译过程](http://images.cnitblog.com/blog/529981/201404/111709138874931.jpg)

Linux下C/C++库函数链接，就处在链接器这一步。我们通常写代码，在IDE中可以正常的用f12跳转至代码声明中，是因为IDE知道一些标准库头文件的存放位置，能编译成功，是因为知道一些标准库的存放位置，比如一个最简单的`helloworld`函数，开头引用的`stdio.h`头文件，是保存在`/usr/include/`目录下的，同样的可以发现像`math.h`，`pthread.h`头文件也放至在其中，C++的头文件是保存在`/usr/include/C++/5/`目录下的。而像pthread这类库，就保存在`/usr/lib/x86_64-linux-gnu`文件之下，并且以`libpthread.so`命名。`.so`结尾的函数库是动态链接库，`.a`结尾的是静态链接库。

我们首先要获取libxml2的源代码，再对他进行构建，然后是使用它。

### Libxml2
笔者是从github上先clone了一个，后来使用github上relese版本的进行编译了。
```sh
git clone git@github.com:GNOME/libxml2.git
git clone git://git.gnome.org/libxml2
```
我下载版本为[2.9.9（点击下载）](https://github.com/GNOME/libxml2/archive/v2.9.9.tar.gz)

第三方库的构建一般采用`./configure & make & make install`三部曲完成。该库源码中存在一个`autogen.sh`的自动配置脚本文件。在autoconf成功后，根据提示运行make（若在make最后显示缺少Python.h，则检查usr/include目录下是否能找到Python.h，如没有，则运行`apt-get install python-dev`）。

![配置过程](https://raw.githubusercontent.com/Changes729/Diary/master/image/Libxml_autogen.sh.gif?token=AFMHNRHUJVLRXKQ3OJV6PYC5ACN5C)

最后运行 `make install`，成功后可以在C代码中引用第三方库的.h，并且在编译时，成功链接第三方库来。可以检查以下`/usr/local/include`目录与`/usr/local/lib`目录下是否有libxml相关目录与库。如下图所示：
![LIBXML2成功配置示意图](https://raw.githubusercontent.com/Changes729/Diary/master/image/libxml%E6%88%90%E5%8A%9F%E9%85%8D%E7%BD%AE%E7%A4%BA%E6%84%8F%E5%9B%BE.png?token=AFMHNRG7E4K4SQWXOWQNX425ACN7G)

按上图配置完成后，在`CMakeLists.txt`中添加如下内容（注:Linux下库文件命名为libxxx.a或libxxx.so，实际库链接时不输入开头的`lib`）：
```cmake
# 添加第三方的库
SET(INC_DIR /usr/local/include/libxml2/)  
SET(LINK_DIR /usr/local/lib)

LINK_LIBRARIES(xml2)

# 将第三方的库链接到可执行文件
TARGET_LINK_LIBRARIES(${PROJECT_NAME} xml2)
```

### API
假定输入XML文件如下所示：
```XML
<?xml version="1.0"?>
<userInfoList>
  <userInfoNode>
    <name>Akashi</name>
    <number>34501</number>
    <age>41</age>
    <country>Japan</country>
  </userInfoNode>
  <userInfoNode>
    <name>Alfred</name>
    <number>8100</number>
    <age>34</age>
    <country>USA</country>
  </userInfoNode>
  <userInfoNode>
    <name>Dats</name>
    <number>709314</number>
    <age>52</age>
    <country>Mozambique</country>
  </userInfoNode>
  <userInfoNode>
    <name>Finlay</name>
    <number>124679</number>
    <age>24</age>
    <country>USA</country>
  </userInfoNode>
  <userInfoNode>
    <name>Gypsy</name>
    <number>8134</number>
    <age>27</age>
    <country>UK</country>
  </userInfoNode>
  <userInfoNode>
    <name>Manhattan</name>
    <number>9047967</number>
    <age>36</age>
    <country>Sudan</country>
  </userInfoNode>
  <userInfoNode>
    <name>Tatum</name>
    <number>9034561</number>
    <age>29</age>
    <country>UK</country>
  </userInfoNode>
  <userInfoNode>
    <name>Will</name>
    <number>589620</number>
    <age>37</age>
    <country>China</country>
  </userInfoNode>
  <userInfoNode>
    <name>Yedda</name>
    <number>8098</number>
    <age>31</age>
    <country>Dubai</country>
  </userInfoNode>
</userInfoList>
```
代码最开始时，应该将下面两行代码写入：
```c
/* XML全局配置，默认忽略空白文本读入、允许树状输出 */
xmlKeepBlanksDefault(0);
xmlIndentTreeOutput = 1;
```
若不写入，则从XML文件读取时，libxml可能会将尾行空格等数据加载为`xmlNode`,同时在输出时，将会是**整行输出**。我们来说明以下XML文档同代码中描述类型的关系：
```xml
<userInfoList>
  <userInfoNode>
    <name>Akashi</name>
    <number>34501</number>
    <age>41</age>
    <country>Japan</country>
  </userInfoNode>
  <userInfoNode>
    <name>Alfred</name>
    <number>8100</number>
    <age>34</age>
    <country>USA</country>
  </userInfoNode>
</userInfoList>
```
`userInfoList`是XML文档的根元素。它包含了多个`userInfoNode`结点元素，一个`userInfoNode`元素内部，含有四个属性结点，分别是`name`,`number`,`age`和`country`。如果我们想要获取到country的值，那么数据流程应该如下所示：
```c
//FLOW:读取文件
xmlDocPtr  pDoc = xmlReadFile(XML_PATH, "UTF-8", XML_PARSE_RECOVER);

//FLOW:获取根结点元素（userInfoList）下的第一个子结点（userInfoNode）。
xmlNodePtr pNode = xmlDocGetRootElement(pDoc)->xmlChildrenNode; 

//FLOW:获取上面结点中第一个子结点，也就是<name>Akashi</name>
//     然后使用next指针，一个个获取到尾部的结点<country>Japan</country>
xmlNodePtr pName = pNode->xmlChildrenNode;
xmlNodePtr pNumber = pName->next;
xmlNodePtr pAge = pNumber->next;
xmlNodePtr pCountry = pAge->next;

//FLOW:获取结点内的数据
message = (char *)xmlNodeGetContent(pCountry);

//FLOW:资源释放
xmlFreeDoc(pDoc);
```
如果我们需要将数据保存为上面那种类型格式，就需要按下面步骤进行：
```c
//FLOW:新建一个xml文档描述数据（xmlDoc），设置文档根结点（rootNode）
xmlDocPtr pDoc = xmlNewDoc((xmlChar *)"1.0");
xmlNodePtr pRootNode = xmlNewNode(NULL, (xmlChar *)"userInfoList");
xmlDocSetRootElement(pDoc, pRootNode);

//FLOW:顺序写入
while (pUserList != NULL)
{
  //FLOW:设置结点标签，添加结点至根结点，添加字节点标签与内容
  xmlNodePtr pNode = xmlNewNode(NULL, (xmlChar *) "userInfoNode");
  xmlAddChild(pRootNode, pNode);
  xmlNewTextChild(pNode, NULL, (xmlChar *) "name", (xmlChar *) pUserList->name);
  xmlNewTextChild(pNode, NULL, (xmlChar *) "number", (xmlChar *) pUserList->number);
  xmlNewTextChild(pNode, NULL, (xmlChar *) "age", (xmlChar *) pUserList->age);
  xmlNewTextChild(pNode, NULL, (xmlChar *) "country", (xmlChar *) pUserList->country);
  pUserList = pUserList->pNext;
}

//FLOW:文本写入
int nRel = xmlSaveFormatFile("CreatedXml.xml", pDoc, 1);
if (nRel != -1)
{
  printf("已保存%d个字节\n", nRel);
}

//FLOW:资源释放
xmlFreeDoc(pDoc);
```
libxml对xml文档的数据是在堆中申请出来的，所以`xmlNewDoc()`函数和`xmlFreeDoc()`就像`new`和`free`一样成对出现。需要提到的是，如果想要在xmlDoc数据中删除某一个结点，那么在修改结点指针操作后，还需要使用`xmlFreeNode()`手动释放欲删除结点的内存。

### Valgrind
Valgrind是一款用于内存调试、内存泄漏检测以及性能分析的软件开发工具。获取只需要`apt install valgrind`即可。使用时，比如目标C程序是a.out，运行
```sh
valgrind --leak-check=full a.out
```
![Valgrind使用效果](https://raw.githubusercontent.com/Changes729/Diary/master/image/Valgrind%E4%BD%BF%E7%94%A8%E6%95%88%E6%9E%9C.gif?token=AFMHNRGY36A3CV5YV5S2PPS5ACOAS)

### std::List
标准库容器可以很好的支持C++语法。简单来说，像Vector，List，Map这类的顺序容器，都支持迭代器算法以及标准库算法。不过，使用C++就需要有好的类设计，代码量自然而然就会变大。

这里将基础类如下设计：
```cpp
class UserInfoNode
{
public:
  UserInfoNode();
  UserInfoNode(char *userInfoString);
  UserInfoNode(char *name, char *number, char *age, char *country);
  UserInfoNode(const UserInfoNode &userInfoNode);
  virtual ~UserInfoNode();

  static char *UserInfoStrFilter(char *message);

  void setName();
  void setNumber();
  void setAge();
  void setCountry();
  char *getName();
  char *getNumber();
  char *getAge();
  char *getCountry();
  void SetInfo(char *name, char *number, char *age, char *country);
  void Print();

  // List中Sort调用该函数
  bool operator< (const UserInfoNode& node);

protected:
  char *_name;
  char *_number;
  char *_age;
  char *_country;
};
```
三种构造函数分别对应了`不需要初始化`、`使用类似Will;589620;37;China的文本方式初始化`以及`逐项初始化`的方案。因为类内基本元素数据类型是指针类型，所以需要手动编写拷贝构造函数，实现深拷贝。`virtual`修饰析构函数，可以在特殊情况下，调用派生类的析构函数，_以保证不会出现内存泄漏的问题_，是一种好的编程习惯。

在一堆设置器取得器之下，我们编写了`operator<()`函数，这个函数在调用`std::sort()`函数时会被隐式调用，以达到排序的目的。

我们将主描述类设计成如下形式：
```cpp
class UserInfoFile
{
private:
  #define ROOT_NODE_NAME "userInfoList"
  #define INFO_NODE_NAME "userInfoNode"
  
  string _fileURL;
  xmlDocPtr _pDoc;
  list<UserInfoNode> _userInfoList;

public:
  UserInfoFile();
  UserInfoFile(string url);
  ~UserInfoFile();

  void ReadFile(string url,
                string encoding = "UTF-8",
                int options = XML_PARSE_RECOVER);
  void SaveFile(string url = "");
  void AddOneNode(const UserInfoNode &node, unsigned int lo);
  void EraseOneNode(unsigned int lo);
  void Sort();
  void PrintList();

private:
  xmlNodePtr _ReadNode(xmlNodePtr pNode);
};
```
按照功能要求，基本需要完成文档的读取功能、保存文档的功能、添加删除功能以及排序的功能。

添加和排序均需要在**任意位置**添加或删除。因此，我们使用`begin()`函数获得List的迭代器，再通过`std::advance()`函数，在begin迭代器的基础上，往后迭代任意位置，最后通过`std::insert()`与`std::erase()`函数实现任意位置的添加和删除。

## 版本
2019年6月5日:最终定稿上传