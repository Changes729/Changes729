# numpy

- `[:, :, 0]` ：这是numpy的一种写法，表示取第一纬的所有数据，第二维的所有数据和第三维的第0个数据



## 矩阵构造

> 参考链接：
>
> - [Array creation routines](https://numpy.org/devdocs/reference/routines.array-creation.html#routines-array-creation)
> - [Array creation](https://numpy.org/devdocs/user/basics.creation.html#arrays-creation)

### 矩阵类型

- 形状矩阵：

  - 只关注矩阵形状，不关心内部数据：`np.empty`、`np.empty_like`
  - 填充重复的矩阵数据：`np.full`、`np.full_like`

- 单位矩阵：`np.eye`、`np.identity`

  > [为什么起名为 eye](https://math.stackexchange.com/questions/3028394/what-is-the-motivation-behind-naming-identity-matrix-as-eye)：因为数学中会使用 `I` 作为标准单位，而 `I` 可以用 `eye` 来拼写。

- 全1矩阵：`np.ones`、`np.ones_like`

- 全0矩阵：`np.zeros`、`np.zeros_like`

- 对角矩阵：`diagflat`

  - `diag`：取对角

- 三角矩阵：`np.tri`、`np.tril`、`np.triu`

- 范德蒙矩阵：`np.vander`



### Numpy 矩阵构造函数

- `array`：从数组构造矩阵

- `frombuffer`：从缓存中建立数组

- `fromfunction`：

  ```python
  np.fromfunction(lambda i, j: i + j, (3, 3), dtype=int)
  array([[0, 1, 2],
         [1, 2, 3],
         [2, 3, 4]])
  ```

- `fromstring`：

  ```python
  np.fromstring('1, 2', dtype=int, sep=',')
  array([1, 2])
  ```

- `arange`：

  ```python
  np.arange(3) 		# function(0,3,1)
  # array([0, 1, 2])
  np.arange(3.0) 	
  # array([ 0.,  1.,  2.])
  np.arange(3,7)	# function(3,7,1)
  # array([3, 4, 5, 6])
  np.arange(3,7,2)# function(3,7,2)
  # array([3, 5])
  ```

- `linspace`：线性空间

  ```python
  np.linspace(2.0, 3.0, num=5)
  array([2.  , 2.25, 2.5 , 2.75, 3.  ])
  np.linspace(2.0, 3.0, num=5, endpoint=False)
  array([2. ,  2.2,  2.4,  2.6,  2.8])
  np.linspace(2.0, 3.0, num=5, retstep=True)
  (array([2.  ,  2.25,  2.5 ,  2.75,  3.  ]), 0.25)
  ```

  ![../../_images/numpy-linspace-1.png](https://numpy.org/devdocs/_images/numpy-linspace-1.png)

- `logspace`：对数空间

  ![../../_images/numpy-logspace-1.png](https://numpy.org/devdocs/_images/numpy-logspace-1.png)

- `geomspace`：几何空间

  ![../../_images/numpy-geomspace-1.png](https://numpy.org/devdocs/_images/numpy-geomspace-1.png)

- `meshgrid`：网格空间

  ![../../_images/numpy-meshgrid-1_00_00.png](https://numpy.org/devdocs/_images/numpy-meshgrid-1_00_00.png)

  ![../../_images/numpy-meshgrid-1_01_00.png](https://numpy.org/devdocs/_images/numpy-meshgrid-1_01_00.png)

