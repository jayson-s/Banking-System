#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "AdminTask.h"
#include "Account.h"

void AdminTask::performAdminTask() {
    std::cout << "Admin Task Options:\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Delete Account\n";
    std::cout << "3. Disable Account\n";
    std::cout << "4. Change Plan\n";
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
                float initialBalance;
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                account.createAccount(initialBalance);
                std::cout << "Account created successfully.\n";
                break;
            }
            case 2: {
                account.deleteAccount();
                std::cout << "Account deleted successfully.\n";
                break;
            }
            case 3: {
                account.toggleDisabledAccount();
                std::cout << "Account status toggled successfully.\n";
                break;
            }
            case 4: {
                account.togglePlan();
                std::cout << "Account plan changed successfully.\n";
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

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