#pragma once
#include "car.h"

class ElectricCar final : public Car {
public:
    ElectricCar(string lp = "UnknownEV", string mdl = "Tesla");

    void honk() const override;
    void serviceInfo() const override final;
    void charge() const override;
};

