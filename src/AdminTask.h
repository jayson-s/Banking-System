#pragma once

#include <string>

class AdminTask {
public:
    void createAccount(const std::string& loggedInAs);
    void deleteAccount(const std::string& loggedInAs);
    void disableAccount(const std::string& loggedInAs);
    void changePlan(const std::string& loggedInAs);

private:
    bool validateUserAsAdmin(const std::string& loggedInAs) const;
    void saveAccountToFile(const std::string& accountDetails) const;
    void deleteAccountFromFile(const std::string& accountNumber) const;
};