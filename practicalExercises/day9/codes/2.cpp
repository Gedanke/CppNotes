#include <iostream>

using namespace std;

int main()
{
    cout << "1--before try block" << endl;
    try
    {
        cout << "2--inside try block" << endl;
        throw 10;
        cout << "3--after throw" << endl;
    }
    catch (double i)
    {
        cout << "4--catch double i" << endl;
    }
    cout << "5--after catch" << endl;

    /*
        1--before try block
        2--inside try block
        terminate called after throwing an instance of 'int'
        Aborted
    */

    return 0;
}
