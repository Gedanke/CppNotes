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
