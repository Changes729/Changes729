> *参考资料*
>
> - [手动推导全连接神经网络的反向传播算法](https://www.bilibili.com/video/BV1ZL4y1479R?share_source=copy_web)
> - [OFA-Sys](https://github.com/OFA-Sys)/**[OFA](https://github.com/OFA-Sys/OFA)**：达摩院自研发的一个统一大数据框架，用于图像识别、解释、文字生成图片等等功能。
> - [Mac给你解锁新技能之人工智能（零代码）](https://www.bilibili.com/video/BV1L3411H7GC?spm_id_from=333.1007.top_right_bar_window_custom_collection.content.click&vd_source=b736aa3d7f0fdf47b59ea3021dc810ab)
>   - [数据集](https://share.weiyun.com/gPhPEFNr)：数据集就是一个`dog`和`cat`的文件夹，聚类。
> - [VDSR、DRRN、LapSRN、RCAN、DSRN…你都掌握了吗？一文总结超分辨率分析必备经典模型（二）](https://mp.weixin.qq.com/s/hK3cXIhr-BUhn2WDYIjquQ)：超分辨率分析。
> - [如何快速稳定地从huggingface下载模型](https://zhuanlan.zhihu.com/p/647843635)：下载到本地
> - [OpenLMLab](https://github.com/OpenLMLab)/[MOSS](https://github.com/OpenLMLab/MOSS)：复旦模型，两张 3090。中文文档

# AI与统计

## 人工智能学习路径

- 基础数学：线性代数、矩阵论、概率论
- 基础方法：最优化、强化学习、深度学习
- 具体应用：视觉、定位、规划



## 关键词

- GPT-3（Generative Pre-trained Transformer 3，生成型预训练变换模型3）：是一个自回归语言模型，目的是为了使用深度学习生成人类可以理解的自然语言。



## AIGC（AI-generated Content）

- [Hugging Face](https://huggingface.co/)：一个人工智能AI社群
- [copilot](https://github.com/features/copilot)：代码人工智能辅助
- 文本转图片：
  - [Stable Diffusion](https://huggingface.co/spaces/stabilityai/stable-diffusion)：人工智能制图
    - [Magic Prompt](https://huggingface.co/spaces/Gustavosta/MagicPrompt-Stable-Diffusion)：用来生成 Prompt 的。
    - [Github](https://github.com/CompVis/stable-diffusion)
    - [civitai](https://civitai.com/)：有一些训练好的图像模型，加上评论可以出人物图
    - **[stable-diffusion-webui](https://github.com/AUTOMATIC1111/stable-diffusion-webui)**：`webui.sh` 安装和运行
  - [DALL·E 2](https://openai.com/product/dall-e-2)：文本转图片
- 音乐：
  - [Magenta](https://magenta.tensorflow.org/)：由Google开发的Magenta项目是一个开源平台，专注于将机器学习应用于创造性音乐和艺术。Magenta提供了一系列的工具、模型和教程，可以用于生成、编辑和交互式地探索音乐创作。只支持特定开发环境的Python，和JS。
  - [MuseGAN](https://salu133445.github.io/musegan/)：MuseGAN是一个开源的深度学习项目，用于生成多轨的MIDI音乐。该项目基于生成对抗网络（GAN）架构，可以学习和生成具有多个乐器轨道的音乐作品。
  - [OpenAI Juking](https://openai.com/research/jukebox)：OpenAI Juking是一个基于PyTorch的开源项目，用于生成音乐的乐句（licks）。它通过训练一个神经网络模型，学习从输入的音乐特征生成新的乐句。这个确实是音频生成音频的模型。也需要模型。
  - [OpenAI MuseNet](https://openai.com/research/musenet)：MuseNet是OpenAI开发的一个AI音乐生成模型，它可以生成多种类型和风格的音乐作品，包括交响乐、爵士乐、流行音乐等。OpenAI还提供了用于训练和使用MuseNet模型的开源代码和示例。主要是 MIDI 学习与生成。
  - [DeepBach](https://github.com/Ghadjeres/DeepBach)：DeepBach是一个基于神经网络的开源项目，旨在生成类似于巴赫风格的合唱音乐。它使用深度学习模型来学习并生成具有巴赫特征的和声。
  - [DeepJ](https://github.com/calclavia/DeepJ)：DeepJ是一个基于深度学习的开源项目，用于生成爵士乐的即兴演奏。它可以通过学习大量爵士乐曲目的数据，生成新的爵士乐段落和即兴演奏。
  - [AudioLDM](https://github.com/haoheliu/AudioLDM)：扩散模型，文本转音乐。Python 工程，自训练模型。
- 文本
  - 剧本、脚本：
    - [dramatron](https://github.com/deepmind/dramatron)：但是依赖 Google AI 框架 Colab
  - 对话：
    - [chatglm-6b](https://huggingface.co/THUDM/chatglm-6b)：16G 显存
- 图片转3D Mesh：
  - [One-2-3-45](https://github.com/One-2-3-45/One-2-3-45)

- 声音克隆
  - [so-vits-svc](https://github.com/svc-develop-team/so-vits-svc)




## 超分辨率

VDSR（ **Very Deep Convolutional Networks SR**）

**DRRN** 

**LapSRN**：金字塔超分辨率网络（*Laplacian Pyramid Super-Resolution Network，*LapSRN）

RCAN（deep residual channel attention networks）

**DSRN**（Dual-State Recurrent Network）



## 3D reconstruction（三维重建）

- [COLMAP – SfM and MVS](https://demuc.de/colmap/)
- [NeRF (Neural Radiance Fields)](https://www.matthewtancik.com/nerf)

