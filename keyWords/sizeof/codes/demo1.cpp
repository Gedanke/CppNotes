#include <iostream>

using namespace std;

class A
{
};

class B
{
public:
    B();
    ~B();
    static int a;
    static void fun3();
    void fun();
    void fun1();
};

int main()
{
    cout << sizeof(A) << endl;
    // 1
    cout << sizeof(B) << endl;
    // 1
    return 0;
}
