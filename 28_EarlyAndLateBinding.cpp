#include<iostream>
using namespace std;
// class A { //Early Binding
// public:
//     void show() {
//         cout << "class A" << endl;
//     }
// };
// 1. Early Binding

// Early binding is the process in which a function call is resolved at compile time. The compiler determines which function will be executed before the program runs.

// It is also called static binding or compile-time binding.
// It is generally associated with function overloading and non-virtual functions.
// It is usually faster because the function call is resolved at compile time.
// It does not support runtime polymorphism through the function call.

class A {
public:
    virtual void show() {
        cout << "class A" << endl;
    }
};

// 2. Late Binding

// Late binding is the process in which a function call is resolved at runtime. The function to be executed is determined while the program is running, based on the actual type of the object.

// It is also called dynamic binding or runtime binding.
// It is achieved in C++ using virtual functions.
// It supports runtime polymorphism.
// It provides flexibility by allowing a base-class pointer or reference to call an overridden function of a derived-class object.

class B : public A {
public:
    void show() {
        cout << "class B" << endl;
    }
};

int main() {
    A *a = new B();
    a->show();
    return 0;

}