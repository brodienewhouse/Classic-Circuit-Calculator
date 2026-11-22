//tasks.cpp file where all functions will be
//Georgy, Brodie, Julia - October 18, 2026
//Stubs will be placed for now

#include <iostream>
#include <limits>
#include "tasks.h"
#include "components.h"
#include "circuit.h"
using namespace std;

//--------------------CIRCUIT STORAGE-------------------------
//One circuit shared by every task (task2 adds parts, task3 sets series/parallel, task4 solves)
//Only one source is allowed per circuit (voltage or current)
static Circuit circuit;
static int numResistors = 0; //how many resistors have been added (max is Circuit::MAX_RESISTORS)

//copies of the sources so task2 can name the one being replaced
static VoltageSource voltageSource;
static CurrentSource currentSource;
static bool hasVoltageSource = false;
static bool hasCurrentSource = false;

//--------------------INPUT HELPER-------------------------
//clears random letters
static void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

//--------------------------------------
//Georgy Rached, Writen with Assistance of Claude Opus 5.5
void task1()
{
    cout << "[Help] \n";
    cout << "This program solves V, I, R, and P for a simple DC resistor circuit. \n";
    cout << "Steps: add parts (2), pick series or parallel (3), then calculate (4). \n\n";

    cout << "1. Help: Shows this message. \n";
    cout << "2. Add Components: Add a resistor (ohms), a voltage source (V), or a current source (A). \n";
    cout << "   - Up to " << Circuit::MAX_RESISTORS << " resistors. Resistance cannot be negative. \n";
    cout << "   - Only one source is allowed. Adding a new one replaces the old one. \n";
    cout << "3. Series/Parallel: Choose how the resistors are connected (series is the default). \n";
    cout << "4. Calculate V, I, R, P: Solves the circuit and prints the source, equivalent \n";
    cout << "   resistance, total power, and each resistor's voltage, current, and power. \n";
    cout << "5. Start Front-End Display: Opens the display version of the program. \n";
    cout << "6. Run Tests: Runs test circuits with known answers to check the solver. \n";
    cout << "0. Exit Program: Closes the program. \n\n";

    cout << "Formulas: V = I * R, P = V * I \n";
    cout << "Series: Req = R1 + R2 + ...      Parallel: 1/Req = 1/R1 + 1/R2 + ... \n";
    cout << "Only enter numbers for menu choices and values. \n";
}
//--------------------------------------

//Georgy Rached
void task2()
{
    cout << "[Add Components] \n";
    cout << "1. Resistor \n";
    cout << "2. Voltage Source \n";
    cout << "3. Current Source \n";
    cout << "0. Back \n";
    cout << "Enter a Number For Your Choice: ";

    int type = 0;

    cin >> type;

    if (!cin)
    {
        cout << "Letters Are Not Allowed \n";
        clearInput();
        return;
    }

    //--------------------COMPONENT SELECTION-------------------------
    //picks the value prompt, or leaves early for Back/invalid/full
    string prompt;
    switch (type)
    {
        case 0:
            return; //retuns back to main menu
            
        case 1:
            if (numResistors == Circuit::MAX_RESISTORS)
            {
                cout << "Circuit is Full (Max " << Circuit::MAX_RESISTORS << " Resistors) \n";
                return;
            }
            
            prompt = "Enter Resistance (ohms): "; 
            break;

        case 2:
            prompt = "Enter Voltage (in V): "; 
            break;

        case 3:
            prompt = "Enter Current (in A): "; 
            break;

        //any other inputs go to this message
        default:
            cout << "Please Choose a Valid Option \n";
            return;
    }

    //--------------------NAME AND VALUE INPUT-------------------------
    string name;
    double value;

    cout << "Enter a Name (e.g. R1, V1, I1): ";
    cin >> name;

    cout << prompt;
    cin >> value;

    if (!cin)
    {
        cout << "Value Must Be a Number \n";
        clearInput();
        return;
    }

    //--------------------STORE COMPONENT-------------------------
    //adds the part to the shared circuit
    if (type == 1)
    {
        Resistor r(name, value);
        circuit.addResistor(r);
        numResistors++;
        cout << "Added ";
        r.print();
    }

    else if (type == 2)
    {
        if (hasCurrentSource) 
        {
            cout << "Replacing current source " << currentSource.getName() << "\n";
        }

        voltageSource = VoltageSource(name, value);
        circuit.setSource(voltageSource);
        hasVoltageSource = true;
        hasCurrentSource = false;
        cout << "Added ";
        voltageSource.print();
    
    }

    else
    {
        if (hasVoltageSource) 
        {
            cout << "Replacing voltage source " << voltageSource.getName() << "\n";
        }

        currentSource = CurrentSource(name, value);
        circuit.setCurrentSource(currentSource);
        hasCurrentSource = true;
        hasVoltageSource = false;
        cout << "Added ";
        currentSource.print();
    }
}
//--------------------------------------
void task3()
{
    cout << "[Series/Parallel] \n";

}
//--------------------------------------
void task4()
{
    cout << "[Calculate V, I, R, P] \n";

}
//--------------------------------------
void task5()
{
    cout << "[Start Front-End Display] \n";

}
//--------------------------------------
void task6()
{
    cout << "[Run Tests] \n";

}