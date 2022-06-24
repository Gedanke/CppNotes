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