#include <iostream>

using namespace std;

// 复数类 Complex，运算符重载实现加减乘除运算

class Complex
{
private:
    double r;
    double i;

public:
    Complex(double R = 0, double I = 0) : r(R), i(I){};
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
    void display();
};

Complex Complex::operator+(Complex c)
{
    return Complex(this->r + c.r, this->i + c.i);
}
Complex Complex::operator-(Complex c)
{
    return Complex(this->r - c.r, this->i - c.i);
}
Complex Complex::operator*(Complex c)
{
    Complex t;
    t.r = this->r * c.r - this->i * c.i;
    t.i = this->r * c.i + this->i * c.r;
    return i;
}
Complex Complex::operator/(Complex c)
{
    Complex t;
    double x;
    x = 1 / (c.r * c.r + c.i * c.i);
    t.r = x * (this->r * c.r + this->i * c.i);
    t.i = x * (this->i * c.r - this->r * c.i);
    return t;
}

void Complex::display()
{
    cout << this->r;
    if (this->i > 0)
    {
        cout << " + ";
    }
    if (this->i != 0)
    {
        cout << this->i << "i" << endl;
    }
}

int main()
{
    Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
    Complex a, b(2, 3);
    a = b + 2;

    // a = 2 + b; 没有与这些操作数匹配的 "+" 运算符C/C++(349)
    // main.cpp(65, 9): 操作数类型为: int + Complex
    /*
        a ? b
        a.operator?(b);    //类的非静态成员函数
        operator?(a, b);  //友元函数 和 普通函数
    */

    a.display();

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c6 = c1 / c2;

    c3.display();
    c4.display();
    c5.display();
    c6.display();

    /*
        4 + 3i
        4 + 6i
        -2-2i
        20.44 + 0.08i
    */

    return 0;
}
