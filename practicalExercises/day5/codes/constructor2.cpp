#include <iostream>

using namespace std;

/*
    先构造成员
    再构造自身（调用构造函数）
*/

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
    B b;
    A a;
};

int main()
{
    C c;

    /*
        B
        A
        C
        ~C
        ~A
        ~B
    */

    return 0;
}
