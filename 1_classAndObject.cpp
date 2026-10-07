#include <bits/stdc++.h>
using namespace std;

class Car {
    // class is basically an user-defined data type which has its own properties and methods and is used to create objects.
    // class is basically a template which is used to create objects and is a blueprint of the object.
    // class represents a real world entity and is used to model the real world entities in the program
    // class encapsulates the data members and member functions of the class and is used to hide the implementation details of the class from the user.
    // user-defined data type is a data type which is defined by the user and not by the compiler.
    // The properties of a class are called data members and the methods of the class are called member functions.
    // The data members and member functions of a class are accessed using the dot operator(.) and the arrow operator(->) respectively
    // dot operator is an operator which is used to access the data members and member functions of a class using the object of the class.
    // arrow operator is an operator which is used to access the data members and member functions of a class using the pointer of the class.
    // dot operator is used when we have an object of the class and arrow operator for pointer to the class
public:
    string name;
    int price;
    int mileage;
    // these are the data members of the class Car
    // A data member is a variable which is defined inside the class and is used to store the properties of the class.
    // data members are also called member variables or attributes of the class
    // data members can be of any data type like int float double char string etc
};


class Cars {
public:
    string brand;
    string color;

    void start() {
        cout << "Car Started" << endl;
    }

    void stop() {
        cout << "Car Stopped" << endl;
    }
};

// Here, brand and color are data members also start() and stop() are member functions

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};

class Students {
public:
    string name;

    void displays() {
        cout << name << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        // An object refers to the instance of the class, which contains the instance of the members and behaviors defined in the class template.
        // In the real world, an object is an actual entity to which a user interacts, whereas class is just the blueprint for that object.
        // So the objects consume space and have some characteristic behavior.
        Car car1;
        // Here car1 is an object of the class Cars and is used to access the data members and member functions of the class Cars.
        // object is an instance of the class and is used to store the properties of the class
        // object is created using the class name followed by the obj name and is used to access the data members and member functions of the class.
        // objects are created in stack memory and are destroyed automatically when they go out of scope.
        // Stack memory is a memory which is used to store the local variables and function calls of the program and is managed by the compiler.
        // Stack memory is faster than heap memory and is used for small and short lived objects and is used for temporary storage of data.
        // Heap memory is a memory which is used to store the dynamic variables and objects of the program and is managed by the programmer.
        // Heap memory is slower than stack memory and is used for large and long lived objects and is used for permanent storage of data.
        // local variables are the variables which are defined inside the function and are used to store the temporary data of the function.
        // They are created in stack memory and destroyed automatically when they are out of scope.
        // They are not accessible outside the func and are not accessible by other functions.
        // They are created when the function is called and destroyed when the function is returned.
        // Global variables are defined outside the function and are used to store the permanent data of the program.
        // They are created in heap memory and destroyed when the program is terminated.
        // They are accessible by all the functions of the program and are created when the program is started.
        // Here the car1 object access the name, price and mileage variables using the dot operators and stores them in stack memory.
        // Scope of the car1 object is limited to while loop.
        cin >> car1.name;
        cin >> car1.price;
        cin >> car1.mileage;
        // We can also use arrow operator to access the data members of the class Car using the pointer of the class.
        // Object can be considered as a bucket which stores the properties of the class and is used to access the data members.
        // Instead of creating multiple objects of a class we can create an array of objects and access each of them using index

        Car car2;

        // A class can be understood as a template or a blueprint, which contains some values, known as member data or member, and some set of rules, known as behaviors or functions.
        // So when an object is created, it automatically takes the data and functions that are defined in the class.
        // It deals with internal designing not external. So it is just to help the programmer to prevent data from mishandling.
        cin >> car2.name;
        cin >> car2.price;
        cin >> car2.mileage;


        Cars car3;
        car3.brand = "Toyota";
        car3.color = "Red";
        car3.start();
        car3.stop();

        // Here we can't give same name for two different classes as it will create ambiguity and the compiler will not be able to differentiate between the two classes and will give an error.
        // This is because compiler only sees the class name and not the object name.
    }
    // A class definition itself does not allocate memory for instance variables. Memory is allocated when objects are created. Member function code is stored once and shared.
    Student s1;
    Student s2;
    // In C++ every object must be created from a class (ignoring primitive built-in types).
    s1.name = "Rahul";
    s1.age = 20;

    s2.name = "Priya";
    s2.age = 21;
    s1.display();
    s2.display();
    //Here both objects use the same display() function but have different data. This shows the reusability of code.
    // This is the main advantage of OOPS as it allows us to create multiple objects of the same class and use the same functions to access their data members.
    // One blueprint can be used to build many houses. Similarly, one class can create many objects.
    // Memory for data members is allocated only when an object is created.
    // Multiple objects created from the same class have independent copies of the data members but share the same member function definitions.


    Students* s = new Students(); //This is called a dynamic object.
    // A dynamic object is an object whose memory is allocated at runtime (during program execution) using the new operator. It resides on the heap (free store) instead of the stack.
    // We use Dynamic objects
    // 1. When the number of objects is not known at compile time.
    // 2. When objects need to exist beyond the scope of a function.
    // 3. To allocate large amounts of memory without risking stack overflow.
    // 4. Used extensively in data structures like linked lists, trees, and graphs.
    s->name = "Rahul";
    s->displays();
    // ****Since s is a pointer: s->displays() is equivalent to: (*s).displays();

    delete s;   // Frees the allocated memory
    return 0;
    // For main function the return 0, is not necessary as it is the default return value of the function but it is a good practice to use it as it indicates that the program has executed successfully and has returned to the os.
}