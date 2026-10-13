#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // 1. DEFAULT CONSTRUCTOR
    // Called when an object is created without arguments.
    Number() : value(0) {}

    // 2. CONVERSION CONSTRUCTOR
    // Accepts an int and creates a Number object.
    // Since it is not explicit, implicit conversion is allowed.
    Number(int x) : value(x) {
        cout << "Conversion constructor called\n";
    }

    // 3. CONVERSION CONSTRUCTOR WITH DEFAULT ARGUMENT
    // A constructor with multiple parameters can also act as a conversion constructor if all parameters after the first have default arguments.
    // Number(double x, int multiplier = 1)
    //     : value(static_cast<int>(x * multiplier)) {}

    // 4. COPY CONSTRUCTOR
    // Creates an object from another object of the SAME class. This is different from a conversion constructor.
    Number(const Number& other) : value(other.value) {
        cout << "Copy constructor called\n";
    }

    // 5. EXPLICIT CONVERSION CONSTRUCTOR
    // Uncomment this constructor instead of Number(int) above to prevent implicit conversions from int to Number.
    //  explicit Number(int x) : value(x) {}

    void display() const {
        cout << "Value = " << value << '\n';
    }
};

int main() {
    // A. DIRECT INITIALIZATION
    // Calls the conversion constructor directly.
    Number n1(10);
    n1.display();

    // B. DIRECT-LIST INITIALIZATION
    // Also calls the conversion constructor.
    Number n2{20};
    n2.display();

    // C. COPY INITIALIZATION
    // Implicitly converts int into Number.
    // Valid because Number(int) is not explicit.
    Number n3 = 30;
    n3.display();

    // D. IMPLICIT CONVERSION AFTER DECLARATION
    // A temporary Number object is created from 40, then assigned to n1 using the generated assignment operator.
    n1 = 40;
    n1.display();

    // E. CONVERSION IN A FUNCTION CALL
    // The int argument is implicitly converted into Number.
    auto printNumber = [](Number n) {
        n.display();
    };
    printNumber(50);

    // F. COPY CONSTRUCTOR
    // Initializes n4 from an existing Number object.
    Number n4(n1);
    n4.display();

    // G. EXPLICIT CONVERSION
    // Even with an explicit constructor, direct initialization remains valid.
    Number n5(60);
    n5.display();

    // Number n6 = 60; // Error if Number(int) is explicit.

    // H. STATIC CAST
    // Explicitly requests conversion to Number.
    Number n7 = static_cast<Number>(70);
    n7.display();

    // I. AMBIGUITY
    // If a class has multiple constructors that can accept the same source value through equally viable conversions, overload resolution can become ambiguous.
    // Example: constructors Number(long) and Number(double) may make Number n(10) ambiguous on common implementations.
    return 0;
}