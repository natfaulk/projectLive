#include "moveable.hpp"
#include "constants.hpp"
#include "map.hpp"

Moveable::Moveable(): Point(0, 0)
{

}

Moveable::Moveable(int _x, int _y)
{
  setPos(_x, _y);
}

void Moveable::setPos(int _x, int _y)
{
  // x = _x * TILE_SIZE;
  // y = _y * TILE_SIZE;
  x = _x;
  y = _y;
  draw();
}

Point Moveable::getPos(void)
{
  return Point(x / TILE_SIZE, y / TILE_SIZE);
}

void Moveable::draw(void)
{
  MAP_SetData(this, MOVEABLE);
}

void Moveable::move(Dirs _dir)
{
  double prevX = x;
  double prevY = y;

  MAP_SetData(this, FLOOR);
  if (UP == _dir) y--;
  else if (DOWN == _dir) y++;
  else if (LEFT == _dir) x--;
  else if (RIGHT == _dir) x++;
  
  if (MAP_GetData(this) != FLOOR)
  {
    x = prevX;
    y = prevY;
  }

  this->draw();
}