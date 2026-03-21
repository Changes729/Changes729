> 参考资料
>
> - [Plugins](https://prosemirror.net/docs/guide/)

# Prosemirror Plugin

```ts
/**
Plugins bundle functionality that can be added to an editor.
They are part of the [editor state](https://prosemirror.net/docs/ref/#state.EditorState) and
may influence that state and the view that contains it.
*/
declare class Plugin<PluginState = any> {
    /**
    The plugin's [spec object](https://prosemirror.net/docs/ref/#state.PluginSpec).
    */
    readonly spec: PluginSpec<PluginState>;
    /**
    Create a plugin.
    */
    constructor(
    /**
    The plugin's [spec object](https://prosemirror.net/docs/ref/#state.PluginSpec).
    */
    spec: PluginSpec<PluginState>);
    /**
    The [props](https://prosemirror.net/docs/ref/#view.EditorProps) exported by this plugin.
    */
    readonly props: EditorProps<Plugin<PluginState>>;
    /**
    Extract the plugin's state field from an editor state.
    */
    getState(state: EditorState): PluginState | undefined;
}
```

```ts
/**
This is the type passed to the [`Plugin`](https://prosemirror.net/docs/ref/#state.Plugin)
constructor. It provides a definition for a plugin.
*/
interface PluginSpec<PluginState> {
    /**
    The [view props](https://prosemirror.net/docs/ref/#view.EditorProps) added by this plugin. Props
    that are functions will be bound to have the plugin instance as
    their `this` binding.
    */
    props?: EditorProps<Plugin<PluginState>>;
    /**
    Allows a plugin to define a [state field](https://prosemirror.net/docs/ref/#state.StateField), an
    extra slot in the state object in which it can keep its own data.
    */
    state?: StateField<PluginState>;
    /**
    Can be used to make this a keyed plugin. You can have only one
    plugin with a given key in a given state, but it is possible to
    access the plugin's configuration and state through the key,
    without having access to the plugin instance object.
    */
    key?: PluginKey;
    /**
    When the plugin needs to interact with the editor view, or
    set something up in the DOM, use this field. The function
    will be called when the plugin's state is associated with an
    editor view.
    */
    view?: (view: EditorView) => PluginView;
    /**
    When present, this will be called before a transaction is
    applied by the state, allowing the plugin to cancel it (by
    returning false).
    */
    filterTransaction?: (tr: Transaction, state: EditorState) => boolean;
    /**
    Allows the plugin to append another transaction to be applied
    after the given array of transactions. When another plugin
    appends a transaction after this was called, it is called again
    with the new state and new transactions—but only the new
    transactions, i.e. it won't be passed transactions that it
    already saw.
    */
    appendTransaction?: (transactions: readonly Transaction[], oldState: EditorState, newState: EditorState) => Transaction | null | undefined;
    /**
    Additional properties are allowed on plugin specs, which can be
    read via [`Plugin.spec`](https://prosemirror.net/docs/ref/#state.Plugin.spec).
    */
    [key: string]: any;
}
```



### 案例一 —— 按键处理

```ts
let myPlugin = new Plugin({
  props: {
    handleKeyDown(view, event) {
      console.log("A key was pressed!")
      return false // We did not handle this
    }
  }
})
```

`this: P` 是上下文绑定。

```ts
interface EditorProps<P = any> {
    handleDOMEvents?: {
        [event in keyof DOMEventMap]?: (this: P, view: EditorView, event: DOMEventMap[event]) => boolean | void;
    };
    handleKeyDown?: (this: P, view: EditorView, event: KeyboardEvent) => boolean | void;
    handleKeyPress?: (this: P, view: EditorView, event: KeyboardEvent) => boolean | void;
    handleTextInput?: (this: P, view: EditorView, from: number, to: number, text: string, deflt: () => Transaction) => boolean | void;
    handleClickOn?: (this: P, view: EditorView, pos: number, node: Node, nodePos: number, event: MouseEvent, direct: boolean) => boolean | void;
    handleClick?: (this: P, view: EditorView, pos: number, event: MouseEvent) => boolean | void;
    handleDoubleClickOn?: (this: P, view: EditorView, pos: number, node: Node, nodePos: number, event: MouseEvent, direct: boolean) => boolean | void;
    handleDoubleClick?: (this: P, view: EditorView, pos: number, event: MouseEvent) => boolean | void;
    handleTripleClickOn?: (this: P, view: EditorView, pos: number, node: Node, nodePos: number, event: MouseEvent, direct: boolean) => boolean | void;
    handleTripleClick?: (this: P, view: EditorView, pos: number, event: MouseEvent) => boolean | void;
    handlePaste?: (this: P, view: EditorView, event: ClipboardEvent, slice: Slice) => boolean | void;
    handleDrop?: (this: P, view: EditorView, event: DragEvent, slice: Slice, moved: boolean) => boolean | void;
    handleScrollToSelection?: (this: P, view: EditorView) => boolean;
    dragCopies?: (event: DragEvent) => boolean;
    createSelectionBetween?: (this: P, view: EditorView, anchor: ResolvedPos, head: ResolvedPos) => Selection | null;
    domParser?: DOMParser;
    transformPastedHTML?: (this: P, html: string, view: EditorView) => string;
    clipboardParser?: DOMParser;
    transformPastedText?: (this: P, text: string, plain: boolean, view: EditorView) => string;
    clipboardTextParser?: (this: P, text: string, $context: ResolvedPos, plain: boolean, view: EditorView) => Slice;
    transformPasted?: (this: P, slice: Slice, view: EditorView, plain: boolean) => Slice;
    transformCopied?: (this: P, slice: Slice, view: EditorView) => Slice;

    nodeViews?: {
        [node: string]: NodeViewConstructor;
    };

    markViews?: {
        [mark: string]: MarkViewConstructor;
    };

    clipboardSerializer?: DOMSerializer;
    clipboardTextSerializer?: (this: P, content: Slice, view: EditorView) => string;
    decorations?: (this: P, state: EditorState) => DecorationSource | null | undefined;
    editable?: (this: P, state: EditorState) => boolean;
    attributes?: {
        [name: string]: string;
    } | ((state: EditorState) => {
        [name: string]: string;
    });

    scrollThreshold?: number | {
        top: number;
        right: number;
        bottom: number;
        left: number;
    };

    scrollMargin?: number | {
        top: number;
        right: number;
        bottom: number;
        left: number;
    };
}
```



## 案例二 —— 私有状态管理

```js
let transactionCounter = new Plugin({
  state: {
    init() { return 0 },
    apply(tr, value) { return value + 1 }
  }
})

function getTransactionCount(state) {
  return transactionCounter.getState(state)
}
```

```ts
interface StateField<T> {
    init: (config: EditorStateConfig, instance: EditorState) => T;
    apply: (tr: Transaction, value: T, oldState: EditorState, newState: EditorState) => T;
    toJSON?: (value: T) => any;
    fromJSON?: (config: EditorStateConfig, value: any, state: EditorState) => T;
}
```

