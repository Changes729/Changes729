> 相关链接：
>
> - 机械臂供应商：[ABB Robots](https://webshop.robotics.abb.com/)、[Fanuc](https://www.fanucamerica.com/)、[安川](https://www.yaskawa.com.cn/)、[KUKA](https://www.kuka.com/zh-cn)、新松、埃夫特、新时达、埃斯顿
>   - [Developer Center](https://developercenter.robotstudio.com/)
> - [【ABB工业机器人】高级应用系统课程](https://www.bilibili.com/video/BV1ZJ41167yu?p=10&spm_id_from=pageDriver)

# 机械臂

## ABB 机械臂硬件构成：

机器人主体

![img](../../../../../../Changes729_image/raw/main/ln/README/irb-1100da9662f1c1f463c09537ff0000433538.jpg)

示教器（FlexPendant）<img src="../../../../../../Changes729_image/raw/main/ln/README/1132311_153100830.png" alt="ABB机器人配件备件示教器3HAC028357-001（DSQC679）" style="zoom:50%;" />

控制柜<img src="../../../../../../Changes729_image/raw/main/ln/README/presentation.jpeg" alt="img" style="zoom:50%;" />

## 机械臂类型

- 平面关节机器人（SCARA Robot）
- 并联机器人、蜘蛛手（Parallel Robot）
- 直角坐标系机器人（Linear Robot）
- 关节坐标式机器人（Articulated Robot）
- 圆柱坐标式机器人（Cylindrical Robot）
- 协同机器人（Dual-Arm Robot）



## 示教器构成

- 连接器、触摸屏、紧急停止按钮、控制感、USB、使动装置、触摸笔、重置按钮



## 机械臂选型

- 手臂运动轴数
- 有效负载
- 手臂负载
- 运动范围（臂展）：手臂运动范围，最终轴的**中心计算**的。
- 安装方式
- 重复定位精度
- 最大运动速度
- 通讯方式
- 软件选型（一些控制模块需要联系厂商加载）



## 软件

- RobotStudio （无Linux）


## 机器人安全

- 操作安全
    - 急停
    - 灭火：二氧化碳灭火
    - 关闭电源
    - 移动机器人：安全围栏
    - 手动操作的习惯
- 工作中的安全
    - 自身安全：保护人
        - 工作区域内操作模式切换为手动
        - 进入保护区时，控制器随身携带
    - 设备安全：保护设备
    - 手动模式下的安全
        - 手动减速模式
        - 手动全速模式：所有人员都位于安全保护空间之外时使用，而且操作员要有培训过
    - 自动模式下的安全
- 安全部件
    - 急停按钮
    - 双手按钮
    - 安全门锁
    - 安全光幕
    - 安全传感器
    - 安全地毯



## 机器人运动方式

- 触发方式：菜单栏-手动操作（Jogging）-动作模式
- 单轴运动：示教器上1～3一组，4～6一组，需要手动切换。三轴分别是，上下左右与旋转。
    - 更新计数器：槽口对齐，菜单栏-校准（Calibration）-手动高级-更新旋转计数器（Update Revolution Counters）
- 线性运动：
    - 速度增量：示教器的按钮处（---），有无、小、中、大、自定义等速度增量
- 重定位运动：固定点重姿态运动
    - 坐标系：工具坐标，自定义的，大小和重心等。
    - 位置格式：欧拉角

机器人状态快捷方式：
- 机器人工具、坐标系等选择
- 机器人移动增量选择
- 机器人程序运动选择
- 机器人步进模式选择
- 机器人调速
- 机器人程序控制


## 机器人编程

| 模块名称    | 模块类型 | 功能说明                                   |
| ----------- | -------- | ------------------------------------------ |
| MainModule  | 程序模块 | 主模块                                     |
| Module_Data | 程序模块 | 编程习惯存放数据模块                       |
| Mtrap       | 程序模块 | 中断功能                                   |
| Robs_A      | 程序模块 | A产品对应的模块                            |
| Robs_B      | 程序模块 | B产品对应的模块                            |
| Robs_C      | 程序模块 | C产品对应的模块                            |
| Robs_Pick   | 程序模块 | 机器人取料模块                             |
| Robs_Place  | 程序模块 | 机器人放料模块                             |
| UTLITY      | 程序模块 | 公共函数                                   |
| Base        | 系统模块 | 系统模块，定义了 toolo、wobj0、load0的数据 |
| Sys_ModuleC | 系统模块 | 自定义功能                                 |

- 程序与结构：编程语言 RAPID、系统模块和程序模块、程序模块中包含程序和数据，数据在菜单栏-程序数据中管理和建立。系统模块在机器人启动时启动。模块好像是各个C文件模块，Task就是一个工程。
- 程序模块
- 创建程序
    - 程序属性：SYSMODULE(系统模块)、NOSTEPIN(不能单步执行)、NOVIEW(可执行但不能显示)、VIEWONLY(可显示但不能修改)。
    - 程序包括：程序（Program）、功能（Function）以及中断（Interrupt）
    - RobotStudio中，程序（Program）是脚本，是执行过程。而功能（Function）才是我们写的函数。
- RobotStudio创建程序模块
- 常用数据类型
    - 整型：NUM、DNUM(视频中说是32位整数，但是范围又不是32位的，很奇怪)
    - BOOL
    - Byte
    - String：最大80个字符
    - Clock：
    - Jointtarget：关节位置数据
    - Robotarget：机器人与外轴的位置数据
    - Speeddata：速度数据
    - Tooldata：工具数据
    - Wobjdata：工件数据
    - Loaddata：负荷数据
    - Pos：位置数据
- 示教器创建数据类型
    - 数据作用域：全局（Global）、局部（Local）、任务（Task）
    - 数据类型：变量（varibale）、可变量（persistent）就是 static 前缀、常量（constant）
- 工具数据 ToolData
    - TCP坐标：tframe.trans(mm)
    - 姿态数据：tframe.rot
    - 工具重量：tload.mass(kg)
    - 工具重心：tload.cog(mm)
    - 力矩轴方向：tload.aom
    - 转动力矩：tload.i[xyz](kgm^2)
    - 数据定义：
        - 4点法：不改变 Tool0 的坐标方向：通过4个不同的角度位置，确定工具方向
        - 5点法：改变 tool0 的z方向：在4点法基础上，移动位置，确定x轴方向（如沿着X移动）
        - 6点法：改变 tool0 的X和Z方向：在5点法基础上，移动位置，确定z方向（如沿着Z移动）
    - 新建工具：菜单栏-手动操作-工具坐标-新建(初始值，Initial Value)/编辑
        - 软件工具依赖建模，实际操作需要不断抬起，放下去获取点位。
- 工件数据 WobjData
    - 工件坐标系：oframe.trans
    - 工件坐标姿态：oframe.rot
    - 数据定义：3点法
    - 新建工具：菜单栏-手动操作-工件坐标-新建(初始值，Initial Value)/编辑
- 有效载荷 LoadData
    - 加载载荷（GripLoad LoadFull），清楚载荷（GripLoad Load0）
    - 载荷数据设定方法
        - 直接输入法：菜单-手动操纵-有效载荷-新建（质量和重心）
        - 调用服务例行程序自动完成：程序编辑器-模块-程序-调试-调用例行服务程序（LoadIdentify）（手动-电机开启时，点击运行），可以测算工具或者负载
- 机器人坐标
    - 大地坐标系
    - 基坐标系
    - 工具坐标系
    - 工件坐标系
- ~~ABB机器人备份文件夹~~
- 程序模块导入机器人控制器
    - 联机：控制器-添加控制器-一键联机

## 运动指令

- MOVEL:MOVE Line 线性移动
- MOVEJ:轴移动*
- MOVEC:绕点移动
- MOVEAbsJ:移动到绝对位置*


### 一些术语

- 运动轴：机器人轴、基座轴、工装轴（变位机）
- 机器人柜（控制柜）



## 必要操作

- [x] 开关机：旋转电源
- [x] 模式选择（自动/手动/<u>手动全速</u>）
- [x] 急停开关与接触报警：按下和旋转
- [x] 电机重启：按下重启按钮
- [x] 示教器查看机器状态：位于示教器节目上方
- [x] 连线/拆线操作
  - [x] 示教器链接控制柜
  - [x] 伺服电机供电
  - [x] SMB（Server Message Block，伺服器訊息區塊）连接线
  - [x] 气管
  - [x] 主电路电缆
  - [ ] 网线
  - [ ] IO
