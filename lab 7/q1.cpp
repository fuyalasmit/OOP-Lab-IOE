//Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.
#include <iostream>
using namespace std;

class Shape {
public:
    virtual float calculateArea() = 0;  // Pure virtual function
    virtual void display() const = 0;   // Pure virtual function
    virtual ~Shape() {}                 // Virtual destructor
};

class Circle : public Shape {
public:
    Circle(float r) : radius(r) {}
    float calculateArea() override {
        return 3.14 * radius * radius;
    }
    void display() const override {
        cout << "Circle:" << endl;
    }
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }

private:
    float radius;
};

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    float calculateArea() override {
        return width * height;
    }
    void display() const override {
        cout << "Rectangle:" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle destructor called" << endl;
    }

private:
    float width, height;
};

class Trapezoid : public Shape {
public:
    Trapezoid(float a, float b, float w, float h) : a1(a), a2(b), width(w), height(h) {}
    float calculateArea() override {
        return 0.5 * (a1 + a2) * height;
    }
    void display() const override {
        cout << "Trapezoid:" << endl;
    }
    ~Trapezoid() {
        cout << "Trapezoid destructor called" << endl;
    }

private:
    float a1, a2, width, height;
};

int main() {
    Circle c1(5.0);
    Rectangle r1(5.0, 8.0);
    Trapezoid t1(8.0, 6.0, 7.0, 10.0);

    Shape* shapes[] = { &c1, &r1, &t1 };

    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
    }

    return 0;
}
