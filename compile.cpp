#include <iostream>
#include <exception>
using namespace std;

void fail(int a = 0)
{
    ///int x[10];
    try
    {
        ///x[15] = 3;
        if (a != 0)
            throw a;
    }
    catch(...)
    {
        throw;
    }
}

int main ()
{
    try
    {
        fail(5);
    }
    catch(int& e)
    {
        cout << "Ex: " << e << endl;
    }
    catch(...)
    {
        cout << "Ex occured.\n";
    }
    return 0;
}
