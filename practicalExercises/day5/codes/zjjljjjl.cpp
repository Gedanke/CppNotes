#include <iostream>

using namespace std;

// 当同时存在直接基类和间接基类时，每个派生类只负责其直接基类的构造

class A
{
private:
    int x;

public:
    A(int a)
    {
        this->x = a;
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
public:
    B(int x) : A(x)
    {
        cout << "B" << endl;
    }
};

class C : public B
{
public:
    C(int y) : B(y)
    {
        cout << "C" << endl;
    }
};

int main()
{
    C c(1);

    /*
        A
        B
        C
        ~A
    */

    return 0;
}
