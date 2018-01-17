#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "point.hpp"

class Camera: public Point {
public:
  Camera();
  Point getPos(void);
  void attachToObject(Point *obj);
  int _w;
  int _h;
private:
  Point *attachedObj;
};

#endif /* end of include guard: CAMERA_HPP */