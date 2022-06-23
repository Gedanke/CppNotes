#include <iostream>
#include <stdio.h>

using namespace std;

struct Base
{
    int v1;
    int v3;

public:
    int v2;
    virtual void print()
    {
        cout << "Base" << endl;
    };
    Base()
    {
        cout << "Base construct" << endl;
    };
    virtual ~Base()
    {
        cout << "Base deconstruct" << endl;
    };
};

struct Derived : Base
{
    Derived()
    {
        cout << "Derived construct" << endl;
    };
    virtual ~Derived()
    {
        cout << "Derived deconstruct" << endl;
    };

public:
    int v2;
    void print()
    {
        cout << "Derived" << endl;
    };
};

int main()
{
    Base *b = new Derived();
    b->print();
    delete b;

    /*
        Base construct
        Derived construct
        Derived
        Derived deconstruct
        Base deconstruct
    */

    return 0;
}