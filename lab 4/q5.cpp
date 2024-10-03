// Write a program that illustrates the following relationship and comment on them. 
// i) const_object.non_const_mem_function
// ii) const_object.const_mem_function
// iii) non_const_object.non_const_mem_function
// iv) non_const_object.const_mem_function
#include <iostream>
using namespace std;

class Example {
private:
    int value;

public:
    // Constructor to initialize value
    Example(int v = 0) : value(v) {}

    // Const member function to show data
    void show() const {
        cout << "Value: " << value << endl;
    }

    // Non-const member function to set data
    void set(int v) {
        value = v;
    }
};

int main() {
    int initialValue;
    cout << "Enter initial value for non-const object: ";
    cin >> initialValue;

    Example ncObj(initialValue);
    const Example cObj(initialValue);

    // i) const_object.non_const_mem_function
    // Uncommenting the following line will cause a compilation error:
    // cObj.set(10);

    // ii) const_object.const_mem_function
    cout << "Const object calling const member function:" << endl;
    cObj.show();

    // iii) non_const_object.non_const_mem_function
    cout << "Non-const object calling non-const member function:" << endl;
    ncObj.set(20);
    ncObj.show();

    // iv) non_const_object.const_mem_function
    cout << "Non-const object calling const member function:" << endl;
    ncObj.show();

    return 0;
}
