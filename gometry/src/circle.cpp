#include "../circle.h"
#include "../line.h"

namespace geometry {
  Circle::Circle() = default;

  Circle::Circle(const Point& pon, const int64_t& rad) {
    center_ = pon;
    rad_ = rad;
  }

  Circle& Circle::Move(const Vector& a) {
    center_ += a;
    return *this;
  }

  bool Circle::ContainsPoint(const Point& pon) const {
    return (pon.Getx() - center_.Getx()) * (pon.Getx() - center_.Getx()) +
    (pon.Gety() - center_.Gety()) * (pon.Gety() - center_.Gety()) <= rad_ * rad_;
  }

  bool Circle::CrossesSegment(const Segment& seg) const {
    if (rad_ == 0) {
      return seg.ContainsPoint(center_);
    }
    if ((seg.Geta1().Getx() - center_.Getx()) * (seg.Geta1().Getx() - center_.Getx()) +
        (seg.Geta1().Gety() - center_.Gety()) * (seg.Geta1().Gety() - center_.Gety()) == rad_ * rad_) {
      return true;
    }
    if ((seg.Geta2().Getx() - center_.Getx()) * (seg.Geta2().Getx() - center_.Getx()) +
        (seg.Geta2().Gety() - center_.Gety()) * (seg.Geta2().Gety() - center_.Gety()) == rad_ * rad_) {
      return true;
    }
    if (ContainsPoint(seg.Geta1()) && ContainsPoint(seg.Geta2())) {
      return false;
    }
    Line lin(seg.Geta1(), seg.Geta2());
    int64_t dist = lin.DistPoint(center_);
    dist = dist * dist;
    int64_t radist = rad_ * rad_ * (lin.Geta() * lin.Geta() + lin.Getb() * lin.Getb());

    return dist <= radist;
  }

  Circle* Circle::Clone() const {
    return new Circle(center_, rad_);
  }

  std::string Circle::ToString() const {
    std::string circ = "Circle(" + center_.ToString() + ", " + std::to_string(rad_) + ")";
    return circ;
  }

  Circle::~Circle() = default;
}
