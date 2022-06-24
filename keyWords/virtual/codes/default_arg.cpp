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