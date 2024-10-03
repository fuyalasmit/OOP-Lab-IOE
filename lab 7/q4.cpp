//Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual void printType() {
        cout << "Vehicle" << endl;
    }
    virtual ~Vehicle() {
        cout << "Vehicle Destroyed." << endl;
    }
};

class Bus : public Vehicle {
public:
    void printType() override {
        cout << "Bus" << endl;
    }
};

class Car : public Vehicle {
public:
    void printType() override {
        cout << "Car" << endl;
    }
};

class Bike : public Vehicle {
public:
    void printType() override {
        cout << "Bike" << endl;
    }
};

int main() {
    Vehicle* v1 = new Bus();
    Vehicle* v2 = new Car();
    Vehicle* v3 = new Bike();

    // Using Dynamic cast
    Bus* b1 = dynamic_cast<Bus*>(v1);
    Car* c1 = dynamic_cast<Car*>(v2);
    Bike* bi1 = dynamic_cast<Bike*>(v3);

    if (b1) {
        cout << "Vehicle-1 is a Bus." << endl;
    } else if (c1) {
        cout << "Vehicle-2 is a Car." << endl;
    } else if (bi1) {
        cout << "Vehicle-3 is a Bike." << endl;
    } else {
        cout << "Vehicle is of unknown type." << endl;
    }

    cout << "Type of vehicle-1: " << typeid(*v1).name() << endl;
    cout << "Type of vehicle-2: " << typeid(*v2).name() << endl;
    cout << "Type of vehicle-3: " << typeid(*v3).name() << endl;

    // Clean up dynamically allocated memory
    delete v1;
    delete v2;
    delete v3;

    return 0;
}
