#include <iostream>

using namespace std;

class Base
{
public:
    inline virtual void who()
    {
        cout << "Base" << endl;
    }
    virtual ~Base()
    {
    }
};

class Derived : public Base
{
public:
    inline void who()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base b;
    b.who();

    Base *p = new Derived();
    p->who();

    delete p;

    // Base
    // Derived
    return 0;
}