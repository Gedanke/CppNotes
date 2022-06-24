#include <iostream>

using namespace std;

class Base
{
public:
    virtual void fun()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    void fun()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base b;
    b.fun();

    Base *p = new Derived();
    p->fun();
    // Base
    // Derived
    return 0;
}