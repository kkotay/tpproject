#include "../IShape.h"
#include "../Vector.h"
#include "../Point.h"
#include "../Segment.h"

namespace geometry {
  Point::Point() = default;
  Point::Point(const float& x, const float& y) {
    x_ = x;
    y_ = y;
  }

  float Point::getX() const {
    return x_;
  }

  float Point::getY() const {
    return y_;
  }

  Point& Point::Move(const Vector& vector) {
    x_ += vector.getX();
    y_ += vector.getY();
    return *this;
  }

  Point& Point::operator+=(const Vector& vector) {
    x_ += vector.getX();
    y_ += vector.getY();
    return *this;
  }

  bool Point::ContainsPoint(const Point& point) const {
    return x_ == point.getX() && y_ == point.getY();
  }

  bool Point::CrossesSegment(const Segment& segment) const {
    return (segment.ContainsPoint(*this));
  }

  bool Point::operator==(const Point& point) const {
    return ContainsPoint(point);
  }

  bool Point::operator!=(const Point& point) const {
    return !ContainsPoint(point);
  }

  Vector Point::operator-(const Point& point) const {
    return Vector(x_ - point.x_, y_ - point.y_);
  }
}