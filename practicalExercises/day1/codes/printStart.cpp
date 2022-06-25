#include <iostream>

using namespace std;

void print_start()
{
    int i, j, k, f;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (k = 1; k <= 8 - 2 * i; k++)
            cout << " ";
        for (f = 1; f <= 2 * i; f++)
            cout << '*';
        cout << endl;
    }
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (f = 1; f <= 7 - 2 * i; f++)
            cout << '*';
        cout << endl;
    }
}

int main()
{
    print_start();
    
    /*
                                            **
                                  ****
                                ******
                              ********
                              *****
                              ***
                              *

    */
    
    return 0;
}