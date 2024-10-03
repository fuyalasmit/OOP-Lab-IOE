// Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.
#include <iostream>
#include <iomanip>
using namespace std;

class T {
private:
    int h, m, s;

public:
    // Constructors
    T() : h(0), m(0), s(0) {}
    T(int hr, int min, int sec) : h(hr), m(min), s(sec) {}

    // Function to add time objects
    T add(const T& t) const {
        int ns = s + t.s;
        int nm = m + t.m + ns / 60;
        int nh = h + t.h + nm / 60;
        return T(nh % 24, nm % 60, ns % 60);
    }

    // Display time in 24-hour format
    void disp24() const {
        cout << setfill('0') << setw(2) << h << ":"
             << setfill('0') << setw(2) << m << ":"
             << setfill('0') << setw(2) << s << endl;
    }

    // Display time in 12-hour format
    void disp12() const {
        int dh = h % 12 == 0 ? 12 : h % 12;
        string p = h < 12 ? "AM" : "PM";
        cout << setfill('0') << setw(2) << dh << ":"
             << setfill('0') << setw(2) << m << ":"
             << setfill('0') << setw(2) << s << " " << p << endl;
    }

    // Function to take input from user
    void input() {
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
    }
};

int main() {
    T t1, t2;

    cout << "Enter first time:" << endl;
    t1.input();

    cout << "Enter second time:" << endl;
    t2.input();

    T t3 = t1.add(t2);

    cout << "\nTime 1 in 24-hour format: ";
    t1.disp24();
    cout << "Time 1 in 12-hour format: ";
    t1.disp12();

    cout << "\nTime 2 in 24-hour format: ";
    t2.disp24();
    cout << "Time 2 in 12-hour format: ";
    t2.disp12();

    cout << "\nSum of Time 1 and Time 2 in 24-hour format: ";
    t3.disp24();
    cout << "Sum of Time 1 and Time 2 in 12-hour format: ";
    t3.disp12();

    return 0;
}
