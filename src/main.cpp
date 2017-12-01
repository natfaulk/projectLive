#include <iostream>
#include "point.hpp"
#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"

int main(int argc, char const *argv[]) {
  /* code */
  // std::cout << "Hello world!\r\n";

  // ASTAR_Test();

  Point src(3, 3);
  Point dest(10, 10);

  MAP_Gen();

  astar(&src, &dest);
  // ASTAR_PrintOpen();
  MAP_Print();

  return 0;
}