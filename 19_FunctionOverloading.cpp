#include <bits/stdc++.h>
using namespace std;
// Function overloading happens when multiple functions can have the same name but different parameter lists.
// It allows us to perform similar operations using the same function name, instead of creating different names for each function.
// Function overloading is an example of compile-time polymorphism.
// polymorphism allows the same name/interface to behave differently in different situations.
// In function overloading, the compiler decides at compile time which function should be called.
// The main purpose is to allow one meaningful name to represent similar operations with different inputs. This improves readability, consistency, and maintainability.

class Maths {

    // We can overload a function by changing:
        // 1. Number of parameters
        // 2. Type of parameters
        // 3. Order of parameters
public:
    // we have two functions with the same name sum(), but their parameter lists are different
    int sum(int a, int b) {
        cout << "The sum of two numbers is: " << a + b << endl;
        return a + b;
    }
    // The function name sum is given multiple meanings depending on the arguments passed to it.
    int sum(int a, int b, int c) {
        cout << "The sum of three numbers is: " << a + b + c << endl;
        return a + b + c;
    }
    // The return type alone cannot be used for function overloading.
    // The compiler cannot determine which function to call based only on the return type.
    // float(int a, int b) { // This is not valid overloading because the parameter lists are exactly the same
    //     return a + b;
    // }

    float sum(float a, float b) {
        // Here the parameter types are different. This is accepted
        return a + b;
    }
    // The order of parameter types is different.
    int sum(int a, float b) {
        return (int)(a + b);
    }
    int sum(float a, int b) {
        return (int)(a + b);
    }
};
// Static functions can be overloaded as long as their parameter lists are different.
// a member function and a non-member function have the same name because they belong to different scopes.
void display() {
    cout << "Global";
}

class Test {
public:
    void display() {
        cout << "Member";
    }
    // They can have different access modifiers, although access control affects whether the function can be called from a particular context.
public:
    void show(int x) {}

private:
    void show(double x) {}
};

// The programmer can understand that all functions perform the same general operation.
// The appropriate function is selected by the compiler based on the arguments.
// Related operations can be grouped under one meaningful function name.


// Simply Function overloading is a compile-time polymorphism feature in C++ that allows multiple functions to have the same name but different parameter lists, with the compiler selecting the appropriate function based on the arguments.

void fun(int& x) {
    cout << "Non-const reference" << endl;
}

void fun(const int& x) {
    cout << "Const reference" << endl;
}

int main() {
    // This is called function overloading
    // The compiler decides which sum() function to call based on the number and/or type of arguments passed.
    Maths m;
    // both functions are named sum(), but they have different numbers of parameters.
    m.sum(5, 10); // When a function is called, the compiler determines which overloaded function should be executed by looking at its arguments.
    m.sum(5, 10, 15);
    // the compiler determines which overloaded function should be called at compile time, based on the arguments passed to the function.
    // m.sum(4, 4.5);
    // m.sum(5.6, 9);

    int a = 10;
    const int b = 20;
    // For function overloading, changing top-level const on a value parameter doesn't matter, but changing the type through a reference or pointer can matter.
    fun(a);
    fun(b);
}