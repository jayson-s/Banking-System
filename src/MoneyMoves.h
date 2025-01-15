#pragma once

#include <string>

class MoneyMoves {
public:
    void withdrawal(const std::string& loggedInAs);
    void payBill(const std::string& loggedInAs);
    void transfer(const std::string& loggedInAs);
    void deposit(const std::string& loggedInAs);
    float getBalance(const std::string& accountName) const;

private:
    void logTransaction(const std::string& transactionDetails);
    bool validateCurrentBalance(float balance, float amount) const;
    bool validateDepositAmount(float amount) const;
};