#include <iostream>

using namespace std;

void test(int *p)
{
    *p = 3;
}

void test2(int &p)
{
    p = 4;
}

int main()
{
    int a = 10;
    int *p = &a;
    test(p);
    cout << a << endl;
    // 3
    test2(a);
    cout << a << endl;
    // 4
    return 0;
}