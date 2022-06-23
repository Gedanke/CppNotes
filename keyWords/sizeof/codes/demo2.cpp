#include <iostream>

using namespace std;

class A
{
public:
    char a;
    int b;
};

class B : A
{
public:
    short a;
    long b;
};

class C
{
private:
    A a;
    char c;
};

class A1
{
    virtual void fun()
    {
    }
};

class C1 : public A
{
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 24
    cout << sizeof(C) << endl;
    // 12
    cout << sizeof(A1) << endl;
    // 8
    cout << sizeof(C1) << endl;
    // 8
    return 0;
}