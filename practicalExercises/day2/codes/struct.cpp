#include <iostream>

using namespace std;

struct Student
{
    int num;
    char name[20];
    char gender;
};

int main()
{
    Student s = {
        18, "Jay", 'M'};
    cout << s.num << endl;
    cout << sizeof(s.num) << endl;
    cout << sizeof(s.name) << endl;
    cout << sizeof(s.gender) << endl;
    cout << sizeof(s) << endl;

    /*
        18
        4
        20
        1
        28
    */

    return 0;
}
