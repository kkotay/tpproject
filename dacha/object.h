#ifndef MYDESMOS_OBJECT_H
#define MYDESMOS_OBJECT_H
#include "../gometry/iShape.h"
class Object {
 protected:
  geometry::IShape* figure{};
  virtual void update() = 0;
};
#endif //MYDESMOS_OBJECT_H
