#include "../vector.h"
#include "point.h"

namespace geometry {
  Vector::Vector(float x, float y) : x_(x), y_(y) {
  }

  Vector::Vector(const Point& a, const Point& b) : x_(b.Getx() - a.Getx()), y_(b.Gety() - a.Gety()) {}

  float Vector::Getx() const {
    return x_;
  }

  float Vector::Gety() const {
    return y_;
  }

  float Vector::Scalar(const Vector& b) const {
    return (x_ * b.Getx() + y_ * b.Gety());
  }

  float Vector::Vectornoe(const Vector& b) const {
    return (x_ * b.Gety() - y_ * b.Getx());
  }

  Vector Vector::operator+(const Vector& b) const {
    return Vector(x_ + b.Getx(), y_ + b.Gety());
  }

  Vector Vector::operator-(const Vector& b) const {
    return *(this) + (-b);
  }

  Vector& Vector::operator*=(float value) {
    x_ *= value;
    y_ *= value;
    return *this;
  }

  Vector& Vector::operator/=(float value) {
    *this *= (1 / value);
    return *this;
  }

  Vector Vector::operator*(float val) const {
    return Vector(x_ * val, y_ * val);
  }

  Vector Vector::operator/(float val) const {
    return *this * (1 / val);
  }

  Vector Vector::operator-() const {
    return Vector(-x_, -y_);
  }

  Vector& Vector::operator+=(const Vector& vec) {
    *this = *this + vec;
    return *this;
  }

  Vector& Vector::operator-=(const Vector& vec) {
    *this += (-vec);
    return *this;
  }

  bool Vector::operator==(const Vector& vec) const {
    return (x_ == vec.x_ && y_ == vec.y_);
  }
}