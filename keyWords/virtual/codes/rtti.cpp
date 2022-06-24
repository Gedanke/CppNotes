#include <iostream>
#include <typeinfo>

using namespace std;

class B
{
private:
    virtual void fun()
    {
    }
};

class D : public B
{
};

int main()
{
    B *b = new D; // 向上转型
    B &obj = *b;
    D *d = dynamic_cast<D *>(b); // 向下转型
    if (d != NULL)
        cout << "works" << endl;
    else
        cout << "cannot cast B* to D*";

    try
    {
        D &dobj = dynamic_cast<D &>(obj);
        cout << "works" << endl;
    }
    catch (bad_cast bc)
    { // ERROR
        cout << bc.what() << endl;
    }
    // works
    // works
    return 0;
}