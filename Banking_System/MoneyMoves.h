#pragma once
#include <string>

using namespace std;

/*
Takes care of standard user commands
*/
class MoneyMoves
{
public:
    float amount;
    float currentBalance;
    string accountHolderName;
    string billName;

    void withdrawal(string loggedInAs);
    void paybill(string loggedInAs);
    void transfer(string loggedInAs);
    void deposit(string loggedInAs);
    float getBalance(string accountName);

private:
    bool validateCurrentBalance(float, float);
    bool validateDepositAmount(float);
    bool validateUserAsAdmin(string);
    bool validateAccountName(string);
    bool validateBillName(string);
    bool validatePaymentAmount(float);
    float getBalance();
};