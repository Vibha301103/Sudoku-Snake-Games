# Snake & Sudoku Projects

This repository contains two terminal-based C++ projects demonstrating core programming concepts such as data structures, recursion, game logic, and algorithm implementation.

---

##  Folder Structure

Sudoku-Snake-Games/
├── Snake/
│ └── game.cpp
├── Sudoku/
│ └── main.cpp
└── README.md

markdown
Copy
Edit

---

## 1.  Snake Game

A simple terminal-based Snake Game implemented in C++.

###  Features:
- Snake movement using `W`, `A`, `S`, `D` keys
- Random food generation
- Snake grows after eating food
- Score tracking
- Game over on wall or self collision

###  File:
- `Snake/game.cpp`

###  How to Compile & Run:
```bash
g++ Snake/game.cpp -o snake
./snake

## 2.  Sudoku Solver

A backtracking-based Sudoku solver that solves a 9x9 puzzle using recursion.

Features:
Backtracking algorithm

Checks rows, columns, and 3×3 subgrids for constraints

Efficient and recursive implementation

 File:
Sudoku/main.cpp

▶How to Compile & Run:
bash
Copy
Edit
g++ Sudoku/main.cpp -o sudoku
./sudoku
🛠 Requirements
A C++ compiler (e.g., g++)

Terminal or Command Prompt

