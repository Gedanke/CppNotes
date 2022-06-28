#include <iostream>

using namespace std;

int main()
{
    char stu[5][10];
    int i;
    for (i = 0; i < 5; i++)
    {
        cin.getline(stu[i], 10, ',');
    }
    cout << "cout" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << stu[i];
    }
    cout << endl;

    /*
        1
        2
        3
        4
        5
        cout
        1
        2
        3
        4
        5
    */

    return 0;
}
