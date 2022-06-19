#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    virtual void fun() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Derived d;
    d.fun();
    // Derived fun
    return 0;
}