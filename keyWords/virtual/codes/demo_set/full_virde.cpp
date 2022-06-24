#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base" << endl;
    }
    virtual ~Base()
    {
        cout << "Destructing Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructing Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructing Derived" << endl;
    }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    // Constructing Base
    // Constructing Derived
    // Destructing Derived
    // Destructing Base
    return 0;
}