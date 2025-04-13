#pragma once
#include "printable.h"

class Ticket : public Printable {
private:
    int ticketNumber;
    double price;

public:
    Ticket(int num = 0, double p = 10.0);
    void print() const override;
};
