#include <bits/stdc++.h>
using namespace std;

// Abstraction means hiding unnecessary implementation details and showing only the essential information or functionality to the user.

// In simple words: Abstraction = WHAT to show + WHAT to hide
// The user knows WHAT an object does, but does not necessarily need to know HOW it does it.
// When using an ATM, you can: Insert your card Enter PIN Withdraw money Check balance
// But you don't need to know the internal process such as: Connecting to the bank server Validating the account Checking the database Processing the transaction Updating the bank records
// The ATM hides these implementation details and exposes only the operations required by the user.

class Car {
private:
    // This is an internal implementation detail.
    // The user does not need to know how the engine is started.
    void startEngine() {
        cout << "Engine started" << endl;
    }

public:
    // This is the function exposed to the user.
    // The user only needs to know: startCar()
    // The user does not need to know that internally startEngine() is called.
    // So this function provides the required functionality while hiding the implementation details.
    void startCar() {
        startEngine();
        cout << "Car started" << endl;
    }
};

// Encapsulation means wrapping data and the functions that operate on that data together inside a single unit, usually a class.
// It also means controlling access to that data.
// Encapsulation = DATA + METHODS + ACCESS CONTROL
// If the data is directly accessible, it can lead to unwanted or invalid modifications. Therefore, we make the data PRIVATE.
// The outside world cannot directly access the private data.
// Instead, we provide public functions such as: setName(), getName(), setRollNo(), getRollNo()
// These functions provide controlled access to the private data.

class Student {
private:
    string name;
    int rollNo;

public:
    // Setter for name.
    // It is used to modify the private name variable.
    void setName(string n) {
        name = n;
    }
    // Getter for name.
    // It is used to access the private name variable.
    string getName() {
        return name;
    }
    // Setter for roll number.
    // It is used to modify the private rollNo variable.
    void setRollNo(int r) {
        rollNo = r;
    }
    // Getter for roll number.
    // It is used to access the private rollNo variable.
    int getRollNo() {
        return rollNo;
    }
};

// BankAccount demonstrates both Abstraction and Encapsulation.
// Encapsulation:
// accountHolder, accountNumber, balance and pin are private.
// They cannot be directly accessed from outside the class.
// Public functions provide controlled access to them.
// Abstraction:
// The user only needs to call functions such as:
// deposit(), withdraw(), getBalance()
// The user does not need to know how PIN validation,
// amount validation, balance modification and transaction
// recording are implemented internally.

class BankAccount {
private:
    string accountHolder;
    long long accountNumber;
    double balance;
    int pin;
    // This is an internal function used to validate the PIN.
    // It is private because the user does not need to call it directly.
    bool validatePIN(int enteredPin) {
        return enteredPin == pin;
    }

    // This function checks whether the transaction amount is valid.
    // It is kept private because it is an internal implementation detail.
    bool validateAmount(double amount) {
        return amount > 0;
    }
    // This function records a transaction internally.
    // The user does not need to know how the transaction is recorded.
    void recordTransaction(string type, double amount) {
        cout << "Transaction recorded: " << type << " of Rs. " << amount << endl;
    }

public:
    // Constructor used to initialize the private data members.
    BankAccount(string name, long long accNo, double initialBalance,int accountPin) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
        pin = accountPin;
    }
    // Deposit function is exposed to the user.
    // The user only needs to call deposit(amount).
    // The internal validation and balance modification are hidden.

    void deposit(double amount) {
        // Validate the amount internally.
        if (!validateAmount(amount)) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        // Modify the private balance.
        balance += amount;
        // Record the transaction internally.
        recordTransaction("Deposit", amount);
        cout << "Deposit successful!" << endl;
    }
    // Withdraw function is exposed to the user. The user only needs to provide the amount and PIN. All the internal processing is hidden from the user.

    void withdraw(double amount, int enteredPin) {
        // Validate the PIN internally.
        if (!validatePIN(enteredPin)) {
            cout << "Incorrect PIN!" << endl;
            return;
        }
        // Validate the withdrawal amount.
        if (!validateAmount(amount)) {
            cout << "Invalid withdrawal amount!" << endl;
            return;
        }
        // Check whether sufficient balance exists.
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        // Modify the private balance.
        balance -= amount;
        // Record the transaction internally.
        recordTransaction("Withdrawal", amount);
        cout << "Withdrawal successful!" << endl;
    }

    // Getter function provides controlled access to the private balance.
    double getBalance() {
        return balance;
    }

    // Public function used to display account details. It accesses the private data internally.
    void displayAccountDetails() {
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : Rs. " << balance << endl;
    }
};


int main() {
    // The user only calls: c.startCar()
    // The user does not need to know how the engine is started.
    // The internal function startEngine() is hidden from the user.
    // Therefore: startCar()    -> WHAT the user needs startEngine() -> HOW it is internally implemented
    Car c;
    c.startCar();
    // Student object demonstrating Encapsulation.
    Student s;
    // We use setter functions to modify private data.
    s.setName("Rahul");
    s.setRollNo(101);

    // We use getter functions to access private data.
    cout << "Name    : " << s.getName() << endl;
    cout << "Roll No : " << s.getRollNo() << endl;
    // BankAccount object demonstrating both Abstraction and Encapsulation.

    BankAccount account("Vagmin", 123456789, 50000, 1234);

    // We don't directly access the private variables. Instead, we use the public function.
    account.displayAccountDetails();
    cout << endl << "Depositing Rs. 10000" << endl;
    // The internal deposit implementation is hidden.
    account.deposit(10000);
    cout << "Current Balance: Rs. " << account.getBalance() << endl;
    cout << endl << "Withdrawing Rs. 5000" << endl;
    
    // The internal PIN validation and withdrawal process are hidden.
    account.withdraw(5000, 1234);
    cout << endl << "Withdrawal With Wrong PIN" << endl;
    // The user only provides the PIN. The actual PIN validation happens internally.
    account.withdraw(5000, 9999);
    cout << endl;
    cout << "Final Balance: Rs. " << account.getBalance() << endl;
    return 0;
}