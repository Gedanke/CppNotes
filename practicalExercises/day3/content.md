# Day3

---

前向引用声明：

```cpp
#include <iostream>

using namespace std;

class Fred;
// 前向引用声明

class Barney
{
    Fred x; // 错误：类 Fred 的声明尚不完善
};
class Fred
{
    Barney y;
};

// 第二种
class Fred; // 前向引用声明

class Barney
{
public:
    void method()
    {
        x->yabbaDabbaDo(); // 错误：Fred 类的对象在定义之前被使用
    }

private:
    Fred *x; // 正确，经过前向引用声明，可以声明 Fred 类的对象指针
};

class Fred
{
public:
    void yabbaDabbaDo();

private:
    Barney *y;
};

/*
    总结：当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。
*/

int main()
{
    return 0;
}
```

类：

```cpp
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
```

inline：

```cpp
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
```

static：

```cpp
#include <iostream>

using namespace std;

class Application
{
public:
    static void f();
    static void g();

private:
    static int global;
};

int Application::global = 0;

void Application::f()
{
    global = 5;
}

void Application::g()
{
    cout << global << endl;
}

int main()
{
    Application::f();
    Application::g();
    // 5
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        this->x = 0;
    }
    static void f(A a);

private:
    int x;
};

void A::f(A a)
{
    cout << a.x << endl;
}

int main()
{
    A a;
    a.f(a);
    // 0
    return 0;
}
```

```cpp
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
```

swap：

```cpp
#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main()
{
    int x1 = 5;
    int x2 = 7;
    cout << x1 << " " << x2 << endl;
    // 7 5
    swap(x1, x2);
    cout << x1 << " " << x2 << endl;
    // 7 5
    return 0;
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
```

---
