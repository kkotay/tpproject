#include "../Segment.h"
#include "../Line.h"
#include "../IShape.h"
#include "../Point.h"
#include "../Ray.h"

namespace geometry {
  Segment::Segment() = default;

  Segment::Segment(const Point& point1, const Point& point2) {
    a1_ = point1;
    a2_ = point2;
    x_ = point2.getX() - point1.getX();
    y_ = point2.getY() - point1.getY();
  };

  Point Segment::getA1() const {
    return a1_;
  }

  Point Segment::getA2() const {
    return a2_;
  }

  Segment& Segment::Move(const Vector& vector) {
    a1_ += vector;
    a2_ += vector;
    return *this;
  }

  bool Segment::ContainsPoint(const Point& point) const {
    if (point.ContainsPoint(a1_) || point.ContainsPoint(a2_)) {
      return true;
    }
    if (x_ * (point.getY() - a1_.getY()) - y_ * (point.getX() - a1_.getX()) == 0) {
      if (x_ * (point.getX() - a1_.getX()) + y_ * (point.getY() - a1_.getY()) > 0) {
        if (x_ * (point.getX() - a2_.getX()) + y_ * (point.getY() - a2_.getY()) < 0) {
          return true;
        }
      }
    }
    return false;
  }

  float Segment::DistPoint(const Point& point) const {
    if ((x_ * (point.getX() - a1_.getX()) + y_ * (point.getY() - a1_.getY())) <= 0) {
      return (point.getX() - a1_.getX()) * (point.getX() - a1_.getX()) +
             (point.getY() - a1_.getY()) * (point.getY() - a1_.getY());
    }
    if ((-x_ * (point.getX() - a2_.getX()) - y_ * (point.getY() - a2_.getY())) <= 0) {
      return (point.getX() - a2_.getX()) * (point.getX() - a2_.getX()) +
             (point.getY() - a2_.getY()) * (point.getY() - a2_.getY());
    }
    return (std::abs(Line(a1_, a2_).DistPoint(point)));
  }

  bool Segment::CrossesSegment(const Segment& segment) const {
    if (Line(a1_, a2_).DistPoint(segment.a1_) * Line(a1_, a2_).DistPoint(segment.a2_) < 0) {
      if (Line(segment.a1_, segment.a2_).DistPoint(a1_) * Line(segment.a1_, segment.a2_).DistPoint(a2_) < 0) {
        return true;
      }
    }
    if (DistPoint(segment.a1_) == 0 || DistPoint(segment.a2_) == 0) {
      return true;
    }
    if (segment.DistPoint(a1_) == 0 || segment.DistPoint(a2_) == 0) {
      return true;
    }
    return false;
  }

  Segment::~Segment() = default;
}