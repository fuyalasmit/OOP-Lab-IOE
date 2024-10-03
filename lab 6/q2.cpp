//  Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.
#include <iostream>

using namespace std;

// MeterCenti class
class MC {
private:
    int m;
    int cm;
public:
    MC(int m = 0, int cm = 0) : m(m), cm(cm) {}
    double toFI() const {
        double ti = m * 39.3701 + cm * 0.393701;
        int f = ti / 12;
        double i = ti - f * 12;
        return f + i / 12.0;
    }
    friend ostream& operator<<(ostream& os, const MC& mc) {
        os << mc.m << " m " << mc.cm << " cm";
        return os;
    }
};

// FeetInch class
class FI {
private:
    int f;
    double i;
public:
    FI(int f = 0, double i = 0) : f(f), i(i) {}
    MC toMC() const {
        double tc = f * 30.48 + i * 2.54;
        int m = tc / 100;
        int cm = tc - m * 100;
        return MC(m, cm);
    }
    friend ostream& operator<<(ostream& os, const FI& fi) {
        os << fi.f << " f " << fi.i << " i";
        return os;
    }
};

int main() {
    int m, cm, f;
    double i;

    cout << "Enter meters and centimeters: ";
    cin >> m >> cm;
    MC mc(m, cm);
    cout << "MC: " << mc << endl;
    cout << "FI: " << mc.toFI() << " f" << endl;

    cout << "Enter feet and inches: ";
    cin >> f >> i;
    FI fi(f, i);
    cout << "FI: " << fi << endl;
    cout << "MC: " << fi.toMC() << endl;

    return 0;
}
