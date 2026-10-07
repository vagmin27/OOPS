#include<bits/stdc++.h>
using namespace std;

// Runtime polymorphism is the ability to call the appropriate overridden function based on the actual object type at runtime, usually achieved in C++ using virtual functions and base-class pointers/references.

class Scooty {
    // A class containing at least one pure virtual function is called an abstract class.
public:
    int price;
    int maxSpeed;
    int mileage;

    // without virtual, the function call is resolved based on the pointer/reference type
    // void sound() {
    //     cout << "Vroom Vroom" << endl;
    // }

    // A virtual function is a member function of a base class that can be overridden in a derived class. When called using a base-class pointer or reference, the overridden function is selected at runtime.
    // It is mainly used to achieve runtime polymorphism.
    // Runtime polymorphism means that the function to be executed is decided at runtime based on the actual object type.
    // It is basically a base-class function that allows the derived-class overridden function to be called through a base-class pointer/reference at runtime.
    
    virtual void sound() {
        // // virtual is generally used in the base class
        // A virtual function does not have to be pure virtual.
        cout << "Vroom Vroom" << endl;
    }
    // **** Constructors cannot be virtual because the constructor is responsible for creating the object, and virtual dispatch requires an object to already exist.

    virtual ~Scooty() {
        // base class should often have a virtual destructor when it is intended to be used polymorphically.
        // A virtual destructor ensures that the derived-class destructor is properly called.
    }

    // A static function belongs to the class rather than to a particular object, while virtual dispatch works with objects so.. Static functions can't be virtual.

    // So a virtual function can be overloaded
    virtual void sound() {
        cout << "Vroooommmm" << endl;
    }
};

class Bike : public Scooty {
public:
    int gears;
    // override tells the compiler that intends to override a virtual function from the base class
    // "override" is recommended because the compiler can detect mistakes.
    void sound() override {
        cout << "Droom Droom" << endl;
    }

    // void sound() { //This is also valid 
    //     cout << "Droom Droom" << endl;
    // }
};

// If a derived class doesn't override a pure virtual function the derived class also becomes abstract
// Late binding means the function call is resolved at runtime rather than compile time. Virtual functions enable late/dynamic binding
class SuperBike : public Scooty {
public:
// Early binding means the function call is resolved at compile time Non-virtual functions generally use early/static binding.
    void sound() override {
        cout << "Zroom Zroom" << endl;
    }
};

class Apple {
public:
    // // A virtual function can be private, protected, or public
    // This is a pure virtual function
    virtual void color() = 0; // This means the derived class is expected to provide an implementation.
};

int main() {
    Scooty *s = new Scooty();
    s->sound();
    // // Virtual behavior becomes particularly important when using a base-class pointer/reference
    // the pointer itself is already of type Bike, so there is no need for runtime polymorphism to select Bike's overridden function
    // Bike *b = new Bike();
    // b.sound();
    // SuperBike *sup = new Scooty();
    // sup.sound();

    // Because sound() is virtual... looks at the actual object type at runtime and calls Child::sound()
    Scooty *b = new Bike(); // With a virtual function, Bike's function is called.
    b->sound();
    // we have a base-class pointer, so virtual functions provide runtime polymorphism
    Scooty *sup = new SuperBike();
    sup->sound();

    // You cannot create its object of an abstract class
    // Apple a;   // Error
    Apple *a; // But you can have a pointer:


    // Few Theoretical aspects of virtual
    // A vtable (virtual table) is a compiler-generated table typically used to support virtual function dispatch.
    // It contains information/pointers used to find the appropriate overridden virtual function.
    // You don't manually create or manage the vtable.
    // A vptr (virtual pointer) is typically a hidden pointer inside an object of a polymorphic class that points to the appropriate vtable.
    // The exact implementation is compiler-dependent, so we can't say that every C++ implementation must use a vptr/vtable.

}