#include "IShape.h"
#include "Vector.h"
#ifndef GEOMETRY_POINT_Hui
#define GEOMETRY_POINT_Hui
namespace geometry {
  class Point : public IShape {
   private:
    float x_ = 0;
    float y_ = 0;

   public:
    Point();
    Point(const float&, const float&);  // NOLINT
    float getX() const;
    float getY() const;
    Point& Move(const Vector&) override;
    bool operator==(const Point&) const;
    Point& operator+=(const Vector&);
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Vector operator-(const Point&) const;
    bool operator!=(const Point&) const;
    ~Point() override = default;
  };
}
#endif