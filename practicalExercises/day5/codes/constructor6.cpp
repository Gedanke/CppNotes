#include <iostream>

using namespace std;

class Point
{
protected:
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout << "point(" << this->x << "," << this->y << ")" << endl;
    }
};

class Line : public Point
{
protected:
    int len;

public:
    Line(int a, int b, int l) : Point(a, b)
    {
        this->len = l;
        cout << "Line" << endl;
    }
};

int main()
{
    Line l(1, 2, 3);

    /*
        point(1,2)
        Line
    */

    return 0;
}
