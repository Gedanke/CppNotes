#include <iostream>

using namespace std;

class A
{
public:
    virtual void f()
    {
        cout << "Base A::fun()" << endl;
    }
};

class B : public A
{
public:
    virtual void f()
    {
        cout << "Derived B::fun()" << endl;
    }
};

int main()
{
    A a;
    B b;

    A *pa = &a;
    pa->f();

    pa = &b;
    pa->f();
    //  Base A::fun()
    // Derived B::fun()
    return 0;
}