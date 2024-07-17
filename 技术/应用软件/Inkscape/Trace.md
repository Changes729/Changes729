# Trace（位图轮廓描摹）

「西湖群山徒步导览」项目虽然在社会上没有引发什么关注，但是做项目的过程还是有接触到很多新东西，Inkscape轮廓描摹就是其中之一。

Inkscape 的位图轮廓描摹功能非常强大，不仅仅可以作为CV抠图的工具之一，同时也有人利用位图描摹以生产特殊纹理。

位图轮廓描摹功能在 Illustrator（AI）中也有。只不过笔者更喜欢开源的 Inkscape。

本文会涉及两方面——首先会简单带大家过一遍位图描摹在Inkscape中的使用，其次会介绍一下如何在代码工程中寻找其实现。



## 位图轮廓描摹

1. 准备一张位图图片。直接拖拽导入Inkscape。

2. 在工具栏找到 `路径->临摹位图轮廓`，然后在右侧详细工具区就会看到它。

3. 我们的目标是想要提取出地图中的各个区块，所以选择 `多次扫描`，再选择`检测模式`为`亮度步进`

   > 为什么不选择 `颜色`，是因为选择`颜色`后整个矢量分割会非常乱，不如`亮度步进`来的清晰，推荐大家自己尝试一下。

4. 然后我们就能在得到一个图层被打包好的矢量描摹组了。

5. 最后可以选择矢量图层进行上色。



## 代码位置

Inkscape trace 位于 `src/trace/` 目录下，可以看到有三种描摹引擎。

```cpp
/** inkscape-potrace.h */
class PotraceTracingEngine final
    : public TracingEngine
    {...}

/** inkscape-autotrace.h */
class AutotraceTracingEngine final
    : public TracingEngine
    {...}

/** inkscape-depixelize.h */
class DepixelizeTracingEngine final
    : public TracingEngine
    {...}
```

让我们回到 GUI，GUI分到三个页面的定义在代码中如下，正好对应了GUI上的 「单次扫描」、「多次扫描」和「像素画」：

```cpp
/** tracedialog.cpp */
enum class Page
{
    SingleScan,
    MultiScan,
    PixelArt
};
```

然后因为GUI在每个不同的扫描类型下还有子选项，比如「多次扫描」下的「亮度步进」、「颜色」等等，代码中的定义如下：

```cpp
constexpr auto cbt_ss_map = std::to_array({
    Trace::Potrace::TraceType::BRIGHTNESS, 					// 亮度截断 
    Trace::Potrace::TraceType::CANNY,								// 边缘检测
    Trace::Potrace::TraceType::QUANT,								// 颜色量化
    Trace::Potrace::TraceType::AUTOTRACE_SINGLE,		// 自动临摹（单次）
    Trace::Potrace::TraceType::AUTOTRACE_CENTERLINE	// 中心线追踪
});

constexpr auto cbt_ms_map = std::to_array({
    Trace::Potrace::TraceType::BRIGHTNESS_MULTI, // 亮度步进
    Trace::Potrace::TraceType::QUANT_COLOR,			 // 颜色
    Trace::Potrace::TraceType::QUANT_MONO,			 // 灰度
    Trace::Potrace::TraceType::AUTOTRACE_MULTI 	 // 自动追踪（多次）
});
```

而具体的描摹类型 `TraceType` 到具体的描摹引擎 `TracingEngine` 是在函数 `getTraceData` 中进行选择的：

```cpp
/** tracedialog.cpp */
TraceData TraceDialogImpl::getTraceData() const
{
    auto current_page = static_cast<Page>(choice_tab.get_current_page());

    auto &cb_siox = current_page == Page::SingleScan ? CB_SIOX : CB_SIOX1;
    bool enable_siox = cb_siox.get_active();

    auto trace_type = current_page == Page::SingleScan
                    ? cbt_ss_map.at(CBT_SS.get_selected())
                    : cbt_ms_map.at(CBT_MS.get_selected());

    EngineType engine_type;
    if (current_page == Page::PixelArt) {
        engine_type = EngineType::Depixelize;
    } else {
        switch (trace_type) {
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_SINGLE:
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_CENTERLINE:
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_MULTI:
                engine_type = EngineType::Autotrace;
                break;
            default:
                engine_type = EngineType::Potrace;
                break;
        }
    }

    auto setup_potrace = [&, this] {
        auto eng = std::make_unique<Trace::Potrace::PotraceTracingEngine>(...);
				...
        return eng;
    };

    auto setup_autotrace = [&, this] {
        auto eng = std::make_unique<Trace::Autotrace::AutotraceTracingEngine>();
				...
        return eng;
    };

    auto setup_depixelize = [this] {
        return std::make_unique<Trace::Depixelize::DepixelizeTracingEngine>(...);
    };

    TraceData data;
    switch (engine_type) {
        case EngineType::Potrace:    data.engine = setup_potrace();    break;
        case EngineType::Autotrace:  data.engine = setup_autotrace();  break;
        case EngineType::Depixelize: data.engine = setup_depixelize(); break;
        default: assert(false); break;
    }
    data.sioxEnabled = enable_siox;

    return data;
}
```

