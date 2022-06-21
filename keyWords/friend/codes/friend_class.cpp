#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int _a) : a(_a)
    {
    }
    friend class B;
};

class B
{
public:
    int getB(A ca)
    {
        return ca.a;
    }
};

int main()
{
    A a(3);
    B b;
    cout << b.getB(a) << endl;
    // 3
    return 0;
}