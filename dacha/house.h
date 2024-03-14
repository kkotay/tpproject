
#ifndef MYDESMOS_HOUSE_H
#define MYDESMOS_HOUSE_H
#include "object.h"
#include "../gometry/point.h"
#include "../gometry/polygon.h"
class House : public Object {
 protected:
  geometry::Vector size_;
  geometry::Point position_;

 public:
  House();
  House(geometry::Vector, geometry::Point);
  void setSize(geometry::Vector);
  void setPosition(geometry::Point);
  void update() override;
  ~House();
};


#endif //MYDESMOS_HOUSE_H
