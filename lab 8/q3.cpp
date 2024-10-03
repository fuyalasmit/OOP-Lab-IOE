// Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.
#include <iostream>
using namespace std;

class Cmp {
    int r, i;
    friend istream& operator>>(istream& is, Cmp& c);
    friend ostream& operator<<(ostream& os, const Cmp& c);

public:
    Cmp() : r(0), i(0) {}  // Initialize with default values
};

istream& operator>>(istream& is, Cmp& c) {
    is >> c.r >> c.i;
    return is;
}

ostream& operator<<(ostream& os, const Cmp& c) {
    os << c.r << "+i" << c.i;
    return os;
}

int main() {
    Cmp c;
    cout << "Enter real and imaginary parts: ";
    cin >> c;
    cout << "Complex number: " << c << endl;
    return 0;
}
