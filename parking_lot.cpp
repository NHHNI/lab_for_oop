#include "parking_lot.h"
#include <iostream>
using namespace std;

ParkingLot::ParkingLot(int cap, int occ) : capacity(cap), occupied(occ) {}

void ParkingLot::print() const {
    cout << "Parking Lot: " << occupied << "/" << capacity << " occupied.\n";
}
