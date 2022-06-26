#include <iostream>

using namespace std;

/*
    基类中protected的成员
    类内部：可以访问
    类的使用者：不能访问
    类的派生类成员：可以访问
*/

class B
{
private:
    int i;

protected:
    int j;

public:
    int k;
};

class D : public B
{
public:
    void f()
    {
        // this->i=1;
        // 成员 "B::i" (已声明 所在行数:14) 不可访问
        this->j = 2;
        this->k = 3;
    }
};

int main()
{
    B b;
    // b.i=1;
    // 成员 "B::i" (已声明 所在行数:14) 不可访问
    // b.j=2;
    // 成员 "B::j" (已声明 所在行数:16) 不可访问
    b.k = 3;
    return 0;
}
