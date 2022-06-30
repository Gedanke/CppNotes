# Day4

---

constructor：

一、类对象成员的构造，先构造成员，再构造自身(调用构造函数)

二、派生类构造函数 派生类可能有多个基类，也可能包括多个成员对象，在创建派生类对象时，派生类的构造函数除了要负责本类成员的初始化外，还要调用基类和成员对象的构造函数，并向它们传递参数，以完成基类子对象和成员对象的建立和初始化。

派生类只能采用构造函数初始化列表的方式向基类或成员对象的构造函数传递参数，形式如下：

派生类构造函数名(参数表):

```cpp
基类构造函数名(参数表), 成员对象名 1(参数表),...
{ 
    // ...
}
```

三、构造函数和析构函数调用次序 派生类对象的构造

* 先构造基类
* 再构造成员
* 最后构造自身(调用构造函数)

基类构造顺序由派生层次决定：最远的基类最先构造，成员构造顺序和定义顺序符合，析构函数的析构顺序与构造相反

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    A(int i = 0)
    {
        this->x = i;
        cout << "----A----" << endl;
    }
};

class B
{
private:
    int y;

public:
    B(int i)
    {
        this->y = i;
        cout << "----B----" << endl;
    }
};

class C
{
private:
    int z;

public:
    C(int i)
    {
        this->z = i;
        cout << "----C----" << endl;
    }
};

class D : public B
{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D() : a0(0), a4(4), c1(1), c2(2), B(1)
    {
        cout << "----D----" << endl;
    }
    ~D()
    {
        delete this->a1;
    }
};

int main()
{
    D d;

    /*
        ----B----
        ----C----
        ----C----
        ----A----
        ----A----
        ----A----
        ----D----
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    先构造成员
    再构造自身（调用构造函数）
*/

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
    B b;
    A a;
};

int main()
{
    C c;

    /*
        B
        A
        C
        ~C
        ~A
        ~B
    */

    return 0;
}
```

构造函数和析构函数的构造规则

* 派生类可以不定义构造函数的情况，当具有下述情况之一时
    * 派生类可以不定义构造函数
    * 基类没有定义任何构造函数
    * 基类具有缺省参数的构造函数
    * 基类具有无参构造函数
* 派生类必须定义构造函数的情况，当基类或成员对象所属类只含有带参数的构造函数时，即使派生类本身没有数据成员要初始化，它也必须定义构造函数，并以构造函数初始化列表的方式向基类和成员对象的构造函数传递参数，以实现基类子对象和成员对象的初始化
* 派生类的构造函数只负责直接基类的初始化

C++ 语言标准有一条规则：

如果派生类的基类同时也是另外一个类的派生类，则每个派生类只负责它的直接基类的构造函数调用。这条规则表明当派生类的直接基类只有带参数的构造函数，但没有默认构造函数时(包括缺省参数和无参构造函数)，它必须在构造函数的初始化列表中调用其直接基类的构造函数，并向基类的构造函数传递参数，以实现派生类对象中的基类子对象的初始化。这条规则有一个例外情况，当派生类存在虚基类时，所有虚基类都由最后的派生类负责初始化

总结：

* 当有多个基类时，将按照它们在继承方式中的声明次序调用，与它们在构造函数初始化列表中的次序无关。当基类 A 本身又是另一个类 B 的派生类时，则先调用基类 B 的构造函数，再调用基类 A 的构造函数

* 当有多个对象成员时，将按它们在派生类中的声明次序调用，与它们在构造函数初始化列表中的次序无关

* 当构造函数初始化列表中的基类和对象成员的构造函数调用完成之后，才执行派生类构造函数体中的程序代码

```cpp
#include <iostream>

using namespace std;

/*
    先构造成员
    再构造自身（调用构造函数）
*/

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        cout << "~B" << endl;
    }
};

