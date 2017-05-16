#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    const long long egn;
    Person(const string& _name, const long long& _egn)
        : name(_name), egn(_egn)
    {
    }
    ~Person(){}
};

class Student : public Person
{
public:
    int facultyNumber;
    string university;
    double grade;
    Student(const Person& person,
            const string& _university,
            const double& _grade)
        : Person(person), university(_university), grade(_grade)
    {

    }
    Student(const string& _name,
            const long long& _egn,
            const string& _university,
            const double& _grade)
        : Person(_name, _egn), university(_university), grade(_grade)
    {

    }
};

int main()
{
    Person p("adfadf", 45964);
    Student s(p, "Sdfgsdggsdt", 3567.4);
    return 0;
}
