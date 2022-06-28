#include <iostream>

using namespace std;

// 内部再次throw异常时，函数不要带throw()

void errorHandler(int n)
{
    try
    {
        if (n == 1)
        {
            throw n;
        }
        cout << "ok" << endl;
    }
    catch (int e)
    {
        cout << "catch an exception in function\t" << e << endl;
        throw e;
    }
}

int main()
{
    try
    {
        errorHandler(1);
    }
    catch (int x)
    {
        cout << "catch an exception in main" << endl;
    }
    cout << "end" << endl;

    /*
        catch an exception in function  1
        catch an exception in main
        end
    */

    return 0;
}
