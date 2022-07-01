#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, string> mp;
    map<string, string>::iterator iter;
    string key[3] = {"img", "system", "ip"};
    string value[3] = {"d:/a.img", "win10", "192.168.1.102"};

    // make_pair 插入
    for (int i = 0; i < 2; i++)
    {
        mp.insert(make_pair(key[i], value[i]));
    }

    // pair<const char*,const char*> 插入
    mp.insert(pair<const string, const string>(key[2], value[2]));

    // 数组插入方式
    mp["addr"] = "Cn";

    // 循环取出元素
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    string key1;
    cout << "input key to find value:" << endl;
    cin >> key1;

    // 查找元素
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (iter->first == key1)
        {
            cout << iter->first << ", successful! "
                 << "value: " << iter->second << endl;
        }
    }
    cout << "======" << endl;

    // 第一种删除方式
    // find 只能用于查找数组建立的形式！并且不支持输入用 cin 等
    iter = mp.find("addr");
    if (iter != mp.end())
    {
        cout << iter->first << ", successful! "
             << "value: " << iter->second << endl;
        cout << "delete it" << endl;
        mp.erase(iter);
    }
    // 循环取出元素
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    cout << "======" << endl;

    // 第二种方式删除
    // 按照 key 删除元素
    string drop_key;
    // 按照 value 删除元素
    string drop_value;

    cout << "input key:" << endl;
    cin >> drop_key;

    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (iter->first == drop_key)
        {
            cout << iter->first << ", successful! "
                 << "value: " << iter->second << endl;
            cout << "delete it" << endl;
            mp.erase(iter);
            break;
        }
    }

    cout << "input value:" << endl;
    cin >> drop_value;

    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        if (iter->second == drop_value)
        {
            cout << iter->second << ", successful! "
                 << "key: " << iter->first << endl;
            cout << "delete it" << endl;
            mp.erase(iter);
            break;
        }
    }
    cout << "======" << endl;

    cout << "after deleting" << endl;
    // 循环取出元素
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }

    /*
        addr    Cn
        img     d:/a.img
        ip      192.168.1.102
        system  win10
        input key to find value:
        ip
        ip, successful! value: 192.168.1.102
        ======
        addr, successful! value: Cn
        delete it
        img     d:/a.img
        ip      192.168.1.102
        system  win10
        ======
        input key:
        img
        img, successful! value: d:/a.img
        delete it
        input value:
        win11
        ======
        after deleting
        ip      192.168.1.102
        system  win10
    */

    return 0;
}
