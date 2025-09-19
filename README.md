# BankAccount Class

A C++ class for making and editing a bank account.

## Data Dictionary
| Attribute | Data Type | Description |
|----------|----------|----------|
| `accountNumber` | `string` | Holds the accounts account number. |
| `accountHolderName` | `string` | Holds the accounts account holder name. |
| `balance` | `double` | Holds the accounts balance. |

## Methods List

| Method Signature | Return Type | Description |
|----------|----------|----------|
| `BankAccount()` | (Constructor) | Default constructor. |
| `BankAccount(acountNum, HolderName, bal)` | (Constructor) | Parameterized constructor. |
| `getAccountNumber()` | `string` | Gets the accounts number. |
| `getAccountHolderName()` | `string` | Gets the accounts account holder name. |
| `getBalance()` | `double` | Gets the account balance. |
| `setAccountHolderName(accountHoldName)` | `void` | Sets the account holder name. |
| `deposit(amount)` | `double` | Deposits money into an account. |
| `withdraw(amount)` | `double` | Withdraws money from a account. |