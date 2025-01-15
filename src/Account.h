#pragma once

#include <string>

class Account {
public:
    Account(const std::string& name);
    Account(const std::string& number, const std::string& name);

    void createAccount(float initialBalance);
    void updateAccountBalance(float newBalance);
    void deleteAccount();
    void toggleDisabledAccount();
    void togglePlan();

    float getBalance() const;
    bool isDisabled() const;
    bool isStudentPlan() const;
    const std::string& getAccountNumber() const;
    const std::string& getAccountHolderName() const;

private:
    std::string accountNumber;
    std::string accountHolderName;
    float balance;
    bool disabled;
    bool studentPlan;

    std::string generateAccountNumber() const;
};