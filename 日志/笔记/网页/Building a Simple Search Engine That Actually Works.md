> 文章来源：https://karboosx.net/post/4eZxhBon/building-a-simple-search-engine-that-actually-works

# Building a Simple Search Engine That Actually Works

# 构建一个简单的搜索引擎（并且真的有用）

## 关键词



## 摘记

**01 怪癖（quirks）工程师**

> Look, I know what you're thinking. "Why not just use Elasticsearch?" or "What about Algolia?" Those are valid options, but they come with complexity. You need to learn their APIs, manage their infrastructure, and deal with their quirks.
>
> 我知道，你可能会想为什么不直接使用 Elasticsearch？或者会问 “Algolia怎么样" ，而这些都是有效的选择，但它们带来了复杂性。你需要学习他们的 API，管理他们的基础设施，并处理他们的怪癖（quirks）。
>

我觉得这个点很有意思，就是会描述说使用第三方系统会引入复杂性，而且需要处理怪癖。



## 思路



## 原文

## Why Build Your Own?

## 为什么要构建一个自己的搜索引擎？

Look, I know what you're thinking. "Why not just use Elasticsearch?" or "What about Algolia?" Those are valid options, but they come with complexity. You need to learn their APIs, manage their infrastructure, and deal with their quirks.

我知道，你可能会想为什么不直接使用 Elasticsearch？或者会问 “Algolia怎么样" ，而这些都是有效的选择，但它们带来了复杂性。你需要学习他们的 API，管理他们的基础设施，并处理他们的怪癖（quirks）。

Sometimes you just want something that:

- Works with your existing database
- Doesn't require external services
- Is easy to understand and debug
- Actually finds relevant results

有时候，你只是想要一些：

- 使用现有数据库
- 不需要外部服务
- 易于理解和调试
- 切实的可以找到相关结果

That's what I built. A search engine that uses your existing database, respects your current architecture, and gives you full control over how it works.

这就是我做的。一个使用您现有数据库的搜索引擎，尊重您当前的架构，并让您完全控制它的工作方式。

------

## The Core Idea

## 核心思想

The concept is simple: **tokenize everything, store it, then match tokens when searching**.

概念很简单：**标记化所有内容，存储它，然后在搜索时匹配标记。**

Here's how it works:

1. **Indexing**: When you add or update content, we split it into tokens (words, prefixes, n-grams) and store them with weights
2. **Searching**: When someone searches, we tokenize their query the same way, find matching tokens, and score the results
3. **Scoring**: We use the stored weights to calculate relevance scores

The magic is in the tokenization and weighting. Let me show you what I mean.

它的工作原理如下：

1. **索引**：当您添加或更新内容时，我们将其拆分为令牌（单词，前缀，n-gram）并将其与权重一起存储
2. **搜索**：当有人搜索时，我们以相同的方式标记他们的查询，找到匹配的标记，并对结果进行评分
3. **评分**：我们使用存储的权重来计算相关性分数

秘诀就是在<u>标记化</u>和<u>加权</u>。让我展示一下我的成果。



------

## Building Block 1: The Database Schema

## 构建块1：数据库模式

We need two simple tables: `index_tokens` and `index_entries`.

我们需要两个简单的表：`index_tokens`和`index_entries`。

### index_tokens（索引标记）

This table stores all unique tokens with their tokenizer weights. Each token name can have multiple records with different weights—one per tokenizer.

此表存储所有唯一标签及其标签化器权重。每个标记名可以有多个具有不同权重的记录-每个标记器一个。

```php
// index_tokens table structure
id | name    | weight
---|---------|-------
1  | parser  | 20     // From WordTokenizer
2  | parser  | 5      // From PrefixTokenizer
3  | parser  | 1      // From NGramsTokenizer
4  | parser  | 10     // From SingularTokenizer
```

Why store separate tokens per weight? Different tokenizers produce the same token with different weights. For example, "parser" from WordTokenizer has weight 20, but "parser" from PrefixTokenizer has weight 5. We need separate records to properly score matches.

为什么要按权重存储单独的标签？不同的tokenizer生成具有不同权重的相同token。例如，文本标志（WordTokenizer）中的“parser”权重为20，而前缀标志（PrefixTokenizer）中的“parser”权重为5。我们需要单独记录来正确地进行匹配。

The unique constraint is on `(name, weight)`, so the same token name can exist multiple times with different weights.

unique约束在`(name, weight)`上，因此相同的令牌名称可以以不同的权重存在多次。



### index_entries（索引项）

This table links tokens to documents with field-specific weights.

此表将令牌链接到具有特定于字段的权重的文档。

```php
// index_entries table structure
id | token_id | document_type | field_id | document_id | weight
---|----------|---------------|----------|-------------|-------
1  | 1        | 1             | 1        | 42          | 2000
2  | 2        | 1             | 1        | 42          | 500
```

The `weight` here is the final calculated weight: `field_weight × tokenizer_weight × ceil(sqrt(token_length))`. This encodes everything we need for scoring. We will talk about scoring later in the post.

