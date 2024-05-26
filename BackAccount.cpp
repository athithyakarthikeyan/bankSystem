#include <iostream>
#include "BankAccount.h"

void BankAccount::setValues(std::string n, int a, float b) {
    name = n;
    accountNumber = a;
    balance = b;
}

void BankAccount::deposit(float amount) {
    balance += amount;
}

bool BankAccount::withdraw(float amount) {
    if (balance - amount < 0) {
        std::cout << "Insufficient balance\n";
        return false;
    }
    balance -= amount;
    return true;
}

void BankAccount::display() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}
