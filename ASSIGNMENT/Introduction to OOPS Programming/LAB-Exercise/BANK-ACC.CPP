#include <iostream>
#include <conio.h>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposited: " << amount;
        } else {
            cout << "\nInvalid deposit amount!";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nWithdrawn: " << amount;
        } else {
            cout << "\nInsufficient balance or invalid amount!";
        }
    }

    void displayBalance() {
        cout << "\nCurrent Balance: " << balance;
    }
};

void main() {

    clrscr();
    cout << "BankAccount"<< account1(1000);

    account1.displayBalance();

    account1.deposit(500);   
    account1.displayBalance();

    account1.withdraw(300); 
    account1.displayBalance();

    account1.withdraw(1500);

    getch();
}
