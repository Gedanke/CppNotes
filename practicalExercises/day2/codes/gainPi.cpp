#include <iostream>

using namespace std;

double arctan(double x);

int main()
{
    double a = 16.0 * arctan(1.0 / 5.0);
    double b = 4.0 * arctan(1.0 / 239.0);
    double pi = a - b;
    cout << pi << endl;
    // 3.14159
    return 0;
}

double arctan(double x)
{
    double res = 0.0;
    double head = x;
    int tail = 1;
    while (double(head / tail) > 1e-15)
    {
        res = (tail % 4 == 1) ? res + head / tail : res - head / tail;
        head *= x * x;
        tail += 2;
    }
    return res;
}