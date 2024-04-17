#include "../Ray.h"
#include "../Segment.h"

namespace geometry {
  Ray::Ray() = default;
  Ray::Ray(const Point& begin, const Point& point) {
    a1_ = begin;
    a2_ = point;
    a_ = -(point.getY() - begin.getY());
    b_ = (point.getX() - begin.getX());
    c_ = -(a_ * begin.getX() + b_ * begin.getY());
  };

  Point Ray::getBegin() const {
    return a1_;
  }

  Point Ray::getPoint() const {
    return a2_;
  }

  Ray& Ray::Move(const Vector& vector) {
    a1_.Move(vector);
    a2_.Move(vector);
    *this = Ray(a1_, a2_);
    return *this;
  }

  float Ray::DistPoint(const Point& point) const {
    return a_ * point.getX() + b_ * point.getY() + c_;
  }

  bool Ray::ContainsPoint(const Point& pon) const {
    if (a1_.ContainsPoint(a2_)) {
      return pon.ContainsPoint(a1_);
    }
    Vector vector(pon.getX() - a1_.getX(), pon.getY() - a1_.getY());
    Vector radius_vector(a2_.getX() - a1_.getX(), a2_.getY() - a1_.getY());
    return DistPoint(pon) == 0 && radius_vector.ScalarProduct(vector) >= 0;
  }

  bool Ray::CrossesSegment(const Segment& segment) const {
    if (ContainsPoint(segment.getA1()) || ContainsPoint(segment.getA2())) {
      return true;
    }
    if (a1_.ContainsPoint(a2_)) {
      return false;
    }
    if (DistPoint(segment.getA1()) * DistPoint(segment.getA2()) < 0) {
      Line line1 = Line(segment.getA1(), segment.getA2());
      float a1 = line1.getA();
      float b1 = line1.getB();
      float c1 = line1.getC();

      float det = a1 * b_ - a_ * b1;
      float detx = b1 * c_ - b_ * c1;
      float dety = c1 * a_ - c_ * a1;
      if (((a2_.getX() - a1_.getX()) * (detx - a1_.getX() * det) +
           (a2_.getY() - a1_.getY()) * (dety - a1_.getY() * det)) * det
      > 0) {
        return true;
      }
    }
    return false;
  }
}