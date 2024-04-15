#include "segment.h"
#include "iShape.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "ray.h"
#ifndef GOMETRY_POLYGON_H
#define GOMETRY_POLYGON_H
#include "SFML/Graphics.hpp"

namespace geometry {
  class Polygon : public IShape {
  private:
    Point* vertices_ = nullptr;
    Point* insides_ = nullptr;
    Point* notshell_ = nullptr;
    size_t count_ = 0;
    size_t insidecount_ = 0;
    size_t notshellcount_ = 0;

  public:
    explicit Polygon(const std::vector<Point>&);
    explicit Polygon(const Point*, const size_t&);
    explicit Polygon(const sf::ConvexShape&);
    Polygon();
    Polygon& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    void ConvexShell();
    Point* GetPoints() const;
    size_t GetCount() const;
    void Shell();
    ~Polygon() override;
  };
}
#endif
