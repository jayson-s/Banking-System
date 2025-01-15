#include <iostream>
#include <string>
#include <memory>
#include "AdminTask.h"
#include "MoneyMoves.h"
#include "Session.h"

using namespace std;

class BankingSystem {
public:
    void run() {
        cout << "Welcome to the Modern Banking System!" << endl;

        unique_ptr<AdminTask> admin = make_unique<AdminTask>();
        unique_ptr<MoneyMoves> money = make_unique<MoneyMoves>();
        unique_ptr<Session> session = make_unique<Session>();

        bool running = true;

        while (running) {
            try {
                displayMenu();
                int choice = getUserChoice();

                switch (choice) {
                    case 1:
                        session->login();
                        break;
                    case 2:
                        admin->performAdminTask();
                        break;
                    case 3:
                        money->makeTransaction();
                        break;
                    case 4:
                        session->logout();
                        break;
                    case 5:
                        cout << "Thank you for using the Modern Banking System. Goodbye!" << endl;
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } catch (const exception &e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

private:
    void displayMenu() const {
        cout << "\nMain Menu:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Admin Task" << endl;
        cout << "3. Perform Transaction" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" << endl;
    }

    int getUserChoice() const {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter a number.");
        }

        return choice;
    }
};

int main() {
    try {
        BankingSystem system;
        system.run();
    } catch (const exception &e) {
        cerr << "Critical Error: " << e.what() << endl;
    }

    return 0;
}
