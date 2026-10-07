#include <bits/stdc++.h>
using namespace std;

// Operator overloading allows us to give a special meaning to an existing operator when it is used with user-defined objects.
// Operator overloading is an example of compile-time polymorphism (static polymorphism).
// It makes operations on objects more natural and readable.
class Fraction {
public:
    int num;
    int den;

    void simplify() {
        int g = __gcd(abs(num), abs(den));
        num = num / g;
        den = den / g;
        // Keep denominator positive
        if (den < 0) {
            num = -num;
            den = -den;
            simplify();
        }
    }

    Fraction(int num, int den) {
        this->num = num;
        this->den = den;
    }

    void display() {
        cout << num << " / " << den << endl;
    }

    Fraction add(Fraction f) {
        int newNum = this->num * f.den + this->den * f.num;
        int newDen = this->den * f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }
    // We can't create a new operator we can only overload existing operators
    // Operator overloading can't change:
    // precedence
    // associativity
    // number of operands
    Fraction operator+(Fraction f) {
        // Here + is overloaded for the Fraction class.
        int newNum = this->num * f.den + this->den * f.num;
        int newDen = this->den * f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }

    Fraction operator-(Fraction f) {
        int newNum = this->num * f.den - this->den * f.num;
        int newDen = this->den * f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }

    Fraction operator*(Fraction f) {
        int newNum = this->num * f.num;
        int newDen = this->den * f.den;
        Fraction ans(newNum, newDen);
        return ans;
    }

    Fraction operator/(Fraction f) {
        int newNum = this->num * f.den;
        int newDen = this->den * f.num;
        Fraction ans(newNum, newDen);
        return ans;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    f1.display();
    f2.display();

    Fraction f = f1.add(f2);
    f.display();

    Fraction f3 = f1 + f2;
    f3.display();
    Fraction f4 = f1 - f2;
    f4.display();
    Fraction f5 = f1 * f2;
    f5.display();
    Fraction f6 = f1 / f2;
    f6.display();
}