#include "../polygon.h"
#include "../segment.h"
#include "../iShape.h"
#include "../point.h"
#include "../vector.h"
#include "../line.h"

namespace geometry {
  Polygon::Polygon(const std::vector<Point>& vert) {
    count_ = vert.end() - vert.begin();
    insidecount_ = count_;
    vertices_ = new Point[count_];
    insides_ = new Point[count_];
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = vert[i];
      insides_[i] = vert[i];
    }
    notshell_ = nullptr;
  }

  Polygon::Polygon(const Point* pons, const size_t& count) {
    count_ = count;
    vertices_ = new Point[count_];
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = pons[i];
      insides_[i] = pons[i];
    }
    notshell_ = nullptr;
  }

  Polygon::Polygon() : vertices_{}, insides_{}, notshell_{} {};

  Polygon& Polygon::Move(const Vector& a) {
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] += a;
      insides_[i] += a;
    }
    return *this;
  }

  bool Polygon::ContainsPoint(const Point& pon) const {
    if (count_ == 0) {
      return false;
    }
    float x = pon.Getx() + 1;
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

  static bool PointSorterup(const Point& a, const Point& b) {
    if (a.Getx() == b.Getx()) {
      return a.Gety() < b.Gety();
    }
    return a.Getx() < b.Getx();
  }

  static bool PointSorterdw(const Point& a, const Point& b) {
    if (a.Getx() == b.Getx()) {
      return a.Gety() > b.Gety();
    }
    return a.Getx() > b.Getx();
  }

  static bool PointSorterupHigh(const Point& a, const Point& b) {
    if (a.Getx() == b.Getx()) {
      return a.Gety() > b.Gety();
    }
    return a.Getx() < b.Getx();
  }

  static bool PointSorterdwDown(const Point& a, const Point& b) {
    if (a.Getx() == b.Getx()) {
      return a.Gety() < b.Gety();
    }
    return a.Getx() > b.Getx();
  }

  void Polygon::ConvexShell() {
    if (insidecount_ < 3) {
      insidecount_ = 0;
      count_ = 0;
      return;
    }
    vertices_ = new Point[insidecount_ + 1];
    for (size_t i = 0; i < insidecount_; ++i) {
      vertices_[i] = insides_[i];
    }
    delete[] insides_;
    count_ = insidecount_;
    insides_ = new Point[count_ + 1];
    std::sort(vertices_, vertices_ + count_, PointSorterup);
    Point firstpon = vertices_[0];
    auto realvert = new Point[count_ + 1];
    size_t counter = 1;
    size_t inscounter = 0;
    Move(Vector(firstpon, Point(0, 0)));
    realvert[0] = vertices_[0];
    for (size_t i = 1; i < count_; ++i) {
      while (counter >= 2) {
        Point a = realvert[counter - 2];
        Point b = realvert[counter - 1];
        float vect = Vector(a, b).Vectornoe(Vector(b, vertices_[i]));
        if (vect > 0) {
          --counter;
          insides_[inscounter] = realvert[counter];
          ++inscounter;
        } else {
          break;
        }
      }
      realvert[counter] = vertices_[i];
      ++counter;
    }
    std::sort(insides_, insides_ + inscounter, PointSorterdw);
    insides_[inscounter] = realvert[0];
    count_ = counter;
    auto realinside = new Point[inscounter];
    insidecount_ = 0;
    for (size_t i = 0; i < inscounter + 1; ++i) {
      while (counter >= count_ + 1) {
        Point a = realvert[counter - 2];
        Point b = realvert[counter - 1];
        float vect = Vector(a, b).Vectornoe(Vector(b, insides_[i]));
        if (vect > 0) {
          --counter;
          realinside[insidecount_] = realvert[counter];
          ++insidecount_;
        } else {
          break;
        }
      }
      realvert[counter] = insides_[i];
      ++counter;
    }
    --counter;
    delete[] vertices_;
    delete[] insides_;
    vertices_ = realvert;
    count_ = counter;
    insides_ = realinside;
    Move(Vector(Point(0, 0), firstpon));
  }

  void Polygon::Shell() {
    count_ = insidecount_;
    insides_ = new Point[count_ + 1];
    std::sort(vertices_, vertices_ + count_, PointSorterup);
    Point firstpon = vertices_[0];
    Point laspon = vertices_[count_ - 1];
    auto realvert = new Point[count_ + 1];
    size_t counter = 1;
    size_t inscounter = 0;
    realvert[0] = vertices_[0];
    Line mainline(firstpon, laspon);
    for (size_t i = 1; i < count_; ++i) {
      if (mainline.DistPoint(vertices_[i]) >= 0) {
        if (vertices_[i - 1].Getx() != vertices_[i].Getx()) {
          realvert[counter] = vertices_[i];
          ++counter;
        } else {
          notshell_[inscounter] = vertices_[i];
          ++inscounter;
        }
      }
    }
    for (size_t i = count_ - 2; i > 0; --i) {
      if (mainline.DistPoint(vertices_[i]) <= 0) {
        if (vertices_[i - 1].Getx() != vertices_[i].Getx()) {
          realvert[counter] = vertices_[i];
          ++counter;
        } else {
          notshell_[inscounter] = vertices_[i];
          ++inscounter;
        }
      }
    }
    delete[] vertices_;
    count_ = counter;
    vertices_ = realvert;
    notshellcount_ = inscounter;
  }

  Polygon::~Polygon() {
    delete[] vertices_;
    delete[] insides_;
  }

  Polygon::Polygon(const sf::ConvexShape& shape) {
    count_ = shape.getPointCount();
    vertices_ = new Point[count_];
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = Point(shape.getPoint(i).x, shape.getPoint(i).y);
      insides_[i] = Point(shape.getPoint(i).x, shape.getPoint(i).y);
    }
    notshell_ = nullptr;
  }

  Point *Polygon::GetPoints() const {
    return vertices_;
  }

  size_t Polygon::GetCount() const {
    return count_;
  }
}