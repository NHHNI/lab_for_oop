#include "electric_car.h"
#include <iostream>
using namespace std;

ElectricCar::ElectricCar(string lp, string mdl) : Car(lp, mdl) {}

void ElectricCar::honk() const {
    cout << model << " goes tsssss (electric honk)!\n";
}

void ElectricCar::serviceInfo() const {
    cout << model << " requires battery check and software update.\n";
}

void ElectricCar::charge() const {
    cout << model << " is charging at the station.\n";
}
