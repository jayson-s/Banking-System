#pragma once

#include <string>

class Session {
public:
    std::string login();
    bool logout();
    bool isLoggedIn() const;
    const std::string& getLoggedInUser() const;

private:
    bool loggedIn = false;
    std::string loggedInUser;
};