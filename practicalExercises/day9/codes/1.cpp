#include <iostream>

using namespace std;

int main()
{
    cout << "1--before try block" << endl;
    try
    {
        cout << "2--inside try block" << endl;
        // throw 10;
        throw(char *) "s";
        cout << "3--after throw" << endl;
    }
    catch (int i)
    {
        cout << "4--catch int i" << endl;
    }
    catch (char *s)
    {
        cout << "5--catch char *s" << endl;
    }
    cout << "6--after catch" << endl;

    /*
        1--before try block
        2--inside try block
        4--catch int i
        6--after catch

        1--before try block
        2--inside try block
        5--catch char *s
        6--after catch
    */

    return 0;
}
