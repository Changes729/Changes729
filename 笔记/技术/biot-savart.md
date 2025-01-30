> 开源代码：[biot-savart](https://github.com/vuthalab/biot-savart)

# biot-savart

## 总评

从设计上来说，这个库可以跟 numpy 依赖，但是跟 matplotlib 的部分需要拆分出来。

对于初学者来说，这份代码有助于学习numpy、matplotlib的一些函数，加深对于python的理解。同时，算法中使用了理查德森外推法（Richardson Extrapolation），算是一个基础算法值得学习。

最后，推荐阅读这篇文章的人有一定的Python基础、线性代数基础和大学物理电磁学基础（大学物理也要求微积分基础）。

——知道什么是数组，以及能够理解多维数组；知道Python文件读写方式；知道python元组；知道python的一些语法糖。

——知道什么是矩阵乘法、知道什么是转秩

——了解基础微积分，了解电磁学的比尔萨法尔定律（biot-savart law）



## Examples

```sh
# coil.txt
0,0,0,1
10,0,0,1
10,10,0,1
20,10,0,1
```

```python
import biot_savart_v4_3 as bs

# 读取线圈，设置保存文件名称，设置盒模型，设置起始点，最后设置分辨率。这个函数计算后，结果会存在一个叫 `targetvol` 的文件中。
bs.write_target_volume("coil.txt", "targetvol", (30, 15, 15), (-5, -0.5, -2.5), 1, 1)

# 绘制线圈
bs.plot_coil("coil.txt")

# 从文件中读取场量
volume = bs.read_target_volume("targetvol")

# 综合绘制场量图形
#!!! 这里有个显示 BUG，希望大家看完代码后能知道这里的 BUG 是什么
bs.plot_fields(volume, (30, 15, 15), (-5, -0.5, -2.5), 1, which_plane='x', level=5, num_contours=50)
```

这里三个代码是相互独立的。我们先看绘制线圈的代码：

### 线圈数据结构

```python
# ‘*’表示支持输入多个参数，并存放在一个元组中
def plot_coil(*input_filenames):
  	# 设置一个画面，画面有 1*1 个槽；将画面放置在第 1 个槽上。
    fig = plt.figure()
    tick_spacing = 2
    ax = fig.add_subplot(111, projection='3d')
    ax.set_xlabel("$x$ (cm)")
    ax.set_ylabel("$y$ (cm)")
    ax.set_zlabel("$z$ (cm)")

    # 遍历文件列表，通过 parse_coil 读取成数组，然后3D显示；
    # 需要注意的是，plot3D是按照X、Y、Z三轴的数组分别输入的。
    # 'lw = line width'
    for input_filename in input_filenames:
        coil_points = np.array(parse_coil(input_filename))
        ax.plot3D(coil_points[0,:],coil_points[1,:],coil_points[2,:],lw=2)

    # 设置多刻度尺，单位2
    for axis in [ax.xaxis,ax.yaxis,ax.zaxis]:
        axis.set_major_locator(ticker.MultipleLocator(tick_spacing))

    # 调整填充
    plt.tight_layout()
    plt.show()
```

这个部分我们重点看一下 `parse_coil` 的函数实现和返回的数据结构。一整行可能看的会比较吃力，我们稍微修改一下：

```python
def parse_coil(filename):
    with open(filename, "r") as f: return np.array([[eval(i) for i in line.split(",")] for line in f.read().splitlines()]).T
```

可以看到，这个函数是通过 `splitlines()` 按行读取，然后再通过 `line.split(",")` 分成二维数组。最后通过 numpy 的转秩操作调换矩阵方向。也就是说，虽然文件里的数据可能以 `x,y,z,I` 的方式进行排列，但是通过这个函数处理之后，数据就变成了列项。

```sh
# coil.txt
# x,y,z,I
0,0,0,1
10,0,0,1
10,10,0,1
20,10,0,1

# print(parse_coil("coil.txt"))
[[ 0 10 10 20]
 [ 0  0 10 10]
 [ 0  0  0  0]
 [ 1  1  1  1]]
```



### 场量数据结构

从上面我们知道了线圈的数据结构是由点构成的。然后我们来看一下场量的数据结构：

```python
def read_target_volume(filename):
    targetVolume = None

    try:
        with open(filename, "rb") as f:
            targetVolume = np.load(f)
        return targetVolume
    except:
        pass
```

可以看到，文件是二进制存储的numpy数据结构。直接打印出来看一下：

```python
volume = bs.read_target_volume("targetvol")
print(volume.shape)
# (31, 16, 16, 3)
```

然后我们看一下数据是如何绘制的：

```python
# 输入一个场量，设置空间大小为 (30, 15, 15) cm，设置起始点为 (-5, -0.5, -2.5)
# 设置分辨率为 1cm，设置沿 Y-Z 方向，X 距离 5cm，设置最大轮廓数量为 50 个
bs.plot_fields(volume, (30, 15, 15), (-5, -0.5, -2.5), 1, which_plane='x', level=5, num_contours=50)

def plot_fields(Bfields,box_size,start_point,vol_resolution,which_plane='z',level=0,num_contours=50):
  	# 在 X、Y、Z 三个方向上分别设置相应分辨率细分
    X = np.linspace(start_point[0], box_size[0] + start_point[0],int(box_size[0]/vol_resolution)+1)
    Y = np.linspace(start_point[1], box_size[1] + start_point[1],int(box_size[1]/vol_resolution)+1)
    Z = np.linspace(start_point[2], box_size[2] + start_point[2],int(box_size[2]/vol_resolution)+1)

    # 如果选择 X 平面，那么压缩 X 的数据；同时提取 Y、Z 点上的（x,y,z）矢量。
    if which_plane=='x':
        converted_level = np.where(X >= level)
        B_sliced = [Bfields[converted_level[0][0],:,:,i].T for i in range(3)]
        x_label,y_label = "y","z"
        x_array,y_array = Y,Z
    elif which_plane=='y':
        converted_level = np.where(Y >= level)
        B_sliced = [Bfields[:,converted_level[0][0],:,i].T for i in range(3)]
        x_label,y_label = "x","z"
        x_array,y_array = X,Z
    else:
        converted_level = np.where(Z >= level)
        B_sliced = [Bfields[:,:,converted_level[0][0],i].T for i in range(3)]
        x_label,y_label = "x","y"
        x_array,y_array = X,Y

    # 取最大值和最小值
    Bmin,Bmax = np.amin(B_sliced),np.amax(B_sliced)

    # 创建一个画布，设置为4幅图，其中设置y轴单位统一为 cm
    component_labels = ['x','y','z']
    fig,axes = plt.subplots(nrows=1,ncols=4,figsize=(10,5))
    axes[0].set_ylabel(y_label + " (cm)")

    # 分别绘制（x,y,z）场等高线
    for i in range(3):
        contours = axes[i].contourf(x_array,y_array,B_sliced[i],
                                    vmin=Bmin,vmax=Bmax,
                                    cmap=cm.magma,levels=num_contours)
        axes[i].set_xlabel(x_label + " (cm)")
        axes[i].set_title("$\mathcal{B}$"+"$_{}$".format(component_labels[i]))
		
    # 设置最后一幅图为条状（20:1）
    axes[3].set_aspect(20)
    fig.colorbar(contours,cax=axes[3],extend='both')

    plt.tight_layout()
    plt.show()
```



## 线圈磁场算法

现在知道了线圈的数据结构，同时也了解了磁场的数据存储结构，那么现在会过来看具体的算法实现：

```python
# 设置线圈文件路径；场数据存储文件；盒大小；起始点；线圈分辨率和场分辨率。
bs.write_target_volume("coil.txt", "targetvol", (30, 15, 15), (-5, -0.5, -2.5), 1, 1)

def write_target_volume(input_filename,output_filename, box_size, start_point,
                        coil_resolution=1, volume_resolution=1):
  	# 获取线圈
    coil = parse_coil(input_filename)
    # 细分线圈
    chopped = slice_coil(coil, coil_resolution)
    # 根据细分线圈；盒大小；起始点和场分辨率，计算具体场量。
    targetVolume = produce_target_volume(chopped, box_size, start_point, volume_resolution)

    with open(output_filename, "wb") as f: np.save(f, targetVolume)
```

然后是最重要的函数 `produce_target_volume`

```python
def produce_target_volume(coil, box_size, start_point, vol_resolution):
  	# 细分盒模型
    x = np.linspace(start_point[0], box_size[0] + start_point[0],int(box_size[0]/vol_resolution)+1)
    y = np.linspace(start_point[1], box_size[1] + start_point[1],int(box_size[1]/vol_resolution)+1)
    z = np.linspace(start_point[2], box_size[2] + start_point[2],int(box_size[2]/vol_resolution)+1)

    # 从坐标向量返回坐标矩阵的列表
    Z, Y, X = np.meshgrid(z, y, x, indexing='ij')

    return calculate_field(coil, X,Y,Z)
```

通过点构建网络，然后将网络和导线网络导入 `calculate_field` 进行计算。

```python
# 传入的 start、end 是一个一维坐标数组
def bs_integrate(start, end):
	dl = (end-start).T
  mid = (start+end)/2
  # 基于中点，构建全场域矢量
  position = np.array((x-mid[0], y-mid[1], z-mid[2])).T
  # 单位矢量绝对值
  mag = np.sqrt((x-mid[0])**2 + (y-mid[1])**2 + (z-mid[2])**2)

  # Biot-Savart Law，start[3] 是电流 I
  # 注意，这里dl；position都是已经转秩过的；所以后面构造 (x,y,z) 矢量的时候需要转秩
  return start[3] * np.cross(dl[:3], position) / np.array((mag ** 3, mag ** 3, mag ** 3)).T

def calculate_field(coil, x, y, z):
  B = 0
  FACTOR = 0.1 # 见最后返回值的解析

  # 等差构造离散点，下面要用理查德森外推法（Richardson Extrapolation）提高精度
  # 这里 coil 是已经转秩过的
  starts, mids, ends = coil[:,:-1:2], coil[:,1::2], coil[:,2::2]

  # 使用 np.nditer 获取点且快速遍历；
  # 'F order' 表示横向顺序。如 [[0,1],[2,3]] 会输出 0,1,2,3
  # 'C order' 表示纵向顺序。如 [[0,1],[2,3]] 会输出 0,2,1,3
  # 理查德森外推法（Richardson Extrapolation）- richardson extrapolated midpoint rule
  for start, mid, end in np.nditer([starts, mids, ends], flags=['external_loop'], order='F'):
    fullpart = bs_integrate(start, end) 
    halfpart = bs_integrate(start, mid) + bs_integrate(mid, end)
    B += 4/3 * halfpart - 1/3 * fullpart 

  # 单位调整：电流单位 A；距离单位 cm；磁感应强度单位 G(高斯) = 10^-4T(特斯拉) 
  # 根据 biot-Savart 公式，cm -> m 单位在公式中需要乘以系数 10^2; 而真空磁导率 mu_0 / 4pi = 10^-7，所以最终的系数为 0.1
  return B * FACTOR
```



关于 `'ij'` 索引和 `'xy'` 索引：其实是有个转秩的关系。

```python
import numpy as np

nx, ny = (3, 2)
x = np.linspace(0, 1, nx)
y = np.linspace(0, 1, ny)
xv, yv = np.meshgrid(x, y, indexing="xy")
print(xv)
print(yv)

'''
[[0.  0.5 1. ]
 [0.  0.5 1. ]]
[[0. 0. 0.]
 [1. 1. 1.]]
'''

xv, yv = np.meshgrid(x, y, indexing="ij")
print(xv)
print(yv)

'''
[[0.  0. ]
 [0.5 0.5]
 [1.  1. ]]
[[0. 1.]
 [0. 1.]
 [0. 1.]]
'''
```



## API List

- [numpy.cross](https://numpy.org/doc/stable/reference/generated/numpy.cross.html)：两个向量差乘。向量形状要一样。
- [numpy.nditer](https://numpy.org/doc/stable/reference/generated/numpy.nditer.html)：使多维数组的遍历变的更便捷（因为一些多维矩阵有不同的排布方式）
  - [Iterating over arrays](https://numpy.org/doc/stable/reference/arrays.nditer.html#arrays-nditer)
- [numpy.meshgrid](https://numpy.org/doc/stable/reference/generated/numpy.meshgrid.html)：通过单维数组构建数据矩阵
- [Richardson Extrapolation（理查德森外推法）的积分应用](https://zhuanlan.zhihu.com/p/629950100)：介绍了什么是理查德森外推法，以及有什么用。



## 存留问题

- Python NumPy 转秩其实不太容易看出来，有没有什么写法可以让转秩、非转秩的数组更容易被我们认识呢？
- C++ 如何实现这个算法？C++ 有类似 NumPy 的函数库吗？