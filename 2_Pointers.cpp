#include <bits/stdc++.h>
using namespace std;
// A pointer is a variable that stores the memory address of another variable.
// Instead of storing a value directly, a pointer stores where that value is located in memory.
// Basically address is a hexa-decimal number

void changeA(int *ptr) {
    // Pass by reference using pointers means passing the address of a variable to a function instead of passing a copy of its value.
    // Because the function receives the address, it can use the pointer to access and modify the original variable.
    *ptr = 20;
}

int main() {

    // The symbol & in C++ is mainly associated with memory addresses and references. Its meaning depends on how it is used.
    // 1. Address-of operator
    // When & is placed before a variable, it returns the memory address of that variable.
    // &x means the address where x is stored in memory. It is commonly used when working with pointers:
    // Address starts with 0x... so if we print it we see 0x at the start so that we can know it is the address of the variable

    int x = 10;
    cout << &x;
    int *p = &x;
    // The dereference operator (*) is used with a pointer to access the value stored at the memory address held by that pointer.
    cout << p << " " << x << endl;
    cout << *(&x) << " " << *(p) << endl;
    // 2. Reference operator
    // When & is used while declaring a variable, it creates a reference.
    int y = 10;
    int &r = y; // Here, r is a reference (alias) to y.
    // Both y and r refer to the same memory location.
    cout << y << " " << r;
    // In C++, & is the address-of operator when used with a variable, and it is also used to declare a reference.
    // It allows us to work with the memory address of a variable or create an alias for an existing variable.

    int **ptr = &p;
    cout << "The address of x is: " << p << "and the address of the pointer to x(i.e, p) is: " << ptr << endl;
    // Pass By Reference using pointer
    int a = 10;

    // // Pointer Arithmetics
    int b = 10;
    int *pt = &b;
    cout << pt << endl;
    pt++;
    cout << pt << endl;
    pt--;
    pt--;
    cout << pt << endl;

    // Array pointers
    // An array name generally acts as a pointer to the first element of the array, and a pointer can be used to traverse and access array elements using pointer arithmetic.
    int arr[5];
    int *ptrs = arr;
}