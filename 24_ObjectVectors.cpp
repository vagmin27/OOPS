#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student() {
        age = 0;
    }

    Student(string name) {
        this->name = name;
        age = 0;
    }

    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

int main() {

    vector<Student> students;

    Student s1;
    s1.name = "Rahul";
    s1.age = 20;

    Student s2("Vagmin", 20);

    Student s3("Vishnu");
    s3.age = INT_MAX;

    // Creates an object first and then adds it to the vector
    students.push_back(s1);

    cout << students[0].name << endl;
    cout << students[0].age << endl;

    students.push_back(s2);
    students.push_back(s3);

    // Constructs the object directly inside the vector
    students.emplace_back("Hari", 20);
    students.emplace_back("Aman", 21);
    students.emplace_back("Priya", 19);

    // Normal index-based loop
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << students[i].age << endl;
    }

    // Range-based loop
    for (Student s : students) {
        cout << s.name << " " << s.age << endl;
    }

    // Reference-based loop
    for (Student &s : students) {
        cout << s.name << " " << s.age << endl;
    }

    // Const reference
    for (const Student &s : students) {
        cout << s.name << " " << s.age << endl;
    }

    // Sort students according to age
    sort(students.begin(), students.end(),
        [](Student &a, Student &b) {
            return a.age < b.age;
        }
    );

    cout << "After sorting by age:";
    for (const Student &s : students) {
        cout << s.name << " " << s.age << endl;
    }
    return 0;
}