int main()
{
    B b;

    /*
        A
        ~B
        ~A
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    Base(int a)
    {
        this->x = a;
        cout << "Base x= " << this->x << endl;
    }
    ~Base()
    {
        cout << "~Base" << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int a, int b) : Base(a)
    {
        this->y = b;
        cout << "Derived y= " << this->y << endl;
    }
    ~Derived()
    {
        cout << "~Derived" << endl;
    }
};

int main()
{
    Derived d(1, 2);

    /*
        Base x= 1
        Derived y= 2
        ~Derived
        ~Base
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};

class D
{
private:
    B b;
    A a;
    C c;

public:
    D()
    {
        cout << "D" << endl;
    }
    ~D()
    {
        cout << "~D" << endl;
    }
};

int main()
{
    D d;

    /*
        B
        A
        C
        D
        ~D
        ~C
        ~A
        ~B
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Point
{
protected:
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout << "point(" << this->x << "," << this->y << ")" << endl;
    }
};

class Line : public Point
{
protected:
    int len;

public:
    Line(int a, int b, int l) : Point(a, b)
    {
        this->len = l;
        cout << "Line" << endl;
    }
};

int main()
{
    Line l(1, 2, 3);

    /*
        point(1,2)
        Line
    */

    return 0;
}
```

继承：

```cpp
#include <iostream>

using namespace std;

/*
    基类中protected的成员
    类内部：可以访问
    类的使用者：不能访问
    类的派生类成员：可以访问
*/

class B
{
private:
    int i;

protected:
    int j;

public:
    int k;
};

class D : public B
{
public:
    void f()
    {
        // this->i=1;
        // 成员 "B::i" (已声明 所在行数:14) 不可访问
        this->j = 2;
        this->k = 3;
    }
};

