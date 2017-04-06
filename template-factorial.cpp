#include <iostream>

using namespace std;

template <int N>
struct Factorial
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0>
{
    enum { value = 1 };
};

void print()
{
    int x = Factorial<4>::value; /// == 24
    int y = Factorial<0>::value; /// == 1
    int z = Factorial<12>::value; /// == 479001600
    cout << x << endl << y << endl << z << endl;
}

int main()
{
    print();
	return 0;
}
