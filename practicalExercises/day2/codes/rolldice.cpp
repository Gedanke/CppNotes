#include <iostream>
#include <cstdlib>

using namespace std;

int rolldice();

int main()
{
    int flag;
    unsigned seed;
    cout << "请输入一个数" << endl;
    cin >> seed;
    srand(seed);
    int sum = rolldice();
    int selfdim;
    switch (sum)
    {
    case 7:
    case 11:
        flag = 1;
        break;
    case 2:
    case 3:
    case 12:
        flag = 2;
        break;
    default:
        flag = 0;
        selfdim = sum;
        break;
    }
    while (flag == 0)
    {
        sum = rolldice();
        if (sum == selfdim)
        {
            flag = 1;
        }
        else if (sum == 7)
        {
            flag = 2;
        }
    }
    if (flag == 1)
    {
        cout << "player win\n";
    }
    else
    {
        cout << "player loses\n";
    }

    /*
        请输入一个数
        16
        sum = 1 + 4
        sum = 4 + 5
        sum = 4 + 6
        sum = 2 + 6
        sum = 4 + 1
        player win
    */

    return 0;
}

int rolldice()
{
    int sum = 0;
    int dim1 = rand() % 6 + 1;
    int dim2 = rand() % 6 + 1;
    sum = dim1 + dim2;
    cout << "sum = " << dim1 << " + " << dim2 << endl;
    return sum;
}