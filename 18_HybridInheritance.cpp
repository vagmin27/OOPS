#include <bits/stdc++.h>
using namespace std;
// Hybrid inheritance is not a completely new inheritance mechanism.
// It simply means that multiple inheritance patterns are combined in one class hierarchy.
// The most important issue associated with hybrid inheritance is the Diamond Problem, which can be solved using virtual inheritance.
class Person {
public:
    string name;
};
// Hybrid inheritance is a combination of two or more types of inheritance in a single program.

// For example, we can combine:
// Multiple inheritance
// Multilevel inheritance
// Hierarchical inheritance
class Student : virtual public Person {
public:
    int rollNo;
};

class Employee : virtual public Person {
public:
    int employeeId;
};

class Manager : public Student, public Employee {
public:
    int salary;
};

int main() {
    // If a class eventually inherits through both of these paths, keep only one shared copy of Person
    Manager m;
    m.name = "Vagmin";
    m.rollNo = 23118023;
    m.employeeId = 5001;
    m.salary = 50000;

    cout << "Name: " << m.name << endl;
    cout << "Roll No: " << m.rollNo << endl;
    cout << "Employee ID: " << m.employeeId << endl;
    cout << "Salary: " << m.salary << endl;

    return 0;
}