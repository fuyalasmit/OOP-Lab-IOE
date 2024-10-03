// Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.
#include <iostream>
using namespace std;

class Integer {
private:
    int val;

public:
    Integer(int n) : val(n) {}

    // Overloading equality operator (==)
    bool operator==(const Integer& n) const {
        return val == n.val;
    }

    // Overloading less than operator (<)
    bool operator<(const Integer& n) const {
        return val < n.val;
    }

    // Overloading greater than operator (>)
    bool operator>(const Integer& n) const {
        return val > n.val;
    }

    // Overloading not equal operator (!=)
    bool operator!=(const Integer& n) const {
        return val != n.val;
    }

    // Overloading less than or equal to operator (<=)
    bool operator<=(const Integer& n) const {
        return val <= n.val;
    }

    // Overloading greater than or equal to operator (>=)
    bool operator>=(const Integer& n) const {
        return val >= n.val;
    }
};

int main() {
    int v1, v2;
    cout << "Enter value for first integer: ";
    cin >> v1;
    cout << "Enter value for second integer: ";
    cin >> v2;

    Integer n1(v1), n2(v2);

    // Testing the overloaded operators
    cout << "n1 == n2 : " << (n1 == n2) << endl;
    cout << "n1 < n2  : " << (n1 < n2) << endl;
    cout << "n1 > n2  : " << (n1 > n2) << endl;
    cout << "n1 != n2 : " << (n1 != n2) << endl;
    cout << "n1 <= n2 : " << (n1 <= n2) << endl;
    cout << "n1 >= n2 : " << (n1 >= n2) << endl;

    return 0;
}
