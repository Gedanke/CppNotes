#include <iostream>

using namespace std;

class A
{
private:
    virtual void fun()
    {
    }
};

class B
{
private:
    virtual void fun2()
    {
    }
};

class C : virtual public A, virtual public B
{
public:
    virtual void fun3()
    {
    }
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 8
    cout << sizeof(C) << endl;
    // 16
    return 0;
}