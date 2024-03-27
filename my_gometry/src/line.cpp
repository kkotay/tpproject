#include "../line.h"
#include "../segment.h"

namespace geometry {
  Line::Line() = default;

  Line::Line(const Point& a1, const Point& b1) {
    a_ = -(b1.Gety() - a1.Gety());
    b_ = (b1.Getx() - a1.Getx());
    c_ = -(a_ * a1.Getx() + b_ * a1.Gety());
    pon1_ = a1;
    pon2_ = b1;
  };

  int64_t Line::Geta() const {
    return a_;
  }

  int64_t Line::Getb() const {
    return b_;
  }

  int64_t Line::Getc() const {
    return c_;
  }

  int64_t Line::DistPoint(const Point& pon) const {
    return (a_ * pon.Getx() + b_ * pon.Gety() + c_);
  }

  Line& Line::Move(const Vector& vec) {
    pon1_.Move(vec);
    pon2_.Move(vec);
    *this = Line(pon1_, pon2_);
    return *this;
  }

  bool Line::ContainsPoint(const Point& pon) const {
    return (a_ * pon.Getx() + b_ * pon.Gety() + c_ == 0);
  }

  bool Line::CrossesSegment(const Segment& seg) const {
    int64_t k1 = a_ * seg.Geta1().Getx() + b_ * seg.Geta1().Gety() + c_;
    int64_t k2 = a_ * seg.Geta2().Getx() + b_ * seg.Geta2().Gety() + c_;
    return (k1 * k2 <= 0);
  }

  Point Line::Getpon2() const {
    return pon2_;
  }

  Point Line::Getpon1() const {
    return pon1_;
  }
}