int main()
{
    B b;
    // b.i=1;
    // 成员 "B::i" (已声明 所在行数:14) 不可访问
    // b.j=2;
    // 成员 "B::j" (已声明 所在行数:16) 不可访问
    b.k = 3;
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    派生方式为protected的继承称为保护继承，在这种继承方式下，
    基类的public成员在派生类中会变成protected成员，
    基类的protected和private成员在派生类中保持原来的访问权限
*/

class Base
{
private:
    int x;

protected:
    int getX()
    {
        return this->x;
    }

public:
    void setX(int x)
    {
        this->x = x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : protected Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:19) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:22) 不可访问
    d.showY();
    // 20
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    void setX(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return this->x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    d.setX(10);
    d.setY(20);
    d.showX();
    d.showY();
    d.setY();
    d.showX();
    d.showY();

    /*
        10
        20
        10
        10
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    void setX(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return this->x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : private Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:9) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:15) 不可访问
    d.showY();
    // 20
    return 0;
}
```

基类与派生类：

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    void setA(int x)
    {
        this->a = x;
    }
    int getA()
    {
        return this->a;
    }
};

class B : public A
{
private:
    int b;

public:
    void setB(int x)
    {
        this->b = x;
    }
    int getB()
    {
        return this->b;
    }
};

void f1(A a, int x)
{
    a.setA(x);
}

void f2(A *a, int x)
{
    a->setA(x);
}

void f3(A &a, int x)
{
    a.setA(x);
}

int main()
{
    A a1, *pa;
    B b1, *pb;
    a1.setA(1);
    b1.setA(2);
    // 把派生类对象赋值给基类对象
    a1 = b1;
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 2
    // 2
    a1.setA(10);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 10
    // 2
    // 把派生类对象的地址赋值给基类指针
    pa = &b1;
    pa->setA(20);
    cout << pa->getA() << endl;
    cout << b1.getA() << endl;
    // 20
    // 20
    // 用派生类对象初始化基类对象的引用
    A &ra = b1;
    ra.setA(30);
    cout << ra.getA() << endl;
    cout << b1.getA() << endl;
    // 30
    // 30
    b1.setA(7);
    cout << b1.getA() << endl;
    // 7
    f1(b1, 100);
    cout << b1.getA() << endl;
    // 7
    f2(&b1, 200);
    cout << b1.getA() << endl;
    // 200
    f3(b1, 300);
    cout << b1.getA() << endl;
    // 300
    return 0;
}
```

虚拟继承：

多继承下的二义性：在多继承方式下，派生类继承了多个基类的成员，当两个不同基类拥有同名成员时，容易产生名字冲突问题。

虚拟继承引入的原因：重复基类，派生类间接继承同一基类使得间接基类(Person)在派生类中有多份拷贝，引发二义性。

* 虚拟继承 `virtual inheritance` 的定义，语法 `class derived_class : virtual [...] base_class 虚基类 virtual base class 被虚拟继承的基类`，在其所有的派生类中，仅出现一次

* 虚拟继承的构造次序，虚基类的初始化与一般的多重继承的初始化在语法上是一样的，但构造函数的调用顺序不同；若基类由虚基类派生而来，则派生类必须提供对间接基类的构造(即在构造函数初始列表中构造虚基类，无论此虚基类是直接还是间接基类)调用顺序的规定： 
    * 先调用虚基类的构造函数，再调用非虚基类的构造函数
        * 若同一层次中包含多个虚基类，这些虚基类的构造函数按它们的说明的次序调用 
        * 若虚基类由非基类派生而来，则仍然先调用基类构造函数，再调用派生类构造函数 
* 虚基类由最终派生类初始化 在没有虚拟继承的情况下，每个派生类的构造函数只负责其直接基类的初始化。但在虚拟继承方式下，虚基类则由最终派生类的构造函数负责初始化。在虚拟继承方式下，若最终派生类的构造函数没有明确调用虚基类的构造函数，编译器就会尝试调用虚基类不需要参数的构造函数(包括缺省、无参和缺省参数的构造函数)，如果没找到就会产生编译错误

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    // d.fun(); "D::fun" 不明确
    return 0;
}
```

* 公有继承
    * 基类中 `protected`的成员。类内部：可以访问；类的使用者：不能访问；类的派生类成员：可以访问
    * 派生类不可访问基类的 `private` 成员
    * 派生类可访问基类的 `protected` 成员
    * 派生类可访问基类的 `public` 成员

基类 `public` 继承 派生类

* `public -> public`
* `protected -> protected`
* `private -> 不可访问`

* 私有继承。派生类也不可访问基类的 `private` 成员

基类 `private` 继承 派生类

* `public -> private`
* `protected -> private`
* `private -> 不可访问`

* 保护继承。派生方式为 `protected` 的继承称为保护继承，在这种继承方式下，基类的 `public` 成员在派生类中会变成 `protected` 成员，基类的 `protected` 和 `private` 成员在派生类中保持原来的访问权限。注意点：当采用保护继承的时候，由于 `public` 成员变为 `protected` 成员，因此类的使用者不可访问，而派生类可访问

基类 `protected` 继承 派生类

* `public -> protected`
* `protected -> protected`
* `private -> 不可访问`

* 派生类对基类成员的访问形式
    * 通过派生类对象直接访问基类成员
    * 在派生类成员函数中直接访问基类成员
    * 通过基类名字限定访问被重载的基类成员名

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    d.fun();
    // A
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a)
    {
        this->a = a;
        cout << "Virtual A" << endl;
    }
};

class B : virtual public A
{
public:
    B(int i) : A(i)
    {
        cout << "virtual B" << endl;
    }
};

class C : virtual public A
{
private:
    int x;

public:
    C(int i) : A(i)
    {
        this->x = i;
        cout << "C" << endl;
    }
};

class ABC : public C, public B
{
public:
    ABC(int i, int j, int k) : C(i), B(j), A(i)
    {
        cout << "ABC" << endl;
    }
};

int main()
{
    ABC abc(1, 2, 3);

    /*
        Virtual A
        C
        virtual B
        ABC
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
};

class B1 : virtual public B, virtual public A
{
public:
    B1(int i)
    {
        cout << "B1" << endl;
    }
};

class B2 : virtual public A, virtual public B
{
public:
    B2(int j)
    {
        cout << "B2" << endl;
    }
};

class D : public B1, public B2
{
public:
    D(int m, int n) : B1(m), B2(n)
    {
        cout << "D" << endl;
    }
    A a;
};

int main()
{
    D d(1, 2);

    /*
        B
        A
        B1
        B2
        A
        D
    */

    return 0;
}
```

直接基类与间接基类：

基类与派生类对象的关系

基类对象与派生类对象之间存在赋值相容性。包括以下几种情况： 

* 把派生类对象赋值给基类对象
* 把派生类对象的地址赋值给基类指针
* 用派生类对象初始化基类对象的引用

反之则不行

* 即不能把基类对象赋值给派生类对象
* 不能把基类对象的地址赋值给派生类对象的指针
* 也不能把基类对象作为派生对象的引用

```cpp
#include <iostream>

using namespace std;

// 当同时存在直接基类和间接基类时，每个派生类只负责其直接基类的构造

class A
{
private:
    int x;

public:
    A(int a)
    {
        this->x = a;
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
public:
    B(int x) : A(x)
    {
        cout << "B" << endl;
    }
};

class C : public B
{
public:
    C(int y) : B(y)
    {
        cout << "C" << endl;
    }
};

int main()
{
    C c(1);

    /*
        A
        B
        C
        ~A
    */

    return 0;
}
```

---
