// Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.

#include <iostream>
#include <cstring>
using namespace std;

class Str {
private:
    char* s;

public:
    // Constructor to allocate and initialize the character array
    Str(const char* init) {
        s = new char[strlen(init) + 1];
        strcpy(s, init);
    }

    // Destructor to free the allocated memory
    ~Str() {
        delete[] s;
    }

    // Function to concatenate two strings
    void join(const Str& s1, const Str& s2) {
        delete[] s;
        s = new char[strlen(s1.s) + strlen(s2.s) + 1];
        strcpy(s, s1.s);
        strcat(s, s2.s);
    }

    // Function to display the string
    void disp() const {
        cout << s << endl;
    }
};

int main() {
    Str s1("Engineers are"), s2(" Creatures of logic"), s3("");

    s3.join(s1, s2);

    cout << "String 1: ";
    s1.disp();
    cout << "String 2: ";
    s2.disp();
    cout << "Concatenated String: ";
    s3.disp();

    return 0;
}
