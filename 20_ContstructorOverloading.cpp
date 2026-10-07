#include <bits/stdc++.h>
using namespace std;

// Constructor overloading means having multiple constructors in the same class with different parameter lists.
// The compiler decides which constructor to call based on the number or type of arguments passed while creating the object.
// Constructor overloading is a feature of C++ in which a class contains multiple constructors with different parameter lists, allowing objects to be initialized in different ways.
// It allows us to initialize objects in different ways.
class Maths {
public:
    // Default constructor
    Maths() {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor with 2 arguments
    Maths(int a, int b) {
        cout << "Product is: " << a * b << endl;
    }

    // Parameterized constructor with 3 arguments
    Maths(int a, int b, int c) {
        cout << "Sum is: " << a + b + c << endl;
    }
};

int main() {
    // A class can have multiple constructors with the same name as the class, as long as their parameter lists are different.
    // The compiler decides which constructor to call based on the number and types of arguments.
    Maths m;            // Calls Maths()
    // Constructors are automatically called during object creation and cannot be called like normal member functions.
    // This is different from function overloading, where you can create one object and call different overloaded functions using different arguments.

    // You cannot do:
    // Maths m;
    // m(10, 15);
    // because m is an object, not a function. Writing m(...) attempts to call the object like a function, which would require an overloaded operator()
    
    Maths m1(10, 15);   // Calls Maths(int, int)
    Maths m2(10, 15, 20); // Calls Maths(int, int, int)
    return 0;
}