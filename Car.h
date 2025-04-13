#pragma once
#include <string>
#include "printable.h"

class Car : public Printable {
protected:
    std::string licensePlate;
    std::string model;

public:
    static int carCount;

    Car(std::string lp = "Unknown", std::string mdl = "Unknown");
    virtual ~Car();

    void info() const;

    virtual void honk() const;
    virtual void serviceInfo() const;
    virtual void charge() const = 0;

    void print() const override;
};
