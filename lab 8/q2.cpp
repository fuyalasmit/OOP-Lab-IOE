// Write a program to create a user-defined manipulator that will format the output by setting the width, precision, and fill character at the same time by passing arguments.
#include <iostream>
#include <iomanip>
using namespace std;

class Fmt {
private:
    int w;
    int p;
    char f;

public:
    Fmt(int width, int prec, char fill) : w(width), p(prec), f(fill) {}
    friend ostream& operator<<(ostream& os, const Fmt& fmt);
};

ostream& operator<<(ostream& os, const Fmt& fmt) {
    os << setfill(fmt.f) << setw(fmt.w) << fixed << setprecision(fmt.p);
    return os;
}

int main() {
    double num = 123.456789;
    Fmt fmt(20, 6, '-');
    cout << fmt << num << endl;

    return 0;
}
