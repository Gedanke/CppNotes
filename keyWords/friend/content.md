# friend

---

## 概述

友元提供了一种 **普通函数或者类成员函数** 访问另一个类中的私有或保护成员的机制。也就是说有两种形式的友元：

* 友元函数：普通函数对一个访问某个类中的私有或保护成员
* 友元类：类 A 中的成员函数访问类 B 中的私有或保护成员

优缺点：

* 优点：提高了程序的运行效率
* 缺点：破坏了类的封装性和数据的透明性

---

## 友元函数

在类声明的任何区域中声明，定义则在类的外部或者内部

```cpp
friend <类型><友元函数名>(<参数表>);
```

注意，友元函数只是一个普通函数，并不是该类的类成员函数，它可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员。

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int _a) : a(_a)
    {
    }
    friend int getA(A &ca); // 友元函数
    friend int getAA(A &ca)
    {
        return ca.a;
    }
};

int getA(A &ca)
{
    return ca.a;
}

int main()
{
    A a(3);
    cout << getA(a) << endl;
    // cout<<a.getAA()<<endl; // 类 "A" 没有成员 "getAA"
    cout << getAA(a) << endl;
    // 3
    // 3
    return 0;
}
```

---

## 友元类

友元类的声明在该类的声明中，而实现在该类外。

```cpp
friend class <友元类名>;
```

类 B 是类 A 的友元，那么类 B 可以直接访问 A 的私有成员。

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int _a) : a(_a)
    {
    }
    friend class B;
};

class B
{
public:
    int getB(A ca)
    {
        return ca.a;
    }
};

int main()
{
    A a(3);
    B b;
    cout << b.getB(a) << endl;
    // 3
    return 0;
}
```

---

## 总结

friend:

* 能访问私有成员
* 破坏封装性
* 友元关系不可传递
* 友元关系的单向性
* 友元声明的形式及数量不受限制

注意:

* 友元关系没有继承性 假如类 B 是类 A 的友元，类 C 继承于类 A，那么友元类 B 是没办法直接访问类 C 的私有或保护成员
* 友元关系没有传递性 假如类 B 是类 A 的友元，类 C 是类 B 的友元，那么友元类 C 是没办法直接访问类 A 的私有或保护成员，也就是不存在“友元的友元”这种关系

---