这里的`weight`是最终计算的重量：`field_weight × tokenizer_weight × ceil(sqrt(token_length))`。它编码了我们需要的一切。我们将在稍后的文章中讨论得分。

We add indexes on:

- `(document_type, document_id)` - for fast document lookups
- `token_id` - for fast token lookups
- `(document_type, field_id)` - for field-specific queries
- `weight` - for filtering by weight

Why this structure? Simple, efficient, and leverages what databases do best.

我们在以下方面添加索引：

- `(document_type, document_id)` -用于快速文档查找
- `token_id` -用于快速令牌查找
- `(document_type, field_id)` -用于特定于字段的查询
- `weight` -按重量过滤

为什么是这种结构？简单、高效，并充分利用数据库的优势。



------

## Building Block 2: Tokenization

## 构建模块2：令牌化

What is tokenization? It's breaking text into searchable pieces. The word "parser" becomes tokens like `["parser"]`, `["par", "pars", "parse", "parser"]`, or `["par", "ars", "rse", "ser"]` depending on which tokenizer we use.

什么是令牌化？它将文本分解成可搜索的片段。单词“parser”会变成像`["parser"]`、`["par", "pars", "parse", "parser"]`或`["par", "ars", "rse", "ser"]`这样的标记，这取决于我们使用的标记器。

Why multiple tokenizers? Different strategies for different matching needs. One tokenizer for exact matches, another for partial matches, another for typos.

为什么要使用多个标记器？不同的匹配需求，不同的策略。一个标记器用于精确匹配，另一个用于部分匹配，另一个用于错别字。

All tokenizers implement a simple interface:

所有tokenizer都实现了一个简单的接口：

```php
interface TokenizerInterface
{
    public function tokenize(string $text): array;  // Returns array of Token objects
    public function getWeight(): int;               // Returns tokenizer weight
}
```

Simple contract, easy to extend.

简单的合同，易于扩展。



### Word Tokenizer（单词标记器）

This one is straightforward—it splits text into individual words. "parser" becomes just `["parser"]`. Simple, but powerful for exact matches.

这一个是直接的-它将文本分割成单独的单词。“parser”变成了`["parser"]`。简单，但功能强大的精确匹配。

First, we normalize the text. Lowercase everything, remove special characters, normalize whitespace:

首先，我们规范文本。全部小写，删除特殊字符，规范化空格：

```php
class WordTokenizer implements TokenizerInterface
{
    public function tokenize(string $text): array
    {
        // Normalize: lowercase, remove special chars
        $text = mb_strtolower(trim($text));
        $text = preg_replace('/[^a-z0-9]/', ' ', $text);
        $text = preg_replace('/\s+/', ' ', $text);
```

Next, we split into words and filter out short ones:

接下来，我们分成单词并过滤出简短的单词：

```php
        // Split into words, filter short ones
        $words = explode(' ', $text);
        $words = array_filter($words, fn($w) => mb_strlen($w) >= 2);
```

Why filter short words? Single-character words are usually too common to be useful. "a", "I", "x" don't help with search.

为什么要过滤短词？单个字符的单词通常太常见而没有用处。“a”，“I”，“x”对搜索没有帮助。

Finally, we return unique words as Token objects:

最后，我们返回唯一的单词作为Token对象：

```php
        // Return as Token objects with weight
        return array_map(
            fn($word) => new Token($word, $this->weight),
            array_unique($words)
        );
    }
}
```

Weight: 20 (high priority for exact matches)

权重：20（精确匹配的高优先级）



### Prefix Tokenizer（前缀标记器）

This generates word prefixes. "parser" becomes `["par", "pars", "parse", "parser"]` (with min length 4). This helps with partial matches and autocomplete-like behavior.

这会生成单词前缀。“parser”变为`["par", "pars", "parse", "parser"]`（最小长度为4）。这有助于部分匹配和类似自动完成的行为。

First, we extract words (same normalization as WordTokenizer):

首先，我们提取单词（与WordTokenizer相同的标准化）：

```php
class PrefixTokenizer implements TokenizerInterface
{
    public function __construct(
        private int $minPrefixLength = 4,
        private int $weight = 5
    ) {}
    
    public function tokenize(string $text): array
    {
        // Normalize same as WordTokenizer
        $words = $this->extractWords($text);
```

Then, for each word, we generate prefixes from the minimum length to the full word:

然后，对于每个单词，我们生成从最小长度到完整单词的前缀：

```php
        $tokens = [];
        foreach ($words as $word) {
            $wordLength = mb_strlen($word);
            // Generate prefixes from min length to full word
            for ($i = $this->minPrefixLength; $i <= $wordLength; $i++) {
                $prefix = mb_substr($word, 0, $i);
                $tokens[$prefix] = true; // Use associative array for uniqueness
            }
        }
```

Why use an associative array? It ensures uniqueness. If "parser" appears twice in the text, we only want one "parser" token.

为什么要使用关联数组？它确保了独特性。如果“parser”在文本中出现两次，我们只需要一个“parser”标记。

