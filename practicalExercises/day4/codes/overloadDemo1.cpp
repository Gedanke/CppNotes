#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void operator()(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void showTime()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

int main()
{
    Time t(12, 13, 14);
    t.showTime();
    t.operator()(22, 23, 24);
    t.showTime();
    t(23, 23, 23);
    t.showTime();

    /*
        12:13:14
        22:23:24
        23:23:23
    */

    return 0;
}
