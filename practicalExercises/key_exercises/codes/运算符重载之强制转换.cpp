#include <iostream>

using namespace std;

/*
    有一个类 Circle，设计该类的类型转换函数，当将 Circle 对象转换成 int 型时，返回圆的半径；当将它转换成 double 型时，就返回圆的周长；当将它转换成 float 型时，就返回圆的面积。
*/

/*
    类型转换函数没有参数。
    类型转换函数没有返回类型。
    类型转换函数必须返回将要转换成的 type 类型数据。
*/

class Circle
{
private:
    double x, y, r;

public:
    Circle(double x, double y, double r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    operator int()
    {
        return int(this->r);
    }
    operator double()
    {
        return (double)2 * 3.14 * this->r;
    }
    operator float()
    {
        return (float)3.14 * this->r * this->r;
    }
};

int main()
{
    Circle c(2.3, 3.4, 4.5);
    int r = c;
    double l = c;
    float s = c;
    double len = (double)c;

    cout << r << endl;
    cout << l << endl;
    cout << s << endl;
    cout << len << endl;

    /*
        4
        28.26
        63.585
        28.26
    */

    return 0;
}
