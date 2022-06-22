#include <iostream>

using namespace std;

int main()
{
    const int a = 10;
    // a=11; 表达式必须是可修改的左值
    const string s = "const";
    // const int i; 常量 变量 "i" 需要初始值设定项
    const int j = 0;
    return 0;
}