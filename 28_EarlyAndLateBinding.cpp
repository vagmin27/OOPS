#include<iostream>
using namespace std;
// class A { //Early Binding
// public:
//     void show() {
//         cout << "class A" << endl;
//     }
// };

class A {
public:
    virtual void show() {
        cout << "class A" << endl;
    }
};

class B : public A {
public:
    void show() {
        cout << "class B" << endl;
    }
};

int main() {
    A *a = new B();
    a->show();
    return 0;

}