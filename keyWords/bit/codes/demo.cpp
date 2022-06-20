#include <iostream>

using namespace std;

struct Box
{
    unsigned int ready : 2;
    unsigned int error : 2;
    unsigned int command : 4;
    unsigned int sector_no : 24;
};

void printMsg(struct Box b)
{
    cout << b.ready << " " << b.error << " " << b.command << " " << b.sector_no << endl;
}

union UBox
{
    struct Box st_box;
    long long int ui_box;
};

int main()
{
    struct Box b = {1, 2, 3, 4};
    printMsg(b);
    cout << sizeof(b) << endl;
    int *p = (int *)&b; // 将 "位域结构体的地址" 映射至 "整形(int*)的地址"
    *p = 0;             // 清除 s1，将各成员归零
    printMsg(b);
    cout << sizeof(b) << endl;

    cout << "------" << endl;

    union UBox u;
    u.ui_box = 0;

    cout << sizeof(u) << endl;
    cout << sizeof(u.st_box) << endl;
    cout << sizeof(u.ui_box) << endl;

    /*
        1 2 3 4
        4
        0 0 0 0
        4
        ------
        8
        4
        8
    */

    return 0;
}
