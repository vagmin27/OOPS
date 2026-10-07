#include <bits/stdc++.h>
using namespace std;
// When a local variable and a global variable have the same name, the local variable gets higher priority inside its scope. The global variable becomes hidden.
// A variable declared outside all functions and classes is called a global variable.
// A variable declared inside a function or block is called a local variable.
// Priority Rule: Local Variable > Global Variable
//  So if both have the same name, the local variable is used.

int x = 100;

class Student {
    int age;
    int marks;
public:
    Student() {

    }
    void Age(int age) {
        age = age;
        // Here, both variables are named age. Left side age → parameter && Right side age → parameter.
    }
    void setAge(int age) {
        // The this keyword is a special pointer available inside every non-static member function of a class. It stores the address of the object that invoked the member function.
        // Non-static members belong to individual objects, so each object has its own copy.
        // Static members belong to the class, so only one copy exists and is shared by all objects.
        // Non-static member functions can access both static and non-static members because they have a this pointer.
        // Static member functions can access only static members directly because they do not have a this pointer
        this->age = age; // this is a pointer that points to the current object.
    }

    void display() {
        cout << "Age = " << age;
    }
    Student(int m) {
        marks = m;
    }
    void compare(Student &s) {
        if (marks > s.marks) {
            cout << "Current object has higher marks";
        } else {
            cout << "Passed object has higher marks";
        }
    }
    void compareWith(Student &s) {
        if (this->marks > s.marks)
            cout << "Current object has higher marks";
        else
            cout << "Passed object has higher marks";
    }
};

class Rectangle {
    int length, breadth;

public:
    void setData(int length, int breadth) {
        this->length = length; // this means the data member length of the current object
        this->breadth = breadth; // The -> operator is used because this is a pointer.
    }

    void display() {
        cout << length << " " << breadth;
    }
};

class Students {
    int marks;
    int age;
public:
    Students* setMarks(int m) {
        marks = m;
        return this; //this can be returned from a function.
    }
    void display() {
        cout << marks;
    }

    Students& setAge(int a) {
        age = a;
        return *this;
    }

    Students& show() {
        cout << age << endl;
        return *this;
    }
};
// Static vs Non-Static members
// The this keyword is a special pointer available inside every non-static member function of a class.It stores the address of the object that invoked the member function.
// It is automatically passed by the compiler to every non-static member function.
// Use static members when data or behavior is common to all objects, for example:
// Counting the number of objects created. Storing company or university name shared by all instances. Utility/helper functions that don't depend on object-specific data.


// A non-static member belongs to a particular object. A static function belongs to the class and can be called without creating an object.
// Because there is no ambiguity about the static member.There is only one shared val. So any object's member function can access that same
// C++ does have static data members and static member functions, but not static constructors or static destructors.
class Calculator {
    int value;

public:
    Calculator() {
        value = 0;
    }

    Calculator& add(int x) {
        value += x;
        return *this;
    }

    Calculator& subtract(int x) {
        value -= x;
        return *this;
    }

    void display() {
        cout << value;
    }
};


class Number {
    int x;

public:
    // this is a pointer to the current object.
    // It is automatically created by the compiler.
    // Available only inside non-static member functions.
    // Used to distinguish data members from local variables or parameters.
    // Access members using this->member.
    // Can return this or *this for method chaining.
    // Helps write cleaner, more readable code.
    Number(int n) {
        x = n;
    }
    // Returning Current Object (*this)
    Number& increment() {
        x++;
        return *this;
    }

    void display() {
        cout << x;
    }
};

int main() {
    int x = 50;
    cout << "Local : " << x << endl;
    cout << "Global: " << ::x; // Use the scope resolution operator(::) to access the global variable when it is hidden by a local variable.
    // When a local variable has the same name as a global variable, the local variable shadows (hides) the global variable.
    // In most cases, local variables are preferred because they:
    // Reduce unintended side effects. Improve code readability and maintainability. Make debugging easier.
    // Avoid accidental modification from different parts of the program.
    // Global variables should be used sparingly, typically only when shared state is genuinely required.

    Student s;
    s.setAge(20);
    s.display();

    Student s1(90), s2(80);

    s1.compareWith(s2);

    Rectangle r;
    r.setData(10, 5);
    r.display();

    // C++ does not support static constructors.A constructor is specifically associated with object creation:
    // Student s1; The constructor initializes s1.
    // But a static member belongs to the class, not an individual object.
    // Therefore, a constructor cannot be declared: static Student();
    // ****C++ does have static data members and static member functions, but not static constructors or static destructors.
    Students st;
    st.setMarks(90)->display();
    st.setAge(21).show();

    Calculator c;
    c.add(10).add(20).subtract(5).display();

    Number n(5);
    n.increment().increment().increment().display();
}