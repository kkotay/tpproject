#include "../iShape.h"
#include "../vector.h"
#include "../point.h"
#include "../segment.h"

namespace geometry {
  Point::Point() = default;
  Point::Point(const int64_t& x, const int64_t& y) {
    x_ = x;
    y_ = y;
  };

  int64_t Point::Getx() const {
    return x_;
  }

  int64_t Point::Gety() const {
    return y_;
  }

  Point& Point::Move(const Vector& a) {
    x_ += a.Getx();
    y_ += a.Gety();
    return *this;
  }

  Point& Point::operator+=(const Vector& vec) {
    x_ += vec.Getx();
    y_ += vec.Gety();
    return *this;
  }

  bool Point::ContainsPoint(const Point& a) const {
    return x_ == a.Getx() && y_ == a.Gety();
  }

  bool Point::CrossesSegment(const Segment& seg) const {
    return (seg.ContainsPoint(*this));
  }

  Point* Point::Clone() const {
    auto a = new Point(x_, y_);
    return a;
  }

  std::string Point::ToString() const {
    std::string pon = "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return pon;
  }

  Vector Point::operator-(const Point& a) const {
    return Vector(x_ - a.x_, y_ - a.y_);
  }
}