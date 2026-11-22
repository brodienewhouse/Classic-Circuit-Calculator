//tasks.cpp file where all functions will be
//Georgy, Brodie, Julia - October 18, 2026
//Stubs will be placed for now

#include <iostream>
#include <limits>
#include "tasks.h"
#include "components.h"
#include "circuit.h"
using namespace std;

//--------------------COMPONENT STORAGE-------------------------
//Temporary storage until the circuit class (circuit.h) is written
//Only one source is allowed per circuit (voltage or current)
const int MAX_RESISTORS = 10; //max number of allowed resisotrs
static Resistor resistors[MAX_RESISTORS];
static int numResistors = 0; 
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
void task1() 
{ 
    cout << "[Help] \n"; 

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
            if (numResistors == MAX_RESISTORS)
            {
                cout << "Circuit is Full (Max " << MAX_RESISTORS << " Resistors) \n";
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
    if (type == 1)
    {
        resistors[numResistors] = Resistor(name, value);
        cout << "Added ";
        resistors[numResistors].print();
        numResistors++;
    }

    else if (type == 2)
    {
        if (hasCurrentSource) 
        {
            cout << "Replacing current source " << currentSource.getName() << "\n";
        }

        voltageSource = VoltageSource(name, value);
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