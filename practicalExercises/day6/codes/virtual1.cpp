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
