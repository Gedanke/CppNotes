#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    Base(int a)
    {
        this->x = a;
        cout << "Base x= " << this->x << endl;
    }
    ~Base()
    {
        cout << "~Base" << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int a, int b) : Base(a)
    {
        this->y = b;
        cout << "Derived y= " << this->y << endl;
    }
    ~Derived()
    {
        cout << "~Derived" << endl;
    }
};

int main()
{
    Derived d(1, 2);

    /*
        Base x= 1
        Derived y= 2
        ~Derived
        ~Base
    */

    return 0;
}
