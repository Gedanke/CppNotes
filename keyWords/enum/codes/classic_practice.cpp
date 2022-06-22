#include <iostream>

using namespace std;

namespace Color
{
    enum Type
    {
        RED = 15,
        YELLOW,
        BLUE
    };
};

struct Color1
{
    enum Type
    {
        RED = 102,
        YELLOW,
        BLUE,
    };
};

enum class Color2
{
    RED = 2,
    YELLOW,
    BLUE
};

enum class Color3 : char;

enum class Color3 : char
{
    RED = 'r',
    BLUE
};

int main()
{
    Color::Type c = Color::RED;
    cout << c << endl;

    Color1 c1;
    cout << c1.RED << endl;

    Color1::Type c11 = Color1::BLUE;
    cout << c11 << endl;

    Color2 c2 = Color2::RED;
    cout << static_cast<int>(c2) << endl;

    char c3 = static_cast<char>(Color3::RED);
    cout << c3 << endl;
    /*
        15
        102
        104
        2
        r
    */
    return 0;
}