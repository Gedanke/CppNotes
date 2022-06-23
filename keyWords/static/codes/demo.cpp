#include <iostream>

using namespace std;

void demo()
{
    static int count = 0;
    cout << count << " ";
    count++;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        demo();
    }
    cout << endl;
    // 0 1 2 3 4
    return 0;
}