#include <bits/stdc++.h>
using namespace std;

// A class becomes abstract if it contains at least one pure virtual function
// An abstract class is a class that contains at least one pure virtual function and cannot be instantiated.
class Animal {
public:
    // An abstract class is a class containing at least one pure virtual function, which cannot be instantiated and is generally used to provide a common interface for derived classes
    virtual void sound() = 0; // A virtual function declared with = 0 is called a pure virtual function.
    // An abstract class acn have a constructor, data members, normal functions, pointer/reference of an abstract class
    // C++ achieves interface-like behavior using abstract classes and pure virtual functions.
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow" << endl;
    }
};

int main() {
    // Even though we cannot create an Animal object directly, its constructor is called when a derived object is created.
    Dog d;
    d.sound();
    Cat c;
    c.sound();
    // The pointer can point to an object of a derived concrete class.
}