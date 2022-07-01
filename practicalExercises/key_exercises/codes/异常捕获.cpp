#include <iostream>

using namespace std;

// 函数异常可以抛出去由主函数来处理
void fun(int x)
{
    try
    {
        if (x == 0)
        {
            throw "error";
        }
    }
    catch (...)
    {
        cout << "fun" << endl;
        throw 1;
    }
}

int main()
{
    try
    {
        fun(0);
    }
    catch (int n)
    {
        cout << "in main" << endl;
    }

    /*
        fun
        in main
     */

    return 0;
}