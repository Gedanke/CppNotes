# assert

---

## 断言案例

断言是宏，而不是函数

```assert``` 宏的原型定义在 ```<assert.h>``` 中。其作用是如果它的条件返回错误，则终止程序执行。

可以通过定义 ```NDEBUG``` 来关闭 ```assert```，但是需要在源代码的开头，```include <assert.h>``` 之前。

```cpp
void assert(int expression);
```

demo: 

```cpp
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
    int x = 7;
    x = 9;
    assert(x == 7);
    // main: main.cpp:9: int main(): Assertion `x==7' failed.
    // Aborted
    return 0;
}
```

输出

```text
main: main.cpp:10: int main(): Assertion `x == 7' failed.
Aborted
```

可以看到输出会把源码文件，行号错误位置，提示出来！

---

## 断言与正常错误处理

断言主要用于检查逻辑上不可能的情况。

例如，它们可用于检查代码在开始运行之前所期望的状态，或者在运行完成后检查状态。与正常的错误处理不同，断言通常在运行时被禁用。

忽略断言，在代码开头加上：

```cpp
#define NDEBUG          // 加上这行，则 assert 不可用
```

demo:

```cpp
#define NDEBUG

#include <assert.h>

int main()
{
    int x = 7;
    assert(x == 5);
    return 0;
}
```

---

## 总结

断言一个判断语句，如果错误，则终止程序执行，增强程序的健壮性

忽略断言可在代码最开头加入 ```#define NDEBUG```

---
