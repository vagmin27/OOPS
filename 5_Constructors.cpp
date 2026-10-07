#include <bits/stdc++.h>
using namespace std;

// A constructor is a special member function of a class that is automatically called when an object is created. Its main purpose is to initialize the object's data members.

// Creating an object without a constructor is like buying a car with no color or we will color it after buying.
// The constructor must be there for initializing the object. At the time of placing the order I wanted a white color Scorpio or BMW etc.
// So the purpose of a constructor is to create a new object and set values for any existing object properties.
// A constructor in C++ is a special method that is automatically called when an object of a class is created.
// To create a constructor, use the same name as the class, followed by parentheses ().
// There should not be a return type of constructor.


// A constructor is a special member function that has the same name as the class and does not have any return type, not even void.
// Without a constructor, data members may contain garbage values.
// A garbage value is a random or unpredictable value present in a variable that has not been initialized. Since no value has been assigned, the variable contains whatever data already existed in that memory location.
class Student {
public:
    string name;
    int rollNo;
    float cgpa;

    // 1. Default Constructor:
    // Default constructor is a constructor that takes no parameters and is used to create an object with default values.
    // It is automatically called when an object is created and is used to initialize the data members of the class with default values.
    // If we don't define a constructor the compiler will automatically provide a default constructor for the class.
    // If we define a constructor with parameters and still want to use default constructor we have to explicitly define it.
    // If we define a constructor with parameters and don't create default constructor the compiler will not provide one.

    Student() {
        // A class can't have multiple default constructors. Only one constructor without parameters can exist.
        // This is because C++ must always know exactly which constructor to call when an object is created.
        // If there were multiple default constructors, the compiler would not know which one to choose.
        cout << "Default Constructor";
    }
    // 2. Parameterized Constructor
    // It takes parameters and is used to create an object with specific values. It is automatically called when an object is created and is used to initialize the data members of the class with specific values in the same order as they are defined in the constructor.
    // It is very much useful in the pillars of OOPS.
    // Initialization happens at object creation. Reduces extra assignment statements.
    // It allows each object to have different values. Parameterized constructors allow us to initialize each object differently.
    Student(string n, int r, float c) {
        name = n;
        rollNo = r;
        cgpa = c;
    }
    // 3. Copy Constructor
    // Copy constructor is used to create a new object as a copy of an existing object. It is automatically called when an object is created and is used to initialize the data members of the class with the values of the existing objext.
    // Here the copy constructor is called when we create s3 as a copy of s2 and it will initialize the data members of the class with the values of s2.
    // Here copy constructor uses deep copy.
};

// There are 5 types of constructors:
// - Default / Non Parameterized Constructor: With no parameters. C++ says that a default constructor is automatically provided by the compiler.
// - Parameterized Constructor: With Parameters, Create a new instance of a class and also pass arguments simultaneously.
// - Copy Constructor: Which creates a new object as a copy of an existing object.

class Employee {
public:
    int id;
    // A constructor is not meant to return any value. Its only job is to initialize an object.
    // If constructors had return types, the compiler would treat it as an ordinary function instead of a constructor.
    // Therefore, constructors cannot have any return type—not even void.
    Employee() {
        id = 101;
    }

    void display() {
        cout << "ID = " << id;
    }
};

class Number {
private:
    int *ptr;

public:
    Number(int x) {
        // The new operator dynamically allocates memory on the heap and returns a pointer to the allocated memory.
        ptr = new int;
        *ptr = x;
        // Normally, variables are created in stack memory.
        // Example: int x = 10;
        // Here, Memory is allocated automatically. Memory is released automatically when the function ends.
        // Sometimes, we don't know how much memory we need until the program is running.

        // For example:
        // User enters the size of an array. Reading data from a file. Creating linked lists, trees, or graphs.
        // Objects whose lifetime should extend beyond the current function.
        // In such cases, we use dynamic memory allocation with new.
    }

    void display() {
        cout << *ptr << endl;
    }
    // A destructor is a special member function that has the same name as the class, prefixed with a tilde (~), and does not have any return type or parameters.
    // Suppose an object allocates memory using new. example: ptr = new int;
    // When the object is destroyed, that memory does not get released automatically because it is on the heap.
    // If we don't free it, the program wastes memory. This is called a memory leak.
    // A destructor automatically performs the cleanup.
    ~Number() {
        delete ptr;
    }
};

class Numbers {
private:
    int *ptr;

public:
    Numbers(int x) {
        ptr = new int;
        *ptr = x;
    }

    void displayed() {
        cout << *ptr << endl;
    }

    ~Numbers() {
        delete ptr;
        cout << "Memory Released";
    }
};

class Rectangle {
public:
    int length;
    int width;

    Rectangle(int l = 10, int w = 5) {
        length = l;
        width = w;
    }

    void area() {
        cout << "Area = " << length * width << endl;
    }
};

class Chai {
private:
    string teaName;
    int servings;
public:
    // This is a parameterized constructor because it accepts two arguments.

    Chai(string name, int serve) : teaName(name), servings(serve) {} // *** This is called a constructor initializer list.
    // The members are initialized directly.
    // This says simply Create teaName with name and create servings with serve
    // Situations when initializer list is used are: a const variable must be initialized when it is created
    // Traditionally The members are first initialized and then assigned new values inside the constructor body.
    // *** The order in which members are initialized is determined by their declaration order, not the order written in the initializer list.
};

int main() {

    int x;  // Not initialized
    cout << x; // The output is unpredictable because x was never assigned a value.
    // When a variable is created, memory is allocated for it. Suppose the memory location already contains the value 4589 from a previous program.
    // x is allocated at address 1000. Since no value is assigned, x = 4589. This 4589 is called a garbage value.

    // A garbage value is the unpredictable value stored in an uninitialized variable. It occurs because memory is allocated to the variable, but no value has been assigned to it. To avoid garbage values, always initialize variables or use constructors to initialize class members.

    Student s1; // Calls default constructor
    // Suppose we create an object. If no constructor is written, the data members contain garbage values.
    // Using a default constructor ensures that every newly created object starts with meaningful values.

    Student s2("John", 101, 3.5); // Calls parameterized constructor

    // Here in s2 we are passing the values of name, rollNo and cgpa to the constructor and it will initialize the data members of the class with these values.
    Student s3 = s2; // Calls copy constructor
    cout << "Enter the name of the student: ";
    cin >> s1.name;
    cout << "Enter the roll number of the student: ";
    cin >> s1.rollNo;
    cout << "Enter the CGPA of the student: ";
    cin >> s1.cgpa;

    cout << "Student 1: " << s1.name << " " << s1.rollNo << " " << s1.cgpa << endl;
    cout << "Student 2: " << s2.name << " " << s2.rollNo << " " << s2.cgpa << endl;
    cout << "Student 3: " << s3.name << " " << s3.rollNo << " " << s3.cgpa << endl;

    Employee e;
    e.display(); //Default
    Number n(500);
    // A constructor that allocates memory dynamically using new.
    // A dynamic constructor is simply a constructor that uses new to allocate memory dynamically.
    n.display(); //Dynamic Constructor

    Rectangle r1;
    Rectangle r2(20);
    Rectangle r3(20, 30);

    r1.area();
    r2.area();
    r3.area();

    Numbers n1(500);
    n1.displayed();
    // When a Chai object is created, initialize its teaName member using name and its servings member using serve
    Chai c("Masala Chai", 2);
    return 0;
}