# sizeof

首先进行总结：

* 空类的大小为 1 字节
* 一个类中，**虚函数本身、成员函数(包括静态与非静态)和静态数据成员** 都是不占用类对象的存储空间
* 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针，vptr 的大小
* 普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小
* 虚函数继承，不管是单继承还是多继承，都是继承了基类的 vptr(32 位操作系统 4 字节，64 位操作系统 8 字节)
* 虚继承，继承基类的 vptr

---

## 原则 1

```cpp
#include <iostream>

using namespace std;

class A
{
};

class B
{
public:
    B();
    ~B();
    static int a;
    static void fun3();
    void fun();
    void fun1();
};

int main()
{
    cout << sizeof(A) << endl;
    // 1
    cout << sizeof(B) << endl;
    // 1
    return 0;
}
```

---

## 原则 2 与 3

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    virtual void fun();
    virtual void fun1();
    virtual void fun2();
    virtual void fun3();
};

class B
{
public:
    char b;
    static int c;
    static int d;
    static int f;
    virtual void fun(){

    };
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 16
    return 0;
}
```

---

## 原则 4 与 5

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    char a;
    int b;
};

class B
{
public:
    short a;
    long b;
};

class C : A, B
{
private:
    char c;
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 16
    cout << sizeof(C) << endl;
    // 32
    return 0;
}
```

## 增加了虚函数

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    char a;
    int b;
};

class B : A
{
public:
    short a;
    long b;
};

class C
{
private:
    A a;
    char c;
};

class A1
{
    virtual void fun()
    {
    }
};

class C1 : public A
{
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 24
    cout << sizeof(C) << endl;
    // 12
    cout << sizeof(A1) << endl;
    // 8
    cout << sizeof(C1) << endl;
    // 8
    return 0;
}
```

---

## 原则 6

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    virtual void fun()
    {
    }
};

class B
{
private:
    virtual void fun2()
    {
    }
};

class C : public A, public B
{
public:
    virtual void fun3()
    {
    }
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 8
    cout << sizeof(C) << endl;
    // 16
    return 0;
}
```

## 虚继承

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    virtual void fun()
    {
    }
};

class B
{
private:
    virtual void fun2()
    {
    }
};

class C : virtual public A, virtual public B
{
public:
    virtual void fun3()
    {
    }
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 8
    cout << sizeof(C) << endl;
    // 16
    return 0;
}
```

---

## 总结

类的大小主要关注数据成员，以及字节对齐原则

---
