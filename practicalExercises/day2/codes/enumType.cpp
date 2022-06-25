#include <iostream>

using namespace std;

enum weekday
{
    s,
    m,
    t,
    w,
    thu,
    f,
    st
};

int main()
{
    enum weekday wek = s;
    for (int i = wek; i != st; i++)
    {
        cout << i << endl;
        cout << wek + s << endl;
        cout << "-------------------------" << endl;
    }

    /*
        0
        0
        -------------------------
        1
        0
        -------------------------
        2
        0
        -------------------------
        3
        0
        -------------------------
        4
        0
        -------------------------
        5
        0
        -------------------------
    */

    return 0;
}
