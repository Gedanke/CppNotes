#include <iostream>

using namespace std;

class A
{
public:
    virtual ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
private:
    char *buf;

public:
    B(int i)
    {
        this->buf = new char[i];
    }
    ~B()
    {
        delete[] this->buf;
        cout << "~B" << endl;
    }
};

int main()
{
    A *a = new B(10);
    delete a;

    /*
        ~B
        ~A
    */

    return 0;
}
