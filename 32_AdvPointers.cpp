
#include <iostream>
using namespace std;

int main() {

    // 1. NULL POINTER
    // A null pointer does not point to any valid object. Use nullptr in modern C++.
    int* nullPtr = nullptr;

    if (nullPtr == nullptr)
        cout << "Null pointer: points to no object\n";

    // Dereferencing nullPtr causes undefined behavior.
    // cout << *nullPtr;


    // 2. DANGLING POINTER
    // A dangling pointer refers to an object whose lifetime has ended or whose storage is invalid.
    int* danglingPtr = new int(100);
    cout << "Before delete: " << *danglingPtr << '\n';

    delete danglingPtr;  // Ends object's lifetime

    // danglingPtr now holds an invalid pointer value.
    // Do not dereference or otherwise use this value.
    danglingPtr = nullptr; // Explicitly reset the pointer


    // 3. WILD POINTER
    // An uninitialized pointer has an indeterminate value.
    // Dereferencing it causes undefined behavior.

    int* wildPtr;  // Uninitialized: unsafe to use
    // cout << *wildPtr; // Undefined behavior

    int x = 50;
    wildPtr = &x;  // Now initialized with a valid address

    cout << "Initialized pointer: " << *wildPtr << '\n';

    // 4. VOID POINTER
    // A void pointer can store the address of an object without specifying its type.
    // It must be converted to a suitable pointer type before dereferencing.

    int num = 200;
    void* voidPtr = &num;

    cout << "Void pointer value: " << *static_cast<int*>(voidPtr) << '\n';
    return 0;
}
