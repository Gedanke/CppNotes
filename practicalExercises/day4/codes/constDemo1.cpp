#include <iostream>

using namespace std;

void display(const double &r);

class A
{
public:
    A(int i, int j)
    {
        this->x = i;
        this->y = j;
    }
    void show()
    {
        cout << this->x << " " << this->y << endl;
    }

private:
    int x;
    int y;
};

int main()
{
    double d = 9.5;
    display(d);
    A const a(3, 4);
    // a.show();
    // 对象含有与成员 函数 "A::show" 不兼容的类型限定符C/C++(1086)
    // main.cpp(25, 5): 对象类型是: const A
    A aa(3, 4);
    aa.show();
    // 9.5
    // 3 4
    return 0;
}

void display(const double &r)
{
    cout << r << endl;
}
