#include <bits/stdc++.h>
using namespace std;

int main() {

    // A pair stores exactly two related values, and the two values can have different data types.
    pair<int, string> p1 = {101, "Rahul"};

    // first accesses the first value and second accesses the second value.
    cout << "First: " << p1.first << endl;
    cout << "Second: " << p1.second << endl;

    // A pair can be modified using first and second.
    p1.first = 102;
    p1.second = "Aman";

    cout << "Modified pair: " << p1.first << " " << p1.second << endl;

    // make_pair() creates a pair by automatically deducing the data types.
    auto p2 = make_pair(103, "Riya");

    cout << "make_pair(): " << p2.first << " " << p2.second << endl;

    // A pair can store two values of the same data type.
    pair<int, int> p3 = {10, 20};

    cout << "p3: " << p3.first << " " << p3.second << endl;

    // Pairs are compared lexicographically: first is compared first,
    // and second is compared if the first values are equal.
    pair<int, int> p4 = {10, 20};
    pair<int, int> p5 = {10, 30};

    if (p4 < p5) {
        cout << "p4 is smaller than p5" << endl;
    }

    // Two pairs can be swapped.
    p4.swap(p5);

    cout << "After swapping p4: " << p4.first << " " << p4.second << endl;
    cout << "After swapping p5: " << p5.first << " " << p5.second << endl;

    // A vector of pairs stores multiple pairs and allows duplicate first values.
    vector<pair<int, int>> v;

    v.push_back({3, 30});
    v.push_back({1, 10});
    v.push_back({3, 20});
    v.push_back({2, 40});
    v.push_back({1, 50});

    cout << "\nVector of pairs:" << endl;

    // Accessing a pair inside a vector using its index.
    cout << "First pair: " << v[0].first << " " << v[0].second << endl;

    // Traversing a vector of pairs using a range-based loop.
    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    // Structured binding directly extracts first and second from each pair.
    // Structured bindings require C++17 or later.
    cout << "\nUsing structured binding:" << endl;

    for (auto [first, second] : v) {
        cout << first << " " << second << endl;
    }

    // Sorting a vector of pairs uses lexicographical ordering by default.
    // First values are sorted first, and second values are used when first values are equal.
    sort(v.begin(), v.end());

    cout << "\nSorted vector of pairs:" << endl;

    for (auto [first, second] : v) {
        cout << first << " " << second << endl;
    }

    // A custom comparator can sort pairs according to the second value.
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    cout << "\nSorted according to second value:" << endl;

    for (auto [first, second] : v) {
        cout << first << " " << second << endl;
    }

    // An unordered_map stores unique keys and their associated values.
    unordered_map<int, int> mp;

    mp[1] = 100;
    mp[2] = 200;
    mp[3] = 300;

    cout << "\nUnordered map:" << endl;

    // When traversing an unordered_map, first represents the key
    // and second represents the mapped value.
    for (auto [key, value] : mp) {
        cout << key << " -> " << value << endl;
    }

    // unordered_map provides average O(1) lookup by key.
    cout << "Value of key 2: " << mp[2] << endl;

    // unordered_map does not allow duplicate keys.
    // Assigning another value to the same key replaces the previous value.
    mp[1] = 500;

    cout << "Updated value of key 1: " << mp[1] << endl;

    // A vector<pair<int,int>> can contain duplicate first values.
    vector<pair<int, int>> duplicatePairs;

    duplicatePairs.push_back({1, 10});
    duplicatePairs.push_back({1, 20});
    duplicatePairs.push_back({2, 30});

    cout << "\nVector containing duplicate first values:" << endl;

    for (auto [key, value] : duplicatePairs) {
        cout << key << " -> " << value << endl;
    }

    // Converting vector<pair<int,int>> to unordered_map.
    // The first value becomes the key and the second value becomes the mapped value.
    unordered_map<int, int> convertedMap;

    for (auto [key, value] : duplicatePairs) {
        convertedMap[key] = value;
    }

    cout << "\nConverted unordered_map:" << endl;

    for (auto [key, value] : convertedMap) {
        cout << key << " -> " << value << endl;
    }

    // Because key 1 appeared twice, the last value overwrites the previous value.
    cout << "Value of key 1 after conversion: " << convertedMap[1] << endl;

    // If one key needs multiple values, use unordered_map<int, vector<int>>.
    unordered_map<int, vector<int>> graph;

    graph[1].push_back(10);
    graph[1].push_back(20);
    graph[1].push_back(30);

    graph[2].push_back(40);
    graph[2].push_back(50);

    cout << "\nUnordered map with multiple values per key:" << endl;

    for (auto [key, values] : graph) {
        cout << key << " -> ";

        for (int value : values) {
            cout << value << " ";
        }

        cout << endl;
    }

    // This structure is commonly used for graph adjacency lists.
    unordered_map<int, vector<int>> adjacencyList;

    adjacencyList[1].push_back(2);
    adjacencyList[1].push_back(3);
    adjacencyList[2].push_back(4);

    cout << "\nGraph adjacency list:" << endl;

    for (auto [node, neighbours] : adjacencyList) {
        cout << node << " -> ";

        for (int neighbour : neighbours) {
            cout << neighbour << " ";
        }

        cout << endl;
    }

    // A vector<pair<int,int>> can represent edges as {source, destination}.
    vector<pair<int, int>> edges;

    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 4});

    cout << "\nEdges stored as vector of pairs:" << endl;

    for (auto [source, destination] : edges) {
        cout << source << " -> " << destination << endl;
    }

    // A pair can contain another pair.
    pair<int, pair<int, int>> nestedPair = {1, {10, 20}};

    cout << "\nNested pair:" << endl;
    cout << nestedPair.first << endl;
    cout << nestedPair.second.first << endl;
    cout << nestedPair.second.second << endl;

    // A pair can be used to store two values returned from a function.
    pair<int, int> result = make_pair(100, 200);

    cout << "\nPair used for two values:" << endl;
    cout << result.first << " " << result.second << endl;

    return 0;
}