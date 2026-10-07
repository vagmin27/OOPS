#include <bits/stdc++.h>
using namespace std;
// The Scope Resolution Operator (::) is used to specify the scope to which a variable or function belongs.
// Common Uses

class Student {
public:
    void display();
    static int count;
};

int x = 100;    // Global variable
int Student::count = 10;

void Student::display() {
    // Here, Student::display() tells the compiler that display() belongs to the Student class.
    cout << "Hello Student";
}

namespace Math {
    int value = 20;
}

int main() {
    // 1. Define Member Functions Outside the Class
    Student s;
    s.display();
    // 2. Access Static Members
    cout << Student::count; // You can access a static member without creating an object.
    // 3. Access Global Variables
    cout << ::x << endl; //::x refers to the global variable x.
    // 4. Access Members of a Namespace
    cout << Math::value << endl; // Math::value refers to the value variable inside the Math namespace.
}