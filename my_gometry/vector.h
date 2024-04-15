#ifndef GOMETRY_VECTOR_H
#define GOMETRY_VECTOR_H
#include <iostream>
#include <cstdint>
#include <vector>
#include "point.h"

namespace geometry {
  class Vector {
  private:
    float x_ = 0;
    float y_ = 0;

  public:
    explicit Vector(const geometry::Point &a, const geometry::Point &b);
    explicit Vector() = default;
    explicit Vector(float, float);
    float Getx() const;
    float Gety() const;
    float Scalar(const Vector&) const;
    float Vectornoe(const Vector&) const;
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector& operator*=(float);
    Vector& operator/=(float);
    Vector operator*(float) const;
    Vector operator/(float) const;
    Vector operator-() const;
    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    bool operator==(const Vector&) const;
  };
}
#endif
