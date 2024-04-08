#ifndef GOMETRY_RAY_H
#define GOMETRY_RAY_H
#include "vector.h"
#include "iShape.h"
#include "line.h"

namespace geometry {
  class Ray : public IShape {
   private:
    Point a1_;
    Point a2_;
    float a_ = 0;
    float b_ = 0;
    float c_ = 0;

   public:
    explicit Ray();
    explicit Ray(const Point& beg, const Point& pon);
    Point Getbeg() const;
    Point Getpon() const;
    float DistPoint(const Point&) const;
    Ray& Move(const Vector &) override;
    bool ContainsPoint(const Point &) const override;
    bool CrossesSegment(const Segment &) const override;
  };
}
#endif //GOMETRY_RAY_H
