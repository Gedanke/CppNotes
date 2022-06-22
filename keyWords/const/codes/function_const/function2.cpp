#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    int *const ptr = &num;
    int *p = &num;
    *p = 1;
    cout << *p << endl;

    const int num_ = 0;
    // int* const p_=&num_; // "const int *" 类型的值不能用于初始化 "int *const" 类型的实体

    const int num__ = 1;
    // int* const p__=&num__; // "const int *" 类型的值不能用于初始化 "int *const" 类型的实体
    const int *const p__ = &num__;
    cout << *p__ << endl;
    return 0;
}