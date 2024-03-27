#include <iostream>
#include <algorithm>
#ifndef GOMETRY_ISHAPE_H
#define GOMETRY_ISHAPE_H

namespace geometry {
  class Point;
  class Segment;
  class Line;
  class Ray;
  class Polygon;
  class Vector;
  class IShape {
   public:
    virtual IShape& Move(const Vector&) = 0;
    virtual bool ContainsPoint(const Point&) const = 0;
    virtual bool CrossesSegment(const Segment&) const = 0;
    virtual ~IShape() = default;
  };
}
#endif
