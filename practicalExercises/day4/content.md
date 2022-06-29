# Day4

---

clock：

```clock.h```:

```cpp
#ifndef CLOCK
#define CLOCK

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s);
    Clock(Clock &c);
    void set(int h, int m, int s);
    void showTime();
    ~Clock();
};

#endif
```

```clock.cpp```:

```cpp
#include <iostream>
#include "clock.h"

using namespace std;

Clock::Clock(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}

Clock::Clock(Clock &c)
{
    this->hour = c.hour;
    this->minute = c.minute;
    this->second = c.second;
}

void Clock::set(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}

void Clock::showTime()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

Clock::~Clock()
{
}

int main()
{
    Clock c(0, 0, 0);

    c.set(20, 20, 20);
    c.showTime();

    Clock c1(c);
    c1.set(21, 22, 23);
    c1.showTime();
    // 20:20:20
    // 21:22:23
    return 0;
}
```

const：

类型的对象必须进行初始化，而且不能被更新。 

* 常引用：被引用的对象不能被更新。`const 类型说明符 &引用名`
* 常对象：必须进行初始化,不能被更新。`类名 const 对象名` 
* 常数组：数组元素不能被更新。`类型说明符 const 数组名[大小]`
* 常指针：指向常量的指针

```cpp
#include <iostream>

using namespace std;

void display(const double &r);

class A
{
public:
    A(int i, int j)
    {
        this->x = i;
        this->y = j;
    }
    void show()
    {
        cout << this->x << " " << this->y << endl;
    }

private:
    int x;
    int y;
};

int main()
{
    double d = 9.5;
    display(d);
    A const a(3, 4);
    // a.show();
    // 对象含有与成员 函数 "A::show" 不兼容的类型限定符C/C++(1086)
    // main.cpp(25, 5): 对象类型是: const A
    A aa(3, 4);
    aa.show();
    // 9.5
    // 3 4
    return 0;
}

void display(const double &r)
{
    cout << r << endl;
}
```

```cpp
#include <iostream>

using namespace std;

class R
{
public:
    R(int r1, int r2)
    {
        this->R1 = r1;
        this->R2 = r2;
    }
    void print();
    void print() const;

private:
    int R1;
    int R2;
};

/*
    常成员函数说明格式：类型说明符  函数名（参数表）const;
    这里，const是函数类型的一个组成部分，因此在实现部分也要带const关键字。
    const关键字可以被用于参与对重载函数的区分
    通过常对象只能调用它的常成员函数
*/

void R::print()
{
    cout << "普通调用" << endl;
    cout << this->R1 << ":" << this->R2 << endl;
}

void R::print() const
{
    cout << "常对象调用" << endl;
    cout << this->R1 << ":" << this->R2 << endl;
}

int main()
{
    R a(3, 4);
    a.print();
    const R b(6, 8);
    b.print();

    /*
        普通调用
        3:4
        常对象调用
        6:8
    */

    return 0;
}
```

friend：

友元是 C++ 提供的一种破坏数据封装和数据隐藏的机制。通过将一个模块声明为另一个模块的友元，一个模块能够引用到另一个模块中本是被隐藏的信息。可以使用友元函数和友元类。为了确保数据的完整性，及数据封装与隐藏的原则，建议尽量不使用或少使用友元。

友元函数是在类声明中由关键字 `friend` 修饰说明的非成员函数，在它的函数体中能够通过对象名访问 `private` 和 `protected` 成员。

作用：增加灵活性，使程序员可以在封装和快速性方面做合理选择。访问对象中的成员必须通过对象名。

```cpp
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    int X;
    int Y;

public:
    Point(int x = 0, int y = 0)
    {
        this->X = x;
        this->Y = y;
    }
    int getX()
    {
        return this->X;
    }
    int getY()
    {
        return this->Y;
    }
    friend float distance(Point &a, Point &b);
    float distance_(Point &p);
};

float distance(Point &a, Point &b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

float Point::distance_(Point &p)
{
    double dx = this->X - p.getX();
    double dy = this->Y - p.getY();
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p1(3, 4);
    Point p2(0, 0);
    cout << distance(p1, p2) << endl;
    cout << p1.distance_(p2) << endl;
    // 5
    // 5
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
若一个类为另一个类的友元，则此类的所有成员都能访问对方类的私有成员。
声明语法：将友元类名在另一个类中使用friend修饰说明。
*/

class A
{
    friend class B;

private:
    int x;

public:
    void display()
    {
        cout << this->x << endl;
    }
};

/*
    如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，
    但A类的成员函数却不能访问B类的私有、保护数据。
*/

class B
{
private:
    A a;

public:
    void set(int i)
    {
        this->a.x = i;
    }
    void display()
    {
        this->a.display();
    }
};

int main()
{
    B b;
    b.set(10);
    b.display();
    // 10
    return 0;
}
```

overload：

```cpp
#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void operator()(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void showTime()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

int main()
{
    Time t(12, 13, 14);
    t.showTime();
    t.operator()(22, 23, 24);
    t.showTime();
    t(23, 23, 23);
    t.showTime();

    /*
        12:13:14
        22:23:24
        23:23:23
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void operator++();
    void operator++(int);
    void showTime()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

void Time::operator++()
{
    this->s++;
    if (this->s == 60)
    {
        this->s = 0;
        this->m++;
        if (this->m == 60)
        {
            this->m = 0;
            this->h++;
            if (this->h == 24)
            {
                this->h = 0;
            }
        }
    }
}

void Time::operator++(int)
{
    this->s++;
    if (this->s == 60)
    {
        this->s = 0;
        this->m++;
        if (this->m == 60)
        {
            this->m = 0;
            this->h++;
            if (this->h == 24)
            {
                this->h = 0;
            }
        }
    }
}

int main()
{
    Time t(23, 59, 59);
    t.showTime();
    ++t;
    t.showTime();
    t++;
    t.showTime();

    /*
        23:59:59
        0:0:0
        0:0:1
    */

    return 0;
}
```

---
