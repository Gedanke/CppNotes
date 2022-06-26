#include <iostream>

using namespace std;

class R
{
public:
    R(int r1, int r2)
    {
        this->R1 = r1;
        this->R2 = r2;
    }
    void print();
    void print() const;

private:
    int R1;
    int R2;
};

/*
    常成员函数说明格式：类型说明符  函数名（参数表）const;
    这里，const是函数类型的一个组成部分，因此在实现部分也要带const关键字。
    const关键字可以被用于参与对重载函数的区分
    通过常对象只能调用它的常成员函数
*/

void R::print()
{
    cout << "普通调用" << endl;
    cout << this->R1 << ":" << this->R2 << endl;
}

void R::print() const
{
    cout << "常对象调用" << endl;
    cout << this->R1 << ":" << this->R2 << endl;
}

int main()
{
    R a(3, 4);
    a.print();
    const R b(6, 8);
    b.print();

    /*
        普通调用
        3:4
        常对象调用
        6:8
    */

    return 0;
}
