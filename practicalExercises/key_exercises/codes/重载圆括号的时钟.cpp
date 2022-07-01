#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0) : h(h), m(m), s(s)
    {
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
    Time t(12, 12, 12);
    t.showTime();
    t.operator()(13, 14, 15);
    t.showTime();
    t(20, 20, 20);
    t.showTime();

    /*
        12:12:12
        13:14:15
        20:20:20
    */

    return 0;
}
