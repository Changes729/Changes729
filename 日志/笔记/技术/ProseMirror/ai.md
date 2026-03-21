## 2️⃣ ProseMirror 学习路径

ProseMirror 学习曲线比较陡，建议分三步走：

### **阶段 1：入门**

- 了解 **Schema** （节点 / mark 定义，内容约束）
- 学习 **State**、**Transaction**、**Plugin** 的基本概念
- 熟悉 **View** 如何渲染内容
- 官方文档（基础篇）：
  - https://prosemirror.net/docs/guide/
  - https://prosemirror.net/examples/

### **阶段 2：定制**

- 自定义 Node（例：Video、Todo List、Callout）
- 自定义 Mark（高亮、标签）
- 通过 NodeView 实现 React/Vue 组件渲染
- 使用 prosemirror-keymap 添加快捷键

### **阶段 3：高级**

- 协作编辑（Y.js + prosemirror-yjs）
- 性能优化（分块加载文档、懒渲染）
- 与外部存储同步（JSON ↔ 数据库）
- 深度阅读源码，理解 selection/transaction 机制

------

## 3️⃣ 推荐学习资源

1. **官方**
   - [ProseMirror Guide](https://prosemirror.net/docs/guide/) — 从 0 到插件
   - [ProseMirror Examples](https://prosemirror.net/examples/) — 经典案例源码
2. **社区博客**
   - *Remirror blog* — 有很多 PM 原理解析
   - *Tiptap Docs* — 用 Tiptap 学 ProseMirror 更轻松
3. **源码学习**
   - [GitHub: ProseMirror](https://github.com/ProseMirror/prosemirror)
   - [GitHub: Tiptap](https://github.com/ueberdosis/tiptap)
4. **视频教程**
   - YouTube: “ProseMirror Tutorial”
   - B站搜索 “ProseMirror 编辑器原理” 有部分拆解视频
5. **进阶**
   - prosemirror-transform 模块阅读
   - 协作模块 prosemirror-collab 用法

------

如果你想，我可以帮你在这个 Demo 的基础上，加一个 **“内嵌视频节点”** 的自定义 NodeView，直接让它支持视频拖拽和 URL 插入，这样你就能同时学到**ProseMirror 核心**和**视频功能实现**。

要我帮你做这个视频节点版本吗？这样就能跟你之前 Notion 类需求结合起来。