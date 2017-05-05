#include <iostream>

using namespace std;

class Vector
{
public:
    int x;
    int y;
    int z;

public:
    Vector(int _x, int _y = 1, int _z = 1) : x(_x), y(_y), z(_z) {}
    Vector() = default;
};

int main()
{
    Vector* v = new Vector(2);
    cout << v->x << ' ' << v->y << ' ' << v->z << endl;
    Vector* v2 = new Vector(3, 25);
    cout << v2->x << ' ' << v2->y << ' ' << v2->z << endl;

    return 0;
}
