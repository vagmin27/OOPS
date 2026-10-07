#include <bits/stdc++.h>
using namespace std;

// Hierarchical inheritance is a type of inheritance where multiple child/derived classes inherit from one common parent/base class.
// Vehicle is the parent/base class, and Bike, Car, and Truck are child/derived classes.
class Vehicle {
public:
    // Instead of writing these properties separately in Bike, Car, and Truck, we define them once in Vehicle.
    int speed;
    float mileage;
    string fuel;
    int seats;
    bool gears;
};

class Bike : public Vehicle {
    // a Bike object gets the properties of Vehicle
public:
    bool footRest; // footRest is specific to the Bike class.
};
class Car : public Vehicle { // Car also inherits from Vehicle.
public:
    bool roof;
    bool ac;
    bool heater;
};
class Truck : public Vehicle { // Truck also inherits from Vehicle.
public:
    double loadSpace;
    double loadCapacity;
    int wheels;
    bool gearBox;
};
// Hierarchical inheritance allows multiple classes to reuse the common properties and functions of one base class while also having their own specialized properties and functions.
// Hierarchical inheritance is a type of inheritance in which multiple derived classes inherit from a single base class.
int main() {

    Bike b;
    b.speed = 100;
    b.mileage = 50.5;
    b.fuel = "Petrol";
    b.seats = 2;
    b.gears = true;
    b.footRest = true;

    Car c;
    c.speed = 180;
    c.mileage = 18.5;
    c.fuel = "Petrol";
    c.seats = 5;
    c.gears = true;
    c.roof = true;
    c.ac = true;
    c.heater = true;

    Truck t;
    t.speed = 80;
    t.mileage = 8.5;
    t.fuel = "Diesel";
    t.seats = 3;
    t.gears = true;
    t.loadSpace = 500;
    t.loadCapacity = 10000;
    t.wheels = 10;
    t.gearBox = true;

    cout << "Bike Speed: " << b.speed << endl;
    cout << "Bike FootRest: " << b.footRest << endl;
    cout << "Car Speed: " << c.speed << endl;
    cout << "Car AC: " << c.ac << endl;
    cout << "Truck Speed: " << t.speed << endl;
    cout << "Truck Load Capacity: " << t.loadCapacity << endl;

    return 0;
}