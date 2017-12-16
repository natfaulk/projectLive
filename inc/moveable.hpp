#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include "point.hpp"
#include "utils.hpp" // for Dirs

class Moveable: public Point {
public:
  Moveable();
  Moveable(int _x, int _y);
  void setPos(int _x, int _y);
  Point getPos(void);
  void draw(void);
  void move(Dirs _dir);
private:

};

#endif /* end of include guard: MOVEABLE_HPP */