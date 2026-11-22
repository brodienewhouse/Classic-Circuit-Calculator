//circuit.cpp file where the Circuit class functions are written
//Julia Terceros
//Declarations are in circuit.h

#include <iostream>
#include "circuit.h"
using namespace std;


//-----------------Constructor-----------------
Circuit::Circuit() {
    isSeries = true;
    usesCurrentSource = false;
}

//-----------------Setters-----------------
//Adds a resistor to the list
void Circuit::addResistor(const Resistor &r){
    resistors.push_back(r);
}

//Sets a voltage source (replaces current source)
void Circuit::setSource(const VoltageSource &v){
    source = v;
    usesCurrentSource = false;
}

//Sets a current source (replaces voltage source)
void Circuit::setCurrentSource(const CurrentSource &I){
    currentSource = I;
    usesCurrentSource = true;
}
//Chooses series (true) or parallel (false)
void Circuit::setSeries(bool series){

    isSeries = series;

}

//-----------------T3: Equivalent Resistance-----------------
//Series:   Req = R1 + R2 + ...
//Parallel: 1/Req = 1/R1 + 1/R2 + ...
double Circuit::equivalentResistance() const {
    double total = 0;

    //Req is calcualted based on whether the resistors and in parallel or series
    if (resistors.size() == 0){
        return 0;
    } 

    //Add up R (series) or 1/R (parallel) for every resistor
    for (int i = 0; i < resistors.size(); i++){
        double R = resistors[i].getResistance();

        if (isSeries) {
            total = total + R;
        } else{
            total = total + (1.0/R);
        }
    }

    //Parallel sum is 1/Req, so flip total
    if (isSeries){
            return total;
        } else {
            return (1.0 / total);
        }
}

//-----------------T4: Solve-----------------
//Finds V and I for the source and every resistor
//P is calculated from V and I by getPower()
void Circuit::solve(){
    double Req = equivalentResistance();
    double totalCurrent;
    double totalVoltage;

    //Checks if there are resistors, 
    if (resistors.size() == 0){
        cout << "Error:No resistors in circuit." << endl;
        return;

    }

    //Check is Req is zero, if it is then short circuit

    if (Req == 0){
        cout << "Error: Short Circuit." << endl;
        return;
    }

    //Find total voltage and current based on which source is used
    if (usesCurrentSource){
        totalCurrent = currentSource.getCurrent();   //Current is known
        totalVoltage = totalCurrent * Req;           //V = I*R
        currentSource.setVoltage(totalVoltage);      //Store voltage in source
    } else {
        totalVoltage = source.getVoltage();          //Voltage is known
        totalCurrent = totalVoltage / Req;           //I = V/R
        source.setCurrent(totalCurrent);             //Store current in source
    }


    //Will go through each resistor, and solve the voltage and current
    for (int i = 0; i < resistors.size(); i++) {
        double R = resistors[i].getResistance();

        if (isSeries){
            double voltage = totalCurrent * R; //When in series, same current through resistors
            resistors[i].setValues(voltage, totalCurrent);
        }else{
            double current = totalVoltage/R; //When in parallel, same voltage across every resistor
            resistors[i].setValues(totalVoltage,current);

        }
    }


}

//-----------------T4: Print Results-----------------
//Prints the source, Req, total power, and each resistor
void Circuit::printResults() const {
    double Req = equivalentResistance();
    

    cout << "\n***Circuit Results***" << endl;

    cout << "\n***Source***" << endl;
    if (usesCurrentSource){
        currentSource.print();
    } else {
        source.print();
    }


    if (isSeries) {
        cout << "Resistors in: Series" << endl;
    } else {
        cout << "Resistors in: Parallel" << endl;
    }

    //Totals
    cout << "Equivalent Resistance: " << Req << " ohms" << endl;

    //Total Power of Circuit
    if (usesCurrentSource){
        cout << "Total Power: " << currentSource.getPower() << " W" << endl;
    } else {
        cout << "Total Power: " << source.getPower() << " W" << endl;
    }

    //Print each resistor and their traits
    cout << "\n***Resistors***" << endl;
    for (int i = 0; i < resistors.size(); i++) {
        resistors[i].print();
    }



}