ok，现在我们已经找到了 GUI 到引擎的关系，接下来带着走一遍执行路径。用户交互路径基本上是`按钮按下->软件执行->反馈信息`

我们可以先看一下具体的描摹类实现：

```cpp
/** tracedialog.cpp */
class TraceDialogImpl : public TraceDialog
{
public:
    TraceDialogImpl();
    ~TraceDialogImpl() override;

protected:
    void selectionModified(Selection *selection, unsigned flags) override;
    void selectionChanged(Selection *selection) override;

private:
    TraceData getTraceData() const;
    void setDefaults();
    void adjustParamsVisible();
    void onTraceClicked();
    void onAbortClicked();
    bool previewsEnabled() const;
    void schedulePreviewUpdate(int msecs, bool force = false);
    void updatePreview(bool force = false);
    void launchPreviewGeneration();
  	...
};
```

简单看，`protected` 的一些函数，其实都是事件触发函数。而 `private` 中的一些内容则是具体的操作。很明显有 `onTraceClicked` 追踪触发函数，也有 `updatePreview` 更新预览的功能。直接看 `onTraceClicked`：

```cpp
/** tracedialog.cpp */
void TraceDialogImpl::onTraceClicked()
{
	  ...
    // Attempt to fire off the tracer.
    auto data = getTraceData();
    trace_future = Trace::trace(std::move(data.engine), data.sioxEnabled,
        // On progress:
        [this] (double progress) {
            progressbar.set_fraction(progress);
        },
        // On completion without cancelling:
        [this] {
            progressbar.set_fraction(1.0);
            stack.set_visible_child(boxchild1);
            if (auto desktop = getDesktop()) desktop->clearWaitingCursor();
            trace_future.cancel();
        }
    );

    ...
}
```

可以看到，这个触发器，只是创建了一个「任务（`trace_future`）」，将一些任务设置好。

做过应用开发的小伙伴们应该都清楚，执行任务时都需要对任务进行抽象，除了在管理上方便对其生命周期进行操作，同时抽象出来后也可以将他们作为异步单元进行性能优化。

```cpp
/** trace.cpp */
TraceFuture trace(std::unique_ptr<TracingEngine> engine, bool sioxEnabled, std::function<void(double)> onprogress, std::function<void()> onfinished)
{
    auto task = std::make_unique<TraceTask>(std::move(engine), sioxEnabled, std::move(onprogress), std::move(onfinished));
    auto saved = task.get();
    return saved->launch(std::move(task));
}

TraceFuture TraceTask::launch(std::unique_ptr<TraceTask> self)
{
    ...
    // Open channel and launch background task.

    auto [src, dst] = Async::Channel::create();
    auto image_watcher = std::make_shared<SPWeakPtr<SPImage>>(image);

    channel = std::move(src);
    image_watcher_weak = image_watcher;

    Async::fire_and_forget([this, self = std::move(self)] () mutable {
        do_async_work(std::move(self));
    });

    return detail::TraceFutureCreate::create(std::move(dst), std::move(image_watcher));
}

void TraceTask::do_async_work(std::unique_ptr<TraceTask> self)
{
  	...
    auto progress = Async::BackgroundProgress(channel, onprogress);
  	auto throttled = Async::ProgressTimeThrottler(progress, std::chrono::milliseconds(10));

  	// Get progress subobjects for siox and trace sub-tasks.
  	std::optional<Async::SubProgress<double>> sub_siox, sub_trace;

    Async::ProgressSplitter(throttled)
      .add_if(sub_siox, 0.1, sioxEnabled)
      .add_if(sub_trace, 0.9, type == Type::Trace);

    // Convert the pixbuf to a GdkPixbuf, which due to immutability requires making a copy first.
    auto copy = Pixbuf(*image_pixbuf);
    auto gdkpixbuf = Glib::wrap(copy.getPixbufRaw(), true);

    // If SIOX has been enabled, run SIOX processing.
    if (sioxEnabled) {
      gdkpixbuf = sioxProcessImage(gdkpixbuf, siox_mask, *sub_siox);
      siox_mask.reset();
      sub_siox->report_or_throw(1.0);
    }

    // If in preview mode, compute and return the preview and exit now.
    if (type == Type::Preview) {
      gdkpixbuf = engine->preview(gdkpixbuf);
      channel.run(std::bind(onfinished_preview, std::move(gdkpixbuf)));
      return;
    }

    // Actually perform the tracing.
    traceresult = engine->trace(gdkpixbuf, *sub_trace);

    gdkpixbuf.reset();

    progress.report_or_throw(1.0);

    // Return to the original thread for the remainder of the processing.
    channel.run([this, self = std::move(self)] () mutable {
      do_final_work(std::move(self));
    });
	  ...
}
```

