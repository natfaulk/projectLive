#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"
#include "utils.hpp" // for Dirs

// #include <cstdio>
#include <iostream>

// int isInClosedList(Point_score *_p);
// int isInOpenList(Point_score *_p);
// int calculateScore(Point_score *_p, Point *src, Point *dest);

// static std::vector<Point_score> open;
// static std::vector<Point_score> closed;

// static std::vector<Point_score> allPoints;
// static std::vector<int> open;
// static std::vector<int> closed;
// static std::vector<int> latestPath;

// Point* _src;
// Point* _dest;
// Point latestSearched = Point(-1, -1);

Astar::Astar()
{
  _latestSearched = Point(-1, -1);
}

void Astar::begin(Point* src, Point* dest)
{
  open.clear();
  closed.clear();
  allPoints.clear();
  latestPath.clear();
  _latestSearched = Point(-1, -1);

  _src = src;
  _dest = dest;

  Point_score current(_src);
  allPoints.push_back(current);
  open.push_back(allPoints.size() - 1);
}

bool Astar::step()
{
  if (open.size() > 0)
  {
    // check that destination not in open list
    for (std::size_t i = 0 ; i < open.size(); i++)
    {
      if ((allPoints.at(open.at(i)).x == _dest->x) && (allPoints.at(open.at(i)).y == _dest->y))
      {
        latestPath.push_back(open.at(i));
        int parent = allPoints.at(open.at(i)).parent;
        while (parent != -1) {
          latestPath.push_back(parent);
          // MAP_SetData(&allPoints.at(parent), BEST);
          parent = allPoints.at(parent).parent;
        }

        return true;
      }
    }
    // if (destfound) break;

    // get the lowest scored open square
    std::size_t minOpenScore = 0;
    for (std::size_t j = 0; j < open.size(); j++)
    {
      if (allPoints.at(open.at(j)).score <= allPoints.at(open.at(minOpenScore)).score)
      {
        minOpenScore = j;
      }
    }

    closed.push_back(open.at(minOpenScore));
    open.erase(open.begin() + minOpenScore);
    int current_p = closed.back();
    _latestSearched = allPoints.at(current_p);
    // MAP_SetData(&allPoints.at(current_p), SEARCHED);
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

    for (int i = 0; i < 4; i++)
    {
      // check they not a wall or in the closed list
      if (MAP_IsPassable(&adj[i]) && (isInClosedList(&adj[i]) == -1))
      {
        if (!MAP_CheckValidLocation(&adj[i])) printf("INVALID LOCATION!! x %f, y %f \r\n", adj[i].x, adj[i].y);
        int openPos = isInOpenList(&adj[i]);
        adj[i].parent = current_p;
        int tempScore = calculateScore(&adj[i], _src, _dest);
        if (openPos == -1)
        {
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

  }
  else return true;

  return false;
}

Point* Astar::latestSearched(void)
{
  return &_latestSearched;
}

Point Astar::pathNextPoint(void)
{
  if (!latestPath.empty())
  {
    int temp = latestPath.back();
    latestPath.pop_back();
    return Point(allPoints.at(temp).x, allPoints.at(temp).y);
  }
  else return Point(-1, -1);
}

int Astar::isInClosedList(Point_score *_p)
{
  for (std::size_t i = 0 ; i < closed.size(); i++)
  {
    if (allPoints.at(closed.at(i)) == (* _p)) return closed.at(i);
  }
  return -1;
}

int Astar::isInOpenList(Point_score *_p)
{
  for (std::size_t i = 0 ; i < open.size(); i++)
  {
    if (allPoints.at(open.at(i)) == (* _p)) return open.at(i);
  }
  return -1;
}

int Astar::calculateScore(Point_score *_p, Point *src, Point *dest)
{
  int count = 0;
  int parent = _p->parent;
  while (parent != -1) {
    count++;
    parent = allPoints.at(parent).parent;
  }
  // return count;
  return count + 1.5 * UTIL_ManhattenDist(_p, dest);
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
