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