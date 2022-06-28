#include <iostream>

using namespace std;

int main()
{
    char c;
    char a[40] = "this is a string...";
    cout << "use get() input char:" << endl;
    ;
    while ((c = cin.get()) != '\n')
    {
        cout.put(c);
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(a, 40).put('\n');
        cout << "look"
             << "\t here!" << endl;
    }

    /*
        use get() input char:
        a
        a
        this
        this is a string...
        look     here!
     */
    /*
        use get() input char:
        ab
        a
        this
        this is a string...
        look     here!
        b
        this
        this is a string...
        look     here!
    */

    return 0;
}
