#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AdminTask.h"

void AdminTask::saveAccountToFile(const std::string& accountDetails) const {
    std::ofstream accounts("CurrentBankAccounts.txt", std::ios::app);
    if (!accounts.is_open()) {
        throw std::runtime_error("Error: Unable to open accounts file for writing.");
    }
    accounts << accountDetails << std::endl;
}

void AdminTask::deleteAccountFromFile(const std::string& accountNumber) const {
    std::ifstream inputFile("CurrentBankAccounts.txt");
    std::ofstream tempFile("TempAccounts.txt");
    if (!inputFile.is_open() || !tempFile.is_open()) {
        throw std::runtime_error("Error: Unable to process accounts file.");
    }

    std::string line;
    bool accountDeleted = false;
    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        std::string accNumber;
        std::getline(stream, accNumber, ',');
        if (accNumber != accountNumber) {
            tempFile << line << std::endl;
        } else {
            accountDeleted = true;
        }
    }

    inputFile.close();
    tempFile.close();
    if (accountDeleted) {
        std::rename("TempAccounts.txt", "CurrentBankAccounts.txt");
    } else {
        std::remove("TempAccounts.txt");
        throw std::runtime_error("Error: Account not found.");
    }
}