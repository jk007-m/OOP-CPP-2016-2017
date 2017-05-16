#include <iostream>

using namespace std;

class CastableFromInt
{
public:
    int size;
    CastableFromInt(int _size = 0) : size(_size) {}
    CastableFromInt& operator= (const int& x)
    {
        size = x;
        return *this;
    }
    operator int() { return size; }
};

int main()
{
    CastableFromInt x;
    cout << x.size << endl;
    x = 5;
    cout << x.size << endl;


    return 0;
}
