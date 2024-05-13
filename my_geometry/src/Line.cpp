#include "../Line.h"
#include "../Segment.h"

namespace geometry {
  Line::Line() = default;

  Line::Line(const Point& a1, const Point& b1) {
    a_ = -(b1.getY() - a1.getY());
    b_ = (b1.getX() - a1.getX());
    c_ = -(a_ * a1.getX() + b_ * a1.getY());
    point1_ = a1;
    point2_ = b1;
  };

  float Line::getA() const {
    return a_;
  }

  float Line::getB() const {
    return b_;
  }

  float Line::getC() const {
    return c_;
  }

  float Line::DistPoint(const Point& point) const {
    return (a_ * point.getX() + b_ * point.getY() + c_);
  }

  Line& Line::Move(const Vector& vector) {
    point1_.Move(vector);
    point2_.Move(vector);
    *this = Line(point1_, point2_);
    return *this;
  }

  bool Line::ContainsPoint(const Point& point) const {
    return (a_ * point.getX() + b_ * point.getY() + c_ == 0);
  }

  bool Line::CrossesSegment(const Segment& segment) const {
    float k1 = a_ * segment.getA1().getX() + b_ * segment.getA1().getY() + c_;
    float k2 = a_ * segment.getA2().getX() + b_ * segment.getA2().getY() + c_;
    return (k1 * k2 <= 0);
  }

  Point Line::getPoint2() const {
    return point2_;
  }

  Point Line::getPoint1() const {
    return point1_;
  }
}