#include <bits/stdc++.h>
using namespace std;

// A friend class is a class whose member functions are allowed to access the private and protected members of another class.
// It is given special permission to access the private and protected members of another class.

// Chai is a class that contains private data.
class Chai {
private:
    // Private data member.
    // It can normally be accessed only inside the Chai class.
    int servings = 5;

    // Friend class declaration.
    // This gives the Helper class permission to access
    // private and protected members of Chai.
    friend class Helper;
};


// Helper is a separate class.
class Helper {
public:
    // This function takes a reference to a Chai object.
    void show(Chai &c) {
        // Although servings is private in Chai,
        // Helper can access it because Helper is declared
        // as a friend class of Chai.
        cout << "Servings: " << c.servings << endl;
    }

    // Function to modify the private data of Chai.
    void change(Chai &c) {
        // Normally this would be illegal because servings is private.
        // But Helper is a friend class, so it is allowed.
        c.servings = 10;
    }
};

// // friend class Helper has access to Chai's private/protected members.
// Friendship does not mean inheritance.
// Friendship is not automatically mutual.
// Friendship is not inherited.
// You declare friendship inside the class whose private data you want to expose.

int main() {
    Chai c;
    Helper h;
    // Helper accesses Chai's private member servings.
    h.show(c);
    // Helper modifies Chai's private member servings.
    h.change(c);
    // Showing the changed value.
    h.show(c);
    return 0;
}