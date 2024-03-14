#include "../vector.h"

namespace geometry {
  Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {
  };

  int64_t Vector::Getx() const {
    return x_;
  }

  int64_t Vector::Gety() const {
    return y_;
  }

  int64_t Vector::Scalar(const Vector &b) const {
    return (x_ * b.Getx() + y_ * b.Gety());
  }

  int64_t Vector::Vectornoe(const Vector &b) const {
    return (x_ * b.Gety() - y_ * b.Getx());
  }

  Vector Vector::operator+(const Vector &b) const {
    return Vector(x_ + b.Getx(), y_ + b.Gety());
  }

  Vector Vector::operator-(const Vector &b) const {
    return *(this) + (-b);
  }

  Vector &Vector::operator*=(int64_t value) {
    x_ *= value;
    y_ *= value;
    return *this;
  }

  Vector &Vector::operator/=(int64_t value) {
    *this *= (1 / value);
    return *this;
  }

  Vector Vector::operator*(int64_t val) const {
    return Vector(x_ * val, y_ * val);
  }

  Vector Vector::operator/(int64_t val) const {
    return *this * (1 / val);
  }

  Vector Vector::operator-() const {
    return Vector(-x_, -y_);
  }

  Vector &Vector::operator+=(const Vector &vec) {
    *this = *this + vec;
    return *this;
  }

  Vector &Vector::operator-=(const Vector &vec) {
    *this += (-vec);
    return *this;
  }

  bool Vector::operator==(const Vector &vec) const {
    return (x_ == vec.x_ && y_ == vec.y_);
  }
}