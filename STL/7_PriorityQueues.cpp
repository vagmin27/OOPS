#include <iostream>
#include <queue>
#include <vector>
#include <functional> // #include <functional> is a standard library header that provides tools related to functions, function objects, and callable objects.
// header that provides predefined function objects and utilities for working with callable objects, such as greater<> and less<>.
// we need it because greater<int> is defined in <functional>.
using namespace std;

// A priority queue stores elements according to priority, and the highest-priority element is always available at the top.
// A priority queue is a container adapter in STL where each element has a priority, and the element with the highest priority is always available at the top.
class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }
};

// Custom comparator: Student with higher marks gets higher priority.
struct Compare {
    bool operator()(Student a, Student b) {
        return a.marks < b.marks;
    }
};

// Priority queues are heavily used in Dijkstra's algorithm, Prim's algorithm, scheduling, Huffman coding, and top-K problems.

int main() {

    // Custom priority queue using Student objects.
    // The Student with the highest marks will be at the top.
    priority_queue<Student, vector<Student>, Compare> pq;

    pq.push(Student("Rahul", 85));
    pq.push(Student("Aman", 95));
    pq.push(Student("Vikas", 90));

    // top() returns the highest-priority element without removing it.
    cout << pq.top().name << " " << pq.top().marks << endl;

    // Default priority_queue is a max-heap,
    // so the largest integer always comes at the top.
    // That depends on the comparator and the type of elements.
    // A priority_queue does not guarantee stable ordering between elements having equal priority.
    // So you should not assume that the element inserted first will come out first.
    // It provides a restricted interface over an underlying container, usually a vector, while maintaining heap properties.
    priority_queue<int> pq1;

    // push() inserts an element into the priority queue.
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);

    // emplace() constructs and inserts the element directly.
    pq1.emplace(4);

    // Elements are removed according to priority, not insertion order.
    while (!pq1.empty()) {
        cout << pq1.top() << " ";

        // pop() removes the highest-priority element.
        // It does not return the removed element.
        pq1.pop();
    }

    cout << endl;

    // size() returns the number of elements currently present.
    cout << pq.size() << endl;

    // Min-heap: the smallest element has the highest priority.
    priority_queue<int, vector<int>, greater<int>> q; // greater<int> is a predefined comparator provided by the <functional> header.
    // Basically it tells Give higher priority to the smaller value
    // So greater<int> creates a min heap

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}