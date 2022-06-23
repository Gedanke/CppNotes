#include <iostream>

using namespace std;

struct Base
{
    int v1;
    int v3;

public:
    int v2;
    void print()
    {
        cout << "Base" << endl;
    }
};

typedef struct Base1
{
    int v1;
    int v3;

public:
    int v2;
    void print()
    {
        cout << "Base1" << endl;
    }
} B;

void Base()
{
    cout << "void Base" << endl;
}

int main()
{
    struct Base base;
    base.v1 = 1;
    base.v3 = 3;
    base.print();
    cout << base.v1 << endl;
    cout << base.v3 << endl;
    Base();
    // Base
    // 1
    // 3
    // void Base
}
