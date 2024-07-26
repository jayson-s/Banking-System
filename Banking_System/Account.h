#pragma once

#include <string>
using namespace std;

/*
Class takes care of lower level file editing for transactions
-data coming to the class is already filtered by AdminTask
*/
class Account
{
public:
    Account(string name);
    Account(string number, string name);

    void createAccount(string initialBalance);
    void deleteAccount();
    void toggleDisabledAccount();
    void togglePlan();

    //accessors
    float getBalance();
    bool getIsDisabled();
    bool getIsPlanTypeStudent();
    bool getIsAccountDeleted();

private:
    string accountNumber;
    string accountName;
    float currentBalance;
    string accountStatus;
    string formatLineForFile(int num, string initialAccountBalance, char status);
};