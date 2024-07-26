#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "Account.h"

using namespace std;

//Constructor
//Retirieves account belonging to name & number and stores it in local variables
Account::Account(string number, string name)
{
    //declaring
    accountNumber = number;
    accountName = name;

    //scan file for needed info
    string line;
    fstream accounts;

    //accounts.open("CurrentBankAccounts.txt");

    if (accounts.is_open() || false)
    {
        while (getline(accounts, line))
        {
            //cout << line << '\n';
            if (line.substr(0, accountNumber.length()) == accountNumber && line.substr(6, 6 + accountName.length()) == accountName)
            {

                //set variables based on collected info
                currentBalance = stof(line.substr(28, 36));
                accountStatus = line[28];
                break;
            }
        }

        accounts.close();
    }
    else
    {
        cout << "Error! Unable to open file";
    }
}
//this constructor will be used for creating accounts
Account::Account(string name)
{
    //declaring
    accountName = name;
}

//returns error or creates new account in a transaction file
void Account::createAccount(string initialBalance)
{

    return;
    //, std::ios_base::app
    string line;
    fstream accounts("CurrentBankAccounts.txt", ios::app);
    int mostRecentAccountNumber = 0;

    if (accounts.is_open())
    {
        //getline(accounts, line);

        while (getline(accounts, line))
        {

            if (line.substr(6, 11) != "END_OF_FILE")
            {
                mostRecentAccountNumber = stoi(line.substr(0, 4));
            }
        }

        accounts << formatLineForFile(mostRecentAccountNumber, initialBalance, 'A');

        accounts.close();
    }
    else
    {
        cout << "Error. Unable to open file";
    }
}
//Sets account in file to deleted
//Adds X to account file
void Account::deleteAccount()
{
    return;

    string line;
    fstream accounts;
    accounts.open("CurrentBankAccounts.txt", ios::app);

    if (accounts.is_open())
    {

        while (getline(accounts, line))
        {
            if (line.substr(0, accountNumber.length()) == accountNumber && line.substr(6, 6 + accountName.length()) == accountName)
            {

                //set account status to X for deleted
                accounts << formatLineForFile(stoi(accountNumber), 0, 'X');
                break;
            }
        }

        accounts.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    //OPEN FILE AND CHANGE TO X
}
//Formats lines according to specificaton
//NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP
string Account::formatLineForFile(int num, string balance, char status)
{

    return "";
    string preZerosAccountNumber;
    int digitsInNum = int(log(num) + 1);

    for (int i = digitsInNum; i < 5; i++)
    {
        preZerosAccountNumber += " ";
    }

    string postZeros;
    for (int i = accountName.length(); i < 20; i++)
    {
        postZeros += " ";
    }

    string preZerosBalance;
    for (int i = balance.length(); i < 8; i++)
    {
        preZerosBalance += " ";
    }

    string fullyFormatted = preZerosAccountNumber + to_string(num) + " " + accountName + postZeros +
                            " " + status + " " + preZerosBalance + balance;

    return fullyFormatted;
}
//returns the current balance as a float
float Account::getBalance()
{
    return currentBalance;
}
//return if the account is disabled
bool Account::getIsDisabled()
{
    return accountStatus.compare("D") == 0;
}
//Return if the account number is accociated with a student plan
bool Account::getIsPlanTypeStudent()
{
    return false;
}
//returns if the account is deleted
bool Account::getIsAccountDeleted()
{
    return accountStatus.compare("X") == 0;
}

void Account::togglePlan()
{
}
void Account::toggleDisabledAccount()
{
}