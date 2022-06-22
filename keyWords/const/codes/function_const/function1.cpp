#include <iostream>

using namespace std;

int main()
{
    const int *ptr;
    // *ptr=10; 表达式必须是可修改的左值

    const int p = 10;
    const void *vp = &p;
    auto ap = &p;
    // void *vp=&p; "const int *" 类型的值不能用于初始化 "void *" 类型的实体

    const int *c_ptr;
    int val = 3;
    c_ptr = &val; // ok
    int *ptr1 = &val;
    *ptr1 = 2;
    cout << ptr << " " << *ptr << endl;
    // 0x7fff60c6d5a0 1
    return 0;
}