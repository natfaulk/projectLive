# Project Live

A grid based person simulator. The eventual goal is to simulate a whole town of people. Currently there is a single person that moves between food, water, and bed to keep themself alive. Originally this was a branch from the basic [A* algorithm I implemented](https://github.com/natfaulk/astar) but has been moved to its own repository.

## To compile / run
The only external dependency is SFML. The makefile is configured for OSX and Windows but should also compile for Linux with minimal changes. For windows the include path for SFML likely needs changhing depending on where it has been installed.