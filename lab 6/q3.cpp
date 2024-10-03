// Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments
// -  veena, guitar, sitar, sarod and mandolin under string()
// -  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
// -  tabla, mridangam, bangos, drums and tambour under perc()

// It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows
// Type of instruments to be displayed
// a.  String instruments
// b.  Wind instruments
// c.  Percussion instruments

// The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.
#include <iostream>
#include <string>

using namespace std;

// Base class Musicians
class Musicians {
protected:
    string stringInstruments[5] = { "veena", "guitar", "sitar", "sarod", "mandolin" };
    string windInstruments[5] = { "flute", "clarinet", "saxophone", "nadhaswaram", "piccolo" };
    string percInstruments[5] = { "tabla", "mridangam", "bongos", "drums", "tambour" };

public:
    // Method to display string instruments
    void displayStringInstruments() {
        cout << "String Instruments:" << endl;
        for (const string& instrument : stringInstruments) {
            cout << instrument << endl;
        }
        cout << endl;
    }

    // Method to display wind instruments
    void displayWindInstruments() {
        cout << "Wind Instruments:" << endl;
        for (const string& instrument : windInstruments) {
            cout << instrument << endl;
        }
        cout << endl;
    }

    // Method to display percussion instruments
    void displayPercInstruments() {
        cout << "Percussion Instruments:" << endl;
        for (const string& instrument : percInstruments) {
            cout << instrument << endl;
        }
        cout << endl;
    }
};

// Derived class TypeIns
class TypeIns : public Musicians {
public:
    // Method to get user choice and display instruments
    void get() {
        char choice;
        cout << "Type of instruments to be displayed:" << endl;
        cout << "a. String instruments" << endl;
        cout << "b. Wind instruments" << endl;
        cout << "c. Percussion instruments" << endl;
        cout << "Enter your choice (a/b/c): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                displayStringInstruments(); // Accessing base class method directly
                break;
            case 'b':
                displayWindInstruments(); // Accessing base class method directly
                break;
            case 'c':
                displayPercInstruments(); // Accessing base class method directly
                break;
            default:
                cout << "Invalid choice. Please enter 'a', 'b', or 'c'." << endl;
        }
    }
};

int main() {
    TypeIns musician;

    // Displaying all instrument categories initially
    musician.displayStringInstruments();
    musician.displayWindInstruments();
    musician.displayPercInstruments();

    // Asking user for specific instrument category
    musician.get();

    return 0;
}
