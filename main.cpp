/*
Quinn Alvine
9/11/25
This program is for making and editing a bank account
Lab Activities: Objects and Classes I
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "BankAccount.h"



void Menu(int accountNum) { // This will display the menu
    cout << "---------------------------" << endl;
    cout << "You are in account number: " << accountNum << endl;
    cout << "1. Set account holder name" << endl;
    cout << "2. Get account holder name" << endl;
    cout << "3. Get account number" << endl;
    cout << "4. Get balance" << endl;
    cout << "5. Change balance" << endl;
    cout << "6. Create new account" << endl;
    cout << "7. Change account" << endl;
    cout << "8. Print all details" << endl;
    cout << "9. Copy existing account" << endl;
    cout << "10. Quit" << endl;
    cout << "---------------------------" << endl;
}

int main() { // Main function
    BankAccount BankAccount1; // This creates the first account
    vector<BankAccount> BankAccounts; // This creates a vector of bank accounts
    BankAccounts.push_back(BankAccount1); // This adds the first account to the vector
    int currentAccountNum = 0; // This is the current account
    int currentDisplayAccountNum = 1; // This is the account number to be displayed
    int input; // This is the input
    int accountInputNum; // This is the input for changing accounts
    string newAccountName; // This is for holding the new name of an account
    do { // This is the main loop
        Menu(currentDisplayAccountNum); // This will display the menu
        cout << "Enter your choice: "; // This will prompt you for your input
        if (!(cin >> input)) { // This will make sure that you are inputting an int
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << endl;
            switch (input) { // This is the main switch
                case 1: // Change account name
                    cout << "Enter account holder name: ";
                    cin.ignore();
                    getline(cin, newAccountName);
                    BankAccounts[currentAccountNum].setAccountHolderName(newAccountName);
                    break;
                case 2: // Get account holder name
                    cout << "The name of this account is: " << BankAccounts[currentAccountNum].getAccountHolderName() << endl;
                    break;
                case 3: // Get account number
                    cout << "The account number is: " << BankAccounts[currentAccountNum].getAccountNumber() << endl;
                    break;
                case 4: // Get balance
                    cout << "The balance is: " << BankAccounts[currentAccountNum].getBalance() << endl;
                    break;
                case 5: {
                    // Change balance
                    cout << "Would you like to make a (1) Deposit or (2) a Withdraw: ";
                    int optionInput;
                    cin >> optionInput;
                    switch (optionInput) {
                        case 1: // Make a deposit
                            cout << endl << "How much would you like to deposit: ";
                            double deposit;
                            cin >> deposit;
                            BankAccounts[currentAccountNum].deposit(deposit);
                            break;
                        case 2: // Make a withdrawal
                            cout << endl << "You currently have $" << BankAccounts[currentAccountNum].getBalance() << endl;
                            cout << "How much would you like to withdraw: ";
                            double withdraw;
                            cin >> withdraw;
                            if (withdraw > BankAccounts[currentAccountNum].getBalance()) {
                                cout << endl << "There is not enough money in your account." << endl;
                            } else {
                                BankAccounts[currentAccountNum].withdraw(withdraw);
                            }
                            break;
                        default: ;
                    }
                    break;
                }
                case 6: {
                    // Create new account
                    BankAccounts.push_back(BankAccount::createAccountFromInput(BankAccounts));
                    break;
                }
                case 7: // Change account
                    if (BankAccounts.size() == 1) {
                        cout << "There is only one bank account" << endl;
                    } else {
                        cout << "There are " << BankAccounts.size() << " bank accounts" << endl;
                        cout << "Please enter account number: ";
                        cin >> accountInputNum;
                        if (accountInputNum < 0 or accountInputNum > BankAccounts.size()) {
                            cout << endl << "There is no account with this number" << endl;
                        } else {
                            currentAccountNum = accountInputNum - 1;
                            currentDisplayAccountNum = accountInputNum;
                        }
                    }
                    break;
                case 8:
                    BankAccount::printAccount(BankAccounts[currentAccountNum]);
                    break;
                case 9: {
                    // Copy existing account
                    BankAccount copiedAccount(BankAccounts[0]);
                    //push the copy onto the vector
                    BankAccounts.push_back(copiedAccount);
                    //print the new account that is a copy
                    BankAccount::printAccount(copiedAccount);
                    break;
                }
                case 10: // Quit
                    cout << "Quit";
                    break;
                default:
                    cout << "Please enter a valid choice." << endl;
                    break;
            }
        }
    } while (input != 10); // will run while input is not 10
    return 0;
}