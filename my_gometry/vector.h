#ifndef GOMETRY_VECTOR_H
#define GOMETRY_VECTOR_H
#define int64_t float
#include <iostream>
#include <cstdint>
#include <vector>

namespace geometry {
  class Point;

  class Vector {
  private:
    int64_t x_ = 0;
    int64_t y_ = 0;

  public:
    explicit Vector() = default;
    explicit Vector(int64_t, int64_t);
    explicit Vector(const Point&, const Point&);
    int64_t Getx() const;
    int64_t Gety() const;
    int64_t Scalar(const Vector&) const;
    int64_t Vectornoe(const Vector&) const;
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector& operator*=(int64_t);
    Vector& operator/=(int64_t);
    Vector operator*(int64_t) const;
    Vector operator/(int64_t) const;
    Vector operator-() const;
    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    bool operator==(const Vector&) const;
  };
}
#endif
