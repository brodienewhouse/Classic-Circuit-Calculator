// components.h file where the component classes are declared
// Brodie - November 14, 2026
// circuit.h and tasks.cpp will include this file to use Resistor and VoltageSource classes

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>
using namespace std;

//-------------------------------------
// Resistor Class Declaration (T2 - Brodie)
// Stores one resistor and its values
// Voltage and current start at 0 and are updated when the circuit is solved
class Resistor {
private: 
    string name; // Label for resistor
    double res; // Resistance in ohms
    double volts; // Voltage across resistor
    double amps; // Current through resistor

public:
    // Constructors
    Resistor(); // Default
    Resistor(string name, double res); // Constructor

    // Getters
    string getName() const; 
    double getResistance() const;
    double getVoltage() const;
    double getCurrent() const;

    // Stores solved volts and amps
    void setValues(double volts, double amps);

    // Returns power used
    double power() const;

    // Prints resistor info to console
    void print() const;

};

//-------------------------------------
// VoltageSource Class Declaration (T2 - Brodie)
// Stores one voltage source and its values
// Stores DC source that powers the circuit
class VoltageSource {
private:
    string name; // Label for voltage source
    double voltage; // Voltage in volts

public:
    // Constructors
    VoltageSource(); // Default
    VoltageSource(string name, double voltage); // Constructor

    // Getters
    string getName() const; 
    double getVoltage() const;

    // Stores changed voltage
    void setVoltage(double voltage);

    // Prints voltage source info to console
    void print() const;

};

#endif
