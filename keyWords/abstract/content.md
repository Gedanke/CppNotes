# 纯虚函数与抽象类

---

## 纯虚函数与抽象类

C++ 中的纯虚函数(或抽象函数)是没有实现的虚函数。我们只需声明它，通过声明中赋值 0 来声明纯虚函数。

```cpp
class A
{
public:
    virtual void show() = 0; // 纯虚函数
    /* Other members */
};
```

* 纯虚函数：没有函数体的虚函数
* 抽象类：包含纯虚函数的类

抽象类只能作为基类来派生新类使用，不能创建抽象类的对象，抽象类的指针和引用->由抽象类派生出来的类的对象

demo:

```cpp
#include <iostream>

using namespace std;

// C++ 中的纯虚函数(或抽象函数)是我们没有实现的虚函数！我们只需声明它!通过声明中赋值 0 来声明纯虚函数
// 纯虚函数：没有函数体的虚函数

class Test
{
private:
    int a;

public:
    virtual void show() = 0;
};

int main()
{
    // Test test;
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    Test *ptr;

    // Test *t=new Test();
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    return 0;
}
```

---

## 实现抽象类

抽象类中：在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能使用纯虚函数。

如果一个类从抽象类派生而来，它必须实现了基类中的所有纯虚函数，才能成为非抽象类。

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    virtual void f() = 0;
    void g()
    {
        this->f();
    }
    A()
    {
    }
};

class B : public A
{
public:
    void f()
    {
        cout << "B:f()" << endl;
    }
};

int main()
{
    B b;
    b.g();
    // B:f()
    return 0;
}
```

---

## 重要点

纯虚函数使得一个类成为抽象类

```cpp
#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Test
{
private:
    int x;

public:
    virtual void show() = 0;
    int getX()
    {
        return this->x;
    }
};

int main()
{
    // Test t;
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    return 0;
}
```

抽象类类型的指针与引用

```cpp
#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
private:
    int x;

public:
    virtual void show() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
    void show()
    {
        cout << "In Derived" << endl;
    }
};

int main()
{
    Base *bp = new Derived();
    bp->show();
    // In Derived
    return 0;
}
```

如果不再派生类中覆盖纯虚函数，那么派生类也是抽象类

```cpp
#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
private:
    int x;

public:
    virtual void show() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
};

int main()
{
    // Derived d;
    // 不允许使用抽象类类型 "Derived" 的对象: -- 纯虚拟 函数 "Base::show" 没有强制替代项
    return 0;
}
```

抽象类可以有构造函数

```cpp
#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
protected:
    int x;

public:
    virtual void fun() = 0;
    Base(int i)
    {
        this->x = i;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int x, int y) : Base(x)
    {
        this->y = y;
    }
    void fun()
    {
        cout << "x = " << x << ";y = " << y << endl;
    }
};

int main()
{
    Derived d(3, 4);
    d.fun();
    // x = 3;y = 4
    return 0;
}
```

构造函数不能是虚函数，但析构函数可以是

```cpp
#include <iostream>

using namespace std;

// 构造函数不能是虚函数，而析构函数可以是虚析构函数。
// 例如：当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。如果析构函数不是虚拟的，则只能调用基类析构函数。

class Base
{
public:
    Base()
    {
        cout << "Constructor: Base" << endl;
    }
    virtual ~Base()
    {
        cout << "Destructor: Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructor: Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructor: Derived" << endl;
    }
};

int main()
{
    Base *pt = new Derived();
    delete pt;
    // Constructor: Base
    // Constructor: Derived
    // Destructor: Derived
    // Destructor: Base
    return 0;
}
```

当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。 如果析构函数不是虚拟的，则只能调用基类析构函数。

完整案例，抽象类由派生类继承实现

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    virtual void fun() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Derived d;
    d.fun();
    // Derived fun
    return 0;
}
```

---

## 总结

纯虚函数赋值为 0 来声明，含有未实现的纯虚函数(自身的以及继承而来)的类为抽象类(和 java 略有不同)，抽象类不能实例化，但可以有指针或者引用，类内部成员函数(不含构造函数与析构函数)可以调用纯虚函数

抽象类有构造函数，构造函数不能为虚函数，析构函数可以

---
