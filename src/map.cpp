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
    xpos = UTIL_RandBetween(1, MAP_WIDTH - 2);
    ypos = UTIL_RandBetween(1, MAP_HEIGHT - 2);
    map[xpos][ypos] = WALL;
  }
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
}

void MAP_Draw(sf::RenderWindow &window)
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      sf::RectangleShape rectangle(sf::Vector2f(TILE_SIZE, TILE_SIZE));
      
      if (map[x][y] == FLOOR)rectangle.setFillColor(FLOOR_COLOR);
      else if (map[x][y] == WALL)rectangle.setFillColor(WALL_COLOR);
      else if (map[x][y] == SRC)rectangle.setFillColor(SRC_COLOR);
      else if (map[x][y] == DEST)rectangle.setFillColor(DEST_COLOR);
      else if (map[x][y] == CUR_POS)rectangle.setFillColor(CURRENT_POS_COLOR);
      else if (map[x][y] == SEARCHED)rectangle.setFillColor(SEARCHED_COLOR);
      else if (map[x][y] == BEST)rectangle.setFillColor(BESTPATH_COLOR);
      
      rectangle.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
      window.draw(rectangle);
    }
  }
}

void MAP_Print(void)
{
  std::cout << "\r\n";
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      switch (map[x][y])
      {
        case FLOOR:
        {
          std::cout << CHAR_FLOOR;
          break;
        }
        case WALL:
        {
          std::cout << CHAR_WALL;
          break;
        }
        case SRC:
        {
          std::cout << CHAR_SRC;
          break;
        }
        case DEST:
        {
          std::cout << CHAR_DEST;
          break;
        }
        case CUR_POS:
        {
          std::cout << CHAR_CURRENT_POS;
          break;
        }
        case SEARCHED:
        {
          std::cout << CHAR_SEARCHED;
          break;
        }
        case BEST:
        {
          std::cout << CHAR_BESTPATH;
          break;
        }
      }
    }
    std::cout << "\r\n";  
  }
}