# Basic A* pathfinding
Basic A* pathfinding for grid based (no diagonal) movement. Generates a random map, random start and finish points. Displays path found (if there is one) as well as all grid points searched. There is now a GUI using SFML. One can generate a new map, start and end points by pressing `R` whilst the program is running. Toggling the check box in the top left corner controls whether the pathfinding runs in timelapse mode or not. In timelapse mode, the grid points slowly display as they are searched, otherwise they appear instantly with the path found.

## Colors
Walls: Red  
Floor: White  
Grid points searched: Grey  
Start point: Yellow  
Destination point: Blue  
Final path:  Black

These colors can be changed in `constants.hpp`

## To compile / run
The previous console only version had no external dependencies, however now SFML is required. Currently it has only been tested on OSX and needs a few small changes to the makefile for it to compile on Windows or Linux. I will do this at some point. On osx, assuming SFML is installed one should be able to call `make run` and it should compile and run.