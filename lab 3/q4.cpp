/*Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.*/#include <iostream>
#include <cmath> // for sqrt function

class Circle {
private:
  double radius;

public:
  void getData() {
    std::cout << "Enter radius: ";
    std::cin >> radius;
  }

  void displayData() {
    std::cout << "Circle" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
  }

  double calculateArea() {
    return 3.14159 * radius * radius;
  }

  double calculatePerimeter() {
    return 2 * 3.14159 * radius;
  }
};

class Rectangle {
private:
  double length, width;

public:
  void getData() {
    std::cout << "Enter length and width: ";
    std::cin >> length >> width;
  }

  void displayData() {
    std::cout << "Rectangle" << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
  }

  double calculateArea() {
    return length * width;
  }

  double calculatePerimeter() {
    return 2 * (length + width);
  }
};

class Triangle {
private:
  double side1, side2, side3;

public:
  void getData() {
    std::cout << "Enter three sides of the triangle: ";
    std::cin >> side1 >> side2 >> side3;
  }

  void displayData() {
    std::cout << "Triangle" << std::endl;
    std::cout << "Side 1: " << side1 << std::endl;
    std::cout << "Side 2: " << side2 << std::endl;
    std::cout << "Side 3: " << side3 << std::endl;
  }

  double calculateArea() {
    // Using Heron's formula to calculate area of triangle
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

  double calculatePerimeter() {
    return side1 + side2 + side3;
  }
};

int main() {
  Circle circle;
  Rectangle rectangle;
  Triangle triangle;

  std::cout << "Enter data for Circle:" << std::endl;
  circle.getData();

  std::cout << "Enter data for Rectangle:" << std::endl;
  rectangle.getData();

  std::cout << "Enter data for Triangle:" << std::endl;
  triangle.getData();

  std::cout << std::endl << "Area and Perimeter for all shapes are:" << std::endl;
  circle.displayData();
  std::cout << "Area: " << circle.calculateArea() << std::endl;
  std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl << std::endl;

  rectangle.displayData();
  std::cout << "Area: " << rectangle.calculateArea() << std::endl;
  std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl << std::endl;

  triangle.displayData();
  std::cout << "Area: " << triangle.calculateArea() << std::endl;
  std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

  return 0;
}
