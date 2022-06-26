#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};

class D
{
private:
    B b;
    A a;
    C c;

public:
    D()
    {
        cout << "D" << endl;
    }
    ~D()
    {
        cout << "~D" << endl;
    }
};

int main()
{
    D d;

    /*
        B
        A
        C
        D
        ~D
        ~C
        ~A
        ~B
    */

    return 0;
}
