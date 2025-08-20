
// Vehicle.cpp
#include "Vehicle.h"

// Default constructor
Vehicle::Vehicle() : id(0), speed(0.0), temperature(0.0), fuel(0.0) {}

// Parameterized constructor
Vehicle::Vehicle(int id, double speed, double temperature, double fuel)
    : id(id), speed(speed), temperature(temperature), fuel(fuel) {}

// Getters
int Vehicle::getId() const { return id; }
double Vehicle::getSpeed() const { return speed; }
double Vehicle::getTemperature() const { return temperature; }
double Vehicle::getFuel() const { return fuel; }

// Setters
void Vehicle::setId(int id) { this->id = id; }
void Vehicle::setSpeed(double speed) { this->speed = speed; }
void Vehicle::setTemperature(double temperature) { this->temperature = temperature; }
void Vehicle::setFuel(double fuel) { this->fuel = fuel; }
