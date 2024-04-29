#include "../Vector.h"
#include "../Point.h"

namespace geometry {
  Vector::Vector(float x, float y) : x_(x), y_(y) {
  }

  Vector::Vector(const Point& point1, const Point& point2) : x_(point2.getX() - point1.getX()), y_(point2.getY() -
                                                                                                   point1.getY()) {}

  float Vector::getX() const {
    return x_;
  }

  float Vector::getY() const {
    return y_;
  }

  float Vector::ScalarProduct(const Vector& vector) const {
    return (x_ * vector.getX() + y_ * vector.getY());
  }

  float Vector::VectorProduct(const Vector& vector) const {
    return (x_ * vector.getY() - y_ * vector.getX());
  }

  Vector Vector::operator+(const Vector& vector) const {
    return Vector(x_ + vector.getX(), y_ + vector.getY());
  }

  Vector Vector::operator-(const Vector& vector) const {
    return *(this) + (-vector);
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

  Vector Vector::operator*(float value) const {
    return Vector(x_ * value, y_ * value);
  }

  Vector Vector::operator/(float value) const {
    return *this * (1 / value);
  }

  Vector Vector::operator-() const {
    return Vector(-x_, -y_);
  }

  Vector& Vector::operator+=(const Vector& vector) {
    *this = *this + vector;
    return *this;
  }

  Vector& Vector::operator-=(const Vector& vector) {
    *this += (-vector);
    return *this;
  }

  bool Vector::operator==(const Vector& vector) const {
    return (x_ == vector.x_ && y_ == vector.y_);
  }
}