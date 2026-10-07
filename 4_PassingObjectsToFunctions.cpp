#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
    int price;
    int mileage;
    string numberPlate;
    float engineCapacity;
    char fuelType;
    bool automatic;
};
// Passing an object to a function means sending an object of a class as an argument to a function. This allows the function to access or modify the object's data.

// We pass objects to functions:
// 1. To perform operations on object data.
// 2. To compare two or more objects.
// 3. To avoid writing duplicate code.
// 4. To implement modular programming.
void print(Car car) {

    // Here we are using pass by value to pass the car object to the function and print its data members using dot operator
    cout << car.name << endl;
    cout << car.price << endl;
    cout << car.mileage << endl;
    cout << car.numberPlate << endl;
    cout << car.engineCapacity << endl;
    cout << car.fuelType << endl;
    cout << car.automatic << endl;

    // This takes the car object as a parameter and prints the data members of the car using dot operator
    // This shows how to pass object to function
}
class Student {
public:
    int marks = 80;
};

void display(Student s) {
    s.marks = 95;
    cout << "Inside Function: " << s.marks << endl;
}
void displays(Student &s) {
    s.marks = 95;
}
// Pass by const reference is safest for read-only operations because it avoids copying while preventing accidental modifications.
// we use const with reference because it Prevents accidental modification. No copy is created. Improves performance and Makes the function safer and self-documenting.
void displaying(const Student &s) {
    cout << s.marks << endl;

    // s.marks = 90;   // Error
}

class Distance {
    // A member function of one object can receive another object.
    int meter;
public:
    void setData(int m) {
        meter = m;
    }

    void add(Distance d) {
        cout << meter + d.meter;
    }
};

Student createStudent() //Objects can both be passed to and returned from functions.
{
    Student s;
    return s;
}



class Rectangle {
    int length, width;

public:
    void setData(int l, int w) {
        length = l;
        width = w;
    }
    // A function can accept two or more objects of the same class or different classes as parameters. This is useful when an operation involves multiple objects, such as comparing, adding, merging, or copying their data.
    //  These objects can be passed either by value, by reference, or by const reference, depending on the requirement.
    // Multiple objects are commonly used for comparison, arithmetic operations, and data processing.
    // Each object passed to the function is treated as a separate parameter.
    // Objects may belong to the same class or different classes, depending on the function's requirements.

    // 1. Pass by value
    // Copies of both objects are created.
    // Changes made inside the function do not affect the original objects.
    // Suitable for small objects but less efficient for large objects.
    void compare(Rectangle r1, Rectangle r2) {
        int area1 = r1.length * r1.width;
        int area2 = r2.length * r2.width;

        if (area1 > area2) {
            cout << "Rectangle 1 has a larger area.";
        } else if (area2 > area1) {
            cout << "Rectangle 2 has a larger area.";
        } else {
            cout << "Both rectangles have the same area.";
        }
    }

    // 2. Pass by const reference (recommended):
    // No copies of the objects are created.
    // The original objects cannot be modified.
    // More efficient and is the preferred approach when the function only needs to read the objects.
    void comparing(const Rectangle &r1, const Rectangle &r2) {
        int area1 = r1.length * r1.width;
        int area2 = r2.length * r2.width;

        if (area1 > area2) {
            cout << "Rectangle 1 has a larger area.";
        } else if (area2 > area1) {
            cout << "Rectangle 2 has a larger area.";
        } else {
            cout << "Both rectangles have the same area.";
        }
    }
};
int main() {
    // We are passing the car object to the print function and printing its data members using dot operator.
    Car car1;
    car1.name = "Toyota Camry";
    car1.price = 25000;
    car1.mileage = 30000;
    car1.numberPlate = "ABC123";
    car1.engineCapacity = 2.5;
    car1.fuelType = 'G';
    car1.automatic = true;
    print(car1);

    // 1.Pass by value:
    // This creates a copy of the object and passes it to the function.
    // Any changes made to the object inside the function will not affect the original object.
    // It is basically used when we want to temporarily use the object inside the function and don't change its value.
    // It is slower than pass by reference and pass by pointer because copy of the object is created.
    // This is the default way of passing object to function.
    // Here we use the dot operator to access the data members of the car object and print them
    // pass by value is slower for large objects because the compiler creates a complete copy of the object, which increases both memory usage and execution time.
    // Passing an object by value invokes the copy constructor (unless optimized by the compiler).
    // When a large object is passed to a function by value, the compiler creates a complete copy of the object. This increases memory usage and execution time because copying a large amount of data is expensive.
    Student s1;
    display(s1);
    cout << "Original Object: " << s1.marks;

    // 2.Pass by reference:
    // This passes the reference of the object to the function
    // Any changes made to the object inside the function will affect the original object.
    // It is basically used when we want to use the object inside the function and change its value in the function.
    // It is faster than pass by object as it doesn't require any copying of the object
    // It is faster than pass by value.
    // Here reference means the address of the object is used to access the object and any changes made to object inside will affect the original object.
    // Reference is basically an alias for the object and is used to access the object using its address.
    // Address of the object is the location in the memory where the object is stored and is used to access the object using pointer.
    // For pass by reference we use & operator.
    // "&" operator basically means the address.
    // Pointer is a variable which stores the address of another variable and is used to access the variable using its address.
    displays(s1);
    cout << s1.marks;

    // 3. Pass by Constant Reference
    // Used when the function only needs to read the object.
    // No copy is created.
    // Faster than pass by value.
    // Object cannot be modified inside the function.
    // Most commonly used for large objects.
    // Pass by Const Reference: No copy → Original object cannot be modified and is the preferred choice when only reading object data.
    displaying(s1);
    Distance d1, d2;

    d1.setData(20);
    d2.setData(30);

    d1.add(d2);
    // The best method to pass an object:
    // Pass by value → Small objects, when modification is not required.
    // Pass by reference → When the function needs to modify the object.
    // Pass by const reference → Best choice for large objects when only reading data.


    // Difference Between Pass by Reference and Pass by Pointer
    // Pass by reference uses the & operator, whereas pass by pointer uses the * operator.
    // A reference cannot be nullptr because it must always refer to a valid object, whereas a pointer can be nullptr, indicating that it does not point to any object.
    // Pass by reference has simpler and cleaner syntax, as the object can be accessed directly. In contrast, pass by pointer requires dereferencing using * or the -> operator to access the object's members.
    // Pass by reference is generally preferred in modern C++ because it is safer and more readable. Pass by pointer is used when a function needs to allow nullptr values or when the pointer itself may need to be changed (reseated) to point to a different object.
    // References are ideal when the object is guaranteed to exist, while pointers are more suitable when the object may be optional or dynamically managed.


    Rectangle rect1, rect2, obj;

    rect1.setData(10, 5);
    rect2.setData(8, 7);

    obj.compare(rect1, rect2);
    obj.comparing(rect1, rect2);
    return 0;
}