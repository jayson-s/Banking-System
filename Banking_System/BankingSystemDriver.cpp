#include <iostream>
#include <string>
#include "AdminTask.h"
#include "MoneyMoves.h"
#include "Session.h"
#include <fstream>
#include <vector>

using namespace std;

string loggedInAs = "";
bool loggedOut = false; //end session

int main(int argc, char *argv[])
{
    //Initialize helper classes
    AdminTask admin;
    MoneyMoves money;
    Session session;

    cout << "Hi Welcome to the Banking System" << endl;

    //open input file
    //Create array with commands
    //create file in ../output/text/HERE directory
    //name of the file should be same as input file except with .out extenstion
    //ex test1.in -> test1.out
    //pass name of newly created file to all functions. Replace cout with appending to that file
    
    while (!loggedOut)
    {

        //string input = commands[counter];
        // counter++;
        // cout << input;
        string input;
        cin >> input;   

        //input.compare returns 0 if the stirngs are the same
        if (input.compare("login") == 0)
        {
            //cout << input << endl;
            //loggedInAs = ...
            if (loggedInAs.compare("standard") == 0 || loggedInAs.compare("admin") == 0)
            {
                cout << "!! YOU ARE ALREADY LOGGED IN !!" << endl;
            }
            else
            {
                loggedInAs = session.login();
            }
        }
        else if (input.compare("logout") == 0)
        {
            loggedOut = session.logout(loggedInAs);
        }
        else if (input.compare("create") == 0)
        {
            admin.createAccount(loggedInAs);
        }
        else if (input.compare("delete") == 0) 
        {
            admin.deleteAccount(loggedInAs);
        }
        else if (input.compare("disable") == 0)
        {
            admin.disableAccount(loggedInAs);
        }
        else if (input.compare("changeplan") == 0)
        {
            admin.changePlan(loggedInAs);
        }
        else if (input.compare("transfer") == 0)
        {
            money.transfer(loggedInAs);
        }
        else if (input.compare("paybill") == 0)
        {
            money.paybill(loggedInAs);
        }
        else if (input.compare("deposit") == 0)
        {
            money.deposit(loggedInAs);
        }
        else if (input.compare("withdrawl") == 0)
        {
            money.withdrawal(loggedInAs);
        }
        else
        {
            cout << "!! you must login first !!" << endl;
        }
    }

    return 0;
}