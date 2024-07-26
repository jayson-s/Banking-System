#pragma once
#include <string>

using namespace std;


class Session
{
public:
    string login();
    bool logout(string);
};