#include <iostream>

using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    // d.fun(); "D::fun" 不明确
    return 0;
}
