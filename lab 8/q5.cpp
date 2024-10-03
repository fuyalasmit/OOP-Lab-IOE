// Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account-number, last-name, first-name, total-balance).

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Account
{
private:
    int accountNumber;
    char lastName[30];
    char firstName[30];
    double totalBalance;

public:
    Account() : accountNumber(0), totalBalance(0.0)
    {
        strcpy(lastName, "");
        strcpy(firstName, "");
    }

    Account(int accNum, const char *lName, const char *fName, double balance)
        : accountNumber(accNum), totalBalance(balance)
    {
        strcpy(lastName, lName);
        strcpy(firstName, fName); 
    }

    int getAccountNumber() const { return accountNumber; }

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    void setLastName(const char *lName) { strcpy(lastName, lName); }
    void setFirstName(const char *fName) { strcpy(firstName, fName); }
    void setTotalBalance(double balance) { totalBalance = balance; }

    void addAccount(fstream &file)
    {
        file.seekp(0, ios::end);
        file.write(reinterpret_cast<const char *>(this), sizeof(Account));
    }

    void updateAccount(fstream &file, int accNum, double newBalance)
    {
        Account account;
        file.seekg(0);

        while (file.read(reinterpret_cast<char *>(&account), sizeof(Account)))
        {
            if (account.getAccountNumber() == accNum)
            {
                account.setTotalBalance(newBalance);
                file.seekp(-sizeof(Account), ios::cur);
                file.write(reinterpret_cast<const char *>(&account), sizeof(Account));
                cout << "Account updated successfully." << endl;
                return;
            }
            else{
                break;
            }
        }

        cout << "Account not found." << endl;
    }

    void deleteAccount(fstream &file, int accNum)
    {
        Account account;
        file.seekg(0);

        while (file.read(reinterpret_cast<char *>(&account), sizeof(Account)))
        {
            if (account.getAccountNumber() == accNum)
            {
                account.setAccountNumber(0);
                file.seekp(-sizeof(Account), ios::cur);
                file.write(reinterpret_cast<const char *>(&account), sizeof(Account));
                cout << "Account deleted successfully." << endl;
                return;
            }
            else{
                break;
            }
        }

        cout << "Account not found." << endl;
    }

    void displayAllAccounts(fstream &file)
    {
        Account account;
        file.clear();  // Clear any error flags
        file.seekg(0); // Reset to beginning of the file

        while (file.read(reinterpret_cast<char *>(&account), sizeof(Account)))
        {
            if (account.getAccountNumber() != 0)
            {
                cout << "Account Number: " << account.getAccountNumber() << endl;
                cout << "Last Name: " << account.lastName << endl;
                cout << "First Name: " << account.firstName << endl;
                cout << "Total Balance: " << account.totalBalance << endl;
                cout << "---------------------------" << endl;
            }
            else{
                break;
            }
        }
    }
};

int main()
{
    // First, create the file if it doesn't exist
    ofstream tempFile("accounts.dat", ios::app | ios::binary);
    if (!tempFile)
    {
        cerr << "Error creating file." << endl;
        return 1;
    }
    tempFile.close();

    // Now open the file for reading and writing
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Account account;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Account\n";
        cout << "2. Update Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Display All Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int accNum;
            char lName[30];
            char fName[30];
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Last Name: ";
            cin >> lName;
            cout << "Enter First Name: ";
            cin >> fName;
            cout << "Enter Total Balance: ";
            cin >> balance;

            Account newAccount(accNum, lName, fName, balance);
            newAccount.addAccount(file);
            break;
        }
        case 2:
        {
            int accNum;
            double newBalance;
            cout << "Enter Account Number to update: ";
            cin >> accNum;
            cout << "Enter New Balance: ";
            cin >> newBalance;

            account.updateAccount(file, accNum, newBalance);
            break;
        }
        case 3:
        {
            int accNum;
            cout << "Enter Account Number to delete: ";
            cin >> accNum;

            account.deleteAccount(file, accNum);
            break;
        }
        case 4:
            account.displayAllAccounts(file);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        // Reset the file position for next operation
        file.clear();
        file.seekg(0, ios::beg);
        file.seekp(0, ios::beg);

    } while (choice != 5);

    file.close();
    return 0;
}
