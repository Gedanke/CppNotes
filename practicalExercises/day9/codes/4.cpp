#include <iostream>

using namespace std;

void temperature(int t)
{
    if (t == 100)
    {
        throw "boiling point";
    }
    else if (t == 0)
    {
        throw "freezing point";
    }
    else
    {
        cout << "ok" << endl;
    }
}

int main()
{
    try
    {
        temperature(0);
        // temperature(10);
        // temperature(100);
    }
    catch (char const *s)
    {
        cout << s << endl;
    }

    /*
        freezing point
        ok
        boiling point
    */

    return 0;
}
