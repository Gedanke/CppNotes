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
    friend int getA(A &ca); // 友元函数
    friend int getAA(A &ca)
    {
        return ca.a;
    }
};

int getA(A &ca)
{
    return ca.a;
}

int main()
{
    A a(3);
    cout << getA(a) << endl;
    // cout<<a.getAA()<<endl; // 类 "A" 没有成员 "getAA"
    cout << getAA(a) << endl;
    // 3
    // 3
    return 0;
}