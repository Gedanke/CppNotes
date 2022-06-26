#include <iostream>
#include <vector>

using namespace std;

const float PI = 3.14159;
const float FencePrice = 34;
const float ConcretePrice = 20;

class Circle
{
private:
    float radius;

public:
    Circle(float r);
    float Circumference() const;
    float Area() const;
};

Circle::Circle(float r)
{
    this->radius = r;
}

float Circle::Circumference() const
{
    return 2 * PI * this->radius;
}

float Circle::Area() const
{
    return PI * this->radius * this->radius;
}

int main()
{
    float r;
    float fenceCost, concreteCost;
    cin >> r;
    Circle pool(r);
    Circle poolRim(r + 3);
    fenceCost = poolRim.Circumference() * FencePrice;
    cout << fenceCost << endl;
    concreteCost = (poolRim.Area() - pool.Area()) * ConcretePrice;
    cout << concreteCost << endl;

    /*
        12
        3204.42
        5089.38
    */

    return 0;
}