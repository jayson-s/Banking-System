#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MoneyMoves.h"

using namespace std;

//function to retrieve current user's balance from account detail's file.
float MoneyMoves::getBalance(string accountName)
{
    string myText, line;
    ifstream ReadFile("transactionfile.txt");
    while (getline(ReadFile, myText))
    {
        line = myText;
    }
    /*
    //NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP
    */
    string arr[4];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 4)
    {
        ssin >> arr[i];
        ++i;
    }
    for (i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }
    ReadFile.close();
    int accountNumber = std::stoi(arr[0]);
    accountName = arr[1];
    string accountStatus = arr[2];
    float currentBalance = std::stof(arr[3]);
    return currentBalance;
}
//function to handle withdrawing funds from user's valid account
void MoneyMoves::withdrawal(string loggedInAs)
{
    return;
    //Ask for admin for holder name 
    if (loggedInAs == "admin")
    {
        //All inputs will be strings and later cast to ints if needed
        //Get name of account holder
        do {
            string accountHolderName;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            if(validateAccountName(accountHolderName)){
                break;
            }
            cout << "!! This is not a valid Account Holder Name !!\n"<< endl;
        } while(validateAccountName(accountHolderName) == false);
           
    }


    
    string accountNumber;
    cout << "Enter Account Holder number: " << endl;
    cin >> accountNumber;




    //Get withdrawal amount
    float withdrawalAmount;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawalAmount;
    if (!validateCurrentBalance(currentBalance, withdrawalAmount))
    {
        cout << "Error";
        return;
    }
    //SAVE TO FILE
    return ;
}
//function to handle depositing funds into user's valid account
void MoneyMoves::deposit(string loggedInAs)
{
    return ;
    //ASk admin for Holder Name
    if (loggedInAs == "admin")
    {
     do{
            string accountHolderName;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            if(validateAccountName(accountHolderName)){
                break;
            }
            cout << "Try Again "<< endl;
        } while(validateAccountName(accountHolderName) == false);
           
    }

    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string accountHolderNumber;
    cout << "Enter account holder number: ";
    cin >> accountHolderNumber;
    // if (!validateAccountName(accountHolderName))
    // {
    //     cout << "Error";
    //     return;
    // }

    //Get deposit amount
    float depositAmount;
    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    if (!validateDepositAmount(depositAmount))
    {
        cout << "Error";
        return;
    }

    //SAVE TO FILE

    cout << "Deposited !!" << endl; 
    return ;
}
//paybill function to handle paying bills to valid companies
void MoneyMoves::paybill(string loggedInAs)
{
    return;
 
    //ASk admin for Holder Name
    if (loggedInAs == "admin")
    {
     do{
            string accountHolderName;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            if(validateAccountName(accountHolderName)){
                break;
            }
            cout << "Try Again "<< endl;
        } while(validateAccountName(accountHolderName) == false);
           
    }

    string accountNumber;
    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;


    //All inputs will be strings and later cast to ints if needed
    //Get name of account holder
    string billName;
    cout << "Enter name of bill you want to pay";
    cin >> billName;
    if (!validateBillName(billName))
    {
        cout << "Error";
        return;
    }

    //Get paymount amount
    float paymentAmount;
    cout << "Enter payment amount";
    cin >> paymentAmount;
    if (!validatePaymentAmount(paymentAmount))
    {
        cout << "Error";
        return;
    }
    //SAVE TO FILE

    return ;
}
// transfer function to handle transferring funds to and from valid accounts
void MoneyMoves::transfer(string loggedInAs)        
{
    return;
    //block user if logged in as standard
    if (loggedInAs == "admin")
    {
     do{
            string accountHolderName;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            if(validateAccountName(accountHolderName)){
                break;
            }
            cout << "Try Again "<< endl;
        } while(validateAccountName(accountHolderName) == false);
           
    }
    
    string accountHolderNumber;
    cout << "Enter Account Holder Number: " ;
    cin >> accountHolderNumber;
    //Get transfer account number
    float transferAccountNum;
    cout << "Enter transfer account number: ";
    cin >> transferAccountNum;

    //Get transfer amount
    float transferAmount;
    cout << "Enter transfer amount:  ";
    cin >> transferAmount;
    if (transferAmount > 1000)
    {
        cout << "Error";
        return;
    }
    return ;
}
//validate current amount of available funds are greater than requested
bool MoneyMoves::validateCurrentBalance(float currentBalance, float withdrawalAmount)
{
    if (withdrawalAmount < currentBalance)
    {
        return true;
    }
    else
    {
        cout << "Not enough funds available in account." << endl;
    }
}
//validate amount of deposit to be a positive amount
bool MoneyMoves::validateDepositAmount(float depositAmount)
{
    if (depositAmount > 0)
    {
        return true;
    }
    else
    {
        cout << "Invalid amount to deposit." << endl;
    }
}
//validate amount of payment to be a positive amount
bool MoneyMoves::validatePaymentAmount(float paymentAmount)
{
    if (paymentAmount > 0)
    {
        return true;
    }
    else
    {
        cout << "Invalid payment amount." << endl;
    }
}
//validate current user login status & privilege
bool MoneyMoves::validateUserAsAdmin(string loggedInAs)
{
    if (loggedInAs == "admin")
    {
        return true;
    }
    else if (loggedInAs == "" || loggedInAs == "standard")
    {
        cout << "Must be logged in as admin to use this feature" << endl;
    }
}
//validate company number to paybill to
bool MoneyMoves::validateBillName(string billName)
{
    if (billName == "Company 1" || billName == "Company 2" || billName == "Company 3")
    {
        return true;
    }
    else
    {
        cout << "Invalid company number!" << endl;
    }
}

bool MoneyMoves::validateAccountName(string hello){
    return false;
}