Finally, we convert the keys to Token objects:

最后，我们将密钥转换为Token对象：

```php
        return array_map(
            fn($prefix) => new Token($prefix, $this->weight),
            array_keys($tokens)
        );
    }
}
```

Weight: 5 (medium priority)

重量：5（中等优先级）

Why min length? Avoid too many tiny tokens. Prefixes shorter than 4 characters are usually too common to be useful.

为什么是最小长度？避免太多的小代币。短于4个字符的前缀通常太常见而没有用处。

### N-Grams Tokenizer（N-Grams标记器）

This creates character sequences of a fixed length (I use 3). "parser" becomes `["par", "ars", "rse", "ser"]`. This catches typos and partial word matches.

这将创建固定长度的字符序列（我使用3）。“parser”变为`["par", "ars", "rse", "ser"]`。这将捕获拼写错误和部分单词匹配。

First, we extract words:

首先，我们提取单词：

```php
class NGramsTokenizer implements TokenizerInterface
{
    public function __construct(
        private int $ngramLength = 3,
        private int $weight = 1
    ) {}
    
    public function tokenize(string $text): array
    {
        $words = $this->extractWords($text);
```

Then, for each word, we slide a window of fixed length across it:

然后，对于每个单词，我们在其上滑动一个固定长度的窗口：

```php
        $tokens = [];
        foreach ($words as $word) {
            $wordLength = mb_strlen($word);
            // Sliding window of fixed length
            for ($i = 0; $i <= $wordLength - $this->ngramLength; $i++) {
                $ngram = mb_substr($word, $i, $this->ngramLength);
                $tokens[$ngram] = true;
            }
        }
```

The sliding window: for "parser" with length 3, we get:

- Position 0: "par"
- Position 1: "ars"
- Position 2: "rse"
- Position 3: "ser"

滑动窗口：对于长度为3的“parser”，我们得到：

- 位置0："par"
- 位置1：“ars”
- 位置2：“rse”
- 位置3：“ser”

Why this works? Even if someone types "parsr" (typo), we still get "par" and "ars" tokens, which match the correctly spelled "parser".

为什么这样做有效？即使有人键入“parsr”（错别字），我们仍然得到“par”和“ars”标记，它们与正确拼写的“parser”匹配。

Finally, we convert to Token objects:

最后，我们转换为Token对象：

```php
        return array_map(
            fn($ngram) => new Token($ngram, $this->weight),
            array_keys($tokens)
        );
    }
}
```

Weight: 1 (low priority, but catches edge cases)

权重：1（低优先级，但捕获边缘情况）

Why 3? Balance between coverage and noise. Too short and you get too many matches, too long and you miss typos.

为什么是3？在覆盖和噪音之间取得平衡。太短，你会得到太多的匹配，太长，你错过错别字。

### Normalization（正常化）

All tokenizers do the same normalization:

- Lowercase everything
- Remove special characters (keep only alphanumerical)
- Normalize whitespace (multiple spaces to single space)

This ensures consistent matching regardless of input format.

所有的tokenizer都进行相同的标准化：

- 小写的一切
- 删除特殊字符（仅保留文字）
- 规范化空白（多个空格到单个空格）

这确保了一致的匹配，而与输入格式无关。

------

## Building Block 3: The Weight System

## 积木3：重量系统

We have three levels of weights working together:

1. **Field weights**: Title vs content vs keywords
2. **Tokenizer weights**: Word vs prefix vs n-gram (stored in index_tokens)
3. **Document weights**: Stored in index_entries (calculated: `field_weight × tokenizer_weight × ceil(sqrt(token_length))`)

我们有三个级别的权重一起工作：

1. 字段权重：标题vs内容vs关键字
2. 标记器权重：单词vs前缀vs n-gram（存储在index_tokens中）
3. 文档权重：存储在index_entries中（计算：`field_weight × tokenizer_weight × ceil(sqrt(token_length))`）

### Final Weight Calculation（最终重量计算）

When indexing, we calculate the final weight like this:

索引时，我们计算最终的权重如下：

```php
$finalWeight = $fieldWeight * $tokenizerWeight * ceil(sqrt($tokenLength));
```

For example:

- Title field: weight 10
- Word tokenizer: weight 20
- Token "parser": length 6
- Final weight: `10 × 20 × ceil(sqrt(6)) = 10 × 20 × 3 = 600`

举例来说：

- 标题字段：重量10
- 单词分词器：weight 20
- 标记“parser”：长度6
- 最终重量：`10 × 20 × ceil(sqrt(6)) = 10 × 20 × 3 = 600`

Why use `ceil(sqrt())`? Longer tokens are more specific, but we don't want weights to blow up with very long tokens. "parser" is more specific than "par", but a 100-character token shouldn't have 100x the weight. The square root function gives us diminishing returns—longer tokens still score higher, but not linearly. We use `ceil()` to round up to the nearest integer, keeping weights as whole numbers.

