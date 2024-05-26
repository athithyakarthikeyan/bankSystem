#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string name;
    int accountNumber;
    float balance;

public:
    void setValues(std::string n, int a, float b);
    void deposit(float amount);
    bool withdraw(float amount);
    void display();
};

#endif
