# game-of-life-in-c

**Author:** Omri Levin
**Language:** C
**Platform:** Console (Linux / macOS / WSL)

---

## Overview

This program implements **Conway’s Game of Life**, a famous cellular automaton that simulates the evolution of a population based on simple rules.
The grid wraps around at the edges (toroidal topology) and updates every generation based on the number of live neighbors.

Each cell is either **alive (1)** or **dead (0)**.
For every generation:
  * A live cell with fewer than 2 or more than 3 neighbors dies.
  * A live cell with 2 or 3 neighbors survives.
  * A dead cell with exactly 3 neighbors becomes alive.
The world wraps around horizontally and vertically, and delay between generations is controlled by the user.

---

## How to Run

Compile:
```bash
gcc exercise_gameoflife.c -o gameoflife
```

Run:
```bash
./gameoflife
```

Input format:
1. Number of iterations
2. Delay (multiplier for 0.5 seconds)
3. Initial board state (20 rows × 30 columns of 0/1)

Sample input:
```
5
1
000000000000000000000000000000
000000000000000000000000000000
000000000000011000000000000000
000000000000011000000000000000
...
```

---

## Key Functions

* `print_screen()`: Prints the current board state to the console.
* `count_neighbours()`: Counts the number of live neighbors around each cell (with wrap-around).
* `main()`: Handles initial input, simulation loop, and buffer swapping.

---

## Possible Extensions

* Add color output (using ANSI escape codes)
* Save each generation to a file for visualization
* Support variable grid sizes via command-line arguments
* Add predefined patterns (Glider, Spaceship, etc.)

---

## References

* Conway, J.H. *Game of Life* (1970).
* Wikipedia: [Conway’s Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

---

רוצה שאכין לך גרסה נוספת תואמת־יפנית שתוכל לשים מתחת ל־English version (כמו שאתה עושה בשאר הרפוזיטוריז שלך)?
