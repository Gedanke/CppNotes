#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a)
    {
        this->a = a;
        cout << "Virtual A" << endl;
    }
};

class B : virtual public A
{
public:
    B(int i) : A(i)
    {
        cout << "virtual B" << endl;
    }
};

class C : virtual public A
{
private:
    int x;

public:
    C(int i) : A(i)
    {
        this->x = i;
        cout << "C" << endl;
    }
};

class ABC : public C, public B
{
public:
    ABC(int i, int j, int k) : C(i), B(j), A(i)
    {
        cout << "ABC" << endl;
    }
};

int main()
{
    ABC abc(1, 2, 3);

    /*
        Virtual A
        C
        virtual B
        ABC
    */

    return 0;
}
