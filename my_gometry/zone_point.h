#ifndef DACHA_ZONE_POINT_H
#define DACHA_ZONE_POINT_H
#include "point.h"
namespace geometry {

  class Zone_point {
   private:
    Point a_;
    size_t zone_ = 0;

   public:
    explicit Zone_point();
    explicit Zone_point(const Point& a);
    Point& Getpon();
    void Setzone(size_t a);
    size_t Getzone();
    ~Zone_point();
  };
} // geometry

#endif //DACHA_ZONE_POINT_H
