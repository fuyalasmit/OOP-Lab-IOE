// Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.
#include <iostream>

using namespace std;

class C
{
protected:
    float r, i;

public:
    C(float real = 0, float imag = 0) : r{real}, i{imag} {}

    void prompt()
    {
        cout << "Enter real part: ";
        cin >> r;

        cout << "Enter imaginary part: ";
        cin >> i;
    }

    void display() const
    {
        cout << '(' << r << ", " << i << ")\n";
    }

    friend class C_;
    friend class D;
};

class C_ : public C
{
public:
    C_(float real = 0, float imag = 0) : C(real, imag) {}

    C_ operator+(const C &c)
    {
        return C_(r + c.r, i + c.i);
    }

    friend class D;
};

class D
{
public:
    C result(const C &c1, const C_ &c2)
    {
        return C(c1.r - c2.r, c1.i - c2.i);
    }
};

int main()
{
    C c1;
    C_ c2;

    c1.prompt();
    cout << '\n';
    c2.prompt();

    cout << '\n';
    C c3 = c2 + c1;
    c3.display();

    D d;
    c3 = d.result(c1, c2);
    c3.display();

    return 0;
}