为什么要使用`ceil(sqrt())`？更长的令牌更具体，但我们不希望权重因太长令牌而膨胀。“parser”比“par”更具体，但是一个100个字符的标记不应该有100倍的权重。平方根函数给我们的回报是递减的，更长的代币仍然得分更高，但不是线性的。我们使用`ceil()`来四舍五入到最接近的整数，保持权重为整数。

### Tuning Weights（调整权重）

You can adjust weights for your use case:

- Increase field weights for titles if titles are most important
- Increase tokenizer weights for exact matches if you want to prioritize exact matches
- Adjust the token length function (ceil(sqrt), log, or linear) if you want longer tokens to matter more or less

You can see exactly how weights are calculated and adjust them as needed.

您可以根据您的用例调整权重：

- 如果标题最重要，则增加标题的字段权重
- 如果要优先考虑精确匹配，请增加精确匹配的标记器权重
- 如果您希望更长的标记或多或少起作用，请调整标记长度函数（ceil（sqrt）、log或linear

您可以确切地看到权重是如何计算的，并根据需要对其进行调整。

------

## Building Block 4: The Indexing Service

## 构建模块4：索引服务

The indexing service takes a document and stores all its tokens in the database.

索引服务获取文档并将其所有标记存储在数据库中。

### The Interface（接口）

Documents that can be indexed implement `IndexableDocumentInterface`:

可以索引的文档实现`IndexableDocumentInterface`：

```php
interface IndexableDocumentInterface
{
    public function getDocumentId(): int;
    public function getDocumentType(): DocumentType;
    public function getIndexableFields(): IndexableFields;
}
```

To make a document searchable, you implement these three methods:

要使文档可搜索，可以实现以下三种方法：

```php
class Post implements IndexableDocumentInterface
{
    public function getDocumentId(): int
    {
        return $this->id ?? 0;
    }
    
    public function getDocumentType(): DocumentType
    {
        return DocumentType::POST;
    }
    
    public function getIndexableFields(): IndexableFields
    {
        $fields = IndexableFields::create()
            ->addField(FieldId::TITLE, $this->title ?? '', 10)
            ->addField(FieldId::CONTENT, $this->content ?? '', 1);
        
        // Add keywords if present
        if (!empty($this->keywords)) {
            $fields->addField(FieldId::KEYWORDS, $this->keywords, 20);
        }
        
        return $fields;
    }
}
```

Three methods to implement:

- `getDocumentType()`: returns the document type enum
- `getDocumentId()`: returns the document ID
- `getIndexableFields()`: builds fields with weights using fluent API

三种方法来实现：

- `getDocumentType()`：返回文档类型枚举
- `getDocumentId()`：返回文档ID
- `getIndexableFields()`：使用fluent API构建具有权重的字段



You can index documents:

- On create/update (via event listeners)
- Via commands: `app:index-document`, `app:reindex-documents`
- Via cron (for batch reindexing)

您可以索引文档：

- 创建/更新时（通过事件侦听器）
- 通过命令：`app:index-document`、`app:reindex-documents`
- 通过cron（用于批量重新索引）



### How It Works（它是如何工作）

Here's the indexing process, step by step.

下面是索引过程，一步一步。

First, we get the document information:

首先，我们获取文档信息：

```php
class SearchIndexingService
{
    public function indexDocument(IndexableDocumentInterface $document): void
    {
        // 1. Get document info
        $documentType = $document->getDocumentType();
        $documentId = $document->getDocumentId();
        $indexableFields = $document->getIndexableFields();
        $fields = $indexableFields->getFields();
        $weights = $indexableFields->getWeights();
```

The document provides its fields and weights via the `IndexableFields` builder.

文档通过`IndexableFields`构建器提供其字段和权重。

Next, we remove the existing index for this document. This handles updates—if the document changed, we need to reindex it:

接下来，我们删除此文档的现有索引。这处理更新-如果文档改变了，我们需要重新索引它：

```php
        // 2. Remove existing index for this document
        $this->removeDocumentIndex($documentType, $documentId);
        
        // 3. Prepare batch insert data
        $insertData = [];
```

Why remove first? If we just add new tokens, we'll have duplicates. Better to start fresh.

为什么要先删除？如果我们只是添加新的令牌，我们将有重复。最好重新开始。

Now, we process each field. For each field, we run all tokenizers:

现在，我们处理每个字段。对于每个字段，我们运行所有的tokenizer：

```php
        // 4. Process each field
        foreach ($fields as $fieldIdValue => $content) {
            if (empty($content)) {
                continue;
            }
            
            $fieldId = FieldId::from($fieldIdValue);
            $fieldWeight = $weights[$fieldIdValue] ?? 0;
            
            // 5. Run all tokenizers on this field
            foreach ($this->tokenizers as $tokenizer) {
                $tokens = $tokenizer->tokenize($content);
```

For each tokenizer, we get tokens. Then, for each token, we find or create it in the database and calculate the final weight:

对于每个tokenizer，我们得到token。然后，对于每个token，我们在数据库中找到或创建它，并计算最终的权重：

