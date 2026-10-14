#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
// A map stores key-value pairs in sorted order of keys, and each key must be unique. The keys are automatically sorted.
// mp[key] accesses the value associated with the key. If the key does not exist, it creates the key with a default value.
// map is generally implemented using a self-balancing binary search tree, commonly a Red-Black Tree.
// The avg complexity is O(log n)

// An unordered_map also stores key-value pairs, but it does not maintain keys in sorted order.
// It uses hashing internally. Most functions are similar to map
// Worst case can become O(n), mainly because of hash collisions and avg case is O(1)

// A multimap is similar to map, but duplicate keys are allowed.
// The elements are still stored in sorted order of keys. You cannot use [] with a multimap.
// Insert O(log n), Search, O(log n) Delete, O(log n), count() O(log n + k)

// So basically Use map when you need unique keys and sorted order.
// Use unordered_map when you need unique keys and fast average O(1) lookup and ordering is irrelevant.
// Use multimap when you need multiple values associated with the same key while keeping the keys sorted.

int main() {

    // map stores key-value pairs in sorted order and does not allow duplicate keys.
    map<int, string> mp;

    mp[101] = "Rahul";
    mp[103] = "Aman";
    mp[102] = "Priya";

    // insert() adds a key-value pair.
    mp.insert({104, "Riya"});

    // [] accesses the value associated with a key.
    cout << "Student 101: " << mp[101] << endl;

    // find() returns an iterator to the key if it exists.
    if (mp.find(102) != mp.end()) {
        cout << "Student 102 found" << endl;
    }

    // count() returns 1 if the key exists and 0 otherwise.
    cout << "Count of 103: " << mp.count(103) << endl;

    // erase() removes the element having the specified key.
    mp.erase(103);

    // map elements are printed in sorted key order.
    cout << "Map:";
    for (auto p : mp) {
        cout << p.first << " " << p.second << endl;
    }

    // unordered_map stores key-value pairs using hashing and does not maintain sorted order.
    unordered_map<int, string> ump;
    // unordered_map is often preferred when you only need fast key-value lookup and do not care about the order of elements, because it provides average O(1) insertion, searching, and deletion.
    // map → Use when you need unique keys and sorted order.
    // unordered_map → Use when you need unique keys and fast average O(1) operations, and ordering is not important.
    // multimap → Use when you need duplicate keys and sorted order.
    // Advantages sentence-wise
    // map: The main advantage of map is that it automatically keeps keys sorted, making it useful when you need ordered data or range-based operations.
    // unordered_map: The main advantage of unordered_map is its average O(1) lookup, insertion, and deletion, making it generally faster when ordering is not required.
    // multimap: The main advantage of multimap is that it allows multiple values to have the same key while still maintaining the keys in sorted order.

    // Among these, unordered_map is commonly used when ordering is not required because it provides average O(1) lookup, insertion, and deletion.
    // However, map is preferred when sorted keys are required, while multimap is used when duplicate keys are needed.

    ump[101] = "Rahul";
    ump[103] = "Aman";
    ump[102] = "Priya";

    // insert() adds another key-value pair.
    ump.insert({104, "Riya"});

    // find() searches for a key.
    if (ump.find(102) != ump.end()) {
        cout << "102 exists in unordered_map" << endl;
    }

    // unordered_map provides average O(1) search, insertion and deletion.
    cout << "Student 101: " << ump[101] << endl;

    // The order of elements is not guaranteed.
    cout << "Unordered Map:";
    for (auto p : ump) {
        cout << p.first << " " << p.second << endl;
    }

    // multimap stores key-value pairs in sorted order and allows duplicate keys.
    multimap<int, string> mmp;

    // insert() is used because [] is not available for multimap.
    mmp.insert({101, "Rahul"});
    mmp.insert({102, "Priya"});
    mmp.insert({101, "Aman"});
    mmp.insert({101, "Riya"});

    // count() returns the number of elements having the specified key.
    cout << "Number of students with key 101: " << mmp.count(101) << endl;

    // equal_range() returns the range containing all elements with the specified key.
    auto range = mmp.equal_range(101);

    cout << "Students with key 101:";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it->second << endl;
    }

    // erase() can remove all elements having the specified key.
    mmp.erase(102);

    cout << "Multimap:";
    for (auto p : mmp) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}