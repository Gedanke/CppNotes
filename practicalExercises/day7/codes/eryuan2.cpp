#include <iostream>

/*
    在C++的标准命名空间 std 中预定义了复数类 Complex，
    并且通过友元重载了 Complex 的各种运算，包括本程序中重载的 +、-、*、/。
    若使用 using namespace std 将 std 名字空间引入本程序，
    则本程序中的 Complex 将与 std 名字空间中的 Complex 类的运算符重载函数产生冲突，引起编译错误。
*/

/*
    对于不要求左值且可以交换参数次序的运算符（如+、-、*、/ 等运算符），
    最好用非成员形式（包括友元和普通函数）的重载运算符函数实现。
*/

// 解决前面的 2 + b 问题。

class Complex
{
private:
    double r;
    double i;

public:
    Complex(double R = 0, double I = 0) : r(R), i(I){};
    friend Complex operator+(Complex a, Complex b);
    friend Complex operator-(Complex a, Complex b);
    friend Complex operator*(Complex a, Complex b);
    friend Complex operator/(Complex a, Complex b);

    friend Complex operator+(Complex a, double b)
    {
        return Complex(a.r + b, a.i);
    }
    friend Complex operator+(double a, Complex b)
    {
        return Complex(a + b.r, b.i);
    }

    void display();
};

Complex operator+(Complex a, Complex b)
{
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(Complex a, Complex b)
{
    return Complex(a.r - b.r, a.i - b.i);
}

Complex operator*(Complex a, Complex b)
{
    Complex t;
    t.r = a.r * b.r - a.i * b.i;
    t.i = a.i * b.i + a.i * b.i;
    return t;
}

Complex operator/(Complex a, Complex b)
{
    Complex t;
    double x;
    x = 1 / (b.r * b.r + b.i * b.i);
    t.r = x * (a.r * b.r + a.i * b.i);
    t.i = x * (a.i * b.r - a.r * b.i);
    return t;
}

void Complex::display()
{
    std::cout << this->r;
    if (this->i > 0)
    {
        std::cout << " + ";
    }
    if (this->i != 0)
    {
        std::cout << this->i << "i" << std::endl;
    }
}

int main()
{
    Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
    Complex b(2, 3);
    Complex a1 = b + 2;
    Complex a2 = 2 + b;
    a1.display();
    a2.display();

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c6 = c1 / c2;

    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
    c6.display();

    /*
        4 + 3i
        4 + 3i
        1 + 2i
        3 + 4i
        4 + 6i
        -2-2i
        -5 + 16i
        0.44 + 0.08i
    */

    return 0;
}
