#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V1;
using V2 = vector<int>;

int main()
{
    int num1[] = {
        1, 2, 3, 4, 5, 6};
    V1 vec1(num1, num1 + sizeof(num1) / sizeof(int));
    int num2[] = {
        5, 7, 6};
    V2 vec2(num2, num2 + sizeof(num2) / sizeof(int));

    for (auto i : vec1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : vec2)
    {
        cout << i << " ";
    }
    cout << endl;
    // 1 2 3 4 5 6
    // 5 7 6
    return 0;
}