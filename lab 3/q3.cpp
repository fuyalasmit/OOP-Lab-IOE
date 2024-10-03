/*Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time. Make functions to set data members and show the charges and parked hours of the corresponding car id. Make functions for setting and showing the data members. Member function should be called from other functions.*/
#include <iostream>

using namespace std;

class CarPark {
private:
  int carId;
  int chargePerHour;
  float parkedTime;

public:
  // Function to set car data (car ID, charge per hour, parked time)
  void setData(int id, int charge, float time) {
    carId = id;
    chargePerHour = charge;
    parkedTime = time;
  }

  // Function to display car data and calculate charges
  void showData() {
    cout << "Car ID: " << carId << endl;
    cout << "Charge per Hour: $" << chargePerHour << endl;
    cout << "Parked Time: " << parkedTime << " hours" << endl;
    cout << "Total Charges: $" << calculateCharges() << endl;
  }

private:
  // Function to calculate total charges based on parked time and hourly charge
  float calculateCharges() {
    return chargePerHour * parkedTime;
  }
};

int main() {
  CarPark car1;
  double id,rate,time;
  cout<<"Enter car ID, charge per hour and parked time respectively: ";
  cin>>id>>rate>>time;
  // Set car data for car1
  // car1.setData(1234, 10, 3.5);
  car1.setData(id,rate,time);

  // Display car data and charges for car1
  car1.showData();

  return 0;
}
