#include <bits/stdc++.h>
using namespace std;

// Dynamic memory allocation means allocating memory at runtime,
// instead of deciding the memory requirement beforehand.
// In C++, dynamic memory is generally allocated from the heap
// using the new operator and released using delete.

class Cricketer {
public:
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg) {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
};

int main() {

    Cricketer c1("Virat Kohli", 25000, 55.2);
    Cricketer c2("Rohit Sharma", 18000, 45);

    // 1. Dynamic allocation of an integer
    int n;
    cin >> n;

    // The size of a normal array generally needs to be known at compile time.
    // Therefore, int arr[n] is NOT standard C++.
    // int arr[n]; Avoid this
    // Dynamic allocation allows us to allocate memory according to the value of n at runtime.
    int *arr = new int[n];

    // arr is a pointer that stores the address of the dynamically allocated array.
    arr[0] = 10;
    arr[1] = 20;

    cout << arr[0] << endl;
    cout << arr[1] << endl;

    // Since the array was created using new[],
    // we must use delete[].
    delete[] arr;
    // 2. Dynamic allocation of a single integer
    int x = 10;
    // x is a normal variable.
    // Its memory is automatically released when it goes out of scope.

    int *ptr = new int(10);
    // new int(10) dynamically allocates an integer and directly initializes it with 10.
    cout << *ptr << endl;

    // new → Allocate
    // delete → Deallocates
    delete ptr;

    // 3. Dynamic allocation of an object
    Cricketer *ptrs = new Cricketer("Sachin Tendulkar", 28000, 58.2);
    // The Cricketer object is dynamically allocated on the heap. ptrs stores the address of that object.
    // Since ptrs is an object pointer, use ->
    cout << ptrs->name << endl;
    cout << ptrs->runs << endl;
    cout << ptrs->avg << endl;
    // Release the dynamically allocated object.
    delete ptrs;

    // 4. Array of pointers to dynamically allocated objects
    // If we want different constructor arguments
    // for every object, we can use an array of pointers.

    Cricketer *players[3];

    players[0] = new Cricketer("Virat", 25000, 55.2);
    players[1] = new Cricketer("Rohit", 20000, 48.5);
    players[2] = new Cricketer("Dhoni", 18000, 50.0);

    cout << players[0]->name << endl;
    cout << players[1]->name << endl;
    cout << players[2]->name << endl;

    // Each object was separately allocated using new,
    // so each object must be separately deleted.

    delete players[0];
    delete players[1];
    delete players[2];

    return 0;
}