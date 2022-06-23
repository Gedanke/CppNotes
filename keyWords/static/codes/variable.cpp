#include <iostream>

using namespace std;

class Apple
{
public:
    static int i;
    Apple()
    {
    }
};

int Apple::i = 0;

int main()
{
    Apple appple;
    cout << appple.i << endl;
    /*
        0
    */
    return 0;
}