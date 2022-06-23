#include <iostream>

using namespace std;

class A
{
private:
    virtual void fun();
    virtual void fun1();
    virtual void fun2();
    virtual void fun3();
};

class B
{
public:
    char b;
    static int c;
    static int d;
    static int f;
    virtual void fun(){

    };
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 16
    return 0;
}