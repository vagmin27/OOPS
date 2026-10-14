#include<set>
#include<unordered_set>
#include<iostream>

using namespace std;
// A set stores unique elements in sorted order, an unordered_set stores unique elements using hashing without maintaining order, and a multiset stores duplicate elements in sorted order.
// set is useful when you need sorted unique elements.
// unordered_set is useful when you mainly need fast existence checking, such as checking whether a value has already appeared.
// multiset is useful when you need duplicates while keeping elements sorted, especially when you need operations such as getting the minimum/maximum or finding the next greater/smaller element.

int main() {

    // set stores unique elements in sorted ascending order.
    // A set is an STL container that stores unique elements in sorted order.
    // The elements are automatically arranged in ascending order by default.
    // If the same element is inserted multiple times, only one copy of that element is stored.
    // Insertion, deletion, and searching generally take O(log n) time.
    // A set is useful when we need unique values and sorted order.
    set<int> s = {40, 10, 30, 20, 20};

    // insert() adds an element; duplicate elements are ignored in set.
    s.insert(50);

    // find() returns an iterator to the element if it exists, otherwise end().
    if (s.find(20) != s.end())
        cout << "20 exists in set" << endl;

    // count() returns 1 if the element exists and 0 if it does not exist in set.
    cout << "Count of 20 in set: " << s.count(20) << endl;

    // erase(value) removes the specified element from the set.
    s.erase(30);

    // begin() points to the smallest element and rbegin() points to the largest element.
    cout << "Smallest: " << *s.begin() << endl;
    cout << "Largest: " << *s.rbegin() << endl;

    // lower_bound() returns an iterator to the first element greater than or equal to the given value.
    cout << "Lower bound of 25: " << *s.lower_bound(25) << endl;

    // upper_bound() returns an iterator to the first element strictly greater than the given value.
    cout << "Upper bound of 20: " << *s.upper_bound(20) << endl;

    // Iterating through set gives elements in sorted order.
    cout << "Set: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;


    // unordered_set stores unique elements without maintaining any sorted order.
    // An unordered_set is an STL container that stores unique elements without maintaining any particular order.
    // Duplicate elements are not stored.
    // Insertion, deletion, and searching take O(1) average time, although they can take O(n) in the worst case because it is hash-table based.
    // An unordered_set is generally preferred when we need fast lookup of unique elements and do not care about their order.
    unordered_set<int> us = {40, 10, 30, 20, 20};

    // insert() adds an element; duplicate elements are ignored.
    us.insert(50);

    // find() checks whether an element exists with O(1) average time.
    if (us.find(20) != us.end())
        cout << "20 exists in unordered_set" << endl;

    // count() returns 1 if the element exists and 0 otherwise.
    cout << "Count of 20 in unordered_set: " << us.count(20) << endl;

    // erase(value) removes the specified element.
    us.erase(30);

    // Iteration order of unordered_set is not guaranteed.
    cout << "Unordered set: ";
    for (int x : us)
        cout << x << " ";
    cout << endl;

    // size() returns the number of elements currently stored.
    cout << "Size of unordered_set: " << us.size() << endl;


    // multiset stores elements in sorted order and allows duplicate values.
    // A multiset is an STL container that stores elements in sorted order and allows duplicate elements.
    // Unlike set, the same value can appear multiple times.
    // Insertion, deletion, and searching generally take O(log n) time.
    // A multiset is useful when we need sorted elements while also allowing duplicates.
    multiset<int> ms = {40, 10, 30, 20, 20};

    // insert() adds another copy of the element.
    ms.insert(20);

    // count() returns the total number of occurrences of the given value.
    cout << "Count of 20 in multiset: " << ms.count(20) << endl;

    // find() returns an iterator to one occurrence of the element.
    auto it = ms.find(20);

    // erase(iterator) removes only the occurrence pointed to by the iterator.
    if (it != ms.end())
        ms.erase(it);

    // erase(value) removes all occurrences of that value from a multiset.
    ms.erase(30);

    // lower_bound() returns the first element greater than or equal to the given value.
    cout << "Lower bound of 20: " << *ms.lower_bound(20) << endl;

    // upper_bound() returns the first element strictly greater than the given value.
    cout << "Upper bound of 20: " << *ms.upper_bound(20) << endl;

    // Iterating through multiset gives sorted elements including duplicates.
    cout << "Multiset: ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;


    // empty() checks whether the container contains no elements.
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << endl;

    // clear() removes all elements from the container.
    // s.clear();

    return 0;
}