#include "utils.hpp"

#include <cstdlib> // for rand
#include <ctime> // for seeding rng

void UTIL_RandSeed(void)
{
  srand(time(NULL));
}

int UTIL_RandBetween(int _lower, int _upper)
{
  return (std::rand() % (_upper - _lower)) + _lower;
}