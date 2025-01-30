> 参考资料：
>
> - [Anthropic’s new 100K context window model is insane!](https://www.youtube.com/watch?v=2kFhloXz5_E&t=400s)
> - [How many words do we read per minute? A review and meta-analysis of reading rate](https://www.sciencedirect.com/science/article/abs/pii/S0749596X19300786)：意思就是说，一个成年人，在阅读小说的时候，和阅读非小说的时候的每分钟阅读速度（Words Per Minite、WPM），大概是 175–300 wpm
>   - [sci-hub](https://sci-hub.se/https://doi.org/10.1016/j.jml.2019.104047)
> - [anthropic](https://www.anthropic.com/)：他就是研究出 Claude 的公司

# Claude 100k

## 摘要

> Digest，summarize，and explain technical documents
>
> Ask questions and find answers in long documents without having to search
>
> Analysis/Perform tasks that require synthesizing information across the entirety of your document.



## Start

- ```
  pip install gradio
  ```

> Q：Gradio 和 Claude 是一个玩意儿么？
>
> A：gradio是一个Python写的简易Web调用器。

## Examples

```python
# assemblyai: https://www.assemblyai.com/docs/
import assemblyai

transcript = assemblyai.transcribe("https://www.listennotes.com/e/p/9b39e6d07c39452fa01af3e856a127eb/")
res = {"text": transcript["text"]}

with open('podcast.json', 'w') as f:
  json.dump(res, f)
```

```python
import json

with open("podcast.json", "r") as f:
  data = json.load(f)

num_words = len(data["text"].split())
print(f"Approximately {num_words} words and {num_words * 4 / 3} tokens")
```

```python
# Use Claude API 3th-party tool
import anthropic

ANTHROPIC_KEY = os.environ.get("ANTHROPIC_KEY")

client = anthropic.Client(ANTHROPIC_KEY)
```

```python
summary_prompt = rf'''
Human: Here is the transcript of a Lex Fridman podcast:

<transcript>
{data['text']}
</transcript>

[this is prompt 1]
You are an expert at writing factual summaries.
Write a summary of the transcript in about 10 sentences.

[this is prompt 2]
Based on thr transcript, what are some of Carmack's views on C++?
Select one or two relevant quotations about C++ from thr transcript and then explain Carmack's opinions.

Assistant: I would be happy to help. Here is the summary:
'''

response = client.completion(
	prompt=summary_prompt,
  model="claude-v1.3-100k",
  max_tokens_to_sample=500,
)

print(response['completion'])
```



