#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Session.h"

std::string Session::login() {
    if (loggedIn) {
        std::cerr << "Error: A user is already logged in." << std::endl;
        return "";
    }

    std::string userType;
    std::string username;
    std::string password;

    std::cout << "Enter login type (admin/standard): ";
    std::cin >> userType;

    if (userType != "admin" && userType != "standard") {
        std::cerr << "Invalid login type!" << std::endl;
        return "";
    }

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Validate credentials from a file (e.g., Users.txt)
    std::ifstream userFile("Users.txt");
    if (!userFile.is_open()) {
        throw std::runtime_error("Error: Unable to open user file for authentication.");
    }

    std::string line;
    bool authenticated = false;
    while (std::getline(userFile, line)) {
        std::istringstream stream(line);
        std::string fileType, fileUsername, filePassword;

        std::getline(stream, fileType, ',');
        std::getline(stream, fileUsername, ',');
        std::getline(stream, filePassword, ',');

        if (fileType == userType && fileUsername == username && filePassword == password) {
            authenticated = true;
            break;
        }
    }

    userFile.close();

    if (authenticated) {
        loggedIn = true;
        loggedInUser = username;
        std::cout << "Login successful!" << std::endl;
        return userType;
    } else {
        std::cerr << "Invalid username or password." << std::endl;
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
    std::cout << "Logout successful." << std::endl;
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