// Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement. 
#include <iostream>

class Distance {
private:
    int m, cm;

public:
    Distance(float meters) {
        m = static_cast<int>(meters);
        cm = static_cast<int>((meters - m) * 100);
    }

    operator float() const { return m + cm / 100.0f; }

    void display() const { std::cout << m << "m " << cm << "cm\n"; }
};

int main() {
    float meters;
    std::cout << "Enter distance (meters): ";
    std::cin >> meters;
    Distance d(meters);
    std::cout << meters << "m = ";
    d.display();
    return 0;
}
