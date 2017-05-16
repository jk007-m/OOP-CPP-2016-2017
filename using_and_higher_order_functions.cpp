#include <iostream>

namespace my_namespace
{
    using namespace std;
    void func() { cout << "funk\n"; }
}

namespace second
{
    void func() { std::cout << "funk2\n"; }
}

/*void func()
{
    std::cout << "1\n";
}*/

//using namespace my_namespace;
//using namespace second;

namespace my_namespace
{
    void g(){std::cout << "g\n";}
    namespace inner
    {
        void print(){cout << "print\n";}
    }
}

int main()
{
    //second::func();
    //func();

    int x;
    using namespace my_namespace;
    using my_namespace::inner::print;
    print();
    func();
    return 0;
}
