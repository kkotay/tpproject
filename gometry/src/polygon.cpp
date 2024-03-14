#include "../polygon.h"
#include "../segment.h"
#include "../iShape.h"
#include "../point.h"
#include "../vector.h"
#include "../line.h"

namespace geometry {
  Polygon::Polygon(const std::vector<Point>& vert) {
    count_ = vert.end() - vert.begin();
    vertices_ = new Point[count_];
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = vert[i];
    }
  }

  Polygon::Polygon(const Point* pons, const size_t& count) {
    count_ = count;
    vertices_ = new Point[count_];
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = pons[i];
    }
  }

  Polygon::Polygon() : vertices_{} {};

  Polygon& Polygon::Move(const Vector& a) {
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] += a;
    }
    return *this;
  }

  bool Polygon::ContainsPoint(const Point& pon) const {
    int64_t x = pon.Getx() + 1;
    Ray ray = Ray(pon, Point(x, pon.Gety()));
    int counter = 0;
    size_t curver = 0;
    while (curver < count_) {
      if (Segment(vertices_[curver], vertices_[(curver + 1) % count_]).ContainsPoint(pon)) {
        return true;
      }
      if (ray.ContainsPoint(vertices_[curver])) {
        if (!ray.ContainsPoint(vertices_[(curver + 1) % count_])) {
          ++curver;
          continue;
        }
      }
      if (!ray.ContainsPoint(vertices_[curver])) {
        if (ray.ContainsPoint(vertices_[(curver + 1) % count_])) {
          size_t otptr = curver + 2;
          while (ray.ContainsPoint(vertices_[otptr % count_])) {
            ++otptr;
          }
          if (ray.DistPoint(vertices_[curver]) * ray.DistPoint(vertices_[otptr % count_]) < 0) {
            ++counter;
          }
          ++curver;
          continue;
        }
      }
      if (ray.CrossesSegment(Segment(vertices_[curver], vertices_[(curver + 1) % count_])) &&
      !(ray.ContainsPoint(vertices_[curver]) || ray.ContainsPoint(vertices_[(curver + 1 % count_)]))) {
        ++counter;
      }
      ++curver;
    }
    return (counter & 1) != 0;
  }

  bool Polygon::CrossesSegment(const Segment& seg) const {
    size_t curver = 0;
    while (curver < count_) {
      if (Segment(vertices_[curver], vertices_[(curver + 1) % count_]).CrossesSegment(seg)) {
        return true;
      }
      curver++;
    }
    return false;
  }

  Polygon* Polygon::Clone() const {
    auto poly = new Polygon{vertices_, count_};
    return poly;
  }

  std::string Polygon::ToString() const {
    std::string poly = "Polygon(" + vertices_[0].ToString();
    for (size_t i = 1; i < count_; ++i) {
      poly += ", ";
      poly += vertices_[i].ToString();
    }
    poly += ")";
    return poly;
  }

  Polygon::~Polygon() {
    delete[] vertices_;
  }
}