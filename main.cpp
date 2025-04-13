#include <iostream>
#include <vector>
#include "electric_car.h"
#include "ticket.h"
#include "parking_lot.h"

using namespace std;

int main() {
    cout << "=== Static Binding Problem ===\n";
    Car* basePtr;
    ElectricCar ev("EV1234", "Tesla Model S");
    basePtr = &ev;
    basePtr->info(); // викликає не virtual метод

    cout << "\n=== Dynamic Polymorphism (Pointer) ===\n";
    basePtr->honk();
    basePtr->serviceInfo();
    basePtr->charge();

    cout << "\n=== Dynamic Polymorphism (Reference) ===\n";
    Car& baseRef = ev;
    baseRef.honk();
    baseRef.serviceInfo();
    baseRef.charge();

    cout << "\n=== Interface Demonstration ===\n";
    vector<Printable*> items;
    items.push_back(new ElectricCar("EV9999", "Nissan Leaf"));
    items.push_back(new Ticket(101, 15.0));
    items.push_back(new ParkingLot(100, 25));

    for (auto item : items)
        item->print();

    for (auto item : items)
        delete item;

    cout << "\nTotal cars: " << Car::carCount << endl;
    return 0;
}
