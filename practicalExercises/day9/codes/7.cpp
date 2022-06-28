#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int i = 0) : a(i)
    {
        cout << "A constructor" << endl;
    }
    ~A()
    {
        cout << "A destructor" << endl;
    }
};

class B
{
private:
    A obj[3];
    double *pb[10];

public:
    B(int k)
    {
        cout << "B constructor" << endl;
        for (int i = 0; i < 10; i++)
        {
            this->pb[i] = new double[20000000];
            if (this->pb[i] == 0)
            {
                throw i;
            }
            else
            {
                cout << "Allocated 200000000 doubles in pb[" << i << "]" << endl;
            }
        }
    }
    ~B()
    {
        cout << "B destructor" << endl;
    }
};

int main()
{
    try
    {
        B b(2);
    }
    catch (int e)
    {
        cout << "catch an exception when allocated pb[" << e << "]" << endl;
    }

    /*
        A constructor
        A constructor
        A constructor
        B constructor
        Allocated 200000000 doubles in pb[0]
        Allocated 200000000 doubles in pb[1]
        Allocated 200000000 doubles in pb[2]
        Allocated 200000000 doubles in pb[3]
        Allocated 200000000 doubles in pb[4]
        Allocated 200000000 doubles in pb[5]
        Allocated 200000000 doubles in pb[6]
        Allocated 200000000 doubles in pb[7]
        Allocated 200000000 doubles in pb[8]
        Allocated 200000000 doubles in pb[9]
        B destructor
        A destructor
        A destructor
        A destructor
    */

    return 0;
}
