#include "Segment.h"
#include "IShape.h"
#include "Point.h"
#include "Line.h"
#include "Vector.h"
#include "Ray.h"
#ifndef GEOMETRY_POLYGON_H
#define GEOMETRY_POLYGON_H
#include "SFML/Graphics.hpp"

namespace geometry {
  class Polygon : public IShape {
  private:
    std::vector<Point> vertices_;
    std::vector<Point> insides_;
    std::vector<Point> notshell_;
    size_t count_ = 0;
    size_t insidecount_ = 0;
    size_t notshellcount_ = 0;

  public:
    explicit Polygon(const std::vector<Point>&);
    explicit Polygon(const sf::ConvexShape&);
    Polygon();
    Polygon& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    void ConvexShell();
    std::vector<Point> getPoints() const;
    size_t getCount() const;
    void Shell();
    ~Polygon() override;
  };
}
#endif
