#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    A(int i = 0)
    {
        this->x = i;
        cout << "----A----" << endl;
    }
};

class B
{
private:
    int y;

public:
    B(int i)
    {
        this->y = i;
        cout << "----B----" << endl;
    }
};

class C
{
private:
    int z;

public:
    C(int i)
    {
        this->z = i;
        cout << "----C----" << endl;
    }
};

class D : public B
{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D() : a0(0), a4(4), c1(1), c2(2), B(1)
    {
        cout << "----D----" << endl;
    }
    ~D()
    {
        delete this->a1;
    }
};

int main()
{
    D d;

    /*
        ----B----
        ----C----
        ----C----
        ----A----
        ----A----
        ----A----
        ----D----
    */

    return 0;
}
