#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "You are too broke for " << item << endl;
        } else {
            balance -= cost;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(76.00);
    myAccount.makePurchase("Shrimp Welfare Donation", 50.00);
    myAccount.makePurchase("Jabbawockez Ticket", 24.00);
    myAccount.displayBalance();

    return 0;
}





