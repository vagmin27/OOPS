#include <bits/stdc++.h>
using namespace std;

// A stack in C++ STL is a container adapter that follows the LIFO principle, allowing insertion and deletion only from the top.
// Its main operations are push(), pop(), top(), empty(), and size().
// A stack is a container adapter that follows the LIFO (Last In, First Out) principle, meaning the element inserted last is removed first.
// vector is a general-purpose sequence container that supports random access and iterators, while stack is a container adapter that restricts access to the top element and follows LIFO.

int main() {
    stack<int> st;
    // The underlying container is protected inside the stack adapter, so you should interact with the stack through its public functions such as push(), pop(), and top().
    // push() adds an element to the top of the stack.
    st.push(10);
    st.push(20);
    st.push(30);
    // top() returns the element currently present at the top.
    cout << "Top element: " << st.top() << endl;
    // size() returns the number of elements currently in the stack.
    cout << "Size: " << st.size() << endl;
    // empty() returns true if the stack contains no elements, otherwise false.
    cout << "Is empty: " << st.empty() << endl;

    // pop() removes only the top element and does not return it.
    st.pop();
    cout << "Top after pop: " << st.top() << endl;

    // We can use top() before pop() if we need to store the removed value.
    int x = st.top();
    st.pop();
    cout << "Removed element: " << x << endl;

    // swap() exchanges the contents of two stacks.
    stack<int> st2;
    st2.push(100);
    st2.push(200);
    st.swap(st2);
    cout << "Top of st after swap: " << st.top() << endl;

    // There is no direct reverse() function for std::stack.
    // You generally need another stack or another data structure to reverse its elements.

    if (st == st2) { // the comparison is based on the elements in the underlying containers.
        cout << "Equal";
    }

    // Stack overflow occurs when there is an attempt to put more data into a stack than its available capacity.
    // In the context of std::stack, memory exhaustion is more relevant because it is dynamically resizable, unlike a fixed-size stack implementation.
}