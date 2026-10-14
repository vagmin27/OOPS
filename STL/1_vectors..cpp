#include <bits/stdc++.h>
using namespace std;

// A vector is an STL container that stores elements in contiguous memory and can dynamically resize itself when elements are added or removed.
// An array has a fixed size, whereas a vector can dynamically grow or shrink during runtime.
// A vector behaves like a dynamic array because it stores elements contiguously and can automatically allocate more memory when required.
// size() = number of actual elements, while capacity() = amount of currently allocated storage. reserve() changes capacity, while push_back()/emplace_back() change size.

// the time complexity of accessing a vector element is O(1) because vector elements are stored in contiguous memory
// can directly calculate the memory address of the ith element.

class Student {
public:
    string name;
    int age;
};
int main() {

    // vector<int> creates a dynamic array that stores integers.
    vector<int> v;

    // push_back() adds an element at the end of the vector.
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // emplace_back() constructs and adds an element directly at the end of the vector.
    v.emplace_back(40);
    // A vector can also be initialized directly with multiple values.
    vector<int> nums = {10, 20, 30, 40, 50};
    // vector<int> v2(5) creates a vector of size 5 with default-initialized values.
    vector<int> v2(5);
    // vector<int> v3(5, 100) creates 5 elements, each initialized to 100.
    vector<int> v3(5, 100);

    // [] accesses an element using its index and does not perform bounds checking.
    cout << "Element at index 2: " << nums[2] << endl;
    // at() accesses an element using its index and performs bounds checking.
    cout << "Element at index 2 using at(): " << nums.at(2) << endl;

    // front() returns a reference to the first element.
    cout << "First element: " << nums.front() << endl;
    // back() returns a reference to the last element.
    // if you call front() or back() on an empty vector. It results in undefined behavior.
    cout << "Last element: " << nums.back() << endl;

    // size() returns the number of elements currently present in the vector.
    // The vector allocates a larger memory block, moves or copies its existing elements to the new memory, destroys the old storage, and then adds the new element.
    // This process is called reallocation.
    // push_back() adds an existing object or value, while emplace_back() constructs the object directly inside the vector.
    // pop_back() removes the last element from the vector. Here v.pop_back() it decreases the size by one but normally does not decrease capacity.
    // Also pop_back() returns void
    cout << "Size: " << nums.size() << endl;
    // capacity() returns the amount of storage currently allocated by the vector.
    // The vector does not require a specific growth factor. The implementation decides how much additional capacity to allocate.
    cout << "Capacity: " << nums.capacity() << endl;

    // empty() returns true if the vector contains no elements, otherwise it returns false. empty() checks whether the vector contains zero elements.
    cout << "Is vector empty? " << nums.empty() << endl;
    // reserve() requests memory for at least the specified number of elements.
    // It changes capacity but does not change the size.
    nums.reserve(100);

    cout << "Size after reserve: " << nums.size() << endl;
    cout << "Capacity after reserve: " << nums.capacity() << endl;

    // insert() adds an element at the specified position. The existing elements from that position are shifted to make space.
    nums.insert(nums.begin() + 2, 25);

    // The vector is now: 10 20 25 30 40 50
    // insert() can also insert multiple copies of the same value.
    nums.insert(nums.begin() + 3, 2, 99);
    // The vector is now: 10 20 25 99 99 30 40 50
    // erase() removes the element at the specified position. erase() removes an element or a range of elements.
    // erase() removes a specific element or range. whereas clear() removes all elements.
    nums.erase(nums.begin() + 1);
    // The element 20 is removed.
    // erase() can also remove a range of elements.
    nums.erase(nums.begin() + 2, nums.begin() + 4);
    // The elements in the specified range are removed.
    // A normal for loop can access vector elements using their indexes.
    cout << "Using index:" << endl;

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    // A range-based for loop directly accesses each element.
    cout << "Using range-based loop:" << endl;
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    // begin() returns an iterator pointing to the first element.
    // An iterator is an object used to traverse and access elements of an STL container.
    auto it = nums.begin();

    // Dereferencing an iterator using * gives the element it points to.
    cout << "First element using iterator: " << *it << endl;

    // Incrementing the iterator moves it to the next element.
    it++;
    cout << "Second element using iterator: " << *it << endl;

    // Iterators can be used to traverse the complete vector.
    // When a vector reallocates its storage, iterators, pointers, and references to its elements are generally invalidated
    cout << "Using iterators:" << endl;

    for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // end() points just after the last element and should not be dereferenced.
    
    // rbegin() returns a reverse iterator pointing to the last element.
    // rend() returns a reverse iterator pointing just before the first element.
    cout << "Reverse traversal:" << endl;

    for (auto it = nums.rbegin(); it != nums.rend(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    // pop_back() removes only the last element.
    nums.pop_back();
    cout << "After pop_back:" << endl;
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    // clear() removes all elements from the vector.
    nums.clear();
    // After clear(), size becomes zero.
    cout << "Size after clear: " << nums.size() << endl;
    // Capacity normally remains unchanged even after clear().
    cout << "Capacity after clear: " << nums.capacity() << endl;
    // empty() now returns true because the vector contains no elements.
    cout << "Is vector empty after clear? " << nums.empty() << endl;


    vector<Student> students;
    // vectors can store objects of a class
    students.emplace_back("Rahul", 20);
    return 0;
}