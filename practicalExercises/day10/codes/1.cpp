#include <iostream>

using namespace std;

int main()
{
    //用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
    char a[50];
    cout << "input a string" << endl;
    cin >> a;
    cout << a << endl;

    /*
        input a string
        qwer
        qwer
    */

    return 0;
}
