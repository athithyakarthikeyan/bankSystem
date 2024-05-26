#include <iostream>
#include "BankAccount.h"

int main() {
    BankAccount account;
    account.setValues("RandomName", 12345, 5000.0);
    account.display();
    account.deposit(1000.0);
    account.withdraw(2000.0);
    account.display();

    return 0;
}
