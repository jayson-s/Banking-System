#include <iostream>
#include <string>
#include <stdexcept>
#include "Session.h"

std::string Session::login() {
    if (loggedIn) {
        std::cerr << "Error: A user is already logged in." << std::endl;
        return "";
    }

    std::string userType;
    std::cout << "Enter login type (admin/standard): ";
    std::cin >> userType;

    if (userType == "admin" || userType == "standard") {
        loggedIn = true;
        loggedInUser = userType;
        return userType;
    } else {
        std::cerr << "Invalid login type!" << std::endl;
        return "";
    }
}

bool Session::logout() {
    if (!loggedIn) {
        std::cerr << "Error: No user is currently logged in." << std::endl;
        return false;
    }
    loggedIn = false;
    loggedInUser.clear();
    return true;
}

bool Session::isLoggedIn() const {
    return loggedIn;
}

const std::string& Session::getLoggedInUser() const {
    if (!loggedIn) {
        throw std::runtime_error("No user is logged in.");
    }
    return loggedInUser;
}