```php
                foreach ($tokens as $token) {
                    $tokenValue = $token->value;
                    $tokenWeight = $token->weight;
                    
                    // 6. Find or create token in index_tokens
                    $tokenId = $this->findOrCreateToken($tokenValue, $tokenWeight);
                    
                    // 7. Calculate final weight
                    $tokenLength = mb_strlen($tokenValue);
                    $finalWeight = (int) ($fieldWeight * $tokenWeight * ceil(sqrt($tokenLength)));
                    
                    // 8. Add to batch insert
                    $insertData[] = [
                        'token_id' => $tokenId,
                        'document_type' => $documentType->value,
                        'field_id' => $fieldId->value,
                        'document_id' => $documentId,
                        'weight' => $finalWeight,
                    ];
                }
            }
        }
```

Why batch insert? Performance. Instead of inserting one row at a time, we collect all rows and insert them in one query.

为什么要批量插入？性能我们不是一次插入一行，而是收集所有行并将它们插入到一个查询中。

Finally, we batch insert everything:

最后，我们批量插入所有内容：

```php
        // 9. Batch insert for performance
        if (!empty($insertData)) {
            $this->batchInsertSearchDocuments($insertData);
        }
    }
```

The `findOrCreateToken` method is straightforward:

`findOrCreateToken`方法很简单：

```php
    private function findOrCreateToken(string $name, int $weight): int
    {
        // Try to find existing token with same name and weight
        $sql = "SELECT id FROM index_tokens WHERE name = ? AND weight = ?";
        $result = $this->connection->executeQuery($sql, [$name, $weight])->fetchAssociative();
        
        if ($result) {
            return (int) $result['id'];
        }
        
        // Create new token
        $insertSql = "INSERT INTO index_tokens (name, weight) VALUES (?, ?)";
        $this->connection->executeStatement($insertSql, [$name, $weight]);
        
        return (int) $this->connection->lastInsertId();
    }
}
```

Why find or create? Tokens are shared across documents. If "parser" already exists with weight 20, we reuse it. No need to create duplicates.

为什么要寻找或创造？令牌在文档之间共享。如果“parser”已经存在，权重为20，我们就重用它。不需要创建副本。

The key points:

- We remove old index first (handles updates)
- We batch insert for performance (one query instead of many)
- We find or create tokens (avoids duplicates)
- We calculate final weight on the fly

关键点：

- 我们首先删除旧索引（处理更新）
- 为了提高性能，我们使用批插入（一个查询而不是多个查询）
- 我们查找或创建令牌（避免重复）
- 我们在飞行中计算最终重量



------

## Building Block 5: The Search Service

## 构建模块5：搜索服务

The search service takes a query string and finds relevant documents. It tokenizes the query the same way we tokenized documents during indexing, then matches those tokens against the indexed tokens in the database. The results are scored by relevance and returned as document IDs with scores.

搜索服务获取查询字符串并查找相关文档。它标记查询的方式与我们在索引过程中标记文档的方式相同，然后将这些标记与数据库中的索引标记进行匹配。结果按相关性进行评分，并作为文档ID和分数返回。

### How It Works（它是如何工作）

Here's the search process, step by step.

这是搜索过程，一步一步。

First, we tokenize the query using all tokenizers:

首先，我们使用所有的tokenizer对查询进行tokenize：

```php
class SearchService
{
    public function search(DocumentType $documentType, string $query, ?int $limit = null): array
    {
        // 1. Tokenize query using all tokenizers
        $queryTokens = $this->tokenizeQuery($query);
        
        if (empty($queryTokens)) {
            return [];
        }
```

If the query produces no tokens (e.g., only special characters), we return empty results.

如果查询不产生令牌（例如，只有特殊字符），我们返回空结果。

### Why Tokenize the Query Using the Same Tokenizers?

为什么要使用相同的令牌化器对查询进行令牌化？

Different tokenizers produce different token values. If we index with one set and search with another, we'll miss matches.

不同的tokenizer产生不同的token值。如果我们用一个集合索引，用另一个集合搜索，我们会错过匹配。

Example:

- Indexing with PrefixTokenizer creates tokens: "par", "pars", "parse", "parser"
- Searching with only WordTokenizer creates token: "parser"
- We'll find "parser", but we won't find documents that only have "par" or "pars" tokens
- Result: Incomplete matches, missing relevant documents!

范例：

- 使用PrefixTokenizer建立索引会创建标记：“par”、“pars”、“parse”、“parser”
- 仅使用WordTokenizer搜索将创建标记：“parser”
- 我们会找到“parser”，但不会找到只有“par”或“pars”标记的文档
- 结果：不完全匹配，缺少相关文档！

**The solution**: Use the same tokenizers for both indexing and searching. Same tokenization strategy = same token values = complete matches.

解决方案：使用相同的标记器进行索引和搜索。相同的标记化策略=相同的标记值=完全匹配。

This is why the `SearchService` and `SearchIndexingService` both receive the same set of tokenizers.

