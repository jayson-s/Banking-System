#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "MoneyMoves.h"
#include "Account.h"

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