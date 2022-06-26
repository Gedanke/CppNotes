#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
};

class B1 : virtual public B, virtual public A
{
public:
    B1(int i)
    {
        cout << "B1" << endl;
    }
};

class B2 : virtual public A, virtual public B
{
public:
    B2(int j)
    {
        cout << "B2" << endl;
    }
};

class D : public B1, public B2
{
public:
    D(int m, int n) : B1(m), B2(n)
    {
        cout << "D" << endl;
    }
    A a;
};

int main()
{
    D d(1, 2);

    /*
        B
        A
        B1
        B2
        A
        D
    */

    return 0;
}
