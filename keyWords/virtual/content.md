# virtual

---

## 虚函数与运行多态

虚函数的调用取决于指向或者引用的对象类型，而不是指针或者引用本身的类型

demo：

```cpp
#include <iostream>

using namespace std;

class Employee
{
public:
    virtual void raiseSalary()
    {
        cout << 0 << endl;
    }
    virtual void promote()
    {
    }
};

class Manager : public Employee
{
public:
    virtual void raiseSalary()
    {
        cout << 100 << endl;
    }
    virtual void promote()
    {
    }
};

class Engineer : public Employee
{
public:
    virtual void raiseSalary()
    {
        cout << 200 << endl;
    }
    virtual void promote()
    {
    }
};

void globalRaiseSalary(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        emp[i]->raiseSalary();
    }
}

int main()
{
    Employee *emp[] = {
        new Manager(), new Engineer()};
    globalRaiseSalary(emp, 2);
    // 100
    // 200
    return 0;
}
```

---

## 虚函数中的默认参数

默认参数是静态绑定的，虚函数是动态绑定的，默认参数的使用需要看指针或者引用 **本身的类型**，而不是对象的类型。

demo：

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    virtual void fun(int x = 10)
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun(int x = 20)
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};

int main()
{
    // 虚函数动态绑定
    // 默认参数静态绑定
    Derived d;
    Base *p = &d;
    p->fun();
    // Derived::fun(), x = 10
    return 0;
}
```

---

## yes or no

静态函数可以声明为虚函数吗？

静态函数不可以声明为虚函数，同时也不能被 ```const``` 和 ```volatile``` 关键字修饰

原因主要有两方面：

* ```static``` 成员函数不属于任何类对象或类实例，所以即使给此函数加上 ```virutal``` 也是没有任何意义
* 虚函数依靠 ```vptr``` 和 ```vtable``` 来处理。```vptr``` 是一个指针，在类的构造函数中创建生成，并且只能用 ```this``` 指针来访问它，静态成员函数没有 ```this``` 指针，所以无法访问 ```vptr```

demo:

```cpp
// 类声明外部的说明符无效

virtual static void fun()
{
}

// 非成员函数上不允许使用类型限定符
static void fun() const
{
}
```

构造函数可以声明为虚函数吗？

构造函数不可以声明为虚函数。同时除了 ```inline|explicit``` 之外，构造函数不允许使用其它任何关键字。

为什么构造函数不可以为虚函数？

尽管虚函数表 ```vtable``` 是在编译阶段就已经建立的，但指向虚函数表的指针 ```vptr``` 是在运行阶段实例化对象时才产生的。如果类含有虚函数，编译器会在构造函数中添加代码来创建 ```vptr```。

问题来了，如果构造函数是虚的，那么它需要 ```vptr``` 来访问 ```vtable```，可这个时候 ```vptr``` 还没产生。 因此，构造函数不可以为虚函数。

我们之所以使用虚函数，是因为需要在信息不全的情况下进行多态运行。而构造函数是用来初始化实例的，实例的类型必须是明确的。因此，构造函数没有必要被声明为虚函数。

代码学习：

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived created" << endl;
    }
    Derived(const Derived &d)
    {
        cout << "Derived created by deep copy" << endl;
    }
    ~Derived()
    {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Derived d;
    Derived d1 = d;
    // Derived created
    // Derived created by deep copy
    // Derived destroyed
    // Derived destroyed
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

//// LIBRARY SRART
class Base
{
public:
    Base()
    {
    }
    // Ensures to invoke actual object destructor
    virtual ~Base() {}
    virtual void ChangeAttributes() = 0;
    // The "Virtual Constructor"
    static Base *Create(int id);
    // The "Virtual Copy Constructor"
    virtual Base *Clone() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }
    Derived1(const Derived1 &rhs)
    {
        cout << "Derived1 created by deep copy" << endl;
    }
    ~Derived1()
    {
        cout << "~Derived1 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived1 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived1(*this);
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }
    Derived2(const Derived2 &rhs)
    {
        cout << "Derived2 created by deep copy" << endl;
    }
    ~Derived2()
    {
        cout << "~Derived2 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived2 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived2(*this);
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }
    Derived3(const Derived3 &rhs)
    {
        cout << "Derived3 created by deep copy" << endl;
    }
    ~Derived3()
    {
        cout << "~Derived3 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived3 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived3(*this);
    }
};

// We can also declare "Create" outside Base.
// But is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User need not be recompiled to create newly added class objects

    if (id == 1)
    {
        return new Derived1;
    }
    else if (id == 2)
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}
// LIBRARY END

// UTILITY SRART
class User
{
public:
    User() : pBase(0)
    {
        // Creates any object of Base heirarchey at runtime
        int input;
        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;
        while ((input != 1) && (input != 2) && (input != 3))
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }

        // Create objects via the "Virtual Constructor"
        pBase = Base::Create(input);
    }

    ~User()
    {
        if (pBase)
        {
            delete pBase;
            pBase = 0;
        }
    }
    void Action()
    {
        // Duplicate current object
        Base *pNewBase = pBase->Clone();
        // Change its attributes
        pNewBase->ChangeAttributes();
        // Dispose the created object
        delete pNewBase;
    }

private:
    Base *pBase;
};

// UTILITY END
// Consumer of User (UTILITY) class
int main()
{
    User *user = new User();
    user->Action();
    delete user;
    /*
    Enter ID (1, 2 or 3): 1
    Derived1 created
    Derived1 created by deep copy
    Derived1 Attributes Changed
    ~Derived1 destroyed
    ~Derived1 destroyed

    Enter ID (1, 2 or 3): 2
    Derived2 created
    Derived2 created by deep copy
    Derived2 Attributes Changed
    ~Derived2 destroyed
    ~Derived2 destroyed

    Enter ID (1, 2 or 3):
    Derived3 created
    Derived3 created by deep copy
    Derived3 Attributes Changed
    ~Derived3 destroyed
    ~Derived3 destroyed
    */
}
```

