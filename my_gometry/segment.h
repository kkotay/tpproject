#include "iShape.h"
#include "point.h"

#ifndef GOMETRY_SEGMENT_H
#define GOMETRY_SEGMENT_H

namespace geometry {
  class Segment : public IShape {
   private:
    Point a1_;
    Point a2_;
    int64_t x_ = 0;
    int64_t y_ = 0;

   public:
    Segment();
    Segment(const Point& a1, const Point& a2);
    Point Geta1() const;
    Point Geta2() const;
    Segment& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    int64_t DistPoint(const Point&) const;
    bool CrossesSegment(const Segment&) const override;
    ~Segment() override;
  };
}
#endif
