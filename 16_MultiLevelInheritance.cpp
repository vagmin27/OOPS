#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
    int speed;
    string fuel;
    // This is the base class.
    // It contains common properties of vehicles.
    void showVehicle() {
        cout << "Speed: " << speed << endl;
        cout << "Fuel: " << fuel << endl;
    }
};

class Car : public Vehicle {
    // Car gets the accessible members of Vehicle.
public:
    int seats;

    void showCar() {
        cout << "Seats: " << seats << endl;
    }
};

class SportsCar : public Car {
    // SportsCar gets the accessible members of Car.
    // Since Car itself inherited from Vehicle, SportsCar can also access the inherited members of Vehicle.
public:
    bool turbo;

    void showSportsCar() {
        cout << "Turbo: " << turbo << endl;
    }
};
// SportsCar is-a Car, and Car is-a Vehicle. Therefore: SportsCar is also a Vehicle.
// This is the main idea behind multilevel inheritance.
int main() {

    SportsCar s;

    s.speed = 250;       // From Vehicle
    s.fuel = "Petrol";   // From Vehicle
    s.seats = 2;         // From Car
    s.turbo = true;      // From SportsCar

    s.showVehicle();
    s.showCar();
    s.showSportsCar();

    return 0;
}