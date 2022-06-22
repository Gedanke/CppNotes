#include <iostream>

using namespace std;

struct A
{
    A(int)
    {
    }
    operator bool() const
    {
        return true;
    }
};

struct B
{
    explicit B(int)
    {
    }
    explicit operator bool() const
    {
        return true;
    }
};

void doA(A a)
{
}

void doB(B b)
{
}

int main()
{
    A a1(1);
    A a2 = 1;
    A a3{1};
    A a4 = {1};
    A a5 = (A)1;

    doA(1);

    if (a1)
    {
    }
    bool a6(a1);
    bool a7 = a1;
    bool a8 = static_cast<bool>(a1);

    B b1(1);
    // B b2=1; // 不存在从 "int" 转换到 "B" 的适当构造函数
    B b3{1};
    // B b4={1}; // 复制列表初始化不能使用标记为“显式”的构造函数
    B b5 = (B)1;
    if (b1)
    {
    }
    bool b6(b1);
    // bool b7=b1; // 不存在从 "B" 到 "bool" 的适当转换函数
    bool b8 = static_cast<bool>(b1);
    return 0;
}