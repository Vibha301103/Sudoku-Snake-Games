# Snake & Sudoku Projects 

This repository contains two C++ projects demonstrating fundamental data structures, algorithms, and game logic using terminal-based applications.

---

1. Snake Game

A classic terminal-based Snake Game written in C++.  
It includes features like:
- Food generation
- Snake movement and growth
- Score tracking
- Collision detection (wall and self)

### File
- `SnakeGame/snake.cpp`

### Demo
The snake moves using `W`, `A`, `S`, `D` keys and grows each time it eats the food. The game ends when the snake collides with itself or the wall.

---

##  2. Sudoku Solver

A backtracking-based solution to solve a 9x9 Sudoku puzzle using recursion.

### File
- `SudokuSolver/sudoku.cpp`

### Features
- Uses backtracking and recursion
- Checks validity row-wise, column-wise, and 3x3 grid-wise
- Solves partially filled puzzles efficiently

---

## Requirements
- C++ compiler (like g++)
- Terminal or command prompt

## How to Run

### For Snake Game:
```bash
g++ SnakeGame/snake.cpp -o snake
./snake
