#include "utils.hpp"

#include <cstdlib> // for rand
#include <ctime> // for seeding rng
#include <cmath> // for abs

void UTIL_RandSeed(void)
{
  srand(time(NULL));
}

int UTIL_RandBetween(int _lower, int _upper)
{
  return (std::rand() % (_upper - _lower)) + _lower;
}

int UTIL_ManhattenDist(Point* src, Point* dest)
{
  return std::abs(src->x - dest->x) + std::abs(src->y - dest->y);
}