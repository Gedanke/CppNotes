#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Test
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

int main()
{
    // Test t;
    // 不允许使用抽象类类型 "Test" 的对象: -- 函数 "Test::show" 是纯虚拟函数
    return 0;
}