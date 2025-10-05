// Create a class called BankAccount with private data members for account number, 
// account holder name, and balance. Implement public member functions for deposit, 
// withdrawal, and displaying the account details.

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
    account.display();

    cout << "\nDepositing Rs. 3000..." << endl;
    account.deposit(3000);
    account.display();

    cout << "\nWithdrawing Rs. 5000..." << endl;
    account.withdraw(5000);
    account.display();

    cout << "\n\nProgrammed by Milan Bairagi...";

    return 0;
}