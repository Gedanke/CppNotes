#include <iostream>
#define throw(...)
using namespace std;

void handler(int n) throw(int, char, double)
{
    if (n == 1)
    {
        throw n;
    }
    if (n == 2)
    {
        throw 'x';
    }
    if (n == 3)
    {
        throw 1.1;
    }
}

int main()
{
    cout << "before handler" << endl;
    try
    {
        handler(1);
    }
    catch (int i)
    {
        cout << "catch an integer.." << endl;
    }
    catch (char c)
    {
        cout << "catch a char" << endl;
    }
    catch (double d)
    {
        cout << "catch a double" << endl;
    }

    /*
        before handler
        catch an integer..
    */

    return 0;
}
