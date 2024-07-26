#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
#include "AdminTask.h"

using namespace std;

//Creates a new Account
//Takes account type of logged in user as input
//returns error or craetes new account in a transaction file
void AdminTask::createAccount(string loggedInAs)
{
    
    //block user if logged in as standard
    if (!validateUserAsAdmin(loggedInAs))
    {
        return;
    }

    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string accountHolderName;
    cout << "Enter account holder name" << endl;
    cin >> accountHolderName;

    if (!validateAccountName(accountHolderName))
    {
        return;
    }

    //Get initial balance
    string initialBalance;
    cout << "Enter initial balance" << endl;
    cin >> initialBalance;

    if (!validateInitialBalance(initialBalance))
    {
        return;
    }

    //Account class takes care of setting up the account
    Account admin(accountHolderName);
    admin.createAccount(initialBalance);
    return;
}
//Deletes an account
void AdminTask::deleteAccount(string loggedInAs)
{
    return ;
    //block user if logged in as standard
    if (!validateUserAsAdmin(loggedInAs))
    {
        return;
    }

    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string accountHolderName;
    cout << "Enter account holder name" << endl;
    cin >> accountHolderName;

    if (!validateAccountName(accountHolderName))
    {
        return;
    }

    //Get initial balance
    string accountNumber;
    cout << "Enter account number" << endl;
    cin >> accountNumber;

    //will have to make sure that the balance is zero before deleting
    if (!validateAccountNumber(accountNumber))
    {
        return;
    }

    Account admin(accountNumber, accountHolderName);
    admin.deleteAccount();
}
//Toggles the disable account option
void AdminTask::disableAccount(string loggedInAs)
{
    return ;
    //block user if logged in as standard
    if (!validateUserAsAdmin(loggedInAs))
    {
        return;
    }

    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string accountHolderName;
    cout << "Enter account holder name" << endl;
    cin >> accountHolderName;

    if (!validateAccountName(accountHolderName))
    {
        return;
    }

    //Get initial balance
    string accountNumber;
    cout << "Enter account number" << endl;
    cin >> accountNumber;

    //will have to make sure that the balance is zero before deleting
    if (!validateAccountNumber(accountNumber))
    {
        return;
    }

    Account admin(accountNumber, accountHolderName);
    admin.toggleDisabledAccount();
}
//toggles the users plan type
void AdminTask::changePlan(string loggedInAs)
{
    return ;
    //block user if logged in as standard
    if (!validateUserAsAdmin(loggedInAs))
    {
        return;
    }

    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string accountHolderName;
    cout << "Enter account holder name" << endl;
    cin >> accountHolderName;

    if (!validateAccountName(accountHolderName))
    {
        return;
    }

    //Get initial balance
    string accountNumber;
    cout << "Enter account number" << endl;
    cin >> accountNumber;

    //will have to make sure that the balance is zero before deleting
    if (!validateAccountNumber(accountNumber))
    {
        return;
    }

    Account admin(accountNumber, accountHolderName);
    admin.togglePlan();
}

//Validates that user logged in as admin
bool AdminTask::validateUserAsAdmin(string loggedInAs)
{
    if (loggedInAs.compare("admin") == 0)
    {
        return true;
    }
    else if (loggedInAs.compare("standard") == 0)
    {
        cout << "Must be logged in as admin to use this feature" << endl;
        return false;
    }
    else
    {
        cout << "Must be logged in to use this feature" << endl;
        return false;
    }
}

//Validates that name is less then 20 chars but more then 0
bool AdminTask::validateAccountName(string name)
{
    //check length
    if (name.length() > 20 || name.length() < 1)
    {
        cout << "Name must be less then 20 characters" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

//Check to make sure initial balce is within proper range
bool AdminTask::validateInitialBalance(string balance)
{
    //99999.99
    float n;
    try
    {
        n = stof(balance);
   
    }
    catch (...)
    {
        cout << "Error. Must enter in a number";
        return false;
    }
    if (n <= 0 || n > 99999.99)
    {
        cout << "invalid number" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool AdminTask::validateAccountNumber(string accountNumber){
    return true;
}