#include <iostream>

using namespace std;

class BasicException
{
public:
    string where()
    {
        return "Basic Exception";
    }
};

class FileSysException : public BasicException
{
public:
    string where()
    {
        return "FileSysException";
    }
};

class FileNotFind : public FileSysException
{
public:
    string where()
    {
        return "FileNotFind";
    }
};

class DiskNotFind : public FileSysException
{
public:
    string where()
    {
        return "DiskNotFind";
    }
};

int main()
{
    try
    {
        throw FileSysException();
    }
    catch (DiskNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.where() << endl;
    }
    catch (BasicException p)
    {
        cout << p.where() << endl;
    }
    try
    {
        throw DiskNotFind();
    }
    catch (BasicException p)
    {
        cout << p.where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.where() << endl;
    }
    catch (DiskNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileNotFind p)
    {
        cout << p.where() << endl;
    }

    /*
        FileSysException
        Basic Exception
    */

    return 0;
}
