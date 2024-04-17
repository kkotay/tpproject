#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H
#include "Vector.h"
#include "Point.h"
#include "IShape.h"
namespace geometry {
  class Line : public IShape {
  private:
    float a_ = 0;
    float b_ = 0;
    float c_ = 0;
    Point point1_;
    Point point2_;

  public:
    explicit Line();
    explicit Line(const Point&, const Point&) ;
    float getA() const;
    float getB() const;
    float getC() const;
    Point getPoint1() const;
    Point getPoint2() const;
    float DistPoint(const Point& point) const;
    Line& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
  };
}
#endif
