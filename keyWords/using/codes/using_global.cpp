#include <iostream>
#define isNs1 1
// #define isGlobal 2

using namespace std;

void func()
{
    cout << "::func" << endl;
}

namespace ns1
{
    void func()
    {
        cout << "ns1::func" << endl;
    }
}

namespace ns2
{
#ifdef isNs1
    using ns1::func;
#elif isGlobal
    using ::func;
#else
    void func()
    {
        cout << "other::func" << endl;
    }
#endif
}

int main()
{
    ns2::func();
    // ns1::func
    return 0;
}