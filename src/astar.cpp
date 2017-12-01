#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"

#include <vector>
#include <cmath> // for abs

#include <cstdio>

class Point_score: public Point {
public:
  Point_score();
  Point_score(Point *_p);
  bool operator==(const Point_score& other);
  int score;
  int parent;
};

int getManhattenDist(Point* src, Point* dest);
int isInClosedList(Point_score *_p);
int isInOpenList(Point_score *_p);
int calculateScore(Point_score *_p, Point *src, Point *dest);

// static std::vector<Point_score> open;
// static std::vector<Point_score> closed;

static std::vector<Point_score> allPoints;
static std::vector<int> open;
static std::vector<int> closed;

void ASTAR_Test(void)
{
  // Point_score test;
  // test.x = 10;
  // test.y = 10;
  // allPoints.push_back(test);
  // closed.push_back(&(allPoints.back()));
  // Point testPoint(10, 10);
  // Point_score test2(&testPoint);
  // printf("test is: %f, %f; test2 is %f, %f\r\n", closed.at(0)->x, closed.at(0)->y, test2.x, test2.y);
  // if (isInClosedList(&test2) >= 0) printf("TEST PASSED\r\n");
  // else printf("TEST FAILED\r\n");
}

void astar(Point* src, Point* dest)
{
  enum Dirs {UP, DOWN, LEFT, RIGHT};

  open.clear();
  closed.clear();
  allPoints.clear();

  Point_score current(src);
  allPoints.push_back(src);
  open.push_back(allPoints.size() - 1);

  MAP_SetData(src, SRC);
  MAP_SetData(dest, DEST);

  bool destfound = false;

  // int tc = 0;

  while (open.size() > 0)
  {
    // check that destination not in open list
    for (std::size_t i = 0 ; i < open.size(); i++)
    {
      if ((allPoints.at(open.at(i)).x == dest->x) && (allPoints.at(open.at(i)).y == dest->y))
      {
        destfound = true;
        break;
      }
    }
    if (destfound) break;

    // get the lowest scored open square
    std::size_t minOpenScore = 0;
    for (std::size_t j = 0; j < open.size(); j++)
    {
      if (allPoints.at(open.at(j)).score <= allPoints.at(open.at(minOpenScore)).score)
      {
        minOpenScore = j;
      }
    }

    // printf("j %d\r\n", minOpenScore);

    // printf("print all open\r\n");
    // for (std::size_t j = 0; j < open.size(); j++)
    // {
    //   printf("AO: x %f, y %f", open.at(j)->x, open.at(j)->y);
    // }

    closed.push_back(open.at(minOpenScore));
    open.erase(open.begin() + minOpenScore);
    int current_p = closed.back();
    MAP_SetData(&allPoints.at(current_p), SEARCHED);
    // printf("\r\ncurrent p x %f, y %f\r\n", current_p->x, current_p->y);
    // MAP_Print();

    // get adj squares
    Point_score adj[4];
    adj[UP].x = allPoints.at(current_p).x;
    adj[UP].y = allPoints.at(current_p).y - 1;
    adj[DOWN].x = allPoints.at(current_p).x;
    adj[DOWN].y = allPoints.at(current_p).y + 1;
    adj[LEFT].x = allPoints.at(current_p).x - 1;
    adj[LEFT].y = allPoints.at(current_p).y;
    adj[RIGHT].x = allPoints.at(current_p).x + 1;
    adj[RIGHT].y = allPoints.at(current_p).y;

    // Point t(0,0);
    // if (MAP_GetData(&t) != WALL)
    // {
    //   printf("PROBLEM %f %f\r\n", allPoints.at(current_p).x, allPoints.at(current_p).y);
    // }
    // else printf("all g %f %f\r\n", allPoints.at(current_p).x, allPoints.at(current_p).y);

    // printf("open size %d closed size %d\r\n", open.size(), closed.size());

    for (int i = 0; i < 4; i++)
    {
      // check they not a wall or in the closed list
      if ((MAP_GetData(&adj[i]) != WALL) && (isInClosedList(&adj[i]) == -1))
      {
        if (!MAP_CheckValidLocation(&adj[i])) printf("INVALID LOCATION!! x %f, y %f \r\n", adj[i].x, adj[i].y);
        int openPos = isInOpenList(&adj[i]);
        int tempScore = calculateScore(&adj[i], src, dest);
        if (openPos == -1)
        {
          adj[i].parent = current_p;
          adj[i].score = tempScore;
          allPoints.push_back(adj[i]);
          open.push_back(allPoints.size() - 1);
        } else {
          if (tempScore < allPoints.at(openPos).score)
          {
           allPoints.at(openPos).parent = current_p;
           allPoints.at(openPos).score = tempScore;
          }
        }
      }
    }

    //  printf("print all open\r\n");
    // for (std::size_t j = 0; j < open.size(); j++)
    // {
    //   printf("AO: x %f, y %f", open.at(j)->x, open.at(j)->y);
    // }
    // printf("tc is %d, open list is %d\r\n", tc++, open.size());
  }

  if (destfound)
  {
    printf("found destination");
  }
  else
  {
    printf("couldnt find path");    
  }
}

void ASTAR_PrintOpen(void)
{
  for (std::size_t i = 0 ; i < open.size(); i++)
  {
    printf("Open list %d: x %f, y %f", i, allPoints.at(open.at(i)).x, allPoints.at(open.at(i)).y);
  }
}

void ASTAR_PrintClosed(void)
{
  for (std::size_t i = 0 ; i < closed.size(); i++)
  {
    printf("Closed list %d: x %f, y %f", i, allPoints.at(closed.at(i)).x, allPoints.at(closed.at(i)).y);
  }
}

int getManhattenDist(Point* src, Point* dest)
{
  return std::abs(src->x - dest->x) + std::abs(src->y - dest->y);
}

int isInClosedList(Point_score *_p)
{
  for (std::size_t i = 0 ; i < closed.size(); i++)
  {
    if (allPoints.at(closed.at(i)) == (* _p)) return closed.at(i);
  }
  return -1;
}

int isInOpenList(Point_score *_p)
{
  for (std::size_t i = 0 ; i < open.size(); i++)
  {
    if (allPoints.at(open.at(i)) == (* _p)) return open.at(i);
  }
  return -1;
}

int calculateScore(Point_score *_p, Point *src, Point *dest)
{
  int count = 0;
  int parent = _p->parent;
  while (parent != -1) {
    count++;
    parent = allPoints.at(parent).parent;
  }
  return count + getManhattenDist(_p, dest);
}

Point_score::Point_score(): Point(0, 0), score(0), parent(-1)
{

}

Point_score::Point_score(Point *_p): Point(_p->x, _p->y), score(0), parent(-1)
{
}

bool Point_score::operator==(const Point_score& other)
{
  return (x == other.x) && (y == other.y);
}
