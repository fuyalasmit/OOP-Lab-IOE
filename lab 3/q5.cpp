/*Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus

and

had worked ... ... ... hours as overtime in the year ... ... ...*/
#include <iostream>

class EmployeeReport
{
private:
  int emp_id;
  double total_bonus;
  int total_overtime;
  int year;

public:
  // Function to set the employee report attributes
  void set_report(int id, double bonus, int overtime, int yr)
  {
    emp_id = id;
    total_bonus = bonus;
    total_overtime = overtime;
    year = yr;
  }

  // Function to display the employee report in the desired format
  void display_report()
  {
    std::cout << "An employee with ID " << emp_id << " has received Rs "
              << total_bonus << ".00 as a bonus" << std::endl;
    std::cout << "and had worked " << total_overtime << " hours as overtime in the year "
              << year << std::endl;
  }
};

int main()
{
  // Define the size of the employee report array (adjust as needed)
  const int num_employees = 2;
  EmployeeReport employee_reports[num_employees];

  // Set employee report data for each employee (replace with your data)
  employee_reports[0].set_report(101, 50000.00, 200, 2023);
  employee_reports[1].set_report(102, 75000.50, 150, 2023);

  // Display employee reports
  for (int i = 0; i < num_employees; ++i)
  {
    employee_reports[i].display_report();
    std::cout << std::endl;
  }

  return 0;
}