这就是为什么`SearchService`和`SearchIndexingService`都接收相同的tokenizer集合。

Next, we extract unique token values. Multiple tokenizers might produce the same token value, so we deduplicate:

接下来，我们提取唯一的令牌值。多个tokenizer可能会产生相同的token值，所以我们去重：

```php
        // 2. Extract unique token values
        $tokenValues = array_unique(array_map(
            fn($token) => $token instanceof Token ? $token->value : $token,
            $queryTokens
        ));
```

Why extract values? We search by token name, not by weight. We need the unique token names to search for.

为什么要提取值？我们是按代币名称搜索，不是按重量。我们需要唯一的令牌名称来搜索。

Then, we sort tokens by length (longest first). This prioritizes specific matches:

我们先从长计议，再从长计议。这会优先考虑特定的匹配：

```php
        // 3. Sort tokens (longest first - prioritize specific matches)
        usort($tokenValues, fn($a, $b) => mb_strlen($b) <=> mb_strlen($a));
```

Why sort? Longer tokens are more specific. "parser" is more specific than "par", so we want to search for "parser" first.

为什么要排序？更长的令牌更具体。“parser”比“par”更具体，所以我们想先搜索“parser”。

We also limit the token count to prevent DoS attacks with huge queries:

我们还限制令牌计数，以防止具有巨大查询的DoS攻击：

```php
        // 4. Limit token count (prevent DoS with huge queries)
        if (count($tokenValues) > 300) {
            $tokenValues = array_slice($tokenValues, 0, 300);
        }
```

Why limit? A malicious user could send a query that produces thousands of tokens, causing performance issues. We keep the longest 300 tokens (already sorted).

为什么要限制？恶意用户可能发送一个查询，生成数千个令牌，从而导致性能问题。我们保留最长的300个令牌（已经排序）。

Now, we execute the optimized SQL query. The `executeSearch()` method builds the SQL query and executes it:

现在，我们执行优化的SQL查询。`executeSearch()`方法构建SQL查询并执行它：

```php
        // 5. Execute optimized SQL query
        $results = $this->executeSearch($documentType, $tokenValues, $limit);
```

Inside `executeSearch()`, we build the SQL query with parameter placeholders, execute it, filter low-scoring results, and convert to SearchResult objects:

在`executeSearch()`中，我们使用参数占位符构建SQL查询，执行它，过滤低得分结果，并转换为SearchResult对象：

```php
private function executeSearch(DocumentType $documentType, array $tokenValues, int $tokenCount, ?int $limit, int $minTokenWeight): array
{
    // Build parameter placeholders for token values
    $tokenPlaceholders = implode(',', array_fill(0, $tokenCount, '?'));
    
    // Build the SQL query (shown in full in "The SQL Query" section below)
    $sql = "SELECT sd.document_id, ... FROM index_entries sd ...";
    
    // Build parameters array
    $params = [
        $documentType->value,  // document_type
        ...$tokenValues,       // token values for IN clause
        $documentType->value,  // for subquery
        ...$tokenValues,       // token values for subquery
        $minTokenWeight,      // minimum token weight
        // ... more parameters
    ];
    
    // Execute query with parameter binding
    $results = $this->connection->executeQuery($sql, $params)->fetchAllAssociative();
    
    // Filter out results with low normalized scores (below threshold)
    $results = array_filter($results, fn($r) => (float) $r['score'] >= 0.05);
    
    // Convert to SearchResult objects
    return array_map(
        fn($result) => new SearchResult(
            documentId: (int) $result['document_id'],
            score: (float) $result['score']
        ),
        $results
    );
}
```

The SQL query does the heavy lifting: finds matching documents, calculates scores, and sorts by relevance. We use raw SQL for performance and full control—we can optimize the query exactly how we need it.

SQL查询完成了繁重的工作：查找匹配的文档、计算分数并按相关性进行排序。我们使用原始SQL来提高性能和进行完全控制-我们可以按照需要优化查询。

The query uses JOINs to connect tokens and documents, subqueries for normalization, aggregation for scoring, and indexes on token name, document type, and weight. We use parameter binding for security (prevents SQL injection).

该查询使用JOIN连接标记和文档，使用子查询进行规范化，使用聚合进行评分，并使用标记名称、文档类型和权重的索引。我们使用参数绑定来保证安全性（防止SQL注入）。

We'll see the full query in the next section.

我们将在下一节中看到完整的查询。

The main `search()` method then returns the results:

main的`search()`方法返回结果：

```php
        // 5. Return results
        return $results;
    }
}
```

### The Scoring Algorithm（计分算法）

The scoring algorithm balances multiple factors. Let's break it down step by step.

评分算法平衡多个因素。让我们一步一步来。

The base score is the sum of all matched token weights:

基础分数是所有匹配的令牌权重的总和：

```sql
SELECT 
    sd.document_id,
    SUM(sd.weight) as base_score
FROM index_entries sd
INNER JOIN index_tokens st ON sd.token_id = st.id
WHERE 
    sd.document_type = ?
    AND st.name IN (?, ?, ?)  -- Query tokens
GROUP BY sd.document_id
```

