> 参考资料：
>
> - [ ] [卷积神经网络（Convolutional Neural Network, CNN）](https://www.tensorflow.org/tutorials/images/cnn?hl=zh-cn)：CNN 图像分类
>   - [ ] [TinyML on Arduino and STM32: CNN (Convolutional Neural Network) example](https://eloquentarduino.github.io/2020/11/tinyml-on-arduino-and-stm32-cnn-convolutional-neural-network-example/)
> - [ ] [Hand Gesture Recognition on ESP32-S3 with ESP-Deep Learning](https://blog.espressif.com/hand-gesture-recognition-on-esp32-s3-with-esp-deep-learning-176d7e13fd37)
> - [ ] [Arduino_TensorFlowLite_ESP32](https://github.com/tanakamasayuki/Arduino_TensorFlowLite_ESP32)
> - [ ] **[tinyml-on-the-edge](https://github.com/jaredmaks/tinyml-on-the-edge)**
> - [x] [ArduinoTensorFlowLiteTutorials](https://github.com/arduino/ArduinoTensorFlowLiteTutorials)：入门教程，走流程的
>   - [Colab](https://colab.research.google.com/drive/17_voeGDplhO8GryyTaQzbJBtodRqaOqr#scrollTo=9J33uwpNtAku)
> - [ ] **[IMU_GestureClassifier](https://github.com/humberto-trujillo/IMU_GestureClassifier)**
> - [ ] [Gesture Recognition Toolkit (GRT)](https://github.com/nickgillian/grt)

# TinyML

## Layers

### **Convolution layers 卷积层**

`Conv2D` 卷积层

- **filters**：输出空间的维度数；每个过滤器会作用于输入数据，最终形成特征图。

  > Q：如何理解 filters？是什么（在数学过程中）？有什么用（在具体应用中）
  >
  > A：现在理解，filters 好像是一种随机权重，在每一次神经网络迭代时，也会迭代过滤器中的权重，以至于到最后，过滤器可以看作特征、分类器的根本。过滤器越多，越能把握数据的特征，但是所需要的运算和中间数据存储也越多。
  >
  > [What does the filter parameter mean in Conv2d layer?](https://stackoverflow.com/questions/67439067/what-does-the-filter-parameter-mean-in-conv2d-layer)
  >
  > [CS231n Convolutional Neural Networks for Visual Recognition](https://cs231n.github.io/)
  >
  > [Understanding the Convolutional Filter Operation in CNN's](https://medium.com/advanced-deep-learning/cnn-operation-with-2-kernels-resulting-in-2-feature-mapsunderstanding-the-convolutional-filter-c4aad26cf32)
  >
  > [In CNN, why do we increase the number of filters in deeper Convolution layers for complex images?](https://datascience.stackexchange.com/questions/55545/in-cnn-why-do-we-increase-the-number-of-filters-in-deeper-convolution-layers-fo)

- **kernel_size**：卷积窗

- **strides**：卷积步长，一般为 1



### Pooling layers 池化层

`MaxPooling2D` 最大池化

> Q：什么是池化？为什么要池化？池化的影响？
>
> A：池化（Pooling）作为学术名词，表示将资源分组在一起的过程。在深度学习中，池化将特定大小的矩阵内的数据分组在一起，而达到减小数据量的效果。根据文章说明，池化可以帮助减小数据量，提高运算速度，避免过拟合等效果。但是还是不清楚池化的数学原理。这里我们用的是最大池化，还有平均池化。
>
> [Max Pooling In Convolutional Neural Networks](https://deeplizard.com/learn/video/ZjM_XQa5s6s)