#include <iostream>

using namespace std;

using ull = unsigned long long;
using matrix = int[10][10];

using int_ptr = int*;

template <int N>
using matrixN = int [N][N];

int main()
{
    ull x = 12345678901234567890;
    cout << x << endl;
    matrix m =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,5,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    matrixN<5> m2 =
    {
        {1,0,0,0,0},
        {1,2,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,1,0}
    };

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
            cout << m2[i][j];
        cout << endl;
    }

    /*int n;
    cin >> n;
    matrixN<n> c;*/
    int_ptr arr = new int[10];
    delete[] arr;

    return 0;
}
