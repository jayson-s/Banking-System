#include <iostream>
#include <string>
#include <fstream>
#include "Session.h"

using namespace std;

//logs in the user
//returns the session type if successful
//returns empty string iff error
string Session::login()
{
    string user;
    // string account;
    cout << "What would you like to login as:" << endl;
    cin >> user;

    // string user;
    string holderName;

    if (user.compare("standard") == 0)
    {
        cout << "Successfully logged in as Standard!!" << endl;
        

        cout << "What is your account holder name:" << endl;
        cin >> holderName;

        return "standard";

        
    }
    else if (user.compare("admin") == 0)
    {
        cout << "Successfully logged in as admin!!" << endl;
        return "admin";
    }
    else
    {
        cout << "!! Sorry that is an invalid session type !!" << endl;
        return "";
    }
}
//ends session
//returns true if successful
//returns false if error
bool Session::logout(string loggedInAs)
{
    if (loggedInAs.compare("") == 0)
    {
        cout << "!! you must login first !!" << endl;
        return false;
    }
    else
    {
        cout << "Successfully logged-out!!";
        return true;
    }
}
