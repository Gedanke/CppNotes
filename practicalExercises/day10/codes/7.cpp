#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    ofstream out("./test.dat", ios::out | ios::binary);
    for (int i = 0; i < 90; i++)
    {
        if (i > 0 && (i % 30) == 0)
        {
            out.put('\n');
        }
        out.put(i);
        out.put(' ');
    }
    out.close();
    ifstream in("./test.dat", ios::in | ios::binary);
    while (in.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    in.close();

    /*




         1 2 3 4 5 6 7 8 9 : ;
        < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y
    */

    return 0;
}
