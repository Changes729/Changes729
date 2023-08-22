> 参考资料：
>
> - [使用OpenCV进行轮廓检测（Python/C++）](https://learnopencv.com/contour-detection-using-opencv-python-c/#Drawing-Contours-using-CHAIN_APPROX_SIMPLE)

# opencv

- medianBlur：模糊处理
- moment：用于计算图形矩？[参考](https://en.wikipedia.org/wiki/Image_moment)
  - 这个主要是指原始矩。通过一阶矩可以计算图像几何中心（重心）
    - 所谓的矩，可以和矩阵联系起来，每个 `(x, y)` 在矩阵上有不同的权重。就是所谓的二维数组。当xy不加权，此时这个矩阵的值就是图像面积（离散）
    - 但是如果x加权，在数学上就是计算不均匀物体的重心，此时也称为x的一阶矩，同理y也有一阶矩
    - 微积分的重心计算就是x的一阶矩处以零阶矩得到的

- findContours：寻找轮廓
  - CHAIN_APPROX_SIMPLE：算法压缩沿着轮廓的水平、垂直和对角线段，只保留它们的端点。这意味着沿着直线路径的任何点都将被忽略，我们将只剩下端点。[参考](https://docs.opencv.org/4.x/d4/d73/tutorial_py_contours_begin.html) 只有四个点
  - RETR_TREE：会建立完整的父子关系（谁在里面谁在外面）
- convexHull：寻找凸包
- getPerspectiveTransform：坐标转化
- warpPerspective：透视变换

