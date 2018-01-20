#ifndef UTILS_HPP
#define UTILS_HPP

#include "point.hpp"

void UTIL_RandSeed(void);
int UTIL_RandBetween(int _lower, int _upper);
int UTIL_ManhattenDist(Point* src, Point* dest);
bool UTIL_DirectoryExists(const char* _path);
void UTIL_Mkdir(const char * _path);

typedef enum dirs {UP, DOWN, LEFT, RIGHT} Dirs;

#endif /* end of include guard: UTILS_HPP */