//Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.
#include <iostream>

inline float calculate(float salary) {
    return (salary-0.1*salary);
}

int main() {
    float salary;
    std::cout << "Enter the employee's salary: ";
    std::cin >> salary;
    std::cout << "Net payment after tax deduction: " << calculate(salary) << std::endl;
    return 0;
}
