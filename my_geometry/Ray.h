#ifndef GEOMETRY_RAY_H
#define GEOMETRY_RAY_H
#include "Vector.h"
#include "IShape.h"
#include "Line.h"

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
    explicit Ray(const Point&, const Point&);
    Point getBegin() const;
    Point getPoint() const;
    float DistPoint(const Point&) const;
    Ray& Move(const Vector &) override;
    bool ContainsPoint(const Point &) const override;
    bool CrossesSegment(const Segment &) const override;
  };
}
#endif
