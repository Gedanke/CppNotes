#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    int X;
    int Y;

public:
    Point(int x = 0, int y = 0)
    {
        this->X = x;
        this->Y = y;
    }
    int getX()
    {
        return this->X;
    }
    int getY()
    {
        return this->Y;
    }
    friend float distance(Point &a, Point &b);
    float distance_(Point &p);
};

float distance(Point &a, Point &b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

float Point::distance_(Point &p)
{
    double dx = this->X - p.getX();
    double dy = this->Y - p.getY();
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p1(3, 4);
    Point p2(0, 0);
    cout << distance(p1, p2) << endl;
    cout << p1.distance_(p2) << endl;
    // 5
    // 5
    return 0;
}
