#include <iostream>

using namespace std;

int i = 10; // i 全局变量，静态生存期

int main()
{
    static int a;
    // 静态局部变量，有全局寿命，局部可见
    int b = -10;
    // b, c为局部变量，具有动态生存期
    int c = 0;
    void fun();
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    c = c + 8;
    fun();
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    i = i + 10;
    fun();
    fun();

    /*
        ---MAIN---
        i: 10 a: 0 b: -10 c: 0
        ---OTHER---
        i: 42 a: 4 b: 0 c: 15
        ---MAIN---
        i: 42 a: 0 b: -10 c: 8
        ---OTHER---
        i: 84 a: 6 b: 4 c: 15
        ---OTHER---
        i: 116 a: 8 b: 6 c: 15
    */

    return 0;
}

void fun()
{
    static int a = 2;
    static int b;
    // a,b 为静态局部变量，具有全局寿命，局部可见。
    // 只第一次进入函数时被初始化。
    int c = 10;
    // c 为局部变量，具有动态生存期
    a = a + 2;
    i = i + 32;
    c = c + 5;
    cout << "---OTHER---" << endl;
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    b = a;
}