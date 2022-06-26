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

class B : public A
{
public:
    ~B()
    {
        cout << "~B" << endl;
    }
};

int main()
{
    B b;

    /*
        A
        ~B
        ~A
    */

    return 0;
}
