#include <iostream>
#include <cstring>

using namespace std;

const int Size = 5;
template <class T>
class Array
{
private:
    T a[Size];

public:
    Array()
    {
        for (int i = 0; i < Size; i++)
        {
            this->a[i] = 0;
        }
    }
    T &operator[](int i);
    void Sort();
};

template <class T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i > Size - 1)
    {
        cout << "\n error" << endl;
        exit(1);
    }
    return this->a[i];
}

template <class T>
void Array<T>::Sort()
{
    int p;
    for (int i = 0; i < Size - 1; i++)
    {
        p = i;
        for (int j = i; j < Size; j++)
        {
            if (this->a[p] < this->a[j])
            {
                p = j;
            }
        }
        T t = this->a[p];
        this->a[p] = a[i];
        this->a[i] = t;
    }
}

template <>
void Array<char *>::Sort()
{
    int p;
    for (int i = 0; i < Size - 1; i++)
    {
        p = i;
        for (int j = i; j < Size; j++)
        {
            if (strcmp(this->a[p], this->a[j]) < 0)
            {
                p = j;
            }
        }
        char *t = this->a[p];
        this->a[p] = a[i];
        this->a[i] = t;
    }
}

int main()
{
    Array<int> a1;
    Array<char *> b1;
    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 6;
    a1[3] = 3;
    a1[4] = 9;
    a1.Sort();
    for (int i = 0; i < 5; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
    b1[0] = (char *)"x1";
    b1[1] = (char *)"ya";
    b1[2] = (char *)"ad";
    b1[3] = (char *)"be";
    b1[4] = (char *)"bc";
    b1.Sort();
    for (int i = 0; i < 5; i++)
    {
        cout << b1[i] << "\t";
    }
    cout << endl;

    /*
        23      9       6       3       1
        ya      x1      be      bc      ad
     */

    return 0;
}
