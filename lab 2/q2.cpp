//Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.
#include <iostream>
using namespace std;

void feet_to_inch() {
    double feet = 0.0;
    cout << "Enter feet: ";
    cin >> feet;
    double inches = feet * 12;
    cout << feet << " feet is " << inches << " inches." << endl;
}


void feet_to_inch(double feet) {
    double inches = feet * 12;
    cout << feet << " feet is " << inches << " inches." << endl;
}


void feet_to_inch(double feet1, double& feet2) {
    double inches1 = feet1 * 12;
    double inches2 = feet2 * 12;
    cout << feet1 << " feet is " << inches1 << " inches." << endl;
    cout << feet2 << " feet is " << inches2 << " inches." << endl;
}

int main() {
    feet_to_inch();

    double feet1 = 5.5;
    feet_to_inch(feet1);

    double feet2 = 7.25;
    feet_to_inch(feet1, feet2);

    return 0;
}