#include "IShape.h"
#include "Point.h"

#ifndef GEOMETRY_SEGMENT_H
#define GEOMETRY_SEGMENT_H

namespace geometry {
  class Segment : public IShape {
   private:
    Point a1_;
    Point a2_;
    float x_ = 0;
    float y_ = 0;

   public:
    Segment();
    Segment(const Point& point1, const Point& point2);
    Point getA1() const;
    Point getA2() const;
    Segment& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    float DistPoint(const Point&) const;
    bool CrossesSegment(const Segment&) const override;
    ~Segment() override;
  };
}
#endif
