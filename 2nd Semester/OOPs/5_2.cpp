// Demonstrate encapsulation by accessing class members through member functions.

#include <iostream>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(string num, string name, double b) {
        accountNumber = num;
        holderName = name;
        balance = b;
    }

    void setAccountNumber(string num) { 
        accountNumber = num;
    }
    string getAccountNumber() { 
        return accountNumber;
    }
    void setHolderName(string name) { 
        holderName = name;
    }
    string getHolderName() { 
        return holderName;
    }
    void setBalance(float num) { 
        balance = num;
    }
    double getBalance() { 
        return balance;
    }

    void deposit(double num) {
        balance += num;
    }

    void withdraw(double num) {
        if (num > balance) {
            cout << "You don't have enouch balance to withdraw" << endl;
            return;
        }
        balance -= num;
    }

    void display() {
        cout << "Account Number: " << accountNumber << ", Account Holder Name: " <<
            holderName << ", Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account("0123456789", "Milan Bairagi", 607009.87);

    cout << "Initial account detail:" << endl;
    account.display();

    // Modify account details using setter functions
    account.setAccountNumber("9876543210");
    account.setHolderName("John Wick");


    // Deposit money into the account
    account.deposit(500.0);

    // Withdraw money from the account
    account.withdraw(200.0);

    cout << "Updated account detail: " << endl;
    account.display();


    cout << "\n\nProgrammed by Milan Bairagi...";

    return 0;
}