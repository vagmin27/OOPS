#include<bits/stdc++.h>
using namespace std;

// A friend function is a non-member function that is explicitly given access to a class's private and protected members.

class Chai {
private:
    string teaName;
    int servings;
public:
    // The initializer list is specifically for initializing the members of the object. The member name is already implied.
    // constructor parameters and class data members can have the same name.
    // In an initializer list, the member is identified by the name before the parentheses, while the parameter is the expression inside the parentheses.
    // In the constructor body, we use this->member to distinguish the member from the parameter
    Chai(string teaName, int servings) : teaName(teaName), servings(servings) {} //initialize member teaName using parameter teaName initialize member servings using parameter servings
    // You don't need this-> in an initializer list.

    // It is useful for a class to grant member level access to a function that aren't members of the class or to all members in a separate class
    // These free functions or classes are called as friends
    // Only the class implementer can declare who its friends are.
    friend bool compare(const Chai &c1, const Chai &c2);
    friend void show(Chai);

    void display() {
        cout << "Chai name is: " << teaName << endl;
        cout << "No of servings is: " << servings << endl;
    }
};
// This means compare() is not a member function of Chai, but it is allowed to access the private members of Chai.
// Instead of making servings public, we give only compare() special access.
// So friend functions are useful when an outside function needs access to private data.
// compare() is still a non-member function.

// compare() can access Chai. But Chai does not automatically become a friend of whatever class/function show belongs to.
// Friendship is granted explicitly.
// The friendship does not automatically transfer to a derived class.
bool compare(const Chai &c1, const Chai &c2) {
    return c1.servings > c2.servings;
}

void show(int servings) {
    cout << "Chai is served: " << endl;
}

int main() {
    Chai chai1("Masala Chai", 3);
    Chai chai2("Adhrak Chai", 2);
    Chai chai3("Elaichi Chai", 1);

    chai1.display();
    chai2.display();
    chai3.display();

    // Friendship is granted to the function, not to a particular data member.
    if (compare(chai1, chai2)) {
        cout << "Masala Chai is having more servings" << endl;
    } else {
        cout << "Adhrak Chai is having more servings" << endl;
    }
    
}