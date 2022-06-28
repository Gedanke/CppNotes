#include <iostream>

using namespace std;

void temperature(int t)
{
    try
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
    catch (int x)
    {
        cout << "temperature=" << x << endl;
    }
    catch (char const *s)
    {
        cout << s << endl;
    }
}

int main()
{
    temperature(0);
    temperature(10);
    temperature(100);

    /*
        freezing point
        ok
        boiling point
    */

    return 0;
}
