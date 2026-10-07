#include<bits/stdc++.h>
using namespace std;

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
    
    void print() {
        cout << name << " " << runs << " " << avg << endl;
    }
    int matches() {
        return runs / avg;
    }
};

int main() {
    Cricketer c1("Virat Kohli", 25000, 55.2);
    c1.print();
    
    // Object pointer: An object pointer is simply a pointer that stores the address of an object.
    Cricketer *ptr = &c1;
    // Access members using object pointer ptr is an object pointer. &c1 gives the address of object c1. Therefore, ptr points to c1.
    cout << ptr->name << endl; //The -> operator is used because ptr is a pointer to an object.
    cout << ptr->runs << endl;
    cout << ptr->avg << endl;

    // Call member functions using object pointer
    ptr->print();
    cout << "Matches: " << ptr->matches() << endl;

    Cricketer *ptrs = new Cricketer("Rohit Sharma", 18000, 45.2); // creates the object dynamically.
    cout << "Matches: " << ptrs->matches() << endl; // accesses it.
    delete ptrs; // releases the dynamically allocated object.
    // C++ does not automatically release that memory just because the pointer variable goes out of scope.
    ptrs = nullptr;
}