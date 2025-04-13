#include "car.h"
#include <iostream>
using namespace std;

int Car::carCount = 0;

Car::Car(string lp, string mdl) : licensePlate(lp), model(mdl) {
    carCount++;
}

Car::~Car() {
    carCount--;
    cout << "Car destroyed\n";
}

void Car::info() const {
    cout << "Base Car info\n";
}

void Car::honk() const {
    cout << model << " goes beep-beep!\n";
}

void Car::serviceInfo() const {
    cout << model << " needs regular maintenance.\n";
}

void Car::print() const {
    cout << "Car: " << model << " [" << licensePlate << "]\n";
}
