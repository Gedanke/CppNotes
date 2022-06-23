#include <iostream>

using namespace std;

class Apple
{
public:
    static void msg()
    {
        cout << "Welcome to Apple" << endl;
    }
};

int main()
{
    Apple::msg();
    // Welcome to Apple
    return 0;
}