#include "moveable.hpp"
#include "map.hpp"
#include "utils.hpp"

#include <climits> // for INT_MAX

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

bool Moveable::nextTo(MapTiles tile)
{
  Point tempNeighbours(x, y-1);
  if (MAP_GetData(&tempNeighbours) == tile) return true;
  tempNeighbours.y += 2;
  if (MAP_GetData(&tempNeighbours) == tile) return true;
  tempNeighbours.y -= 1;
  tempNeighbours.x -= 1;
  if (MAP_GetData(&tempNeighbours) == tile) return true;
  tempNeighbours.x += 2;  
  if (MAP_GetData(&tempNeighbours) == tile) return true;
  return false;
}

Point Moveable::getNearestTile(MapTiles tile)
{
  // TODO: Improve the implementation
  // searches through every map square then finds the closest point to the character
  int minDist = INT_MAX;
  Point closest(-1, -1);
  Point tempPoint(0, 0);
  for (int y = 1; y < MAP_HEIGHT - 1; y++)
  {
    for (int x = 1; x < MAP_WIDTH - 1; x++)
    {
      tempPoint.x = x;
      tempPoint.y = y;
      if (MAP_GetData(&tempPoint) == tile)
      {
        int tempDist;
        tempPoint.y -= 1;
        if (MAP_GetData(&tempPoint) == FLOOR)
        {
          tempDist = UTIL_ManhattenDist(&tempPoint, this);
          if (tempDist < minDist)
          {
            minDist = tempDist;
            closest.x = tempPoint.x;
            closest.y = tempPoint.y;
          }
        }
        tempPoint.y += 2;
        if (MAP_GetData(&tempPoint) == FLOOR)
        {
          tempDist = UTIL_ManhattenDist(&tempPoint, this);
          if (tempDist < minDist)
          {
            minDist = tempDist;
            closest.x = tempPoint.x;
            closest.y = tempPoint.y;
          }
        }
        tempPoint.y -= 1;
        tempPoint.x -= 1;
        if (MAP_GetData(&tempPoint) == FLOOR)
        {
          tempDist = UTIL_ManhattenDist(&tempPoint, this);
          if (tempDist < minDist)
          {
            minDist = tempDist;
            closest.x = tempPoint.x;
            closest.y = tempPoint.y;
          }
        }
        tempPoint.x += 2;  
        if (MAP_GetData(&tempPoint) == FLOOR)
        {
          tempDist = UTIL_ManhattenDist(&tempPoint, this);
          if (tempDist < minDist)
          {
            minDist = tempDist;
            closest.x = tempPoint.x;
            closest.y = tempPoint.y;
          }
        }
      }
    }
  }

  return closest;

  // // TODO: proper implementation
  // // currently just gets the first in the array
  // Point tempPoint(0, 0);
  // for (int y = 1; y < MAP_HEIGHT - 1; y++)
  // {
  //   for (int x = 1; x < MAP_WIDTH - 1; x++)
  //   {
  //     tempPoint.x = x;
  //     tempPoint.y = y;
  //     if (MAP_GetData(&tempPoint) == tile)
  //     {
  //       tempPoint.y -= 1;
  //       if (MAP_GetData(&tempPoint) == FLOOR) return tempPoint;
  //       tempPoint.y += 2;
  //       if (MAP_GetData(&tempPoint) == FLOOR) return tempPoint;
  //       tempPoint.y -= 1;
  //       tempPoint.x -= 1;
  //       if (MAP_GetData(&tempPoint) == FLOOR) return tempPoint;
  //       tempPoint.x += 2;  
  //       if (MAP_GetData(&tempPoint) == FLOOR) return tempPoint;
  //     }
  //   }
  // }

  // return Point(-1, -1);
}
