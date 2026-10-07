#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float cgpa;
    // Getters and setters are member functions used to access and modify private data members of a class.
    // They are mainly used to achieve encapsulation, where the internal data of an object is protected from direct access
public:
    // Setter for name. Here setName() assigns a new value to the private name variable.
    // A setter is a function used to modify/set the value of a private data member.
    void setName(string name) {
        this->name = name;
    }

    // Getter for name. Here getName() returns the value of the private name variable.
    // A getter is a function used to read/access the value of a private data member.
    string getName() {
        return name;
    }

    // Setter for roll number
    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }

    // Getter for roll number
    int getRollNo() {
        return rollNo;
    }

    // Setter for CGPA
    // Setters can also validate data before storing it.
    void setCgpa(float cgpa) {
        if (cgpa >= 0 && cgpa <= 10) {
            this->cgpa = cgpa;
        }
    }

    // Getter for CGPA
    float getCgpa() {
        return cgpa;
    }
};

int main() {
    // This is encapsulation: keeping the data protected and providing controlled access through member functions.
    Student s;

    // s.name = "Vagmin";  // Not allowed
    // s.rollNo = 101;  // Not allowed
    // s.cgpa = 9.69;  // Not allowed
    // Setting values
    s.setName("Vagmin");
    s.setRollNo(101);
    s.setCgpa(9.69);

    // Getting values
    cout << s.getName() << endl;
    cout << s.getRollNo() << endl;
    cout << s.getCgpa() << endl;

    return 0;
}