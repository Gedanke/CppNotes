# using

---

## 基本使用

局部与全局 ```using```，具体操作与使用见下面案例：

```cpp
#include <iostream>
#define isNs1 1
// #define isGlobal 2

using namespace std;

void func()
{
    cout << "::func" << endl;
}

namespace ns1
{
    void func()
    {
        cout << "ns1::func" << endl;
    }
}

namespace ns2
{
#ifdef isNs1
    using ns1::func;
#elif isGlobal
    using ::func;
#else
    void func()
    {
        cout << "other::func" << endl;
    }
#endif
}

int main()
{
    ns2::func();
    // ns1::func
    return 0;
}
```

---

## 改变访问性

```cpp
class Base
{
public:
    std::size_t size() const { return n; }

protected:
    std::size_t n;
};
class Derived : private Base
{
public:
    using Base::size;

protected:
    using Base::n;
};
```

类 ```Derived``` 私有继承了 ```Base```，对于它来说成员变量 n 和成员函数 size 都是私有的，如果使用了 ```using``` 语句，可以改变他们的可访问性，如上述例子中，size 可以按 ```public``` 的权限访问，n 可以按 ```protected``` 的权限访问。

```cpp
#include <iostream>

using namespace std;

class Base1
{
protected:
    int value;

public:
    Base1() : value(10)
    {
    }
    virtual ~Base1()
    {
    }
    void test1()
    {
        cout << "Base test1..." << endl;
    }
};

class Derived1 : Base1
{
public:
    void test2()
    {
        cout << "value is " << value << endl;
    }
};

class Base
{
protected:
    int value;

public:
    Base() : value(20)
    {
    }
    virtual ~Base()
    {
    }
    void test1()
    {
        cout << "Base test1..." << endl;
    }
};

/*
    子类对父类成员的访问权限跟如何继承没有任何关系，
    “子类可以访问父类的 public 和 protected 成员，不可以访问父类的 private 成员”——这句话对任何一种继承都是成立的。
*/

class Derived : Base
{
public:
    using Base::value;
    void test2()
    {
        cout << "value is " << value << endl;
    }
};

int main()
{
    Derived1 d1;
    d1.test2();

    Derived d;
    d.test2();
    // value is 10
    // value is 20
    return 0;
}
```

---

## 函数重载

在继承过程中，派生类可以覆盖重载函数的 0 个或多个实例，一旦定义了一个重载版本，那么其他的重载版本都会变为不可见。

如果对于基类的重载函数，我们需要在派生类中修改一个，又要让其他的保持可见，必须要重载所有版本，这样十分的繁琐。

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    void f()
    {
        cout << "f()" << endl;
    }
    void f(int n)
    {
        cout << "Base::f(int) " << n << endl;
    }
};

class Derived : Base
{
public:
    using Base::f;
    void f(int n)
    {
        cout << "Derived::f(int) " << n << endl;
    }
};

int main()
{
    Base b;
    Derived d;
    d.f();
    d.f(1);
    // f()
    // Derived::f(int) 1
    return 0;
}
```

如上代码中，在派生类中使用 ```using``` 声明语句指定一个名字而不指定形参列表，所以一条基类成员函数的 ```using``` 声明语句就可以把该函数的所有重载实例添加到派生类的作用域中。此时，派生类只需要定义其特有的函数就行了，而无需为继承而来的其他函数重新定义。

---

## 取代 typedef

C 中常用 ```typedef A B``` 这样的语法，将 B 定义为 A 类型，也就是给 A 类型一个别名 B

对应 ```typedef A B```，使用 ```using B = A``` 可以进行同样的操作。

```cpp
typedef vector<int> V1; 
using V2 = vector<int>;
```

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V1;
using V2 = vector<int>;

int main()
{
    int num1[] = {
        1, 2, 3, 4, 5, 6};
    V1 vec1(num1, num1 + sizeof(num1) / sizeof(int));
    int num2[] = {
        5, 7, 6};
    V2 vec2(num2, num2 + sizeof(num2) / sizeof(int));

    for (auto i : vec1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : vec2)
    {
        cout << i << " ";
    }
    cout << endl;
    // 1 2 3 4 5 6
    // 5 7 6
    return 0;
}
```

---
