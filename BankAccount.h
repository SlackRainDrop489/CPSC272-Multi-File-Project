//
// Created by Quinn on 9/20/2025.
//

#ifndef OBJECTS_CLASSES_LAB_BANKACCOUNT_H
#define OBJECTS_CLASSES_LAB_BANKACCOUNT_H

#include <string>
#include <iostream>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    public:
    BankAccount();
    BankAccount(string acountNum, string HolderName, double bal);
    string getAccountNumber();
    string getAccountHolderName();
    double getBalance();
    void setAccountHolderName(string accountHoldName);
    double deposit(double amount);
    double withdraw(double amount);
};


#endif //OBJECTS_CLASSES_LAB_BANKACCOUNT_H