> 视频来源：https://www.youtube.com/watch?v=0XoXNG65rfg
>
> 相关资料：
>
> - [awesome-copilot](https://github.com/github/awesome-copilot)
> - [Context rot: The emerging challenge that could hold back LLM progress](https://www.understandingai.org/p/context-rot-the-emerging-challenge)

## 关键词

- Context rot：情境腐烂



## 摘记

**01 GPT 背后的逻辑**

> 1. System Prompt 系统提示词
>
>    - **Core Identity and Global Rules**，核心身份与全局规则
>
>      You are an intelligent AI coding assistant
>
>    - **General Instructions（Model Specific）**，通用说明（特定型号）
>
>      Never print out a codeblock with file changes
>
>    - **Tool use Instructions**，工具使用说明
>
>      Don't call the run in terminal multiple times in parallel，不要同时多次调用终端中的运行命令
>
>    - **Output Format Instructions**，输出格式说明
>
>      How to format the output in chat for tokenization of things like file links.
>
>    - ***Custom Instructions**：用户提示信息*
>
>    - ***Custom Agents***
>
> 2. User Prompt 用户信息
>
>    - Environment Info
>    - Workspace Info
>      - Project
>        - Folder
>          - file
>
> 3. User Prompt 用户未发送的信息
>
>    - Content Info: Current Date/Time, list of open terminals, etc
>    - Editor Context: Any files that you have added to the chat
>    - User Request
>
> 上面的全部构成了上下文。

- Tool Settings 中，有一个 `Generate Chat Instructions`，生成聊天指令。

  这会生成一个包含项目架构信息的指令文件。



## 思路

作者会先让大模型（Claude Opus）生成一个 Plan（Custom Agents），然后使用大模型根据计划生成（generate）具体的解决方案。最后再由小模型，将大模型的实现一点点的输出。