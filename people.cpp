#include <iostream>
#include <string.h>

class DateTime
{
private:
    uint16_t year;
    uint8_t  day;
    uint8_t  month;
    uint8_t  seconds;
    uint8_t  minutes;
    uint8_t  hours;
    void setNDigitNum(uint16_t num, char* buffer, const uint8_t& numberOfDigits) const
    {
        for (int iteration = 1; iteration <= numberOfDigits; ++iteration)
        {
            buffer[numberOfDigits - iteration] = (num % 10) + '0';
            num /= 10;
        }
    }
public:
    DateTime(const uint8_t& _day = 0, const uint8_t& _month = 0, const uint16_t& _year = 0,
        const uint8_t& _seconds = 0, const uint8_t& _minutes = 0, const uint8_t& _hours = 0)
        : day(_day), month(_month), year(_year), seconds(_seconds), minutes(_minutes), hours(_hours)
    {}
    uint8_t  getDay()     const { return day;     }
    uint8_t  getMonth()   const { return month;   }
    uint16_t getYear()    const { return year;    }
    uint8_t  getSeconds() const { return seconds; }
    uint8_t  getMinutes() const { return minutes; }
    uint8_t getHours()    const { return hours;   }
    void setDay(const uint8_t& _day)         { day     = _day;     }
    void setMonth(const uint8_t& _month)     { month   = _month;   }
    void setYear(const uint16_t& _year)      { year    = _year;    }
    void setSeconds(const uint8_t& _seconds) { seconds = _seconds; }
    void setMinutes(const uint8_t& _minutes) { minutes = _minutes; }
    void setHours(const uint8_t& _hours)     { hours   = _hours;   }
    void getDateTime(char buffer[19]) const /// "hh:mm:ss-dd:mm:yyyy"
    {
        setNDigitNum(hours, buffer, 2);
        setNDigitNum(minutes, buffer + 3, 2);
        setNDigitNum(seconds, buffer + 6, 2);
        setNDigitNum(day, buffer + 9, 2);
        setNDigitNum(month, buffer + 12, 2);
        setNDigitNum(year, buffer + 15, 4);
        buffer[2] = buffer[5] = buffer[11] = buffer[14] = ':';
        buffer[8] = '-';
        buffer[19] = '\0';
    }
};

class Xqwerty
{
private:
    int x;
public:
    Xqwerty(int _x = 5) : x(_x) {}
};

class Person
{
private:
    char name[128];
    char sirname[128];
    DateTime dateOfBirth;
    DateTime dateOfWedding;
public:
    Person(const char* _name = "", const char* _sirname = "", const DateTime& _dateOfBirth = DateTime(), DateTime _dateOfWedding = DateTime())
        : dateOfBirth(_dateOfBirth), dateOfWedding(_dateOfWedding)
    {
        strncpy(name, _name, 127);
        strncpy(sirname, _sirname, 127);
    }
    const char* getName() const { return name; }
    const char* getSirname() const { return sirname; }
    DateTime getDateOfBirth() const { return dateOfBirth; }
    DateTime getDateOfWedding() const { return dateOfWedding; }
};

class Student : private Xqwerty, private Person
{
private:
    uint8_t course;
    uint32_t facultyNumber;
    char* university;
    void copyUniversity(const char* _university)
    {
        size_t length = strlen(_university);
        university = new char [length + 1];
        strcpy(university, _university);
    }
public:
    Student(const Person& _person, const uint32_t& _facultyNumber, const char* _university)
        : Person(_person), facultyNumber(_facultyNumber), course(1)
    {
        size_t length = strlen(_university);
        university = new char [length + 1];
        strcpy(university, _university);
    }
    Student(const Student& other)
        : Person((Person)other), facultyNumber(other.facultyNumber), course(other.course)
    {
        copyUniversity(other.university);
    }
    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
            delete[] university;
            facultyNumber = other.facultyNumber;
            course = other.course;
            copyUniversity(other.university);
            ///...
        }
        return *this;
    }
};

int main()
{
    DateTime d(13, 12, 2017, 34, 54, 13);
    char date[19]; /// 0, 30
    d.getDateTime(date);
    std::cout << date << std::endl;
    Person john("John", "Ivanov", d, d);
    std::cout << john.getName() << std::endl;
    Student someStudent(john, 81374, "SU-FMI");
    return 0;
}
