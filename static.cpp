#include <iostream>

using namespace std;

class Sheep
{
private:
    static unsigned int numberOfSheeps;

public:
    Sheep()
    {
        ++numberOfSheeps;
        cout << "Sheep number " << numberOfSheeps << " was just born!\n";
    }
    ~Sheep()
    {
        --numberOfSheeps;
        cout << "A sheep just died... ;(\nNumber of sheep left: " << numberOfSheeps << endl;
    }
};

unsigned int Sheep::numberOfSheeps = 0;

int main()
{
    Sheep mary; /// Sheep* mary = new Sheep();
	cout << "Mary\n";
	Sheep* gary = new Sheep();
	delete gary;
	gary = new Sheep[13]; /// gary = new Sheep();
	delete[] gary; /// delete gary;
	cout << "End of main!\n";
	return 0;
	///	cout << "End of main!\n";
}
