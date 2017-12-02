# Basic A* pathfinding
Basic A* pathfinding for grid based (no diagonal) movement. Generates a random map, random start and finish points. Displays path found (if there is one) as well as all grid points searched. The GUI is very primitive in the console. The walls are represented by `8`, the start and destination points as `S` and `D` respectively. Grid points that have been searched are shown as `*` and the final path as `.`. These can all be changed in constants.hpp and the program recompiled with `make clean` then `make run`.

## To compile / run
There are no external dependencies so one should be able to call `make run` and it should compile and run.