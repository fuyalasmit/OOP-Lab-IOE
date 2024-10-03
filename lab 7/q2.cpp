//Create a class Person and two derived classes Employee and Student, inherited from class Person. Now create a class Manager which is derived from two base classes Employee and Student. Show the use of the virtual base class.

#include <iostream>
using namespace std;

class Person
{
public:
    void display()
    {
        cout << "You are cute.";
    }
};

class Employee : virtual public Person
{
};

class Student : virtual public Person
{
};

class Manager : public Employee, public Student
{
};
int main()
{
    Manager m1;
    m1.display();
    return 0;
}