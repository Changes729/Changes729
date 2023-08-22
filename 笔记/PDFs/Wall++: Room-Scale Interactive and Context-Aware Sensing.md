> 文章来源：https://chrisharrison.net/projects/wallplusplus/wallplusplus.pdf

# Wall++: Room-Scale Interactive and Context-Aware Sensing

> Despite its high conductivity, we removed silver paint from consideration  due  to  its  high  cost  (~$200  per  m2).  Carbon  paint was also eliminated due to its high resistance, which is incompatible  with  our  technique.  Among  the  remaining  two nickel-based paints, we selected the water-based version, as it produced less odor and resulted in a smoother finish (Figure 2, bottom photos).

四种材料——碳、水性镍（water-based nickel）、丙烯酸镍、银漆。其中，银漆价格高，碳电阻高，丙烯酸镍具有挥发性，且质地不如水性镍平整。

> Application Method and Number of Coats With our conductive paint selected, we next considered its application  method.  We  varied  both  the  number  of  coats and  the  tool  used,  both  of  which  affect  conductivity.  We tested  brush,  spray,  and  roller  applications  with  one,  two, and  three  coats,  resulting  in  a  3×3  test.  Figure  3  shows these  results,  which  consistently  indicate  that  the  surface conductivity  increases  with  number  of  painted  coats. Among  the  application  methods,  we  selected  roller  painting, as it resulted in the highest conductivity and lower variance  across  the  surface.  As  an  added  benefit,  it  was  also the fastest application method.

使用滚刷的方式涂墙。

> In the insulation test, we found that our nickel traces interacted with the latex paint and primer conditions, causing shorts, **though it worked fine with vinyl stickers.** Silver traces worked with all insulators, but had high variance in conductivity. Copper had the worst insulation due to a larger overlapping area, but the least variance, and for this reason, we chose it in combination with vinyl stickers (the most consistent of the insulators we tested).

三种引线：铜条、镍漆、银漆。镍漆会短路，但是乙烯基贴条效果比较好，铜条也容易短路。银电导率差异很大。最终选用铜+乙烯基贴条。

> Phases  5  and  6  were  primarily  focused  on  mutual  capacitance sensing. In this design phase, we wished to verify that our  selected  diamond  pattern  could  robustly  capture  airborne  EM  signals.  There  are  many  ways  to  configure  diamond patterns into an antenna array. For example, we could connect  all  columns  and  rows  together  to  make  one  large antenna.  However,  this  monolithic  antenna  eliminates  the possibility of triangulating signal sources, discussed later.
> Therefore, we investigated the idea of selecting a subset of diamond columns as antennas (as illustrated in Figure 1F). These need not be single columns, but could be several adjacent columns connected together. To see if this improved

最终，他们选择 70mm 大小的天线平面+48mm的间隙（一个标准电工胶带的宽度）。

> **Mutual Capacitance Sensing** 
>
> To detect a user’s hands and body pose, we use **mutual capacitance sensing**, which measures the capacitance between two electrodes [6,8]. This sensing technique is the basis of modern  touchscreens  as  seen  in  smartphones  and  tablets. When  a  body  part  is  near  a  transmitter-receiver  pair,  it  interferes  with  the  projected  electric  field,  reducing  the  received  current,  which  can  be  measured.  This  is  referred  to as shunting mode [65,66,83] sensing. On the other hand, if the user’s body directly touches an electrode, it greatly increases the capacitance and received current. See [21] for a more thorough review of capacitive sensing in HCI.
> In  capacitive  sensing  mode,  our  main  board  uses  an AD5930  [3]  DDS  to  generate  a  100 kHz  sine  wave  as  the excitation signal. This signal is amplified to 18 V peak-topeak by the multiplexing board (Figure 8B) and routed to a specified transmitter electrode column (Figure 1A, red). We use  another  set  of  multiplexers  to  connect  a  receiver  electrode row (Figure 1A, blue) to our analog frontend, which is filtered  and  amplified.  We  use  an  AD637  RMS-DC  converter  [4]  to  measure  the  amplitude  of  the  received  signal, which  correlates  to  the  capacitance  between  the  current transmitter  and  receiver  electrodes.  We  set  the  integration

互电感感测量（mutual capacitance sensing）

AD5930：100k频率发生器

AD637：RMS-to-DC（Root Mean Square to Direct Current）是一种电路或器件，用于将交流信号（通常为正弦波）转换为等效的直流信号。RMS-to-DC电路通常用于测量交流信号的有效值（RMS值）。