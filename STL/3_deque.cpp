#include<bits/stdc++.h>
// #include <deque> we use this we are not doing bits/stdc++.h
using namespace std;

// Deque is a data structure/container, whereas dequeue is an operation that means removing an element from a queue.
// Deque and dequeue are two different terms: deque is a data structure (and an STL container in C++) that allows insertion and deletion of elements from both the front and the back, whereas dequeue is an operation that means removing an element from a queue, usually from the front.


// Deque stands for Double-Ended Queue.
// It is an STL container that allows you to insert and delete elements from both the front and the back efficiently.
int main() {
    deque<int> dq;
    // Deque = Double-Ended Queue.
    // It supports efficient insertion and deletion from both front and back.
    // It supports random access using [] and at().
    // A vector stores its elements in contiguous memory. A deque generally stores its elements in multiple memory blocks/chunks managed internally.
    // Unlike a vector, its elements are not stored in one contiguous memory block.
    // Unlike a list, it supports random access.
    // This allows deque to efficiently grow at both ends.

    // Use deque when you need both-end operations and random access.
    // Use list when you frequently insert/delete in the middle and already have an iterator to that position.
    

    // A deque is an STL container that provides efficient insertion and deletion at both ends while also supporting random access to its elements.
    dq.push_back(10);                 // Adds 10 at the back
    dq.push_back(20);                 // Adds 20 at the back
    dq.push_front(5);                 // Adds 5 at the front
    dq.push_front(1);                 // Adds 1 at the front

    cout << "Deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Front: " << dq.front() << endl;    // Returns first element
    cout << "Back: " << dq.back() << endl;      // Returns last element
    cout << "Index 2: " << dq[2] << endl;       // Accesses using index
    cout << "At index 1: " << dq.at(1) << endl; // Accesses with bounds checking
    cout << "Size: " << dq.size() << endl;      // Returns number of elements

    dq.push_front(0);                // Adds element at the front
    dq.push_back(30);                // Adds element at the back

    dq.pop_front();                  // Removes first element
    dq.pop_back();                   // Removes last element

    dq.insert(dq.begin() + 1, 15);   // Inserts 15 at position 1
    
    // This removes elements from the first iterator up to but not including the second iterator.
    dq.erase(dq.begin() + 1);        // Removes element at position 1

    cout << "After operations: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse: ";
    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    if (dq.empty()) {                // Checks whether deque is empty
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    dq.clear();                      // Removes all elements

    cout << "Size after clear: " << dq.size() << endl;

    return 0;
}