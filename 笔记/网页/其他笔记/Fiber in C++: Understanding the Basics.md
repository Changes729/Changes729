> 原文链接：https://agraphicsguynotes.com/posts/fiber_in_cpp_understanding_the_basics/
>
> 参考资料：
>
> - [CppCon 2016: James McNellis “Introduction to C++ Coroutines"](https://www.youtube.com/watch?v=ZTqHjjm86Bw)

# Fiber in C++: Understanding the Basics

## 摘记

|         | Subroutine       | Coroutine                                    |
| ------- | ---------------- | -------------------------------------------- |
| Invoke  | Function call    | Function call                                |
| Return  | return statement | co_return statement                          |
| Suspend |                  | co_await expression<br />co_yield expression |
| Resume  |                  | coroutine_handle<>::resume()                 |

传统C++，Subroutine 就是正常的 Function，但是如今，一个Function 可以是 Subroutine ，也可以是 Coroutine。

唤醒（invoke）一个协程会使用程序栈空间。内部会调用可以被重载的 `new`



### 协程如何实现

```cpp
/** auto result = co_await expression; */
auto&& __a = expression;
if(!__a.await_ready())
{
  __a.await_suspend(coroutine-handle);
  // ...suspend/resume porint...
}

auto result = __a.await_resume();

/** suspend_always */
struct suspend_always
{
  bool await_ready() noexcept
  {
    return false;
  }
  
  void await_suspend(coroutine_handle<>) noexcept{}
  void await_resume() noexcept{}
}
```

```cpp
template<>
struct coroutine_handle<void>
{
  coroutine_handle() noecept = default;
  coroutine_handle(nullptr_t) noexcpet;
  coroutine_handle& operator=(nullprt_t) noexcept;
  explicit operator bool() const noexcept;
  
  static coroutine_handle from_address(void* a) noexcept;
  void* to_address() const noexcept;
  
  void operator()() const;
  void resume() const;
  
  void destory();
  
  bool done() const;
}

template<typename Promise>
struct coroutine_handle: coroutine_handle<void>
{
  Promise& promise() const noexcept;
  
  static coroutine_handle from_promise(Promise&) noexcept;
}
```

```cpp
struct resumable_thing
{
  struct promise_type {
    int _value;
    
    resumable_thing get_return_object() {
      return resumable_thing(coroutine_handle<promise_type>::from_promise(*this));
		}
    
    auto initial_suspend(){return suspend_never{};}
    auto final_suspend(){return suspend_always {};}
    
    void return_void(){}
    
    void return_value(int value) { _value = value; }
  };
  
  coroutine_handle<promise_type> _coroutine = nullprt;
  
  explicit resumable_thing(coroutine_handle<promise_type> coroutine)
    :_coroutine(coroutine){}
  
  ~resumable_thing(){
    if(_coroutine) {_coroutine.destory();}
  }
  
  int get() {return _coroutine.promise()._value;}
}
```

```cpp
/** example1 */
// local storage struct
struct __counter_context {
  resumable_thing::promise_type _promise;
  unsigned											_i;
  void*													_instruction_pointer;
}

resumable_thing counter(){
  __counter_context* __context = new __counter_context{};
  __return = __context->_promise.get_return_object();
  co_await 	 __context->_promise.initial_suspend();
  
  cout << "counter: called\n";
  for (unsigned i = 1; ; ++i) {
    co_await suspend_always();
    cout << "counter: resumed\n";
	}

__final_suspend_label:
  co_await __context->_promise.final_suspend();
  delete __context;
}
```

```cpp
/** exmaple2 */
resumable_thing get_value(){
  __counter_context* __context = new __counter_context{};
  __return = __context->_promise.get_return_object();
  co_await 	 __context->_promise.initial_suspend();
  
  cout << "get_value: called\n";
  co_await suspend_always();
  cout << "get_value: resumed\n";
  
	/** co_return 30; */
  __context->_promise.return_value(30);
  goto __final_suspend_label;

__final_suspend_label:
  co_await __context->_promise.final_suspend();
  delete __context;
}
```

```cpp
/** future */
template<typename T>
class fucure
{
	struct promise_type
  {
    
  };
  
  bool await_ready();
  void await_suspend(coroutine_handle<>);
  T		 await_resume();
}

template<typename T>
struct future_awaiter{
  future<T>& _f;
  bool await_ready() { return _f.is_ready(); }
  void await_suspend(coroutine_handle<> ch)
  {
    _f.then([ch](){ch.resume();})
  }
  auto await_resume(){return _f.get();}
}

template<typename T>
future_awaiter<T> operator co_await(future<T>& value)
{
	return future_awaiter<T>{value};
}

template<typename T, typename... Arguments>
struct coroutine_traits<future<T>, Arduments...>
{
  struct promise_type
  {
    promise<T> _promise;
    
    future<T> get_return_object() { return _promise.get_future(); }
    
    auto initial_suspend() { return suspend_never{};}
    auto final_suspend() { return suspend_never{};}
    
    template<typename U>
    void return_value(U&& value){ _promise.set_value(std::forward<U>(value));}
    
    void set_exception(std::exception_prt ex) { _promise.set_exception(std::move(ex));}
	}
}
```

 