#include "../Polygon.h"
#include "../Segment.h"
#include "../IShape.h"
#include "../Point.h"
#include "../Vector.h"
#include "../Line.h"

namespace geometry {
  Polygon::Polygon(const std::vector<Point>& vertices) {
    count_ = vertices.end() - vertices.begin();
    insidecount_ = count_;
    vertices_.resize(count_);
    insides_.resize(count_);
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = vertices[i];
      insides_[i] = vertices[i];
    }
    notshell_.clear();
  }

  Polygon::Polygon() : vertices_{}, insides_{}, notshell_{} {};

  Polygon& Polygon::Move(const Vector& vector) {
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] += vector;
      insides_[i] += vector;
    }
    return *this;
  }

  bool Polygon::ContainsPoint(const Point& point) const {
    if (count_ == 0) {
      return false;
    }
    float x = point.getX() + 1;
    Ray ray = Ray(point, Point(x, point.getY()));
    int counter = 0;
    size_t curver = 0;
    while (curver < count_) {
      if (Segment(vertices_[curver], vertices_[(curver + 1) % count_]).ContainsPoint(point)) {
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
          size_t otherptr = curver + 2;
          while (ray.ContainsPoint(vertices_[otherptr % count_])) {
            ++otherptr;
          }
          if (ray.DistPoint(vertices_[curver]) * ray.DistPoint(vertices_[otherptr % count_]) < 0) {
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

  bool Polygon::CrossesSegment(const Segment& segment) const {
    size_t curver = 0;
    while (curver < count_) {
      if (Segment(vertices_[curver], vertices_[(curver + 1) % count_]).CrossesSegment(segment)) {
        return true;
      }
      curver++;
    }
    return false;
  }

  static bool PointSorterDownHigh(const Point& point1, const Point& point2) {
    if (point1.getX() == point2.getX()) {
      return point1.getY() > point2.getY();
    }
    return point1.getX() > point2.getX();
  }

  static bool PointSorterUpHigh(const Point& point1, const Point& point2) {
    if (point1.getX() == point2.getX()) {
      return point1.getY() > point2.getY();
    }
    return point1.getX() < point2.getX();
  }

  static bool PointSorterUpLess(const Point& point1, const Point& point2) {
    if (point1.getX() == point2.getX()) {
      return point1.getY() < point2.getY();
    }
    return point1.getX() < point2.getX();
  }

  static bool PointSorterDownLess(const Point& point1, const Point& point2) {
    if (point1.getX() == point2.getX()) {
      return point1.getY() < point2.getY();
    }
    return point1.getX() > point2.getX();
  }

  void Polygon::ConvexShell() {
    if (insidecount_ < 3) {
      insidecount_ = 0;
      count_ = 0;
      return;
    }
    vertices_.resize(insidecount_ + 1);
    for (size_t i = 0; i < insidecount_; ++i) {
      vertices_[i] = insides_[i];
    }
    insides_.clear();
    count_ = insidecount_;
    insides_.resize(count_ + 1);
    std::sort(vertices_.begin(), vertices_.end(), PointSorterUpLess);
    Point firts_point = vertices_[0];
    std::vector<Point> real_vertices(count_ + 1);
    size_t counter = 1;
    size_t inside_counter = 0;
    Move(Vector(firts_point, Point(0, 0)));
    real_vertices[0] = vertices_[0];
    for (size_t i = 1; i < count_; ++i) {
      while (counter >= 2) {
        Point a = real_vertices[counter - 2];
        Point b = real_vertices[counter - 1];
        float vect = Vector(a, b).VectorProduct(Vector(b, vertices_[i]));
        if (vect > 0) {
          --counter;
          insides_[inside_counter] = real_vertices[counter];
          ++inside_counter;
        } else {
          break;
        }
      }
      real_vertices[counter] = vertices_[i];
      ++counter;
    }
    std::sort(insides_.begin(), insides_.end(), PointSorterDownHigh);
    insides_[inside_counter] = real_vertices[0];
    count_ = counter;
    std::vector<Point> real_inside(inside_counter);
    insidecount_ = 0;
    for (size_t i = 0; i < inside_counter + 1; ++i) {
      while (counter >= count_ + 1) {
        Point a = real_vertices[counter - 2];
        Point b = real_vertices[counter - 1];
        float vect = Vector(a, b).VectorProduct(Vector(b, insides_[i]));
        if (vect > 0) {
          --counter;
          real_inside[insidecount_] = real_vertices[counter];
          ++insidecount_;
        } else {
          break;
        }
      }
      real_vertices[counter] = insides_[i];
      ++counter;
    }
    --counter;
    vertices_.clear();
    insides_.clear();
    vertices_ = real_vertices;
    count_ = counter;
    insides_ = real_inside;
    Move(Vector(Point(0, 0), firts_point));
  }

  void Polygon::Shell() {
    count_ = insidecount_;
    insides_.resize(count_ + 1);
    std::sort(vertices_.begin(), vertices_.end(), PointSorterUpLess);
    Point firstpon = vertices_[0];
    Point laspon = vertices_[count_ - 1];
    std::vector<Point> real_vertices(count_ + 1);
    size_t counter = 1;
    size_t inscounter = 0;
    real_vertices[0] = vertices_[0];
    Line main_line(firstpon, laspon);
    for (size_t i = 1; i < count_; ++i) {
      if (main_line.DistPoint(vertices_[i]) >= 0) {
        if (vertices_[i - 1].getX() != vertices_[i].getX()) {
          real_vertices[counter] = vertices_[i];
          ++counter;
        } else {
          notshell_[inscounter] = vertices_[i];
          ++inscounter;
        }
      }
    }
    for (size_t i = count_ - 2; i > 0; --i) {
      if (main_line.DistPoint(vertices_[i]) <= 0) {
        if (vertices_[i - 1].getX() != vertices_[i].getX()) {
          real_vertices[counter] = vertices_[i];
          ++counter;
        } else {
          notshell_[inscounter] = vertices_[i];
          ++inscounter;
        }
      }
    }
    vertices_.clear();
    count_ = counter;
    vertices_ = real_vertices;
    notshellcount_ = inscounter;
  }

  Polygon::~Polygon() {
    vertices_.clear();
    insides_.clear();
  }

  Polygon::Polygon(const sf::ConvexShape& shape) {
    count_ = shape.getPointCount();
    vertices_.resize(count_);
    for (size_t i = 0; i < count_; ++i) {
      vertices_[i] = Point(shape.getPoint(i).x, shape.getPoint(i).y);
      insides_[i] = Point(shape.getPoint(i).x, shape.getPoint(i).y);
    }
    notshell_.clear();
  }

  std::vector<Point> Polygon::getPoints() const {
    return vertices_;
  }

  size_t Polygon::getCount() const {
    return count_;
  }
}