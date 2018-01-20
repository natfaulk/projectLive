#include "utils.hpp"

#include <cstdlib> // for rand
#include <ctime> // for seeding rng
#include <cmath> // for abs

#include <sys/types.h>
#include <sys/stat.h>

#include <iostream>
// #include <cstdio>

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

bool UTIL_DirectoryExists(const char* _path)
{
  struct stat info;

  if( stat( _path, &info ) != 0 ) return false;
    // printf( "cannot access %s\n", _path );
  else if( info.st_mode & S_IFDIR ) return true;
    // printf( "%s is a directory\n", _path );
  else return false;
    // printf( "%s is not a directory\n", _path );
}

void UTIL_Mkdir(const char * _path)
{
  mode_t nMode = 0733; // UNIX style permissions
  int nError = 0;
#if defined(_WIN32)
  nError = _mkdir(_path); // can be used on Windows
#else 
  nError = mkdir(_path, nMode); // can be used on non-Windows
#endif
  if (nError != 0) {
    std::cout << "Failed to create directory" << std::endl;
  }
}