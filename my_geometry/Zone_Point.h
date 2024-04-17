#ifndef GEOMETRY_ZONE_POINT_H
#define GEOMETRY_ZONE_POINT_H
#include "Point.h"
namespace geometry {

  class Zone_Point {
   private:
    Point point_;
    size_t zone_ = 0;

   public:
    explicit Zone_Point();
    explicit Zone_Point(const Point&);
    Point& getPoint();
    void setZone(size_t);
    size_t getZone() const;
    ~Zone_Point();
  };
}

#endif
