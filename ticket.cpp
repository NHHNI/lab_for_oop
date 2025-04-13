#include "ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket(int num, double p) : ticketNumber(num), price(p) {}

void Ticket::print() const {
    cout << "Ticket #" << ticketNumber << " | Price: $" << price << endl;
}
