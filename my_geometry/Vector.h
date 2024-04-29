#ifndef GEOMETRY_VECTOR_H
#define GEOMETRY_VECTOR_H
#include <iostream>
#include <cstdint>
#include <vector>
#include "Point.h"

namespace geometry {
  class Vector {
  private:
    float x_ = 0;
    float y_ = 0;

  public:
    explicit Vector(const geometry::Point&, const geometry::Point&);
    explicit Vector() = default;
    explicit Vector(float, float);
    float getX() const;
    float getY() const;
    float ScalarProduct(const Vector&) const;
    float VectorProduct(const Vector&) const;
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
