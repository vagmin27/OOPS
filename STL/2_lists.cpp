#include <bits/stdc++.h>
using namespace std;

// Use list when you frequently need insertion and deletion in the middle of the container and already have an iterator pointing to the position. For most general-purpose use cases, vector is usually preferred because of better cache locality and random access.

int main() {
    list<int> nums = {10, 20, 30};

    nums.push_back(40);      // Add at end
    nums.push_front(5);      // Add at beginning

    cout << "List: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    cout << "First: " << nums.front() << endl;  // First element
    cout << "Last: " << nums.back();    // Last element

    nums.pop_back();         // Remove last element
    nums.pop_front();        // Remove first element

    nums.push_back(50);

    nums.sort();             // Sort the list
    nums.reverse();          // Reverse the list

    cout << "After changes: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    // A list is implemented as a linked list, so its elements are not stored in contiguous memory.
    // It does not support random access.
    // To reach the third element, we must traverse from the beginning or end using an iterator.
    cout << "Size: " << nums.size();

    nums.clear();            // Remove all elements
    cout << endl;
    // Use vector when you need fast random access and mostly add/remove elements at the end.
    // Use list when you frequently insert or delete elements at known positions using iterators.
    // In practice, vector is generally preferred because it has better cache locality
    cout << "Empty: " << nums.empty();
    return 0;
}