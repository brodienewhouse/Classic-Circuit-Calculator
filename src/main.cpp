//Main Menu, Calls One Function
//By Georgy Rached - October 18, 2026

//--------------------DECLARATIONS-------------------------
//importing neccesary libraries and other needed files
#include <iostream>
#include "tasks.h"
using namespace std;

//--------------------MAIN FUNCTION-------------------------
//main function
int main()
{
    //declaring variable that will be input from user
    int choice; 

    //start do-while loop
    do
    {
        //--------------------MENU OUTPUT-------------------------
        //Outputting Terminal Options
        cout << "\n--- Simpler Circuit Solver Menu ---\n";
        cout << "1. Help \n";
        cout << "2. Add Components (sources/resistors) \n";
        cout << "3. Series/Parallel Connection \n";
        cout << "4. Calculate V, I, R, P\n";
        cout << "5. Start Front-End Display\n";
        cout << "6. Run Tests\n";
        cout << "0. Exit Program\n";
        cout << "Enter a Number For Your Choice: ";
        cin >> choice;

        //--------------------INPUT VALIDATION-------------------------
        //letters exit code early so this stops it if letter is input
        if (!cin)
        {
            cout <<"Letters Are Not Allowed, Terminating Program";
            choice = 0;
            continue;
        }

        //--------------------TASK SELECTION-------------------------
        //does specific task based on choice input
        switch (choice)
        {
            case 1:
                task1(); break;
            case 2:
                task2(); break;
            case 3:
                task3(); break;
            case 4:
                task4(); break;
            case 5:
                task5(); break;
            case 6:
                task6(); break;
            case 0: cout << "Terminating Program \n"; break;

            //any other inputs go to this message
            default: cout << "Please Choose a Valid Option\n";
        }
    }

    //--------------------LOOP EXIT-------------------------
    //stops if choice is 0
    while (choice != 0);

    return 0;
}
