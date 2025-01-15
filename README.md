# Banking-System

## About

The Banking System is a C++ project simulating the core functionalities of a modern banking application. It supports account management, financial transactions, and balance inquiries while ensuring data integrity and scalability.

## Features

- Account Management:
   - Create and delete accounts.
   - Toggle account status (e.g., enable/disable).
   - Switch between account types (e.g., standard or student plans).
- Transaction Processing:
   - Perform deposits, withdrawals, and fund transfers.
   - Pay bills directly from accounts.
   - Generate and log detailed transaction reports.
- Data Management:
   - Persistent file-based storage for accounts and transactions.
   - Real-time updates ensure accurate balance tracking.
- Error Handling:
   - Robust input validation and error recovery mechanisms.

## Getting Started

### Prerequisites:

To build and run this project, ensure you have the following:
- A C++17-compatible compiler (e.g., g++ or clang++).
- Make utility for building the project.

### Installation:

1. **Clone the repository**
   ```sh
   git clone https://github.com/jayson-s/BankingSystem.git
   cd BankingSystem

2. **Build the project**
   ```sh
   make

### Running the Project:

**Execute the main script**
  ```sh
  ./bin/banking_system
  ```

### Testing:

**Run automated tests to validate functionality:**
```sh
   make test
```
Tests are located in the input/ directory:
- in/: Input files for each operation.
- out/: Actual output files generated during testing.
- eout/: Expected output files.

## Project Highlights

- Advanced Design: Implements object-oriented programming principles, emphasizing scalability and modularity.
- Real-World Applications: Simulates realistic banking operations, such as bill payments and fund transfers.
- Error Resilience: Ensures stability through robust error-handling and input validation.