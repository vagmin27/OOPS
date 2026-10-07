#include <bits/stdc++.h>
using namespace std;

// Here we are demonstrating how the actual vector works using the oops concept.
class Vector {
public:
    int size;
    int capacity;
    int *arr;
    // The constructor initializes the vector by setting its initial size to 0, capacity to 1, and dynamically allocating memory for the array.
    Vector() {
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    // The add() function is used to insert an element at the end of the vector.
    // If the vector is full, it doubles the capacity, creates a new larger array, copies the existing elements, and then adds the new element.
    void add(int num) {
        if (size == capacity) {
            capacity *= 2;
            int *arr2 = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size++] = num;
    }

    // The print() function is used to display all the elements currently present in the vector.
    // It iterates only up to size, since the remaining capacity may be unused.
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // The get() function is used to access and return an element at a particular index.
    // It first checks whether the vector is empty and whether the given index is valid.
    int get(int idx) {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return -1;
        }
        if (idx >= size) {
            cout << "Invalid Index" << endl;
            return -1;
        }
        return arr[idx];
    }

    // The remove() function is used to remove the last element from the vector logically by decreasing the size by one.
    // The memory is not physically cleared; the position simply becomes available for future use.
    void remove() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return;
        }
        size--;
    }

    // The destructor is automatically called when the vector object is destroyed.
    // It releases the dynamically allocated memory using delete[] and prevents memory leaks.
    ~Vector() {
        delete[] arr;
    }
};

int main() {
    // Basically A vector is a dynamic array whose size can grow at runtime.
    // When its capacity becomes full, it allocates a larger memory block, copies the existing elements into it, and continues storing new elements.
    Vector v;
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
    v.add(10);
    v.print();
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
    v.add(7);
    v.print();
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
    v.add(4);
    v.print();
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
    v.add(2);
    v.print();
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
    v.add(0);
    v.print();
    cout << "The size and capacity of the vector are : " << v.size << " " << v.capacity << endl;
}