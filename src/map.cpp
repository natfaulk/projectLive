#include "map.hpp"
#include "utils.hpp"

#include <iostream>
#include <cstdlib> // for rand

static MapTiles map[MAP_WIDTH][MAP_HEIGHT] = {{FLOOR}};

void addOuterWalls(void);

// char** MAP_Get(void)
// {
//   return &(map[0]);
// }

MapTiles MAP_GetData(Point* _p)
{
  return map[int(_p->x)][int(_p->y)];
}

// can walk through it
bool MAP_IsPassable(Point* _p)
{
  MapTiles temp = map[int(_p->x)][int(_p->y)];
  return (temp != WALL) 
  && (temp != WATER)
  && (temp != FOOD)
  && (temp != BED)
  ;
}

void MAP_SetData(Point* _p, MapTiles _d)
{
  map[int(_p->x)][int(_p->y)] = _d;
}

bool MAP_CheckValidLocation(Point *p)
{
  if (p->x < 0) return false;
  if (p->y < 0) return false;
  if (p->x >= MAP_WIDTH) return false;
  if (p->y >= MAP_HEIGHT) return false;
  return true;
}

void MAP_Gen(void)
{
  addOuterWalls();  

  map[9][9] = WALL;
  map[9][10] = WALL;
  map[10][9] = WALL;
  map[11][9] = WALL;
  // map[9][4] = WALL;
  // map[9][5] = WALL;
  // map[10][5] = WALL;
  // map[9][8] = WALL;
}

void MAP_GenRandom(void)
{
  addOuterWalls();

  int numWalls = UTIL_RandBetween(MG_NUM_WALLS_MIN, MG_NUM_WALLS_MAX);
  int xpos, ypos;

  for (int i = 0; i < numWalls; i++)
  {
    xpos = UTIL_RandBetween(1, MAP_WIDTH - 1);
    ypos = UTIL_RandBetween(1, MAP_HEIGHT - 1);
    map[xpos][ypos] = WALL;
  }

  // add some water
  for (int i = 1; i < MAP_HEIGHT - 1; i++)
  {
    map[MAP_WIDTH / 2][i] = WATER;
    map[(MAP_WIDTH / 2) - 1][i] = WATER;
  }

  // add some food
  for (int i = 0; i < 10; i ++)
  {
    xpos = UTIL_RandBetween(1, MAP_WIDTH - 1);
    ypos = UTIL_RandBetween(1, MAP_HEIGHT - 1);
    map[xpos][ypos] = FOOD;
  }

  // add a bridge
  map[MAP_WIDTH / 2][MAP_HEIGHT / 2] = FLOOR;
  map[(MAP_WIDTH / 2) - 1][MAP_HEIGHT / 2] = FLOOR;

  // add a bed
  xpos = UTIL_RandBetween(1, MAP_WIDTH - 1);
  ypos = UTIL_RandBetween(1, MAP_HEIGHT - 1);
  map[xpos][ypos] = BED;

}

void MAP_Clear(void)
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      map[x][y] = FLOOR;
    }
  }
}

void addOuterWalls(void)
{
  for (int i = 0; i < MAP_WIDTH; i++)
  {
    map[i][0] = WALL;
    map[i][MAP_HEIGHT - 1] = WALL;
  }

  for (int i = 0; i < MAP_HEIGHT; i++)
  {
    map[0][i] = WALL;
    map[MAP_WIDTH - 1][i] = WALL;
  }

  // // add walls behind the checkbox
  // for (int y = 0; y < 7; y++)
  // {
  //   for (int x = 0; x < 55; x++)
  //   {
  //     map[x][y] = WALL;
  //   }
  // }
}

void MAP_Draw(sf::RenderWindow &window)
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      sf::RectangleShape rectangle(sf::Vector2f(TILE_SIZE, TILE_SIZE));
      rectangle.setFillColor(* MapTileColors[map[x][y]]);
      rectangle.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
      window.draw(rectangle);
    }
  }
}

// void MAP_Print(void)
// {
//   std::cout << "\r\n";
//   for (int y = 0; y < MAP_HEIGHT; y++)
//   {
//     for (int x = 0; x < MAP_WIDTH; x++)
//     {
//       switch (map[x][y])
//       {
//         case FLOOR:
//         {
//           std::cout << CHAR_FLOOR;
//           break;
//         }
//         case WALL:
//         {
//           std::cout << CHAR_WALL;
//           break;
//         }
//         case SRC:
//         {
//           std::cout << CHAR_SRC;
//           break;
//         }
//         case DEST:
//         {
//           std::cout << CHAR_DEST;
//           break;
//         }
//         case CUR_POS:
//         {
//           std::cout << CHAR_CURRENT_POS;
//           break;
//         }
//         case SEARCHED:
//         {
//           std::cout << CHAR_SEARCHED;
//           break;
//         }
//         case BEST:
//         {
//           std::cout << CHAR_BESTPATH;
//           break;
//         }
//       }
//     }
//     std::cout << "\r\n";  
//   }
// }