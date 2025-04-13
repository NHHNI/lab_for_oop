#pragma once
#include "printable.h"

class ParkingLot : public Printable {
private:
    int capacity;
    int occupied;

public:
    ParkingLot(int cap = 50, int occ = 0);
    void print() const override;
};
