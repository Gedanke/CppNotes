#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Apple
{
private:
    vector<int> people;

public:
    const int apple_num;
    Apple(int i);
    void take(int num) const;
    void add(int num);
    void add(int num) const;
    int getCount() const;
};