#include <iostream>

using namespace std;

class Math
{
public:
    static const float PI;

    template<typename T>
    static T square(const T& x)
    {
        return x * x;
    }

    template<typename T>
    static T cube(const T& x)
    {
        return x * x * x;
    }

    template<typename T>
    static T rectangleArea(const T& width, const T& height)
    {
        return width * height;
    }

    template<typename T>
    static T rectanglePerimeter(const T& width, const T& height)
    {
        return 2 * (width + height);
    }

    template<typename T>
    static T circleArea(const T& radius)
    {
        return PI * radius * radius;
    }
};

const float Math::PI = 3.14;

int main()
{
    cout << "1):\n";
    Math math;
	cout << "PI = " << math.PI << endl;
	cout << "Five squared = " << math.square(5) << endl;
	cout << "PI cubed = " << math.cube(math.PI) << endl;
	cout << "Circle with radius = 5.98's area = " << math.circleArea((double)5.98) << endl;
	cout << "Rectangle (4, 5)'s area = " << math.rectangleArea(4, 5) << endl;
    cout << "Rectangle (4.32, 5)'s perimeter = " << math.rectanglePerimeter(4.32, (double)5) << endl;

    cout << "\n2):\n";
	cout << "PI = " << Math::PI << endl;
	cout << "Five squared = " << Math::square(5) << endl;
	cout << "PI cubed = " << Math::cube(Math::PI) << endl;
	cout << "Circle with radius = 5.98's area = " << Math::circleArea(5.98) << endl;
	cout << "Rectangle (4, 5)'s area = " << Math::rectangleArea(4, 5) << endl;
    cout << "Rectangle (4.32, 5)'s perimeter = " << Math::rectanglePerimeter(4.32, (double)5) << endl;
	return 0;
}
