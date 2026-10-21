# Classic Circuit Calculator

A C++ calculator that solves **voltage (V), current (I), resistance (R) and power (P)** for simple DC resistor circuits. The user enters a voltage source and resistors, picks **series** or **parallel**, and the program solves for every component.

EECE2140 team project. Instructor: Dr. Nafa Fatema.

## Team
| Member | Role (Iteration 2) | Tasks |
|---|---|---|
| Brodie Newhouse | Project Leader | T2, T6 |
| Georgy Rached | Developer | T1, T5 |
| Julia Terceros | Developer | T3, T4, T6 |

## Features
- Add a DC voltage source and one or more resistors
- Combine resistors in series or parallel
- Solve V, I, R and P for each resistor using Ohm's law (V = IR) and P = VI
- Text menu in the terminal (front end for a touch display planned)

**Out of scope:** AC circuits, capacitors and inductors, diodes and transistors, custom circuit graphs, exporting to PDF.

## Menu
```
===== Simple Circuit Solver =====
1. Help
2. Add Components
3. Series / Parallel
4. Solve V, I, R, P
5. Front-End Display
6. Run Tests
0. Exit
```

## File Structure
```
.
├── main.cpp            # Menu loop and switch statement
├── tasks.h / tasks.cpp # One function per menu option (task1() ... task6())
├── components.h / .cpp # Resistor and VoltageSource classes
├── circuit.h / .cpp    # Circuit class: series/parallel + V, I, R, P solver
├── README.md
└── docs/               # Iteration reports (PDF) and Excel project plan
```

## Build and Run
You need a C++ compiler such as g++. From the repo folder:

```bash
g++ -std=c++17 -o circuit main.cpp tasks.cpp components.cpp circuit.cpp
./circuit
```
On Windows, run `circuit.exe` instead of `./circuit`.

## Example
A 12 V source with two 6 Ω resistors in series gives:
- Equivalent resistance: 12 Ω
- Current: 1 A
- Each resistor: 6 V, 1 A, 6 W

## Project Status
| Iteration | Goal | Status |
|---|---|---|
| 1 | Project plan and repo setup | Done |
| 2 | Classes, menu, working code | In progress |
| 3 | Run on STM32 board with touch display | Planned |
| Final | Testing, bug fixes, demo (Dec 11) | Planned |

## Tools
C++ · Git/GitHub · Visual Studio Code · Claude (front end and docs, see AI disclosure in reports)
