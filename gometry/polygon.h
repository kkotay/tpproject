#include "segment.h"
#include "iShape.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "ray.h"
#ifndef GOMETRY_POLYGON_H
#define GOMETRY_POLYGON_H

namespace geometry {
  class Polygon : public IShape {
  private:
    Point* vertices_;
    size_t count_ = 0;

  public:
    explicit Polygon(const std::vector<Point>&);
    Polygon(const Point*, const size_t&);
    Polygon();
    Polygon& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Polygon* Clone() const override;
    std::string ToString() const override;
    ~Polygon() override;
  };
}
#endif
