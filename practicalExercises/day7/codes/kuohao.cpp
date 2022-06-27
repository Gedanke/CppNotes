#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h, int m, int s)
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
    void show()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

int main()
{
    Time t(12, 12, 12);
    t.show();
    t.operator()(13, 13, 13);
    t.show();
    t(14, 14, 14);
    t.show();

    /*
        12:12:12
        13:13:13
        14:14:14
    */

    return 0;
}
