# Day6

---

abstract：

```cpp
#include <iostream>

using namespace std;

class Figure
{
protected:
    double x, y;

public:
    void set(double i, double j)
    {
        this->x = i;
        this->y = j;
    }
    virtual void area() = 0;
};

class Trianle : public Figure
{
public:
    void area()
    {
        cout << "Trianle" << endl;
    }
};

class Rectangle : public Figure
{
public:
    void area()
    {
        cout << "Rectangle" << endl;
    }
};

int main()
{
    // 抽象指针
    Figure *pf = NULL;
    // Figure f; 不允许使用抽象类类型 "Figure" 的对象
    Rectangle r;
    Trianle t;
    t.set(10, 20);
    pf = &t;
    pf->area();
    r.set(10, 20);
    pf = &r;
    pf->area();
    // 抽象类引用
    Figure &rf = t;
    rf.set(20, 20);
    rf.area();

    /*
        Trianle
        Rectangle
        Trianle
    */

    return 0;
}
```

virtual：

**多态性**

多态性：多态就是在同一个类或继承体系结构的基类与派生类中，用同名函数来实现各种不同的功能

* 静态绑定又称静态联编，是指在编译程序时就根据调用函数提供的信息，把它所对应的具体函数确定下来，即在编译时就把调用函数名与具体函数绑定在一起
* 动态绑定又称动态联编，是指在编译程序时还不能确定函数调用所对应的具体函数，只有在程序运行过程中才能够确定函数调用所对应的具体函数，即在程序运行时才把调用函数名与具体函数绑定在一起
* 编译时多态性：**静态联编(连接)**。系统在编译时就决定如何实现某一动作，即对某一消息如何处理。静态联编具有执行速度快的优点，在 C++ 中的编译时多态性是通过函数重载和运算符重载实现的
* 运行时多态性：**动态联编(连接)**。系统在运行时动态实现某一动作，即对某一消息在运行过程实现其如何响应。动态联编为系统提供了灵活和高度问题抽象的优点，在 C++ 中的运行时多态性是通过继承和虚函数实现的

**虚函数**

虚函数的意义

* 基类与派生类的赋值相容
    * 派生类对象可以赋值给基类对象
    * 派生类对象的地址可以赋值给指向基类对象的指针
    * 派生类对象可以作为基类对象的引用

赋值相容的问题：不论哪种赋值方式，都只能通过基类对象(或基类对象的指针或引用)访问到派生类对象从基类中继承到的成员，不能借此访问派生类定义的成员

* 虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员
* `Virtual` 关键字其实质是告知编译系统，被指定为 `virtual` 的函数采用动态联编的形式编译
* 虚函数的虚特征：基类指针指向派生类的对象时，通过该指针访问其虚函数将调用派生类的版本
    * 一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了
    * 如果基类定义了虚函数，当通过基类指针或引用调用派生类对象时，将访问到它们实际所指对象中的虚函数版本
    * 只有通过基类对象的指针和引用访问派生类对象的虚函数时，才能体现虚函数的特性
    * 派生类中的虚函数要保持其虚特征，必须与基类虚函数的函数原型完全相同，否则就是普通的重载函数，与基类的虚函数无关
    * 派生类通过从基类继承的成员函数调用虚函数时，将访问到派生类中的版本
    * 只有类的非静态成员函数才能被定义为虚函数，类的构造函数和静态成员函数不能定义为虚函数。原因是虚函数在继承层次结构中才能够发生作用，而构造函数、静态成员是不能够被继承的
    * 内联函数也不能是虚函数。因为内联函数采用的是静态联编的方式，而虚函数是在程序运行时才与具体函数动态绑定的，采用的是动态联编的方式，即使虚函数在类体内被定义，C++ 编译器也将它视为非内联函数
    
* 基类析构函数几乎总是为虚析构函数。why? 假定使用 `delete` 和一个指向派生类的基类指针来销毁派生类对象，如果基类析构函数不为虚,就如一个普通成员函数，`delete` 函数调用的就是基类析构函数。在通过基类对象的引用或指针调用派生类对象时，将致使对象析构不彻底！

**纯虚函数和抽象类**

* 纯虚函数概念？

仅定义函数原型而不定义其实现的虚函数 Why pure function? 

实用角度：占位手段 place-holder 方法学：接口定义手段，抽象表达手段 How? 

```cpp
class X 
{ 
    virtual ret_type func_name (param) = 0; 
} 
```
* 抽象类概念？What is an abstract class? 

包含一个或多个纯虚函数的类 Using abstract class 不能实例化抽象类 但是可以定义抽象类的指针和引用 Converting abstract class to concrete class 定义一个抽象类的派生类 定义所有纯虚函数

* C++ 对抽象类具有以下限定

* 抽象类中含有纯虚函数，由于纯虚函数没有实现代码，所以不能建立抽象类的对象
* 抽象类只能作为其他类的基类，可以通过抽象类对象的指针或引用访问到它的派生类对象，实现运行时的多态性
* 如果派生类只是简单地继承了抽象类的纯虚函数，而没有重新定义基类的纯虚函数，则派生类也是一个抽象类

