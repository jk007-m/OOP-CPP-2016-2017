#include <iostream>
#include <exception>
#include <string>

class ExceptionWithID : public std::exception
{
private:
    std::string _id; ///int _id;
public:
    ExceptionWithID(/*int*/ std::string id = "0"/*0*/) : _id(id) {}
    const char* what() const noexcept
    {
        return ("Exception with ID = " + _id/*std::to_string(_id)*/ + " was thrown!\n").c_str();
    }
};

int main()
{
    try
    {
        throw ExceptionWithID("34"/*34*/);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
