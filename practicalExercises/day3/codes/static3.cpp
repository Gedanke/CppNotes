#include <iostream>

using namespace std;

class Point
{
public:
    Point(Point &p);
    Point(int xx = 0, int yy = 0)
    {
        this->x = xx;
        this->y = yy;
        this->countP++;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    void getC()
    {
        cout << "Object id = " << this->countP << endl;
    }

private:
    int x;
    int y;
    static int countP;
};

int Point::countP = 0;

Point::Point(Point &p)
{
    this->x = p.x;
    this->y = p.y;
    this->countP++;
}

int main()
{
    Point A(3, 4);
    cout << "Point A: " << A.getX() << "," << A.getY() << endl;
    A.getC();
    Point B(A);
    cout << "Point B: " << B.getX() << "," << B.getY() << endl;
    B.getC();

    /*
        Point A: 3,4
        Object id = 1
        Point B: 3,4
        Object id = 2
    */

    return 0;
}