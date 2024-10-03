//Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.
#include <iostream>

void setLarger(float &temp1, float &temp2) {
    float &larger = (temp1 > temp2) ? temp1 : temp2;
    std::cout << "Enter the new value for the larger temperature: ";
    std::cin >> larger;
}

int main() {
    float temp1 , temp2;
    std::cout<<"Enter two temperature values: " ;
    std::cin>>temp1>>temp2;
    setLarger(temp1, temp2);
    std::cout << "Larger temperature after update: " << ((temp1 > temp2) ? temp1 : temp2) << std::endl;
    return 0;
}
