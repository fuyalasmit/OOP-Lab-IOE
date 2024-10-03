// Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.
#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    int y, m, d;

public:
    Date(int yy, int mm, int dd) : y(yy), m(mm), d(dd) {}

    // Prefix increment operator (++date)
    Date& operator++() {
        d++;
        if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 31)) {
            d = 1;
            m++;
        } else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30)) {
            d = 1;
            m++;
        } else if (m == 2 && leap() && (d > 29)) {
            d = 1;
            m++;
        } else if (m == 2 && !leap() && (d > 28)) {
            d = 1;
            m++;
        }

        if (m > 12) {
            m = 1;
            y++;
        }

        return *this;
    }

    // Postfix increment operator (date++)
    Date operator++(int) {
        Date temp(*this); // Make a copy of the current object
        ++(*this);        // Use the prefix increment to increase the date
        return temp;      // Return the copy of the original date
    }

    // Check if the year is a leap year
    bool leap() const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    // Display the date in yyyy-mm-dd format
    void display() const {
        cout << y << "-" << setfill('0') << setw(2) << m << "-" << setw(2) << d << '\n';
    }
};

int main() {
    int yy, mm, dd;
    cout << "Enter year, month, day: ";
    cin >> yy >> mm >> dd;

    Date date(yy, mm, dd);

    cout << "Original Date:" << endl;
    date.display();

    ++date; // Prefix increment
    cout << "\nAfter prefix increment:" << endl;
    date.display();

    date++; // Postfix increment
    cout << "\nAfter postfix increment:" << endl;
    date.display();

    return 0;
}
