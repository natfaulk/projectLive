#ifndef MAP_HPP
#define MAP_HPP

#include "point.hpp"
#include "constants.hpp"

#include <SFML/Graphics.hpp>

// char** MAP_Get(void);
MapTiles MAP_GetData(Point* _p);
bool MAP_IsPassable(Point* _p);
void MAP_SetData(Point* _p, MapTiles _d);
bool MAP_CheckValidLocation(Point *p);
void MAP_Gen(void);
void MAP_GenRandom(void);
// void MAP_Print(void);
void MAP_Draw(sf::RenderWindow &window);
void MAP_Clear(void);

#endif /* end of include guard: MAP_HPP */