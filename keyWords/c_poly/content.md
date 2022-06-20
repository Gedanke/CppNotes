# C 实现 C++ 的面向对象特性

---

## C++ 实现案例

C++ 中的多态: 在 C++ 中会维护一张虚函数表，根据赋值兼容规则，我们知道父类的指针或者引用是可以指向子类对象的。

如果一个父类的指针或者引用调用父类的虚函数则该父类的指针会在自己的虚函数表中查找自己的函数地址，如果该父类对象的指针或者引用指向的是子类的对象，而且该子类已经重写了父类的虚函数，则该指针会调用子类的已经重写的虚函数。

demo:

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    virtual void f()
    {
        cout << "Base A::fun()" << endl;
    }
};

class B : public A
{
public:
    virtual void f()
    {
        cout << "Derived B::fun()" << endl;
    }
};

int main()
{
    A a;
    B b;

    A *pa = &a;
    pa->f();

    pa = &b;
    pa->f();
    //  Base A::fun()
    // Derived B::fun()
    return 0;
}
```

---

## C 实现

* 封装

C 语言中是没有 ``class`` 类这个概念的，但是有 ``struct`` 结构体，可以考虑使用 ``struct`` 来模拟；

使用函数指针把属性与方法封装到结构体中。

* 继承

结构体嵌套

* 多态

类与子类方法的函数指针不同

在 C 语言的结构体内部是没有成员函数的，如果实现这个父结构体和子结构体共有的函数呢？我们可以考虑使用函数指针来模拟。但是这样处理存在一个缺陷就是：父子各自的函数指针之间指向的不是类似 C++ 中维护的虚函数表而是一块物理内存，如果模拟的函数过多的话就会不容易维护了。

模拟多态，必须保持函数指针变量对齐(在内容上完全一致，而且变量对齐上也完全一致)。否则父类指针指向子类对象，运行崩溃！

demo:

```cpp
#include <stdio.h>

typedef void (*pf)();

typedef struct _A
{
    pf _f;
} A;

typedef struct _B
{
    A _b;
} B;

void FunA()
{
    printf("%s\n", "Base A::fun()");
}

void FunB()
{
    printf("%s\n", "Base B::fun()");
}

int main()
{
    A a;
    B b;

    a._f = FunA;
    b._b._f = FunB;

    A *pa = &a;
    pa->_f();
    pa = (A *)&b;
    pa->_f();

    a._f();
    b._b._f();

    /*
        Base A::fun()
        Base B::fun()
        Base A::fun()
        Base B::fun()
    */

    return 0;
}
```

---
