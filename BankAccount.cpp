//
// Created by Quinn on 9/20/2025.
//

#include "BankAccount.h"
#include <iostream>


string BankAccount::getAccountNumber() { // This will return the account number
    return accountNumber;
}

string BankAccount::getAccountHolderName() { // This will return the bank account holder name
    return accountHolderName;
}

double BankAccount::getBalance() { // This will get the bank account balance
    return balance;
}

void BankAccount::setAccountHolderName(string accountHoldName) { // This will set the bank account holder name
    accountHolderName = accountHoldName;
}

double BankAccount::deposit(double amount) { // This will deposit money into the bank account
    balance += amount;
    return balance;
}

double BankAccount::withdraw(double amount) { // This will withdraw money from the bank account
    balance -= amount;
    return balance;
}

BankAccount::BankAccount() { // This is the default constructor
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}

BankAccount::BankAccount(string acountNum, string HolderName, double bal) { // This is the parameterized constructor
    accountNumber = acountNum;
    accountHolderName = HolderName;
    balance = bal;
}