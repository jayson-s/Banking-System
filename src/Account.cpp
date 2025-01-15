#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdio>
#include "Account.h"

// Constructor: Initialize with account holder's name
Account::Account(const std::string &name)
    : accountHolderName(name), balance(0.0), disabled(false), studentPlan(false)
{
    accountNumber = generateAccountNumber();
}

// Constructor: Initialize with account number and name
Account::Account(const std::string &number, const std::string &name)
    : accountNumber(number), accountHolderName(name)
{
    std::ifstream accounts("CurrentBankAccounts.txt");
    if (!accounts.is_open())
    {
        throw std::runtime_error("Error: Unable to open accounts file.");
    }

    std::string line;
    bool accountFound = false;
    while (std::getline(accounts, line))
    {
        std::istringstream stream(line);
        std::string accNumber, accName;
        float balance;
        bool disabled, studentPlan;

        std::getline(stream, accNumber, ',');
        std::getline(stream, accName, ',');
        stream >> balance >> disabled >> studentPlan;

        if (accNumber == accountNumber && accName == accountHolderName)
        {
            this->balance = balance;
            this->disabled = disabled;
            this->studentPlan = studentPlan;
            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        throw std::runtime_error("Error: Account not found.");
    }
}

// Create a new account with an initial balance
void Account::createAccount(float initialBalance)
{
    if (initialBalance < 0)
    {
        throw std::invalid_argument("Error: Initial balance cannot be negative.");
    }
    balance = initialBalance;
    std::ofstream accounts("CurrentBankAccounts.txt", std::ios::app);
    if (!accounts.is_open())
    {
        throw std::runtime_error("Error: Unable to open accounts file for writing.");
    }
    accounts << accountNumber << "," << accountHolderName << "," << balance << ",0,0\n";
}

// Update account balance in the file
void Account::updateAccountBalance(float newBalance)
{
    std::ifstream inputFile("CurrentBankAccounts.txt");
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Error: Unable to open accounts file.");
    }

    std::ofstream tempFile("TempAccounts.txt");
    if (!tempFile.is_open())
    {
        throw std::runtime_error("Error: Unable to create temporary accounts file.");
    }

    std::string line;
    bool accountUpdated = false;
    while (std::getline(inputFile, line))
    {
        std::istringstream stream(line);
        std::string accNumber;
        std::getline(stream, accNumber, ',');

        if (accNumber == accountNumber)
        {
            tempFile << accountNumber << "," << accountHolderName << "," << newBalance << ",0,0\n";
            accountUpdated = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    if (!accountUpdated)
    {
        throw std::runtime_error("Error: Account not found.");
    }

    if (std::remove("CurrentBankAccounts.txt") != 0 || std::rename("TempAccounts.txt", "CurrentBankAccounts.txt") != 0)
    {
        throw std::runtime_error("Error: Unable to update accounts file.");
    }
}

// Generate a unique account number
std::string Account::generateAccountNumber() const
{
    static int counter = 1000;
    return "ACC" + std::to_string(counter++);
}

// Delete an account from the file
void Account::deleteAccount() {
    std::ifstream inputFile("CurrentBankAccounts.txt");
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: Unable to open accounts file.");
    }

    std::ofstream tempFile("TempAccounts.txt");
    if (!tempFile.is_open()) {
        throw std::runtime_error("Error: Unable to create temporary accounts file.");
    }

    std::string line;
    bool accountDeleted = false;
    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        std::string accNumber;
        std::getline(stream, accNumber, ',');

        if (accNumber != accountNumber) {
            tempFile << line << "\n";
        } else {
            accountDeleted = true;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!accountDeleted) {
        throw std::runtime_error("Error: Account not found.");
    }

    if (std::remove("CurrentBankAccounts.txt") != 0 || std::rename("TempAccounts.txt", "CurrentBankAccounts.txt") != 0) {
        throw std::runtime_error("Error: Unable to update accounts file.");
    }
}

float Account::getBalance() const {
    return balance;
}

// Toggle the disabled status of an account
void Account::toggleDisabledAccount() {
    disabled = !disabled;
    updateAccountBalance(balance); // Rewrites account data with updated status
}

// Toggle the account plan (e.g., student plan)
void Account::togglePlan() {
    studentPlan = !studentPlan;
    updateAccountBalance(balance); // Rewrites account data with updated plan
}

// Check if the account is disabled
bool Account::isDisabled() const {
    return disabled;
}

// Check if the account is on a student plan
bool Account::isStudentPlan() const {
    return studentPlan;
}