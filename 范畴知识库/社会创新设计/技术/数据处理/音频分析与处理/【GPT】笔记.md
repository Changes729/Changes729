## 关键词

- 音频信息：音调、响度、节奏、声源



## 摘记

**01 音频分析与识别的定义**

- **音频分析（Audio Analysis）**：对音频信号进行建模、处理、理解的过程，主要目的是提取音频的有用信息（如音调、节奏、声源类型等）。
- **音频识别（Audio Recognition）**：基于分析结果，识别音频中所包含的内容（如语音、说话人、情绪、事件等）。



**02 音频分析与识别典型任务**

| 类别                                              | 说明                                 | 典型工具/方法                                           |
| ------------------------------------------------- | ------------------------------------ | ------------------------------------------------------- |
| **静音检测**（Silence Detection）                 | 用于分割说话段 vs 静音段             | `pydub.silence`, `sox`                                  |
| **说话人分离**（Speaker Diarization）             | 按说话人切分                         | `pyannote-audio`, `Resemblyzer`, `Kaldi`, `SpeechBrain` |
| **语种/语言切换检测**（Language Diarization）     | 不同语言切割                         | `pyannote`, `Whisper`                                   |
| **语音活动检测**（VAD, Voice Activity Detection） | 分出有声段（包括语音/非语音）        | `webrtcvad`, `Silero VAD`, `py-webrtcvad`               |
| **声学事件检测**（Sound Event Detection, SED）    | 按事件类型分割（音乐、鼓点、警笛等） | `Audacity`, `OpenL3`, `DESED`                           |
| **节拍或音符检测**（主要用于音乐）                | 按节拍分段                           | `librosa.onset_detect`, `madmom`                        |
| **语音识别（ASR）**                               | 将语音转换成文本                     | HMM-DNN、CTC、Transformer、Whisper                      |
| 说话人识别                                        | 判断/区分说话者身份                  | i-vector, x-vector, ECAPA-TDNN                          |
| 说话人分离（Diarization）                         | 分辨出谁在说话，并分时间段           | pyannote-audio、Kaldi                                   |
| 情感识别                                          | 判断说话者的情绪状态                 | 音高、能量、频谱特征+分类器                             |
| 音频事件检测（AED/SED）                           | 检测和分类环境音事件（狗叫、打雷等） | CNN, CRNN, YAMNet                                       |
| 音乐信息检索（MIR）                               | 获取音乐风格、节拍、情感、歌手等信息 | librosa、madmom、MusicNN                                |
| 声音分离与增强                                    | 从混合音中提取目标声音或去噪         | Conv-TasNet、DCCRN、Spectral Masking                    |
| 关键词检测（Wake Word Detection）                 | 检测特定词如“Hey Siri”               | CNN/ResNet + 后处理                                     |



**03 主流工具与框架**

| 名称             | 功能                     | 语言       |
| ---------------- | ------------------------ | ---------- |
| `librosa`        | 特征提取、音频分析       | Python     |
| `pyannote-audio` | 说话人识别与分离         | Python     |
| `SpeechBrain`    | 多模态语音任务库         | Python     |
| `Whisper`        | 端到端语音识别           | Python     |
| `openSMILE`      | 音频特征提取器（大规模） | C++        |
| `Kaldi`          | 高性能语音识别           | C++        |
| `ESPnet`         | 端到端语音识别、合成     | PyTorch    |
| `YAMNet`         | 音频事件识别（预训练）   | TensorFlow |
| `Audacity`       | 音频分析与处理（GUI）    | 多平台     |



**04 Sound Event Detection 相关工具**

1. [DESED Baseline](https://github.com/turpaultn/DESED)
   - 官方 SED 基准，基于 CRNN 或 CNN14 架构。
   - 数据集：DESED（来自 Audioset 的合成声音）。
   - 模型结构：CNN-BiLSTM-Attention。
   - 适合入门和比赛用。
2. [YAMNet](https://github.com/tensorflow/models/tree/master/research/audioset/yamnet)
   - Google 提供的 TensorFlow 预训练模型；
   - 521类环境声音标签（来自 AudioSet）。
   - 输入原始波形，输出每段声音的标签概率分布。
   - 可用于迁移学习或快速部署。
3. [PANNs](https://github.com/qiuqiangkong/audioset_tagging_cnn)
   - CNN14 / ResNet 系列环境声音识别模型。
   - 提供强大的预训练特征提取器。
   - 可提取 embedding，用于后续分类/检测。
4. [OpenL3](https://github.com/marl/openl3)
   - 多模态音频嵌入模型；
   - 可用于声音风格相似度/聚类任务。
   - 适合复杂场景的事件建模。
5. [Sony Neural Sound Event Detection](https://github.com/SonyCSL-Paris/Sound_event_detection)
   - 用于 DCASE 比赛的高精度框架。
   - 支持 SED 强标签和弱标签训练（weak supervision）。
   - 支持多模态训练（音频+视频）。



**05 SED 相关案例**

1. [**DCASE Challenge**](https://dcase.community)
   - 每年举办的国际声音事件检测比赛；
   - 提供标准数据集、基准模型、任务设定（如 polyphonic SED）；
   - 各大高校和公司如 Sony、NTT、Google 参与；
   - 子任务如：
     - Task 4: Sound Event Detection in Domestic Environments
     - Task 5: Few-shot Bioacoustic Event Detection