// components.h file where the component classes are declared
// Brodie - November 14, 2026
// circuit.h and tasks.cpp will include this file to use Resistor, VoltageSource, and CurrentSource classes

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
    double getPower() const;

    // Stores solved volts and amps
    void setValues(double volts, double amps);

    // Prints resistor info to console
    void print() const;

};

//-------------------------------------
// VoltageSource Class Declaration (T2 - Brodie)
// Stores one voltage source and its values
// Stores DC source that powers the circuit
// Current starts at 0 and is updated when the circuit is solved
class VoltageSource {
private:
    string name; // Label for voltage source
    double voltage; // Fixed voltage in volts (set by user)
    double current; // Current through source (set by solver)

public:
    // Constructors
    VoltageSource(); // Default
    VoltageSource(string name, double voltage); // Constructor

    // Getters
    string getName() const;
    double getVoltage() const;
    double getCurrent() const;
    double getPower() const;

    // Setters
    void setVoltage(double voltage);
    void setCurrent(double current); // Called by circuit after solving

    // Prints voltage source info to console
    void print() const;

};

//-------------------------------------
// CurrentSource Class Declaration (T2 - Georgy)
// Stores one current source and its values
// Stores DC current source that powers the circuit
// Voltage starts at 0 and is updated when the circuit is solved
class CurrentSource {
private:
    string name; // Label for current source
    double current; // Fixed current in amps (set by user)
    double voltage; // Voltage across source (set by solver)

public:
    // Constructors
    CurrentSource(); // Default
    CurrentSource(string name, double current); // Constructor

    // Getters
    string getName() const;
    double getCurrent() const;
    double getVoltage() const;
    double getPower() const;

    // Setters
    void setCurrent(double current);
    void setVoltage(double voltage); // Called by circuit after solving

    // Prints current source info to console
    void print() const;

};

#endif
