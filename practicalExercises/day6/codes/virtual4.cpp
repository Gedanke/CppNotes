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
