// Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).
#include <iostream>
using namespace std;

class Park {
private:
    int num_vehicle, hour, rate;

public:
    // Constructor to initialize data members
    Park(int nv, int hr, int rt) : num_vehicle(nv), hour(hr), rate(rt) {}

    // Copy constructor to perform a bit-by-bit copy
    Park(const Park& p) : num_vehicle(p.num_vehicle), hour(p.hour), rate(p.rate) {}

    // Function to calculate and display total charge
    void showCharge() const {
        double total = hour * rate;
        if (num_vehicle > 10) total *= 0.9; // 10% discount
        cout << "Total Charge: " << total << endl;
    }

    // Function to take input from user for num_vehicle, hour, and rate
    void input() {
        cout << "Enter number of vehicles: ";
        cin >> num_vehicle;
        cout << "Enter hours parked: ";
        cin >> hour;
        cout << "Enter rate per hour: ";
        cin >> rate;
    }
};

int main() {
    Park p1(0, 0, 0); // Initialize with default values
    p1.input();

    cout << "\nObject p1:" << endl;
    p1.showCharge();

    Park p2(p1); // Copy constructor invoked
    cout << "\nObject p2 (Copy of p1):" << endl;
    p2.showCharge();

    return 0;
}
