// Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
// A. Make a particular member function of one class as a friend function of another class for addition.
// B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
// C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.
// Make least possible classes to demonstrate all the above in a single program without conflict.
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Friend function declaration for addition
    friend Point add(const Point& p1, const Point& p2);

    // Functions to bridge between Point and Calculator
    Point multiply(const Point& p2) const;
    Point divide(const Point& p2) const;
    Point subtract(const Point& p2) const;

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Friend function definition for addition
Point add(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// Member function definitions for multiplication, division, and subtraction
Point Point::multiply(const Point& p2) const {
    return Point(x * p2.x, y * p2.y);
}

Point Point::divide(const Point& p2) const {
    // Ensure p2.x and p2.y are non-zero to avoid division by zero
    if (p2.x != 0 && p2.y != 0)
        return Point(x / p2.x, y / p2.y);
    else
        return Point(0, 0); // Handle division by zero gracefully
}

Point Point::subtract(const Point& p2) const {
    return Point(x - p2.x, y - p2.y);
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x y): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x y): ";
    cin >> x2 >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    // Demonstrate friend function (addition)
    Point sum = add(p1, p2);
    cout << "Sum of points: ";
    sum.display();

    // Demonstrate member functions (multiplication, division, subtraction)
    Point product = p1.multiply(p2);
    cout << "Product of points: ";
    product.display();

    Point quotient = p1.divide(p2);
    cout << "Quotient of points: ";
    quotient.display();

    Point difference = p1.subtract(p2);
    cout << "Difference of points: ";
    difference.display();

    return 0;
}
