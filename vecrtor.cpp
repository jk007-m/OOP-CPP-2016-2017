#include <iostream>
#include <assert.h>
#include <fstream>

using namespace std;

template <typename T>
const T& min(const T& first, const T& second)
{
    return (first < second) ? first : second;
}

template <typename T>
class Vector
{
private:
    T* elements;
    size_t size;
    size_t maxSize;
    void copyMembers(const Vector<T>& other)
    {
        maxSize = other.maxSize;
        size = other.size;
        elements = new T[maxSize];
        for (int ind = 0; ind < size; ++ind)
            elements[ind] = other.elements[ind];
    }
    void resize(size_t _size)
    {
        T* newElements = new T[_size];
        /// Check for NULL
        size_t newSize = ::min(size, _size);
        for (size_t ind = 0; ind < newSize; ++ind)
            newElements[ind] = elements[ind];
        delete[] elements;
        elements = newElements;
        size = newSize;
        maxSize = _size;
    }

public:
    Vector(size_t _maxSize = 128, size_t _size = 0) : maxSize(_maxSize), size(_size)
    {
        elements = new T[_maxSize];
        /// Check for NULL
    }

    Vector(const Vector<T>& other)
    {
        copyMembers(other);
    }

    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this != &other)
        {
            delete[] elements;
            copyMembers(other);
        }
        return *this;
    }

    friend bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        if (lhs.size != rhs.size)
            return false;
        for (size_t ind = 0; ind < lhs.size; ++ind)
            if (lhs.elements[ind] != rhs.elements[ind])
                return false;
        return true;
    }

    friend bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        return !(lhs==rhs); /// Vector <int> a; ...; Vector<int> b; ...; a.operator==(b)
    }

    friend inline bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        return lhs.size < rhs.size;
    }

    friend inline bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        return rhs < lhs;
    }

    friend inline bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        return !(lhs < rhs);
    }

    friend inline bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
    {
        return !(lhs > rhs);
    }

    T& operator[](size_t ind) const
    {
        return elements[ind];
    }

    template <typename M>
    friend istream& operator>>(istream&, Vector<M>&);

    size_t getSize() const { return size; }

    size_t max_size() const { return maxSize; }

    bool empty() const { return (size == 0); }

    T last() const
    {
        return elements[size - 1];
    }

    T first() const
    {
        return (size != 0) ? elements[0] : T();
    }

    void clear()
    {
        delete[] elements;
        elements = nullptr;
        size = maxSize = 0;
    }

    void push_back(const T& elem)
    {
        if (size == maxSize) resize(maxSize * 2);
        elements[size] = elem;
        ++size;
    }

    void pop_back()
    {
        --size;
        elements[size] = T();
    }

    bool insert(const size_t& index, const T& value)
    {
        if (index > size)
            return false;
        this -> push_back(T());
        for (size_t ind = size - 1; ind >= index + 1; --ind)
        {
            elements[ind] = elements[ind - 1];
        }
        elements[index] = value;
        return true;
    }

    void erase(const size_t& index)
    {
        if (index >= size)
            return;
        for (size_t ind = index; ind < size; ++ind)
            elements[ind] = elements[ind + 1];
        --size;
    }

    ///template <typename M>
    ///friend ostream& operator<<(ostream&, const Vector<M>&);

    ~Vector()
    {
        delete[] elements;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& obj)
{
    os << "(" << obj.getSize() << ") :";
    for (int ind = 0; ind < obj.getSize(); ++ind)
        os << ' ' << obj[ind];
    return os;
}

template <typename T>
istream& operator>>(istream& is, Vector<T>& obj)
{
    size_t size, max_size;
    is >> size;

    obj.clear();
    obj.resize(size);

    T temp;
    for (size_t ind = 0; ind < size; ++ind)
    {
        is >> temp;
        obj.push_back(temp);
    }
    /// if(/*! T could not be constructed */ )
    ///     is.setstate(ios::failbit);
    return is;
}

//template <typename T>
//ostream& operator<<(ostream& os, const Vector<T>& obj)
//{
//    os << "(" << obj.size << ") :";
//    for (int ind = 0; ind < obj.size; ++ind)
//        os << ' ' << obj[ind];
//    return os;
//}

void test()
{
    Vector<int> input(20, 5);
    for (int i = 1; i <= 5; ++i)
    {
        input[i - 1] = 2 * i;
        cout << input[i - 1] << endl;
    }
    cout << input << endl;
    cout << input.last() << endl;
    assert(input.first() == 2);
    cout << input.first() << endl;
    ofstream fout("vector-test.txt", ios::app);
    fout << input << endl;
    cin >> input;
    cout << input << endl;
}

int main()
{
    test();
    return 0;
}
