#include <iostream>
using namespace std;

// BASE CLASS
class Base {
public:
    // A virtual function enables runtime polymorphism. When called through a Base reference or pointer,
    // C++ selects the overridden function based on the actual type of the object at runtime.
    virtual void fun() {
        cout << "Print From Base" << endl;
    }

    // A virtual destructor is good practice when a class is intended to be used polymorphically.
    virtual ~Base() = default;
};


// DERIVED CLASS
class Child : public Base {
public:
    // override ensures that this function correctly overrides the virtual function declared in Base.
    // If the signature does not match, the compiler reports an error.
    void fun() override {
        cout << "Print From Child" << endl;
    }
};


// PASSING BY VALUE — OBJECT SLICING
void executeByValue(Base obj) {

    // THEORY:
    // When a Child object is passed to this function, a separate Base object is constructed from its Base portion.
    //
    // The Child-specific portion is discarded. This is called OBJECT SLICING.
    // obj is now an independent Base object, so the virtual function call invokes Base::fun().
    obj.fun();
}


// PASSING BY REFERENCE — RUNTIME POLYMORPHISM
void executeByReference(Base& obj) {

    // THEORY:
    // No new Base object is created. obj refers directly to the original object.
    // If the original object is of type Child, virtual dispatch invokes Child::fun().
    // Since no object copy is made, slicing does not occur.
    obj.fun();
}


// PASSING BY POINTER — RUNTIME POLYMORPHISM
void executeByPointer(Base* obj) {

    // THEORY:
    // obj stores the address of an existing Base or derived object.
    // The arrow operator (->) accesses the function through the pointer.
    // Because fun() is virtual, the implementation is selected according to the actual object's type.
    // The pointer must point to a valid object.
    if (obj != nullptr) {
        obj->fun();
    }
}


int main() {

    // A Child object contains its inherited Base portion along with any additional Child-specific state.
    Child c;

    cout << "1. Passing by Value:" << endl;
    executeByValue(c);
    // Output: Print From Base
    // Reason: The Child object is sliced into a separate Base object.

    cout << "\n2. Passing by Reference:" << endl;
    executeByReference(c);
    // Output: Print From Child
    // Reason: The reference refers to the original Child object.

    cout << "\n3. Passing by Pointer:" << endl;
    executeByPointer(&c);
    // Output: Print From Child
    // Reason: The pointer points to the original Child object.

    return 0;
}