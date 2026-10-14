#include <bits/stdc++.h>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);  // Adds 10 at the back
    q.push(20);  // Adds 20 at the back
    q.push(30);  // Adds 30 at the back

    cout << "Front: " << q.front() << endl;  // Returns first element: 10
    cout << "Back: " << q.back() << endl;    // Returns last element: 30
    cout << "Size: " << q.size() << endl;    // Returns number of elements: 3

    q.pop();  // Removes only the front element, so 10 is removed

    cout << "Front after pop: " << q.front() << endl;  // 20

    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}