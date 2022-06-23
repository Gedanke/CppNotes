#include <iostream>

using namespace std;

#define exp(s) printf("test s is:%s\n", s)
#define exp1(s) printf("test s is:%s\n", #s)
#define exp2(s) #s

int main()
{
    exp("hello");
    exp1(hello);

    string str = exp2(bac);
    cout << str << " " << str.size() << endl;

    /*
        忽略传入参数名前面和后面的空格。
    */

    string str1 = exp2(asda bac);

    /*
        当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
        用每个子字符串之间以一个空格连接，忽略剩余空格。
    */

    cout << str1 << " " << str1.size() << endl;

    return 0;
}