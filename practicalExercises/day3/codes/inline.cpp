#include <iostream>

using namespace std;

inline double calArea(double r);

int main()
{
    double r = 3.0;
    double area;
    area = calArea(r);
    cout << area << endl;
    // 28.26
    return 0;
}

inline double calArea(double r)
{
    return 3.14 * r * r;
}