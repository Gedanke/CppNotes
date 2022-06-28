#include <iostream>
#include <cstring>

using namespace std;

template <class T>

T Max(T a, T b)
{
    return (a > b) ? a : b;
}

template <>
char *Max<char *>(char *a, char *b)
{
    return (strcmp(a, b) >= 0) ? a : b;
}

int main()
{
    float c = 5.1, d = 3.2;
    cout << "2,3的最大值是：" << Max(3, 2) << endl;
    cout << "c,d的最大值是：" << Max(c, d) << endl;
    cout << Max("xbv", "xyce") << endl;

    /*
        2,3的最大值是：3
        c,d的最大值是：5.1
        xbv
    */

    return 0;
}