```cpp
#include <iostream>

using namespace std;

class B
{
public:
    void f()
    {
        this->g();
    }
    virtual void g()
    {
        cout << "B::g()" << endl;
    }
};

class D : public B
{
public:
    void g()
    {
        cout << "D::g()" << endl;
    }
};

int main()
{
    D d;
    d.f();
    d.g();
    // D::g()
    // D::g()
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    某公司有经理、销售员、小时工等多类人员。经理按周计算薪金；销售员每月底薪800元，
    然后加销售提成，每销售1件产品提取销售利润的5%；小时工按小时计算薪金。每类人员都有姓名和身份证号等数据。
    为简化问题，把各类人员的共有信息抽象成基类Employee，其他人员则继承该类的功能。
*/

class Employee
{
private:
    string name;
    string id;

public:
    Employee(string name, string id)
    {
        this->name = name;
        this->id = id;
    }
    string getName()
    {
        return this->name;
    }
    string getId()
    {
        return this->id;
    }
    float getSalary()
    {
        return 0.0;
    }
    void print()
    {
        cout << "Name: " << this->name << "\t\t Id: " << this->id << endl;
    }
};

class Manager : public Employee
{
private:
    float weekSalary;

public:
    Manager(string name, string id, int week) : Employee(name, id)
    {
        this->weekSalary = week * 2000;
    }
    float getSalary()
    {
        return this->weekSalary;
    }
    void print()
    {
        cout << "Manager: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

class SaleWorker : public Employee
{
private:
    float baseMoney = 6000.0;
    float workMoney;

public:
    SaleWorker(string name, string id, int profit, int x) : Employee(name, id)
    {
        this->workMoney = this->baseMoney + x * 0.05 * profit;
    }
    float getSalary()
    {
        return this->workMoney;
    }
    void print()
    {
        cout << "SaleWorker: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

class HourWorker : public Employee
{
private:
    float hourMoney = 100.0;
    float totalMoney;

public:
    HourWorker(string name, string id, int h) : Employee(name, id)
    {
        this->totalMoney = h * this->hourMoney;
    }
    float getSalary()
    {
        return this->totalMoney;
    }
    void print()
    {
        cout << "HourWorker: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

int main()
{
    cout << "week: " << endl;
    int week;
    cin >> week;
    Manager m("wang", "12345", week);
    m.print();
    cout << "profit: " << endl;
    int profit;
    cin >> profit;
    cout << "num: " << endl;
    int x;
    cin >> x;
    SaleWorker s("Li", "12344", profit, x);
    s.print();
    cout << "hour: " << endl;
    int hour;
    cin >> hour;
    HourWorker h("He", "12333", hour);
    h.print();

    /*
        week:
        4
        Manager: wang            Id: 12345               Money: 8000
        profit:
        10000
        num:
        3
        SaleWorker: Li           Id: 12344               Money: 7500
        hour:
        8
        HourWorker: He           Id: 12333               Money: 800
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

// 基类指针或引用指向派生类对象时,虚函数与非虚函数区别：
// 声明Employee的print为虚函数，则可访问到Manager的print函数，非虚函数，则只能访问到Employee的print

class Employee
{
private:
    string name;
    string id;

public:
    Employee(string name, string id);
    string getName();
    string getId();
    float getSalary();
    virtual void print();
};

Employee::Employee(string name, string id)
{
    this->name = name;
    this->id = id;
}

string Employee::getName()
{
    return this->name;
}

string Employee::getId()
{
    return this->id;
}

float Employee::getSalary()
{
    return 0.0;
}
void Employee::print()
{
    cout << "Name: " << this->getName() << "\t Id: " << this->id << endl;
}

class Manager : public Employee
{
private:
    float weekSalary;

public:
    Manager(string name, string id, float s = 0.0) : Employee(name, id)
    {
        this->weekSalary = s;
    }
    void setSalary(float s)
    {
        this->weekSalary = s;
    }
    float getSalary()
    {
        return this->weekSalary;
    }
    void print()
    {
        cout << "Manager: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

int main()
{
    Employee e("mi", "0001"), *pm;
    Manager m("wang", "0002", 220);
    m.print();
    pm = &m;
    pm->print();
    Employee &rm = m;
    rm.print();

    /*
        Manager: wang            Id: 0002                Money: 220
        Manager: wang            Id: 0002                Money: 220
        Manager: wang            Id: 0002                Money: 220
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
    void f()
    {
        cout << "A::f()" << endl;
    }
};

class B : public A
{
public:
    virtual void f()
    {
        cout << "B::f()" << endl;
    }
};

class C : public B
{
public:
    void f()
    {
        cout << "C::f()" << endl;
    }
};

class D : public C
{
public:
    void f()
    {
        cout << "D::f()" << endl;
    }
};

int main()
{
    A *pa, a;
    B *pb, b;
    C c;
    D d;
    pa = &a;
    pa->f();
    pb = &b;
    pb->f();
    pb = &c;
    pb->f();
    pb = &d;
    pb->f();

    /*
        A::f()
        B::f()
        C::f()
        D::f()
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
    virtual ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
private:
    char *buf;

public:
    B(int i)
    {
        this->buf = new char[i];
    }
    ~B()
    {
        delete[] this->buf;
        cout << "~B" << endl;
    }
};

int main()
{
    A *a = new B(10);
    delete a;

    /*
        ~B
        ~A
    */

    return 0;
}
```

---
