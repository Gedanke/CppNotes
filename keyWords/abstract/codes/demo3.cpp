#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
private:
    int x;

public:
    virtual void show() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
};

int main()
{
    // Derived d;
    // 不允许使用抽象类类型 "Derived" 的对象: -- 纯虚拟 函数 "Base::show" 没有强制替代项
    return 0;
}