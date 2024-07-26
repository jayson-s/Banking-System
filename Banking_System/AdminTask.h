#pragma once

#include <string>
using namespace std;

/*
Class takes care of validation of inputs
-Only allows admin to do admin tasks
*/
class AdminTask
{
public:
    void createAccount(std::string loggedInAs);
    void deleteAccount(string loggedInAs);
    void disableAccount(string loggedInAs);
    void changePlan(string loggedInAs);

private:
    bool validateUserAsAdmin(string loggedInAs);
    bool validateAccountName(string name);
    bool validateInitialBalance(string balance);
    void saveToFile(string accountHolderName, string initialBalance, string transactionCode);
    //Maybe overload saveFile to work for all needs
    bool validateAccountNumber(string accountNumber);
    void getAccountInfo(string accountNumber); //change to returning info
    void editAccountInfo(string accountnumber);
};