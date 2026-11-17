// components.cpp file where the component classes are written
// Brodie - November 16, 2026
// Declarations are in components.h

#include <iostream>
#include "components.h"
using namespace std;

//==================RESISTOR====================

//-----------------Constructors-----------------
// Default constructor
Resistor::Resistor() {
    name = "R";
    res = 0.0;
    volts = 0.0;
    amps = 0.0;
}

// Main constructor
Resistor::Resistor(string name, double res) {
    this->name = name;
    volts = 0;
    amps = 0;

    if (res < 0) {
        cout << "Resistance cannot be negative. " << name << ": Resistance set to 0." << endl;
        this->res = 0;
    }
    else {
        this->res = res;
    }
}

//-----------------Getters-----------------
string Resistor::getName() const {
    return name;
}

double Resistor::getResistance() const {
    return res;
}

double Resistor::getVoltage() const {
    return volts;
}

double Resistor::getCurrent() const {
    return amps;
}

//-----------------Setters-----------------
// Called by circuit after solving to store V and I
void Resistor::setValues(double volts, double amps) {
    this->volts = volts;
    this->amps = amps;
}

//-----------------Power-----------------
// P=V*I
double Resistor::getPower() const {
    return volts * amps;
}

//-----------------Print-----------------
void Resistor::print() const {
    cout << name << ": " << res << " ohms, " << volts <<
    " V, " << amps << " A, " << getPower() << " W" << endl;
}

//==================VOLTAGE SOURCE====================

//-----------------Constructors-----------------
// Default constructor
VoltageSource::VoltageSource() {
    name = "V";
    voltage = 0.0;
    current = 0.0;
}

// Main constructor
VoltageSource::VoltageSource(string name, double voltage) {
    this->name = name;
    this->voltage = voltage;
    current = 0.0;
}

//-----------------Getters-----------------
string VoltageSource::getName() const {
    return name;
}

double VoltageSource::getVoltage() const {
    return voltage;
}

double VoltageSource::getCurrent() const {
    return current;
}

//-----------------Power-----------------
// P = V * I (power delivered by source)
double VoltageSource::getPower() const {
    return voltage * current;
}

//-----------------Setters-----------------
// Changes voltage of source
void VoltageSource::setVoltage(double voltage) {
    this->voltage = voltage;
}

// Sets current
void VoltageSource::setCurrent(double current) {
    this->current = current;
}

//-----------------Print-----------------
void VoltageSource::print() const {
    cout << name << ": " << voltage << " V, " << current <<
    " A, " << getPower() << " W" << endl;
}

//==================CURRENT SOURCE====================

//-----------------Constructors-----------------
// Default constructor
CurrentSource::CurrentSource() {
    name = "I";
    current = 0.0;
    voltage = 0.0;
}

// Main constructor
CurrentSource::CurrentSource(string name, double current) {
    this->name = name;
    this->current = current;
    voltage = 0.0;
}

//-----------------Getters-----------------
string CurrentSource::getName() const {
    return name;
}

double CurrentSource::getCurrent() const {
    return current;
}

double CurrentSource::getVoltage() const {
    return voltage;
}

//-----------------Power-----------------
// P = V * I (power delivered by source)
double CurrentSource::getPower() const {
    return voltage * current;
}

//-----------------Setters-----------------
// Changes current of source
void CurrentSource::setCurrent(double current) {
    this->current = current;
}

// Sets the voltage
void CurrentSource::setVoltage(double voltage) {
    this->voltage = voltage;
}

//-----------------Print-----------------
void CurrentSource::print() const {
    cout << name << ": " << current << " A, " << voltage <<
    " V, " << getPower() << " W" << endl;
}

