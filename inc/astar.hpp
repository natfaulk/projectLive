#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "point.hpp"

#include <vector>

class Point_score: public Point {
public:
  Point_score();
  Point_score(Point *_p);
  bool operator==(const Point_score& other);
  int score;
  int parent;
};

class Astar {
public:
  Astar();
  void begin(Point* src, Point* dest);
  bool step(void);
  Point* latestSearched(void);
  Point pathNextPoint(void);
private:
  std::vector<Point_score> allPoints;
  std::vector<int> open;
  std::vector<int> closed;
  std::vector<int> latestPath;

  Point* _src;
  Point* _dest;
  Point _latestSearched;

  int isInClosedList(Point_score *_p);
  int isInOpenList(Point_score *_p);
  int calculateScore(Point_score *_p, Point *src, Point *dest);
};

// void astar(Point* src, Point* dest);
// void ASTAR_PrintOpen(void);
// void ASTAR_PrintClosed(void);

// void ASTAR_Begin(Point* src, Point* dest);
// bool ASTAR_Step();
// Point* ASTAR_LatestSearched(void);
// Point ASTAR_PathNextPoint(void);

// void ASTAR_Test(void);

#endif /* end of include guard: ASTAR_HPP */