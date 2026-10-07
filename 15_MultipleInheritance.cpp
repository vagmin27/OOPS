#include <bits/stdc++.h>
using namespace std;

// Multiple inheritance is a type of inheritance where one derived class inherits from more than one base class.
class Engine {
public:
    int horsepower;
    void showEngine() {
        cout << "Horsepower: " << horsepower << endl;
    }
};

class Vehicle {
public:
    string brand;
    void showVehicle() {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Engine, public Vehicle {
public:
    int seats;
    void showCar() {
        cout << "Seats: " << seats << endl;
    }
};
// Car gets:
// horsepower and showEngine() from Engine
// brand and showVehicle() from Vehicle
// seats and showCar() from itself
// So, Multiple Inheritance = One child class + Multiple parent classes.

int main() {
    // multiple inheritance allows a class to combine features from multiple independent classes.
    Car c;
    c.horsepower = 150;
    c.brand = "Toyota";
    c.seats = 5;

    c.showEngine();
    c.showVehicle();
    c.showCar();
    return 0;
}