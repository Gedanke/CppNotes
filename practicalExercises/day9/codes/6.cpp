#include <iostream>

using namespace std;

void errorHandler(int n) throw()
{
    try
    {
        if (n == 1)
        {
            throw n;
        }
        if (n == 2)
        {
            throw "dx";
        }
        if (n == 3)
        {
            throw 1.1;
        }
    }
    catch (...)
    {
        cout << "catch en exception" << endl;
    }
}

int main()
{
    errorHandler(1);
    errorHandler(2);
    errorHandler(3);

    /*
        catch en exception
        catch en exception
        catch en exception
    */

    return 0;
}