析构函数可以为虚函数吗

析构函数可以声明为虚函数。如果我们需要删除一个指向派生类的基类指针时，应该把析构函数声明为虚函数。事实上，只要一个类有可能会被其它类所继承，就应该声明虚析构函数(哪怕该析构函数不执行任何操作)

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base" << endl;
    }
    virtual ~Base()
    {
        cout << "Destructing Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructing Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructing Derived" << endl;
    }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    // Constructing Base
    // Constructing Derived
    // Destructing Derived
    // Destructing Base
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base" << endl;
    }
    ~Base()
    {
        cout << "Destructing Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructing Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructing Derived" << endl;
    }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete d;
    /*
    Constructing Base
    Constructing Derived
    Destructing Derived
    Destructing Base
    */

    delete b;
    /*
    Constructing Base
    Constructing Derived
    Destructing Base
    */
    return 0;
}
```

虚函数可以为私有函数吗

* 基类指针指向继承类对象，则调用继承类对象的函数
* ```int main()``` 必须声明为 ```Base``` 类的友元，否则编译失败，编译器报错： ptr 无法访问私有函数。当然，把基类声明为 ```public```， 继承类为 ```private```，该问题就不存在了

```cpp
#include <iostream>

using namespace std;

class Dervied;

class Base
{
private:
    virtual void fun()
    {
        cout << "Base fun" << endl;
    }
    friend int main();
};

class Derived : public Base
{
public:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Base *p = new Derived();
    p->fun();
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
虚函数可以被私有化，但有一些细节需要注意。
基类指针指向继承类对象，则调用继承类对象的函数；
int main() 必须声明为 Base 类的友元，否则编译失败。编译器报错：ptr 无法访问私有函数。
当然，把基类声明为 public，继承类为 private，该问题就不存在了。----> 见另外一个例子
*/

class Dervied;

class Base
{
public:
    virtual void fun()
    {
        cout << "Base fun" << endl;
    }
    // friend int main();
};

class Derived : public Base
{
private:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Base *p = new Derived();
    p->fun();
    // Derived fun
    return 0;
}
```

---

## 虚函数可以被内联吗

通常类成员函数都会被编译器考虑是否进行内联。但通过基类指针或者引用调用的虚函数必定不能被内联。当然，实体对象调用虚函数或者静态调用时可以被内联，虚析构函数的静态调用也一定会被内联展开。

* 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联
* 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时(运行期)不可以内联。
* ```inline virtual``` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类(如 ```Base::who()```)，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    virtual void fun()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    void fun()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base b;
    b.fun();

    Base *p = new Derived();
    p->fun();
    // Base
    // Derived
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    inline virtual void who()
    {
        cout << "Base" << endl;
    }
    virtual ~Base()
    {
    }
};

class Derived : public Base
{
public:
    inline void who()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base b;
    b.who();

    Base *p = new Derived();
    p->who();

    delete p;

    // Base
    // Derived
    return 0;
}
```

---

## RTTI 与 dynamic_cast

RTTI(Run-Time Type Identification)，通过运行时类型信息程序能够使用基类的指针或引用来检查这些指针或引用所指的对象的实际派生类型。

在面向对象程序设计中，有时需要在运行时查询一个对象是否能作为某种多态类型使用。与 Java 的 ```instanceof```，以及 C# 的 ```as、is``` 运算符类似，C++ 提供了 ```dynamic_cast``` 函数用于动态转型。相比 C 风格的强制类型转换和 C++ ```reinterpret_cast```，```dynamic_cast``` 提供了类型安全检查，是一种基于能力查询(Capability Query)的转换，所以在多态类型间进行转换更提倡采用 ```dynamic_cast```。

```cpp
#include <iostream>
#include <typeinfo>

using namespace std;

class B
{
private:
    virtual void fun()
    {
    }
};

class D : public B
{
};

int main()
{
    B *b = new D; // 向上转型
    B &obj = *b;
    D *d = dynamic_cast<D *>(b); // 向下转型
    if (d != NULL)
        cout << "works" << endl;
    else
        cout << "cannot cast B* to D*";

    try
    {
        D &dobj = dynamic_cast<D &>(obj);
        cout << "works" << endl;
    }
    catch (bad_cast bc)
    { // ERROR
        cout << bc.what() << endl;
    }
    // works
    // works
    return 0;
}
```

```cpp
class A
{
};

class B
{
public:
    virtual ~B()
    {
    }
};

class D : public A
{
};

class E : private A
{
};

class F : private B
{
};
```

---

## 总结

默认参数静态绑定，虚函数动态绑定，且取决于指向或者引用对象的类型

静态函数，构造函数不可声明为虚函数，析构函数则可以，虚函数可以为私有函数，需要对类的权限作一些修改，声明友元

虚函数视情况进行内联，类型转换时尽量使用 ```dynamic_cast```，更加安全

---
