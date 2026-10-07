#include<bits/stdc++.h>
using namespace std;
// Single inheritance is a type of inheritance in which one derived (child) class inherits properties and functions from only one base (parent) class.

class Scooty { //Base / Parent class
private:
    double bootSpace;
public:
    int speed;
    float mileage;
};

class Bike : public Scooty { // Derived / Child class
    // Here public Scooty specifies that Bike class inherits from its Parent Scooty class
    // It allows the child class to reuse the data members and member functions of the parent class.
public:
    int gears;
};

class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};
// The child class can reuse the functionality of the parent class.
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};
int main() {
    Scooty s;
    s.speed = 60;
    s.mileage = 30;
    //  Single inheritance allows one derived class to inherit from one base class, providing code reusability and allowing the derived class to extend the functionality of the base class.
    Bike b;
    b.speed = 100;
    b.mileage = 45.0;
    b.gears = 4;

    Dog d;
    d.eat();   // inherited function
    // Dog inherits the eat() function from Animal, so we can call: d.eat() without defining eat() again inside Dog.
    d.bark();  // own function
}