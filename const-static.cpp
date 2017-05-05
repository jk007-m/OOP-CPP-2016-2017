#include <iostream>

using namespace std;

class Counter
{
private:
    static unsigned int counter;
public:
    void increase() const { ++counter; }
    unsigned  int get() const { return counter; }
};

unsigned int Counter::counter = 0;

int main()
{
    Counter c;
    cout << c.get() << endl;
    c.increase();
    cout << c.get() << endl;
    c.increase();
    cout << c.get() << endl;
    c.increase();
    cout << c.get() << endl;


    return 0;
}