- `sd.weight`: from index_entries (field_weight × tokenizer_weight × ceil(sqrt(token_length)))
- `sd.weight`：来自index_entries（field_weight × tokenizer_weight × ceil（sqrt（token_length）

Why not multiply by `st.weight`? The tokenizer weight is already included in `sd.weight` during indexing. The `st.weight` from `index_tokens` is used only in the full SQL query's WHERE clause for filtering (ensures at least one token with weight >= minTokenWeight).

为什么不乘以`st.weight`？标记器权重在索引期间已经包含在`sd.weight`中。`st.weight`中的`index_tokens`只在完整SQL查询的WHERE子句中用于过滤（确保至少有一个weight = minTokenWeight的标记）。

This gives us the raw score. But we need more than that.

这给了我们原始的分数。但我们需要更多。

We add a token diversity boost. Documents matching more unique tokens score higher:

我们增加了一个象征性的多样性提升。匹配更多唯一令牌的文档得分更高：

```sql
(1.0 + LOG(1.0 + COUNT(DISTINCT sd.token_id))) * base_score
```

Why? A document matching 5 different tokens is more relevant than one matching the same token 5 times. The LOG function makes this boost logarithmic—matching 10 tokens doesn't give 10x the boost.

为什么？为什么？匹配5个不同标记的文档比匹配相同标记5次的文档更相关。这个函数使得这个提升是精确的--匹配10个代币并不会带来10倍的提升。

We also add an average weight quality boost. Documents with higher quality matches score higher:

我们还增加了平均重量质量提升。匹配质量越高的文档得分越高：

```sql
(1.0 + LOG(1.0 + AVG(sd.weight))) * base_score
```

Why? A document with high-weight matches (e.g., title matches) is more relevant than one with low-weight matches (e.g., content matches). Again, LOG makes this logarithmic.

为什么？为什么？具有高权重匹配的文档（例如，标题匹配）比具有低权重匹配的标题（例如，内容匹配）。再一次地，π使这个对数化。

We apply a document length penalty. Prevents long documents from dominating:

我们使用文档长度惩罚。防止长文档占主导地位：

```sql
base_score / (1.0 + LOG(1.0 + doc_token_count.token_count))
```

Why? A 1000-word document doesn't automatically beat a 100-word document just because it has more tokens. The LOG function makes this penalty logarithmic—a 10x longer document doesn't get 10x the penalty.

为什么？为什么？一个1000字的文档不会因为它有更多的标记而自动击败一个100字的文档。LOG函数使此惩罚为对数--长度为10倍的文档不会得到10倍的惩罚。

Finally, we normalize by dividing by the maximum score:

最后，我们通过除以最大得分来进行归一化：

```sql
score / GREATEST(1.0, max_score) as normalized_score
```

This gives us a 0-1 range, making scores comparable across different queries.

这给了我们一个0-1的范围，使不同查询的分数具有可比性。

The full formula looks like this:

完整的公式如下所示：

```sql
SELECT 
    sd.document_id,
    (
        SUM(sd.weight) *                                  -- Base score
        (1.0 + LOG(1.0 + COUNT(DISTINCT sd.token_id))) * -- Token diversity boost
        (1.0 + LOG(1.0 + AVG(sd.weight))) /              -- Average weight quality boost
        (1.0 + LOG(1.0 + doc_token_count.token_count))   -- Document length penalty
    ) / GREATEST(1.0, max_score) as score                -- Normalization
FROM index_entries sd
INNER JOIN index_tokens st ON sd.token_id = st.id
INNER JOIN (
    SELECT document_id, COUNT(*) as token_count
    FROM index_entries
    WHERE document_type = ?
    GROUP BY document_id
) doc_token_count ON sd.document_id = doc_token_count.document_id
WHERE 
    sd.document_type = ?
    AND st.name IN (?, ?, ?)  -- Query tokens
    AND sd.document_id IN (
        SELECT DISTINCT document_id
        FROM index_entries sd2
        INNER JOIN index_tokens st2 ON sd2.token_id = st2.id
        WHERE sd2.document_type = ?
        AND st2.name IN (?, ?, ?)
        AND st2.weight >= ?  -- Ensure at least one token with meaningful weight
    )
GROUP BY sd.document_id
ORDER BY score DESC
LIMIT ?
```

Why the subquery with `st2.weight >= ?`? This ensures we only include documents that have at least one matching token with a meaningful tokenizer weight. Without this filter, a document matching only low-priority tokens (like n-grams with weight 1) would be included even if it doesn't match any high-priority tokens (like words with weight 20). This subquery filters out documents that only match noise. We want documents that match at least one meaningful token.

为什么使用子查询`st2.weight >= ?`？这确保我们只包含至少有一个匹配token的文档，该token具有有意义的tokenizer权重。如果没有这个过滤器，一个只匹配低优先级标记（比如权重为1的n-gram）的文档将被包括在内，即使它不匹配任何高优先级标记（比如权重为20的单词）。这个子查询过滤掉只匹配噪声的文档。我们希望文档至少匹配一个有意义的标记。

