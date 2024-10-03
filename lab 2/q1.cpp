//Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function
#include <iostream>
#include <iomanip>
using namespace std;
struct date { 
    int mm;
    int dd;
    int yy;
};

int printDate(struct date x) {
    cout << setw(2) << setfill('0') << x.mm << "/" << setw(2) << setfill('0') << x.dd << "/"<< x.yy << endl;
}

int main() {
    struct date d;
    cout<<"Enter the month, date and year respectively: ";
    cin>>d.mm>>d.dd>>d.yy;
    cout << "Today's date is: "; printDate(d);
    return 0;
}


