#include <iostream>

using namespace std;

void fun(const int i)
{
    // i=10; 表达式必须是可修改的左值
    cout << i << endl;
}

int main()
{
    fun(1);
    return 0;
}