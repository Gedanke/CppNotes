#include <iostream>

using namespace std;

class Apple
{
private:
    int i;

public:
    Apple()
    {
        this->i = 0;
        cout << "Inside Constructor" << endl;
    }
    ~Apple()
    {
        cout << "Inside Destructor" << endl;
    }
};

int main()
{
    int x = 0;
    if (x == 0)
    {
        Apple apple;
    }
    cout << "End of main" << endl;
    /*
        Inside Constructor
        Inside Destructor
        End of main
    */
    return 0;
}