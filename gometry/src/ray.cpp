#include "../ray.h"
#include "../segment.h"

namespace geometry {
  Ray::Ray() = default;
  Ray::Ray(const Point& beg, const Point& pon) {
    a1_ = beg;
    a2_ = pon;
    a_ = -(pon.Gety() - beg.Gety());
    b_ = (pon.Getx() - beg.Getx());
    c_ = -(a_ * beg.Getx() + b_ * beg.Gety());
  };

  Point Ray::Getbeg() const {
    return a1_;
  }

  Point Ray::Getpon() const {
    return a2_;
  }

  Ray& Ray::Move(const Vector& vec) {
    a1_.Move(vec);
    a2_.Move(vec);
    *this = Ray(a1_, a2_);
    return *this;
  }

  int64_t Ray::DistPoint(const Point& pon) const {
    return a_ * pon.Getx() + b_ * pon.Gety() + c_;
  }

  bool Ray::ContainsPoint(const Point& pon) const {
    if (a1_.ContainsPoint(a2_)) {
      return pon.ContainsPoint(a1_);
    }
    Vector vect(pon.Getx() - a1_.Getx(), pon.Gety() - a1_.Gety());
    Vector ra(a2_.Getx() - a1_.Getx(), a2_.Gety() - a1_.Gety());
    return DistPoint(pon) == 0 && ra.Scalar(vect) >= 0;
  }

  bool Ray::CrossesSegment(const Segment& seg) const {
    if (ContainsPoint(seg.Geta1()) || ContainsPoint(seg.Geta2())) {
      return true;
    }
    if (a1_.ContainsPoint(a2_)) {
      return false;
    }
    if (DistPoint(seg.Geta1()) * DistPoint(seg.Geta2()) < 0) {
      Line lin1 = Line(seg.Geta1(), seg.Geta2());
      int64_t a1 = lin1.Geta();
      int64_t b1 = lin1.Getb();
      int64_t c1 = lin1.Getc();

      int64_t det = a1 * b_ - a_ * b1;
      int64_t detx = b1 * c_ - b_ * c1;
      int64_t dety = c1 * a_ - c_ * a1;
      if (((a2_.Getx() - a1_.Getx()) * (detx - a1_.Getx() * det) +
      (a2_.Gety() - a1_.Gety()) * (dety - a1_.Gety() * det)) * det
      > 0) {
        return true;
      }
    }
    return false;
  }

  Ray* Ray::Clone() const {
    auto ray = new Ray(a1_, a2_);
    return ray;
  }

  std::string Ray::ToString() const {
    std::string ray = "Ray(" + a1_.ToString() + ", Vector(" + std::to_string((a2_.Getx() - a1_.Getx())) + ", " + std::to_string((a2_.Gety() - a1_.Gety())) + "))";
    return ray;
  }


}