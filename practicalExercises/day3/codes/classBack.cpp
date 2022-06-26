#include <iostream>

using namespace std;

class Fred;
// 前向引用声明

class Barney
{
    Fred x; // 错误：类 Fred 的声明尚不完善
};
class Fred
{
    Barney y;
};

// 第二种
class Fred; // 前向引用声明

class Barney
{
public:
    void method()
    {
        x->yabbaDabbaDo(); // 错误：Fred 类的对象在定义之前被使用
    }

private:
    Fred *x; // 正确，经过前向引用声明，可以声明 Fred 类的对象指针
};

class Fred
{
public:
    void yabbaDabbaDo();

private:
    Barney *y;
};

/*
    总结：当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。
*/

int main()
{
    return 0;
}