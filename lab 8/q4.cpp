// Write a program that stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally, retrieve the information from your file and print it in the proper format on your output screen.

#include <iostream>
#include <fstream>
using namespace std;

class Std {
private:
    char nm[40];
    int id;
    char dept[40];
    char addr[40];

public:
    void setData() {
        cout << "Enter name of student: ";
        cin.getline(nm, 40);
        cout << "Enter student's id: ";
        cin >> id;
        cin.ignore(); // Clear the newline character left in the buffer
        cout << "Enter student's department: ";
        cin.getline(dept, 40);
        cout << "Enter student's address: ";
        cin.getline(addr, 40);
    }

    void showData() const {
        cout << "Name of Student: " << nm << endl;
        cout << "ID of Student: " << id << endl;
        cout << "Department: " << dept << endl;
        cout << "Address: " << addr << endl;
    }

    void inputToFile() const {
        fstream file;
        file.open("student.dat", ios::binary | ios::out | ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file.write(reinterpret_cast<const char*>(this), sizeof(*this));
        file.close();
    }

    static void outputFromFile() {
        fstream file;
        Std s;
        file.open("student.dat", ios::binary | ios::in);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
            cout << "Student Record:" << endl;
            s.showData();
            cout << "----------------------------" << endl;
        }
        file.close();
    }
};

int main() {
    Std s;
    cout << "Enter student data: " << endl;
    s.setData();
    s.inputToFile();
    cout << "---------------- Information From File ----------------" << endl;
    Std::outputFromFile();
    return 0;
}
