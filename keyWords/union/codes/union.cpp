#include <iostream>

using namespace std;

// 默认 public，可以有构造函数，析构函数
union UnionTest
{
public:
    int i;
    UnionTest() : i(10)
    {
        cout << i << endl;
    }
    ~UnionTest()
    {
    }

private:
    void print(int i)
    {
        cout << i << endl;
    }
};

// 全局匿名联合必须为静态
static union
{
    int i;
    double d;
};

int main()
{
    UnionTest u;

    union
    {
        int i;
        double d;
    };

    cout << u.i << endl;

    // 全局匿名
    ::i = 20;
    cout << ::i << endl;

    // main 中匿名联合，可以直接访问
    i = 30;
    cout << i << endl;

    /*
        10
        10
        20
        30
    */

    return 0;
}