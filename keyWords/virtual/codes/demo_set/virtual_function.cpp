#include <iostream>

using namespace std;

class Base
{
private:
    virtual void fun()
    {
        cout << "Base fun" << endl;
    }
    friend int main();
};

class Derived : public Base
{
public:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Base *p = new Derived();
    p->fun();
    return 0;
}