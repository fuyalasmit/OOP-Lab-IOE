// Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

#include <iostream>
using namespace std;

class Obj {
private:
    static int cnt;   // Static data member to keep track of the number of objects created
    int sn;           // Data member to hold the serial number of each object

public:
    // Constructor
    Obj() : sn(++cnt) {}

    // Function to get the serial number of the object
    int get() const {
        return sn;
    }

    // Static member function to get the count of objects created
    static int tot() {
        return cnt;
    }
};

// Initialize static data member
int Obj::cnt = 0;

int main() {
    Obj o1, o2, o3;

    cout << "Object 1 Serial Number: " << o1.get() << endl;
    cout << "Object 2 Serial Number: " << o2.get() << endl;
    cout << "Object 3 Serial Number: " << o3.get() << endl;
    cout << "Total Objects Created: " << Obj::tot() << endl;

    return 0;
}
