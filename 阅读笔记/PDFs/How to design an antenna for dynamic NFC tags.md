> 文章来源：https://www.st.com/resource/en/application_note/cd00232630-how-to-design-an-antenna-for-dynamic-nfc-tags-stmicroelectronics.pdf
>
> 参考资料：
> - [电路原理](https://www.icourse163.org/course/UESTC-500002?tid=573002)

# How to design an antenna for dynamic NFC tags

## Basic principles and equations

The energy transfer from the reader to the dynamic NFC tag chip depends on:
- how well the tag antenna is tuned, close to the reader's carrier frequency(13.56 MHz)
- the distance between the reader and the tag antenna board
- the dimensions of the reader antenna and of the tag antenna board
- the reader power
- the tag antenna orientation related to the reader antenna

At the end of the request, the reader keeps the magnetic field non modulated to power the tag, and allows it to generate an answer. To send its response back to the reader, the dynamic NFC tag chip backscatters the data to the reader by internally modulating its input impedance. Tag chip input impedance variation modulates the signal across the reader antenna due to the mutual coupling between reader and tag antennas. The reader demodulates this signal and decodes the tag answer.

All this is part of the standard protocol and is taken into account by the dynamic NFC tag chip embedded circuitry and by the RFID reader's electronics.

## How to design the antenna on a PCB

A 13.56 MHz antenna can be designed with different shapes, depending on the application requirements. As explained previously, the major parameter is the equivalent inductance $$L_A$$ of the antenna at 13.56 MHz.

The stray capacitance is difficult to approximate, but for typical NFC/RFID products is in the range of few pF.


## From design to production

- System level validation
- Considerations on the actual system tuning frequency
- PCB manufacturing process validation
- Product packaging/housing considerations

## Equations

$$frequency_{tuning} = \frac{1}{2 \pi x \sqrt{L_{antenna} x C_{tuning}}}$$

$$Z(\omega) = \.{U} / \.{I} = R + j \omega L + \frac{1}{j \omega C} = R + j(\omega L - \frac{1}{\omega C}) $$

**Inductance of a circular antenna**

$$L_{ant} = \mu_{0} x N^{1.9} x r x ln(\frac{r}{r_0})$$, where:
- $$r$$ is the radius, in millimeters
- $$r_0$$ is the wire diameter, in millimeters
- N is the number of turns
- $$\mu_0 = 4 \pi \dot 10^-7 H / m$$
- L is measured in Henry

**Inductance of a spiral antenna**

$$L_{ant} = 31.33 x \mu_0 x N^2 x \frac{a^2}{8a + 11c}$$, where:
- $$a = (r_{in} + r_{out}) / 2$$ (the average radius, in meters)
- $$c = r_{out} - r_{in}$$ is the thickness of the winding, in meters
- $$\mu_0 = 4 \pi \dot 10^-7 H / m$$
- L is measured in Henry
- N is the number of turns

**Inductance of a square antenna**

> this part please to watch the pdf.

## Nouns

- backscatters: 反向散射
- impedance: 阻抗
- self-resonant frequency: 自谐振频率
