#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T compareMax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

template <>
const char *compareMax<const char *>(const char *s1, const char *s2)
{
    cout << "[for debug]"
         << " call compareMax template" << endl;
    return strcmp(s1, s2) >= 0 ? s1 : s2;
}

int main()
{
    cout << compareMax(1, 2) << endl;
    cout << compareMax("asda", "qweq") << endl;

    /*
        2
        [for debug] call compareMax template
        qweq
     */

    return 0;
}
