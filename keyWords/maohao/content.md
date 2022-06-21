# ::

---

* 全局作用域符(::name)：用于类型名称(类、类成员、成员函数、变量等)前，表示作用域为全局命名空间
* 类作用域符(class::name)：用于表示指定类型的作用域范围是具体某个类的
* 命名空间作用域符(namespace::name)：用于表示指定类型的作用域范围是具体某个命名空间的

demo:

```cpp
#include <iostream>

using namespace std;

int count = 0;

class A
{
public:
    static int count;
};

int A::count;

int main()
{
    ::count = 1;
    A::count = 5;
    cout << ::count << endl;
    // 1
    cout << A::count << endl;
    // 5
    // int count=3;
    // count=4;
    return 0;
}
```

---
