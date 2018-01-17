#include "camera.hpp"
#include "constants.hpp"

Camera::Camera()
{
  _w = CAMERA_WIDTH;
  _h = CAMERA_HEIGHT;
  attachedObj = nullptr;
}

// gets top left corner
// checks attached object still on screen
// warning need to disconnect camera from object before destroying object
Point Camera::getPos(void)
{
  if (attachedObj != nullptr)
  {
    if (attachedObj->x < (x + CAMERA_HYSTERESIS))
    {
      x = attachedObj->x - CAMERA_HYSTERESIS;
      if (x < 0) x = 0;
    }

    if (attachedObj->x > ((x + CAMERA_WIDTH) - CAMERA_HYSTERESIS))
    {
      x = (attachedObj->x - (CAMERA_WIDTH - CAMERA_HYSTERESIS));
      if (x > (MAP_WIDTH - CAMERA_WIDTH)) x = (MAP_WIDTH - CAMERA_WIDTH);
    }

    if (attachedObj->y < (y + CAMERA_HYSTERESIS))
    {
      y = attachedObj->y - CAMERA_HYSTERESIS;
      if (y < 0) y = 0;
    }

    if (attachedObj->y > ((y + CAMERA_HEIGHT) - CAMERA_HYSTERESIS))
    {
      y = (attachedObj->y - (CAMERA_HEIGHT - CAMERA_HYSTERESIS));
      if (y > (MAP_HEIGHT - CAMERA_HEIGHT)) y = (MAP_HEIGHT - CAMERA_HEIGHT);      
    }

  }

  return Point(x, y);
}

void Camera::attachToObject(Point *obj)
{
  attachedObj = obj;
}