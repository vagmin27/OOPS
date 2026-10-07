#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int *marks;
    // There basically 2 ways to copy an object.
    // 1. Shallow Copy
    // In shallow copy, all variable values are copied, but dynamically allocated memory addresses are shared between objects.
    // Both objects point to the same heap memory, so changes made through one object affect the other.
    // This can lead to runtime errors like dangling pointers and double deletion, so it does not create an independent copy.
    // A shallow copy copies the values of all data members exactly as they are.
    // Normal variables are copied.
    // Pointer variables are also copied as addresses.
    // Both objects point to the same memory location.
    // So, only the pointer is copied, not the data it points to.
    Student(int m) {
        marks = new int;
        *marks = m;
    }
    // 2. Deep Copy:
    // In deep copy, a new object is created by copying all variable values and allocating separate memory for dynamically allocated variables.
    // Both the original and copied objects store their data in different memory locations.
    // Changes made to one object do not affect the other because a custom copy constructor is used.
    // When we create an object by copying data of another object along with the values of memory resources that reside outside the object, then it is called a deep copy
    // It copies all fields, and makes copies of dynamically allocated memory pointed to by the fields
    //  Deep copy is performed by implementing our own copy constructor.
    // If we do not create the deep copy in a rightful way then the copy will point to the original, with disastrous consequences.
    // Deep Copy Constructor
    Student(const Student &obj) {
        marks = new int;
        *marks = *(obj.marks);
        //We implement a deep copy by writing our own copy constructor that allocates new memory and copies the pointed-to data.
    }

    ~Student() {
        delete marks;
    }
};
int main() {
    // Shallow copy
    // shallow copy is dangerous because:
    // Both objects share the same memory. Changes in one affect the other.
    // Can cause dangling pointers.
    // Can lead to double deletion when destructors run.
    // The compiler-generated (default) copy constructor performs a shallow copy.
    Student s1(90);
    Student s2 = s1;
    // Shallow copy can be used safely if the class contains only non-pointer data members (e.g., int, float, char), because each value is copied independently.
    cout << *s1.marks << endl;
    cout << *s2.marks << endl;

    // Deep Copy
    // It is mainly needed when a class manages resources such as dynamically allocated memory, file handles, or other owned resources.
    Student s3(90);
    Student s4 = s3;
    *s4.marks = 50;
    cout << *s3.marks << endl;
    cout << *s4.marks << endl;
    // Without dynamic memory: Member values are copied, and the default copy constructor is usually sufficient.
    // With dynamic memory: Pointer addresses would be copied by default, so a deep copy is required to create independent objects.
    
    // Shallow copy is generally faster because it only copies member values (including pointer addresses), while deep copy allocates additional memory and copies the underlying data.
}