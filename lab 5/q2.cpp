// Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).
#include <iostream>
using namespace std;

class Coord3D {
private:
    float x, y, z;

public:
    Coord3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

    // Friend functions for addition and subtraction
    friend Coord3D operator+(const Coord3D& c1, const Coord3D& c2);
    friend Coord3D operator-(const Coord3D& c1, const Coord3D& c2);

    // Display function
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

// Addition operator (friend function)
Coord3D operator+(const Coord3D& c1, const Coord3D& c2) {
    return {c1.x + c2.x, c1.y + c2.y, c1.z + c2.z};
}

// Subtraction operator (friend function)
Coord3D operator-(const Coord3D& c1, const Coord3D& c2) {
    return {c1.x - c2.x, c1.y - c2.y, c1.z - c2.z};
}

int main() {
    float x1, y1, z1, x2, y2, z2;

    cout << "Enter x, y, z for first point: ";
    cin >> x1 >> y1 >> z1;
    Coord3D p1(x1, y1, z1);

    cout << "Enter x, y, z for second point: ";
    cin >> x2 >> y2 >> z2;
    Coord3D p2(x2, y2, z2);

    Coord3D add_result = p1 + p2;
    Coord3D sub_result = p1 - p2;

    cout << "Point 1: ";
    p1.display();
    cout << "Point 2: ";
    p2.display();

    cout << "Result of addition: ";
    add_result.display();

    cout << "Result of subtraction: ";
    sub_result.display();

    return 0;
}
