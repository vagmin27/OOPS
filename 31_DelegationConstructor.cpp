
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double cgpa;

public:
    // 1. TARGET CONSTRUCTOR
    // Performs the actual initialization of all data members.
    Student(string n, int a, double c)
        : name(n), age(a), cgpa(c) {
        cout << "Parameterized constructor called\n";
    }

    // 2. DELEGATING CONSTRUCTOR
    // Delegates initialization to the 3-parameter constructor.
    // The constructor call appears in the member initializer list.
    Student(string n, int a)
        : Student(n, a, 0.0) {
        cout << "Two-parameter constructor called\n";
    }

    // 3. ANOTHER DELEGATING CONSTRUCTOR
    // Delegates to the 2-parameter constructor, which in turn delegates to the 3-parameter constructor.
    Student(string n)
        : Student(n, 18, 0.0) {
        cout << "One-parameter constructor called\n";
    }

    // 4. DEFAULT CONSTRUCTOR
    // Delegates to the target constructor with default values.
    Student()
        : Student("Unknown", 18, 0.0) {
        cout << "Default constructor called\n";
    }

    void display() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "CGPA: " << cgpa << "\n\n";
    }
};

int main() {
    // Calls the 3-parameter constructor directly.
    Student s1("Aman", 20, 9.5);
    s1.display();

    // Calls the 2-parameter constructor, which delegates to the 3-parameter constructor first.
    Student s2("Riya", 19);
    s2.display();

    // Calls the 1-parameter constructor, which delegates through the 2-parameter constructor to the 3-parameter constructor.
    Student s3("Rahul");
    s3.display();

    // Calls the default constructor, which delegates to the 3-parameter constructor.
    Student s4;
    s4.display();

    return 0;
}