这里其实就是使用一个 `unique_ptr` 来管理动态资源，这样程序员就不用太考虑什么时候应该调用 delete 释放资源了。

整个函数基本上也是构建了一个 `TraceTask` 异步任务。异步任务又会执行具体的`do_async_work`操作。可以看到最终调用的是描摹引擎中的 `trace` 函数。

在看具体实现前，我们再回顾一下描摹类型和描摹引擎之间的关系：

```cpp
/** tracedialog.cpp */
TraceData TraceDialogImpl::getTraceData() const {
  	...
    EngineType engine_type;
    if (current_page == Page::PixelArt) {
        engine_type = EngineType::Depixelize;
    } else {
        switch (trace_type) {
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_SINGLE:
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_CENTERLINE:
            case Inkscape::Trace::Potrace::TraceType::AUTOTRACE_MULTI:
                engine_type = EngineType::Autotrace;
                break;
            default:
                engine_type = EngineType::Potrace;
                break;
        }
    }
	  ...
}
```

也就是说，除了自动描摹和像素画以外的所有描摹，都是引擎 `PotraceTracingEngine` 实现的。那我们开始看一下这个引擎的内部实现：

```cpp
/** inkscape-potrace.cpp */
TraceResult PotraceTracingEngine::trace(Glib::RefPtr<Gdk::Pixbuf> const &pixbuf, Async::Progress<double> &progress)
{
    if (traceType == TraceType::QUANT_COLOR || traceType == TraceType::QUANT_MONO) {
        return traceQuant(pixbuf, progress);
    } else if (traceType == TraceType::BRIGHTNESS_MULTI) {
        return traceBrightnessMulti(pixbuf, progress);
    } else { /** BRIGHTNESS、QUANT、CANNY */
        return traceSingle(pixbuf, progress);
    }
}
```

先看 `traceSingle`：

```cpp
/** inkscape-potrace.cpp */
TraceResult PotraceTracingEngine::traceSingle(Glib::RefPtr<Gdk::Pixbuf> const &pixbuf, Async::Progress<double> &progress)
{
    brightnessFloor = 0.0; // important to set this, since used by filter()

    auto grayMap = filter(pixbuf);
    if (!grayMap) {
        return {};
    }

    progress.report_or_throw(0.2);

    auto sub_gm = Async::SubProgress(progress, 0.2, 0.8);
    auto pv = grayMapToPath(*grayMap, sub_gm);

    TraceResult results;
    results.emplace_back("fill:#000000", std::move(pv));
    return results;
}
```

单次扫描，就是通过 `filter` 将位图先灰度化，然后再根据 `grayMapToPath` 灰度图生成矢量路径。

```cpp
/** inkscape-potrace.cpp */
Geom::PathVector PotraceTracingEngine::grayMapToPath(GrayMap const &grayMap, Async::Progress<double> &progress)
{
    auto potraceBitmap = potrace_bitmap_uniqptr(bm_new(grayMap.width, grayMap.height));
    if (!potraceBitmap) {
        return {};
    }

    bm_clear(potraceBitmap.get(), 0);

    // Read the data out of the GrayMap
    for (int y = 0; y < grayMap.height; y++) {
        for (int x = 0; x < grayMap.width; x++) {
            BM_UPUT(potraceBitmap, x, y, grayMap.getPixel(x, y) ? 0 : 1);
        }
    }

    progress.throw_if_cancelled();

    // Trace the bitmap.

    auto throttled = Async::ProgressStepThrottler(progress, 0.02);

    potraceParams->progress.data = &throttled;
    potraceParams->progress.callback = [] (double progress, void *data) { reinterpret_cast<decltype(throttled)*>(data)->report(progress); };
    auto potraceState = potrace_state_uniqptr(potrace_trace(potraceParams, potraceBitmap.get()));

    potraceBitmap.reset();

    progress.throw_if_cancelled();

    // Extract the paths into a pathvector and return it.
    Geom::PathBuilder builder;
    std::unordered_set<Geom::Point> points;
    writePaths(potraceState->plist, builder, points, progress);
    return builder.peek();
}
```

最后我们会看到两个外部库：[`potrace`](https://github.com/skyrpex/potrace) 和 [`2geom`](https://gitlab.com/inkscape/lib2geom)

`potrace` 是一个跟踪位图的工具，可以用它将位图平滑，并变成可以缩放的图像。

而 `2geom` 则是 inkscape 自己写的一款开源 2D 几何库。

所以最后的原理就是 inkscape 使用 potrace 将位图变成矢量图，再通过 `2geom` 变成inkscape自己的数据结构。



## 写在最后

`potrace` 是 [GPL-2.0 license](https://github.com/skyrpex/potrace#GPL-2.0-1-ov-file) 的开源软件，如果嵌入使用，则工程也必须开源。当然 `potrace` 还提供了命令行工具 `mkbitmap`。

这篇文章仅仅只是一个代码扫描，也并没有涉及到最终的 `potrace` 算法层面。如果以后有机会再填坑吧。