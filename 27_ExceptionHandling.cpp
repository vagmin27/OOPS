#include <bits/stdc++.h>
using namespace std;

// Exception handling is a mechanism used to handle runtime errors without abruptly terminating the program.
// Basic causes of exception are:
    // 1. Division by zero
    // 2. Invalid input
    // 3. File not found
    // 4. Insufficient resources
    // 5. Invalid array/index operations
class BankAccount {
private:
    int balance;

public:
    BankAccount(int b) {
        balance = b;
    }
    // the function where the error occurs doesn't necessarily have to handle it. It can throw the exception, and another function can catch it.
    void withdraw(int amount) {
        if (amount > balance) {
            // Used to generate/raise an exception.
            throw "Insufficient balance";
        }

        balance -= amount;
        cout << "Withdrawal successful\n";
    }
};
// Exception handling separates normal program logic from error-handling logic.
int main() {
    BankAccount account(5000);
    // The code that might cause an exception is placed inside try.
    try {
        account.withdraw(7000);
    }
    // If throw is executed, the remaining statements inside the try block are skipped, and C++ searches for a matching catch.
    // Used to handle the exception.
    catch (const char* msg) {
        cout << msg;
    }
    
    // Multiple catch blocks You can handle different types of exceptions
    // Only the first matching catch is executed.
    try {
        throw 10;
    }
    catch (int x) {
        cout << "Integer exception";
    }
    catch (double x) {
        cout << "Double exception";
    }
    catch (const char* x) {
        cout << "String exception";
    }
    return 0;
}