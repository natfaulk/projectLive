#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "point.hpp"

void astar(Point* src, Point* dest);
void ASTAR_PrintOpen(void);
void ASTAR_PrintClosed(void);

void ASTAR_Begin(Point* src, Point* dest);
bool ASTAR_Step();
Point* ASTAR_LatestSearched(void);
Point ASTAR_PathNextPoint(void);

void ASTAR_Test(void);

#endif /* end of include guard: ASTAR_HPP */