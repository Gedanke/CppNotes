#include <iostream>

using namespace std;

// C++ 中的纯虚函数(或抽象函数)是我们没有实现的虚函数！我们只需声明它!通过声明中赋值 0 来声明纯虚函数
// 纯虚函数：没有函数体的虚函数

class Test
{
private:
    int a;

public:
    virtual void show() = 0;
};

int main()
{
    // Test test;
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    Test *ptr;

    // Test *t=new Test();
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    return 0;
}
