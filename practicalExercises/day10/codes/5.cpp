#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char c[30] = "this is a string";
    double d = -1234.8976;
    cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << c << "----L2" << endl;
    // showbase 显示数值的基数前缀
    cout << dec << showbase << showpoint << setw(30) << d << "----L3" << endl;
    // showpoint 显示小数点
    cout << setw(30) << showpoint << setprecision(10) << d << "----L4" << endl;
    // setbase(8) 设置八进制
    cout << setw(30) << setbase(16) << 100 << "----L5" << endl;

    /*
        root@master:/home/root/codes/cplusplus/vscode/demo/test# g++ -o main main.cpp && ./main
        this is a string**************----L1
        **************this is a string----L2
        **********************-1234.90----L3
        ******************-1234.897600----L4
        **************************0x64----L5
     */

    return 0;
}
