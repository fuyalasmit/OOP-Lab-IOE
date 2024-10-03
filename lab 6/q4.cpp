// Write three derived classes inheriting functionality of base class person (should have a member function that asks to enter name and age) and with added unique features of student, and employee, and functionality to assign, change and delete records of student and employee. And make one member function for printing the address of the objects of classes (base and derived) using this pointer. Create two objects of the base class and derived classes each and print the addresses of individual objects. Using a calculator, calculate the address space occupied by each object and verify this with address spaces printed by the program.
#include <iostream>
#include <string>

using namespace std;

class P
{
protected:
    string n;
    int a;

public:
    P()
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, n);
        cout << "Enter age: ";
        cin >> a;
    }

    void setDetails(const string &name, int age)
    {
        n = name;
        a = age;
    }

    virtual void display() const
    {
        cout << "Name: " << n << "\nAge: " << a << endl;
    }

    void displayAddress() const
    {
        cout << "Address of this object: " << this << "\nSize of this object: " << sizeof(*this) << " bytes" << endl;
    }
};

class S : public P
{
private:
    string id;

public:
    S()
    {
        cout << "Enter student ID: ";
        cin.ignore();
        getline(cin, id);
    }

    void setDetails(const string &name, int age, const string &studentID)
    {
        P::setDetails(name, age);
        id = studentID;
    }

    void display() const override
    {
        P::display();
        cout << "Student ID: " << id << endl;
    }
};

class E : public P
{
private:
    string id;
    int s;

public:
    E()
    {
        cout << "Enter employee ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Enter salary: ";
        cin >> s;
    }

    void setDetails(const string &name, int age, const string &employeeID, int salary)
    {
        P::setDetails(name, age);
        id = employeeID;
        s = salary;
    }

    void display() const override
    {
        P::display();
        cout << "Employee ID: " << id << "\nSalary: " << s << endl;
    }
};

int main()
{
    cout << "Enter details for Person 1:\n";
    P *p1 = new P();
    p1->display();
    p1->displayAddress();

    cout << "\nEnter details for Person 2:\n";
    P *p2 = new P();
    p2->display();
    p2->displayAddress();

    cout << "\nEnter details for Student 1:\n";
    S *s1 = new S();
    s1->display();
    s1->displayAddress();

    cout << "\nEnter details for Student 2:\n";
    S *s2 = new S();
    s2->display();
    s2->displayAddress();

    cout << "\nEnter details for Employee 1:\n";
    E *e1 = new E();
    e1->display();
    e1->displayAddress();

    cout << "\nEnter details for Employee 2:\n";
    E *e2 = new E();
    e2->display();
    e2->displayAddress();

    delete p1;
    delete p2;
    delete s1;
    delete s2;
    delete e1;
    delete e2;

    return 0;
}
