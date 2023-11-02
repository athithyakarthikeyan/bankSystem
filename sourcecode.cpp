#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
        string name;
        int accountNumber;
        float balance;
    public:
        void setValues(string n,int a,float b){
            name = n;
            accountNumber = a;
            balance = b;
        }
        void deposit(float amount){
            balance += amount;
        }
        void withdraw(float amount){
            if(balance-amount<0){
                cout << "Insufficient balance\n";
            }
            else{
                balance -= amount;
            }
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main(){
    BankAccount account1;
    account1.setValues("RandomName", 12345, 5000.0);
    account1.display();
    account1.deposit(1000.0);
    account1.withdraw(2000.0);
    account1.display();
    return 0;
}
