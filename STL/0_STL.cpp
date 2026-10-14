#include <bits/stdc++.h>
using namespace std;

// STL (Standard Template Library) is a collection of pre-built, reusable classes and functions in C++ that help us perform common programming tasks easily and efficiently.
// Instead of implementing data structures and algorithms from scratch, we can use STL components directly.
//  Main Components of STL
// STL is mainly divided into 4 parts:
// 1. Containers Store and organize data.

// vector
// list
// deque
// stack
// queue
// priority_queue
// set
// map
// unordered_set
// unordered_map

// 2. Algorithms Perform operations on data.

// sort()
// reverse()
// find()
// binary_search()
// max()
// min()
// count()

// 3. Iterators Used to traverse/access elements of containers.

// begin()
// end()
// rbegin()
// rend()

// 4. Function Objects (Functors) Objects that can behave like functions and can be passed to algorithms.
int main() {
    vector<int> v = {5, 2, 8, 1, 3};

    sort(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}

// Here:
// vector → containersort() → algorithmbegin() and end() → iterators
// STL is a collection of template-based containers, algorithms, iterators, and function objects provided by C++ that allows us to implement common data structures and operations efficiently and with reusable code.

// STL = Containers + Algorithms + Iterators + Function Objects.