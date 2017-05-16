#include <iostream>
#include <string>
#include <vector>

template <typename T>
T max(const T& x, const T& y) { return (x < y) ? y : x; }

template <typename T>
T findMaximum(T* arr, size_t size)
{
    T maximum = arr[0];
    for (int i = 1; i < size; ++i)
        maximum = max(maximum, arr[i]);
    return maximum;
}

template <typename T>
using comparator = T (*) (const T&, const T&);

template <typename T>
T getOptimum(T arr[], size_t size, comparator<T> optimumComparator)
{
    T optimum = arr[0];
    for (int i = 1; i < size; ++i)
        optimum = optimumComparator(optimum, arr[i]);
    return optimum;
}

template <typename T>
using boolPredicate = bool (*) (const T&);

template <typename T>
std::vector<T> filter(const std::vector<T>& arr, boolPredicate<T> predicate)
{
    std::vector<T> result;
    for (int i = 0; i < arr.size(); ++i)
        if (predicate(arr[i]))
            result.push_back(arr[i]);
    return result;
}

bool odd(const int& x) { return (x & 1); }

void test()
{
    std::vector<int> testVect;
    testVect.push_back(3);
    testVect.push_back(-1);
    testVect.push_back(2);
    testVect.push_back(4);
    std::vector<int> result = filter<int>(testVect, odd);
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << ' ';
    std::cout << "\n";
}

int main()
{
    ///comparator<double> doubleComparator = max<double>;
    double arr[] = {1.32, 3, -2.23, 54.15, 21};
    std::cout << getOptimum<double>(arr, 5, max<double>) << std::endl;
    test();
    return 0;
}
