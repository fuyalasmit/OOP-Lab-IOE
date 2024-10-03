//Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student.
#include <iostream>
using namespace std;

class Student {
public:
    virtual void print() { cout << "Student" << endl; }
    virtual ~Student() {} // Virtual destructor for polymorphic behavior
};

class Engineering : public Student {
public:
    void print() override { cout << "Engineering student" << endl; }
};

class Medicine : public Student {
public:
    void print() override { cout << "Medicine student" << endl; }
};

class Science : public Student {
public:
    void print() override { cout << "Science student" << endl; }
};

int main() {
    Student *s[3];
    
    s[0] = new Engineering();
    s[1] = new Medicine();
    s[2] = new Science();

    for (int i = 0; i < 3; ++i) {
        s[i]->print();
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete s[i];
    }

    return 0;
}
