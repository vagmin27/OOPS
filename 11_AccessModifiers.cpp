#include <bits/stdc++.h>
using namespace std;

// Access modifiers are keywords used in a class to control the accessibility of its data members and member functions.
// They are an important part of data hiding and encapsulation in OOP.
class Student {
    // 1. Private:
    // If no access modifier is specified in a class, its members are private by default.
    // private is an access modifier that restricts access to class members.
    // A private member can be accessed only from within the same class.
    // The main purpose of private is data hiding. It prevents outside code from directly modifying important data.
    string name;
    int rollNo;
    float cgpa;
    // They can be accessed only from inside the Student class.
    // They can be directly accessed by functions that belong to the Student class.
public:
    void display() {
        cout << name << endl;
        cout << rollNo << endl;
        cout << cgpa << endl;
    }
};

// For a struct. The default is public.
struct Student {
    string name;
    int rollNo;
    float cgpa;
};

// is equivalent to:

struct Student {
public:
    string name;
    int rollNo;
    float cgpa;
};

class Students {
    // 2. Public:
    // public is an access modifier that allows class members to be accessed from anywhere where the object is accessible.
    // they can be accessed directly using an object
    // public is generally used for the interface of a class.
    // Public members are the things that we allow the outside world to interact with. The outside code interacts with the class through the public functions.
    // a class may keep its data private but provide public functions to interact with that data.
public:
    // public members can be accessed from anywhere, including outside the class using an object.
    string name;
    int rollNo;
    float cgpa;

protected:
    // protected members can be accessed:
    // Inside the same class
    // Inside derived/child classes
    // Not directly through an object from outside
    string names;
    int rNo;
};
int main() {
    // private protects the internal data of a class, while public provides the accessible interface through which outside code can interact with the class.
    Student s;
    // s.name = "Vagmin";   // Error
    // s.rollNo = 101;     // Error

    // Members declared under public: can be accessed from anywhere using the object.
    Students stds;
    // Here, name, rollNo, and cgpa are publicly accessible.
    stds.name = "Vagmin";
    stds.rollNo = 23118023;
    stds.cgpa = 9.73;
    cout << stds.name;
}