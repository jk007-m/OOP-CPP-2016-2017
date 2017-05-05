#include <iostream>
#include <exception>
#include <string>

class ExceptionWithID : public std::exception
{
private:
    std::string _id; ///int _id;
public:
    ExceptionWithID(/*int*/ std::string id = "0"/*0*/) : _id(id) {}
    const char* what() const
    {
        //try{throw 12;}catch(int& e){}
        return ("Exception with ID = " +
                _id/*std::to_string(_id)*/ +
                " was thrown!\n")
                .c_str();
    } ///"Exception with ID = 0 was thrown!\n"
};

void bubbleSort(int* arr, const size_t& size) noexcept
{
    ...
}

void mergeSort(int* arr, const size_t& size)
{
    int* mem = new int[size/2];
    try
    {
        int* mem2 = new int[size/2];
    }
    catch(std::exception& e)
    {
        delete[] mem;
        throw std::bad_alloc;
    }

    ///...
}

void Sort(int* arr, const size_t& size) noexcept
{
    try
    {
        mergeSort(arr, size);
    }
    catch (std::exception& e)
    {
        bubbleSort(arr, size);
    }
}

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
