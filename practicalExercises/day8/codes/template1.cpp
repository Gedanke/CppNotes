#include <iostream>

using namespace std;

template <class T>
// 降序排列
void sort(T *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i; j < n; j++)
        {
            if (t[p] < t[j])
            {
                p = j;
            }
        }
        T tmp = t[i];
        t[i] = t[p];
        t[p] = tmp;
    }
}

template <class T>
void display(T &t, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {2, 3, 7, 1, 9, 4, 5, 8, 6};
    char b[] = {'a', 'c', 'g', 'f', 'b', 'd', 'e'};
    sort(a, 9);
    sort(b, 8);
    display(a, 9);
    display(b, 8);

    /*
        9 8 7 6 5 4 3 2 1
        g f e d c b a
    */

    return 0;
}
