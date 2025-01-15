#include <iostream>
#include "MoneyMoves.h"
#include "Account.h"

void MoneyMoves::makeTransaction() {
    std::cout << "Transaction Options:\n";
    std::cout << "1. Deposit\n";
    std::cout << "2. Withdraw\n";
    std::cout << "3. Transfer\n";
    std::cout << "4. Pay Bill\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    std::string accountHolderName;
    std::cout << "Enter account holder's name: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);

    try {
        Account account(accountHolderName);

        switch (choice) {
            case 1: {
                float amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.updateAccountBalance(account.getBalance() + amount);
                std::cout << "Deposit successful.\n";
                break;
            }
            case 2: {
                float amount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                if (account.getBalance() < amount) {
                    std::cout << "Insufficient funds.\n";
                } else {
                    account.updateAccountBalance(account.getBalance() - amount);
                    std::cout << "Withdrawal successful.\n";
                }
                break;
            }
            case 3: {
                std::string targetAccountName;
                float amount;
                std::cout << "Enter target account holder's name: ";
                std::cin.ignore();
                std::getline(std::cin, targetAccountName);
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                if (account.getBalance() < amount) {
                    std::cout << "Insufficient funds.\n";
                } else {
                    Account targetAccount(targetAccountName);
                    account.updateAccountBalance(account.getBalance() - amount);
                    targetAccount.updateAccountBalance(targetAccount.getBalance() + amount);
                    std::cout << "Transfer successful.\n";
                }
                break;
            }
            case 4: {
                std::string biller;
                float amount;
                std::cout << "Enter biller name: ";
                std::cin.ignore();
                std::getline(std::cin, biller);
                std::cout << "Enter amount to pay: ";
                std::cin >> amount;
                if (account.getBalance() < amount) {
                    std::cout << "Insufficient funds.\n";
                } else {
                    account.updateAccountBalance(account.getBalance() - amount);
                    std::cout << "Bill paid successfully.\n";
                }
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void MoneyMoves::logTransaction(const std::string& transactionDetails) {
    std::ofstream transactionFile("BankAccountTransaction.txt", std::ios::app);
    if (!transactionFile.is_open()) {
        throw std::runtime_error("Error: Unable to open transaction file for writing.");
    }
    transactionFile << transactionDetails << std::endl;
}

void MoneyMoves::deposit(const std::string& loggedInAs) {
    float amount;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    if (!validateDepositAmount(amount)) {
        std::cerr << "Error: Invalid deposit amount." << std::endl;
        return;
    }

    Account account(loggedInAs, loggedInAs);
    float balance = account.getBalance();
    balance += amount;
    account.updateAccountBalance(balance);

    std::ostringstream transactionDetails;
    transactionDetails << loggedInAs << ",deposit," << amount << "," << balance;
    logTransaction(transactionDetails.str());
}
