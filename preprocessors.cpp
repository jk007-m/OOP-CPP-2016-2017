#include <iostream>
using namespace std;
//#define ARR_SIZE 100
#define getmax(a,b) ((a>b)?(a):(b))
#define print_each(start,end) for(int ind = start; ind < end; ++ind){cout << ind << endl;}

#define toString(x) #x
#define merge(x, y) x##y

int getMax(int a, int b) { return (a > b) ? a : b; }



int main()
{
    //#ifndef ARR_SIZE
    //#define ARR_SIZE 200
    //#endif

    #line 20 "assignment of x"
//20
//21
//22
    cout << __cplusplus << endl;
    int x = 7;

    //#line 1 "file"
    #if defined ARR_SIZE
    #define ARR_SIZE 400
    #endif // defined

    #if !defined ARR_SIZE
    #define ARR_SIZE 10
    #endif

    int arr[ARR_SIZE];
    //#define ARR_SIZE 350
    #if ARR_SIZE > 200
        cout << "ARR_SIZE > 200: " << ARR_SIZE << endl;
    #elif ARR_SIZE < 50
        cout << "ARR_SIZE < 50: " << ARR_SIZE << endl;
    #else
        cout << "50 <= ARR_SIZE <= 200: " << ARR_SIZE << endl;
    #endif // ARR_SIZE


    ///cout << getmax(-48, -45.123) << endl;
    ///print_each(0, 10);
    cout << "output" << endl;
    return 0;
}

/**
#include <iostream>
#define N 123
#define ll long long
using namespace std;
void maiN()
{
    cout << N << endl;
    #undef N
    #define N 15
    cout << N << endl;
}
int main()
{
    ll x = 5;
    cout << x << endl;
    cout << N << endl;
    #undef N
    #define N 34
    maiN();
    cout << N << endl;
    return 0;
}

*/
