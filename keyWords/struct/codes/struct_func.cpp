#include <iostream>

using namespace std;

struct Base
{
    int v1;
    int v2;

public:
    int v3;
    void print()
    {
        cout << "Base" << endl;
    }
};

int main()
{
    struct Base base1;
    Base base2;
    Base base;
    base.v1 = 1;
    base.v3 = 3;
    base.print();
    cout << base.v1 << endl;
    cout << base.v3 << endl;
    // Base
    // 1
    // 3
}
