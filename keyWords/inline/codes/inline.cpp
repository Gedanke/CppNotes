#include <iostream>
#include "inline.h"

using namespace std;

int foo(int x, int y);

inline int foo(int x, int y)
{
    return x + y;
}

// 推荐该写法
inline void A::fun1(int x)
{
    cout << "inline: " << x << endl;
}

int main()
{
    cout << foo(1, 2) << endl;
    // 3
    A a;
    a.fun1(4);
    // inline: 4
    return 0;
}