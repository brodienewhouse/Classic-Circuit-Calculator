// circuit.h file where the Circuit class is declared
// Julia Terceros


#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "components.h"
using namespace std;


//------------------------------------
// Circuit Class Declaration (T3/T4 - Julia)
// Holds the resistors and one source (voltage or current)
// Combines resistors in series or parallel and solves V, I, R, P
// Only one source is used at a time, setting one replaces the other




class Circuit{
    private:
        vector<Resistor> resistors; // List of every resistor in the circuit
        VoltageSource source;  // Voltage source (used when usesCurrentSource is false)
        CurrentSource currentSource; //Current source (used when usesCurrentSource is true)
        
        
        bool isSeries; //true = series, false = parallel
        bool usesCurrentSource; //true = current source, false = voltage source

    public:
        Circuit(); //Constructor, empty circuit

        //Setters
        void addResistor(const Resistor &r); // Adds resistor to list
        void setSource(const VoltageSource &v); //Sets voltage source to circuit 
        void setCurrentSource(const CurrentSource &I); // Sets a current source (replaces voltage source)
        void setSeries(bool series); //Chooses series or parallel resistors
        

        //T3: Calculates total resistance based on whether the resistors are parallel or in series
        double equivalentResistance() const; //Calculates total resistance

        //T4: Solves V and I for every resistor and the source
        void solve(); 

        //T4: Prints source, equivalent resistance, total power, and each resistor's V, I, R, P
        void printResults() const;

        
};




#endif