Why this formula? It balances multiple factors for relevance. Exact matches score high, but so do documents matching many tokens. Long documents don't dominate, but high-quality matches do.

为什么是这个公式？它平衡了多个因素的相关性。精确匹配得分很高，但匹配许多标记的文档也是如此。长文档并不占主导地位，但高质量的匹配却占主导地位。

If no results with weight 10, we retry with weight 1 (fallback for edge cases).

如果权重为10没有结果，我们将使用权重1重试（边缘情况的回退）。

### Converting IDs to Documents（将ID转换为文档）

The search service returns `SearchResult` objects with document IDs and scores:

搜索服务返回带有文档ID和分数的`SearchResult`对象：

```php
class SearchResult
{
    public function __construct(
        public readonly int $documentId,
        public readonly float $score
    ) {}
}
```

But we need actual documents, not just IDs. We convert them using repositories:

但我们需要真实的文件而不仅仅是身份证。我们使用存储库转换它们：

```php
// Perform search
$searchResults = $this->searchService->search(
    DocumentType::POST,
    $query,
    $limit
);

// Get document IDs from search results (preserving order)
$documentIds = array_map(fn($result) => $result->documentId, $searchResults);

// Get documents by IDs (preserving order from search results)
$documents = $this->documentRepository->findByIds($documentIds);
```

Why preserve order? The search results are sorted by relevance score. We want to keep that order when displaying results.

为什么要维持秩序？搜索结果按相关性分数排序。我们希望在显示结果时保持该顺序。

The repository method handles the conversion:

存储库方法处理转换：

```php
public function findByIds(array $ids): array
{
    if (empty($ids)) {
        return [];
    }
    
    return $this->createQueryBuilder('d')
        ->where('d.id IN (:ids)')
        ->setParameter('ids', $ids)
        ->orderBy('FIELD(d.id, :ids)')  // Preserve order from IDs array
        ->getQuery()
        ->getResult();
}
```

The `FIELD()` function preserves the order from the IDs array, so documents appear in the same order as search results.

`FIELD()`函数保留了ID数组中的顺序，因此文档将以与搜索结果相同的顺序显示。



------

## The Result: What You Get（结果：你得到了什么）

What you get is a search engine that:

- **Finds relevant results quickly** (leverages database indexes)
- **Handles typos** (n-grams catch partial matches)
- **Handles partial words** (prefix tokenizer)
- **Prioritizes exact matches** (word tokenizer has highest weight)
- **Works with existing database** (no external services)
- **Easy to understand and debug** (everything is transparent)
- **Full control over behavior** (adjust weights, add tokenizers, modify scoring)

你得到的是一个搜索引擎，它：

- 快速查找相关结果（利用数据库索引）
- 处理拼写错误（n-grams捕获部分匹配）
- 处理部分单词（前缀分词器）
- 优先考虑精确匹配（单词标记器具有最高权重）
- 与现有数据库一起使用（无外部服务）
- 易于理解和调试（一切都是透明的）
- 完全控制行为（调整权重、添加标记器、修改评分）



------

## Extending the System（扩展系统）

Want to add a new tokenizer? Implement `TokenizerInterface`:

想要添加新的tokenizer吗？工具`TokenizerInterface`：

```php
class StemmingTokenizer implements TokenizerInterface
{
    public function tokenize(string $text): array
    {
        // Your stemming logic here
        // Return array of Token objects
    }
    
    public function getWeight(): int
    {
        return 15; // Your weight
    }
}
```

Register it in your services configuration, and it's automatically used for both indexing and searching.

在您的服务配置中注册它，它将自动用于索引和搜索。

Want to add a new document type? Implement `IndexableDocumentInterface`:

想要添加新的文档类型？工具`IndexableDocumentInterface`：

```php
class Comment implements IndexableDocumentInterface
{
    public function getIndexableFields(): IndexableFields
    {
        return IndexableFields::create()
            ->addField(FieldId::CONTENT, $this->content ?? '', 5);
    }
}
```

Want to adjust weights? Change the configuration. Want to modify scoring? Edit the SQL query. Everything is under your control.

想要调整体重吗？更改配置。想要修改评分？编辑SQL查询。一切都在你的掌控之中。



------

## Conclusion（结论）

So there you have it. A simple search engine that actually works. It's not fancy, and it doesn't need a lot of infrastructure, but for most use cases, it's perfect.

所以你有它。一个简单的搜索引擎，实际上工作。它并不花哨，也不需要很多基础设施，但对于大多数用例来说，它是完美的。

The key insight? Sometimes the best solution is the one you understand. No magic, no black boxes, just straightforward code that does what it says.

关键的洞察力？有时候最好的解决办法就是你能理解的。没有魔法，没有黑盒，只是简单的代码，做它说的。

You own it, you control it, you can debug it. And that's worth a lot.

你拥有它，你控制它，你可以调试它。这很有价值。