#include <iostream>

using namespace std;

class Base
{
public:
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived created" << endl;
    }
    Derived(const Derived &d)
    {
        cout << "Derived created by deep copy" << endl;
    }
    ~Derived()
    {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Derived d;
    Derived d1 = d;
    // Derived created
    // Derived created by deep copy
    // Derived destroyed
    // Derived destroyed
    return 0;
}