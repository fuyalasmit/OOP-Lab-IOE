// Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.
#include <iostream>
#include <string>

using namespace std;

class Dept {
private:
    int id;
    string name;

public:
    Dept(int i, const string& n) : id(i), name(n) {
        cout << "Constructor called for Dept " << id << ": " << name << endl;
    }

    ~Dept() {
        cout << "Destructor called for Dept " << id << ": " << name << ". Object " << id << " goes out of scope." << endl;
    }
};

int main() {
    Dept d1(1, "Civil");
    {
        Dept d2(2, "Computer");
        {
            Dept d3(3, "Electrical");
        }
    }

    return 0;
}
