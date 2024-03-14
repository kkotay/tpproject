#include "../segment.h"
#include "../line.h"
#include "../iShape.h"
#include "../point.h"
#include "../ray.h"

namespace geometry {
  Segment::Segment() = default;

  Segment::Segment(const Point& a1, const Point& a2) {
    a1_ = a1;
    a2_ = a2;
    x_ = a2.Getx() - a1.Getx();
    y_ = a2.Gety() - a1.Gety();
  };

  Point Segment::Geta1() const {
    return a1_;
  }

  Point Segment::Geta2() const {
    return a2_;
  }

  Segment& Segment::Move(const Vector& vec) {
    a1_ += vec;
    a2_ += vec;
    return *this;
  }

  bool Segment::ContainsPoint(const Point& pon) const {
    if (pon.ContainsPoint(a1_) || pon.ContainsPoint(a2_)) {
      return true;
    }
    if (x_ * (pon.Gety() - a1_.Gety()) - y_ * (pon.Getx() - a1_.Getx()) == 0) {
      if (x_ * (pon.Getx() - a1_.Getx()) + y_ * (pon.Gety() - a1_.Gety()) > 0) {
        if (x_ * (pon.Getx() - a2_.Getx()) + y_ * (pon.Gety() - a2_.Gety()) < 0) {
          return true;
        }
      }
    }
    return false;
  }

  int64_t Segment::DistPoint(const Point& pon) const {
    if ((x_ * (pon.Getx() - a1_.Getx()) + y_ * (pon.Gety() - a1_.Gety())) <= 0) {
      return (pon.Getx() - a1_.Getx()) * (pon.Getx() - a1_.Getx()) +
      (pon.Gety() - a1_.Gety()) * (pon.Gety() - a1_.Gety());
    }
    if ((-x_ * (pon.Getx() - a2_.Getx()) - y_ * (pon.Gety() - a2_.Gety())) <= 0) {
      return (pon.Getx() - a2_.Getx()) *(pon.Getx() - a2_.Getx()) +
      (pon.Gety() - a2_.Gety()) * (pon.Gety() - a2_.Gety());
    }
    return (std::abs(Line(a1_, a2_).DistPoint(pon)));
  }

  bool Segment::CrossesSegment(const Segment& b) const {
    if (Line(a1_, a2_).DistPoint(b.a1_) * Line(a1_, a2_).DistPoint(b.a2_) < 0) {
      if (Line(b.a1_, b.a2_).DistPoint(a1_) * Line(b.a1_, b.a2_).DistPoint(a2_) < 0) {
        return true;
      }
    }
    if (DistPoint(b.a1_) == 0 || DistPoint(b.a2_) == 0) {
      return true;
    }
    if (b.DistPoint(a1_) == 0 || b.DistPoint(a2_) == 0) {
      return true;
    }
    return false;
  }

  Segment* Segment::Clone() const {
    auto seg = new Segment(a1_, a2_);
    return seg;
  }

  std::string Segment::ToString() const {
    std::string seg = "Segment(" + a1_.ToString() + ", " + a2_.ToString() + ")";
    return seg;
  }

  Segment::~Segment() = default;
}